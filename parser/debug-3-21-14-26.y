%{
#include "parser.hh"
#include <llvm/Support/JSON.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/raw_ostream.h>
#include <stdio.h>
#include <queue>
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
auto debug_stak = true;
llvm::json::Array stak;
std::queue<llvm::json::Value> lexqueue;
int const_def_num = 0;
int val_def_num = 0;
}  //namespace
auto print_stack(){
  if(debug_stak) llvm::outs()<<"\nprintf stak\n";
  for(auto i=0;i<stak.size();i++){
    if(debug_stak) llvm::outs()<<stak[i]<<"\n";
  }
  if(debug_stak) llvm::outs()<<"\nprintf stak end\n";
  return 0;
}
auto print_msg(const char * msg){
  if(debug){
    llvm::outs()<<"\n"<<msg<<"\n";
  }
  print_stack();
}
auto yylex() {
  auto tk = wk_getline();
  auto b = tk.find("'") + 1, e = tk.rfind("'");
  auto s = tk.substr(b, e - b).str(), t = tk.substr(0, tk.find(" ")).str();
  std::string sss="yylex "+t;
  print_msg(sss.c_str());

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
    lexqueue.push(llvm::json::Object{{"value", s}});
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
  if (t == "while")
    return T_WHILE;
  if (t == "break")
    return T_BREAK;
  if (t == "continue")
    return T_CONTINUE;
  if (t == "return")
    return T_RETURN;
  if (t == "numeric_constant") {
    lexqueue.push(llvm::json::Object{{"kind", "IntegerLiteral"}, {"value", s}});
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
  debug_stak=true;
  print_stack();
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
  // auto inner = stak.back();
  // stak.pop_back();
  // stak.back().getAsObject()->get("inner")->getAsArray()->push_back(inner);
  print_msg("compunit 2 compunit");
}|CompUnitItem {
  // auto inner = stak.back();
  // stak.back() = llvm::json::Object{{"kind", "TranslationUnitDecl"},
  //                                  {"inner", llvm::json::Array{inner}}};
  print_msg("compunititem 2 compunit");
}
CompUnitItem: 
VarDecl {
  print_msg("vardecl 2 compunititem");
}
|FuncDef {
  print_msg("funcdef 2 compunititem");
}

Decl: ConstDecl{
  // auto json_inner = llvm::json::Array{};
  // for(auto i = 0; i < const_def_num; i++){
  //   json_inner.push_back(stak.back());
  //   stak.pop_back();
  // }
  // stak.push_back(llvm::json::Object{{"kind", "DeclStmt"},
  //                                  {"inner", llvm::json::Array{}}});
  // auto array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  // for(auto i = const_def_num-1; i >= 0; i--){
  //   array_inner->push_back(json_inner[i]);
  // }
  print_msg("constdecl 2 decl");
  
}| VarDecl{
  // if(debug) llvm::outs()<<"vardecl 2 decl\n";
  // if(debug) print_stack();
  // auto json_inner = llvm::json::Array{};
  // for(auto i = 0; i < val_def_num; i++){
  //   json_inner.push_back(stak.back());
  //   stak.pop_back();
  // }
  // stak.push_back(llvm::json::Object{{"kind", "DeclStmt"},
  //                                  {"inner", llvm::json::Array{}}});
  // auto array_inner = stak.back().getAsObject()->get("inner")->getAsArray();
  // for(auto i = val_def_num-1; i >= 0; i--){
  //   array_inner->push_back(json_inner[i]);
  // }
  print_msg("vardecl 2 decl");
}

ConstDecl: T_CONST T_INT ConstDefChain T_SEMI{
  print_msg("int 2 constdecl");
}|T_CONST T_CHAR ConstDefChain T_SEMI{
  print_msg("char 2 constdecl");
}|T_CONST T_LONGLONG ConstDefChain T_SEMI{
  print_msg("longlong 2 constdecl");
}

ConstDefChain: ConstDef{
  // if(debug) llvm::outs()<<"constdef first\n";
  // const_def_num = 1;
  print_msg("constdef 2 constdefchain");
}|ConstDefChain T_COMMA ConstDef{
  // if(debug) llvm::outs()<<"constdef second\n";
  // const_def_num++;
  print_msg("constdefchain 2 constdefchain");
}

ConstDef: T_IDENTIFIER T_EQUAL ConstInitVal{
  // auto exp2 = stak.back();
  // stak.pop_back();
  // auto exp1 = stak.back();
  // auto exp1_name = exp1.getAsObject()->get("value")->getAsString()->str();
  // stak.back() = llvm::json::Object{{"kind", "VarDecl"},
  //                                 {"name",exp1_name},
  //                                 {"inner", llvm::json::Array{exp2}}};
  print_msg("ident = init 2 constdef");
}

ConstInitVal: ConstExp{
  // if(debug) llvm::outs()<<"constexp 2 ConstInitVal\n";
  print_msg("constexp 2 constinitval");
}


Block: T_L_BRACE T_R_BRACE{
  stak.push_back(llvm::json::Object{{"kind", "CompoundStmt"}});
  print_msg("empty 2 block");
}|T_L_BRACE BlockItemChain T_R_BRACE {
  // if(debug) llvm::outs()<<"blockitem 2 block\n";
  print_msg("noempty 2 block");
}

BlockItemChain:BlockItem{
  print_msg("blockitem 2 blockitemchain");
}|BlockItemChain Stmt{
  // auto stmt = stak.back();
  // stak.pop_back();
  // auto be_block_item = stak.back();
  // stak.back().getAsObject()->get("inner")->getAsArray()->push_back(stmt);
  print_msg("chain stmt 2 blockitemchain");
}|BlockItemChain Decl{
  // auto decl = stak.back();
  // stak.pop_back();
  // auto be_block_item = stak.back();
  // stak.back().getAsObject()->get("inner")->getAsArray()->push_back(decl);
  print_msg("chain decl 2 blockitemchain");
}

BlockItem: 
Stmt {
  // auto inner = stak.back();
  // stak.back() = llvm::json::Object{{"kind", "CompoundStmt"},
  //                                  {"inner", llvm::json::Array{inner}}};
  print_msg("stmt 2 blockitem");
}|Decl{
  // auto inner = stak.back();
  // stak.back() = llvm::json::Object{{"kind", "CompoundStmt"},
  //                                  {"inner", llvm::json::Array{inner}}};
  print_msg("decl 2 blockitem");
}


//todo
Stmt: MatchedStmt{
  print_msg("match 2 stmt");
}|OpenStmt{
  print_msg("open 2 stmt");
}

MatchedStmt:LVal T_EQUAL Exp T_SEMI {
  // auto exp = stak.back();
  // stak.pop_back();
  // auto lval = stak.back();
  // stak.pop_back();
  // stak.push_back(llvm::json::Object{{"kind","BinaryOperator"},{"opcode","="},{"inner",llvm::json::Array{lval,exp}}});
  print_msg("lval = exp 2 MatchedStmt");
}|T_SEMI{
  // stak.push_back(llvm::json::Object{{"kind","NullStmt"}});
  print_msg("empty 2 MatchedStmt");
}|Exp T_SEMI{
  print_msg("exp 2 MatchedStmt");
}|Block{
  print_msg("block 2 MatchedStmt");
}|T_IF T_L_PAREN Exp T_R_PAREN MatchedStmt T_ELSE MatchedStmt {
  // todo
  // auto elseStmt = stak.back();
  // stak.pop_back();
  // auto thenStmt = stak.back();
  // stak.pop_back();
  // auto ifExp = stak.back();
  // stak.pop_back();
  // stak.push_back(llvm::json::Object{{"kind","IfStmt"},{"inner",llvm::json::Array{ifExp,thenStmt,elseStmt}}});
  print_msg("if match else match 2 MatchedStmt");
}|T_RETURN T_SEMI{
  // stak.push_back(llvm::json::Object{{"kind", "ReturnStmt"}});
  print_msg("return empty 2 MatchedStmt");
}|T_RETURN Exp T_SEMI {
  // if(debug) llvm::outs()<<"return 2 stmt\n";
  // if(debug) print_stack();
  // auto inner = stak.back();
  // stak.back() = llvm::json::Object{{"kind", "ReturnStmt"},
  //                                  {"inner", llvm::json::Array{inner}}};
  print_msg("return exp 2 MatchedStmt");
}

OpenStmt: T_IF T_L_PAREN Exp T_R_PAREN Stmt {
  // todo
  auto thenStmt = stak.back();
  stak.pop_back();
  auto ifExp = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","IfStmt"},{"inner",llvm::json::Array{ifExp,thenStmt}}});
  print_msg("if exp stmt 2 OpenStmt");
}|T_IF T_L_PAREN Exp T_R_PAREN MatchedStmt T_ELSE OpenStmt {
  // todo
  // auto elseStmt = stak.back();
  // stak.pop_back();
  // auto thenStmt = stak.back();
  // stak.pop_back();
  // auto ifExp = stak.back();
  // stak.pop_back();
  // stak.push_back(llvm::json::Object{{"kind","IfStmt"},{"inner",llvm::json::Array{ifExp,thenStmt,elseStmt}}});
  print_msg("if exp match else open 2 OpenStmt");
}

//todo

VarDecl: T_INT VarDefChain T_SEMI {
  // if(debug) llvm::outs()<<"valdefchain 2 vardecl and val_def_num is "<<val_def_num<<"\n";
  print_msg("vardefchain 2 vardecl");
}

VarDefChain: VarDef{
  // val_def_num = 1;
  print_msg("vardef 2 chain");
}|VarDefChain T_COMMA VarDef{
  // val_def_num++;
  print_msg("vardefchain 2 vardefchain");
}

VarDef: T_IDENTIFIER{
  // auto name = stak.back().getAsObject()->get("value")->getAsString()->str();
  // stak.back() = llvm::json::Object{{"kind", "VarDecl"}, {"name", name}};
  print_msg("ident 2 vardef");
}|T_IDENTIFIER T_EQUAL InitVal{
  // auto init_val = stak.back();
  // stak.pop_back();
  // auto name = stak.back().getAsObject()->get("value")->getAsString()->str();
  // stak.back() = llvm::json::Object{{"kind", "VarDecl"}, {"name", name},{"inner",llvm::json::Array{init_val}}};
  print_msg("ident = init 2 vardef");
}

InitVal: Exp{
  print_msg("exp 2 initval");
}

FuncDef: T_INT T_IDENTIFIER T_L_PAREN T_R_PAREN Block {
  // auto inner = stak.back();
  // stak.pop_back();
  // auto name = stak.back().getAsObject()->get("value")->getAsString()->str();
  // stak.back() = llvm::json::Object{{"kind", "FunctionDecl"},
  //                                  {"name", name},
  //                                  {"inner", llvm::json::Array{inner}}};
  print_msg("int ident() {} 2 funcdef");
}

Exp : LOrExp{
  // if(debug) llvm::outs()<<"LOrExp 2 Exp\n";
  print_msg("lorexp 2 exp");
}

LVal : T_IDENTIFIER{
  // auto ident = stak.back();
  // auto name = ident.getAsObject()->get("value")->getAsString()->str();
  // stak.back() = llvm::json::Object{{"kind", "DeclRefExpr"},
  //                                  {"name", name}};
  print_msg("ident 2 lval");
}|LVal T_L_SQUARE Exp T_R_SQUARE{
  // auto exp = stak.back();
  print_msg("lval [exp] 2 lval");
}//todo

PrimaryExp : T_L_PAREN Exp T_R_PAREN{
  // auto inner = stak.back();
  // stak.back() = llvm::json::Object{{"kind","ParenExpr"},
  // {"inner", llvm::json::Array{inner}}};
  print_msg("(exp) 2 prmaryexp");
}|LVal{
  print_msg("lval 2 primaryexp");
}|Number{
  // if(debug) llvm::outs()<<"number 2 primary\n";
  print_msg("number 2 primaryexp");
}

UnaryExp : PrimaryExp{
  // if(debug) llvm::outs()<<"primary 2 unaryexp\n";
  // if(debug) print_stack();
  print_msg("primaryexp 2 unaryexp");
}|T_PLUS UnaryExp{
  // if(debug) llvm::outs()<<"UnaryExp 2 UnaryExp\n";
  // auto inner = stak.back();
  // stak.back() = llvm::json::Object{{"kind", "UnaryOperator"},
  // {"opcode",""},
  // {"inner",llvm::json::Array{inner}}};
  print_msg("+ UnaryExp 2 UnaryExp");
}|T_MINUS UnaryExp{
  // if(debug) llvm::outs()<<"UnaryExp 2 UnaryExp\n";
  // auto inner = stak.back();
  // stak.back() = llvm::json::Object{{"kind", "UnaryOperator"},
  // {"opcode","-"},
  // {"inner",llvm::json::Array{inner}}};
  print_msg("- UnaryExp 2 UnaryExp");
}|T_EXCLAIM UnaryExp{
  // if(debug) llvm::outs()<<"UnaryExp 2 UnaryExp\n";
  // auto inner = stak.back();
  // stak.back() = llvm::json::Object{{"kind", "UnaryOperator"},
  // {"opcode","!"},
  // {"inner",llvm::json::Array{inner}}};
  print_msg("! UnaryExp 2 UnaryExp");
};

Number : T_NUMERIC_CONSTANT{
  // if(debug) llvm::outs()<<"T_NUMERIC_CONSTANT 2 number\n";
  while(!lexqueue.empty()){
    llvm::json::Value lexfront = lexqueue.front();
    lexqueue.pop();
    stak.push_back(lexfront);
  }
  print_msg("T_NUMERIC_CONSTANT 2 number");
}




MulExp:
UnaryExp{
  // if(debug) llvm::outs()<<"UnaryExp 2 MulExp\n";
  // print_stack();
  print_msg("UnaryExp 2 MulExp");
}|MulExp T_STAR UnaryExp{
  // if(debug) llvm::outs()<<"MulExp 2 MulExp\n";
  // if(debug) print_stack();
  // auto unary_exp = stak.back();
  // stak.pop_back();
  // auto mul_exp = stak.back();
  // stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","*"},{"inner",llvm::json::Array{mul_exp,unary_exp}}};
  print_msg("mulexp * UnaryExp 2 MulExp");
}|MulExp T_SLASH UnaryExp{
  // if(debug) llvm::outs()<<"MulExp 2 MulExp\n";
  // if(debug) print_stack();
  // auto unary_exp = stak.back();
  // stak.pop_back();
  // auto mul_exp = stak.back();
  // stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","/"},{"inner",llvm::json::Array{mul_exp,unary_exp}}};
  print_msg("mulexp / UnaryExp 2 MulExp");
}|MulExp T_PERCENT UnaryExp{
  // if(debug) llvm::outs()<<"MulExp 2 MulExp\n";
  // if(debug) print_stack();
  // auto unary_exp = stak.back();
  // stak.pop_back();
  // auto mul_exp = stak.back();
  // stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","%"},{"inner",llvm::json::Array{mul_exp,unary_exp}}};
  print_msg("mulexp \% UnaryExp 2 MulExp");
}


AddExp: 
MulExp{
  // if(debug) llvm::outs()<<"MulExp 2 AddExp\n";
  print_msg("mulexp  2 addExp");
}| AddExp T_PLUS MulExp{
  // if(debug) llvm::outs()<<"exp1 2 AddExp\n";
  auto exp2 = stak.back();
  stak.pop_back();
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","+"},{"inner",llvm::json::Array{exp1,exp2}}};
  print_msg("addexp + mulexp 2 addexp");
}| AddExp T_MINUS MulExp{
  // if(debug) llvm::outs()<<"exp2 2 AddExp\n";
  // auto exp2 = stak.back();
  // stak.pop_back();
  // auto exp1 = stak.back();
  // stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","-"},{"inner",llvm::json::Array{exp1,exp2}}};
  print_msg("addexp - mulexp 2 addexp");
}

RelExp:
AddExp{
  // if(debug) llvm::outs()<<"AddExp 2 RelExp\n";
  print_msg("addexp 2 RelExp");
}| RelExp T_LESS AddExp{
  // if(debug) llvm::outs()<<"exp1 2 RelExp\n";
  // auto exp2 = stak.back();
  // stak.pop_back();
  // auto exp1 = stak.back();
  // stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","<"},{"inner",llvm::json::Array{exp1,exp2}}};
  print_msg("RelExp < addexp 2 RelExp");
}| RelExp T_GREATER AddExp{
  // if(debug) llvm::outs()<<"exp2 2 RelExp\n";
  auto exp2 = stak.back();
  stak.pop_back();
  auto exp1 = stak.back();
  stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode",">"},{"inner",llvm::json::Array{exp1,exp2}}};
  print_msg("RelExp > addexp 2 RelExp");
}| RelExp T_LESSEQUAL AddExp{
  // if(debug) llvm::outs()<<"exp3 2 RelExp\n";
  // auto exp2 = stak.back();
  // stak.pop_back();
  // auto exp1 = stak.back();
  // stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","<="},{"inner",llvm::json::Array{exp1,exp2}}};
  print_msg("RelExp <= addexp 2 RelExp");
}| RelExp T_GREATEREQUAL AddExp{
  // if(debug) llvm::outs()<<"exp4 2 RelExp\n";
  // auto exp2 = stak.back();
  // stak.pop_back();
  // auto exp1 = stak.back();
  // stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode",">="},{"inner",llvm::json::Array{exp1,exp2}}};
  print_msg("RelExp >= addexp 2 RelExp");
}

EqExp:
RelExp{
  print_msg("RelExp 2 eqexp");
}|EqExp T_EQUALEQUAL RelExp{
  // auto exp2 = stak.back();
  // stak.pop_back();
  // auto exp1 = stak.back();
  // stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","=="},{"inner",llvm::json::Array{exp1,exp2}}};
  print_msg("eqexp == RelExp 2 eqexp");
}|EqExp T_EXCLAIMEQUAL RelExp{
  // auto exp2 = stak.back();
  // stak.pop_back();
  // auto exp1 = stak.back();
  // stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","!="},{"inner",llvm::json::Array{exp1,exp2}}};
  print_msg("eqexp != RelExp 2 eqexp");
}

LAndExp:
EqExp{
  print_msg("eqexp 2 LAndExp");
}|LAndExp T_AMPAMP EqExp{
  // auto exp2 = stak.back();
  // stak.pop_back();
  // auto exp1 = stak.back();
  // stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","&&"},{"inner",llvm::json::Array{exp1,exp2}}};
  print_msg("landexp && eqexp 2 LAndExp");
}

LOrExp: LAndExp{
  print_msg("landexp  2 lorexp");
}|LOrExp T_PIPEPIPE LAndExp{
  // auto exp2 = stak.back();
  // stak.pop_back();
  // auto exp1 = stak.back();
  // stak.back() = llvm::json::Object{{"kind","BinaryOperator"},{"opcode","||"},{"inner",llvm::json::Array{exp1,exp2}}};
  print_msg("lorexp || landexp 2 lorexp");
}

ConstExp: Exp{
  // if(debug) llvm::outs()<<"ConstExp 2 Exp\n";
  print_msg("exp 2 constexp");
}


%%