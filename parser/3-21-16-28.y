%{
#include "parser.hh"
#include <llvm/Support/JSON.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/raw_ostream.h>
#include <stdio.h>
#define yyerror(x)                                                             \
  do {                                                                         \
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
auto debug = true;
llvm::json::Array stak;
int const_def_num = 0;
int val_def_num = 0;
}  //namespace
auto print_stack(){
  if(debug) llvm::outs()<<"\nprintf stak\n";
  for(auto i=0;i<stak.size();i++){
    if(debug) llvm::outs()<<stak[i]<<"\n";
  }
  if(debug) llvm::outs()<<"\nprintf stak end\n";
  return 0;
}
auto yylex() {
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
    stak.push_back(llvm::json::Object{{"value", s}});
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
    stak.push_back(
        llvm::json::Object{{"kind", "IntegerLiteral"}, {"value", s}});
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
%}
%token T_CONST
%token T_COMMA
%token T_SEMI
%token T_INT
%token T_CHAR
%token T_LONGLONG
%token T_L_SQUARE
%token T_R_SQUARE
%token T_EQUAL
%token T_L_BRACE
%token T_R_BRACE
%token T_IDENTIFIER
%token T_L_PAREN
%token T_R_PAREN
%token T_VOID
%token T_IF
%token T_ELSE
%token T_DO
%token T_WHILE
%token T_BREAK
%token T_CONTINUE
%token T_RETURN
%token T_NUMERIC_CONSTANT
%token T_PLUS
%token T_MINUS
%token T_EXCLAIM
%token T_STAR
%token T_SLASH
%token T_PERCENT
%token T_LESS
%token T_GREATER
%token T_LESSEQUAL
%token T_GREATEREQUAL
%token T_EQUALEQUAL
%token T_EXCLAIMEQUAL
%token T_AMPAMP
%token T_PIPEPIPE

%left T_PIPEPIPE
%left T_AMPAMP
%left T_PLUS T_MINUS
%left T_STAR T_SLASH T_PERCENT
%start CompUnit
%define parse.error verbose
%define parse.lac full
%%
CompUnit: CompUnit CompUnitItem {
  auto inner = stak.back();
  stak.pop_back();
  stak.back().getAsObject()->get("inner")->getAsArray()->push_back(inner);
}|CompUnitItem {
  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind", "TranslationUnitDecl"},
                                   {"inner", llvm::json::Array{inner}}};
}
CompUnitItem: 
Decl {}
|FuncDef {}

Decl: ConstDecl{
  
  auto json_inner = llvm::json::Array{};
  for(auto i = 0; i < const_def_num; i++){
    json_inner.push_back(stak.back());
    stak.pop_back();
  }
  stak.push_back(llvm::json::Object{{"kind", "DeclStmt"},
                                   {"inner", llvm::json::Array{}}});
  auto array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  for(auto i = const_def_num-1; i >= 0; i--){
    array_inner->push_back(json_inner[i]);
  }
  
}| VarDecl{
  if(debug) llvm::outs()<<"vardecl 2 decl\n";
  if(debug) print_stack();
  auto json_inner = llvm::json::Array{};
  for(auto i = 0; i < val_def_num; i++){
    json_inner.push_back(stak.back());
    stak.pop_back();
  }
  stak.push_back(llvm::json::Object{{"kind", "DeclStmt"},
                                   {"inner", llvm::json::Array{}}});
  auto array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  for(auto i = val_def_num-1; i >= 0; i--){
    array_inner->push_back(json_inner[i]);
  }
}

ConstDecl: T_CONST T_INT ConstDefChain T_SEMI{

}|T_CONST T_CHAR ConstDefChain T_SEMI{
  
}|T_CONST T_LONGLONG ConstDefChain T_SEMI{
  
}

ConstDefChain: ConstDef{
  if(debug) llvm::outs()<<"constdef first\n";
  const_def_num = 1;
}|ConstDefChain T_COMMA ConstDef{
  if(debug) llvm::outs()<<"constdef second\n";
  const_def_num++;
}

ConstDef: T_IDENTIFIER T_EQUAL ConstInitVal{
  auto exp2 = stak.back();
  stak.pop_back();
  auto exp1 = stak.back();
  auto exp1_name = exp1.getAsObject()->get("value")->getAsString()->str();
  stak.back() = llvm::json::Object{{"kind", "VarDecl"},
                                  {"name",exp1_name},
                                  {"inner", llvm::json::Array{exp2}}};
}

ConstInitVal: ConstExp{
  if(debug) llvm::outs()<<"constexp 2 ConstInitVal\n";
}


Block: T_L_BRACE T_R_BRACE{
  stak.push_back(llvm::json::Object{{"kind", "CompoundStmt"}});
}|T_L_BRACE BlockItemChain T_R_BRACE {
  if(debug) llvm::outs()<<"blockitem 2 block\n";
}

BlockItemChain:BlockItem{

}|BlockItemChain Stmt{
  auto stmt = stak.back();
  stak.pop_back();
  auto be_block_item = stak.back();
  stak.back().getAsObject()->get("inner")->getAsArray()->push_back(stmt);
}|BlockItemChain Decl{
  auto decl = stak.back();
  stak.pop_back();
  auto be_block_item = stak.back();
  stak.back().getAsObject()->get("inner")->getAsArray()->push_back(decl);
}

