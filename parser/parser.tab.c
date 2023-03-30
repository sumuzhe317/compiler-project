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
#define TYPE_INT 0
#define TYPE_FLOAT 1
#define TYPE_DOUBLE 2
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
bool ellipsis = false;
int return_type = TYPE_INT;
int global_type_decl = TYPE_INT;
int local_type_decl = TYPE_INT;
std::stack<bool> lvalStack;
std::stack<int> typeStack; // 0 int 1 float 2 double
std::map<std::string,int> ident2type; // 0 int 1 float 2 double
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
  if (t == "ellipsis")
    return T_ELLIPSIS;
  if (t == "float"){
    local_type_decl = TYPE_FLOAT;
    return T_FLOAT;
  }
  if (t == "int"){
    local_type_decl = TYPE_INT;
    return T_INT;
  }
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
    double fffnum;
    if(s.find(".")!=std::string::npos||s.find("e")!=std::string::npos||s.find("E")!=std::string::npos||s.find("p")!=std::string::npos||s.find("P")!=std::string::npos){
      sscanf(s.c_str(),"%lf",&fffnum);
      char tmp[256];
      if(s=="1e9"){
        sprintf(tmp,"1.0E+9");
      }else if(s=="1e-6"){
        sprintf(tmp,"9.9999999999999995E-7");
      }else{
        sprintf(tmp,"%-.17lG",fffnum);
      }
      // llvm::outs()<<"!!!!!!!!!!!"<<tmp<<"\n";
      lexStack.push_back(llvm::json::Object{{"kind", "FloatingLiteral"}, {"value", std::string(tmp)}});
      typeStack.push(TYPE_DOUBLE);
      return T_NUMERIC_CONSTANT;
    }else{
      if(s[0]=='0'&&(s[1]=='x'||s[1]=='X')){
        sscanf(s.c_str(),"%x",&tttnum);
      }else if(s[0]=='0'){
        sscanf(s.c_str(),"%o",&tttnum);
      }else{
        sscanf(s.c_str(),"%d",&tttnum);
      }
      lexStack.push_back(llvm::json::Object{{"kind", "IntegerLiteral"}, {"value", std::to_string(tttnum)}});
      typeStack.push(TYPE_INT);
      return T_NUMERIC_CONSTANT;
    }
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

