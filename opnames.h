/* ex: set ro ft=c: -*- buffer-read-only: t -*-
 *
 *    opnames.h
 *
 *    Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007,
 *    2008 by Larry Wall and others
 *
 *    You may distribute under the terms of either the GNU General Public
 *    License or the Artistic License, as specified in the README file.
 *
 * !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
 * This file is built by regen/opcode.pl from its data.
 * Any changes made here will be lost!
 */

typedef enum opcode {
	OP_NULL		 = 0,
	OP_STUB		 = 1,
	OP_SCALAR	 = 2,
	OP_PUSHMARK	 = 3,
	OP_WANTARRAY	 = 4,
	OP_CONST	 = 5,
	OP_GVSV		 = 6,
	OP_GV		 = 7,
	OP_GELEM	 = 8,
	OP_PADSV	 = 9,
	OP_PADAV	 = 10,
	OP_PADHV	 = 11,
	OP_PADANY	 = 12,
	OP_PUSHRE	 = 13,
	OP_RV2GV	 = 14,
	OP_RV2SV	 = 15,
	OP_AV2ARYLEN	 = 16,
	OP_RV2CV	 = 17,
	OP_ANONCODE	 = 18,
	OP_PROTOTYPE	 = 19,
	OP_REFGEN	 = 20,
	OP_SREFGEN	 = 21,
	OP_REF		 = 22,
	OP_BLESS	 = 23,
	OP_BACKTICK	 = 24,
	OP_GLOB		 = 25,
	OP_READLINE	 = 26,
	OP_RCATLINE	 = 27,
	OP_REGCMAYBE	 = 28,
	OP_REGCRESET	 = 29,
	OP_REGCOMP	 = 30,
	OP_MATCH	 = 31,
	OP_QR		 = 32,
	OP_SUBST	 = 33,
	OP_SUBSTCONT	 = 34,
	OP_TRANS	 = 35,
	OP_TRANSR	 = 36,
	OP_SASSIGN	 = 37,
	OP_AASSIGN	 = 38,
	OP_CHOP		 = 39,
	OP_SCHOP	 = 40,
	OP_CHOMP	 = 41,
	OP_SCHOMP	 = 42,
	OP_DEFINED	 = 43,
	OP_UNDEF	 = 44,
	OP_STUDY	 = 45,
	OP_POS		 = 46,
	OP_PREINC	 = 47,
	OP_I_PREINC	 = 48,
	OP_PREDEC	 = 49,
	OP_I_PREDEC	 = 50,
	OP_POSTINC	 = 51,
	OP_I_POSTINC	 = 52,
	OP_POSTDEC	 = 53,
	OP_I_POSTDEC	 = 54,
	OP_POW		 = 55,
	OP_MULTIPLY	 = 56,
	OP_I_MULTIPLY	 = 57,
	OP_DIVIDE	 = 58,
	OP_I_DIVIDE	 = 59,
	OP_MODULO	 = 60,
	OP_I_MODULO	 = 61,
	OP_REPEAT	 = 62,
	OP_ADD		 = 63,
	OP_I_ADD	 = 64,
	OP_U_ADD	 = 65,
	OP_SUBTRACT	 = 66,
	OP_I_SUBTRACT	 = 67,
	OP_CONCAT	 = 68,
	OP_STRINGIFY	 = 69,
	OP_LEFT_SHIFT	 = 70,
	OP_RIGHT_SHIFT	 = 71,
	OP_LT		 = 72,
	OP_I_LT		 = 73,
	OP_GT		 = 74,
	OP_I_GT		 = 75,
	OP_LE		 = 76,
	OP_I_LE		 = 77,
	OP_GE		 = 78,
	OP_I_GE		 = 79,
	OP_EQ		 = 80,
	OP_I_EQ		 = 81,
	OP_NE		 = 82,
	OP_I_NE		 = 83,
	OP_CMP		 = 84,
	OP_I_CMP	 = 85,
	OP_S_LT		 = 86,
	OP_S_GT		 = 87,
	OP_S_LE		 = 88,
	OP_S_GE		 = 89,
	OP_S_EQ		 = 90,
	OP_S_NE		 = 91,
	OP_S_CMP	 = 92,
	OP_BIT_AND	 = 93,
	OP_BIT_XOR	 = 94,
	OP_BIT_OR	 = 95,
	OP_I_BIT_AND	 = 96,
	OP_I_BIT_XOR	 = 97,
	OP_I_BIT_OR	 = 98,
	OP_S_BIT_AND	 = 99,
	OP_S_BIT_XOR	 = 100,
	OP_S_BIT_OR	 = 101,
	OP_NEGATE	 = 102,
	OP_I_NEGATE	 = 103,
	OP_NOT		 = 104,
	OP_COMPLEMENT	 = 105,
	OP_I_COMPLEMENT	 = 106,
	OP_S_COMPLEMENT	 = 107,
	OP_SMARTMATCH	 = 108,
	OP_ATAN2	 = 109,
	OP_SIN		 = 110,
	OP_COS		 = 111,
	OP_RAND		 = 112,
	OP_SRAND	 = 113,
	OP_EXP		 = 114,
	OP_LOG		 = 115,
	OP_SQRT		 = 116,
	OP_INT		 = 117,
	OP_HEX		 = 118,
	OP_OCT		 = 119,
	OP_ABS		 = 120,
	OP_BOX_INT	 = 121,
	OP_BOX_UINT	 = 122,
	OP_BOX_STR	 = 123,
	OP_BOX_NUM	 = 124,
	OP_UNBOX_INT	 = 125,
	OP_UNBOX_UINT	 = 126,
	OP_UNBOX_STR	 = 127,
	OP_UNBOX_NUM	 = 128,
	OP_UINT_LEFT_SHIFT = 129,
	OP_UINT_RIGHT_SHIFT = 130,
	OP_UINT_POW	 = 131,
	OP_UINT_COMPLEMENT = 132,
	OP_INT_PREINC	 = 133,
	OP_INT_PREDEC	 = 134,
	OP_INT_POSTINC	 = 135,
	OP_INT_POSTDEC	 = 136,
	OP_INT_ADD	 = 137,
	OP_INT_SUBTRACT	 = 138,
	OP_INT_MULTIPLY	 = 139,
	OP_INT_DIVIDE	 = 140,
	OP_INT_MODULO	 = 141,
	OP_INT_NEGATE	 = 142,
	OP_INT_NOT	 = 143,
	OP_INT_ABS	 = 144,
	OP_INT_LT	 = 145,
	OP_INT_GT	 = 146,
	OP_INT_LE	 = 147,
	OP_INT_GE	 = 148,
	OP_INT_EQ	 = 149,
	OP_INT_NE	 = 150,
	OP_NUM_ADD	 = 151,
	OP_NUM_SUBTRACT	 = 152,
	OP_NUM_MULTIPLY	 = 153,
	OP_NUM_DIVIDE	 = 154,
	OP_NUM_ATAN2	 = 155,
	OP_NUM_POW	 = 156,
	OP_NUM_SIN	 = 157,
	OP_NUM_COS	 = 158,
	OP_NUM_EXP	 = 159,
	OP_NUM_LOG	 = 160,
	OP_NUM_SQRT	 = 161,
	OP_LENGTH	 = 162,
	OP_SUBSTR	 = 163,
	OP_VEC		 = 164,
	OP_INDEX	 = 165,
	OP_RINDEX	 = 166,
	OP_SPRINTF	 = 167,
	OP_FORMLINE	 = 168,
	OP_ORD		 = 169,
	OP_CHR		 = 170,
	OP_CRYPT	 = 171,
	OP_UCFIRST	 = 172,
	OP_LCFIRST	 = 173,
	OP_UC		 = 174,
	OP_LC		 = 175,
	OP_QUOTEMETA	 = 176,
	OP_RV2AV	 = 177,
	OP_AELEMFAST	 = 178,
	OP_AELEMFAST_LEX = 179,
	OP_AELEM	 = 180,
	OP_I_AELEM	 = 181,
	OP_N_AELEM	 = 182,
	OP_S_AELEM	 = 183,
	OP_INT_AELEM	 = 184,
	OP_NUM_AELEM	 = 185,
	OP_STR_AELEM	 = 186,
	OP_ASLICE	 = 187,
	OP_KVASLICE	 = 188,
	OP_AEACH	 = 189,
	OP_AKEYS	 = 190,
	OP_AVALUES	 = 191,
	OP_EACH		 = 192,
	OP_VALUES	 = 193,
	OP_KEYS		 = 194,
	OP_DELETE	 = 195,
	OP_EXISTS	 = 196,
	OP_RV2HV	 = 197,
	OP_HELEM	 = 198,
	OP_HSLICE	 = 199,
	OP_KVHSLICE	 = 200,
	OP_MULTIDEREF	 = 201,
	OP_UNPACK	 = 202,
	OP_PACK		 = 203,
	OP_SPLIT	 = 204,
	OP_JOIN		 = 205,
	OP_LIST		 = 206,
	OP_LSLICE	 = 207,
	OP_ANONLIST	 = 208,
	OP_ANONHASH	 = 209,
	OP_SPLICE	 = 210,
	OP_PUSH		 = 211,
	OP_POP		 = 212,
	OP_SHIFT	 = 213,
	OP_UNSHIFT	 = 214,
	OP_SORT		 = 215,
	OP_REVERSE	 = 216,
	OP_GREPSTART	 = 217,
	OP_GREPWHILE	 = 218,
	OP_MAPSTART	 = 219,
	OP_MAPWHILE	 = 220,
	OP_RANGE	 = 221,
	OP_FLIP		 = 222,
	OP_FLOP		 = 223,
	OP_AND		 = 224,
	OP_OR		 = 225,
	OP_XOR		 = 226,
	OP_DOR		 = 227,
	OP_COND_EXPR	 = 228,
	OP_ANDASSIGN	 = 229,
	OP_ORASSIGN	 = 230,
	OP_DORASSIGN	 = 231,
	OP_METHOD	 = 232,
	OP_ENTERSUB	 = 233,
	OP_ENTERXSSUB	 = 234,
	OP_LEAVESUB	 = 235,
	OP_LEAVESUBLV	 = 236,
	OP_CALLER	 = 237,
	OP_WARN		 = 238,
	OP_DIE		 = 239,
	OP_RESET	 = 240,
	OP_LINESEQ	 = 241,
	OP_NEXTSTATE	 = 242,
	OP_DBSTATE	 = 243,
	OP_UNSTACK	 = 244,
	OP_ENTER	 = 245,
	OP_LEAVE	 = 246,
	OP_SCOPE	 = 247,
	OP_ENTERITER	 = 248,
	OP_ITER		 = 249,
	OP_ENTERLOOP	 = 250,
	OP_LEAVELOOP	 = 251,
	OP_RETURN	 = 252,
	OP_LAST		 = 253,
	OP_NEXT		 = 254,
	OP_REDO		 = 255,
	OP_DUMP		 = 256,
	OP_GOTO		 = 257,
	OP_EXIT		 = 258,
	OP_METHOD_NAMED	 = 259,
	OP_METHOD_SUPER	 = 260,
	OP_METHOD_REDIR	 = 261,
	OP_METHOD_REDIR_SUPER = 262,
	OP_ENTERGIVEN	 = 263,
	OP_LEAVEGIVEN	 = 264,
	OP_ENTERWHEN	 = 265,
	OP_LEAVEWHEN	 = 266,
	OP_BREAK	 = 267,
	OP_CONTINUE	 = 268,
	OP_OPEN		 = 269,
	OP_CLOSE	 = 270,
	OP_PIPE_OP	 = 271,
	OP_FILENO	 = 272,
	OP_UMASK	 = 273,
	OP_BINMODE	 = 274,
	OP_TIE		 = 275,
	OP_UNTIE	 = 276,
	OP_TIED		 = 277,
	OP_DBMOPEN	 = 278,
	OP_DBMCLOSE	 = 279,
	OP_SSELECT	 = 280,
	OP_SELECT	 = 281,
	OP_GETC		 = 282,
	OP_READ		 = 283,
	OP_ENTERWRITE	 = 284,
	OP_LEAVEWRITE	 = 285,
	OP_PRTF		 = 286,
	OP_PRINT	 = 287,
	OP_SAY		 = 288,
	OP_SYSOPEN	 = 289,
	OP_SYSSEEK	 = 290,
	OP_SYSREAD	 = 291,
	OP_SYSWRITE	 = 292,
	OP_EOF		 = 293,
	OP_TELL		 = 294,
	OP_SEEK		 = 295,
	OP_TRUNCATE	 = 296,
	OP_FCNTL	 = 297,
	OP_IOCTL	 = 298,
	OP_FLOCK	 = 299,
	OP_SEND		 = 300,
	OP_RECV		 = 301,
	OP_SOCKET	 = 302,
	OP_SOCKPAIR	 = 303,
	OP_BIND		 = 304,
	OP_CONNECT	 = 305,
	OP_LISTEN	 = 306,
	OP_ACCEPT	 = 307,
	OP_SHUTDOWN	 = 308,
	OP_GSOCKOPT	 = 309,
	OP_SSOCKOPT	 = 310,
	OP_GETSOCKNAME	 = 311,
	OP_GETPEERNAME	 = 312,
	OP_LSTAT	 = 313,
	OP_STAT		 = 314,
	OP_FTRREAD	 = 315,
	OP_FTRWRITE	 = 316,
	OP_FTREXEC	 = 317,
	OP_FTEREAD	 = 318,
	OP_FTEWRITE	 = 319,
	OP_FTEEXEC	 = 320,
	OP_FTIS		 = 321,
	OP_FTSIZE	 = 322,
	OP_FTMTIME	 = 323,
	OP_FTATIME	 = 324,
	OP_FTCTIME	 = 325,
	OP_FTROWNED	 = 326,
	OP_FTEOWNED	 = 327,
	OP_FTZERO	 = 328,
	OP_FTSOCK	 = 329,
	OP_FTCHR	 = 330,
	OP_FTBLK	 = 331,
	OP_FTFILE	 = 332,
	OP_FTDIR	 = 333,
	OP_FTPIPE	 = 334,
	OP_FTSUID	 = 335,
	OP_FTSGID	 = 336,
	OP_FTSVTX	 = 337,
	OP_FTLINK	 = 338,
	OP_FTTTY	 = 339,
	OP_FTTEXT	 = 340,
	OP_FTBINARY	 = 341,
	OP_CHDIR	 = 342,
	OP_CHOWN	 = 343,
	OP_CHROOT	 = 344,
	OP_UNLINK	 = 345,
	OP_CHMOD	 = 346,
	OP_UTIME	 = 347,
	OP_RENAME	 = 348,
	OP_LINK		 = 349,
	OP_SYMLINK	 = 350,
	OP_READLINK	 = 351,
	OP_MKDIR	 = 352,
	OP_RMDIR	 = 353,
	OP_OPEN_DIR	 = 354,
	OP_READDIR	 = 355,
	OP_TELLDIR	 = 356,
	OP_SEEKDIR	 = 357,
	OP_REWINDDIR	 = 358,
	OP_CLOSEDIR	 = 359,
	OP_FORK		 = 360,
	OP_WAIT		 = 361,
	OP_WAITPID	 = 362,
	OP_SYSTEM	 = 363,
	OP_EXEC		 = 364,
	OP_KILL		 = 365,
	OP_GETPPID	 = 366,
	OP_GETPGRP	 = 367,
	OP_SETPGRP	 = 368,
	OP_GETPRIORITY	 = 369,
	OP_SETPRIORITY	 = 370,
	OP_TIME		 = 371,
	OP_TMS		 = 372,
	OP_LOCALTIME	 = 373,
	OP_GMTIME	 = 374,
	OP_ALARM	 = 375,
	OP_SLEEP	 = 376,
	OP_SHMGET	 = 377,
	OP_SHMCTL	 = 378,
	OP_SHMREAD	 = 379,
	OP_SHMWRITE	 = 380,
	OP_MSGGET	 = 381,
	OP_MSGCTL	 = 382,
	OP_MSGSND	 = 383,
	OP_MSGRCV	 = 384,
	OP_SEMOP	 = 385,
	OP_SEMGET	 = 386,
	OP_SEMCTL	 = 387,
	OP_REQUIRE	 = 388,
	OP_DOFILE	 = 389,
	OP_HINTSEVAL	 = 390,
	OP_ENTEREVAL	 = 391,
	OP_LEAVEEVAL	 = 392,
	OP_ENTERTRY	 = 393,
	OP_LEAVETRY	 = 394,
	OP_GHBYNAME	 = 395,
	OP_GHBYADDR	 = 396,
	OP_GHOSTENT	 = 397,
	OP_GNBYNAME	 = 398,
	OP_GNBYADDR	 = 399,
	OP_GNETENT	 = 400,
	OP_GPBYNAME	 = 401,
	OP_GPBYNUMBER	 = 402,
	OP_GPROTOENT	 = 403,
	OP_GSBYNAME	 = 404,
	OP_GSBYPORT	 = 405,
	OP_GSERVENT	 = 406,
	OP_SHOSTENT	 = 407,
	OP_SNETENT	 = 408,
	OP_SPROTOENT	 = 409,
	OP_SSERVENT	 = 410,
	OP_EHOSTENT	 = 411,
	OP_ENETENT	 = 412,
	OP_EPROTOENT	 = 413,
	OP_ESERVENT	 = 414,
	OP_GPWNAM	 = 415,
	OP_GPWUID	 = 416,
	OP_GPWENT	 = 417,
	OP_SPWENT	 = 418,
	OP_EPWENT	 = 419,
	OP_GGRNAM	 = 420,
	OP_GGRGID	 = 421,
	OP_GGRENT	 = 422,
	OP_SGRENT	 = 423,
	OP_EGRENT	 = 424,
	OP_GETLOGIN	 = 425,
	OP_SYSCALL	 = 426,
	OP_LOCK		 = 427,
	OP_ONCE		 = 428,
	OP_CUSTOM	 = 429,
	OP_REACH	 = 430,
	OP_RKEYS	 = 431,
	OP_RVALUES	 = 432,
	OP_COREARGS	 = 433,
	OP_RUNCV	 = 434,
	OP_FC		 = 435,
	OP_PADCV	 = 436,
	OP_INTROCV	 = 437,
	OP_CLONECV	 = 438,
	OP_PADRANGE	 = 439,
	OP_REFASSIGN	 = 440,
	OP_LVREF	 = 441,
	OP_LVREFSLICE	 = 442,
	OP_LVAVREF	 = 443,
	OP_ANONCONST	 = 444,
	OP_max		
} opcode;

