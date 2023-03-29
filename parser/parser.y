%{
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
int global_type_decl = 0;
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
    float fffnum;
    if(s.find(".")!=std::string::npos||s.find("e")!=std::string::npos||s.find("E")!=std::string::npos||s.find("p")!=std::string::npos||s.find("P")!=std::string::npos){
      sscanf(s.c_str(),"%f",&fffnum);
      lexStack.push_back(llvm::json::Object{{"kind", "FloatLiteral"}, {"value", std::to_string(fffnum)}});
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
%}
%token T_CONST
%token T_COMMA
%token T_SEMI
%token T_FLOAT
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
}|CompUnitItem {
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
CompUnitItem: 
Decl {
  global_decl = true;
}
|FuncDef {}

Decl: ConstDecl{
  
}| VarDecl{

}| FuncDecl{

}

ConstDecl: T_CONST T_INT ConstDefChain T_SEMI{
  global_type_decl = TYPE_INT;
}|T_CONST T_CHAR ConstDefChain T_SEMI{
  
}|T_CONST T_LONGLONG ConstDefChain T_SEMI{
  
}|T_CONST T_FLOAT ConstDefChain T_SEMI{
  // todo
  global_type_decl = TYPE_FLOAT;
}

ConstExpChain:T_L_SQUARE ConstExp T_R_SQUARE {
  // 
  lvalStack.pop();
  typeStack.pop();
  stak.pop_back();
}| ConstExpChain T_L_SQUARE ConstExp T_R_SQUARE{
  // 
  lvalStack.pop();
  typeStack.pop();
  stak.pop_back();
}

ConstDefChain: ConstDef{
  if(debug) llvm::outs()<<"constdef first\n";
  def_num = 1;
}|ConstDefChain T_COMMA ConstDef{
  if(debug) llvm::outs()<<"constdef second\n";
  def_num++;
}

ConstDef: T_IDENTIFIER T_EQUAL ConstInitVal{
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
}|T_IDENTIFIER ConstExpChain T_EQUAL ConstInitVal{
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

ConstInitVal: ConstExp{
  // 
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
}| T_L_BRACE T_R_BRACE {
  // 
  stak.push_back(llvm::json::Object{{"kind", "InitListExpr"}});
  init_stak_level = 1;
  initStak.push_back(llvm::json::Object{{"value",init_stak_level}});
}| T_L_BRACE ConstInitValChain T_R_BRACE {
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

ConstInitValChain: ConstInitVal {
  // 

}|ConstInitValChain T_COMMA ConstInitVal {
  // 
}


VarDecl: T_INT VarDefChain T_SEMI {
  if(debug) llvm::outs()<<"valdefchain 2 vardecl and def_num is "<<def_num<<"\n";
  global_type_decl = TYPE_INT;
}| T_FLOAT VarDefChain T_SEMI {
  // todo
  global_type_decl = TYPE_FLOAT;
  if(debug) llvm::outs()<<"valdefchain 2 vardecl and def_num is "<<def_num<<"\n";
}

VarDefChain: VarDef{
  def_num = 1;
}|VarDefChain T_COMMA VarDef{
  def_num++;
}

VarDef: T_IDENTIFIER{
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "VarDecl"}, {"name", name}});
}|T_IDENTIFIER T_EQUAL InitVal{
  // 
  initStak.pop_back();
  auto init_val = stak.back();
  stak.pop_back();
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "VarDecl"}, {"name", name},{"inner",llvm::json::Array{init_val}}});
}|T_IDENTIFIER ConstExpChain {
  // 
  // to compute constexp
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "VarDecl"}, {"name", name}});
}|T_IDENTIFIER ConstExpChain T_EQUAL InitVal{
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


InitVal: Exp{
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
}| T_L_BRACE T_R_BRACE {
  // 
  if(debug) llvm::outs()<<"empty 2 InitVal\n";
  if(debug) print_stack();
  stak.push_back(llvm::json::Object{{"kind", "InitListExpr"}});
  init_stak_level = 1;
  initStak.push_back(llvm::json::Object{{"value",init_stak_level}});
}| T_L_BRACE InitValChain T_R_BRACE {
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

InitValChain: InitVal {
  // 
  if(debug) llvm::outs()<<"initval 2 initvalchain\n";
  if(debug) print_stack();
}|InitValChain T_COMMA InitVal {
  // 
  if(debug) llvm::outs()<<"initvalchain 2 initvalchain\n";
  if(debug) print_stack();
}

FuncDecl: T_INT T_IDENTIFIER T_L_PAREN T_R_PAREN T_SEMI {
  global_type_decl = TYPE_INT;
  def_num = 1;
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                    {"name", name}});
  ident2type[name] = TYPE_INT;
}| T_VOID T_IDENTIFIER T_L_PAREN T_R_PAREN T_SEMI{
  def_num = 1;
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                    {"name", name}});
}| T_FLOAT T_IDENTIFIER T_L_PAREN T_R_PAREN T_SEMI{
  global_type_decl = TYPE_FLOAT;
  // todo
  def_num = 1;
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                    {"name", name}});
  ident2type[name] = TYPE_FLOAT;
}| T_INT T_IDENTIFIER T_L_PAREN FuncFParams T_R_PAREN T_SEMI {
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
}| T_VOID T_IDENTIFIER T_L_PAREN FuncFParams T_R_PAREN T_SEMI{
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
}| T_FLOAT T_IDENTIFIER T_L_PAREN FuncFParams T_R_PAREN T_SEMI{
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

FuncDef: T_INT T_IDENTIFIER T_L_PAREN T_R_PAREN Block {
  global_type_decl = TYPE_INT;
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto inner = stak.back();
  stak.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                    {"name", name},
                                    {"inner", llvm::json::Array{inner}}});
  ident2type[name] = TYPE_INT;
}| T_VOID T_IDENTIFIER T_L_PAREN T_R_PAREN Block{
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto inner = stak.back();
  stak.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                    {"name", name},
                                    {"inner", llvm::json::Array{inner}}});
}| T_FLOAT T_IDENTIFIER T_L_PAREN T_R_PAREN Block{
  //todo
  global_type_decl = TYPE_FLOAT;
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto inner = stak.back();
  stak.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind", "FunctionDecl"},
                                    {"name", name},
                                    {"inner", llvm::json::Array{inner}}});
  ident2type[name] = TYPE_FLOAT;
}| T_INT T_IDENTIFIER T_L_PAREN FuncFParams T_R_PAREN Block {
  global_type_decl = TYPE_INT;
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
  ident2type[name] = TYPE_INT;
}| T_VOID T_IDENTIFIER T_L_PAREN FuncFParams T_R_PAREN Block{
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
}| T_FLOAT T_IDENTIFIER T_L_PAREN FuncFParams T_R_PAREN Block{
  //todo
  global_type_decl = TYPE_FLOAT;
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
  ident2type[name] = TYPE_FLOAT;
}