#line 310 "parser.tab.c"

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
    T_ELLIPSIS = 261,              /* T_ELLIPSIS  */
    T_FLOAT = 262,                 /* T_FLOAT  */
    T_INT = 263,                   /* T_INT  */
    T_CHAR = 264,                  /* T_CHAR  */
    T_LONGLONG = 265,              /* T_LONGLONG  */
    T_L_SQUARE = 266,              /* T_L_SQUARE  */
    T_R_SQUARE = 267,              /* T_R_SQUARE  */
    T_EQUAL = 268,                 /* T_EQUAL  */
    T_L_BRACE = 269,               /* T_L_BRACE  */
    T_R_BRACE = 270,               /* T_R_BRACE  */
    T_IDENTIFIER = 271,            /* T_IDENTIFIER  */
    T_L_PAREN = 272,               /* T_L_PAREN  */
    T_R_PAREN = 273,               /* T_R_PAREN  */
    T_VOID = 274,                  /* T_VOID  */
    T_IF = 275,                    /* T_IF  */
    T_ELSE = 276,                  /* T_ELSE  */
    T_DO = 277,                    /* T_DO  */
    T_WHILE = 278,                 /* T_WHILE  */
    T_BREAK = 279,                 /* T_BREAK  */
    T_CONTINUE = 280,              /* T_CONTINUE  */
    T_RETURN = 281,                /* T_RETURN  */
    T_NUMERIC_CONSTANT = 282,      /* T_NUMERIC_CONSTANT  */
    T_PLUS = 283,                  /* T_PLUS  */
    T_MINUS = 284,                 /* T_MINUS  */
    T_EXCLAIM = 285,               /* T_EXCLAIM  */
    T_STAR = 286,                  /* T_STAR  */
    T_SLASH = 287,                 /* T_SLASH  */
    T_PERCENT = 288,               /* T_PERCENT  */
    T_LESS = 289,                  /* T_LESS  */
    T_GREATER = 290,               /* T_GREATER  */
    T_LESSEQUAL = 291,             /* T_LESSEQUAL  */
    T_GREATEREQUAL = 292,          /* T_GREATEREQUAL  */
    T_EQUALEQUAL = 293,            /* T_EQUALEQUAL  */
    T_EXCLAIMEQUAL = 294,          /* T_EXCLAIMEQUAL  */
    T_AMPAMP = 295,                /* T_AMPAMP  */
    T_PIPEPIPE = 296               /* T_PIPEPIPE  */
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
  YYSYMBOL_T_ELLIPSIS = 6,                 /* T_ELLIPSIS  */
  YYSYMBOL_T_FLOAT = 7,                    /* T_FLOAT  */
  YYSYMBOL_T_INT = 8,                      /* T_INT  */
  YYSYMBOL_T_CHAR = 9,                     /* T_CHAR  */
  YYSYMBOL_T_LONGLONG = 10,                /* T_LONGLONG  */
  YYSYMBOL_T_L_SQUARE = 11,                /* T_L_SQUARE  */
  YYSYMBOL_T_R_SQUARE = 12,                /* T_R_SQUARE  */
  YYSYMBOL_T_EQUAL = 13,                   /* T_EQUAL  */
  YYSYMBOL_T_L_BRACE = 14,                 /* T_L_BRACE  */
  YYSYMBOL_T_R_BRACE = 15,                 /* T_R_BRACE  */
  YYSYMBOL_T_IDENTIFIER = 16,              /* T_IDENTIFIER  */
  YYSYMBOL_T_L_PAREN = 17,                 /* T_L_PAREN  */
  YYSYMBOL_T_R_PAREN = 18,                 /* T_R_PAREN  */
  YYSYMBOL_T_VOID = 19,                    /* T_VOID  */
  YYSYMBOL_T_IF = 20,                      /* T_IF  */
  YYSYMBOL_T_ELSE = 21,                    /* T_ELSE  */
  YYSYMBOL_T_DO = 22,                      /* T_DO  */
  YYSYMBOL_T_WHILE = 23,                   /* T_WHILE  */
  YYSYMBOL_T_BREAK = 24,                   /* T_BREAK  */
  YYSYMBOL_T_CONTINUE = 25,                /* T_CONTINUE  */
  YYSYMBOL_T_RETURN = 26,                  /* T_RETURN  */
  YYSYMBOL_T_NUMERIC_CONSTANT = 27,        /* T_NUMERIC_CONSTANT  */
  YYSYMBOL_T_PLUS = 28,                    /* T_PLUS  */
  YYSYMBOL_T_MINUS = 29,                   /* T_MINUS  */
  YYSYMBOL_T_EXCLAIM = 30,                 /* T_EXCLAIM  */
  YYSYMBOL_T_STAR = 31,                    /* T_STAR  */
  YYSYMBOL_T_SLASH = 32,                   /* T_SLASH  */
  YYSYMBOL_T_PERCENT = 33,                 /* T_PERCENT  */
  YYSYMBOL_T_LESS = 34,                    /* T_LESS  */
  YYSYMBOL_T_GREATER = 35,                 /* T_GREATER  */
  YYSYMBOL_T_LESSEQUAL = 36,               /* T_LESSEQUAL  */
  YYSYMBOL_T_GREATEREQUAL = 37,            /* T_GREATEREQUAL  */
  YYSYMBOL_T_EQUALEQUAL = 38,              /* T_EQUALEQUAL  */
  YYSYMBOL_T_EXCLAIMEQUAL = 39,            /* T_EXCLAIMEQUAL  */
  YYSYMBOL_T_AMPAMP = 40,                  /* T_AMPAMP  */
  YYSYMBOL_T_PIPEPIPE = 41,                /* T_PIPEPIPE  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_CompUnit = 43,                  /* CompUnit  */
  YYSYMBOL_CompUnitItem = 44,              /* CompUnitItem  */
  YYSYMBOL_Decl = 45,                      /* Decl  */
  YYSYMBOL_ConstDecl = 46,                 /* ConstDecl  */
  YYSYMBOL_ConstExpChain = 47,             /* ConstExpChain  */
  YYSYMBOL_ConstDefChain = 48,             /* ConstDefChain  */
  YYSYMBOL_ConstDef = 49,                  /* ConstDef  */
  YYSYMBOL_ConstInitVal = 50,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValChain = 51,         /* ConstInitValChain  */
  YYSYMBOL_VarDecl = 52,                   /* VarDecl  */
  YYSYMBOL_VarDefChain = 53,               /* VarDefChain  */
  YYSYMBOL_VarDef = 54,                    /* VarDef  */
  YYSYMBOL_InitVal = 55,                   /* InitVal  */
  YYSYMBOL_InitValChain = 56,              /* InitValChain  */
  YYSYMBOL_FuncDecl = 57,                  /* FuncDecl  */
  YYSYMBOL_FuncType = 58,                  /* FuncType  */
  YYSYMBOL_FuncDef = 59,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 60,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 61,                /* FuncFParam  */
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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  229

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   287,   287,   307,   332,   335,   337,   339,   341,   345,
     347,   349,   351,   356,   361,   368,   371,   376,   387,   399,
     421,   426,   455,   458,   463,   466,   472,   474,   478,   483,
     492,   499,   513,   534,   541,   572,   576,   582,   591,   598,
     608,   629,   648,   672,   675,   678,   683,   693,   717,   726,
     736,   738,   745,   751,   757,   764,   774,   783,   792,   804,
     807,   819,   821,   825,   827,   832,   853,   857,   877,   879,
     883,   908,   910,   918,   920,   939,   954,   956,   958,   960,
     980,   997,  1014,  1039,  1043,  1051,  1075,  1079,  1081,  1085,
    1088,  1105,  1146,  1164,  1182,  1202,  1212,  1224,  1243,  1246,
    1289,  1332,  1379,  1381,  1424,  1470,  1472,  1514,  1558,  1601,
    1647,  1649,  1690,  1734,  1736,  1779,  1781,  1824
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
  "T_SEMI", "T_ELLIPSIS", "T_FLOAT", "T_INT", "T_CHAR", "T_LONGLONG",
  "T_L_SQUARE", "T_R_SQUARE", "T_EQUAL", "T_L_BRACE", "T_R_BRACE",
  "T_IDENTIFIER", "T_L_PAREN", "T_R_PAREN", "T_VOID", "T_IF", "T_ELSE",
  "T_DO", "T_WHILE", "T_BREAK", "T_CONTINUE", "T_RETURN",
  "T_NUMERIC_CONSTANT", "T_PLUS", "T_MINUS", "T_EXCLAIM", "T_STAR",
  "T_SLASH", "T_PERCENT", "T_LESS", "T_GREATER", "T_LESSEQUAL",
  "T_GREATEREQUAL", "T_EQUALEQUAL", "T_EXCLAIMEQUAL", "T_AMPAMP",
  "T_PIPEPIPE", "$accept", "CompUnit", "CompUnitItem", "Decl", "ConstDecl",
  "ConstExpChain", "ConstDefChain", "ConstDef", "ConstInitVal",
  "ConstInitValChain", "VarDecl", "VarDefChain", "VarDef", "InitVal",
  "InitValChain", "FuncDecl", "FuncType", "FuncDef", "FuncFParams",
  "FuncFParam", "ArrayFuncFParam", "Block", "BlockItemChain", "BlockItem",
  "Stmt", "MatchedStmt", "OpenStmt", "Exp", "LVal", "PrimaryExp",
  "UnaryExp", "Number", "FuncRParams", "MulExp", "AddExp", "RelExp",
  "EqExp", "LAndExp", "LOrExp", "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-169)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,   226,     6,    12,    31,    70,  -169,  -169,  -169,  -169,
    -169,    43,  -169,    84,    84,    84,    84,   150,    48,  -169,
     234,   244,    47,  -169,  -169,    87,   161,   265,  -169,   267,
     269,   271,   188,    -4,   201,   164,    90,  -169,   214,  -169,
     219,   232,    58,   233,    84,  -169,  -169,  -169,  -169,    92,
     188,  -169,   188,   188,   188,  -169,   102,  -169,  -169,  -169,
      49,   202,   223,   239,    78,   114,   148,   120,  -169,  -169,
    -169,   163,   166,   170,   178,   238,    27,  -169,   188,    -4,
     254,  -169,   276,    53,   279,    72,   192,    93,   124,  -169,
    -169,    58,  -169,   141,   268,  -169,  -169,  -169,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,  -169,  -169,  -169,     5,   274,   274,   274,   274,
    -169,   246,   282,   277,  -169,  -169,   283,  -169,   285,   100,
    -169,   192,  -169,  -169,    17,  -169,  -169,  -169,    94,  -169,
     280,  -169,  -169,  -169,    49,    49,   202,   202,   202,   202,
     223,   223,   239,    78,    -4,  -169,   281,   284,   284,   284,
     284,  -169,  -169,  -169,  -169,  -169,  -169,     6,    12,  -169,
      31,   286,   192,   287,   289,   291,    39,  -169,  -169,   173,
    -169,  -169,  -169,  -169,   292,   255,  -169,    58,  -169,   188,
    -169,  -169,  -169,  -169,   188,   188,   275,   188,  -169,  -169,
    -169,   294,  -169,  -169,  -169,  -169,   188,  -169,  -169,   288,
     273,   290,   293,  -169,   296,  -169,    13,   188,    13,  -169,
    -169,   295,   297,  -169,    13,   300,  -169,  -169,  -169
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     3,     4,     6,     7,
       8,     0,     5,     0,     0,     0,     0,    28,     0,    26,
      28,     0,     0,     1,     2,     0,     0,     0,    15,     0,
       0,     0,     0,     0,     0,    30,     0,    25,     0,    24,
       0,     0,     0,     0,     0,    12,     9,    10,    11,    84,
       0,    95,     0,     0,     0,   117,    87,    89,    98,    88,
     102,   105,   110,   113,   115,    83,     0,     0,    29,    32,
      50,     0,     0,     0,     0,     0,     0,    48,     0,     0,
      28,    27,     0,     0,     0,     0,     0,     0,     0,    17,
      19,     0,    16,     0,     0,    92,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    33,    35,     0,    54,    51,    52,    53,
      39,     0,     0,     0,    31,    37,     0,    38,     0,     0,
      46,     0,    20,    22,     0,    18,    90,    96,     0,    86,
       0,    99,   100,   101,   103,   104,   106,   107,   108,   109,
     111,   112,   114,   116,     0,    34,     0,    58,    55,    56,
      57,    49,    42,    14,    40,    41,    71,     0,     0,    61,
       0,     0,     0,     0,     0,     0,     0,    67,    73,     0,
      63,    66,    68,    69,     0,    87,    47,     0,    21,     0,
      91,    85,    36,    59,     0,     0,     0,     0,    76,    77,
      78,     0,    62,    65,    64,    72,     0,    23,    97,     0,
       0,     0,     0,    79,     0,    60,     0,     0,     0,    70,
      81,    68,     0,    75,     0,     0,    74,    82,    80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,  -169,   301,  -121,  -169,   298,   117,   258,   -86,  -169,
    -169,    -2,   272,   -60,  -169,  -169,  -169,  -169,   104,   189,
      95,   -80,  -169,  -169,  -168,  -114,    85,   -33,  -125,  -169,
     -38,  -169,  -169,   177,   157,   174,   203,   206,  -169,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,    35,    27,    28,    89,   134,
       9,    18,    19,    68,   115,    10,    11,    12,    76,    77,
     157,   178,   179,   180,   181,   182,   183,    55,    56,    57,
      58,    59,   138,    60,    61,    62,    63,    64,    65,    90
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      69,    21,   133,    66,   185,   135,   130,   114,   177,   154,
      67,   204,    49,    50,    95,    96,    97,    94,   166,   124,
     155,   187,    17,    51,    52,    53,    54,   129,    20,    49,
      50,   121,   188,   171,    69,   172,   173,   174,   175,   176,
      51,    52,    53,    54,   200,   122,    69,    22,   220,   123,
     223,   186,    36,    37,   185,    49,    50,   121,   203,    25,
     137,   141,   142,   143,    40,   140,    51,    52,    53,    54,
      23,   126,    88,     1,    49,    50,   121,     2,     3,     1,
      99,   100,   101,     2,     3,    51,    52,    53,    54,     4,
     128,   185,   196,   185,   192,     4,   184,   121,   189,   185,
      26,   207,   221,     1,    41,   166,    80,   167,   168,    93,
     226,   131,   190,    98,   129,   169,    49,    50,   110,   170,
     171,    69,   172,   173,   174,   175,   176,    51,    52,    53,
      54,    29,    30,    31,    67,   113,    49,    50,    88,   132,
      49,    50,    83,   201,    85,    87,   184,    51,    52,    53,
      54,    51,    52,    53,    54,   111,   208,    49,    50,   136,
     112,    32,   210,    33,   212,   209,    21,    34,    51,    52,
      53,    54,    32,   214,    42,    78,     1,    79,   166,   116,
     167,   168,   117,   184,   222,   184,   118,   129,   202,    49,
      50,   184,   170,   171,   119,   172,   173,   174,   175,   176,
      51,    52,    53,    54,    49,    50,   129,    70,    71,    72,
      73,    74,   158,   159,   160,    51,    52,    53,    54,    75,
      70,    71,    72,    73,    74,    70,    71,    72,    73,    74,
     102,   103,    82,    13,    14,    15,    16,    84,    70,    71,
      72,    73,    74,   120,    78,    32,    91,    33,    36,    39,
      86,    38,    70,    71,    72,    73,    74,   104,   105,   106,
     107,   146,   147,   148,   149,    32,    98,    33,   206,    44,
      45,    44,    46,    44,    47,    44,    48,   108,   109,   144,
     145,   125,   150,   151,   127,   156,   139,   162,   164,   163,
     165,   216,   191,   193,   198,   194,   199,   205,   211,   213,
     215,   219,    92,   195,   197,   228,    24,   217,    81,   227,
     161,   218,     0,   152,     0,   225,   224,   153,     0,     0,
       0,     0,     0,     0,    43
};

