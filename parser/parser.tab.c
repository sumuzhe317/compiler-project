/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include "parser.hh"
#include <llvm/Support/JSON.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/raw_ostream.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <iostream>
#include <sstream>
int token_idx = -1;
#define yyerror(x)                                                             \
  do {                                                                         \
    llvm::errs() <<"token idx "<<token_idx<<"\n";                              \
    llvm::errs() << (x);                                                       \
  } while (0)
namespace {
auto llvmin = llvm::MemoryBuffer::getFileOrSTDIN("-");
auto input = llvmin.get() -> getBuffer();
auto end = input.end(), it = input.begin();
auto wk_getline(char endline = "\n"[0]) {
  auto beg = it;
  while (it != end && *it != endline)
    ++it;
  auto len = it - beg;
  if (it != end && *it == endline)
    ++it;
  return llvm::StringRef(beg, len);
}
bool debug = false;
llvm::json::Array stak;
int def_num = 0;
bool global_decl = false;
std::stack<bool> lvalStack;
int func_FPara_num = 0;
// std::stack<int> func_RPara_num;
int init_stak_level = 1;
llvm::json::Array initStak;
llvm::json::Array lexStack;
}  //namespace
int print_stack(){
  if(debug) llvm::outs()<<"\n-------------------------------printf stak-------------------------------\n";
  for(int i=0;i<stak.size();i++){
    if(debug) llvm::outs()<<stak[i]<<"\n";
  }
  if(debug) llvm::outs()<<"\n-----------------------------printf stak end-----------------------------\n";
  return 0;
}
auto yylex() {
  token_idx ++;
  auto tk = wk_getline();
  auto b = tk.find("'") + 1, e = tk.rfind("'");
  auto s = tk.substr(b, e - b).str(), t = tk.substr(0, tk.find(" ")).str();
  if(debug) llvm::outs()<<"yylex ";
  if(debug) llvm::outs()<<t<<"\n";


  if (t == "const")
    return T_CONST;
  if (t == "comma")
    return T_COMMA;
  if (t == "semi")
    return T_SEMI;
  if (t == "float")
    return T_FLOAT;
  if (t == "int")
    return T_INT;
  if (t == "char")
    return T_CHAR;
  if (t == "longlong")
    return T_LONGLONG;
  if (t == "l_square")
    return T_L_SQUARE;
  if (t == "r_square")
    return T_R_SQUARE;
  if (t == "equal")
    return T_EQUAL;
  if (t == "l_brace")
    return T_L_BRACE;
  if (t == "r_brace")
    return T_R_BRACE;
  if (t == "identifier") {
    lexStack.push_back(llvm::json::Object{{"value", s}});
    // stak.push_back(llvm::json::Object{{"value", s}});
    return T_IDENTIFIER;
  }
  if (t == "l_paren")
    return T_L_PAREN;
  if (t == "r_paren")
    return T_R_PAREN;
  if (t == "void")
    return T_VOID;
  if (t == "if")
    return T_IF;
  if (t == "else")
    return T_ELSE;
  if (t == "do")
    return T_DO;
  if (t == "while")
    return T_WHILE;
  if (t == "break")
    return T_BREAK;
  if (t == "continue")
    return T_CONTINUE;
  if (t == "return")
    return T_RETURN;
  if (t == "numeric_constant") {
    int tttnum;
    if(s[0]=='0'&&(s[1]=='x'||s[1]=='X')){
      tttnum = strtol(s.c_str(),0,16);
    }else if(s[0]=='0'){
      tttnum = strtol(s.c_str(),0,8);
    }else{
      tttnum = strtol(s.c_str(),0,10);
    }
    lexStack.push_back(llvm::json::Object{{"kind", "IntegerLiteral"}, {"value", std::to_string(tttnum)}});
    // stak.push_back(llvm::json::Object{{"kind", "IntegerLiteral"}, {"value", s}});
    return T_NUMERIC_CONSTANT;
  }
  if (t == "plus"){
    //stak.push_back(
    //    llvm::json::Object{{"kind", "Operator"}, {"opcode", s}});
    return T_PLUS;
  }
  if (t == "minus"){
    //stak.push_back(
    //    llvm::json::Object{{"kind", "Operator"}, {"opcode", s}});
    return T_MINUS;
  }
  if (t == "exclaim"){
    //stak.push_back(
    //    llvm::json::Object{{"kind", "Operator"}, {"opcode", s}});
    return T_EXCLAIM;
  }
  if (t == "star"){
    //stak.push_back(
    //    llvm::json::Object{{"kind", "Operator"}, {"opcode", s}});
    return T_STAR;
  }
  if (t == "slash"){
    //stak.push_back(
    //    llvm::json::Object{{"kind", "Operator"}, {"opcode", s}});
    return T_SLASH;
  }
  if (t == "percent"){
    //stak.push_back(
    //    llvm::json::Object{{"kind", "Operator"}, {"opcode", s}});
    return T_PERCENT;
  }
  if (t == "less")
  {
    //stak.push_back(
    //    llvm::json::Object{{"kind", "Operator"}, {"opcode", s}});
    return T_LESS;
  }
  if (t == "greater")
  {
    //stak.push_back(
    //    llvm::json::Object{{"kind", "Operator"}, {"opcode", s}});
    return T_GREATER;
  }
  if (t == "lessequal")
  {
    //stak.push_back(
    //    llvm::json::Object{{"kind", "Operator"}, {"opcode", s}});
    return T_LESSEQUAL;
  }
  if (t == "greaterequal")
  {
    //stak.push_back(
    //    llvm::json::Object{{"kind", "Operator"}, {"opcode", s}});
    return T_GREATEREQUAL;
  }
  if (t == "equalequal")
  {
    //stak.push_back(
    //    llvm::json::Object{{"kind", "Operator"}, {"opcode", s}});
    return T_EQUALEQUAL;
  }
  if (t == "exclaimequal")
  {
    //stak.push_back(
    //    llvm::json::Object{{"kind", "Operator"}, {"opcode", s}});
    return T_EXCLAIMEQUAL;
  }
  if (t == "ampamp")
  {
    //stak.push_back(
    //    llvm::json::Object{{"kind", "Operator"}, {"opcode", s}});
    return T_AMPAMP;
  }
  if (t == "pipepipe")
  {
    //stak.push_back(
    //    llvm::json::Object{{"kind", "Operator"}, {"opcode", s}});
    return T_PIPEPIPE;
  }
  return YYEOF;
}

int main() {
  yyparse();
  llvm::outs() << stak.back() << "\n";
}