BlockItem: 
Stmt {
  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind", "CompoundStmt"},
                                   {"inner", llvm::json::Array{inner}}};
}|Decl{
  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind", "CompoundStmt"},
                                   {"inner", llvm::json::Array{inner}}};
}


Stmt: MatchedStmt{

}|OpenStmt{

}

MatchedStmt:LVal T_EQUAL Exp T_SEMI {
  auto exp = stak.back();
  stak.pop_back();
  auto lval = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","BinaryOperator"},{"opcode","="},{"inner",llvm::json::Array{lval,exp}}});
}|T_SEMI{
  stak.push_back(llvm::json::Object{{"kind","NullStmt"}});
}|Exp T_SEMI{

}|Block{

}|T_IF T_L_PAREN Exp T_R_PAREN MatchedStmt T_ELSE MatchedStmt {
  auto elseStmt = stak.back();
  stak.pop_back();
  auto thenStmt = stak.back();
  stak.pop_back();
  auto ifExp = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","IfStmt"},{"inner",llvm::json::Array{ifExp,thenStmt,elseStmt}}});
}|T_WHILE T_L_PAREN Exp T_R_PAREN Stmt {
  auto loopStmt = stak.back();
  stak.pop_back();
  auto whileExp = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","WhileStmt"},{"inner",llvm::json::Array{whileExp,loopStmt}}});
}|T_BREAK T_SEMI {
  stak.push_back(llvm::json::Object{{"kind","BreakStmt"}});
}|T_CONTINUE T_SEMI {
  stak.push_back(llvm::json::Object{{"kind","ContinueStmt"}});
}|T_RETURN T_SEMI{
  stak.push_back(llvm::json::Object{{"kind", "ReturnStmt"}});
}|T_RETURN Exp T_SEMI {
  if(debug) llvm::outs()<<"return 2 stmt\n";
  if(debug) print_stack();
  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind", "ReturnStmt"},
                                   {"inner", llvm::json::Array{inner}}};
}|T_DO Block T_WHILE T_L_PAREN Exp T_R_PAREN T_SEMI {
  auto whileExp = stak.back();
  stak.pop_back();
  auto blockStmt = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","DoStmt"},{"inner",llvm::json::Array{blockStmt,whileExp}}});
}

OpenStmt: T_IF T_L_PAREN Exp T_R_PAREN Stmt {
  auto thenStmt = stak.back();
  stak.pop_back();
  auto ifExp = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","IfStmt"},{"inner",llvm::json::Array{ifExp,thenStmt}}});
}|T_IF T_L_PAREN Exp T_R_PAREN MatchedStmt T_ELSE OpenStmt {
  auto elseStmt = stak.back();
  stak.pop_back();
  auto thenStmt = stak.back();
  stak.pop_back();
  auto ifExp = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","IfStmt"},{"inner",llvm::json::Array{ifExp,thenStmt,elseStmt}}});
}


VarDecl: T_INT VarDefChain T_SEMI {
  if(debug) llvm::outs()<<"valdefchain 2 vardecl and val_def_num is "<<val_def_num<<"\n";
}

VarDefChain: VarDef{
  val_def_num = 1;
}|VarDefChain T_COMMA VarDef{
  val_def_num++;
}

VarDef: T_IDENTIFIER{
  auto name = stak.back().getAsObject()->get("value")->getAsString()->str();
  stak.back() = llvm::json::Object{{"kind", "VarDecl"}, {"name", name}};
}|T_IDENTIFIER T_EQUAL InitVal{
  auto init_val = stak.back();
  stak.pop_back();
  auto name = stak.back().getAsObject()->get("value")->getAsString()->str();
  stak.back() = llvm::json::Object{{"kind", "VarDecl"}, {"name", name},{"inner",llvm::json::Array{init_val}}};
}

InitVal: Exp{

}

FuncDef: T_INT T_IDENTIFIER T_L_PAREN T_R_PAREN Block {
  auto inner = stak.back();
  stak.pop_back();
  auto name = stak.back().getAsObject()->get("value")->getAsString()->str();
  stak.back() = llvm::json::Object{{"kind", "FunctionDecl"},
                                   {"name", name},
                                   {"inner", llvm::json::Array{inner}}};
}| T_VOID T_IDENTIFIER T_L_PAREN T_R_PAREN Block{

}

Exp : LOrExp{
  if(debug) llvm::outs()<<"LOrExp 2 Exp\n";
}

LVal : T_IDENTIFIER{
  auto ident = stak.back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.back() = llvm::json::Object{{"kind", "DeclRefExpr"},
                                   {"name", name}};
}|LVal T_L_SQUARE Exp T_R_SQUARE{
  auto exp = stak.back();
}//todo

PrimaryExp : T_L_PAREN Exp T_R_PAREN{
  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind","ParenExpr"},
  {"inner", llvm::json::Array{inner}}};
}|LVal{
  
}|Number{
  if(debug) llvm::outs()<<"number 2 primary\n";
}