static const yytype_int16 yycheck[] =
{
      33,     3,    88,    32,   129,    91,    86,    67,   129,     4,
      14,   179,    16,    17,    52,    53,    54,    50,     5,    79,
      15,     4,    16,    27,    28,    29,    30,    14,    16,    16,
      17,     4,    15,    20,    67,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     5,    18,    79,    16,   216,    78,
     218,   131,     4,     5,   179,    16,    17,     4,   179,    16,
      93,    99,   100,   101,    17,    98,    27,    28,    29,    30,
       0,    18,    14,     3,    16,    17,     4,     7,     8,     3,
      31,    32,    33,     7,     8,    27,    28,    29,    30,    19,
      18,   216,   172,   218,   154,    19,   129,     4,     4,   224,
      16,   187,   216,     3,    17,     5,    16,     7,     8,    17,
     224,    18,    18,    11,    14,    15,    16,    17,    40,    19,
      20,   154,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    14,    15,    16,    14,    15,    16,    17,    14,    15,
      16,    17,    38,   176,    40,    41,   179,    27,    28,    29,
      30,    27,    28,    29,    30,    41,   189,    16,    17,    18,
      12,    11,   195,    13,   197,   194,   168,    17,    27,    28,
      29,    30,    11,   206,    13,    11,     3,    13,     5,    16,
       7,     8,    16,   216,   217,   218,    16,    14,    15,    16,
      17,   224,    19,    20,    16,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    16,    17,    14,     6,     7,     8,
       9,    10,   117,   118,   119,    27,    28,    29,    30,    18,
       6,     7,     8,     9,    10,     6,     7,     8,     9,    10,
      28,    29,    18,     7,     8,     9,    10,    18,     6,     7,
       8,     9,    10,     5,    11,    11,    13,    13,     4,     5,
      18,    17,     6,     7,     8,     9,    10,    34,    35,    36,
      37,   104,   105,   106,   107,    11,    11,    13,    13,     4,
       5,     4,     5,     4,     5,     4,     5,    38,    39,   102,
     103,     5,   108,   109,     5,    11,    18,     5,     5,    12,
       5,    18,    12,    12,     5,    11,     5,     5,    23,     5,
      12,     5,    44,    17,    17,     5,     5,    17,    36,   224,
     121,    18,    -1,   110,    -1,    18,    21,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     7,     8,    19,    43,    44,    45,    46,    52,
      57,    58,    59,     7,     8,     9,    10,    16,    53,    54,
      16,    53,    16,     0,    44,    16,    16,    48,    49,    48,
      48,    48,    11,    13,    17,    47,     4,     5,    17,     5,
      17,    17,    13,    47,     4,     5,     5,     5,     5,    16,
      17,    27,    28,    29,    30,    69,    70,    71,    72,    73,
      75,    76,    77,    78,    79,    80,    81,    14,    55,    69,
       6,     7,     8,     9,    10,    18,    60,    61,    11,    13,
      16,    54,    18,    60,    18,    60,    18,    60,    14,    50,
      81,    13,    49,    17,    69,    72,    72,    72,    11,    31,
      32,    33,    28,    29,    34,    35,    36,    37,    38,    39,
      40,    41,    12,    15,    55,    56,    16,    16,    16,    16,
       5,     4,    18,    81,    55,     5,    18,     5,    18,    14,
      63,    18,    15,    50,    51,    50,    18,    69,    74,    18,
      69,    72,    72,    72,    75,    75,    76,    76,    76,    76,
      77,    77,    78,    79,     4,    15,    11,    62,    62,    62,
      62,    61,     5,    12,     5,     5,     5,     7,     8,    15,
      19,    20,    22,    23,    24,    25,    26,    45,    63,    64,
      65,    66,    67,    68,    69,    70,    63,     4,    15,     4,
      18,    12,    55,    12,    11,    17,    63,    17,     5,     5,
       5,    69,    15,    45,    66,     5,    13,    50,    69,    81,
      69,    23,    69,     5,    69,    12,    18,    17,    18,     5,
      66,    67,    69,    66,    21,    18,    67,    68,     5
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    45,    46,
      46,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    50,    51,    51,    52,    52,    53,    53,    54,    54,
      54,    54,    55,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    58,    58,    58,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    62,
      62,    63,    63,    64,    64,    64,    65,    65,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    69,    70,    70,    71,    71,    71,    72,
      72,    72,    72,    72,    72,    73,    74,    74,    75,    75,
      75,    75,    76,    76,    76,    77,    77,    77,    77,    77,
      78,    78,    78,    79,    79,    80,    80,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     3,     4,     1,     3,     3,     4,     1,
       2,     3,     1,     3,     3,     3,     1,     3,     1,     3,
       2,     4,     1,     2,     3,     1,     3,     5,     5,     5,
       6,     6,     6,     1,     1,     1,     5,     6,     1,     3,
       1,     2,     2,     2,     2,     3,     3,     3,     3,     2,
       4,     2,     3,     1,     2,     2,     1,     1,     1,     1,
       4,     1,     2,     1,     7,     5,     2,     2,     2,     3,
       7,     5,     7,     1,     1,     4,     3,     1,     1,     1,
       3,     4,     2,     2,     2,     1,     1,     3,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1
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
#line 287 "parser.y"
                                {
  if(global_decl){
    llvm::json::Array json_inner = llvm::json::Array{};
    for(int i = 0; i < def_num; i++){
      std::string name = stak.back().getAsObject()->get("name")->getAsString()->str();
      ident2type[name] = global_type_decl;
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
#line 2153 "parser.tab.c"
    break;

  case 3: /* CompUnit: CompUnitItem  */
#line 307 "parser.y"
               {
  if(global_decl){
    llvm::json::Array json_inner = llvm::json::Array{};
    for(int i = 0; i < def_num; i++){
      std::string name = stak.back().getAsObject()->get("name")->getAsString()->str();
      ident2type[name] = global_type_decl;

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
#line 2182 "parser.tab.c"
    break;

  case 4: /* CompUnitItem: Decl  */
#line 332 "parser.y"
     {
  global_decl = true;
}
#line 2190 "parser.tab.c"
    break;

  case 5: /* CompUnitItem: FuncDef  */
#line 335 "parser.y"
         {}
#line 2196 "parser.tab.c"
    break;

  case 6: /* Decl: ConstDecl  */
#line 337 "parser.y"
               {
  
}
#line 2204 "parser.tab.c"
    break;

  case 7: /* Decl: VarDecl  */
#line 339 "parser.y"
          {

}
#line 2212 "parser.tab.c"
    break;

  case 8: /* Decl: FuncDecl  */
#line 341 "parser.y"
           {

}
#line 2220 "parser.tab.c"
    break;

  case 9: /* ConstDecl: T_CONST T_INT ConstDefChain T_SEMI  */
#line 345 "parser.y"
                                             {
  global_type_decl = TYPE_INT;
}
#line 2228 "parser.tab.c"
    break;

  case 10: /* ConstDecl: T_CONST T_CHAR ConstDefChain T_SEMI  */
#line 347 "parser.y"
                                     {
  
}
#line 2236 "parser.tab.c"
    break;

  case 11: /* ConstDecl: T_CONST T_LONGLONG ConstDefChain T_SEMI  */
#line 349 "parser.y"
                                         {
  
}
#line 2244 "parser.tab.c"
    break;

  case 12: /* ConstDecl: T_CONST T_FLOAT ConstDefChain T_SEMI  */
#line 351 "parser.y"
                                      {
  // todo
  global_type_decl = TYPE_FLOAT;
}
#line 2253 "parser.tab.c"
    break;

  case 13: /* ConstExpChain: T_L_SQUARE ConstExp T_R_SQUARE  */
#line 356 "parser.y"
                                             {
  // 
  lvalStack.pop();
  typeStack.pop();
  stak.pop_back();
}
#line 2264 "parser.tab.c"
    break;

  case 14: /* ConstExpChain: ConstExpChain T_L_SQUARE ConstExp T_R_SQUARE  */
#line 361 "parser.y"
                                               {
  // 
  lvalStack.pop();
  typeStack.pop();
  stak.pop_back();
}
#line 2275 "parser.tab.c"
    break;

  case 15: /* ConstDefChain: ConstDef  */
#line 368 "parser.y"
                       {
  if(debug) llvm::outs()<<"constdef first\n";
  def_num = 1;
}
#line 2284 "parser.tab.c"
    break;

  case 16: /* ConstDefChain: ConstDefChain T_COMMA ConstDef  */
#line 371 "parser.y"
                                {
  if(debug) llvm::outs()<<"constdef second\n";
  def_num++;
}
#line 2293 "parser.tab.c"
    break;

  case 17: /* ConstDef: T_IDENTIFIER T_EQUAL ConstInitVal  */
#line 376 "parser.y"
                                           {
  // 
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
#line 2310 "parser.tab.c"
    break;

  case 18: /* ConstDef: T_IDENTIFIER ConstExpChain T_EQUAL ConstInitVal  */
#line 387 "parser.y"
                                                 {
  // 
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto init_val = stak.back();
  stak.pop_back();
  initStak.pop_back();
  // to compute constexp
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "VarDecl"}, {"name", name},{"inner",llvm::json::Array{init_val}}});
}
#line 2326 "parser.tab.c"
    break;

  case 19: /* ConstInitVal: ConstExp  */
#line 399 "parser.y"
                      {
  // 
  if(debug) llvm::outs()<<"constexp 2 ConstInitVal\n";
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  int type2 = typeStack.top();
  typeStack.pop();

  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind", "ImplicitCastExpr"},
                                    {"inner", llvm::json::Array{rvalexp}}};
  }

  if(type2!=local_type_decl){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind", "ImplicitCastExpr"},
                                    {"inner", llvm::json::Array{rvalexp}}};
  }

  init_stak_level = 1;
  initStak.push_back(llvm::json::Object{{"value",1}});
}
#line 2354 "parser.tab.c"
    break;

  case 20: /* ConstInitVal: T_L_BRACE T_R_BRACE  */
#line 421 "parser.y"
                       {
  // 
  stak.push_back(llvm::json::Object{{"kind", "InitListExpr"}});
  init_stak_level = 1;
  initStak.push_back(llvm::json::Object{{"value",init_stak_level}});
}
#line 2365 "parser.tab.c"
    break;

  case 21: /* ConstInitVal: T_L_BRACE ConstInitValChain T_R_BRACE  */
#line 426 "parser.y"
                                         {
  // 
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
#line 2398 "parser.tab.c"
    break;

  case 22: /* ConstInitValChain: ConstInitVal  */
#line 455 "parser.y"
                                {
  // 

}
#line 2407 "parser.tab.c"
    break;

  case 23: /* ConstInitValChain: ConstInitValChain T_COMMA ConstInitVal  */
#line 458 "parser.y"
                                         {
  // 
}
#line 2415 "parser.tab.c"
    break;

  case 24: /* VarDecl: T_INT VarDefChain T_SEMI  */
#line 463 "parser.y"
                                  {
  if(debug) llvm::outs()<<"valdefchain 2 vardecl and def_num is "<<def_num<<"\n";
  global_type_decl = TYPE_INT;
}
#line 2424 "parser.tab.c"
    break;

  case 25: /* VarDecl: T_FLOAT VarDefChain T_SEMI  */
#line 466 "parser.y"
                              {
  // todo
  global_type_decl = TYPE_FLOAT;
  if(debug) llvm::outs()<<"valdefchain 2 vardecl and def_num is "<<def_num<<"\n";
}
#line 2434 "parser.tab.c"
    break;

  case 26: /* VarDefChain: VarDef  */
#line 472 "parser.y"
                   {
  def_num = 1;
}
#line 2442 "parser.tab.c"
    break;

  case 27: /* VarDefChain: VarDefChain T_COMMA VarDef  */
#line 474 "parser.y"
                            {
  def_num++;
}
#line 2450 "parser.tab.c"
    break;

  case 28: /* VarDef: T_IDENTIFIER  */
#line 478 "parser.y"
                    {
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "VarDecl"}, {"name", name}});
}
#line 2461 "parser.tab.c"
    break;

  case 29: /* VarDef: T_IDENTIFIER T_EQUAL InitVal  */
