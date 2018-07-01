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

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
    #include "structures.h"
   // #include "eval.h"

	// extern "C" int yylex();
	// extern "C" int yyparse();
	// extern "C" void yyerror(char *s);

	char filenumber = '0';
	int firstfile_flag = 1;

	struct listAttr *newattrs;
    nodeType statement_type;
	int d_attr;
	int d_func;
	char *new_table;
	char *new_file;
	char *old_table;
    struct f_opr *finalFunction;
	struct tbl_list *tables;
    struct Gtable *head = NULL;
	struct node *boolean;
	struct n_list *groupingAtts;
	struct n_list *attsToSelect;

    struct node* makeboolcomp(int code);
    struct node* makeliteral(int code, char* value);
    struct node* make_or(struct node *l, struct node *r);
    struct node* make_and(struct node *l, struct node *r);
    void addtables(char *name, struct listAttr *list);
    void eval();
    void merge(char *file1, char *file2);
    FILE* merge_removedup(FILE* fp1, FILE* fp2);
	FILE* rec_eval(struct node *p, FILE *fp);
	FILE* eval_condition(int code, struct node* p, FILE *fp);
	void finalprint_select();



#line 109 "y.tab.c" /* yacc.c:339  */

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
    Name = 258,
    Float = 259,
    Int = 260,
    String = 261,
    SELECT = 262,
    GROUP = 263,
    DISTINCT = 264,
    BY = 265,
    FROM = 266,
    WHERE = 267,
    SUM = 268,
    AS = 269,
    AND = 270,
    OR = 271,
    CREATE = 272,
    TABLE = 273,
    HEAP = 274,
    INSERT = 275,
    INTO = 276,
    SET = 277,
    OUTPUT = 278,
    DROP = 279,
    SORTED = 280,
    ON = 281,
    LE = 282,
    NE = 283,
    GE = 284,
    EXIT = 285
  };
#endif
/* Tokens.  */
#define Name 258
#define Float 259
#define Int 260
#define String 261
#define SELECT 262
#define GROUP 263
#define DISTINCT 264
#define BY 265
#define FROM 266
#define WHERE 267
#define SUM 268
#define AS 269
#define AND 270
#define OR 271
#define CREATE 272
#define TABLE 273
#define HEAP 274
#define INSERT 275
#define INTO 276
#define SET 277
#define OUTPUT 278
#define DROP 279
#define SORTED 280
#define ON 281
#define LE 282
#define NE 283
#define GE 284
#define EXIT 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 44 "yaccfile.y" /* yacc.c:355  */

    struct or_list *myor_list;
	struct and_list *myand_list;
	struct n_list *myNames;
	struct listAttr *myAttrList;
	struct n_list *mysortattrs;
	char *actualChars;
	char whichOne;	
    struct f_oper *myOperand;
    struct f_opr *myOperator;
	struct tbl_list *myTables;
	struct cmp_opr *myComparison;
	struct Operand *myBoolOperand;
    struct node *nodeptr;

#line 225 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 240 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   97

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    37,    36,    34,    35,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      39,    41,    40,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    81,    81,    82,    85,    87,    89,    91,    93,    95,
      98,   105,   113,   115,   117,   119,   122,   124,   127,   131,
     136,   141,   147,   156,   162,   164,   169,   176,   177,   178,
     179,   182,   184,   185,   186,   189,   191,   194,   197,   198,
     199,   200,   201,   202,   205,   207,   209,   211,   214,   218,
     222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Name", "Float", "Int", "String",
  "SELECT", "GROUP", "DISTINCT", "BY", "FROM", "WHERE", "SUM", "AS", "AND",
  "OR", "CREATE", "TABLE", "HEAP", "INSERT", "INTO", "SET", "OUTPUT",
  "DROP", "SORTED", "ON", "LE", "NE", "GE", "EXIT", "';'", "'('", "')'",
  "','", "'-'", "'+'", "'*'", "'/'", "'<'", "'>'", "'='", "$accept",
  "SQLQueries", "SQL", "NewAtts", "argsAndFunc", "Function", "Atts",
  "Tables", "CompoundExp", "Op", "booleanConditions", "booleanConditions1",
  "Condition", "BoolComp", "Literal", "SimpleExp", YY_NULLPTR
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
     285,    59,    40,    41,    44,    45,    43,    42,    47,    60,
      62,    61
};
# endif