#line 278 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_CONST = 258,                 /* T_CONST  */
    T_COMMA = 259,                 /* T_COMMA  */
    T_SEMI = 260,                  /* T_SEMI  */
    T_FLOAT = 261,                 /* T_FLOAT  */
    T_INT = 262,                   /* T_INT  */
    T_CHAR = 263,                  /* T_CHAR  */
    T_LONGLONG = 264,              /* T_LONGLONG  */
    T_L_SQUARE = 265,              /* T_L_SQUARE  */
    T_R_SQUARE = 266,              /* T_R_SQUARE  */
    T_EQUAL = 267,                 /* T_EQUAL  */
    T_L_BRACE = 268,               /* T_L_BRACE  */
    T_R_BRACE = 269,               /* T_R_BRACE  */
    T_IDENTIFIER = 270,            /* T_IDENTIFIER  */
    T_L_PAREN = 271,               /* T_L_PAREN  */
    T_R_PAREN = 272,               /* T_R_PAREN  */
    T_VOID = 273,                  /* T_VOID  */
    T_IF = 274,                    /* T_IF  */
    T_ELSE = 275,                  /* T_ELSE  */
    T_DO = 276,                    /* T_DO  */
    T_WHILE = 277,                 /* T_WHILE  */
    T_BREAK = 278,                 /* T_BREAK  */
    T_CONTINUE = 279,              /* T_CONTINUE  */
    T_RETURN = 280,                /* T_RETURN  */
    T_NUMERIC_CONSTANT = 281,      /* T_NUMERIC_CONSTANT  */
    T_PLUS = 282,                  /* T_PLUS  */
    T_MINUS = 283,                 /* T_MINUS  */
    T_EXCLAIM = 284,               /* T_EXCLAIM  */
    T_STAR = 285,                  /* T_STAR  */
    T_SLASH = 286,                 /* T_SLASH  */
    T_PERCENT = 287,               /* T_PERCENT  */
    T_LESS = 288,                  /* T_LESS  */
    T_GREATER = 289,               /* T_GREATER  */
    T_LESSEQUAL = 290,             /* T_LESSEQUAL  */
    T_GREATEREQUAL = 291,          /* T_GREATEREQUAL  */
    T_EQUALEQUAL = 292,            /* T_EQUALEQUAL  */
    T_EXCLAIMEQUAL = 293,          /* T_EXCLAIMEQUAL  */
    T_AMPAMP = 294,                /* T_AMPAMP  */
    T_PIPEPIPE = 295               /* T_PIPEPIPE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_CONST = 3,                    /* T_CONST  */
  YYSYMBOL_T_COMMA = 4,                    /* T_COMMA  */
  YYSYMBOL_T_SEMI = 5,                     /* T_SEMI  */
  YYSYMBOL_T_FLOAT = 6,                    /* T_FLOAT  */
  YYSYMBOL_T_INT = 7,                      /* T_INT  */
  YYSYMBOL_T_CHAR = 8,                     /* T_CHAR  */
  YYSYMBOL_T_LONGLONG = 9,                 /* T_LONGLONG  */
  YYSYMBOL_T_L_SQUARE = 10,                /* T_L_SQUARE  */
  YYSYMBOL_T_R_SQUARE = 11,                /* T_R_SQUARE  */
  YYSYMBOL_T_EQUAL = 12,                   /* T_EQUAL  */
  YYSYMBOL_T_L_BRACE = 13,                 /* T_L_BRACE  */
  YYSYMBOL_T_R_BRACE = 14,                 /* T_R_BRACE  */
  YYSYMBOL_T_IDENTIFIER = 15,              /* T_IDENTIFIER  */
  YYSYMBOL_T_L_PAREN = 16,                 /* T_L_PAREN  */
  YYSYMBOL_T_R_PAREN = 17,                 /* T_R_PAREN  */
  YYSYMBOL_T_VOID = 18,                    /* T_VOID  */
  YYSYMBOL_T_IF = 19,                      /* T_IF  */
  YYSYMBOL_T_ELSE = 20,                    /* T_ELSE  */
  YYSYMBOL_T_DO = 21,                      /* T_DO  */
  YYSYMBOL_T_WHILE = 22,                   /* T_WHILE  */
  YYSYMBOL_T_BREAK = 23,                   /* T_BREAK  */
  YYSYMBOL_T_CONTINUE = 24,                /* T_CONTINUE  */
  YYSYMBOL_T_RETURN = 25,                  /* T_RETURN  */
  YYSYMBOL_T_NUMERIC_CONSTANT = 26,        /* T_NUMERIC_CONSTANT  */
  YYSYMBOL_T_PLUS = 27,                    /* T_PLUS  */
  YYSYMBOL_T_MINUS = 28,                   /* T_MINUS  */
  YYSYMBOL_T_EXCLAIM = 29,                 /* T_EXCLAIM  */
  YYSYMBOL_T_STAR = 30,                    /* T_STAR  */
  YYSYMBOL_T_SLASH = 31,                   /* T_SLASH  */
  YYSYMBOL_T_PERCENT = 32,                 /* T_PERCENT  */
  YYSYMBOL_T_LESS = 33,                    /* T_LESS  */
  YYSYMBOL_T_GREATER = 34,                 /* T_GREATER  */
  YYSYMBOL_T_LESSEQUAL = 35,               /* T_LESSEQUAL  */
  YYSYMBOL_T_GREATEREQUAL = 36,            /* T_GREATEREQUAL  */
  YYSYMBOL_T_EQUALEQUAL = 37,              /* T_EQUALEQUAL  */
  YYSYMBOL_T_EXCLAIMEQUAL = 38,            /* T_EXCLAIMEQUAL  */
  YYSYMBOL_T_AMPAMP = 39,                  /* T_AMPAMP  */
  YYSYMBOL_T_PIPEPIPE = 40,                /* T_PIPEPIPE  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_CompUnit = 42,                  /* CompUnit  */
  YYSYMBOL_CompUnitItem = 43,              /* CompUnitItem  */
  YYSYMBOL_Decl = 44,                      /* Decl  */
  YYSYMBOL_ConstDecl = 45,                 /* ConstDecl  */
  YYSYMBOL_ConstExpChain = 46,             /* ConstExpChain  */
  YYSYMBOL_ConstDefChain = 47,             /* ConstDefChain  */
  YYSYMBOL_ConstDef = 48,                  /* ConstDef  */
  YYSYMBOL_ConstInitVal = 49,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValChain = 50,         /* ConstInitValChain  */
  YYSYMBOL_VarDecl = 51,                   /* VarDecl  */
  YYSYMBOL_VarDefChain = 52,               /* VarDefChain  */
  YYSYMBOL_VarDef = 53,                    /* VarDef  */
  YYSYMBOL_InitVal = 54,                   /* InitVal  */
  YYSYMBOL_InitValChain = 55,              /* InitValChain  */
  YYSYMBOL_FuncDecl = 56,                  /* FuncDecl  */
  YYSYMBOL_FuncDef = 57,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 58,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 59,                /* FuncFParam  */
  YYSYMBOL_60_1 = 60,                      /* $@1  */
  YYSYMBOL_61_2 = 61,                      /* $@2  */
  YYSYMBOL_ArrayFuncFParam = 62,           /* ArrayFuncFParam  */
  YYSYMBOL_Block = 63,                     /* Block  */
  YYSYMBOL_BlockItemChain = 64,            /* BlockItemChain  */
  YYSYMBOL_BlockItem = 65,                 /* BlockItem  */
  YYSYMBOL_Stmt = 66,                      /* Stmt  */
  YYSYMBOL_MatchedStmt = 67,               /* MatchedStmt  */
  YYSYMBOL_OpenStmt = 68,                  /* OpenStmt  */
  YYSYMBOL_Exp = 69,                       /* Exp  */
  YYSYMBOL_LVal = 70,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 71,                /* PrimaryExp  */
  YYSYMBOL_UnaryExp = 72,                  /* UnaryExp  */
  YYSYMBOL_Number = 73,                    /* Number  */
  YYSYMBOL_FuncRParams = 74,               /* FuncRParams  */
  YYSYMBOL_MulExp = 75,                    /* MulExp  */
  YYSYMBOL_AddExp = 76,                    /* AddExp  */
  YYSYMBOL_RelExp = 77,                    /* RelExp  */
  YYSYMBOL_EqExp = 78,                     /* EqExp  */
  YYSYMBOL_LAndExp = 79,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 80,                    /* LOrExp  */
  YYSYMBOL_ConstExp = 81                   /* ConstExp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   299

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  221

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   254,   254,   272,   294,   297,   299,   301,   303,   307,
     309,   311,   315,   319,   325,   328,   333,   344,   356,   369,
     374,   403,   406,   411,   415,   417,   421,   426,   435,   442,
     456,   470,   477,   508,   512,   518,   525,   532,   552,   573,
     582,   591,   612,   635,   639,   644,   650,   650,   662,   671,
     671,   691,   694,   705,   707,   711,   713,   718,   737,   741,
     759,   761,   765,   778,   780,   787,   789,   807,   821,   823,
     825,   827,   841,   857,   873,   897,   901,   908,   929,   933,
     935,   939,   942,   958,   998,  1016,  1034,  1054,  1064,  1075,
    1093,  1096,  1117,  1138,  1163,  1165,  1185,  1208,  1210,  1229,
    1250,  1270,  1293,  1295,  1313,  1334,  1336,  1356,  1358,  1378
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_CONST", "T_COMMA",
  "T_SEMI", "T_FLOAT", "T_INT", "T_CHAR", "T_LONGLONG", "T_L_SQUARE",
  "T_R_SQUARE", "T_EQUAL", "T_L_BRACE", "T_R_BRACE", "T_IDENTIFIER",
  "T_L_PAREN", "T_R_PAREN", "T_VOID", "T_IF", "T_ELSE", "T_DO", "T_WHILE",
  "T_BREAK", "T_CONTINUE", "T_RETURN", "T_NUMERIC_CONSTANT", "T_PLUS",
  "T_MINUS", "T_EXCLAIM", "T_STAR", "T_SLASH", "T_PERCENT", "T_LESS",
  "T_GREATER", "T_LESSEQUAL", "T_GREATEREQUAL", "T_EQUALEQUAL",
  "T_EXCLAIMEQUAL", "T_AMPAMP", "T_PIPEPIPE", "$accept", "CompUnit",
  "CompUnitItem", "Decl", "ConstDecl", "ConstExpChain", "ConstDefChain",
  "ConstDef", "ConstInitVal", "ConstInitValChain", "VarDecl",
  "VarDefChain", "VarDef", "InitVal", "InitValChain", "FuncDecl",
  "FuncDef", "FuncFParams", "FuncFParam", "$@1", "$@2", "ArrayFuncFParam",
  "Block", "BlockItemChain", "BlockItem", "Stmt", "MatchedStmt",
  "OpenStmt", "Exp", "LVal", "PrimaryExp", "UnaryExp", "Number",
  "FuncRParams", "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp",
  "LOrExp", "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-180)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,    60,    -3,     4,    20,  -180,  -180,  -180,  -180,  -180,
    -180,     9,     9,     9,    85,   251,  -180,    12,  -180,  -180,
      98,   253,  -180,   255,   257,   212,    87,   157,   191,    30,
    -180,   159,   127,   238,     9,  -180,  -180,  -180,    26,   212,
    -180,   212,   212,   212,  -180,    41,  -180,  -180,  -180,   199,
     178,   201,   226,    23,    25,    88,    57,  -180,  -180,    66,
      79,    83,    27,  -180,   212,    87,   239,  -180,   106,    43,
      64,  -180,  -180,   127,  -180,   142,   110,  -180,  -180,  -180,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,  -180,  -180,  -180,    32,    94,    94,
    -180,   170,  -180,   258,   112,   130,  -180,  -180,  -180,   132,
    -180,  -180,    39,  -180,  -180,  -180,    44,  -180,   137,  -180,
    -180,  -180,   199,   199,   178,   178,   178,   178,   201,   201,
     226,    23,    87,  -180,   141,   128,   152,   128,  -180,   163,
    -180,   167,   156,   174,   193,   209,   248,     6,  -180,  -180,
     197,  -180,  -180,  -180,  -180,   262,   242,  -180,  -180,  -180,
    -180,  -180,  -180,   127,  -180,   212,  -180,  -180,  -180,  -180,
     212,   228,   265,   134,   259,   212,   254,   212,  -180,  -180,
    -180,   272,  -180,  -180,  -180,  -180,   212,  -180,  -180,   267,
    -180,   264,   200,   225,   263,   266,   268,  -180,   276,  -180,
      94,   278,    59,   279,    70,   107,   212,   107,  -180,   128,
     281,   282,  -180,   269,   271,  -180,   107,   285,  -180,  -180,
    -180
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     4,     6,     7,     8,
       5,     0,     0,     0,    26,     0,    24,     0,     1,     2,
       0,     0,    14,     0,     0,     0,     0,     0,    28,     0,
      23,     0,     0,     0,     0,     9,    10,    11,    76,     0,
      87,     0,     0,     0,   109,    79,    81,    90,    80,    94,
      97,   102,   105,   107,    75,     0,     0,    27,    30,     0,
       0,     0,     0,    43,     0,     0,    26,    25,     0,     0,
       0,    16,    18,     0,    15,     0,     0,    84,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    31,    33,     0,    45,    46,
      35,     0,    39,     0,     0,     0,    29,    36,    40,     0,
      19,    21,     0,    17,    82,    88,     0,    78,     0,    91,
      92,    93,    95,    96,    98,    99,   100,   101,   103,   104,
     106,   108,     0,    32,     0,    48,     0,    49,    63,     0,
      53,     0,     0,     0,     0,     0,     0,     0,    59,    65,
       0,    55,    58,    60,    61,     0,    79,    44,    37,    41,
      13,    38,    42,     0,    20,     0,    83,    77,    34,    51,
       0,     0,     0,    26,     0,     0,     0,     0,    68,    69,
      70,     0,    54,    57,    56,    64,     0,    22,    89,     0,
      47,     0,     0,     0,     0,     0,     0,    71,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    50,
       0,     0,    73,    60,     0,    67,     0,     0,    66,    74,
      72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -180,  -180,   287,   -91,  -180,   273,   256,   260,   -65,  -180,
    -180,  -180,   270,   -50,  -180,  -180,  -180,   -30,   189,  -180,
    -180,   -95,   -54,  -180,  -180,  -141,  -179,    80,   -26,   -98,
    -180,   -25,  -180,  -180,   186,   158,   182,   203,   204,  -180,
     -23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    28,    21,    22,    71,   112,
       8,    15,    16,    57,    97,     9,    10,    62,    63,   136,
     172,   135,   149,   150,   151,   152,   153,   154,    44,    45,
      46,    47,    48,   116,    49,    50,    51,    52,    53,    54,
      72
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      58,    69,    55,   156,   137,   111,    96,   102,   113,   184,
     148,   180,    14,    76,   108,   106,    77,    78,    79,    17,
      18,    38,    39,     1,    20,     1,   213,     2,    31,     2,
      58,   103,    40,    41,    42,    43,   132,   218,     3,    58,
       3,   105,    75,   163,   104,    66,   133,   103,   165,   115,
     159,    80,   156,   164,   118,   162,   119,   120,   121,   183,
     109,   166,    92,   103,   212,    93,   215,    11,    12,    13,
      56,    95,    38,    39,   103,   155,   210,    70,   110,    38,
      39,    98,   168,    40,    41,    42,    43,   211,   100,   176,
      40,    41,    42,    43,    99,    25,   101,    26,   187,    94,
      56,    27,    38,    39,   134,   209,    58,   156,    25,   156,
      32,   107,   138,    40,    41,    42,    43,   158,   156,   101,
     101,   181,    38,    39,   155,   101,   142,   117,   143,   144,
     145,   146,   147,    40,    41,    42,    43,   161,   170,   188,
      70,   160,    38,    39,    25,   101,    26,   189,   167,   194,
     192,   196,   169,    40,    41,    42,    43,    38,    39,   114,
     198,   171,   202,   204,    59,    60,    59,    60,    40,    41,
      42,    43,   175,     1,    61,   138,    68,   139,   173,   155,
     214,   155,   174,   101,   140,    38,    39,   101,   141,   142,
     155,   143,   144,   145,   146,   147,    40,    41,    42,    43,
       1,    64,   138,    65,   139,    84,    85,    59,    60,   177,
     101,   182,    38,    39,   178,   141,   142,   201,   143,   144,
     145,   146,   147,    40,    41,    42,    43,    38,    39,    81,
      82,    83,    59,    60,    86,    87,    88,    89,    40,    41,
      42,    43,   203,   190,   124,   125,   126,   127,    64,    25,
      73,    26,    80,   179,   186,    29,    30,    34,    35,    34,
      36,    34,    37,    90,    91,    59,    60,   185,    23,    24,
     122,   123,   128,   129,   191,   193,   195,   197,   199,   200,
     205,   208,   206,   100,   107,   207,   158,   161,   217,   216,
     220,    19,   157,    33,    74,   130,   219,   131,     0,    67
};

static const yytype_int16 yycheck[] =
{
      26,    31,    25,   101,    99,    70,    56,    61,    73,   150,
     101,     5,    15,    39,    68,    65,    41,    42,    43,    15,
       0,    15,    16,     3,    15,     3,   205,     7,    16,     7,
      56,     4,    26,    27,    28,    29,     4,   216,    18,    65,
      18,    64,    16,     4,    17,    15,    14,     4,     4,    75,
     104,    10,   150,    14,    80,   109,    81,    82,    83,   150,
      17,    17,    39,     4,   205,    40,   207,     7,     8,     9,
      13,    14,    15,    16,     4,   101,    17,    13,    14,    15,
      16,    15,   132,    26,    27,    28,    29,    17,     5,   143,
      26,    27,    28,    29,    15,    10,    13,    12,   163,    11,
      13,    16,    15,    16,    10,   200,   132,   205,    10,   207,
      12,     5,     5,    26,    27,    28,    29,     5,   216,    13,
      13,   147,    15,    16,   150,    13,    19,    17,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     5,    10,   165,
      13,    11,    15,    16,    10,    13,    12,   170,    11,   175,
      16,   177,    11,    26,    27,    28,    29,    15,    16,    17,
     186,     9,   192,   193,     7,     8,     7,     8,    26,    27,
      28,    29,    16,     3,    17,     5,    17,     7,    15,   205,
     206,   207,    15,    13,    14,    15,    16,    13,    18,    19,
     216,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       3,    10,     5,    12,     7,    27,    28,     7,     8,    16,
      13,    14,    15,    16,     5,    18,    19,    17,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    15,    16,    30,
      31,    32,     7,     8,    33,    34,    35,    36,    26,    27,
      28,    29,    17,    15,    86,    87,    88,    89,    10,    10,
      12,    12,    10,     5,    12,     4,     5,     4,     5,     4,
       5,     4,     5,    37,    38,     7,     8,     5,    12,    13,
      84,    85,    90,    91,     9,    16,    22,     5,    11,    15,
      17,     5,    16,     5,     5,    17,     5,     5,    17,    20,
       5,     4,   103,    20,    34,    92,   216,    93,    -1,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     7,    18,    42,    43,    44,    45,    51,    56,
      57,     7,     8,     9,    15,    52,    53,    15,     0,    43,
      15,    47,    48,    47,    47,    10,    12,    16,    46,     4,
       5,    16,    12,    46,     4,     5,     5,     5,    15,    16,
      26,    27,    28,    29,    69,    70,    71,    72,    73,    75,
      76,    77,    78,    79,    80,    81,    13,    54,    69,     7,
       8,    17,    58,    59,    10,    12,    15,    53,    17,    58,
      13,    49,    81,    12,    48,    16,    69,    72,    72,    72,
      10,    30,    31,    32,    27,    28,    33,    34,    35,    36,
      37,    38,    39,    40,    11,    14,    54,    55,    15,    15,
       5,    13,    63,     4,    17,    81,    54,     5,    63,    17,
      14,    49,    50,    49,    17,    69,    74,    17,    69,    72,
      72,    72,    75,    75,    76,    76,    76,    76,    77,    77,
      78,    79,     4,    14,    10,    62,    60,    62,     5,     7,
      14,    18,    19,    21,    22,    23,    24,    25,    44,    63,
      64,    65,    66,    67,    68,    69,    70,    59,     5,    63,
      11,     5,    63,     4,    14,     4,    17,    11,    54,    11,
      10,     9,    61,    15,    15,    16,    63,    16,     5,     5,
       5,    69,    14,    44,    66,     5,    12,    49,    69,    81,
      15,     9,    16,    16,    69,    22,    69,     5,    69,    11,
      15,    17,    58,    17,    58,    17,    16,    17,     5,    62,
      17,    17,    66,    67,    69,    66,    20,    17,    67,    68,
       5
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    44,    44,    44,    45,
      45,    45,    46,    46,    47,    47,    48,    48,    49,    49,
      49,    50,    50,    51,    52,    52,    53,    53,    53,    53,
      54,    54,    54,    55,    55,    56,    56,    56,    56,    57,
      57,    57,    57,    58,    58,    59,    60,    59,    59,    61,
      59,    62,    62,    63,    63,    64,    64,    64,    65,    65,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    68,    69,    70,    70,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    73,    74,    74,
      75,    75,    75,    75,    76,    76,    76,    77,    77,    77,
      77,    77,    78,    78,    78,    79,    79,    80,    80,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     3,     4,     1,     3,     3,     4,     1,     2,
       3,     1,     3,     3,     1,     3,     1,     3,     2,     4,
       1,     2,     3,     1,     3,     5,     5,     6,     6,     5,
       5,     6,     6,     1,     3,     2,     0,     5,     3,     0,
       7,     2,     4,     2,     3,     1,     2,     2,     1,     1,
       1,     1,     4,     1,     2,     1,     7,     5,     2,     2,
       2,     3,     7,     5,     7,     1,     1,     4,     3,     1,
       1,     1,     3,     4,     2,     2,     2,     1,     1,     3,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          YYNOMEM;                                                      \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      YY_LAC_ESTABLISH;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");
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
| yyreduce -- do a reduction.  |
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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2: /* CompUnit: CompUnit CompUnitItem  */
#line 254 "parser.y"
                                {
  if(global_decl){
    llvm::json::Array json_inner = llvm::json::Array{};
    for(int i = 0; i < def_num; i++){
      json_inner.push_back(stak.back());
      stak.pop_back();
    }
    llvm::json::Array * array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
    for(int i = def_num-1; i >= 0; i--){
      array_inner->push_back(json_inner[i]);
    }
    global_decl = false;
  }else{
    auto inner = stak.back();
    stak.pop_back();
    stak.back().getAsObject()->get("inner")->getAsArray()->push_back(inner);
    global_decl = false;
  }
}
#line 2111 "parser.tab.c"
    break;

  case 3: /* CompUnit: CompUnitItem  */