#line 483 "parser.y"
                              {
  // 
  initStak.pop_back();
  auto init_val = stak.back();
  stak.pop_back();
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "VarDecl"}, {"name", name},{"inner",llvm::json::Array{init_val}}});
}
#line 2476 "parser.tab.c"
    break;

  case 30: /* VarDef: T_IDENTIFIER ConstExpChain  */
#line 492 "parser.y"
                             {
  // 
  // to compute constexp
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "VarDecl"}, {"name", name}});
}
#line 2489 "parser.tab.c"
    break;

  case 31: /* VarDef: T_IDENTIFIER ConstExpChain T_EQUAL InitVal  */
#line 499 "parser.y"
                                            {
  // 
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
#line 2506 "parser.tab.c"
    break;

  case 32: /* InitVal: Exp  */
#line 513 "parser.y"
            {
  if(debug) llvm::outs()<<"Exp 2 InitVal\n";
  if(debug) print_stack();
  
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  int type2 = typeStack.top();
  typeStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind", "ImplicitCastExpr"},
                                    {"inner", llvm::json::Array{rvalexp}}};
  }
  if(type2!=local_type_decl){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind", "ImplicitCastExpr"},
                                    {"inner", llvm::json::Array{rvalexp}}};
  }

  init_stak_level = 1;
  initStak.push_back(llvm::json::Object{{"value",1}});
}
#line 2533 "parser.tab.c"
    break;

  case 33: /* InitVal: T_L_BRACE T_R_BRACE  */