#define YYPACT_NINF -67

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,    37,    -7,    13,     9,    -8,    26,     5,   -67,    25,
       7,    21,    14,    15,    35,    20,    59,   -67,   -67,   -67,
      15,    31,    -1,    61,    25,    62,    34,    64,    38,    -1,
     -67,   -67,   -67,    -1,    -1,    39,    23,    54,     8,    15,
     -67,    67,    40,   -67,    41,    42,   -67,   -67,   -67,   -67,
     -67,   -67,    -1,    70,     4,    73,    74,    45,   -67,   -67,
      23,   -67,   -67,   -67,   -67,   -67,   -67,    48,     6,    65,
      63,    16,    68,    47,    52,    -1,    53,    75,   -67,     4,
      48,   -67,   -67,   -67,   -67,   -67,   -67,    48,    84,    67,
     -67,   -67,    76,    25,   -67,   -67,   -67,   -67,   -67,     4,
     -13,   -67,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     2,    18,     0,
       0,     0,    13,    14,     0,     0,     0,     9,     1,     3,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,    48,    49,     0,     0,     0,    25,     0,     0,    12,
      19,     0,     0,     8,     0,     0,    26,    16,    27,    28,
      29,    30,     0,     0,     0,     0,     0,     0,     7,    17,
      24,    22,    20,    47,    45,    46,    44,     0,     0,    34,
      36,     0,     0,    10,     0,     0,     0,     0,     4,     0,
       0,    43,    41,    42,    38,    39,    40,     0,     0,     0,
       6,    23,    33,     0,    32,    35,    37,    21,    11,     0,
       0,    31,     5
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,    81,   -67,     0,   -67,   -67,    -9,   -67,   -28,    30,
     -66,   -50,   -67,   -67,    10,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,    57,    11,    12,    13,    38,    35,    52,
      68,    69,    70,    87,    71,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    44,    30,    31,    32,    45,    46,    63,    64,    65,
      66,    14,     1,    94,    77,    39,    21,    76,   102,    15,
      54,    25,     2,    17,    61,     3,    18,    16,     8,     4,
      95,    33,    23,   101,    34,     5,    67,    78,    26,    22,
       8,    27,    55,    81,    82,    83,     9,    91,    24,    25,
      10,    63,    64,    65,    66,    84,    85,    86,    48,    49,
      50,    51,    28,    29,    37,    40,    41,    42,    53,    43,
      56,    58,    47,    62,    59,    60,    72,    73,    74,    80,
      79,    89,    88,    90,   100,    93,    92,    97,    19,    98,
      75,    99,     0,     0,     0,     0,     0,    96
};

