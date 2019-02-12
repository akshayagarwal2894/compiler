/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yaccfile.y" /* yacc.c:339  */

/*
Akshay Agarwal
127203
CSE B Section
To compile first type only 1.make 2.press enter 3./a.out and press enter
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//function declarations

char *newlabel();
char *new_temp();
struct CodeLineEntry *genquad(char *code);
int printCode(FILE *outputFile);

//variables

int currentLine = -1,count_t=1,count_t1=1,one_more_default=0;
char ch[20],label[10],buffer[1001],buffer1[1001],buffer2[1001],buffer3[1000];
extern FILE *yyin;
FILE *output,*ofile;

//structures 

struct CodeLineEntry
{
    char *code;
    int gotoL;
    struct CodeLineEntry *next;
};

struct CodeLineEntry *codeLineHead = NULL, *codeLineTail = NULL;

struct BackpatchList
{
    struct CodeLineEntry *entry;
    struct BackpatchList *next;
};

//Backpatch function declarations

void backpatch(struct BackpatchList* list, int gotoL);
struct BackpatchList* mergelists(struct BackpatchList* a, struct BackpatchList* b);
struct BackpatchList* addToList(struct BackpatchList* list, struct CodeLineEntry* entry);
struct BackpatchList *temp;


#line 117 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 51 "yaccfile.y" /* yacc.c:355  */


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


#line 277 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 292 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   437

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    53,     2,     2,
      59,    60,    51,    49,     2,    50,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    58,
      47,    42,    48,     2,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    43,    44,    45,
      46,    55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   116,   116,   126,   132,   141,   150,   156,   167,   172,
     176,   180,   184,   190,   198,   206,   217,   234,   252,   262,
     268,   268,   281,   288,   293,   299,   305,   311,   311,   319,
     319,   338,   343,   350,   357,   364,   371,   378,   386,   394,
     402,   410,   418,   426,   435,   442,   449,   456,   463,   469,
     474,   481,   487,   493,   499,   505,   511,   514,   518,   522,
     526,   530,   534,   540,   552,   564,   573,   582,   591,   600,
     614,   618,   626
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "INT", "BOOLEAN", "UINT", "or",
  "and", "NOTOP", "Bor", "Band", "Bnot", "Bexor", "NUM", "LEOP", "GEOP",
  "EQT", "NOT_EQT", "true_op", "false_op", "ELSE", "IDEN", "IF", "THEN",
  "WHILE", "DO", "FOR", "DOOP", "SWITCH", "CASE", "BREAK", "DEFAULT",
  "INC_OP", "DEC_OP", "PINC_OP", "PDEC_OP", "ADDOP", "SUBOP", "MULTOP",
  "DIVOP", "EXIT", "'='", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'@'", "UMINUS", "'{'", "'}'",
  "';'", "'('", "')'", "':'", "$accept", "program", "block", "stmts",
  "decl", "decls", "type", "value", "stmt", "$@1", "case", "BR", "cases",
  "$@2", "$@3", "expr", "arith_expr", "assign_expr", "reloperators",
  "logical_exp", "M", "N", "N1", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    61,   297,   298,   299,   300,    60,    62,    43,
      45,    42,    47,    37,    64,   301,   123,   125,    59,    40,
      41,    58
};
# endif

