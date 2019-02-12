/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    MAIN = 258,
    INT = 259,
    BOOLEAN = 260,
    UINT = 261,
    or = 262,
    and = 263,
    NOTOP = 264,
    Bor = 265,
    Band = 266,
    Bnot = 267,
    Bexor = 268,
    NUM = 269,
    LEOP = 270,
    GEOP = 271,
    EQT = 272,
    NOT_EQT = 273,
    true_op = 274,
    false_op = 275,
    ELSE = 276,
    IDEN = 277,
    IF = 278,
    THEN = 279,
    WHILE = 280,
    DO = 281,
    FOR = 282,
    DOOP = 283,
    SWITCH = 284,
    CASE = 285,
    BREAK = 286,
    DEFAULT = 287,
    INC_OP = 288,
    DEC_OP = 289,
    PINC_OP = 290,
    PDEC_OP = 291,
    ADDOP = 292,
    SUBOP = 293,
    MULTOP = 294,
    DIVOP = 295,
    EXIT = 296,
    UMINUS = 301
  };
#endif
/* Tokens.  */
#define MAIN 258
#define INT 259
#define BOOLEAN 260
#define UINT 261
#define or 262
#define and 263
#define NOTOP 264
#define Bor 265
#define Band 266
#define Bnot 267
#define Bexor 268
#define NUM 269
#define LEOP 270
#define GEOP 271
#define EQT 272
#define NOT_EQT 273
#define true_op 274
#define false_op 275
#define ELSE 276
#define IDEN 277
#define IF 278
#define THEN 279
#define WHILE 280
#define DO 281
#define FOR 282
#define DOOP 283
#define SWITCH 284
#define CASE 285
#define BREAK 286
#define DEFAULT 287
#define INC_OP 288
#define DEC_OP 289
#define PINC_OP 290
#define PDEC_OP 291
#define ADDOP 292
#define SUBOP 293
#define MULTOP 294
#define DIVOP 295
#define EXIT 296
#define UMINUS 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 51 "yaccfile.y" /* yacc.c:1909  */


struct symrec
{
 char name[100];
 char type[100];
 int deval;
}srec;

struct info{
	char place[1000];
	char code[5000];
	char next[100];
	struct BackpatchList *nextlist;
	int a;
}info,E,id,S,N,L;

struct info1{
char true[100];
char false[100];
char code[1000];
struct BackpatchList *truelist;
struct BackpatchList *falselist;
}B;

struct relop
{
   char op[5];
}rel;

struct backpro{
int instr;
}M;


#line 174 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