static const yytype_int8 yycheck[] =
{
       9,    29,     3,     4,     5,    33,    34,     3,     4,     5,
       6,    18,     7,    79,     8,    24,     9,    67,    31,     6,
      12,    34,    17,    31,    52,    20,     0,    18,     3,    24,
      80,    32,    11,    99,    35,    30,    32,    31,     3,    32,
       3,    21,    34,    27,    28,    29,     9,    75,    34,    34,
      13,     3,     4,     5,     6,    39,    40,    41,    35,    36,
      37,    38,     3,    32,     3,     3,    32,     3,    14,    31,
       3,    31,    33,     3,    33,    33,     3,     3,    33,    16,
      15,    34,    14,    31,    93,    10,    33,     3,     7,    89,
      60,    15,    -1,    -1,    -1,    -1,    -1,    87
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    17,    20,    24,    30,    43,    44,     3,     9,
      13,    46,    47,    48,    18,     6,    18,    31,     0,    43,
      48,     9,    32,    11,    34,    34,     3,    21,     3,    32,
       3,     4,     5,    32,    35,    50,    57,     3,    49,    48,
       3,    32,     3,    31,    50,    50,    50,    33,    35,    36,
      37,    38,    51,    14,    12,    34,     3,    45,    31,    33,
      33,    50,     3,     3,     4,     5,     6,    32,    52,    53,
      54,    56,     3,     3,    33,    51,    53,     8,    31,    15,
      16,    27,    28,    29,    39,    40,    41,    55,    14,    34,
      31,    50,    33,    10,    52,    53,    56,     3,    45,    15,
      48,    52,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    44,    44,    44,    44,
      45,    45,    46,    46,    46,    46,    47,    47,    48,    48,
      49,    49,    50,    50,    50,    50,    50,    51,    51,    51,
      51,    52,    52,    52,    52,    53,    53,    54,    55,    55,
      55,    55,    55,    55,    56,    56,    56,    56,    57,    57,
      57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     7,    10,     7,     5,     4,     2,
       2,     4,     3,     1,     1,     2,     4,     5,     1,     3,
       3,     5,     3,     5,     3,     1,     2,     1,     1,     1,
       1,     5,     3,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
#line 81 "yaccfile.y" /* yacc.c:1646  */
    {}
#line 1383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 82 "yaccfile.y" /* yacc.c:1646  */
    {}
#line 1389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 85 "yaccfile.y" /* yacc.c:1646  */
    { tables = (yyvsp[-3].myTables); boolean = (yyvsp[-1].nodeptr); groupingAtts = NULL; statement_type = selec; eval();}
#line 1395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 87 "yaccfile.y" /* yacc.c:1646  */
    { tables = (yyvsp[-6].myTables); boolean = (yyvsp[-4].nodeptr); groupingAtts = (yyvsp[-1].myNames); statement_type = selec; eval();}
#line 1401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 89 "yaccfile.y" /* yacc.c:1646  */
    { new_table = (yyvsp[-4].actualChars); newattrs = (yyvsp[-2].myAttrList); addtables((yyvsp[-4].actualChars), (yyvsp[-2].myAttrList)); statement_type = create; eval();}
#line 1407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 91 "yaccfile.y" /* yacc.c:1646  */
    { new_file = (yyvsp[-3].actualChars); old_table = (yyvsp[-1].actualChars); statement_type = insert; eval();}
#line 1413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 93 "yaccfile.y" /* yacc.c:1646  */
    { old_table = (yyvsp[-1].actualChars); statement_type = drop; eval();}
#line 1419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 95 "yaccfile.y" /* yacc.c:1646  */
    { exit(0); }
#line 1425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 98 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.myAttrList) = (struct listAttr *) malloc (sizeof (struct listAttr));
                    (yyval.myAttrList)->name = (yyvsp[-1].actualChars);
                    if(strcmp((yyvsp[0].actualChars),"STRING") == 0) (yyval.myAttrList)->type = 2;
                    else if(strcmp((yyvsp[0].actualChars),"INTEGER") == 0) (yyval.myAttrList)->type = 0;
                    else if(strcmp((yyvsp[0].actualChars),"DOUBLE") == 0) (yyval.myAttrList)->type = 1;
                    (yyval.myAttrList)->next = NULL; }
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 105 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.myAttrList) = (struct listAttr *) malloc (sizeof (struct listAttr));
                                    (yyval.myAttrList)->name = (yyvsp[-3].actualChars);
                                    if(strcmp((yyvsp[-2].actualChars),"STRING") == 0) (yyval.myAttrList)->type = 2;
                                    else if(strcmp((yyvsp[-2].actualChars),"INTEGER") == 0) (yyval.myAttrList)->type = 0;
                                    else if(strcmp((yyvsp[-2].actualChars),"DOUBLE") == 0) (yyval.myAttrList)->type = 1;
                                    (yyval.myAttrList)->next = (yyvsp[0].myAttrList);}
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 113 "yaccfile.y" /* yacc.c:1646  */
    {attsToSelect = (yyvsp[0].myNames); d_attr = 0;}
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 115 "yaccfile.y" /* yacc.c:1646  */
    {attsToSelect = NULL;}
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 117 "yaccfile.y" /* yacc.c:1646  */
    {d_attr = 0; finalFunction = NULL; attsToSelect = (yyvsp[0].myNames);}
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 119 "yaccfile.y" /* yacc.c:1646  */
    {d_attr = 1; finalFunction = NULL; attsToSelect = (yyvsp[0].myNames);}
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 122 "yaccfile.y" /* yacc.c:1646  */
    {d_func = 0; finalFunction = (yyvsp[-1].myOperator);}
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 124 "yaccfile.y" /* yacc.c:1646  */
    {d_func = 1; finalFunction = (yyvsp[-1].myOperator);}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 127 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.myNames) = (struct n_list *)malloc(sizeof(struct n_list));
                                    (yyval.myNames)->name = (yyvsp[0].actualChars);
                                    (yyval.myNames)->next = NULL;}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 131 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.myNames) = (struct n_list *)malloc(sizeof(struct n_list));
                                    (yyval.myNames)->name = (yyvsp[0].actualChars);
                                    (yyval.myNames)->next = (yyvsp[-2].myNames);}
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 136 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.myTables) = (struct tbl_list *) malloc (sizeof (struct tbl_list));
                                    (yyval.myTables)->tableName = (yyvsp[-2].actualChars);
                                    (yyval.myTables)->aliasAs = (yyvsp[0].actualChars);
                                    (yyval.myTables)->next = NULL;}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 141 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.myTables) = (struct tbl_list *) malloc (sizeof (struct tbl_list));
                                    (yyval.myTables)->tableName = (yyvsp[-2].actualChars);
                                    (yyval.myTables)->aliasAs = (yyvsp[0].actualChars);
                                    (yyval.myTables)->next = (yyvsp[-4].myTables);}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 147 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.myOperator) = (struct f_opr *) malloc (sizeof (struct f_opr));
                                      (yyval.myOperator)->left = (struct f_opr *) malloc (sizeof (struct f_opr));
                                      (yyval.myOperator)->left->left = NULL;
                                      (yyval.myOperator)->left->operand = (yyvsp[-2].myOperand);
                                      (yyval.myOperator)->left->right = NULL;
                                      (yyval.myOperator)->operand = NULL;
                                      (yyval.myOperator)->right = (yyvsp[0].myOperator);
                                      (yyval.myOperator)->operatorUsed = (yyvsp[-1].whichOne);}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 156 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.myOperator) = (struct f_opr *) malloc (sizeof (struct f_opr));
                                             (yyval.myOperator)->left = (yyvsp[-3].myOperator);
                                             (yyval.myOperator)->operand = NULL;
                                             (yyval.myOperator)->right = (yyvsp[0].myOperator);
                                             (yyval.myOperator)->operatorUsed = (yyvsp[-1].whichOne);}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 162 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.myOperator) = (yyvsp[-1].myOperator);}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 164 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.myOperator) = (struct f_opr *) malloc (sizeof (struct f_opr));
                                     (yyval.myOperator)->left = NULL;
                                     (yyval.myOperator)->operand = (yyvsp[0].myOperand);
                                     (yyval.myOperator)->right = NULL;}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 169 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.myOperator) = (struct f_opr *) malloc (sizeof (struct f_opr));
                                     (yyval.myOperator)->left = (yyvsp[0].myOperator);
                                     (yyval.myOperator)->operand = NULL;
                                     (yyval.myOperator)->right = NULL;
                                     (yyval.myOperator)->operatorUsed = '-';}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 176 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.whichOne) = '-';}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 177 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.whichOne) = '+';}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 178 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.whichOne) = '*';}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 179 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.whichOne) = '/';}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 182 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = make_and((yyvsp[-3].nodeptr), (yyvsp[0].nodeptr));}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 184 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = make_and((yyvsp[-2].nodeptr), (yyvsp[0].nodeptr));}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 185 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = make_and((yyvsp[-1].nodeptr), NULL);  }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 186 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = make_and((yyvsp[0].nodeptr), NULL);  }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 189 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = make_or((yyvsp[-2].nodeptr), (yyvsp[0].nodeptr)); }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 191 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = make_or((yyvsp[0].nodeptr), NULL); }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 194 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = (yyvsp[-1].nodeptr); (yyval.nodeptr)->left = (yyvsp[-2].nodeptr); (yyval.nodeptr)->right = (yyvsp[0].nodeptr);}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 197 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = makeboolcomp(LESS_THAN); }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 198 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = makeboolcomp(GREATER_THAN); }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 199 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = makeboolcomp(EQUALS); }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 200 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = makeboolcomp(NOTEQUAL); }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 201 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = makeboolcomp(GREATER_THAN_EQ); }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 202 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = makeboolcomp(LESS_THAN_EQ); }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 205 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = makeliteral(STRING, (yyvsp[0].actualChars)); }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 207 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = makeliteral(DOUBLE, (yyvsp[0].actualChars)); }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 209 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = makeliteral(INT, (yyvsp[0].actualChars)); }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 211 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.nodeptr) = makeliteral(NAME, (yyvsp[0].actualChars)); }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 214 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.myOperand) = (struct f_oper *) malloc (sizeof (struct f_oper));
                                     (yyval.myOperand)->type = DOUBLE;
                                     (yyval.myOperand)->actualOperand = (yyvsp[0].actualChars);}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 218 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.myOperand) = (struct f_oper *) malloc (sizeof (struct f_oper));
                                     (yyval.myOperand)->type = INT;
                                     (yyval.myOperand)->actualOperand = (yyvsp[0].actualChars);}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 222 "yaccfile.y" /* yacc.c:1646  */
    {(yyval.myOperand) = (struct f_oper *) malloc (sizeof (struct f_oper));
                                     (yyval.myOperand)->type = NAME;
                                     (yyval.myOperand)->actualOperand = (yyvsp[0].actualChars);}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1719 "y.tab.c" /* yacc.c:1646  */
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
#line 227 "yaccfile.y" /* yacc.c:1906  */


