/*	$OpenBSD: privsep.h,v 1.16 2013/02/20 18:50:29 krw Exp $ */

/*
 * Copyright (c) 2004 Henning Brauer <henning@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE, ABUSE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <arpa/inet.h>

#include <imsg.h>

enum imsg_code {
	IMSG_NONE,
	IMSG_DELETE_ADDRESS,
	IMSG_ADD_ADDRESS,
	IMSG_FLUSH_ROUTES,
	IMSG_ADD_DEFAULT_ROUTE,
	IMSG_HUP,
	IMSG_WRITE_FILE
};

struct imsg_delete_address {
	char	ifname[IFNAMSIZ];
	int	rdomain;
	struct	in_addr addr;
};

struct imsg_add_address {
	char	ifname[IFNAMSIZ];
	int	rdomain;
	struct	in_addr	addr;
	struct	in_addr mask;
};

struct imsg_flush_routes {
	char	ifname[IFNAMSIZ];
	int	rdomain;
};

struct imsg_add_default_route {
	int		rdomain;
	struct in_addr	addr;
	struct in_addr	gateway;
};

struct imsg_hup {
	char	ifname[IFNAMSIZ];
	int	rdomain;
	struct	in_addr addr;
};

struct imsg_write_file {
	char	path[MAXPATHLEN];
	int	rdomain;
	int	flags;
	mode_t	mode;
	size_t	len;
	uid_t	uid;
	gid_t	gid;
	char	contents[1];
};

void	dispatch_imsg(struct imsgbuf *);
void	priv_delete_address(struct imsg_delete_address *);
void	priv_add_address(struct imsg_add_address *);
void	priv_flush_routes_and_arp_cache(struct imsg_flush_routes *);
void	priv_add_default_route(struct imsg_add_default_route *);
void	priv_cleanup(struct imsg_hup *);
void	priv_write_file(struct imsg_write_file *);