#define MAXO 445
#define OP_FREED MAXO


/* This encodes the offsets as signed char of the typed variants for each op.
   The first byte is the number of following bytes, max 8.
   variants: u_ i_ n_ s_ int_ uint_ num_ str_ */
#ifndef DOINIT
EXTCONST const char PL_op_type_variants[][8];
#else
EXTCONST const char PL_op_type_variants[][8] = {
	/*   0 null             */ {0},	/*  */
	/*   1 stub             */ {0},	/*  */
	/*   2 scalar           */ {0},	/*  */
	/*   3 pushmark         */ {0},	/*  */
	/*   4 wantarray        */ {0},	/*  */
	/*   5 const            */ {0},	/*  */
	/*   6 gvsv             */ {0},	/*  */
	/*   7 gv               */ {0},	/*  */
	/*   8 gelem            */ {0},	/*  */
	/*   9 padsv            */ {0},	/*  */
	/*  10 padav            */ {0},	/*  */
	/*  11 padhv            */ {0},	/*  */
	/*  12 padany           */ {0},	/*  */
	/*  13 pushre           */ {0},	/*  */
	/*  14 rv2gv            */ {0},	/*  */
	/*  15 rv2sv            */ {0},	/*  */
	/*  16 av2arylen        */ {0},	/*  */
	/*  17 rv2cv            */ {0},	/*  */
	/*  18 anoncode         */ {0},	/*  */
	/*  19 prototype        */ {0},	/*  */
	/*  20 refgen           */ {0},	/*  */
	/*  21 srefgen          */ {0},	/*  */
	/*  22 ref              */ {0},	/*  */
	/*  23 bless            */ {0},	/*  */
	/*  24 backtick         */ {0},	/*  */
	/*  25 glob             */ {0},	/*  */
	/*  26 readline         */ {0},	/*  */
	/*  27 rcatline         */ {0},	/*  */
	/*  28 regcmaybe        */ {0},	/*  */
	/*  29 regcreset        */ {0},	/*  */
	/*  30 regcomp          */ {0},	/*  */
	/*  31 match            */ {0},	/*  */
	/*  32 qr               */ {0},	/*  */
	/*  33 subst            */ {0},	/*  */
	/*  34 substcont        */ {0},	/*  */
	/*  35 trans            */ {0},	/*  */
	/*  36 transr           */ {0},	/*  */
	/*  37 sassign          */ {0},	/*  */
	/*  38 aassign          */ {0},	/*  */
	/*  39 chop             */ {0},	/*  */
	/*  40 schop            */ {0},	/*  */
	/*  41 chomp            */ {0},	/*  */
	/*  42 schomp           */ {0},	/*  */
	/*  43 defined          */ {0},	/*  */
	/*  44 undef            */ {0},	/*  */
	/*  45 study            */ {0},	/*  */
	/*  46 pos              */ {0},	/*  */
	/*  47 preinc           */ {2,1,86},	/* i_preinc:48 int_preinc:133 */
	/*  48 i_preinc         */ {1,85},	/* int_preinc:133 */
	/*  49 predec           */ {2,1,85},	/* i_predec:50 int_predec:134 */
	/*  50 i_predec         */ {1,84},	/* int_predec:134 */
	/*  51 postinc          */ {2,1,84},	/* i_postinc:52 int_postinc:135 */
	/*  52 i_postinc        */ {1,83},	/* int_postinc:135 */
	/*  53 postdec          */ {2,1,83},	/* i_postdec:54 int_postdec:136 */
	/*  54 i_postdec        */ {1,82},	/* int_postdec:136 */
	/*  55 pow              */ {2,76,101},	/* uint_pow:131 num_pow:156 */
	/*  56 multiply         */ {3,1,83,97},	/* i_multiply:57 int_multiply:139 num_multiply:153 */
	/*  57 i_multiply       */ {1,82},	/* int_multiply:139 */
	/*  58 divide           */ {3,1,82,96},	/* i_divide:59 int_divide:140 num_divide:154 */
	/*  59 i_divide         */ {1,81},	/* int_divide:140 */
	/*  60 modulo           */ {2,1,81},	/* i_modulo:61 int_modulo:141 */
	/*  61 i_modulo         */ {1,80},	/* int_modulo:141 */
	/*  62 repeat           */ {0},	/*  */
	/*  63 add              */ {4,2,1,74,88},	/* u_add:65 i_add:64 int_add:137 num_add:151 */
	/*  64 i_add            */ {1,73},	/* int_add:137 */
	/*  65 u_add            */ {0},	/*  */
	/*  66 subtract         */ {3,1,72,86},	/* i_subtract:67 int_subtract:138 num_subtract:152 */
	/*  67 i_subtract       */ {1,71},	/* int_subtract:138 */
	/*  68 concat           */ {0},	/*  */
	/*  69 stringify        */ {0},	/*  */
	/*  70 left_shift       */ {1,59},	/* uint_left_shift:129 */
	/*  71 right_shift      */ {1,59},	/* uint_right_shift:130 */
	/*  72 lt               */ {3,1,14,73},	/* i_lt:73 s_lt:86 int_lt:145 */
	/*  73 i_lt             */ {1,72},	/* int_lt:145 */
	/*  74 gt               */ {3,1,13,72},	/* i_gt:75 s_gt:87 int_gt:146 */
	/*  75 i_gt             */ {1,71},	/* int_gt:146 */
	/*  76 le               */ {3,1,12,71},	/* i_le:77 s_le:88 int_le:147 */
	/*  77 i_le             */ {1,70},	/* int_le:147 */
	/*  78 ge               */ {3,1,11,70},	/* i_ge:79 s_ge:89 int_ge:148 */
	/*  79 i_ge             */ {1,69},	/* int_ge:148 */
	/*  80 eq               */ {3,1,10,69},	/* i_eq:81 s_eq:90 int_eq:149 */
	/*  81 i_eq             */ {1,68},	/* int_eq:149 */
	/*  82 ne               */ {3,1,9,68},	/* i_ne:83 s_ne:91 int_ne:150 */
	/*  83 i_ne             */ {1,67},	/* int_ne:150 */
	/*  84 cmp              */ {2,1,8},	/* i_cmp:85 s_cmp:92 */
	/*  85 i_cmp            */ {0},	/*  */
	/*  86 s_lt             */ {0},	/*  */
	/*  87 s_gt             */ {0},	/*  */
	/*  88 s_le             */ {0},	/*  */
	/*  89 s_ge             */ {0},	/*  */
	/*  90 s_eq             */ {0},	/*  */
	/*  91 s_ne             */ {0},	/*  */
	/*  92 s_cmp            */ {0},	/*  */
	/*  93 bit_and          */ {2,3,6},	/* i_bit_and:96 s_bit_and:99 */
	/*  94 bit_xor          */ {2,3,6},	/* i_bit_xor:97 s_bit_xor:100 */
	/*  95 bit_or           */ {2,3,6},	/* i_bit_or:98 s_bit_or:101 */
	/*  96 i_bit_and        */ {0},	/*  */
	/*  97 i_bit_xor        */ {0},	/*  */
	/*  98 i_bit_or         */ {0},	/*  */
	/*  99 s_bit_and        */ {0},	/*  */
	/* 100 s_bit_xor        */ {0},	/*  */
	/* 101 s_bit_or         */ {0},	/*  */
	/* 102 negate           */ {2,1,40},	/* i_negate:103 int_negate:142 */
	/* 103 i_negate         */ {1,39},	/* int_negate:142 */
	/* 104 not              */ {1,39},	/* int_not:143 */
	/* 105 complement       */ {3,1,2,27},	/* i_complement:106 s_complement:107 uint_complement:132 */
	/* 106 i_complement     */ {1,26},	/* uint_complement:132 */
	/* 107 s_complement     */ {0},	/*  */
	/* 108 smartmatch       */ {0},	/*  */
	/* 109 atan2            */ {1,46},	/* num_atan2:155 */
	/* 110 sin              */ {1,47},	/* num_sin:157 */
	/* 111 cos              */ {1,47},	/* num_cos:158 */
	/* 112 rand             */ {0},	/*  */
	/* 113 srand            */ {0},	/*  */
	/* 114 exp              */ {1,45},	/* num_exp:159 */
	/* 115 log              */ {1,45},	/* num_log:160 */
	/* 116 sqrt             */ {1,45},	/* num_sqrt:161 */
	/* 117 int              */ {0},	/*  */
	/* 118 hex              */ {0},	/*  */
	/* 119 oct              */ {0},	/*  */
	/* 120 abs              */ {1,24},	/* int_abs:144 */
	/* 121 box_int          */ {0},	/*  */
	/* 122 box_uint         */ {0},	/*  */
	/* 123 box_str          */ {0},	/*  */
	/* 124 box_num          */ {0},	/*  */
	/* 125 unbox_int        */ {0},	/*  */
	/* 126 unbox_uint       */ {0},	/*  */
	/* 127 unbox_str        */ {0},	/*  */
	/* 128 unbox_num        */ {0},	/*  */
	/* 129 uint_left_shift  */ {0},	/*  */
	/* 130 uint_right_shift */ {0},	/*  */
	/* 131 uint_pow         */ {0},	/*  */
	/* 132 uint_complement  */ {0},	/*  */
	/* 133 int_preinc       */ {0},	/*  */
	/* 134 int_predec       */ {0},	/*  */
	/* 135 int_postinc      */ {0},	/*  */
	/* 136 int_postdec      */ {0},	/*  */
	/* 137 int_add          */ {0},	/*  */
	/* 138 int_subtract     */ {0},	/*  */
	/* 139 int_multiply     */ {0},	/*  */
	/* 140 int_divide       */ {0},	/*  */
	/* 141 int_modulo       */ {0},	/*  */
	/* 142 int_negate       */ {0},	/*  */
	/* 143 int_not          */ {0},	/*  */
	/* 144 int_abs          */ {0},	/*  */
	/* 145 int_lt           */ {0},	/*  */
	/* 146 int_gt           */ {0},	/*  */
	/* 147 int_le           */ {0},	/*  */
	/* 148 int_ge           */ {0},	/*  */
	/* 149 int_eq           */ {0},	/*  */
	/* 150 int_ne           */ {0},	/*  */
	/* 151 num_add          */ {0},	/*  */
	/* 152 num_subtract     */ {0},	/*  */
	/* 153 num_multiply     */ {0},	/*  */
	/* 154 num_divide       */ {0},	/*  */
	/* 155 num_atan2        */ {0},	/*  */
	/* 156 num_pow          */ {0},	/*  */
	/* 157 num_sin          */ {0},	/*  */
	/* 158 num_cos          */ {0},	/*  */
	/* 159 num_exp          */ {0},	/*  */
	/* 160 num_log          */ {0},	/*  */
	/* 161 num_sqrt         */ {0},	/*  */
	/* 162 length           */ {0},	/*  */
	/* 163 substr           */ {0},	/*  */
	/* 164 vec              */ {0},	/*  */
	/* 165 index            */ {0},	/*  */
	/* 166 rindex           */ {0},	/*  */
	/* 167 sprintf          */ {0},	/*  */
	/* 168 formline         */ {0},	/*  */
	/* 169 ord              */ {0},	/*  */
	/* 170 chr              */ {0},	/*  */
	/* 171 crypt            */ {0},	/*  */
	/* 172 ucfirst          */ {0},	/*  */
	/* 173 lcfirst          */ {0},	/*  */
	/* 174 uc               */ {0},	/*  */
	/* 175 lc               */ {0},	/*  */
	/* 176 quotemeta        */ {0},	/*  */
	/* 177 rv2av            */ {0},	/*  */
	/* 178 aelemfast        */ {0},	/*  */
	/* 179 aelemfast_lex    */ {0},	/*  */
	/* 180 aelem            */ {6,1,2,3,4,5,6},	/* i_aelem:181 n_aelem:182 s_aelem:183 int_aelem:184 num_aelem:185 str_aelem:186 */
	/* 181 i_aelem          */ {1,3},	/* int_aelem:184 */
	/* 182 n_aelem          */ {1,3},	/* num_aelem:185 */
	/* 183 s_aelem          */ {1,3},	/* str_aelem:186 */
	/* 184 int_aelem        */ {0},	/*  */
	/* 185 num_aelem        */ {0},	/*  */
	/* 186 str_aelem        */ {0},	/*  */
	/* 187 aslice           */ {0},	/*  */
	/* 188 kvaslice         */ {0},	/*  */
	/* 189 aeach            */ {0},	/*  */
	/* 190 akeys            */ {0},	/*  */
	/* 191 avalues          */ {0},	/*  */
	/* 192 each             */ {0},	/*  */
	/* 193 values           */ {0},	/*  */
	/* 194 keys             */ {0},	/*  */
	/* 195 delete           */ {0},	/*  */
	/* 196 exists           */ {0},	/*  */
	/* 197 rv2hv            */ {0},	/*  */
	/* 198 helem            */ {0},	/*  */
	/* 199 hslice           */ {0},	/*  */
	/* 200 kvhslice         */ {0},	/*  */
	/* 201 multideref       */ {0},	/*  */
	/* 202 unpack           */ {0},	/*  */
	/* 203 pack             */ {0},	/*  */
	/* 204 split            */ {0},	/*  */
	/* 205 join             */ {0},	/*  */
	/* 206 list             */ {0},	/*  */
	/* 207 lslice           */ {0},	/*  */
	/* 208 anonlist         */ {0},	/*  */
	/* 209 anonhash         */ {0},	/*  */
	/* 210 splice           */ {0},	/*  */
	/* 211 push             */ {0},	/*  */
	/* 212 pop              */ {0},	/*  */
	/* 213 shift            */ {0},	/*  */
	/* 214 unshift          */ {0},	/*  */
	/* 215 sort             */ {0},	/*  */
	/* 216 reverse          */ {0},	/*  */
	/* 217 grepstart        */ {0},	/*  */
	/* 218 grepwhile        */ {0},	/*  */
	/* 219 mapstart         */ {0},	/*  */
	/* 220 mapwhile         */ {0},	/*  */
	/* 221 range            */ {0},	/*  */
	/* 222 flip             */ {0},	/*  */
	/* 223 flop             */ {0},	/*  */
	/* 224 and              */ {0},	/*  */
	/* 225 or               */ {0},	/*  */
	/* 226 xor              */ {0},	/*  */
	/* 227 dor              */ {0},	/*  */
	/* 228 cond_expr        */ {0},	/*  */
	/* 229 andassign        */ {0},	/*  */
	/* 230 orassign         */ {0},	/*  */
	/* 231 dorassign        */ {0},	/*  */
	/* 232 method           */ {0},	/*  */
	/* 233 entersub         */ {0},	/*  */
	/* 234 enterxssub       */ {0},	/*  */
	/* 235 leavesub         */ {0},	/*  */
	/* 236 leavesublv       */ {0},	/*  */
	/* 237 caller           */ {0},	/*  */
	/* 238 warn             */ {0},	/*  */
	/* 239 die              */ {0},	/*  */
	/* 240 reset            */ {0},	/*  */
	/* 241 lineseq          */ {0},	/*  */
	/* 242 nextstate        */ {0},	/*  */
	/* 243 dbstate          */ {0},	/*  */
	/* 244 unstack          */ {0},	/*  */
	/* 245 enter            */ {0},	/*  */
	/* 246 leave            */ {0},	/*  */
	/* 247 scope            */ {0},	/*  */
	/* 248 enteriter        */ {0},	/*  */
	/* 249 iter             */ {0},	/*  */
	/* 250 enterloop        */ {0},	/*  */
	/* 251 leaveloop        */ {0},	/*  */
	/* 252 return           */ {0},	/*  */
	/* 253 last             */ {0},	/*  */
	/* 254 next             */ {0},	/*  */
	/* 255 redo             */ {0},	/*  */
	/* 256 dump             */ {0},	/*  */
	/* 257 goto             */ {0},	/*  */
	/* 258 exit             */ {0},	/*  */
	/* 259 method_named     */ {0},	/*  */
	/* 260 method_super     */ {0},	/*  */
	/* 261 method_redir     */ {0},	/*  */
	/* 262 method_redir_super */ {0},	/*  */
	/* 263 entergiven       */ {0},	/*  */
	/* 264 leavegiven       */ {0},	/*  */
	/* 265 enterwhen        */ {0},	/*  */
	/* 266 leavewhen        */ {0},	/*  */
	/* 267 break            */ {0},	/*  */
	/* 268 continue         */ {0},	/*  */
	/* 269 open             */ {0},	/*  */
	/* 270 close            */ {0},	/*  */
	/* 271 pipe_op          */ {0},	/*  */
	/* 272 fileno           */ {0},	/*  */
	/* 273 umask            */ {0},	/*  */
	/* 274 binmode          */ {0},	/*  */
	/* 275 tie              */ {0},	/*  */
	/* 276 untie            */ {0},	/*  */
	/* 277 tied             */ {0},	/*  */
	/* 278 dbmopen          */ {0},	/*  */
	/* 279 dbmclose         */ {0},	/*  */
	/* 280 sselect          */ {0},	/*  */
	/* 281 select           */ {0},	/*  */
	/* 282 getc             */ {0},	/*  */
	/* 283 read             */ {0},	/*  */
	/* 284 enterwrite       */ {0},	/*  */
	/* 285 leavewrite       */ {0},	/*  */
	/* 286 prtf             */ {0},	/*  */
	/* 287 print            */ {0},	/*  */
	/* 288 say              */ {0},	/*  */
	/* 289 sysopen          */ {0},	/*  */
	/* 290 sysseek          */ {0},	/*  */
	/* 291 sysread          */ {0},	/*  */
	/* 292 syswrite         */ {0},	/*  */
	/* 293 eof              */ {0},	/*  */
	/* 294 tell             */ {0},	/*  */
	/* 295 seek             */ {0},	/*  */
	/* 296 truncate         */ {0},	/*  */
	/* 297 fcntl            */ {0},	/*  */
	/* 298 ioctl            */ {0},	/*  */
	/* 299 flock            */ {0},	/*  */
	/* 300 send             */ {0},	/*  */
	/* 301 recv             */ {0},	/*  */
	/* 302 socket           */ {0},	/*  */
	/* 303 sockpair         */ {0},	/*  */
	/* 304 bind             */ {0},	/*  */
	/* 305 connect          */ {0},	/*  */
	/* 306 listen           */ {0},	/*  */
	/* 307 accept           */ {0},	/*  */
	/* 308 shutdown         */ {0},	/*  */
	/* 309 gsockopt         */ {0},	/*  */
	/* 310 ssockopt         */ {0},	/*  */
	/* 311 getsockname      */ {0},	/*  */
	/* 312 getpeername      */ {0},	/*  */
	/* 313 lstat            */ {0},	/*  */
	/* 314 stat             */ {0},	/*  */
	/* 315 ftrread          */ {0},	/*  */
	/* 316 ftrwrite         */ {0},	/*  */
	/* 317 ftrexec          */ {0},	/*  */
	/* 318 fteread          */ {0},	/*  */
	/* 319 ftewrite         */ {0},	/*  */
	/* 320 fteexec          */ {0},	/*  */
	/* 321 ftis             */ {0},	/*  */
	/* 322 ftsize           */ {0},	/*  */
	/* 323 ftmtime          */ {0},	/*  */
	/* 324 ftatime          */ {0},	/*  */
	/* 325 ftctime          */ {0},	/*  */
	/* 326 ftrowned         */ {0},	/*  */
	/* 327 fteowned         */ {0},	/*  */
	/* 328 ftzero           */ {0},	/*  */
	/* 329 ftsock           */ {0},	/*  */
	/* 330 ftchr            */ {0},	/*  */
	/* 331 ftblk            */ {0},	/*  */
	/* 332 ftfile           */ {0},	/*  */
	/* 333 ftdir            */ {0},	/*  */
	/* 334 ftpipe           */ {0},	/*  */
	/* 335 ftsuid           */ {0},	/*  */
	/* 336 ftsgid           */ {0},	/*  */
	/* 337 ftsvtx           */ {0},	/*  */
	/* 338 ftlink           */ {0},	/*  */
	/* 339 fttty            */ {0},	/*  */
	/* 340 fttext           */ {0},	/*  */
	/* 341 ftbinary         */ {0},	/*  */
	/* 342 chdir            */ {0},	/*  */
	/* 343 chown            */ {0},	/*  */
	/* 344 chroot           */ {0},	/*  */
	/* 345 unlink           */ {0},	/*  */
	/* 346 chmod            */ {0},	/*  */
	/* 347 utime            */ {0},	/*  */
	/* 348 rename           */ {0},	/*  */
	/* 349 link             */ {0},	/*  */
	/* 350 symlink          */ {0},	/*  */
	/* 351 readlink         */ {0},	/*  */
	/* 352 mkdir            */ {0},	/*  */
	/* 353 rmdir            */ {0},	/*  */
	/* 354 open_dir         */ {0},	/*  */
	/* 355 readdir          */ {0},	/*  */
	/* 356 telldir          */ {0},	/*  */
	/* 357 seekdir          */ {0},	/*  */
	/* 358 rewinddir        */ {0},	/*  */
	/* 359 closedir         */ {0},	/*  */
	/* 360 fork             */ {0},	/*  */
	/* 361 wait             */ {0},	/*  */
	/* 362 waitpid          */ {0},	/*  */
	/* 363 system           */ {0},	/*  */
	/* 364 exec             */ {0},	/*  */
	/* 365 kill             */ {0},	/*  */
	/* 366 getppid          */ {0},	/*  */
	/* 367 getpgrp          */ {0},	/*  */
	/* 368 setpgrp          */ {0},	/*  */
	/* 369 getpriority      */ {0},	/*  */
	/* 370 setpriority      */ {0},	/*  */
	/* 371 time             */ {0},	/*  */
	/* 372 tms              */ {0},	/*  */
	/* 373 localtime        */ {0},	/*  */
	/* 374 gmtime           */ {0},	/*  */
	/* 375 alarm            */ {0},	/*  */
	/* 376 sleep            */ {0},	/*  */
	/* 377 shmget           */ {0},	/*  */
	/* 378 shmctl           */ {0},	/*  */
	/* 379 shmread          */ {0},	/*  */
	/* 380 shmwrite         */ {0},	/*  */
	/* 381 msgget           */ {0},	/*  */
	/* 382 msgctl           */ {0},	/*  */
	/* 383 msgsnd           */ {0},	/*  */
	/* 384 msgrcv           */ {0},	/*  */
	/* 385 semop            */ {0},	/*  */
	/* 386 semget           */ {0},	/*  */
	/* 387 semctl           */ {0},	/*  */
	/* 388 require          */ {0},	/*  */
	/* 389 dofile           */ {0},	/*  */
	/* 390 hintseval        */ {0},	/*  */
	/* 391 entereval        */ {0},	/*  */
	/* 392 leaveeval        */ {0},	/*  */
	/* 393 entertry         */ {0},	/*  */
	/* 394 leavetry         */ {0},	/*  */
	/* 395 ghbyname         */ {0},	/*  */
	/* 396 ghbyaddr         */ {0},	/*  */
	/* 397 ghostent         */ {0},	/*  */
	/* 398 gnbyname         */ {0},	/*  */
	/* 399 gnbyaddr         */ {0},	/*  */
	/* 400 gnetent          */ {0},	/*  */
	/* 401 gpbyname         */ {0},	/*  */
	/* 402 gpbynumber       */ {0},	/*  */
	/* 403 gprotoent        */ {0},	/*  */
	/* 404 gsbyname         */ {0},	/*  */
	/* 405 gsbyport         */ {0},	/*  */
	/* 406 gservent         */ {0},	/*  */
	/* 407 shostent         */ {0},	/*  */
	/* 408 snetent          */ {0},	/*  */
	/* 409 sprotoent        */ {0},	/*  */
	/* 410 sservent         */ {0},	/*  */
	/* 411 ehostent         */ {0},	/*  */
	/* 412 enetent          */ {0},	/*  */
	/* 413 eprotoent        */ {0},	/*  */
	/* 414 eservent         */ {0},	/*  */
	/* 415 gpwnam           */ {0},	/*  */
	/* 416 gpwuid           */ {0},	/*  */
	/* 417 gpwent           */ {0},	/*  */
	/* 418 spwent           */ {0},	/*  */
	/* 419 epwent           */ {0},	/*  */
	/* 420 ggrnam           */ {0},	/*  */
	/* 421 ggrgid           */ {0},	/*  */
	/* 422 ggrent           */ {0},	/*  */
	/* 423 sgrent           */ {0},	/*  */
	/* 424 egrent           */ {0},	/*  */
	/* 425 getlogin         */ {0},	/*  */
	/* 426 syscall          */ {0},	/*  */
	/* 427 lock             */ {0},	/*  */
	/* 428 once             */ {0},	/*  */
	/* 429 custom           */ {0},	/*  */
	/* 430 reach            */ {0},	/*  */
	/* 431 rkeys            */ {0},	/*  */
	/* 432 rvalues          */ {0},	/*  */
	/* 433 coreargs         */ {0},	/*  */
	/* 434 runcv            */ {0},	/*  */
	/* 435 fc               */ {0},	/*  */
	/* 436 padcv            */ {0},	/*  */
	/* 437 introcv          */ {0},	/*  */
	/* 438 clonecv          */ {0},	/*  */
	/* 439 padrange         */ {0},	/*  */
	/* 440 refassign        */ {0},	/*  */
	/* 441 lvref            */ {0},	/*  */
	/* 442 lvrefslice       */ {0},	/*  */
	/* 443 lvavref          */ {0},	/*  */
	/* 444 anonconst        */ {0},	/*  */
	/* 445: freed */	{ NULL }
};
#endif

