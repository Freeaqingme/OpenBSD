/* Opcode aliases for m680[012346]0/m6888[12]/m68851/mcf5200.
   Copyright 1989, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999,
   2000, 2001
   Free Software Foundation, Inc.

This file was taken from GNU binutils.

you can redistribute it and/or modify it under the terms of the 
GNU General Public License as published by the Free Software Foundation; 
either version 1, or (at your option) any later version.

This is distributed in the hope that it will be useful, but 
WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this file; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.  */


/* These aliases used to be in the above table, each one duplicating
   all of the entries for its primary exactly.  This table was
   constructed by mechanical processing of the opcode table, with a
   small number of tweaks done by hand.  There are probably a lot more
   aliases above that could be moved down here, except for very minor
   differences.  */

struct m68k_opcode_alias
{
	const char *alias;
	const char *primary;
};

const struct m68k_opcode_alias m68k_opcode_aliases[] =
{
  { "add",	"addw", },
  { "adda",	"addaw", },
  { "addi",	"addiw", },
  { "addq",	"addqw", },
  { "addx",	"addxw", },
  { "asl",	"aslw", },
  { "asr",	"asrw", },
  { "bhi",	"bhiw", },
  { "bls",	"blsw", },
  { "bcc",	"bccw", },
  { "bcs",	"bcsw", },
  { "bne",	"bnew", },
  { "beq",	"beqw", },
  { "bvc",	"bvcw", },
  { "bvs",	"bvsw", },
  { "bpl",	"bplw", },
  { "bmi",	"bmiw", },
  { "bge",	"bgew", },
  { "blt",	"bltw", },
  { "bgt",	"bgtw", },
  { "ble",	"blew", },
  { "bra",	"braw", },
  { "bsr",	"bsrw", },
  { "bhib",	"bhis", },
  { "blsb",	"blss", },
  { "bccb",	"bccs", },
  { "bcsb",	"bcss", },
  { "bneb",	"bnes", },
  { "beqb",	"beqs", },
  { "bvcb",	"bvcs", },
  { "bvsb",	"bvss", },
  { "bplb",	"bpls", },
  { "bmib",	"bmis", },
  { "bgeb",	"bges", },
  { "bltb",	"blts", },
  { "bgtb",	"bgts", },
  { "bleb",	"bles", },
  { "brab",	"bras", },
  { "bsrb",	"bsrs", },
  { "bhs",	"bccw" },
  { "bhss",	"bccs" },
  { "bhsb",	"bccs" },
  { "bhsw",	"bccw" },
  { "bhsl",	"bccl" },
  { "blo",	"bcsw" },
  { "blos",	"bcss" },
  { "blob",	"bcss" },
  { "blow",	"bcsw" },
  { "blol",	"bcsl" },
  { "br",	"braw", },
  { "brs",	"bras", },
  { "brb",	"bras", },
  { "brw",	"braw", },
  { "brl",	"bral", },
  { "jfnlt",	"bcc", },	/* apparently a sun alias */
  { "jfngt",	"ble", },	/* apparently a sun alias */
  { "jfeq",	"beqs", },	/* apparently a sun alias */
  { "bchgb",	"bchg", },
  { "bchgl",	"bchg", },
  { "bclrb",	"bclr", },
  { "bclrl",	"bclr", },
  { "bsetb",	"bset", },
  { "bsetl",	"bset", },
  { "btstb",	"btst", },
  { "btstl",	"btst", },
  { "cas2",	"cas2w", },
  { "cas",	"casw", },
  { "chk2",	"chk2w", },
  { "chk",	"chkw", },
  { "clr",	"clrw", },
  { "cmp2",	"cmp2w", },
  { "cmpa",	"cmpaw", },
  { "cmpi",	"cmpiw", },
  { "cmpm",	"cmpmw", },
  { "cmp",	"cmpw", },
  { "dbccw",	"dbcc", },
  { "dbcsw",	"dbcs", },
  { "dbeqw",	"dbeq", },
  { "dbfw",	"dbf", },
  { "dbgew",	"dbge", },
  { "dbgtw",	"dbgt", },
  { "dbhiw",	"dbhi", },
  { "dblew",	"dble", },
  { "dblsw",	"dbls", },
  { "dbltw",	"dblt", },
  { "dbmiw",	"dbmi", },
  { "dbnew",	"dbne", },
  { "dbplw",	"dbpl", },
  { "dbtw",	"dbt", },
  { "dbvcw",	"dbvc", },
  { "dbvsw",	"dbvs", },
  { "dbhs",	"dbcc", },
  { "dbhsw",	"dbcc", },
  { "dbra",	"dbf", },
  { "dbraw",	"dbf", },
  { "tdivsl",	"divsl", },
  { "divs",	"divsw", },
  { "divu",	"divuw", },
  { "ext",	"extw", },
  { "extbw",	"extw", },
  { "extwl",	"extl", },
  { "fbneq",	"fbne", },
  { "fbsneq",	"fbsne", },
  { "fdbneq",	"fdbne", },
  { "fdbsneq",	"fdbsne", },
  { "fmovecr",	"fmovecrx", },
  { "fmovm",	"fmovem", },
  { "fsneq",	"fsne", },
  { "fssneq",	"fssne", },
  { "ftrapneq",	"ftrapne", },
  { "ftrapsneq", "ftrapsne", },
  { "fjneq",	"fjne", },
  { "fjsneq",	"fjsne", },
  { "jmpl",	"jmp", },
  { "jmps",	"jmp", },
  { "jsrl",	"jsr", },
  { "jsrs",	"jsr", },
  { "leal",	"lea", },
  { "lsl",	"lslw", },
  { "lsr",	"lsrw", },
#if 0
  { "mac",	"macw" },
#endif
  { "movea",	"moveaw", },
  { "movem",	"movemw", },
  { "movml",	"moveml", },
  { "movmw",	"movemw", },
  { "movm",	"movemw", },
  { "movep",	"movepw", },
  { "movpw",	"movepw", },
  { "moves",	"movesw" },
  { "muls",	"mulsw", },
  { "mulu",	"muluw", },
#if 0
  { "msac",	"msacw" },
#endif
  { "nbcdb",	"nbcd" },
  { "neg",	"negw", },
  { "negx",	"negxw", },
  { "not",	"notw", },
  { "peal",	"pea", },
  { "rol",	"rolw", },
  { "ror",	"rorw", },
  { "roxl",	"roxlw", },
  { "roxr",	"roxrw", },
#if 0
  { "sats",	"satsl", },
#endif
  { "sbcdb",	"sbcd", },
  { "sccb",	"scc", },
  { "scsb",	"scs", },
  { "seqb",	"seq", },
  { "sfb",	"sf", },
  { "sgeb",	"sge", },
  { "sgtb",	"sgt", },
  { "shib",	"shi", },
  { "sleb",	"sle", },
  { "slsb",	"sls", },
  { "sltb",	"slt", },
  { "smib",	"smi", },
  { "sneb",	"sne", },
  { "splb",	"spl", },
  { "stb",	"st", },
  { "svcb",	"svc", },
  { "svsb",	"svs", },
  { "sfge",	"sge", },
  { "sfgt",	"sgt", },
  { "sfle",	"sle", },
  { "sflt",	"slt", },
  { "sfneq",	"sne", },
  { "suba",	"subaw", },
  { "subi",	"subiw", },
  { "subq",	"subqw", },
  { "sub",	"subw", },
  { "subx",	"subxw", },
  { "swapw",	"swap", },
  { "tasb",	"tas", },
  { "tpcc",	"trapcc", },
  { "tcc",	"trapcc", },
  { "tst",	"tstw", },
  { "jbra",	"jra", },
  { "jbhi",	"jhi", },
  { "jbls",	"jls", },
  { "jbcc",	"jcc", },
  { "jbcs",	"jcs", },
  { "jbne",	"jne", },
  { "jbeq",	"jeq", },
  { "jbvc",	"jvc", },
  { "jbvs",	"jvs", },
  { "jbpl",	"jpl", },
  { "jbmi",	"jmi", },
  { "jbge",	"jge", },
  { "jblt",	"jlt", },
  { "jbgt",	"jgt", },
  { "jble",	"jle", },
  { "movql",	"moveq", },
  { "moveql",	"moveq", },
  { "movl",	"movel", },
  { "movq",	"moveq", },
  { "moval",	"moveal", },
  { "movaw",	"moveaw", },
  { "movb",	"moveb", },
  { "movc",	"movec", },
  { "movecl",	"movec", },
  { "movpl",	"movepl", },
  { "movw",	"movew", },
  { "movsb",	"movesb", },
  { "movsl",	"movesl", },
  { "movsw",	"movesw", },
#if 0
  { "mov3q",	"mov3ql", },
#endif

  { "tdivul",	"divul", },	/* for m68k-svr4 */
  { "fmovb",	"fmoveb", },
  { "fsmovb",	"fsmoveb", },
  { "fdmovb",	"fdmoveb", },
  { "fmovd",	"fmoved", },
  { "fsmovd",	"fsmoved", },
  { "fmovl",	"fmovel", },
  { "fsmovl",	"fsmovel", },
  { "fdmovl",	"fdmovel", },
  { "fmovp",	"fmovep", },
  { "fsmovp",	"fsmovep", },
  { "fdmovp",	"fdmovep", },
  { "fmovs",	"fmoves", },
  { "fsmovs",	"fsmoves", },
  { "fdmovs",	"fdmoves", },
  { "fmovw",	"fmovew", },
  { "fsmovw",	"fsmovew", },
  { "fdmovw",	"fdmovew", },
  { "fmovx",	"fmovex", },
  { "fsmovx",	"fsmovex", },
  { "fdmovx",	"fdmovex", },
  { "fmovcr",	"fmovecr", },
  { "fmovcrx",	"fmovecrx", },
  { "ftestb",	"ftstb", },
  { "ftestd",	"ftstd", },
  { "ftestl",	"ftstl", },
  { "ftestp",	"ftstp", },
  { "ftests",	"ftsts", },
  { "ftestw",	"ftstw", },
  { "ftestx",	"ftstx", },
};

const int m68k_numaliases =
  sizeof m68k_opcode_aliases / sizeof m68k_opcode_aliases[0];