#line 272 "parser.y"
               {
  if(global_decl){
    llvm::json::Array json_inner = llvm::json::Array{};
    for(int i = 0; i < def_num; i++){
      json_inner.push_back(stak.back());
      stak.pop_back();
    }
    stak.push_back(llvm::json::Object{{"kind", "TranslationUnitDecl"},
                                    {"inner", llvm::json::Array{}}});
    llvm::json::Array * array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
    for(int i = def_num-1; i >= 0; i--){
      array_inner->push_back(json_inner[i]);
    }
    global_decl = false;
  }else{
    auto inner = stak.back();
    stak.back() = llvm::json::Object{{"kind", "TranslationUnitDecl"},
                                    {"inner", llvm::json::Array{inner}}};
    global_decl = false;
  }
}
#line 2137 "parser.tab.c"
    break;

  case 4: /* CompUnitItem: Decl  */
#line 294 "parser.y"
     {
  global_decl = true;
}
#line 2145 "parser.tab.c"
    break;

  case 5: /* CompUnitItem: FuncDef  */
#line 297 "parser.y"
         {}
#line 2151 "parser.tab.c"
    break;

  case 6: /* Decl: ConstDecl  */
#line 299 "parser.y"
               {
  
}
#line 2159 "parser.tab.c"
    break;

  case 7: /* Decl: VarDecl  */
