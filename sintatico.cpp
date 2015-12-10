#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include "sintatico.hpp"
#include "lexico.hpp"

char tk; //precisa ter o token lido no léxico
extern std::ifstream arq;
extern int lasttokenstart;
extern int lastnewline;
extern int linhas;
bool hasname=false;

int main(int argc, char *argv[]) {
	return 0;
}

/* S -> CMD, */
bool S() {
	return CMD();
}

/* CMD -> AtribBnCMD | SpaceCMD | CondCMD | TabCMD | WriteCMD | BnCMD | DeclCMD | ε */
bool CMD() {
	
}

/* Decl -> local Var Bn | Var Bn | local Var = Exp Bn | Var = Exp Bn | Var = Read Bn, 
FIXED::
	Decl -> local X | Var Y,
	X -> Var Z,
	Z -> Bn | W,
	Y -> Bn | W | = Read Bn,
	W -> = Exp Bn*/

/* Atrib -> Declna = Exp | Declna, Atrib, Exp | Declna = Read, 
Fixed::
	Attrib -> Declna Attrib2
Attrib2 -> = Attrib3 | , Attrib, Exp
Attrib3 -> Exp | Read,*/

/* Cond -> if Exp { Bn CMD } Bn | if Exp { Bn CMD } Bn else { Bn CMD } Bn, 
FIXED::
	Cond -> IF,
	IF -> if Exp { Bn CMD } Bn ELSE
	ELSE -> else { Bn CMD } Bn | ε*/
/* Cond -> IF, */
bool Cond(){

}
/* Declna -> local Var | Var, */
bool Declna(){
	if(tk == 25){
		return Var();
	}else
		return Var();
}
/* Booleann ->  true | false, */
bool Booleann(){
	if(tk == 31)
		return true;
	if (tk == 32)
		return false;
}
/* Read -> io.read(), */
bool Read(){
	if(tk == 28){
		tk = token(char c, FILE *fp);
		if(tk == 15){
			tk = token(char c, FILE *fp);
				if(tk == 16)
					return true;
		}
	}else{
		return false;
	}
}
/* Write -> io.write(Wexp) Bn, */
bool Write(){
	if(tk == 29){
		tk = token(char c, FILE *fp);
		if(tk == 15)
			if(Wexp())
				tk = token(char c, FILE *fp);
				if(tk == 16)
					return Bn();
	}else
		return false;
}
/* Wexp -> Wexp1,Wexp1 | Wexp1, */
bool Wexp(){
	if(Wexp1){
		if (tk == 35){
			return Wexp1();
		else
			return false;
	}else
		return Wexp1();
}
/* Wexp1 -> String | Var, */
bool Wexp1(){
	if(tk == 23)
		return String();
	if(tk == 24)
		return Var();
	else
		return false;
}
/* Exp -> Uop Exp | Exp1 Bop Exp1 | (Exp) | Exp2, */
bool Exp(){
	if(Uop()){
		return Exp();
	}else if(Exp1()){
		if(Bop())
			return Exp1();
		return false;
	}else if(tk == '('){
		if (exp())
			if (tk == ')')
				return true;
		return false;
	}else
		Exp2();
}
/* Exp1 -> Uop Exp | (Exp) | Exp2, */
bool Exp1(){
	if(Uop()){
		return Exp();
	}else if(tk == '('){
		if (exp())
			if (tk == ')')
				return true;
		return false;
	}else
		return Exp2();
}
/* Exp2 -> Num | Var | Boolean | nil, */
bool Exp2(){
	if(tk == 22){
		return Num();
	}else if(tk == 24){
		return Var();
	}else if(tk == 31 || tk == 32){
		return Booleann();
	}else if(tk == 30){
		return false;
	}else
		return false;
}
/* Uop -> - | !, */
bool Uop(){
	if(tk == 5 || tk == 19 ){
		return true;
	}else
		return false;
}
/* Bop -> ** | * | / | + | - | > | >= | < | <= | == | & | |, */
bool Bop(){
	if(tk == 8 || tk == 7 || tk == 6 || tk == 4 || tk == 5 || tk == 9 || tk == 10 
		|| tk == 11 || tk == 12 || tk == 14 || tk == 20 || tk == 21){
		return true;
	}else
		return false;
}
/* Bn -> \n  */
bool Bn(){
	if(tk == 1){
		return true;
	}else
		return false;
}
/* Var -> αVar2, */
bool Var(){
	if(tk == 24){
		return Var2();
	}else
		return false;
}
/* Var2 -> αVar2 | Num2Var2, */
bool Var2(){
	if(tk == 24){
		return Var2();
	}else if(Num2()){
		return Var2();
	}else
		return false;
}
/* Num -> .kNum | .Num2 | k, */
/*bool Num(){
	if (tk == 33){
		tk = token(char c, FILE *fp);
		if (tk == 22){
			return Num();
		}else
			return Num2();
	}else if(tk == 22){
		return true;
	}else
		return false;
}*/
Num(){ 
	if(tk == 22){ 
		return true; 
	}else return false; 
}
/* Num2 -> κnum2 | κ, */
bool Num2(){
	if (tk == 22){
		tk = token(char c, FILE *fp);
		if (tk == 22){
			return Num2();
		}else{
			return true;
		}
	}else
		return false;
}
/* String -> "STR", */
bool String(){
	if(tk == 23){
		return STR();
	}else
		return false;
}
/* STR -> γSTR | ε */
bool STR() {
	return true;
}