UnaryExp : PrimaryExp{
  if(debug) llvm::outs()<<"primary 2 unaryexp\n";
  if(debug) print_stack();
}|T_IDENTIFIER T_L_PAREN T_R_PAREN {

}|T_PLUS UnaryExp{
  if(debug) llvm::outs()<<"UnaryExp 2 UnaryExp\n";
  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind", "UnaryOperator"},
  {"opcode",""},
  {"inner",llvm::json::Array{inner}}};
}|T_MINUS UnaryExp{
  if(debug) llvm::outs()<<"UnaryExp 2 UnaryExp\n";
  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind", "UnaryOperator"},
  {"opcode","-"},
  {"inner",llvm::json::Array{inner}}};
}|T_EXCLAIM UnaryExp{
  if(debug) llvm::outs()<<"UnaryExp 2 UnaryExp\n";
  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind", "UnaryOperator"},
  {"opcode","!"},
  {"inner",llvm::json::Array{inner}}};
};

Number : T_NUMERIC_CONSTANT{
  if(debug) llvm::outs()<<"T_NUMERIC_CONSTANT 2 number\n";
}




MulExp:
UnaryExp{
  if(debug) llvm::outs()<<"UnaryExp 2 MulExp\n";
  print_stack();
}|MulExp T_STAR UnaryExp{
  if(debug) llvm::outs()<<"MulExp 2 MulExp\n";
  if(debug) print_stack();
  auto unary_exp = stak.back();
  stak.pop_back();
  auto mul_exp = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","*"},{"inner",llvm::json::Array{mul_exp,unary_exp}}};
}|MulExp T_SLASH UnaryExp{
  if(debug) llvm::outs()<<"MulExp 2 MulExp\n";
  if(debug) print_stack();
  auto unary_exp = stak.back();
  stak.pop_back();
  auto mul_exp = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","/"},{"inner",llvm::json::Array{mul_exp,unary_exp}}};
}|MulExp T_PERCENT UnaryExp{
  if(debug) llvm::outs()<<"MulExp 2 MulExp\n";
  if(debug) print_stack();
  auto unary_exp = stak.back();
  stak.pop_back();
  auto mul_exp = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","%"},{"inner",llvm::json::Array{mul_exp,unary_exp}}};
}


AddExp: 
MulExp{
  if(debug) llvm::outs()<<"MulExp 2 AddExp\n";
}| AddExp T_PLUS MulExp{
  if(debug) llvm::outs()<<"exp1 2 AddExp\n";
  auto exp2 = stak.back();
  stak.pop_back();
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","+"},{"inner",llvm::json::Array{exp1,exp2}}};
}| AddExp T_MINUS MulExp{
  if(debug) llvm::outs()<<"exp2 2 AddExp\n";
  auto exp2 = stak.back();
  stak.pop_back();
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","-"},{"inner",llvm::json::Array{exp1,exp2}}};
}

RelExp:
AddExp{
  if(debug) llvm::outs()<<"AddExp 2 RelExp\n";
}| RelExp T_LESS AddExp{
  if(debug) llvm::outs()<<"exp1 2 RelExp\n";
  auto exp2 = stak.back();
  stak.pop_back();
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","<"},{"inner",llvm::json::Array{exp1,exp2}}};
}| RelExp T_GREATER AddExp{
  if(debug) llvm::outs()<<"exp2 2 RelExp\n";
  auto exp2 = stak.back();
  stak.pop_back();
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode",">"},{"inner",llvm::json::Array{exp1,exp2}}};
}| RelExp T_LESSEQUAL AddExp{
  if(debug) llvm::outs()<<"exp3 2 RelExp\n";
  auto exp2 = stak.back();
  stak.pop_back();
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","<="},{"inner",llvm::json::Array{exp1,exp2}}};
}| RelExp T_GREATEREQUAL AddExp{
  if(debug) llvm::outs()<<"exp4 2 RelExp\n";
  auto exp2 = stak.back();
  stak.pop_back();
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode",">="},{"inner",llvm::json::Array{exp1,exp2}}};
}

EqExp:
RelExp{

}|EqExp T_EQUALEQUAL RelExp{
  auto exp2 = stak.back();
  stak.pop_back();
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","=="},{"inner",llvm::json::Array{exp1,exp2}}};
}|EqExp T_EXCLAIMEQUAL RelExp{
  auto exp2 = stak.back();
  stak.pop_back();
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","!="},{"inner",llvm::json::Array{exp1,exp2}}};
}

LAndExp:
EqExp{

}|LAndExp T_AMPAMP EqExp{
  auto exp2 = stak.back();
  stak.pop_back();
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","&&"},{"inner",llvm::json::Array{exp1,exp2}}};
}

LOrExp: LAndExp{

}|LOrExp T_PIPEPIPE LAndExp{
  auto exp2 = stak.back();
  stak.pop_back();
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","||"},{"inner",llvm::json::Array{exp1,exp2}}};
}

ConstExp: Exp{
  if(debug) llvm::outs()<<"ConstExp 2 Exp\n";
}


%%