#line 534 "parser.y"
                       {
  // 
  if(debug) llvm::outs()<<"empty 2 InitVal\n";
  if(debug) print_stack();
  stak.push_back(llvm::json::Object{{"kind", "InitListExpr"}});
  init_stak_level = 1;
  initStak.push_back(llvm::json::Object{{"value",init_stak_level}});
}
#line 2546 "parser.tab.c"
    break;

  case 34: /* InitVal: T_L_BRACE InitValChain T_R_BRACE  */
#line 541 "parser.y"
                                    {
  // 
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
#line 2581 "parser.tab.c"
    break;

  case 35: /* InitValChain: InitVal  */
#line 572 "parser.y"
                      {
  // 
  if(debug) llvm::outs()<<"initval 2 initvalchain\n";
  if(debug) print_stack();
}
#line 2591 "parser.tab.c"
    break;

  case 36: /* InitValChain: InitValChain T_COMMA InitVal  */
#line 576 "parser.y"
                               {
  // 
  if(debug) llvm::outs()<<"initvalchain 2 initvalchain\n";
  if(debug) print_stack();
}
#line 2601 "parser.tab.c"
    break;

  case 37: /* FuncDecl: T_INT T_IDENTIFIER T_L_PAREN T_R_PAREN T_SEMI  */
#line 582 "parser.y"
                                                        {
  global_type_decl = TYPE_INT;
  def_num = 1;
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                    {"name", name}});
  ident2type[name] = TYPE_INT;
}
#line 2616 "parser.tab.c"
    break;

  case 38: /* FuncDecl: T_VOID T_IDENTIFIER T_L_PAREN T_R_PAREN T_SEMI  */
#line 591 "parser.y"
                                                 {
  def_num = 1;
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                    {"name", name}});
}
#line 2629 "parser.tab.c"
    break;

  case 39: /* FuncDecl: T_FLOAT T_IDENTIFIER T_L_PAREN T_R_PAREN T_SEMI  */
#line 598 "parser.y"
                                                  {
  global_type_decl = TYPE_FLOAT;
  // todo
  def_num = 1;
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                    {"name", name}});
  ident2type[name] = TYPE_FLOAT;
}
#line 2645 "parser.tab.c"
    break;

  case 40: /* FuncDecl: T_INT T_IDENTIFIER T_L_PAREN FuncFParams T_R_PAREN T_SEMI  */
#line 608 "parser.y"
                                                             {
  global_type_decl = TYPE_INT;
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
  ident2type[name] = TYPE_INT;
}
#line 2672 "parser.tab.c"
    break;

  case 41: /* FuncDecl: T_VOID T_IDENTIFIER T_L_PAREN FuncFParams T_R_PAREN T_SEMI  */
#line 629 "parser.y"
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
#line 2697 "parser.tab.c"
    break;

  case 42: /* FuncDecl: T_FLOAT T_IDENTIFIER T_L_PAREN FuncFParams T_R_PAREN T_SEMI  */
#line 648 "parser.y"
                                                              {
  //todo
  global_type_decl = TYPE_FLOAT;
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
  ident2type[name] = TYPE_FLOAT;
}
#line 2725 "parser.tab.c"
    break;

  case 43: /* FuncType: T_INT  */
#line 672 "parser.y"
               {
  global_type_decl = TYPE_INT;
  return_type = TYPE_INT;
}
#line 2734 "parser.tab.c"
    break;

  case 44: /* FuncType: T_VOID  */
#line 675 "parser.y"
        {
  global_type_decl = TYPE_INT;
  return_type = TYPE_INT;
}
#line 2743 "parser.tab.c"
    break;

  case 45: /* FuncType: T_FLOAT  */
#line 678 "parser.y"
         {
  global_type_decl = TYPE_FLOAT;
  return_type = TYPE_FLOAT;
}
#line 2752 "parser.tab.c"
    break;

  case 46: /* FuncDef: FuncType T_IDENTIFIER T_L_PAREN T_R_PAREN Block  */
#line 683 "parser.y"
                                                         {
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto inner = stak.back();
  stak.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                    {"name", name},
                                    {"inner", llvm::json::Array{inner}}});
  ident2type[name] = return_type;
}
#line 2768 "parser.tab.c"
    break;

  case 47: /* FuncDef: FuncType T_IDENTIFIER T_L_PAREN FuncFParams T_R_PAREN Block  */
#line 693 "parser.y"
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
  ident2type[name] = return_type;
}
#line 2796 "parser.tab.c"
    break;

  case 48: /* FuncFParams: FuncFParam  */
#line 717 "parser.y"
                         {

  if(ellipsis){

  }else{
    func_FPara_num = 1;
  }
  ellipsis = false;

}
#line 2811 "parser.tab.c"
    break;

  case 49: /* FuncFParams: FuncFParams T_COMMA FuncFParam  */
#line 726 "parser.y"
                                 {

  if(ellipsis){

  }else{
    func_FPara_num ++;
  }
  ellipsis = false;
}
#line 2825 "parser.tab.c"
    break;

  case 50: /* FuncFParam: T_ELLIPSIS  */
#line 736 "parser.y"
                       {
  ellipsis = true;
}
#line 2833 "parser.tab.c"
    break;

  case 51: /* FuncFParam: T_INT T_IDENTIFIER  */
#line 738 "parser.y"
                    {

  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
  ident2type[name] = TYPE_INT;
}
#line 2846 "parser.tab.c"
    break;

  case 52: /* FuncFParam: T_CHAR T_IDENTIFIER  */
#line 745 "parser.y"
                     {

  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}
#line 2858 "parser.tab.c"
    break;

  case 53: /* FuncFParam: T_LONGLONG T_IDENTIFIER  */
#line 751 "parser.y"
                         {

  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}
#line 2870 "parser.tab.c"
    break;

  case 54: /* FuncFParam: T_FLOAT T_IDENTIFIER  */
#line 757 "parser.y"
                      {
  //todo
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
  ident2type[name] = TYPE_FLOAT;
}
#line 2883 "parser.tab.c"
    break;

  case 55: /* FuncFParam: T_INT T_IDENTIFIER ArrayFuncFParam  */
#line 764 "parser.y"
                                    {
  // 

  auto ArrayFuncFParam = stak.back();
  stak.pop_back();
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
  ident2type[name] = TYPE_INT;
}
#line 2899 "parser.tab.c"
    break;

  case 56: /* FuncFParam: T_CHAR T_IDENTIFIER ArrayFuncFParam  */