#line 301 "parser.y"
          {

}
#line 2167 "parser.tab.c"
    break;

  case 8: /* Decl: FuncDecl  */
#line 303 "parser.y"
           {

}
#line 2175 "parser.tab.c"
    break;

  case 9: /* ConstDecl: T_CONST T_INT ConstDefChain T_SEMI  */
#line 307 "parser.y"
                                             {

}
#line 2183 "parser.tab.c"
    break;

  case 10: /* ConstDecl: T_CONST T_CHAR ConstDefChain T_SEMI  */
#line 309 "parser.y"
                                     {
  
}
#line 2191 "parser.tab.c"
    break;

  case 11: /* ConstDecl: T_CONST T_LONGLONG ConstDefChain T_SEMI  */
#line 311 "parser.y"
                                         {
  
}
#line 2199 "parser.tab.c"
    break;

  case 12: /* ConstExpChain: T_L_SQUARE ConstExp T_R_SQUARE  */
#line 315 "parser.y"
                                             {
  // todo
  lvalStack.pop();
  stak.pop_back();
}
#line 2209 "parser.tab.c"
    break;

  case 13: /* ConstExpChain: ConstExpChain T_L_SQUARE ConstExp T_R_SQUARE  */
#line 319 "parser.y"
                                               {
  // todo
  lvalStack.pop();
  stak.pop_back();
}
#line 2219 "parser.tab.c"
    break;

  case 14: /* ConstDefChain: ConstDef  */
#line 325 "parser.y"
                       {
  if(debug) llvm::outs()<<"constdef first\n";
  def_num = 1;
}
#line 2228 "parser.tab.c"
    break;

  case 15: /* ConstDefChain: ConstDefChain T_COMMA ConstDef  */
#line 328 "parser.y"
                                {
  if(debug) llvm::outs()<<"constdef second\n";
  def_num++;
}
#line 2237 "parser.tab.c"
    break;

  case 16: /* ConstDef: T_IDENTIFIER T_EQUAL ConstInitVal  */
#line 333 "parser.y"
                                           {
  // todo
  auto exp1 = lexStack.back();
  lexStack.pop_back();
  auto exp2 = stak.back();
  stak.pop_back();
  initStak.pop_back();
  auto exp1_name = exp1.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "VarDecl"},
                                  {"name",exp1_name},
                                  {"inner", llvm::json::Array{exp2}}});
}
#line 2254 "parser.tab.c"
    break;

  case 17: /* ConstDef: T_IDENTIFIER ConstExpChain T_EQUAL ConstInitVal  */
#line 344 "parser.y"
                                                 {
  // todo
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto init_val = stak.back();
  stak.pop_back();
  initStak.pop_back();
  // to compute constexp
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "VarDecl"}, {"name", name},{"inner",llvm::json::Array{init_val}}});
}
#line 2270 "parser.tab.c"
    break;

  case 18: /* ConstInitVal: ConstExp  */