struct node* makeboolcomp(int code) {

    struct node *p = (struct node *) malloc (sizeof (struct node));
    p->code = code;
    p->type = comparision;
    p->left = p->right = NULL;
    p->value =  NULL;

    return p;

}


struct node* makeliteral(int code, char* value) {

    struct node *p = (struct node *) malloc (sizeof (struct node));
    p->type = operand;
    p->code = code;
    p->value = value;

    p->left = p->right =  NULL;

    return p;
}

struct node* make_or(struct node *l, struct node *r) {

    struct node *p = (struct node *) malloc (sizeof (struct node));
    p->type = orlist;
    p->code = 0;
    p->value = NULL;
    p->left = l;
    p->right = r;

    return p;
}

struct node* make_and(struct node *l, struct node *r) {

    struct node *p = (struct node *) malloc (sizeof (struct node));
    p->type = andlist;
    p->code = 0;
    p->value = NULL;
    p->left = l;
    p->right = r;

    return p;
}

void addtables(char *name, struct listAttr *list) {

    struct Gtable *p = (struct Gtable *)malloc(sizeof(struct Gtable));
    p->tablename = name;
    p->attrlist = list;
    p->next = NULL;

    if(head == NULL) {
        head = p;
        return;
    }

    p->next = head;
    head = p;
}

