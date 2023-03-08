%{
#include <cctype>
#include <cstdio>
#include <string>
#define YYEOF 0
int yylex();
int main() {
  do {
  } while (yylex() != YYEOF);
}
std::string yyloc = "<stdin>";
int yyrow = 1, yycolumn = 1, yycolpre = 1;
bool StartOfLine = true;
std::string StartOfLine_str = " [StartOfLine]";
bool LeadingSpace = false;
std::string LeadingSpace_str = " [LeadingSpace]";
#define YY_USER_ACTION                                                         \
  do {                                                                         \
    yycolumn += yyleng;                                                        \
  } while (0);
%}
%option noyywrap

HEX 0(X|x)([0-9a-fA-F]+)
OCTAL 0([0-7]+)
DECIMAL [0-9]+
INT {HEX}|{OCTAL}|{DECIMAL}

DECIMAL-WHOLE-NUMBER {DECIMAL}
DECIMAL-FRACTION \.{DECIMAL}
DECIMAL-EXPONENT (e|E)(\+|\-)?{DECIMAL}

HEX-WHOLE-NUMBER 0(X|x)([0-9a-fA-F]*)
HEX-FRACTION \.([0-9a-fA-F]+)
HEX-EXPONENT (p|P)(\+|\-)?([0-9a-fA-F]+)

SUFFIX (f|F|l|L)?

HEX_FLOAT {HEX-WHOLE-NUMBER}{HEX-FRACTION}{HEX-EXPONENT}?|{HEX-WHOLE-NUMBER}{HEX-EXPONENT}|{HEX-WHOLE-NUMBER}\.{HEX-EXPONENT}?|{HEX-FRACTION}{HEX-EXPONENT}?
DECIMAL_FLOAT {DECIMAL-WHOLE-NUMBER}{DECIMAL-FRACTION}{DECIMAL-EXPONENT}?|{DECIMAL-WHOLE-NUMBER}{DECIMAL-EXPONENT}|{DECIMAL-WHOLE-NUMBER}\.{DECIMAL-EXPONENT}?|{DECIMAL-FRACTION}{DECIMAL-EXPONENT}?
FLOAT {HEX_FLOAT}|{DECIMAL_FLOAT}{SUFFIX}

NUMERIC_CONSTANT {INT}|{FLOAT}

STRING_LITERAL \"(\\.|[^\\\n\"])*\"

STRING_LITERAL_TMP \"[\ "'@0-9a-zA-Z\+\-\!\*\/\%\<\>\=\&\|\;\(\)\{\}\[\]\\]*\"

%%
#.* {
  std::string s(yytext);
  auto l = s.find("\""), r = s.rfind("\"");
  yyloc = s.substr(l + 1, r - l - 1);
  for (int i = 0; i < s.size(); ++i){
    if (std::isdigit(s[i])) {
      for (yyrow = 0; i < s.size() && std::isdigit(s[i]); ++i)
        yyrow = yyrow * 10 + s[i] - '0';
      --yyrow;
      break;
    }
  }
}