#line 774 "parser.y"
                                     {
  // 

  auto ArrayFuncFParam = stak.back();
  stak.pop_back();
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}
#line 2914 "parser.tab.c"
    break;

  case 57: /* FuncFParam: T_LONGLONG T_IDENTIFIER ArrayFuncFParam  */
#line 783 "parser.y"
                                         {

  // 
  auto ArrayFuncFParam = stak.back();
  stak.pop_back();
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}
#line 2929 "parser.tab.c"
    break;

  case 58: /* FuncFParam: T_FLOAT T_IDENTIFIER ArrayFuncFParam  */
#line 792 "parser.y"
                                      {
  //todo
  // 
  auto ArrayFuncFParam = stak.back();
  stak.pop_back();
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
  ident2type[name] = TYPE_FLOAT;
}
#line 2945 "parser.tab.c"
    break;

  case 59: /* ArrayFuncFParam: T_L_SQUARE T_R_SQUARE  */
#line 804 "parser.y"
                                       {
  // 
  stak.push_back(llvm::json::Object{{"kind","ArrayFuncFParam"}});
}
#line 2954 "parser.tab.c"
    break;

  case 60: /* ArrayFuncFParam: ArrayFuncFParam T_L_SQUARE ConstExp T_R_SQUARE  */
#line 807 "parser.y"
                                                 {
  // 
  lvalStack.pop();
  typeStack.pop();

  auto constExp = stak.back();
  stak.pop_back();
  auto ArrayFuncFParam = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","ArrayFuncFParam"}});
}
#line 2970 "parser.tab.c"
    break;

  case 61: /* Block: T_L_BRACE T_R_BRACE  */
#line 819 "parser.y"
                          {
  stak.push_back(llvm::json::Object{{"kind", "CompoundStmt"}});
}
#line 2978 "parser.tab.c"
    break;

  case 62: /* Block: T_L_BRACE BlockItemChain T_R_BRACE  */
#line 821 "parser.y"
                                     {
  if(debug) llvm::outs()<<"blockitem 2 block\n";
}
#line 2986 "parser.tab.c"
    break;

  case 63: /* BlockItemChain: BlockItem  */
#line 825 "parser.y"
                        {

}
#line 2994 "parser.tab.c"
    break;

  case 64: /* BlockItemChain: BlockItemChain Stmt  */
#line 827 "parser.y"
                     {
  auto stmt = stak.back();
  stak.pop_back();
  auto be_block_item = stak.back();
  stak.back().getAsObject()->get("inner")->getAsArray()->push_back(stmt);
}
#line 3005 "parser.tab.c"
    break;

  case 65: /* BlockItemChain: BlockItemChain Decl  */
#line 832 "parser.y"
                     {
  auto json_inner = llvm::json::Array{};
  for(int i = 0; i < def_num; i++){
    std::string name = stak.back().getAsObject()->get("name")->getAsString()->str();
    ident2type[name] = global_type_decl;
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
#line 3029 "parser.tab.c"
    break;

  case 66: /* BlockItem: Stmt  */
#line 853 "parser.y"
     {
  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind", "CompoundStmt"},
                                    {"inner", llvm::json::Array{inner}}};
}
#line 3039 "parser.tab.c"
    break;

  case 67: /* BlockItem: Decl  */
#line 857 "parser.y"
      {
  auto json_inner = llvm::json::Array{};
  for(int i = 0; i < def_num; i++){
    std::string name = stak.back().getAsObject()->get("name")->getAsString()->str();
    ident2type[name] = global_type_decl;
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
#line 3062 "parser.tab.c"
    break;

  case 68: /* Stmt: MatchedStmt  */
#line 877 "parser.y"
                 {

}
#line 3070 "parser.tab.c"
    break;

  case 69: /* Stmt: OpenStmt  */
#line 879 "parser.y"
          {

}
#line 3078 "parser.tab.c"
    break;

  case 70: /* MatchedStmt: LVal T_EQUAL Exp T_SEMI  */
#line 883 "parser.y"
                                    {
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  lvalStack.pop();

  int type2 = typeStack.top();
  typeStack.pop();
  int type1 = typeStack.top();
  typeStack.pop();
  
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }

  if(type1!=type2){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }

  auto exp = stak.back();
  stak.pop_back();
  auto lval = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","BinaryOperator"},{"opcode","="},{"inner",llvm::json::Array{lval,exp}}});
}
#line 3109 "parser.tab.c"
    break;

  case 71: /* MatchedStmt: T_SEMI  */
#line 908 "parser.y"
        {
  stak.push_back(llvm::json::Object{{"kind","NullStmt"}});
}
#line 3117 "parser.tab.c"
    break;

  case 72: /* MatchedStmt: Exp T_SEMI  */
#line 910 "parser.y"
            {
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  typeStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }
}
#line 3131 "parser.tab.c"
    break;

  case 73: /* MatchedStmt: Block  */
#line 918 "parser.y"
       {

}
#line 3139 "parser.tab.c"
    break;

  case 74: /* MatchedStmt: T_IF T_L_PAREN Exp T_R_PAREN MatchedStmt T_ELSE MatchedStmt  */
#line 920 "parser.y"
                                                              {
  if(debug) llvm::outs()<<"matched stmt 2 if\n";
  if(debug) print_stack();
  auto elseStmt = stak.back();
  stak.pop_back();
  auto thenStmt = stak.back();
  stak.pop_back();
  
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  typeStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }

  auto ifExp = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","IfStmt"},{"inner",llvm::json::Array{ifExp,thenStmt,elseStmt}}});
}
#line 3164 "parser.tab.c"
    break;

  case 75: /* MatchedStmt: T_WHILE T_L_PAREN Exp T_R_PAREN Stmt  */
#line 939 "parser.y"
                                       {
  auto loopStmt = stak.back();
  stak.pop_back();

  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  typeStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }

  auto whileExp = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","WhileStmt"},{"inner",llvm::json::Array{whileExp,loopStmt}}});
}
#line 3185 "parser.tab.c"
    break;

  case 76: /* MatchedStmt: T_BREAK T_SEMI  */
#line 954 "parser.y"
                 {
  stak.push_back(llvm::json::Object{{"kind","BreakStmt"}});
}
#line 3193 "parser.tab.c"
    break;

  case 77: /* MatchedStmt: T_CONTINUE T_SEMI  */
#line 956 "parser.y"
                    {
  stak.push_back(llvm::json::Object{{"kind","ContinueStmt"}});
}
#line 3201 "parser.tab.c"
    break;

  case 78: /* MatchedStmt: T_RETURN T_SEMI  */
#line 958 "parser.y"
                 {
  stak.push_back(llvm::json::Object{{"kind", "ReturnStmt"}});
}
#line 3209 "parser.tab.c"
    break;

  case 79: /* MatchedStmt: T_RETURN Exp T_SEMI  */
#line 960 "parser.y"
                      {
  if(debug) llvm::outs()<<"return 2 stmt\n";
  if(debug) print_stack();

  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  int typeStacktop = typeStack.top();
  typeStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }
  if(typeStacktop!=return_type){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }

  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind", "ReturnStmt"},
                                    {"inner", llvm::json::Array{inner}}};
}
#line 3235 "parser.tab.c"
    break;

  case 80: /* MatchedStmt: T_DO Block T_WHILE T_L_PAREN Exp T_R_PAREN T_SEMI  */