FuncFParams : FuncFParam {

  func_FPara_num = 1;

}| FuncFParams T_COMMA FuncFParam{

  func_FPara_num++;
}

FuncFParam : T_INT T_IDENTIFIER{

  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}|T_CHAR T_IDENTIFIER{

  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}|T_LONGLONG T_IDENTIFIER{

  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}|T_FLOAT T_IDENTIFIER{
  //todo
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}|T_INT T_IDENTIFIER ArrayFuncFParam{
  // 

  auto ArrayFuncFParam = stak.back();
  stak.pop_back();
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}|T_CHAR T_IDENTIFIER ArrayFuncFParam{
  // 

  auto ArrayFuncFParam = stak.back();
  stak.pop_back();
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}|T_LONGLONG T_IDENTIFIER ArrayFuncFParam{

  // 
  auto ArrayFuncFParam = stak.back();
  stak.pop_back();
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}|T_FLOAT T_IDENTIFIER ArrayFuncFParam{
  //todo
  // 
  auto ArrayFuncFParam = stak.back();
  stak.pop_back();
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","ParmVarDecl"},{"name",name}});
}

ArrayFuncFParam: T_L_SQUARE T_R_SQUARE {
  // 
  stak.push_back(llvm::json::Object{{"kind","ArrayFuncFParam"}});
}|ArrayFuncFParam T_L_SQUARE ConstExp T_R_SQUARE {
  // 
  lvalStack.pop();
  typeStack.pop();

  auto constExp = stak.back();
  stak.pop_back();
  auto ArrayFuncFParam = stak.back();
  stak.pop_back();
  stak.push_back(llvm::json::Object{{"kind","ArrayFuncFParam"}});
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

BlockItem: 
Stmt {
  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind", "CompoundStmt"},
                                    {"inner", llvm::json::Array{inner}}};
}|Decl{
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


Stmt: MatchedStmt{

}|OpenStmt{

}

MatchedStmt:LVal T_EQUAL Exp T_SEMI {
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
}|T_SEMI{
  stak.push_back(llvm::json::Object{{"kind","NullStmt"}});
}|Exp T_SEMI{
  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  typeStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }
}|Block{

}|T_IF T_L_PAREN Exp T_R_PAREN MatchedStmt T_ELSE MatchedStmt {
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
}|T_WHILE T_L_PAREN Exp T_R_PAREN Stmt {
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
}|T_BREAK T_SEMI {
  stak.push_back(llvm::json::Object{{"kind","BreakStmt"}});
}|T_CONTINUE T_SEMI {
  stak.push_back(llvm::json::Object{{"kind","ContinueStmt"}});
}|T_RETURN T_SEMI{
  stak.push_back(llvm::json::Object{{"kind", "ReturnStmt"}});
}|T_RETURN Exp T_SEMI {
  if(debug) llvm::outs()<<"return 2 stmt\n";
  if(debug) print_stack();

  bool lval2rval = lvalStack.top();
  lvalStack.pop();
  typeStack.pop();
  if(lval2rval){
    auto rvalexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rvalexp}}};
  }

  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind", "ReturnStmt"},
                                    {"inner", llvm::json::Array{inner}}};
}|T_DO Block T_WHILE T_L_PAREN Exp T_R_PAREN T_SEMI {

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

OpenStmt: T_IF T_L_PAREN Exp T_R_PAREN Stmt {
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
}|T_IF T_L_PAREN Exp T_R_PAREN MatchedStmt T_ELSE OpenStmt {
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





Exp : LOrExp{
  if(debug) llvm::outs()<<"LOrExp 2 Exp\n";
}

LVal : T_IDENTIFIER{
  auto ident = lexStack.back();
  lexStack.pop_back();
  auto name = ident.getAsObject()->get("value")->getAsString()->str();
  stak.push_back(llvm::json::Object{{"kind","DeclRefExpr"},{"name",name}});
  
  lvalStack.push(true);
  typeStack.push(ident2type[name]);
}|LVal T_L_SQUARE Exp T_R_SQUARE{
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

}//

PrimaryExp : T_L_PAREN Exp T_R_PAREN{
  auto inner = stak.back();
  stak.back() = llvm::json::Object{{"kind","ParenExpr"},
  {"inner", llvm::json::Array{inner}}};
}|LVal{
  // 
}|Number{
  if(debug) llvm::outs()<<"number 2 primary\n";
}

UnaryExp : PrimaryExp{
  if(debug) llvm::outs()<<"primary 2 unaryexp\n";
  if(debug) print_stack();
}|T_IDENTIFIER T_L_PAREN T_R_PAREN {
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
}|T_IDENTIFIER T_L_PAREN FuncRParams T_R_PAREN {

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
}|T_PLUS UnaryExp{
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
}|T_MINUS UnaryExp{
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
}|T_EXCLAIM UnaryExp{
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
};

Number : T_NUMERIC_CONSTANT{
  auto number = lexStack.back();
  lexStack.pop_back();
  stak.push_back(number);
  if(debug) llvm::outs()<<"T_NUMERIC_CONSTANT 2 number\n";

  lvalStack.push(false);
}


FuncRParams : Exp{
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
}| FuncRParams T_COMMA Exp{
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



MulExp:
UnaryExp{
  if(debug) llvm::outs()<<"UnaryExp 2 MulExp\n";
  print_stack();
}|MulExp T_STAR UnaryExp{
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

  if((type1==1||type1==2)&&type2==0){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==1||type2==2)&&type1==0){
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
}|MulExp T_SLASH UnaryExp{
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

  if((type1==1||type1==2)&&type2==0){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==1||type2==2)&&type1==0){
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
}|MulExp T_PERCENT UnaryExp{
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

  if((type1==1||type1==2)&&type2==0){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==1||type2==2)&&type1==0){
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


AddExp: 
MulExp{
  if(debug) llvm::outs()<<"MulExp 2 AddExp\n";
}| AddExp T_PLUS MulExp{
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

  if((type1==1||type1==2)&&type2==0){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==1||type2==2)&&type1==0){
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
}| AddExp T_MINUS MulExp{
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

  if((type1==1||type1==2)&&type2==0){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==1||type2==2)&&type1==0){
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

RelExp:
AddExp{
  if(debug) llvm::outs()<<"AddExp 2 RelExp\n";
}| RelExp T_LESS AddExp{
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

  if((type1==1||type1==2)&&type2==0){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==1||type2==2)&&type1==0){
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
}| RelExp T_GREATER AddExp{
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

  if((type1==1||type1==2)&&type2==0){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==1||type2==2)&&type1==0){
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

}| RelExp T_LESSEQUAL AddExp{
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

  if((type1==1||type1==2)&&type2==0){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==1||type2==2)&&type1==0){
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
}| RelExp T_GREATEREQUAL AddExp{
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

  if((type1==1||type1==2)&&type2==0){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==1||type2==2)&&type1==0){
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

EqExp:
RelExp{

}|EqExp T_EQUALEQUAL RelExp{
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

  if((type1==1||type1==2)&&type2==0){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==1||type2==2)&&type1==0){
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
}|EqExp T_EXCLAIMEQUAL RelExp{
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

  if((type1==1||type1==2)&&type2==0){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==1||type2==2)&&type1==0){
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

LAndExp:
EqExp{

}|LAndExp T_AMPAMP EqExp{
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

  if((type1==1||type1==2)&&type2==0){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==1||type2==2)&&type1==0){
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

LOrExp: LAndExp{

}|LOrExp T_PIPEPIPE LAndExp{
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

  if((type1==1||type1==2)&&type2==0){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  auto exp2 = stak.back();
  stak.pop_back();
  if(lval2rval1){
    auto rexp = stak.back();
    stak.back() = llvm::json::Object{{"kind","ImplicitCastExpr"},{"inner",llvm::json::Array{rexp}}};
  }

  if((type2==1||type2==2)&&type1==0){
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

ConstExp: Exp{
  if(debug) llvm::outs()<<"ConstExp 2 Exp\n";
}


%%