int main(int argc, char *argv) {


    head = NULL;

    printf("-------------------------------------------------------------------\n");
    printf("Welcome to SQL.\n");
    printf("-------------------------------------------------------------------\n");
    printf("Enter exit; to EXIT from SQL\n");
    yyparse();

    return 0;
}

// evaluation


void eval() {

    char *fname; FILE *fp, *fp1, *fp2;
    char *newfile1;
    int i, j=0, status;
    char fn[6]; fn[0] = 't';fn[1] = 'e';fn[2] = 'm';fn[3] = 'p';fn[4] = filenumber; fn[5] = '\0';

    switch(statement_type) {

        case create:
            fname = new_table;
            fp = fopen(fname, "w");

            struct listAttr *temp = newattrs;

            while(temp) {

                fprintf(fp, "|%s\t\t", temp->name);
                temp = temp->next;
            }

            fprintf(fp, "\n");
            fclose(fp);
            return;

        case selec:

			firstfile_flag = 1;

            if(tables->next) {

                // JOIN TWO TABLES
            }
            // Single Table 

            fp = fopen(tables->tableName, "r");
			fp = rec_eval(boolean, fp);
			fclose(fp);

			fn[4] = filenumber;
			
			finalprint_select();
			
			for (i=1;i<=filenumber;i++) {
				fn[4] = i;
				remove(fn);
			}

			filenumber = 0;

            return;
            // boolean

        case insert:
            newfile1 = (char *)malloc(sizeof(new_file)-2);
            for(i=1; i<strlen(new_file)-1;i++) {
                newfile1[j] = new_file[i];
                j++;
            }
            merge(old_table, newfile1);

        break;

        case drop:
            status = remove(old_table);
          
            if( status == 0 )
               printf("%s Table deleted successfully.\n",old_table);
            else
            {
               printf("Unable to delete the Table\n");
               perror("Error");
            }
        return;
    }

}


