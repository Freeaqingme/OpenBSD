/* $OpenBSD: names.c,v 1.18 2012/11/27 09:20:03 nicm Exp $ */

/*
 * Copyright (c) 2009 Nicholas Marriott <nicm@users.sourceforge.net>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/types.h>

#include <ctype.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "tmux.h"

void	 window_name_callback(unused int, unused short, void *);
char	*parse_window_name(const char *);

void
queue_window_name(struct window *w)
{
	struct timeval	tv;

	tv.tv_sec = 0;
	tv.tv_usec = NAME_INTERVAL * 1000L;

	if (event_initialized(&w->name_timer))
		evtimer_del(&w->name_timer);
	evtimer_set(&w->name_timer, window_name_callback, w);
	evtimer_add(&w->name_timer, &tv);
}

/* ARGSUSED */
void
window_name_callback(unused int fd, unused short events, void *data)
{
	struct window	*w = data;
	char		*name, *wname;

	if (w->active == NULL)
		return;

	if (!options_get_number(&w->options, "automatic-rename")) {
		if (event_initialized(&w->name_timer))
			event_del(&w->name_timer);
		return;
	}
	queue_window_name(w);

	if (w->active->screen != &w->active->base)
		name = NULL;
	else
		name = get_proc_name(w->active->fd, w->active->tty);
	if (name == NULL)
		wname = default_window_name(w);
	else {
		/*
		 * If tmux is using the default command, it will be a login
		 * shell and argv[0] may have a - prefix. Remove this if it is
		 * present. Ick.
		 */
		if (w->active->cmd != NULL && *w->active->cmd == '\0' &&
		    name != NULL && name[0] == '-' && name[1] != '\0')
			wname = parse_window_name(name + 1);
		else
			wname = parse_window_name(name);
		free(name);
	}

	if (w->active->fd == -1) {
		xasprintf(&name, "%s[dead]", wname);
		free(wname);
		wname = name;
	}

	if (strcmp(wname, w->name)) {
		window_set_name(w, wname);
		server_status_window(w);
	}
	free(wname);
}

char *
default_window_name(struct window *w)
{
	if (w->active->screen != &w->active->base)
		return (xstrdup("[tmux]"));
	if (w->active->cmd != NULL && *w->active->cmd != '\0')
		return (parse_window_name(w->active->cmd));
	return (parse_window_name(w->active->shell));
}

char *
parse_window_name(const char *in)
{
	char	*copy, *name, *ptr;

	name = copy = xstrdup(in);
	if (strncmp(name, "exec ", (sizeof "exec ") - 1) == 0)
		name = name + (sizeof "exec ") - 1;

	while (*name == ' ')
		name++;
	if ((ptr = strchr(name, ' ')) != NULL)
		*ptr = '\0';

	if (*name != '\0') {
		ptr = name + strlen(name) - 1;
		while (ptr > name && !isalnum((u_char)*ptr))
			*ptr-- = '\0';
	}

	if (*name == '/')
		name = basename(name);
	name = xstrdup(name);
	free(copy);
	return (name);
}