#line 356 "parser.y"
                      {
  // todo
  if(debug) llvm::outs()<<"constexp 2 ConstInitVal\n";
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind", "ImplicitCastExpr"},
                                   {"inner", llvm::json::Array{rvalexp}}};
  }

  init_stak_level = 1;
  initStak.push_back(llvm::json::Object{{"value",1}});
}
#line 2289 "parser.tab.c"
    break;

  case 19: /* ConstInitVal: T_L_BRACE T_R_BRACE  */
#line 369 "parser.y"
                       {
  // todo
  stak.push_back(llvm::json::Object{{"kind", "InitListExpr"}});
  init_stak_level = 1;
  initStak.push_back(llvm::json::Object{{"value",init_stak_level}});
}
#line 2300 "parser.tab.c"
    break;

  case 20: /* ConstInitVal: T_L_BRACE ConstInitValChain T_R_BRACE  */
#line 374 "parser.y"
                                         {
  // todo
  auto json_inner = llvm::json::Array{};
  int initStakSize = initStak.size();
  // while(initStakSize--){
  //   auto level_number = initStak.back().getAsObject()->get("value")->getAsInteger();
  //   if(level_number.value() == init_stak_level){
  //     json_inner.push_back(stak.back());
  //     stak.pop_back();
  //     initStak.pop_back();
  //   }else{
  //     break;
  //   }
  // }
  while(initStakSize--){
    json_inner.push_back(stak.back());
    stak.pop_back();
    initStak.pop_back();
  }
  stak.push_back(llvm::json::Object{{"kind", "InitListExpr"},
                                   {"inner", llvm::json::Array{}}});
  // llvm::json::Array * array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  // for(int i = json_inner.size()-1; i >= 0; i--){
  //   array_inner->push_back(json_inner[i]);
  // }
  init_stak_level++;
  initStak.push_back(llvm::json::Object{{"value",init_stak_level}});
}
#line 2333 "parser.tab.c"
    break;

  case 21: /* ConstInitValChain: ConstInitVal  */
#line 403 "parser.y"
                                {
  // todo

}
#line 2342 "parser.tab.c"
    break;

  case 22: /* ConstInitValChain: ConstInitValChain T_COMMA ConstInitVal  */
#line 406 "parser.y"
                                         {
  // todo
}
#line 2350 "parser.tab.c"
    break;

  case 23: /* VarDecl: T_INT VarDefChain T_SEMI  */
#line 411 "parser.y"
                                  {
  if(debug) llvm::outs()<<"valdefchain 2 vardecl and def_num is "<<def_num<<"\n";
}
#line 2358 "parser.tab.c"
    break;

  case 24: /* VarDefChain: VarDef  */
#line 415 "parser.y"
                   {
  def_num = 1;
}
#line 2366 "parser.tab.c"
    break;

  case 25: /* VarDefChain: VarDefChain T_COMMA VarDef  */
#line 417 "parser.y"
                            {
  def_num++;
}
#line 2374 "parser.tab.c"
    break;

  case 26: /* VarDef: T_IDENTIFIER  */
#line 421 "parser.y"
                    {
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "VarDecl"}, {"name", name}});
}
#line 2385 "parser.tab.c"
    break;

  case 27: /* VarDef: T_IDENTIFIER T_EQUAL InitVal  */
#line 426 "parser.y"
                              {
  // todo
  initStak.pop_back();
  auto init_val = stak.back();
  stak.pop_back();
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "VarDecl"}, {"name", name},{"inner",llvm::json::Array{init_val}}});
}
#line 2400 "parser.tab.c"
    break;

  case 28: /* VarDef: T_IDENTIFIER ConstExpChain  */
#line 435 "parser.y"
                             {
  // todo
  // to compute constexp
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "VarDecl"}, {"name", name}});
}
#line 2413 "parser.tab.c"
    break;

  case 29: /* VarDef: T_IDENTIFIER ConstExpChain T_EQUAL InitVal  */
#line 442 "parser.y"
                                            {
  // todo
  auto init_val = stak.back();
  stak.pop_back();
  initStak.pop_back();
  // to compute constexp
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "VarDecl"}, {"name", name},{"inner",llvm::json::Array{init_val}}})
  ;
}
#line 2430 "parser.tab.c"
    break;

  case 30: /* InitVal: Exp  */
#line 456 "parser.y"
            {
  if(debug) llvm::outs()<<"Exp 2 InitVal\n";
  if(debug) print_stack();
  
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind", "ImplicitCastExpr"},
                                   {"inner", llvm::json::Array{rvalexp}}};
  }

  init_stak_level = 1;
  initStak.push_back(llvm::json::Object{{"value",1}});
}
#line 2450 "parser.tab.c"
    break;

  case 31: /* InitVal: T_L_BRACE T_R_BRACE  */
#line 470 "parser.y"
                       {
  // todo
  if(debug) llvm::outs()<<"empty 2 InitVal\n";
  if(debug) print_stack();
  stak.push_back(llvm::json::Object{{"kind", "InitListExpr"}});
  init_stak_level = 1;
  initStak.push_back(llvm::json::Object{{"value",init_stak_level}});
}
#line 2463 "parser.tab.c"
    break;

  case 32: /* InitVal: T_L_BRACE InitValChain T_R_BRACE  */
#line 477 "parser.y"
                                    {
  // todo
  if(debug) llvm::outs()<<"initvalchain 2 initval\n";
  if(debug) print_stack();
  auto json_inner = llvm::json::Array{};
  int initStakSize = initStak.size();
  // while(initStakSize--){
  //   auto level_number = initStak.back().getAsObject()->get("value")->getAsInteger();
  //   if(level_number.value() == init_stak_level){
  //     json_inner.push_back(stak.back());
  //     stak.pop_back();
  //     initStak.pop_back();
  //   }else{
  //     break;
  //   }
  // }
  while(initStakSize--){
    json_inner.push_back(stak.back());
    stak.pop_back();
    initStak.pop_back();
  }
  stak.push_back(llvm::json::Object{{"kind", "InitListExpr"},
                                   {"inner", llvm::json::Array{}}});
  // llvm::json::Array * array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  // for(int i = json_inner.size()-1; i >= 0; i--){
  //   array_inner->push_back(json_inner[i]);
  // }
  init_stak_level++;
  initStak.push_back(llvm::json::Object{{"value",init_stak_level}});
}
#line 2498 "parser.tab.c"
    break;

  case 33: /* InitValChain: InitVal  */
#line 508 "parser.y"
                      {
  // todo
  if(debug) llvm::outs()<<"initval 2 initvalchain\n";
  if(debug) print_stack();
}
#line 2508 "parser.tab.c"
    break;

  case 34: /* InitValChain: InitValChain T_COMMA InitVal  */
#line 512 "parser.y"
                               {
  // todo
  if(debug) llvm::outs()<<"initvalchain 2 initvalchain\n";
  if(debug) print_stack();
}
#line 2518 "parser.tab.c"
    break;

  case 35: /* FuncDecl: T_INT T_IDENTIFIER T_L_PAREN T_R_PAREN T_SEMI  */
#line 518 "parser.y"
                                                        {
  def_num = 1;
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                   {"name", name}});
}
#line 2531 "parser.tab.c"
    break;

  case 36: /* FuncDecl: T_VOID T_IDENTIFIER T_L_PAREN T_R_PAREN T_SEMI  */
#line 525 "parser.y"
                                                 {
  def_num = 1;
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                   {"name", name}});
}
#line 2544 "parser.tab.c"
    break;

  case 37: /* FuncDecl: T_INT T_IDENTIFIER T_L_PAREN FuncFParams T_R_PAREN T_SEMI  */
#line 532 "parser.y"
                                                             {
  def_num = 1;

  auto json_inner = llvm::json::Array{};
  for(int i = 0; i < func_FPara_num; i++){
    json_inner.push_back(stak.back());
    stak.pop_back();
  }
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();

  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                    {"name",name},
                                    {"inner", llvm::json::Array{}}});
  auto array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  for(int i = func_FPara_num-1; i >= 0; i--){
    array_inner->push_back(json_inner[i]);
  }

}
#line 2570 "parser.tab.c"
    break;

  case 38: /* FuncDecl: T_VOID T_IDENTIFIER T_L_PAREN FuncFParams T_R_PAREN T_SEMI  */