#define YYPACT_NINF -96

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-96)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,   303,    33,   117,   -96,    44,   -37,   -96,   -96,   -18,
     -17,   117,   117,   117,   -96,   117,   -96,   -96,   -96,   260,
      -5,   -96,   -96,     3,   117,   117,   117,   117,   117,   247,
       2,   303,   205,   117,   -96,   -96,     3,   120,   172,   117,
     117,   117,   -96,   -96,   117,   117,   117,   117,   117,   117,
     -96,   -96,   359,   359,   359,   359,   359,   247,   -96,   -96,
     247,   350,    -2,   247,    29,   359,     7,   200,   -96,   -96,
     -96,    15,   -96,    35,   -96,   -96,   383,   138,   251,    43,
      43,     1,     1,     1,     1,   -96,   147,     0,   -96,   -96,
     -96,   -96,   -96,   -96,   117,   -96,   -96,   -96,    10,    16,
     -96,   -96,   -96,    27,   321,   -96,   359,   247,   247,   303,
     -96,   247,   247,    18,   117,    20,   -96,    77,   -96,    70,
     303,    13,    22,    19,   359,   -96,   -96,   -96,   -96,    40,
     -96,   -96,   -96,    42,    19,   303,   -96,   205,    86,    48,
     -96,   -96,   -96,   -96,    54,   321,    41,   321,    72,   -96,
      72,    46,   -96,   303,   -96,   -96,   -96,   -96
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    49,    50,     0,    70,    70,     0,
       0,     0,     0,     0,     9,     0,     2,     4,    22,     0,
       0,     1,    50,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,    39,     6,     0,     0,
       0,     0,    46,    47,     0,     0,     0,     0,     0,     0,
      31,    32,    52,    53,    54,    55,    51,     0,    67,    68,
       0,     0,     0,     0,     0,    56,     0,     0,    10,    11,
      12,     0,     8,     0,    70,    48,    43,    41,    42,    33,
      34,    35,    36,    37,    38,    65,     0,     0,    59,    60,
      61,    62,    58,    57,     0,    70,    70,    70,     0,     0,
      70,    20,     3,    14,     6,    66,    69,     0,     0,     0,
      70,     0,     0,     0,     0,     0,     5,    64,    63,    15,
       0,     0,     0,    24,    13,     7,    71,    70,    17,     0,
      70,    27,    29,     0,    24,     0,    19,     0,     0,     0,
      21,    23,    16,    72,     0,     6,     0,     6,    26,    70,
      26,     0,    30,     0,    28,    25,    72,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -96,   -96,   -30,   -95,   -96,   -96,   -96,   -96,   -33,   -96,
     -16,   -34,   -96,   -96,   -96,   -96,    -1,   -29,   -96,   -44,
      -8,   -96,   -39
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    16,    71,    72,    37,    73,   115,    17,   113,
     133,   152,   134,   138,   139,    18,    19,    20,    94,    62,
      30,   127,   146
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,    64,    23,    66,    74,    95,    96,    95,    96,   116,
      34,    35,    36,    85,    38,     1,    87,    95,    96,    98,
      95,    96,    29,    52,    53,    54,    55,    56,    61,    95,
      96,    65,    67,    21,    42,    43,    42,    43,    76,    77,
      78,    32,    33,    79,    80,    81,    82,    83,    84,   131,
     148,   132,   150,    51,    99,    49,    61,   103,    97,    86,
     105,    63,    61,   117,   118,   100,   104,   121,   122,   114,
     110,    74,   102,   129,   123,   111,    42,    43,   125,   119,
     130,    24,    25,    26,    27,    96,    28,   107,   108,   109,
     128,   126,   112,   106,    46,    47,    48,    49,   136,   140,
     144,   149,   120,   151,   155,   142,    61,    61,   143,   145,
      61,    61,    74,   124,    74,   147,   154,   157,   141,   135,
       0,     0,   137,   156,    68,    69,    70,     0,     0,     3,
       0,     4,     3,     0,     4,     0,    65,     0,     0,    22,
       0,   153,     5,     6,     0,     7,     8,     9,     0,    10,
      11,    12,     0,    11,    12,     0,     0,    39,    40,     0,
      41,     0,    88,    89,    90,    91,     0,    13,     0,     0,
      13,    42,    43,     0,     0,     0,    15,     0,     0,    15,
      42,    43,    39,    40,     0,    41,     0,    44,    45,    46,
      47,    48,    49,     0,    92,    93,    44,    45,    46,    47,
      48,    49,     0,     0,     0,    42,    43,    75,     0,     0,
      39,    40,     0,    41,     0,     0,     0,     3,     0,     4,
       0,    44,    45,    46,    47,    48,    49,     5,     0,     0,
       0,     0,    75,    42,    43,     0,     0,     0,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      45,    46,    47,    48,    49,    13,    57,     0,     0,     3,
     101,     4,    40,     0,    15,     0,    58,    59,     0,    22,
      39,    40,     0,    41,     0,     0,     0,     0,     0,     0,
      11,    12,     0,     0,    42,    43,     0,     0,     0,     0,
       0,     0,     0,    42,    43,     0,     0,    13,     0,     0,
      44,    45,    46,    47,    48,    49,    60,     0,     0,    44,
      45,    46,    47,    48,    49,     3,     0,     4,    50,     0,
       0,     0,     0,     0,     0,     5,     6,     0,     7,     8,
       9,     0,    10,     3,     0,     4,    11,    12,     0,     0,
       0,     0,     0,     5,     6,     0,     7,     8,     9,     0,
      10,     0,     0,    13,    11,    12,     0,     0,     0,    14,
      39,    40,    15,    41,     0,    88,    89,    90,    91,    39,
      40,    13,    41,     0,     0,     0,     0,     0,     0,     0,
      15,     0,     0,    42,    43,     0,     0,     0,     0,     0,
       0,     0,    42,    43,    40,     0,    41,    92,    93,    44,
      45,    46,    47,    48,    49,     0,     0,     0,    44,    45,
      46,    47,    48,    49,     0,     0,    42,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,    45,    46,    47,    48,    49
};