#define NUM_OP_TYPE_VARIANTS(op) PL_op_type_variants[op][0]

/* for 1 to num */
#define OP_TYPE_VARIANT(op, _j) \
  (PL_op_type_variants[(op)][(_j)] \
    ? (op) + PL_op_type_variants[(op)][(_j)] \
    : 0)


/* the OP_IS_* macros are optimized to a simple range check because
    all the member OPs are contiguous in regen/opcodes table.
    opcode.pl verifies the range contiguity, or generates an OR-equals
    expression */

#define OP_IS_SOCKET(op)	\
	((op) >= OP_SEND && (op) <= OP_GETPEERNAME)

#define OP_IS_FILETEST(op)	\
	((op) >= OP_FTRREAD && (op) <= OP_FTBINARY)

#define OP_IS_FILETEST_ACCESS(op)	\
	((op) >= OP_FTRREAD && (op) <= OP_FTEEXEC)

#define OP_IS_NUMCOMPARE(op)	\
	((op) >= OP_LT && (op) <= OP_I_CMP)

#define OP_IS_DIRHOP(op)	\
	((op) >= OP_READDIR && (op) <= OP_CLOSEDIR)

#define OP_IS_INFIX_BIT(op)	\
	((op) >= OP_BIT_AND && (op) <= OP_S_BIT_OR)