#line 552 "parser.y"
                                                             {
  def_num = 1;
  
  auto json_inner = llvm::json::Array{};
  for(int i = 0; i < func_FPara_num; i++){
    json_inner.push_back(stak.back());
    stak.pop_back();
  }
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();

  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                    {"name",name},
                                    {"inner", llvm::json::Array{}}});
  auto array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  for(int i = func_FPara_num-1; i >= 0; i--){
    array_inner->push_back(json_inner[i]);
  }
}
#line 2595 "parser.tab.c"
    break;

  case 39: /* FuncDef: T_INT T_IDENTIFIER T_L_PAREN T_R_PAREN Block  */
#line 573 "parser.y"
                                                      {
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto inner = stak.back();
  stak.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                   {"name", name},
                                   {"inner", llvm::json::Array{inner}}});
}
#line 2610 "parser.tab.c"
    break;

  case 40: /* FuncDef: T_VOID T_IDENTIFIER T_L_PAREN T_R_PAREN Block  */
#line 582 "parser.y"
                                                {
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto inner = stak.back();
  stak.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                   {"name", name},
                                   {"inner", llvm::json::Array{inner}}});
}
#line 2625 "parser.tab.c"
    break;

  case 41: /* FuncDef: T_INT T_IDENTIFIER T_L_PAREN FuncFParams T_R_PAREN Block  */
#line 591 "parser.y"
                                                            {
  auto inner = stak.back();
  stak.pop_back();

  auto json_inner = llvm::json::Array{};
  for(int i = 0; i < func_FPara_num; i++){
    json_inner.push_back(stak.back());
    stak.pop_back();
  }
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();

  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                    {"name",name},
                                    {"inner", llvm::json::Array{}}});
  auto array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  for(int i = func_FPara_num-1; i >= 0; i--){
    array_inner->push_back(json_inner[i]);
  }
  array_inner->push_back(inner);
}
#line 2652 "parser.tab.c"
    break;

  case 42: /* FuncDef: T_VOID T_IDENTIFIER T_L_PAREN FuncFParams T_R_PAREN Block  */
#line 612 "parser.y"
                                                            {
  auto inner = stak.back();
  stak.pop_back();

  auto json_inner = llvm::json::Array{};
  for(int i = 0; i < func_FPara_num; i++){
    json_inner.push_back(stak.back());
    stak.pop_back();
  }
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();

  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                    {"name",name},
                                    {"inner", llvm::json::Array{}}});
  auto array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  for(int i = func_FPara_num-1; i >= 0; i--){
    array_inner->push_back(json_inner[i]);
  }
  array_inner->push_back(inner);
}
#line 2679 "parser.tab.c"
    break;

  case 43: /* FuncFParams: FuncFParam  */
#line 635 "parser.y"
                         {

  func_FPara_num = 1;

}
#line 2689 "parser.tab.c"
    break;

  case 44: /* FuncFParams: FuncFParams T_COMMA FuncFParam  */
#line 639 "parser.y"
                                 {

  func_FPara_num++;
}
#line 2698 "parser.tab.c"
    break;

  case 45: /* FuncFParam: T_INT T_IDENTIFIER  */
#line 644 "parser.y"
                               {

  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}
#line 2710 "parser.tab.c"
    break;

  case 46: /* $@1: %empty  */
#line 650 "parser.y"
                     {

  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}
#line 2722 "parser.tab.c"
    break;

  case 47: /* FuncFParam: T_CHAR T_IDENTIFIER $@1 T_LONGLONG T_IDENTIFIER  */
#line 656 "parser.y"
                        {

  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}
#line 2734 "parser.tab.c"
    break;

  case 48: /* FuncFParam: T_INT T_IDENTIFIER ArrayFuncFParam  */
#line 662 "parser.y"
                                    {
  // todo

  auto ArrayFuncFParam = stak.back();
  stak.pop_back();
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}
#line 2749 "parser.tab.c"
    break;

  case 49: /* $@2: %empty  */
#line 671 "parser.y"
                                     {
  // todo

  auto ArrayFuncFParam = stak.back();
  stak.pop_back();
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}
#line 2764 "parser.tab.c"
    break;

  case 50: /* FuncFParam: T_CHAR T_IDENTIFIER ArrayFuncFParam $@2 T_LONGLONG T_IDENTIFIER ArrayFuncFParam  */
#line 680 "parser.y"
                                        {

  // todo
  auto ArrayFuncFParam = stak.back();
  stak.pop_back();
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}
#line 2779 "parser.tab.c"
    break;

  case 51: /* ArrayFuncFParam: T_L_SQUARE T_R_SQUARE  */
#line 691 "parser.y"
                                       {
  // todo
  stak.push_back(llvm::json::Object{{"kind","ArrayFuncFParam"}});
}
#line 2788 "parser.tab.c"
    break;

  case 52: /* ArrayFuncFParam: ArrayFuncFParam T_L_SQUARE ConstExp T_R_SQUARE  */
#line 694 "parser.y"
                                                 {
  // todo
  lvalStack.pop();

  auto constExp = stak.back();
  stak.pop_back();
  auto ArrayFuncFParam = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","ArrayFuncFParam"}});
}
#line 2803 "parser.tab.c"
    break;

  case 53: /* Block: T_L_BRACE T_R_BRACE  */
#line 705 "parser.y"
                          {
  stak.push_back(llvm::json::Object{{"kind", "CompoundStmt"}});
}
#line 2811 "parser.tab.c"
    break;

  case 54: /* Block: T_L_BRACE BlockItemChain T_R_BRACE  */
#line 707 "parser.y"
                                     {
  if(debug) llvm::outs()<<"blockitem 2 block\n";
}
#line 2819 "parser.tab.c"
    break;

  case 55: /* BlockItemChain: BlockItem  */
#line 711 "parser.y"
                        {

}
#line 2827 "parser.tab.c"
    break;

  case 56: /* BlockItemChain: BlockItemChain Stmt  */
#line 713 "parser.y"
                     {
  auto stmt = stak.back();
  stak.pop_back();
  auto be_block_item = stak.back();
  stak.back().getAsObject()->get("inner")->getAsArray()->push_back(stmt);
}
#line 2838 "parser.tab.c"
    break;

  case 57: /* BlockItemChain: BlockItemChain Decl  */
#line 718 "parser.y"
                     {
  auto json_inner = llvm::json::Array{};
  for(int i = 0; i < def_num; i++){
    json_inner.push_back(stak.back());
    stak.pop_back();
  }
  stak.push_back(llvm::json::Object{{"kind", "DeclStmt"},
                                   {"inner", llvm::json::Array{}}});
  auto array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  for(int i = def_num-1; i >= 0; i--){
    array_inner->push_back(json_inner[i]);
  }
  auto decl = stak.back();
  stak.pop_back();
  auto be_block_item = stak.back();
  stak.back().getAsObject()->get("inner")->getAsArray()->push_back(decl);
}
#line 2860 "parser.tab.c"
    break;

  case 58: /* BlockItem: Stmt  */
#line 737 "parser.y"
     {
  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind", "CompoundStmt"},
                                   {"inner", llvm::json::Array{inner}}};
}
#line 2870 "parser.tab.c"
    break;

  case 59: /* BlockItem: Decl  */
#line 741 "parser.y"
      {
  auto json_inner = llvm::json::Array{};
  for(int i = 0; i < def_num; i++){
    json_inner.push_back(stak.back());
    stak.pop_back();
  }
  stak.push_back(llvm::json::Object{{"kind", "DeclStmt"},
                                   {"inner", llvm::json::Array{}}});
  auto array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  for(int i = def_num-1; i >= 0; i--){
    array_inner->push_back(json_inner[i]);
  }
  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind", "CompoundStmt"},
                                   {"inner", llvm::json::Array{inner}}};
}
#line 2891 "parser.tab.c"
    break;

  case 60: /* Stmt: MatchedStmt  */
#line 759 "parser.y"
                 {

}
#line 2899 "parser.tab.c"
    break;

  case 61: /* Stmt: OpenStmt  */
#line 761 "parser.y"
          {

}
#line 2907 "parser.tab.c"
    break;

  case 62: /* MatchedStmt: LVal T_EQUAL Exp T_SEMI  */
#line 765 "parser.y"
                                    {
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  lvalStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }
  auto exp = stak.back();
  stak.pop_back();
  auto lval = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","BinaryOperator"},{"opcode","="},{"inner",llvm::json::Array{lval,exp}}});
}
#line 2926 "parser.tab.c"
    break;

  case 63: /* MatchedStmt: T_SEMI  */
#line 778 "parser.y"
        {
  stak.push_back(llvm::json::Object{{"kind","NullStmt"}});
}
#line 2934 "parser.tab.c"
    break;

  case 64: /* MatchedStmt: Exp T_SEMI  */