\.\.\. {

  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  
  std::fprintf(yyout, "ellipsis '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}


\  {
  LeadingSpace = true;
  return ~YYEOF;
}

\n {
  ++yyrow;
  yycolpre = yycolumn;
  yycolumn = 1;
  StartOfLine = true;
  LeadingSpace = false;
}

[\f\r\t\v ] {

}

int {

  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  
  std::fprintf(yyout, "int '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

long {

  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  
  std::fprintf(yyout, "long '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

do {

  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  
  std::fprintf(yyout, "do '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

{STRING_LITERAL} {

  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  
  std::fprintf(yyout, "string_literal '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

float {

  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  
  std::fprintf(yyout, "float '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

double {

  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  
  std::fprintf(yyout, "double '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

char {

  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  
  std::fprintf(yyout, "char '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}


return {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "return '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

const {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "const '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

void {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "void '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

if {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "if '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

else {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "else '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

while {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "while '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

break {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "break '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

continue {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "continue '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

\( {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "l_paren '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

\) {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "r_paren '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

\[ {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "l_square '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

\] {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "r_square '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

\{ {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "l_brace '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

\} {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "r_brace '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

, {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "comma '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

; {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "semi '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

{NUMERIC_CONSTANT} {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "numeric_constant '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext,
               StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

[a-zA-Z_][a-zA-Z_0-9]* {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "identifier '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext,
               StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow, yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

<<EOF>> {
  StartOfLine_str = "";
  LeadingSpace_str = "";
  std::fprintf(yyout, "eof ''\t%s%s\tLoc=<%s:%d:%d>\n", StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow - 1,
               yycolpre - yyleng);
  return YYEOF;
}

\+|\-|\!|\*|\/|\% {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  switch(yytext[0]){
    case '+':{
      std::fprintf(yyout, "plus '+'\t%s%s\tLoc=<%s:%d:%d>\n",  StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
                  yycolumn - yyleng);
      break;
    }
    case '-':{
      std::fprintf(yyout, "minus '-'\t%s%s\tLoc=<%s:%d:%d>\n",  StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
                  yycolumn - yyleng);
      break;
    }
    case '!':{
      std::fprintf(yyout, "exclaim '!'\t%s%s\tLoc=<%s:%d:%d>\n",  StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
                  yycolumn - yyleng);
      break;
    }
    case '*':{
      std::fprintf(yyout, "star '*'\t%s%s\tLoc=<%s:%d:%d>\n",  StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
                  yycolumn - yyleng);
      break;
    }
    case '/':{
      std::fprintf(yyout, "slash '/'\t%s%s\tLoc=<%s:%d:%d>\n",  StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
                  yycolumn - yyleng);
      break;
    }
    case '%':{
      std::fprintf(yyout, "percent '\%'\t%s%s\tLoc=<%s:%d:%d>\n",  StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
                  yycolumn - yyleng);
      break;
    }
    default:{
      std::fprintf(yyout, "error ''\t%s%s\tLoc=<%s:%d:%d>\n", StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
               yycolumn - yyleng);
      break;
    }
  }
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

\<\= {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "lessequal '<='\t%s%s\tLoc=<%s:%d:%d>\n", StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
               yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}
\>\= {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "greaterequal '>='\t%s%s\tLoc=<%s:%d:%d>\n", StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
               yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

\=\= {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "equalequal '=='\t%s%s\tLoc=<%s:%d:%d>\n", StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
               yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

!\= {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "exclaimequal '!='\t%s%s\tLoc=<%s:%d:%d>\n", StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
               yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

&& {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "ampamp '&&'\t%s%s\tLoc=<%s:%d:%d>\n", StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
               yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

\|\| {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "pipepipe '||'\t%s%s\tLoc=<%s:%d:%d>\n", StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
               yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

= {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "equal '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
               yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

\< {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "less '<'\t%s%s\tLoc=<%s:%d:%d>\n", StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
               yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}

\> {
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "greater '>'\t%s%s\tLoc=<%s:%d:%d>\n", StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(), yyrow,
               yycolumn - yyleng);
  StartOfLine = false; LeadingSpace = false; return ~YYEOF;
}



. {
  LeadingSpace = true;
  if(StartOfLine){
    StartOfLine_str = " [StartOfLine]";
  }else{
    StartOfLine_str = "";
  }
  if(LeadingSpace){
    LeadingSpace_str = " [LeadingSpace]";
  }else{
    LeadingSpace_str = "";
  }
  std::fprintf(yyout, "unknown '%s'\t%s%s\tLoc=<%s:%d:%d>\n", yytext, StartOfLine_str.c_str(), LeadingSpace_str.c_str(), yyloc.c_str(),
               yyrow, yycolumn - yyleng);
  return ~YYEOF;
}
%%