void merge(char *file1, char *file2) {

	// remove single quote from file2

	FILE *fs1, *fs2, *ft; char ch;

	fs1 = fopen(file1,"r");
    fs2 = fopen(file2,"r");
 
   if( fs1 == NULL || fs2 == NULL ) {
      perror("Error ");
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
 
   ft = fopen("just","w");
 
   if( ft == NULL ) {
      perror("Error opening File");
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
 	
   while( ( ch = fgetc(fs1) ) != EOF )
      fputc(ch,ft);
    while( ( ch = fgetc(fs2) ) != EOF )
      fputc(ch,ft);
	

  fclose(fs1);
	fclose(fs2);
   fclose(ft);

   fs1 = fopen(file1,"w");
   ft = fopen("just","r");
 
	while( ( ch = fgetc(ft) ) != EOF )
    	  fputc(ch,fs1);

    fclose(fs1);fclose(ft);
}

FILE* rec_eval(struct node *p, FILE *fp) {

	FILE *fp1, *fp2, *fp3;
	rewind(fp); // check here later
	 char fn[6]; fn[0] = 't';fn[1] = 'e';fn[2] = 'm';fn[3] = 'p';fn[4] = filenumber; fn[5] = '\0';

	switch(p->type) {

		case andlist:

			fp1 = rec_eval(p->left, fp);
			rewind(fp1);

			fclose(fp1);
			fn[4] = filenumber;
			fp1 = fopen(fn, "r");

			if(!p->right)
				return fp1;

			fp2 = rec_eval(p->right, fp1);
			rewind(fp2);
			return fp2;
		case orlist:

			fp1 = rec_eval(p->left, fp);
			rewind(fp);rewind(fp1);

			fclose(fp1);
			fn[4] = filenumber;
			fp1 = fopen(fn, "r");

			if(!p->right)
				return fp1;

			fp2 = rec_eval(p->right, fp);

			rewind(fp2);

			fclose(fp2);
			fn[4] = filenumber;
			fp2 = fopen(fn, "r");

			fp3 = merge_removedup(fp1, fp2);
			//rewind(fp3);
			return fp3; // anything mishap
		case comparision:

			fp3 = eval_condition(p->code, p, fp);
			rewind(fp3);
			return fp3;
	}
}

char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace(*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace(*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}

FILE* eval_condition(int code, struct node* p, FILE *fp) {

	char *attr_name = p->left->value;int attr_no = 0;char buff[100], valuebuff[100]; 
	char c;
	int i, j=0, intvar;
	float floatvar;
	int t = STRING, val;float fval;char *tname = tables->tableName;
	struct Gtable *temp = head;struct listAttr *alist;
	char * line = NULL;
   size_t len = 0;
   ssize_t read;
   char fn[6]; fn[0] = 't';fn[1] = 'e';fn[2] = 'm';fn[3] = 'p';fn[4] = (filenumber+1); filenumber++; fn[5] = '\0';

   FILE *fp1 = fopen(fn, "w");

	while(temp) {

		if(strcmp(tname, temp->tablename))
			temp = temp->next;
		else
			break;
	}

	if(temp == NULL) {
		printf("%s table not present\n", tname);
		exit(1);
	}
	else {

		alist = temp->attrlist;

		while(alist) {

			if(strcmp(attr_name, alist->name)) {
				alist = alist->next;
				attr_no++;
			}
			else {
				break;
			}
		}
	}

	// obtained attr-no .

	if(p->right->code == INT) {

		t = INT;
		val = atoi(p->right->value);
	}
	else if(p->right->code == DOUBLE) {

		t = DOUBLE;
		fval = atof(p->right->value);
	}
	else if(p->right->code == STRING) {

		t = STRING;
		// here
		for(i = 1, j = 0; i < strlen(p->right->value)-1; i++, j++)
			valuebuff[j] = p->right->value[i];
		valuebuff[j] = '\0';

	}

	if(firstfile_flag) { 

		firstfile_flag = 0;
		read = getline(&line, &len, fp);
	}


	while ((read = getline(&line, &len, fp)) != -1) {

		j = 0;
		for(i = 0; i < attr_no;) {
			if (line[j] == ',')
				i++;
			j++;
		}

		for (i = 0; line[j] != ',' && line[j];) {
			if (line[j] != '\n' && line[j] !=' ') {
				buff[i] = line[j];
				i++;
			}
			j++;
		}
		buff[i] = '\0';
		
		// char *end;

		//   // Trim leading space
		//   while(isspace(*buff)) buff++;

		//   if(*buff == 0)  // All spaces?
		//     return buff;

		//   // Trim trailing space
		//   end = buff + strlen(buff) - 1;
		//   while(end > buff && isspace(*end)) end--;

		//   // Write new null terminator
		//   *(end+1) = 0;

		if (t == DOUBLE) 
			floatvar = atof(buff);
		else if (t == INT)
			intvar = atoi(buff);
		
		switch(p->code) {
		
			case EQUALS: 
				
				if(t == STRING) {

					if(strcmp(buff, valuebuff) == 0)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == INT) {

					if(val == intvar)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == DOUBLE) {

					if(fval == floatvar)
						fprintf(fp1, "%s\n", line);
				}
			break;
			case LESS_THAN:

				if(t == STRING) {

					if(strcmp(buff, valuebuff) < 0)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == INT) {

					if(val > intvar)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == DOUBLE) {

					if(fval > floatvar)
						fprintf(fp1, "%s\n", line);
				}				
			break;
			case GREATER_THAN:

				if(t == STRING) {

					if(strcmp(buff, valuebuff) > 0)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == INT) {

					if(val < intvar)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == DOUBLE) {

					if(fval < floatvar)
						fprintf(fp1, "%s\n", line);
				}				
			break;
			case NOTEQUAL:

				if(t == STRING) {
					if(strcmp(buff, valuebuff) != 0)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == INT) {

					if(val != intvar)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == DOUBLE) {

					if(fval != floatvar)
						fprintf(fp1, "%s\n", line);
				}				
			break;
			case GREATER_THAN_EQ:

				if(t == STRING) {

					if(strcmp(buff, valuebuff) >= 0)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == INT) {

					if(val <= intvar)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == DOUBLE) {

					if(fval <= floatvar)
						fprintf(fp1, "%s\n", line);
				}				
			break;
			case LESS_THAN_EQ:

				if(t == STRING) {

					if(strcmp(buff, valuebuff) <= 0)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == INT) {

					if(val >= intvar)
						fprintf(fp1, "%s\n", line);
				}
				else if(t == DOUBLE) {

					if(fval >= floatvar)
						fprintf(fp1, "%s\n", line);
				}				
			break;
		}
	}

	rewind(fp1);
	return fp1;
}

FILE* merge_removedup(FILE* fp1, FILE* fp2) {

	FILE *fp3;
	char *line1 = NULL, *line2 = NULL;
	size_t len1 = 0, len2 = 0;
	ssize_t read1, read2; int putflag = 1;
	char fn[6]; fn[0] = 't';fn[1] = 'e';fn[2] = 'm';fn[3] = 'p';fn[4] = (filenumber+1); filenumber++; fn[5] = '\0';

	rewind(fp1); rewind(fp2);

	fp3 = fopen(fn, "w");


	while ((read1 = getline(&line1, &len1, fp1)) != -1) {

		while ((read2 = getline(&line2, &len2, fp2)) != -1) {

			if(strcmp(line1, line2) == 0) {

				putflag = 0;
				break;
			}
		}

		if(putflag)
			fprintf(fp3, "%s\n", line1);	
	}

	rewind(fp2);

	while ((read2 = getline(&line2, &len2, fp2)) != -1) {

		fprintf(fp3, "%s\n", line2);
	}

	rewind(fp3);

	return fp3;
}

int compare(const void* a, const void *b) {

	return ( *(int*)a - *(int*)b);
}

void finalprint_select() {

	int att_arr[11] = {0}, i, j; int len;struct listAttr *list, *list1;struct Gtable *temp = head;struct n_list *temp2 = attsToSelect;

	char fn[6]; fn[0] = 't';fn[1] = 'e';fn[2] = 'm';fn[3] = 'p';fn[4] = filenumber; fn[5] = '\0';
	FILE *fp = fopen(fn, "r");

	while(temp) {

		if(strcmp(tables->tableName, temp->tablename))
			temp = temp->next;
		else 
			break;
	}

	if(temp == NULL) {

		printf("Table not Found ..Error\n");
		exit(1);
	}

	list = temp->attrlist;

	i = 0;

	while(attsToSelect) {
		list1 = list;
		while(list1) {

			if(strcmp(list1->name, attsToSelect->name)) {
				
				list1 = list1->next;
				att_arr[i]++;
			}
			else
				break;
		}
		i++;
		attsToSelect = attsToSelect->next;
	}

	len = i;

	qsort(att_arr, len, sizeof(int), compare);

	printf("-----------------------------------------------------------------------------\n");

	printf("Select Statement successfully executed. Table: %s\n", tables->tableName);

	while(temp2) {

		printf("|%s ||  ", temp2->name);
		temp2 = temp2->next;
	}
	printf("\n");

	int k = 0, l;
	char *line = NULL;
	char buff[100];
    size_t leng = 0;
    ssize_t read;
	// printed the initial line stating the name of the attributes
	while ((read = getline(&line, &leng, fp)) != -1) {
		if (strcmp(line, "\n") == 0)
			continue;
		i = 0; j = 0;
		k=0;
		while(k<=len-1) {
			for(; i < att_arr[k];) {
				if (line[j] == ',' && line[j])
					i++;
				j++;
			}

			for (l = 0; line[j] != ',' && line[j]; ) {
				if (line[j] != '\n' && line[j] !=' ') {
					buff[l] = line[j];
					l++;	
				}
				j++;
			}
			buff[l] = '\0';
			printf("%s ||  ", buff);
			k++;
		}
		printf("\n");
	}
}