static const yytype_int16 yycheck[] =
{
       8,    31,     3,    32,    37,     7,     8,     7,     8,   104,
      11,    12,    13,    57,    15,     3,    60,     7,     8,    63,
       7,     8,    59,    24,    25,    26,    27,    28,    29,     7,
       8,    32,    33,     0,    33,    34,    33,    34,    39,    40,
      41,    59,    59,    44,    45,    46,    47,    48,    49,    30,
     145,    32,   147,    58,    25,    54,    57,    22,    60,    60,
      60,    59,    63,   107,   108,    58,    74,   111,   112,    42,
      60,   104,    57,    60,    56,    59,    33,    34,    58,   109,
      58,    37,    38,    39,    40,     8,    42,    95,    96,    97,
     120,    21,   100,    94,    51,    52,    53,    54,    58,    57,
      14,    60,   110,    31,    58,   135,   107,   108,   137,    61,
     111,   112,   145,   114,   147,    61,   150,   156,   134,   127,
      -1,    -1,   130,   153,     4,     5,     6,    -1,    -1,    12,
      -1,    14,    12,    -1,    14,    -1,   137,    -1,    -1,    22,
      -1,   149,    22,    23,    -1,    25,    26,    27,    -1,    29,
      33,    34,    -1,    33,    34,    -1,    -1,    10,    11,    -1,
      13,    -1,    15,    16,    17,    18,    -1,    50,    -1,    -1,
      50,    33,    34,    -1,    -1,    -1,    59,    -1,    -1,    59,
      33,    34,    10,    11,    -1,    13,    -1,    49,    50,    51,
      52,    53,    54,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    33,    34,    60,    -1,    -1,
      10,    11,    -1,    13,    -1,    -1,    -1,    12,    -1,    14,
      -1,    49,    50,    51,    52,    53,    54,    22,    -1,    -1,
      -1,    -1,    60,    33,    34,    -1,    -1,    -1,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    50,     9,    -1,    -1,    12,
      60,    14,    11,    -1,    59,    -1,    19,    20,    -1,    22,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    -1,    50,    -1,    -1,
      49,    50,    51,    52,    53,    54,    59,    -1,    -1,    49,
      50,    51,    52,    53,    54,    12,    -1,    14,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    -1,    25,    26,
      27,    -1,    29,    12,    -1,    14,    33,    34,    -1,    -1,
      -1,    -1,    -1,    22,    23,    -1,    25,    26,    27,    -1,
      29,    -1,    -1,    50,    33,    34,    -1,    -1,    -1,    56,
      10,    11,    59,    13,    -1,    15,    16,    17,    18,    10,
      11,    50,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    11,    -1,    13,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    63,    12,    14,    22,    23,    25,    26,    27,
      29,    33,    34,    50,    56,    59,    64,    70,    77,    78,
      79,     0,    22,    78,    37,    38,    39,    40,    42,    59,
      82,    82,    59,    59,    78,    78,    78,    67,    78,    10,
      11,    13,    33,    34,    49,    50,    51,    52,    53,    54,
      58,    58,    78,    78,    78,    78,    78,     9,    19,    20,
      59,    78,    81,    59,    64,    78,    79,    78,     4,     5,
       6,    65,    66,    68,    70,    60,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    81,    78,    81,    15,    16,
      17,    18,    47,    48,    80,     7,     8,    60,    81,    25,
      58,    60,    57,    22,    82,    60,    78,    82,    82,    82,
      60,    59,    82,    71,    42,    69,    65,    81,    81,    64,
      82,    81,    81,    56,    78,    58,    21,    83,    64,    60,
      58,    30,    32,    72,    74,    82,    58,    82,    75,    76,
      57,    72,    64,    79,    14,    61,    84,    61,    65,    60,
      65,    31,    73,    82,    73,    58,    64,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    66,    67,    67,
      68,    68,    68,    69,    69,    70,    70,    70,    70,    70,
      71,    70,    70,    72,    72,    73,    73,    75,    74,    76,
      74,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    80,    80,    80,
      80,    80,    80,    81,    81,    81,    81,    81,    81,    81,
      82,    83,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     1,     3,     0,     4,     2,     0,
       1,     1,     1,     2,     0,     6,     9,     7,    14,     8,
       0,     8,     1,     2,     0,     2,     0,     0,     6,     0,
       5,     2,     2,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     3,     3,     2,     2,     2,     2,     3,     1,
       1,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     2,     3,     1,     1,     3,
       0,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 117 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.S.code),(yyvsp[0].S.code));
		fprintf(output,"%s\n",(yyval.S.code));
		printf("%s \n %s \n  %s\n","Please look for output the files :","backcode.txt --with backpatching  ","and output.txt --without backpatching(in terms of B.true and B.false)");
		return 0;
	}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 127 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.S.code),(yyvsp[-1].S.code));
		strcpy((yyval.S.next),(yyvsp[-1].S.next));
	}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 133 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyvsp[0].S.next),newlabel());
		strcpy((yyval.S.next),(yyvsp[0].S.next));
		strcpy((yyval.S.code),strcat((yyvsp[0].S.code),(yyvsp[0].S.next)));
	}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 142 "yaccfile.y" /* yacc.c:1646  */
    {
		backpatch((yyvsp[-2].S.nextlist),(yyvsp[-1].M.instr));
		(yyval.S.nextlist)=(yyvsp[0].S.nextlist);
		strcpy((yyvsp[0].S.next),newlabel());
		strcpy((yyval.S.code),strcat((yyval.S.code),strcat((yyvsp[0].S.code),(yyvsp[0].S.next))));
		strcpy((yyval.S.next),(yyvsp[0].S.next));
	}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 150 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.S.code),"");
	}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 157 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.srec.name),(yyvsp[-2].srec.name));
		strcpy((yyval.srec.type),(yyvsp[-3].srec.type));
		strcat(strcat((yyval.srec.type),"   "),(yyval.srec.name));
		if(strlen((yyvsp[-1].E.place))!=0){sprintf(buffer,"%s %s","=",(yyvsp[-1].E.place));strcat((yyval.srec.type),buffer);}
		genquad((yyval.srec.type));
	}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 168 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.srec.name),(yyvsp[0].srec.name));
		strcpy((yyval.srec.type),(yyvsp[0].srec.type));
	}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 177 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.srec.type),(yyvsp[0].srec.type));
	}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 181 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.srec.type),(yyvsp[0].srec.type));
	}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 185 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.srec.type),(yyvsp[0].srec.type));
	}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 191 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),new_temp());
		sprintf(buffer,"%s %s %s\n",(yyval.E.place),"=",(yyvsp[0].E.place));
		strcpy((yyval.E.code),strcat((yyvsp[0].E.code),buffer));
		genquad(buffer);
	}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 198 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),"");
		strcpy((yyval.srec.type),"");
	}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 207 "yaccfile.y" /* yacc.c:1646  */
    {
		backpatch((yyvsp[-3].B.truelist),(yyvsp[-1].M.instr));
		(yyval.S.nextlist)=mergelists((yyvsp[-3].B.falselist),(yyvsp[0].S.nextlist));
		strcpy((yyvsp[-3].B.true),newlabel());
		strcpy((yyvsp[-3].B.false),newlabel());
		strcpy((yyval.S.next),"B.false :\n");
		strcpy((yyval.S.code),strcat(strcat((yyvsp[-3].B.code),"B.true : \n"),(yyvsp[0].S.code)));
		strcat((yyval.S.code),"B.false : \n");
	}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 218 "yaccfile.y" /* yacc.c:1646  */
    {
		backpatch((yyvsp[-6].B.truelist),(yyvsp[-4].M.instr));
		backpatch((yyvsp[-6].B.falselist),(yyvsp[-1].M.instr));
		temp=mergelists((yyvsp[-3].S.nextlist),(yyvsp[-2].N.nextlist));
		(yyval.S.nextlist)=mergelists(temp,(yyvsp[0].S.nextlist));
		strcpy((yyvsp[-6].B.true),newlabel());
		strcpy((yyvsp[-6].B.false),newlabel());
		strcpy((yyval.S.next),(yyvsp[0].S.next));
		strcpy((yyvsp[-3].S.next),(yyvsp[0].S.next));
		bzero(buffer1,1000);
		sprintf(buffer1,"%s %s\n","goto",(yyval.S.next));
		bzero(buffer,1000);
		sprintf(buffer,"%s %s %s %s %s %s\n",(yyvsp[-6].B.code),"B.true : \n",(yyvsp[-3].S.code),buffer1,"B.false : \n",(yyvsp[0].S.code));
		strcpy((yyval.S.code),buffer);
	}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 235 "yaccfile.y" /* yacc.c:1646  */
    {
		backpatch((yyvsp[0].S.nextlist),(yyvsp[-5].M.instr));
		backpatch((yyvsp[-3].B.truelist),(yyvsp[-1].M.instr));
		(yyval.S.nextlist)=(yyvsp[-3].B.falselist);
		sprintf(buffer1,"%s %d","goto",(yyvsp[-5].M.instr));
		genquad(buffer1);
		char begin[10];
		strcpy(begin,newlabel());
		strcpy((yyvsp[-3].B.true),newlabel());
		strcpy((yyvsp[-3].B.false),(yyval.S.next));
		strcpy((yyvsp[0].S.next),begin);
		sprintf(buffer1,"%s %s\n","goto",begin);
		sprintf(buffer,"%s %s %s %s %s",begin,(yyvsp[-3].B.code),"B.true :\n",(yyvsp[0].S.code),buffer1);
		strcpy((yyval.S.code),buffer);
		strcat((yyval.S.code),"B.false :\n");
	}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 253 "yaccfile.y" /* yacc.c:1646  */
    {
            backpatch((yyvsp[-11].B.truelist), (yyvsp[-9].M.instr));
           // backpatch($<S.nextlist>13, $<M.instr>8);
	    backpatch((yyvsp[0].N.nextlist),(yyvsp[-6].M.instr));
            backpatch((yyvsp[-8].B.truelist), (yyvsp[-2].M.instr));
            (yyval.S.nextlist) = (yyvsp[-8].B.falselist);
        //    backpatch($<B.truelist>9, $<M.instr>5);
            backpatch((yyvsp[-4].N.nextlist), (yyvsp[-9].M.instr));
        }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 263 "yaccfile.y" /* yacc.c:1646  */
    {
		backpatch((yyvsp[-2].B.truelist),(yyvsp[-6].M.instr));
		(yyval.S.nextlist)=(yyvsp[-2].B.falselist);		
		//backpatch($<N.nextlist>8,$<M.instr>2);
	}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 268 "yaccfile.y" /* yacc.c:1646  */
    {sprintf(buffer,"%s %s %s","t","=",(yyvsp[-1].E.place));genquad(buffer);genquad("goto test :");}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 269 "yaccfile.y" /* yacc.c:1646  */
    {
		sprintf(buffer,"%s %s %s\n",(yyvsp[-5].S.code),"goto test\n",(yyvsp[-1].S.code));
		strcpy((yyval.S.code),buffer);
		sprintf(buffer1,"%s","test :\n");
		genquad("test :\n");
		strcat((yyval.S.code),buffer1);
		strcat((yyval.S.code),buffer3);
		genquad(buffer3);
		strcat((yyval.S.code),"\nnext  :\n");
		genquad("\nnext :\n");
	}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 282 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.S.code),(yyvsp[0].S.code));
	}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 289 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.S.code),strcat((yyval.S.code),(yyvsp[0].S.code)));
	}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 293 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.S.code),"");
	}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 300 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.S.code),"goto next\n");
		genquad((yyval.S.code));
	}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 305 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.S.code),"");
	}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 311 "yaccfile.y" /* yacc.c:1646  */
    {strcpy(label,newlabel());genquad(label);}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 312 "yaccfile.y" /* yacc.c:1646  */
    {
		sprintf(buffer,"%s %s %s\n",label,(yyvsp[-1].S.code),(yyvsp[0].S.code));
		strcpy((yyval.S.code),buffer);
		sprintf(buffer1,"%s %d %s %s","if t = " , (yyvsp[-3].id.a) , "goto" , label);
		strcat(buffer3,buffer1);
	}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 319 "yaccfile.y" /* yacc.c:1646  */
    {strcpy(label,newlabel());genquad(label);}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 320 "yaccfile.y" /* yacc.c:1646  */
    {
		if(!one_more_default)
		{
			one_more_default=1;
		}
		else
		{
			printf(" syntax error:more than one default encountered\n");
			exit(0);
		}
		sprintf(buffer,"%s %s %s\n",label,(yyvsp[-1].S.code),(yyvsp[0].S.code));
		strcpy((yyval.S.code),buffer);
		sprintf(buffer1,"%s %s","goto" , label);
		strcat(buffer3,buffer1);
	}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 339 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.S.code),(yyvsp[-1].S.code));
	}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 344 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.S.code),(yyvsp[-1].S.code));
	}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 351 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),new_temp());
		sprintf(buffer," %s %s %s %s %s\n",(yyval.E.place),"=",(yyvsp[-2].E.place),"+",(yyvsp[0].E.place));
		strcpy((yyval.E.code),strcat(strcat((yyvsp[-2].E.code),(yyvsp[0].E.code)),buffer));
		genquad(buffer);
	}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 358 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",(yyval.E.place),"=",(yyvsp[-2].E.place),"-",(yyvsp[0].E.place));
		strcpy((yyval.E.code),strcat(strcat((yyvsp[-2].E.code),(yyvsp[0].E.code)),buffer));
		genquad(buffer);
	}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 365 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",(yyval.E.place),"=",(yyvsp[-2].E.place),"*",(yyvsp[0].E.place));
		strcpy((yyval.E.code),strcat(strcat((yyvsp[-2].E.code),(yyvsp[0].E.code)),buffer));
		genquad(buffer);
	}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 372 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",(yyval.E.place),"=",(yyvsp[-2].E.place),"/",(yyvsp[0].E.place));
		strcpy((yyval.E.code),strcat(strcat((yyvsp[-2].E.code),(yyvsp[0].E.code)),buffer));
		genquad(buffer);
	}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 379 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",(yyval.E.place),"=",(yyvsp[-2].E.place),"%",(yyvsp[0].E.place));
		strcpy((yyval.E.code),strcat(strcat((yyvsp[-2].E.code),(yyvsp[0].E.code)),buffer));
		genquad(buffer);
	}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 387 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",(yyval.E.place),"=",(yyvsp[-2].E.place),"@",(yyvsp[0].E.place));
		strcpy((yyval.E.code),strcat(strcat((yyvsp[-2].E.code),(yyvsp[0].E.code)),buffer));
		genquad(buffer);
	  }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 395 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),new_temp());
		sprintf(buffer,"%s %s %s %s\n",(yyval.E.place),"=","-",(yyvsp[0].E.place));
		strcpy((yyval.E.code),strcat((yyvsp[0].E.code),buffer));
		genquad(buffer);
	}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 403 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),new_temp());
		sprintf(buffer,"%s %s %s %s\n",(yyval.E.place),"=","~",(yyvsp[-1].E.place));
		strcpy((yyval.E.code),strcat((yyvsp[-1].E.code),buffer));
		genquad(buffer);
	}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 411 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",(yyval.E.place),"=",(yyvsp[-2].E.place),"&",(yyvsp[0].E.place));
		strcpy((yyval.E.code),strcat(strcat((yyvsp[-2].E.code),(yyvsp[0].E.code)),buffer));
		genquad(buffer);
	}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 419 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",(yyval.E.place),"=",(yyvsp[-2].E.place),"^",(yyvsp[0].E.place));
		strcpy((yyval.E.code),strcat(strcat((yyvsp[-2].E.code),(yyvsp[0].E.code)),buffer));
		genquad(buffer);
	}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 427 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",(yyval.E.place),"=",(yyvsp[-2].E.place),"|",(yyvsp[0].E.place));
		strcpy((yyval.E.code),strcat(strcat((yyvsp[-2].E.code),(yyvsp[0].E.code)),buffer));
		genquad(buffer);
	}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 436 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),(yyvsp[0].E.place));
		sprintf(buffer,"%s %s %s %s\n",(yyvsp[0].E.place),"=",(yyvsp[0].E.place),"+ 1");
		strcpy((yyval.E.code),strcat((yyvsp[0].E.code),buffer));
		genquad(buffer);
	}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 443 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),(yyvsp[0].E.place));
		sprintf(buffer,"%s %s %s %s\n",(yyvsp[0].E.place),"=",(yyvsp[0].E.place),"- 1");
		strcpy((yyval.E.code),strcat((yyvsp[0].E.code),buffer));
		genquad(buffer);
	}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 450 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),(yyvsp[-1].E.place));
		sprintf(buffer,"%s %s %s %s\n",(yyvsp[-1].E.place),"=",(yyvsp[-1].E.place),"+ 1");
		strcpy((yyval.E.code),strcat((yyvsp[-1].E.code),buffer));
		genquad(buffer);
	}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 457 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),(yyvsp[-1].E.place));
		sprintf(buffer,"%s %s %s %s\n",(yyvsp[-1].E.place),"=",(yyvsp[-1].E.place),"- 1");
		strcpy((yyval.E.code),strcat((yyvsp[-1].E.code),buffer));
		genquad(buffer);
	}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 464 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),(yyvsp[-1].E.place));
		strcpy((yyval.E.code),(yyvsp[-1].E.code));
		sprintf(buffer,"%s %s %s\n",(yyval.E.place),"=",(yyvsp[-1].E.place));
	}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 470 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),(yyvsp[0].id.place));
		strcpy((yyval.E.code),"");
	}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 475 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.E.place),(yyvsp[0].id.place));
		strcpy((yyval.E.code),"");
	}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 482 "yaccfile.y" /* yacc.c:1646  */
    {
		sprintf(buffer,"%s %s %s\n",(yyvsp[-2].id.place),"=",(yyvsp[0].E.place));
		strcpy((yyval.S.code),strcat((yyvsp[0].E.code),buffer));
		genquad(buffer);
	}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 488 "yaccfile.y" /* yacc.c:1646  */
    {
		sprintf(buffer,"%s %s %s\n",(yyvsp[-2].id.place),"+=",(yyvsp[0].E.place));
		strcpy((yyval.S.code),strcat((yyvsp[0].E.code),buffer));
		genquad(buffer);
	}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 494 "yaccfile.y" /* yacc.c:1646  */
    {
		sprintf(buffer,"%s %s %s\n",(yyvsp[-2].id.place),"-=",(yyvsp[0].E.place));
		strcpy((yyval.S.code),strcat((yyvsp[0].E.code),buffer));
		genquad(buffer);
	}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 500 "yaccfile.y" /* yacc.c:1646  */
    {
		sprintf(buffer,"%s %s %s\n",(yyvsp[-2].id.place),"*=",(yyvsp[0].E.place));
		strcpy((yyval.S.code),strcat((yyvsp[0].E.code),buffer));
		genquad(buffer);
	}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 506 "yaccfile.y" /* yacc.c:1646  */
    {
		sprintf(buffer,"%s %s %s\n",(yyvsp[-2].id.place),"/=",(yyvsp[0].E.place));
		strcpy((yyval.S.code),strcat((yyvsp[0].E.code),buffer));
		genquad(buffer);
	}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 515 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.rel.op),">");
	}
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 519 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.rel.op),"<");
	}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 523 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.rel.op),"<=");
	}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 527 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.rel.op),">=");
	}
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 531 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.rel.op),"==");
	}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 535 "yaccfile.y" /* yacc.c:1646  */
    {
		strcpy((yyval.rel.op),"!=");
	}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 541 "yaccfile.y" /* yacc.c:1646  */
    {
		backpatch((yyvsp[-3].B.truelist),(yyvsp[-1].M.instr));
		(yyval.B.truelist)=(yyvsp[0].B.truelist);
		(yyval.B.falselist)=mergelists((yyvsp[-3].B.falselist),(yyvsp[0].B.falselist));
		strcpy((yyvsp[-3].B.true),newlabel());
		strcpy((yyvsp[-3].B.false),"B.false");
		strcpy((yyvsp[0].B.true),"B.true");
		strcpy((yyvsp[0].B.false),"B.false");
		strcpy((yyval.B.code),strcat(strcat((yyvsp[-3].B.code),"B.true :\n"),(yyvsp[0].B.code)));
	}
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 553 "yaccfile.y" /* yacc.c:1646  */
    {
		backpatch((yyvsp[-3].B.falselist),(yyvsp[-1].M.instr));
		(yyval.B.truelist)=mergelists((yyvsp[-3].B.truelist),(yyvsp[0].B.truelist));
		(yyval.B.falselist)=(yyvsp[0].B.falselist);
		strcpy((yyvsp[-3].B.true),"B.true");
		strcpy((yyvsp[-3].B.false),newlabel());
		strcpy((yyvsp[0].B.true),"B.true");
		strcpy((yyvsp[0].B.false),"B.false");
		strcpy((yyval.B.code),strcat(strcat((yyvsp[-3].B.code),"B.false :\n"),(yyvsp[0].B.code)));
	}
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 565 "yaccfile.y" /* yacc.c:1646  */
    {
		(yyval.B.truelist)=(yyvsp[0].B.falselist);
		(yyval.B.falselist)=(yyvsp[0].B.truelist);
		strcpy(buffer1,"not");
		strcat(buffer1,(yyvsp[0].B.code));
		strcpy((yyval.B.code),buffer1);
	}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 574 "yaccfile.y" /* yacc.c:1646  */
    {
		(yyval.B.truelist)=(yyvsp[-1].B.truelist);
		(yyval.B.falselist)=(yyvsp[-1].B.falselist);
		strcpy((yyvsp[-1].B.true),"B.true");
		strcpy((yyvsp[-1].B.false),"B.false");
		strcpy((yyval.B.code),(yyvsp[-1].B.code));
	}
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 583 "yaccfile.y" /* yacc.c:1646  */
    {
		sprintf(buffer,"%s %s\n","goto","B.true");
		(yyval.B.truelist)=addToList(NULL,genquad(buffer));
		sprintf(buffer,"%s %d","goto",0);
		genquad(buffer);
		strcpy((yyval.B.code),buffer);
	}
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 592 "yaccfile.y" /* yacc.c:1646  */
    {
		sprintf(buffer,"%s %s\n","goto","B.false");
		(yyval.B.falselist)=addToList(NULL,genquad(buffer));
		sprintf(buffer,"%s %d","goto",0);
		genquad(buffer);
		strcpy((yyval.B.code),buffer);
	}
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 601 "yaccfile.y" /* yacc.c:1646  */
    {
		sprintf(buffer1,"%s %s %s %s %s %s","if",(yyvsp[-2].E.place),(yyvsp[-1].rel.op),(yyvsp[0].E.place),"goto","");
		(yyval.B.truelist)=addToList(NULL,genquad(buffer1));
		sprintf(buffer2,"%s %s","goto","");
		(yyval.B.falselist)=addToList(NULL,genquad(buffer2));
		sprintf(buffer1,"%s %s %s %s %s %s\n","if",(yyvsp[-2].E.place),(yyvsp[-1].rel.op),(yyvsp[0].E.place),"goto","B.true");
		sprintf(buffer2,"%s %s","goto","B.false");
		sprintf(buffer,"%s %s %s %s\n",(yyvsp[-2].E.code),(yyvsp[0].E.code),buffer1,buffer2);
		strcpy((yyval.B.code),buffer);
	}
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 614 "yaccfile.y" /* yacc.c:1646  */
    {
		(yyval.M.instr)=currentLine+1;
	}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 619 "yaccfile.y" /* yacc.c:1646  */
    {
		sprintf(buffer1,"%s %s","goto","");
		(yyval.N.nextlist)=addToList(NULL,genquad(buffer1));
	}
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 626 "yaccfile.y" /* yacc.c:1646  */
    {
		sprintf(buffer1,"%s %s","goto","");
		(yyval.N.nextlist)=addToList(NULL,genquad(buffer1));
	}
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2257 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 632 "yaccfile.y" /* yacc.c:1906  */