#line 780 "parser.y"
            {
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }
}
#line 2947 "parser.tab.c"
    break;

  case 65: /* MatchedStmt: Block  */
#line 787 "parser.y"
       {

}
#line 2955 "parser.tab.c"
    break;

  case 66: /* MatchedStmt: T_IF T_L_PAREN Exp T_R_PAREN MatchedStmt T_ELSE MatchedStmt  */
#line 789 "parser.y"
                                                              {
  if(debug) llvm::outs()<<"matched stmt 2 if\n";
  if(debug) print_stack();
  auto elseStmt = stak.back();
  stak.pop_back();
  auto thenStmt = stak.back();
  stak.pop_back();
  
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }

  auto ifExp = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","IfStmt"},{"inner",llvm::json::Array{ifExp,thenStmt,elseStmt}}});
}
#line 2979 "parser.tab.c"
    break;

  case 67: /* MatchedStmt: T_WHILE T_L_PAREN Exp T_R_PAREN Stmt  */
#line 807 "parser.y"
                                       {
  auto loopStmt = stak.back();
  stak.pop_back();

  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }

  auto whileExp = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","WhileStmt"},{"inner",llvm::json::Array{whileExp,loopStmt}}});
}
#line 2999 "parser.tab.c"
    break;

  case 68: /* MatchedStmt: T_BREAK T_SEMI  */
#line 821 "parser.y"
                 {
  stak.push_back(llvm::json::Object{{"kind","BreakStmt"}});
}
#line 3007 "parser.tab.c"
    break;

  case 69: /* MatchedStmt: T_CONTINUE T_SEMI  */
#line 823 "parser.y"
                    {
  stak.push_back(llvm::json::Object{{"kind","ContinueStmt"}});
}
#line 3015 "parser.tab.c"
    break;

  case 70: /* MatchedStmt: T_RETURN T_SEMI  */
#line 825 "parser.y"
                 {
  stak.push_back(llvm::json::Object{{"kind", "ReturnStmt"}});
}
#line 3023 "parser.tab.c"
    break;

  case 71: /* MatchedStmt: T_RETURN Exp T_SEMI  */
#line 827 "parser.y"
                      {
  if(debug) llvm::outs()<<"return 2 stmt\n";
  if(debug) print_stack();

  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }

  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind", "ReturnStmt"},
                                   {"inner", llvm::json::Array{inner}}};
}
#line 3043 "parser.tab.c"
    break;

  case 72: /* MatchedStmt: T_DO Block T_WHILE T_L_PAREN Exp T_R_PAREN T_SEMI  */
#line 841 "parser.y"
                                                    {

  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }

  auto whileExp = stak.back();
  stak.pop_back();
  auto blockStmt = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","DoStmt"},{"inner",llvm::json::Array{blockStmt,whileExp}}});
}
#line 3063 "parser.tab.c"
    break;

  case 73: /* OpenStmt: T_IF T_L_PAREN Exp T_R_PAREN Stmt  */
#line 857 "parser.y"
                                            {
  if(debug) llvm::outs()<<"open stmt no else 2 if\n";
  if(debug) print_stack();
  auto thenStmt = stak.back();
  stak.pop_back();

  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }

  auto ifExp = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","IfStmt"},{"inner",llvm::json::Array{ifExp,thenStmt}}});
}
#line 3085 "parser.tab.c"
    break;

  case 74: /* OpenStmt: T_IF T_L_PAREN Exp T_R_PAREN MatchedStmt T_ELSE OpenStmt  */
#line 873 "parser.y"
                                                           {
  if(debug) llvm::outs()<<"open stmt no else 2 if\n";
  if(debug) print_stack();
  auto elseStmt = stak.back();
  stak.pop_back();
  auto thenStmt = stak.back();
  stak.pop_back();

  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }

  auto ifExp = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","IfStmt"},{"inner",llvm::json::Array{ifExp,thenStmt,elseStmt}}});
}
#line 3109 "parser.tab.c"
    break;

  case 75: /* Exp: LOrExp  */
#line 897 "parser.y"
            {
  if(debug) llvm::outs()<<"LOrExp 2 Exp\n";
}
#line 3117 "parser.tab.c"
    break;

  case 76: /* LVal: T_IDENTIFIER  */
#line 901 "parser.y"
                   {
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","DeclRefExpr"},{"name",name}});
  
  lvalStack.push(true);
}
#line 3130 "parser.tab.c"
    break;

  case 77: /* LVal: LVal T_L_SQUARE Exp T_R_SQUARE  */
#line 908 "parser.y"
                                {
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  if(lval2rval){
    auto exp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{exp}}};
  }
  lvalStack.pop();

  auto exp = stak.back();
  stak.pop_back();
  auto be_lval = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{be_lval}}});
  auto ImplicitCastExpr = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","ArraySubscriptExpr"},{"inner",llvm::json::Array{ImplicitCastExpr,exp}}});
  
  lvalStack.push(true);
}
#line 3155 "parser.tab.c"
    break;

  case 78: /* PrimaryExp: T_L_PAREN Exp T_R_PAREN  */
#line 929 "parser.y"
                                    {
  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind","ParenExpr"},
  {"inner", llvm::json::Array{inner}}};
}
#line 3165 "parser.tab.c"
    break;

  case 79: /* PrimaryExp: LVal  */
#line 933 "parser.y"
      {
  // todo
}
#line 3173 "parser.tab.c"
    break;

  case 80: /* PrimaryExp: Number  */
#line 935 "parser.y"
        {
  if(debug) llvm::outs()<<"number 2 primary\n";
}
#line 3181 "parser.tab.c"
    break;

  case 81: /* UnaryExp: PrimaryExp  */
#line 939 "parser.y"
                     {
  if(debug) llvm::outs()<<"primary 2 unaryexp\n";
  if(debug) print_stack();
}
#line 3190 "parser.tab.c"
    break;

  case 82: /* UnaryExp: T_IDENTIFIER T_L_PAREN T_R_PAREN  */
#line 942 "parser.y"
                                   {
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();

  stak.push_back(llvm::json::Object{{"kind","DeclRefExpr"}});
  auto DeclRefExpr =  stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{DeclRefExpr}}});
  auto ImplicitCastExpr = stak.back();

  stak.back() = llvm::json::Object{{"kind", "CallExpr"},
                                    {"name",name},
                                    {"inner", llvm::json::Array{ImplicitCastExpr}}};
  
  lvalStack.push(false);
}
#line 3212 "parser.tab.c"
    break;

  case 83: /* UnaryExp: T_IDENTIFIER T_L_PAREN FuncRParams T_R_PAREN  */
#line 958 "parser.y"
                                               {

  llvm::json::Value funcRParams(stak.back());
  stak.pop_back();

  // auto json_inner = llvm::json::Array{};
  // for(int i = 0; i < func_RPara_num; i++){
  //   bool lval2rval = lvalStack.top();
  //   if(lval2rval){
  //     auto rvalexp = stak.back();
  //     json_inner.push_back(llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}});
  //   }else{
  //     auto rvalexp = stak.back();
  //     json_inner.push_back(rvalexp);
  //   }
  //   stak.pop_back();
  //   lvalStack.pop();
  // }
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();

  stak.push_back(llvm::json::Object{{"kind","DeclRefExpr"}});
  auto DeclRefExpr =  stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{DeclRefExpr}}});
  auto ImplicitCastExpr = stak.back();
  stak.back() = funcRParams;
  auto array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  array_inner->insert(array_inner->begin(),ImplicitCastExpr);
  lvalStack.push(false);


  // stak.back() = llvm::json::Object{{"kind", "CallExpr"},
  //                                   {"name",name},
  //                                   {"inner", llvm::json::Array{ImplicitCastExpr}}};
  // auto array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  // for(int i = func_RPara_num-1; i >= 0; i--){
  //   array_inner->push_back(json_inner[i]);
  // }
}
#line 3258 "parser.tab.c"
    break;

  case 84: /* UnaryExp: T_PLUS UnaryExp  */
#line 998 "parser.y"
                 {
  if(debug) llvm::outs()<<"UnaryExp 2 UnaryExp\n";
  bool lval2rval = lvalStack.top();
  lvalStack.pop();

  auto inner = stak.back();
  if(lval2rval){
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{inner}}};
    inner = stak.back();
    stak.back() = llvm::json::Object{{"kind", "UnaryOperator"},
    {"opcode","+"},
    {"inner",llvm::json::Array{inner}}};
  }else{
    stak.back() = llvm::json::Object{{"kind", "UnaryOperator"},
    {"opcode","+"},
    {"inner",llvm::json::Array{inner}}};
  }
  lvalStack.push(false);
}
#line 3282 "parser.tab.c"
    break;

  case 85: /* UnaryExp: T_MINUS UnaryExp  */