/* backcompat old Perl 5 names: */
#if 1
#define OP_NCMP		 OP_CMP
#define OP_I_NCMP	 OP_I_CMP
#define OP_SLT		 OP_S_LT
#define OP_SGT		 OP_S_GT
#define OP_SLE		 OP_S_LE
#define OP_SGE		 OP_S_GE
#define OP_SEQ		 OP_S_EQ
#define OP_SNE		 OP_S_NE
#define OP_SCMP		 OP_S_CMP
#define OP_NBIT_AND	 OP_I_BIT_AND
#define OP_NBIT_XOR	 OP_I_BIT_XOR
#define OP_NBIT_OR	 OP_I_BIT_OR
#define OP_SBIT_AND	 OP_S_BIT_AND
#define OP_SBIT_XOR	 OP_S_BIT_XOR
#define OP_SBIT_OR	 OP_S_BIT_OR
#define OP_NCOMPLEMENT	 OP_I_COMPLEMENT
#define OP_SCOMPLEMENT	 OP_S_COMPLEMENT

#define Perl_pp_ncmp	 Perl_pp_cmp
#define Perl_pp_i_ncmp	 Perl_pp_i_cmp
#define Perl_pp_slt	 Perl_pp_s_lt
#define Perl_pp_sgt	 Perl_pp_s_gt
#define Perl_pp_sle	 Perl_pp_s_le
#define Perl_pp_sge	 Perl_pp_s_ge
#define Perl_pp_seq	 Perl_pp_s_eq
#define Perl_pp_sne	 Perl_pp_s_ne
#define Perl_pp_scmp	 Perl_pp_s_cmp
#define Perl_pp_nbit_and Perl_pp_i_bit_and
#define Perl_pp_nbit_xor Perl_pp_i_bit_xor
#define Perl_pp_nbit_or	 Perl_pp_i_bit_or
#define Perl_pp_sbit_and Perl_pp_s_bit_and
#define Perl_pp_sbit_xor Perl_pp_s_bit_xor
#define Perl_pp_sbit_or	 Perl_pp_s_bit_or
#define Perl_pp_ncomplement Perl_pp_i_complement
#define Perl_pp_scomplement Perl_pp_s_complement
#endif

/* ex: set ro: */