int main()
{
	yyin=fopen("code.txt","r+"); 
	output=fopen("output.txt","w");
	ofile = fopen("backcode.txt", "w");
    		
	yyparse();
	printCode(ofile);
	fclose(output);
    	return 0;
}
char *new_temp()
{
	char buf[3],buff[10];
	strcpy(buff,"t");
	sprintf(buf,"%d",count_t);
	strcpy(ch,strcat(buff,buf));
	count_t++;
	return ch;
}
char *newlabel()
{
	char buf[3],buff[10];
	strcpy(buff,"l");
	sprintf(buf,"%d\n",count_t1);
	strcpy(ch,strcat(buff,buf));
	count_t1++;
	return ch;
}
void backpatch(struct BackpatchList* list, int gotoL){
	fflush(stdout);
	if(list == NULL){
		return;
	} else{
		struct BackpatchList* temp;
		while(list){
			if(list->entry != NULL){
				list->entry->gotoL = gotoL;
			}
			
			temp = list;
			list = list->next;
			free(temp);
		}
	}
}

struct BackpatchList* mergelists(struct BackpatchList* a, struct BackpatchList* b){
	//printf("In mergelists\n");
	fflush(stdout);
	if(a != NULL && b == NULL){
		return a;
	}
	else if(a == NULL && b != NULL){
		return b;
	}
	else if(a == NULL && b == NULL){
		return NULL;
	}
	else{
		struct BackpatchList* temp = a;
		while(a->next){
			a = a->next;
		}
		a->next = b;
		return temp;
	}
}

