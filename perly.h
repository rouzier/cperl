/* ex: set ro ft=c: -*- mode: c; buffer-read-only: t -*-
   !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
   This file is built by regen_perly.pl from perly.y.
   Any changes made here will be lost!
 */

#define PERL_BISON_VERSION  30000

#ifdef PERL_CORE
/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    GRAMPROG = 258,
    GRAMEXPR = 259,
    GRAMBLOCK = 260,
    GRAMBARESTMT = 261,
    GRAMFULLSTMT = 262,
    GRAMSTMTSEQ = 263,
    BAREWORD = 264,
    METHOD = 265,
    FUNCMETH = 266,
    THING = 267,
    PMFUNC = 268,
    PRIVATEREF = 269,
    QWLIST = 270,
    FUNC0OP = 271,
    FUNC0SUB = 272,
    UNIOPSUB = 273,
    LSTOPSUB = 274,
    PLUGEXPR = 275,
    PLUGSTMT = 276,
    CLASSDECL = 277,
    LABEL = 278,
    FORMAT = 279,
    SUB = 280,
    METHDECL = 281,
    MULTIDECL = 282,
    ANONSUB = 283,
    PACKAGE = 284,
    USE = 285,
    WHILE = 286,
    UNTIL = 287,
    IF = 288,
    UNLESS = 289,
    ELSE = 290,
    ELSIF = 291,
    CONTINUE = 292,
    FOR = 293,
    GIVEN = 294,
    WHEN = 295,
    DEFAULT = 296,
    LOOPEX = 297,
    DOTDOT = 298,
    YADAYADA = 299,
    FUNC0 = 300,
    FUNC1 = 301,
    FUNC = 302,
    UNIOP = 303,
    LSTOP = 304,
    RELOP = 305,
    EQOP = 306,
    MULOP = 307,
    UNIMULOP = 308,
    ADDOP = 309,
    DOLSHARP = 310,
    DO = 311,
    HASHBRACK = 312,
    NOAMP = 313,
    LOCAL = 314,
    MY = 315,
    HAS = 316,
    REQUIRE = 317,
    COLONATTR = 318,
    FORMLBRACK = 319,
    FORMRBRACK = 320,
    PREC_LOW = 321,
    OROP = 322,
    DOROP = 323,
    ANDOP = 324,
    NOTOP = 325,
    ASSIGNOP = 326,
    OROR = 327,
    DORDOR = 328,
    ANDAND = 329,
    BITOROP = 330,
    BITANDOP = 331,
    SHIFTOP = 332,
    MATCHOP = 333,
    UMINUS = 334,
    REFGEN = 335,
    POWOP = 336,
    POWCOP = 337,
    PREINC = 338,
    PREDEC = 339,
    POSTINC = 340,
    POSTDEC = 341,
    POSTJOIN = 342,
    ARROW = 343
  };
#endif

/* Tokens.  */
#define GRAMPROG 258
#define GRAMEXPR 259
#define GRAMBLOCK 260
#define GRAMBARESTMT 261
#define GRAMFULLSTMT 262
#define GRAMSTMTSEQ 263
#define BAREWORD 264
#define METHOD 265
#define FUNCMETH 266
#define THING 267
#define PMFUNC 268
#define PRIVATEREF 269
#define QWLIST 270
#define FUNC0OP 271
#define FUNC0SUB 272
#define UNIOPSUB 273
#define LSTOPSUB 274
#define PLUGEXPR 275
#define PLUGSTMT 276
#define CLASSDECL 277
#define LABEL 278
#define FORMAT 279
#define SUB 280
#define METHDECL 281
#define MULTIDECL 282
#define ANONSUB 283
#define PACKAGE 284
#define USE 285
#define WHILE 286
#define UNTIL 287
#define IF 288
#define UNLESS 289
#define ELSE 290
#define ELSIF 291
#define CONTINUE 292
#define FOR 293
#define GIVEN 294
#define WHEN 295
#define DEFAULT 296
#define LOOPEX 297
#define DOTDOT 298
#define YADAYADA 299
#define FUNC0 300
#define FUNC1 301
#define FUNC 302
#define UNIOP 303
#define LSTOP 304
#define RELOP 305
#define EQOP 306
#define MULOP 307
#define UNIMULOP 308
#define ADDOP 309
#define DOLSHARP 310
#define DO 311
#define HASHBRACK 312
#define NOAMP 313
#define LOCAL 314
#define MY 315
#define HAS 316
#define REQUIRE 317
#define COLONATTR 318
#define FORMLBRACK 319
#define FORMRBRACK 320
#define PREC_LOW 321
#define OROP 322
#define DOROP 323
#define ANDOP 324
#define NOTOP 325
#define ASSIGNOP 326
#define OROR 327
#define DORDOR 328
#define ANDAND 329
#define BITOROP 330
#define BITANDOP 331
#define SHIFTOP 332
#define MATCHOP 333
#define UMINUS 334
#define REFGEN 335
#define POWOP 336
#define POWCOP 337
#define PREINC 338
#define PREDEC 339
#define POSTINC 340
#define POSTDEC 341
#define POSTJOIN 342
#define ARROW 343

/* Value type.  */
#ifdef PERL_IN_TOKE_C
static bool
S_is_opval_token(int type) {
    switch (type) {
    case BAREWORD:
    case CLASSDECL:
    case FUNC0OP:
    case FUNC0SUB:
    case FUNCMETH:
    case LSTOPSUB:
    case METHOD:
    case PLUGEXPR:
    case PLUGSTMT:
    case PMFUNC:
    case PRIVATEREF:
    case QWLIST:
    case THING:
    case UNIOPSUB:
	return 1;
    }
    return 0;
}
#endif /* PERL_IN_TOKE_C */
#endif /* PERL_CORE */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{

    I32	ival; /* __DEFAULT__ (marker for regen_perly.pl;
				must always be 1st union member) */
    char *pval;
    OP *opval;
    GV *gvval;

};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void);


#if YYDEBUG
#define YYPRINT
#endif

/* Generated from:
 * 0893235f124b7829b2f47ba7c3bc31782144691e3732ba9f2c61f6226c5a63b4 perly.y
 * 5132b115dedc64fcaea289ebf11528abd6f23d9b88e5247a236e1116603edcdb regen_perly.pl
 * ex: set ro: */