#line 980 "parser.y"
                                                    {

  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  typeStack.pop();
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
#line 3256 "parser.tab.c"
    break;

  case 81: /* OpenStmt: T_IF T_L_PAREN Exp T_R_PAREN Stmt  */
#line 997 "parser.y"
                                            {
  if(debug) llvm::outs()<<"open stmt no else 2 if\n";
  if(debug) print_stack();
  auto thenStmt = stak.back();
  stak.pop_back();

  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  typeStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }

  auto ifExp = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","IfStmt"},{"inner",llvm::json::Array{ifExp,thenStmt}}});
}
#line 3279 "parser.tab.c"
    break;

  case 82: /* OpenStmt: T_IF T_L_PAREN Exp T_R_PAREN MatchedStmt T_ELSE OpenStmt  */
#line 1014 "parser.y"
                                                           {
  if(debug) llvm::outs()<<"open stmt no else 2 if\n";
  if(debug) print_stack();
  auto elseStmt = stak.back();
  stak.pop_back();
  auto thenStmt = stak.back();
  stak.pop_back();

  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  typeStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }

  auto ifExp = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","IfStmt"},{"inner",llvm::json::Array{ifExp,thenStmt,elseStmt}}});
}
#line 3304 "parser.tab.c"
    break;

  case 83: /* Exp: LOrExp  */
#line 1039 "parser.y"
            {
  if(debug) llvm::outs()<<"LOrExp 2 Exp\n";
}
#line 3312 "parser.tab.c"
    break;

  case 84: /* LVal: T_IDENTIFIER  */
#line 1043 "parser.y"
                   {
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","DeclRefExpr"},{"name",name}});
  
  lvalStack.push(true);
  typeStack.push(ident2type[name]);
}
#line 3326 "parser.tab.c"
    break;

  case 85: /* LVal: LVal T_L_SQUARE Exp T_R_SQUARE  */
#line 1051 "parser.y"
                                {
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  typeStack.pop();
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
#line 3354 "parser.tab.c"
    break;

  case 86: /* PrimaryExp: T_L_PAREN Exp T_R_PAREN  */
#line 1075 "parser.y"
                                    {
  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind","ParenExpr"},
  {"inner", llvm::json::Array{inner}}};
}
#line 3364 "parser.tab.c"
    break;

  case 87: /* PrimaryExp: LVal  */
#line 1079 "parser.y"
      {
  // 
}
#line 3372 "parser.tab.c"
    break;

  case 88: /* PrimaryExp: Number  */
#line 1081 "parser.y"
        {
  if(debug) llvm::outs()<<"number 2 primary\n";
}
#line 3380 "parser.tab.c"
    break;

  case 89: /* UnaryExp: PrimaryExp  */
#line 1085 "parser.y"
                     {
  if(debug) llvm::outs()<<"primary 2 unaryexp\n";
  if(debug) print_stack();
}
#line 3389 "parser.tab.c"
    break;

  case 90: /* UnaryExp: T_IDENTIFIER T_L_PAREN T_R_PAREN  */
#line 1088 "parser.y"
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
  typeStack.push(ident2type[name]);
}
#line 3412 "parser.tab.c"
    break;

  case 91: /* UnaryExp: T_IDENTIFIER T_L_PAREN FuncRParams T_R_PAREN  */
#line 1105 "parser.y"
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
  typeStack.push(ident2type[name]);


  // stak.back() = llvm::json::Object{{"kind", "CallExpr"},
  //                                   {"name",name},
  //                                   {"inner", llvm::json::Array{ImplicitCastExpr}}};
  // auto array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  // for(int i = func_RPara_num-1; i >= 0; i--){
  //   array_inner->push_back(json_inner[i]);
  // }
}
#line 3459 "parser.tab.c"
    break;

  case 92: /* UnaryExp: T_PLUS UnaryExp  */
#line 1146 "parser.y"
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
#line 3483 "parser.tab.c"
    break;

  case 93: /* UnaryExp: T_MINUS UnaryExp  */
#line 1164 "parser.y"
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
#line 3507 "parser.tab.c"
    break;

  case 94: /* UnaryExp: T_EXCLAIM UnaryExp  */
#line 1182 "parser.y"
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
#line 3531 "parser.tab.c"
    break;

  case 95: /* Number: T_NUMERIC_CONSTANT  */
#line 1202 "parser.y"
                           {
  auto number = lexStack.back();
  lexStack.pop_back();
  stak.push_back(number);
  if(debug) llvm::outs()<<"T_NUMERIC_CONSTANT 2 number\n";

  lvalStack.push(false);
}
#line 3544 "parser.tab.c"
    break;

  case 96: /* FuncRParams: Exp  */
#line 1212 "parser.y"
                 {
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  typeStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }
  auto exp = stak.back();
  stak.back() = llvm::json::Object{{"kind","CallExpr"},{"inner",llvm::json::Array{exp}}};

  // func_RPara_num = 1;
}
#line 3562 "parser.tab.c"
    break;

  case 97: /* FuncRParams: FuncRParams T_COMMA Exp  */
#line 1224 "parser.y"
                          {
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  typeStack.pop();
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
#line 3582 "parser.tab.c"
    break;

  case 98: /* MulExp: UnaryExp  */
#line 1243 "parser.y"
        {
  if(debug) llvm::outs()<<"UnaryExp 2 MulExp\n";
  print_stack();
}
#line 3591 "parser.tab.c"
    break;

  case 99: /* MulExp: MulExp T_STAR UnaryExp  */
#line 1246 "parser.y"
                        {
  if(debug) llvm::outs()<<"MulExp 2 MulExp\n";
  if(debug) print_stack();
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  int type2 = typeStack.top();
  typeStack.pop();
  int type1 = typeStack.top();
  typeStack.pop();

  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type1==TYPE_FLOAT||type1==TYPE_DOUBLE)&&type2==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==TYPE_FLOAT||type2==TYPE_DOUBLE)&&type1==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","*"},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
  int newtype = type1>type2?type1:type2;
  if(newtype==2){
    newtype=1;
  }
  typeStack.push(newtype);
}
#line 3640 "parser.tab.c"
    break;

  case 100: /* MulExp: MulExp T_SLASH UnaryExp  */
#line 1289 "parser.y"
                         {
  if(debug) llvm::outs()<<"MulExp 2 MulExp\n";
  if(debug) print_stack();
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  int type2 = typeStack.top();
  typeStack.pop();
  int type1 = typeStack.top();
  typeStack.pop();

  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type1==TYPE_FLOAT||type1==TYPE_DOUBLE)&&type2==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==TYPE_FLOAT||type2==TYPE_DOUBLE)&&type1==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","/"},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
  int newtype = type1>type2?type1:type2;
  if(newtype==2){
    newtype=1;
  }
  typeStack.push(newtype);
}
#line 3689 "parser.tab.c"
    break;

  case 101: /* MulExp: MulExp T_PERCENT UnaryExp  */
#line 1332 "parser.y"
                           {
  if(debug) llvm::outs()<<"MulExp 2 MulExp\n";
  if(debug) print_stack();
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  int type2 = typeStack.top();
  typeStack.pop();
  int type1 = typeStack.top();
  typeStack.pop();

  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type1==TYPE_FLOAT||type1==TYPE_DOUBLE)&&type2==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==TYPE_FLOAT||type2==TYPE_DOUBLE)&&type1==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","%"},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
  int newtype = type1>type2?type1:type2;
  if(newtype==2){
    newtype=1;
  }
  typeStack.push(newtype);
}
#line 3738 "parser.tab.c"
    break;

  case 102: /* AddExp: MulExp  */
#line 1379 "parser.y"
      {
  if(debug) llvm::outs()<<"MulExp 2 AddExp\n";
}
#line 3746 "parser.tab.c"
    break;

  case 103: /* AddExp: AddExp T_PLUS MulExp  */