#line 1016 "parser.y"
                  {
  if(debug) llvm::outs()<<"UnaryExp 2 UnaryExp\n";
  bool lval2rval = lvalStack.top();
  lvalStack.pop();

  auto inner = stak.back();
  if(lval2rval){
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{inner}}};
    inner = stak.back();
    stak.back() = llvm::json::Object{{"kind", "UnaryOperator"},
    {"opcode","-"},
    {"inner",llvm::json::Array{inner}}};
  }else{
    stak.back() = llvm::json::Object{{"kind", "UnaryOperator"},
    {"opcode","-"},
    {"inner",llvm::json::Array{inner}}};
  }
  lvalStack.push(false);
}
#line 3306 "parser.tab.c"
    break;

  case 86: /* UnaryExp: T_EXCLAIM UnaryExp  */
#line 1034 "parser.y"
                    {
  if(debug) llvm::outs()<<"UnaryExp 2 UnaryExp\n";
  bool lval2rval = lvalStack.top();
  lvalStack.pop();

  auto inner = stak.back();
  if(lval2rval){
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{inner}}};
    inner = stak.back();
    stak.back() = llvm::json::Object{{"kind", "UnaryOperator"},
    {"opcode","!"},
    {"inner",llvm::json::Array{inner}}};
  }else{
    stak.back() = llvm::json::Object{{"kind", "UnaryOperator"},
    {"opcode","!"},
    {"inner",llvm::json::Array{inner}}};
  }
  lvalStack.push(false);
}
#line 3330 "parser.tab.c"
    break;

  case 87: /* Number: T_NUMERIC_CONSTANT  */
#line 1054 "parser.y"
                           {
  auto number = lexStack.back();
  lexStack.pop_back();
  stak.push_back(number);
  if(debug) llvm::outs()<<"T_NUMERIC_CONSTANT 2 number\n";

  lvalStack.push(false);
}
#line 3343 "parser.tab.c"
    break;

  case 88: /* FuncRParams: Exp  */
#line 1064 "parser.y"
                 {
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }
  auto exp = stak.back();
  stak.back() = llvm::json::Object{{"kind","CallExpr"},{"inner",llvm::json::Array{exp}}};

  // func_RPara_num = 1;
}
#line 3360 "parser.tab.c"
    break;

  case 89: /* FuncRParams: FuncRParams T_COMMA Exp  */
#line 1075 "parser.y"
                          {
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }
  auto exp = stak.back();
  stak.pop_back();
  llvm::json::Array * array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  array_inner->push_back(exp);

  // func_RPara_num ++;
}
#line 3379 "parser.tab.c"
    break;

  case 90: /* MulExp: UnaryExp  */
#line 1093 "parser.y"
        {
  if(debug) llvm::outs()<<"UnaryExp 2 MulExp\n";
  print_stack();
}
#line 3388 "parser.tab.c"
    break;

  case 91: /* MulExp: MulExp T_STAR UnaryExp  */
#line 1096 "parser.y"
                        {
  if(debug) llvm::outs()<<"MulExp 2 MulExp\n";
  if(debug) print_stack();
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  if(lval2rval2){
    auto exp2 = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{exp2}}};
  }
  auto unary_exp = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto exp1 = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{exp1}}};
  }
  auto mul_exp = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","*"},{"inner",llvm::json::Array{mul_exp,unary_exp}}};
  lvalStack.push(false);
}
#line 3415 "parser.tab.c"
    break;

  case 92: /* MulExp: MulExp T_SLASH UnaryExp  */
#line 1117 "parser.y"
                         {
  if(debug) llvm::outs()<<"MulExp 2 MulExp\n";
  if(debug) print_stack();
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  if(lval2rval2){
    auto exp2 = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{exp2}}};
  }
  auto unary_exp = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto exp1 = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{exp1}}};
  }
  auto mul_exp = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","/"},{"inner",llvm::json::Array{mul_exp,unary_exp}}};
  lvalStack.push(false);
}
#line 3442 "parser.tab.c"
    break;

  case 93: /* MulExp: MulExp T_PERCENT UnaryExp  */
#line 1138 "parser.y"
                           {
  if(debug) llvm::outs()<<"MulExp 2 MulExp\n";
  if(debug) print_stack();
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  if(lval2rval2){
    auto exp2 = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{exp2}}};
  }
  auto unary_exp = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto exp1 = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{exp1}}};
  }
  auto mul_exp = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","%"},{"inner",llvm::json::Array{mul_exp,unary_exp}}};
  lvalStack.push(false);
}
#line 3469 "parser.tab.c"
    break;

  case 94: /* AddExp: MulExp  */
#line 1163 "parser.y"
      {
  if(debug) llvm::outs()<<"MulExp 2 AddExp\n";
}
#line 3477 "parser.tab.c"
    break;

  case 95: /* AddExp: AddExp T_PLUS MulExp  */
#line 1165 "parser.y"
                       {
  if(debug) llvm::outs()<<"exp1 2 AddExp\n";

  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();
  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","+"},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
}
#line 3503 "parser.tab.c"
    break;

  case 96: /* AddExp: AddExp T_MINUS MulExp  */
#line 1185 "parser.y"
                        {
  if(debug) llvm::outs()<<"exp2 2 AddExp\n";

  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();
  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","-"},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
}
#line 3529 "parser.tab.c"
    break;

  case 97: /* RelExp: AddExp  */
#line 1208 "parser.y"
      {
  if(debug) llvm::outs()<<"AddExp 2 RelExp\n";
}
#line 3537 "parser.tab.c"
    break;

  case 98: /* RelExp: RelExp T_LESS AddExp  */
#line 1210 "parser.y"
                       {
  if(debug) llvm::outs()<<"exp1 2 RelExp\n";
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();
  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","<"},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
}
#line 3562 "parser.tab.c"
    break;

  case 99: /* RelExp: RelExp T_GREATER AddExp  */
#line 1229 "parser.y"
                          {
  if(debug) llvm::outs()<<"exp2 2 RelExp\n";

  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();
  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode",">"},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);

}
#line 3589 "parser.tab.c"
    break;

  case 100: /* RelExp: RelExp T_LESSEQUAL AddExp  */
#line 1250 "parser.y"
                            {
  if(debug) llvm::outs()<<"exp3 2 RelExp\n";

  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();
  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","<="},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
}
#line 3615 "parser.tab.c"
    break;

  case 101: /* RelExp: RelExp T_GREATEREQUAL AddExp  */
#line 1270 "parser.y"
                               {
  if(debug) llvm::outs()<<"exp4 2 RelExp\n";

  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();
  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode",">="},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
}
#line 3641 "parser.tab.c"
    break;

  case 102: /* EqExp: RelExp  */
#line 1293 "parser.y"
      {

}
#line 3649 "parser.tab.c"
    break;

  case 103: /* EqExp: EqExp T_EQUALEQUAL RelExp  */
#line 1295 "parser.y"
                           {
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();
  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","=="},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
}
#line 3673 "parser.tab.c"
    break;

  case 104: /* EqExp: EqExp T_EXCLAIMEQUAL RelExp  */
#line 1313 "parser.y"
                             {
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();
  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","!="},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
}
#line 3697 "parser.tab.c"
    break;

  case 105: /* LAndExp: EqExp  */
#line 1334 "parser.y"
     {

}
#line 3705 "parser.tab.c"
    break;

  case 106: /* LAndExp: LAndExp T_AMPAMP EqExp  */
#line 1336 "parser.y"
                        {
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();
  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","&&"},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
}
#line 3729 "parser.tab.c"
    break;

  case 107: /* LOrExp: LAndExp  */
#line 1356 "parser.y"
               {

}
#line 3737 "parser.tab.c"
    break;

  case 108: /* LOrExp: LOrExp T_PIPEPIPE LAndExp  */
#line 1358 "parser.y"
                           {
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();
  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","||"},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
}
#line 3761 "parser.tab.c"
    break;

  case 109: /* ConstExp: Exp  */
#line 1378 "parser.y"
             {
  if(debug) llvm::outs()<<"ConstExp 2 Exp\n";
}
#line 3769 "parser.tab.c"
    break;


#line 3773 "parser.tab.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1383 "parser.y"
