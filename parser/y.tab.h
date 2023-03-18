/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    T_INT = 261,                   /* T_INT  */
    T_L_SQUARE = 262,              /* T_L_SQUARE  */
    T_R_SQUARE = 263,              /* T_R_SQUARE  */
    T_EQUAL = 264,                 /* T_EQUAL  */
    T_L_BRACE = 265,               /* T_L_BRACE  */
    T_R_BRACE = 266,               /* T_R_BRACE  */
    T_IDENTIFIER = 267,            /* T_IDENTIFIER  */
    T_L_PAREN = 268,               /* T_L_PAREN  */
    T_R_PAREN = 269,               /* T_R_PAREN  */
    T_VOID = 270,                  /* T_VOID  */
    T_IF = 271,                    /* T_IF  */
    T_ELSE = 272,                  /* T_ELSE  */
    T_WHILE = 273,                 /* T_WHILE  */
    T_BREAK = 274,                 /* T_BREAK  */
    T_CONTINUE = 275,              /* T_CONTINUE  */
    T_RETURN = 276,                /* T_RETURN  */
    T_NUMERIC_CONSTANT = 277,      /* T_NUMERIC_CONSTANT  */
    T_PLUS = 278,                  /* T_PLUS  */
    T_MINUS = 279,                 /* T_MINUS  */
    T_EXCLAIM = 280,               /* T_EXCLAIM  */
    T_STAR = 281,                  /* T_STAR  */
    T_SLASH = 282,                 /* T_SLASH  */
    T_PERCENT = 283,               /* T_PERCENT  */
    T_LESS = 284,                  /* T_LESS  */
    T_GREATER = 285,               /* T_GREATER  */
    T_LESSEQUAL = 286,             /* T_LESSEQUAL  */
    T_GREATEREQUAL = 287,          /* T_GREATEREQUAL  */
    T_EQUALEQUAL = 288,            /* T_EQUALEQUAL  */
    T_EXCLAIMEQUAL = 289,          /* T_EXCLAIMEQUAL  */
    T_AMPAMP = 290,                /* T_AMPAMP  */
    T_PIPEPIPE = 291               /* T_PIPEPIPE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_CONST 258
#define T_COMMA 259
#define T_SEMI 260
#define T_INT 261
#define T_L_SQUARE 262
#define T_R_SQUARE 263
#define T_EQUAL 264
#define T_L_BRACE 265
#define T_R_BRACE 266
#define T_IDENTIFIER 267
#define T_L_PAREN 268
#define T_R_PAREN 269
#define T_VOID 270
#define T_IF 271
#define T_ELSE 272
#define T_WHILE 273
#define T_BREAK 274
#define T_CONTINUE 275
#define T_RETURN 276
#define T_NUMERIC_CONSTANT 277
#define T_PLUS 278
#define T_MINUS 279
#define T_EXCLAIM 280
#define T_STAR 281
#define T_SLASH 282
#define T_PERCENT 283
#define T_LESS 284
#define T_GREATER 285
#define T_LESSEQUAL 286
#define T_GREATEREQUAL 287
#define T_EQUALEQUAL 288
#define T_EXCLAIMEQUAL 289
#define T_AMPAMP 290
#define T_PIPEPIPE 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