struct BackpatchList* addToList(struct BackpatchList* list, struct CodeLineEntry* entry){
	//printf("In addToList\n");
	fflush(stdout);
	if(entry == NULL){
		return list;
	}
	else if(list == NULL){
		struct BackpatchList* newEntry = malloc(sizeof(struct BackpatchList));
		newEntry->entry = entry;
		newEntry->next = NULL;
		return newEntry;
	}
	else{
		struct BackpatchList* newEntry = malloc(sizeof(struct BackpatchList)), *temp = list;
		newEntry->entry = entry;
		newEntry->next=NULL;
		while(list->next){
			list = list->next;
		}
		list->next = newEntry;
		return temp;
	}
}

struct CodeLineEntry *genquad(char *code){
	//printf("In genquad\n");
	fflush(stdout);
	struct CodeLineEntry* newCodeLine = malloc(sizeof(struct CodeLineEntry));
		
	//printf("%s\n",code);
	//Create the element
	newCodeLine->code = strdup(code);
	newCodeLine->next = NULL;
	newCodeLine->gotoL = -1;
	//refresh the header/tail
	if(codeLineHead == NULL){
		codeLineHead = newCodeLine;
		codeLineTail = newCodeLine;
	}
	else{
		codeLineTail->next = newCodeLine;
		codeLineTail = newCodeLine;
	}
	currentLine++;
	//return a pointer to the new element
	return newCodeLine;
	
}
int printCode(FILE *outputFile)
{
 
    struct    CodeLineEntry *codeLine = codeLineHead;

    if(codeLine == NULL)
    {

        return 0;
    }

    unsigned long lineNumber = 0;

    if(fprintf(outputFile, "\n\nCODE\n----\n\n") <= 0)
    {

        return 0;
    }

    while(codeLine)
    {
    	int ret;
    	//No goto
    	if(codeLine->gotoL == -1){
    		ret = fprintf(outputFile, "%-4lu %s\n", lineNumber, codeLine->code);
    	}
    	//goto
    	else{
    		ret = fprintf(outputFile, "%-4lu %s %d\n\n", lineNumber, codeLine->code, codeLine->gotoL);
    	}
        if(ret <= 0)
        {

            return 0;
        }

        codeLine = codeLine->next;
        ++lineNumber;
    }

    return 1;
}