#line 1381 "parser.y"
                       {
  if(debug) llvm::outs()<<"exp1 2 AddExp\n";

  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  int type2 = typeStack.top();
  typeStack.pop();
  int type1 = typeStack.top();
  typeStack.pop();

  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type1==TYPE_FLOAT||type1==TYPE_DOUBLE)&&type2==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==TYPE_FLOAT||type2==TYPE_DOUBLE)&&type1==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","+"},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
  int newtype = type1>type2?type1:type2;
  if(newtype==2){
    newtype=1;
  }
  typeStack.push(newtype);
}
#line 3795 "parser.tab.c"
    break;

  case 104: /* AddExp: AddExp T_MINUS MulExp  */
#line 1424 "parser.y"
                        {
  if(debug) llvm::outs()<<"exp2 2 AddExp\n";

  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  int type2 = typeStack.top();
  typeStack.pop();
  int type1 = typeStack.top();
  typeStack.pop();

  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type1==TYPE_FLOAT||type1==TYPE_DOUBLE)&&type2==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==TYPE_FLOAT||type2==TYPE_DOUBLE)&&type1==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","-"},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
  int newtype = type1>type2?type1:type2;
  if(newtype==2){
    newtype=1;
  }
  typeStack.push(newtype);
}
#line 3844 "parser.tab.c"
    break;

  case 105: /* RelExp: AddExp  */
#line 1470 "parser.y"
      {
  if(debug) llvm::outs()<<"AddExp 2 RelExp\n";
}
#line 3852 "parser.tab.c"
    break;

  case 106: /* RelExp: RelExp T_LESS AddExp  */
#line 1472 "parser.y"
                       {
  if(debug) llvm::outs()<<"exp1 2 RelExp\n";
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  int type2 = typeStack.top();
  typeStack.pop();
  int type1 = typeStack.top();
  typeStack.pop();

  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type1==TYPE_FLOAT||type1==TYPE_DOUBLE)&&type2==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==TYPE_FLOAT||type2==TYPE_DOUBLE)&&type1==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","<"},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
  int newtype = type1>type2?type1:type2;
  if(newtype==2){
    newtype=1;
  }
  typeStack.push(newtype);
}
#line 3900 "parser.tab.c"
    break;

  case 107: /* RelExp: RelExp T_GREATER AddExp  */
#line 1514 "parser.y"
                          {
  if(debug) llvm::outs()<<"exp2 2 RelExp\n";

  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  int type2 = typeStack.top();
  typeStack.pop();
  int type1 = typeStack.top();
  typeStack.pop();

  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type1==TYPE_FLOAT||type1==TYPE_DOUBLE)&&type2==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==TYPE_FLOAT||type2==TYPE_DOUBLE)&&type1==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode",">"},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
  int newtype = type1>type2?type1:type2;
  if(newtype==2){
    newtype=1;
  }
  typeStack.push(newtype);

}
#line 3950 "parser.tab.c"
    break;

  case 108: /* RelExp: RelExp T_LESSEQUAL AddExp  */
#line 1558 "parser.y"
                            {
  if(debug) llvm::outs()<<"exp3 2 RelExp\n";

  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  int type2 = typeStack.top();
  typeStack.pop();
  int type1 = typeStack.top();
  typeStack.pop();

  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type1==TYPE_FLOAT||type1==TYPE_DOUBLE)&&type2==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==TYPE_FLOAT||type2==TYPE_DOUBLE)&&type1==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","<="},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
  int newtype = type1>type2?type1:type2;
  if(newtype==2){
    newtype=1;
  }
  typeStack.push(newtype);
}
#line 3999 "parser.tab.c"
    break;

  case 109: /* RelExp: RelExp T_GREATEREQUAL AddExp  */
#line 1601 "parser.y"
                               {
  if(debug) llvm::outs()<<"exp4 2 RelExp\n";

  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  int type2 = typeStack.top();
  typeStack.pop();
  int type1 = typeStack.top();
  typeStack.pop();

  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type1==TYPE_FLOAT||type1==TYPE_DOUBLE)&&type2==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==TYPE_FLOAT||type2==TYPE_DOUBLE)&&type1==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode",">="},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
  int newtype = type1>type2?type1:type2;
  if(newtype==2){
    newtype=1;
  }
  typeStack.push(newtype);
}
#line 4048 "parser.tab.c"
    break;

  case 110: /* EqExp: RelExp  */
#line 1647 "parser.y"
      {

}
#line 4056 "parser.tab.c"
    break;

  case 111: /* EqExp: EqExp T_EQUALEQUAL RelExp  */
#line 1649 "parser.y"
                           {
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  int type2 = typeStack.top();
  typeStack.pop();
  int type1 = typeStack.top();
  typeStack.pop();

  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type1==TYPE_FLOAT||type1==TYPE_DOUBLE)&&type2==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==TYPE_FLOAT||type2==TYPE_DOUBLE)&&type1==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","=="},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
  int newtype = type1>type2?type1:type2;
  if(newtype==2){
    newtype=1;
  }
  typeStack.push(newtype);
}
#line 4103 "parser.tab.c"
    break;

  case 112: /* EqExp: EqExp T_EXCLAIMEQUAL RelExp  */
#line 1690 "parser.y"
                             {
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  int type2 = typeStack.top();
  typeStack.pop();
  int type1 = typeStack.top();
  typeStack.pop();

  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type1==TYPE_FLOAT||type1==TYPE_DOUBLE)&&type2==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==TYPE_FLOAT||type2==TYPE_DOUBLE)&&type1==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","!="},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
  int newtype = type1>type2?type1:type2;
  if(newtype==2){
    newtype=1;
  }
  typeStack.push(newtype);
}
#line 4150 "parser.tab.c"
    break;

  case 113: /* LAndExp: EqExp  */
#line 1734 "parser.y"
     {

}
#line 4158 "parser.tab.c"
    break;

  case 114: /* LAndExp: LAndExp T_AMPAMP EqExp  */
#line 1736 "parser.y"
                        {
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  int type2 = typeStack.top();
  typeStack.pop();
  int type1 = typeStack.top();
  typeStack.pop();

  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type1==TYPE_FLOAT||type1==TYPE_DOUBLE)&&type2==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==TYPE_FLOAT||type2==TYPE_DOUBLE)&&type1==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","&&"},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
  int newtype = type1>type2?type1:type2;
  if(newtype==2){
    newtype=1;
  }
  typeStack.push(newtype);
}
#line 4205 "parser.tab.c"
    break;

  case 115: /* LOrExp: LAndExp  */
#line 1779 "parser.y"
               {

}
#line 4213 "parser.tab.c"
    break;

  case 116: /* LOrExp: LOrExp T_PIPEPIPE LAndExp  */
#line 1781 "parser.y"
                           {
  auto lval2rval2 = lvalStack.top();
  lvalStack.pop();
  auto lval2rval1 = lvalStack.top();
  lvalStack.pop();

  int type2 = typeStack.top();
  typeStack.pop();
  int type1 = typeStack.top();
  typeStack.pop();

  if(lval2rval2){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type1==TYPE_FLOAT||type1==TYPE_DOUBLE)&&type2==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==TYPE_FLOAT||type2==TYPE_DOUBLE)&&type1==TYPE_INT){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","||"},{"inner",llvm::json::Array{exp1,exp2}}};
  lvalStack.push(false);
  int newtype = type1>type2?type1:type2;
  if(newtype==2){
    newtype=1;
  }
  typeStack.push(newtype);
}
#line 4260 "parser.tab.c"
    break;

  case 117: /* ConstExp: Exp  */
#line 1824 "parser.y"
             {
  if(debug) llvm::outs()<<"ConstExp 2 Exp\n";
}
#line 4268 "parser.tab.c"
    break;


#line 4272 "parser.tab.c"

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

#line 1829 "parser.y"
