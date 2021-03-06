

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include "sintatico.hpp"

using namespace std;
 
 
 
char tk; //precisa ter o token lido no léxico
FILE *fp;
extern std::ifstream arq;
extern int lasttokenstart;
extern int lastnewline;
extern int linhas;
 
extern int coluna, linha;
int token(char c, FILE *fp);
 
/*int leToken() {
	char c;
        if (c=getc(fp) != EOF){
                return token(c, fp);
        }
        else
                return 0;
}*/

int leToken() {
	char c;
	int	temp;
	if (c=getc(fp) != EOF){
		temp = token(c, fp);
		std::cout << "Letra: " << c << " -=- Token: " << temp << std::endl;
		return temp;
	}
	else {
		std::cout << "End Of File" << std::endl;
		return 0;
	}
}
 
bool hasname=false;
 
int main(int argc, char *argv[]) {
        coluna = 0;
        linha = 0;
        fp=fopen(argv[1],"r");
        int coluna=0, linha=0;
        S();
        return 0;
}
 
/* S -> CMD, */
bool S() {
        return CMD();
}
 
/* CMD -> AtribBnCMD | SpaceCMD | CondCMD | TabCMD | WriteCMD | BnCMD | DeclCMD | ε */
bool CMD() {
	cout << "CMD" << endl;
        if(Attrib()){
            if(Bn()){
                return CMD();
            }
        }
        /*if(Space()){
                return CMD();
        }*/
        if(Cond()){
                return CMD();
        }
        /*if(Tab()){
                return CMD();
        }*/
        if(Write()){
                return CMD();
        }
        if(Bn()){
                return CMD();
        }
        if(Decl()){
                return CMD();
        }
        return true;
}
 
/* Decl -> local Var Bn | Var Bn | local Var = Exp Bn | Var = Exp Bn | Var = Read Bn,
FIXED::
        Decl -> local X | Var Y,
        X -> Var Z,
        Z -> Bn | W,
        Y -> Bn | W | = Read Bn,
        W -> = Exp Bn*/
/* Decl -> local X | Var Y, */
bool Decl(){
	cout << "Decl" << endl;
	cout << tk << endl;
        tk = leToken();
        if(tk == 25){
                return X();
        }
        if(Var()){
                return Y();
        }
}
/* X -> Var Z, */
bool X(){
	cout << "X" << endl;
        if (Var()){
                return Z();
        }else
                return false;
}
/* Z -> Bn | W,*/
bool Z(){
	cout << "X" << endl;
        if(Bn()){
                return true;
        }else
                return W();
}
/* Y -> Bn | W | = Read Bn, */
bool Y(){
	cout << "Y" << endl;
        if(Bn()){
                return true;
        }else{
                tk = leToken();
                if(tk == 13){
                        if(Read())
                                return Bn();
                }
        }
        return W();    
}
/*W -> = Exp Bn*/
bool W(){
        if(Exp()){
                return Bn();
        }else
                return false;
}
/* Atrib -> Declna = Exp | Declna, Atrib, Exp | Declna = Read,
Fixed::
        Attrib -> Declna Attrib2
Attrib2 -> = Attrib3 | , Attrib, Exp
Attrib3 -> Exp | Read,*/
/* Attrib -> Declna Attrib2 */
bool Attrib(){
        if(Declna()){
                return Attrib2();
        }else
                return false;
}
/* Attrib2 -> = Attrib3 | , Attrib, Exp */
bool Attrib2(){
        tk = leToken();
        if(tk == 33){
                if(Attrib()){
                        tk = leToken();
                        if(tk == 33){
                                return Exp();
                        }
                }
        }else{
                return Attrib3();
        }
}
/* Attrib3 -> Exp | Read */
bool Attrib3(){
        if (Read())
                return true;
        else {
                if (Exp())
                        return true;
        }
        return false;
}
/* Cond -> if Exp { Bn CMD } Bn | if Exp { Bn CMD } Bn else { Bn CMD } Bn,
FIXED::
        Cond -> IF,
        IF -> if Exp { Bn CMD } Bn ELSE,
        ELSE -> else { Bn CMD } Bn | ε*/
/* Cond -> IF, */
bool Cond(){
        return IF();
}
/* IF -> if Exp { Bn CMD } Bn ELSE,*/
bool IF(){
        tk = leToken();
        if(tk == 27){
                if(Exp()){
                        tk = leToken();
                        if(tk == 17){
                                if(Bn()){
                                        if(CMD()){
                                                tk = leToken();
                                                if(tk == 18){
                                                        if(Bn()){
                                                                return ELSE();
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }
}
/* ELSE -> else { Bn CMD } Bn | ε*/
bool ELSE(){
        tk = leToken();
        if(tk == 32){
                tk = leToken();
                if(tk == 17){
                        if(Bn()){
                                if(CMD()){
                                        tk = leToken();
                                        if(tk == 18){
                                                if(Bn())
                                                        return true;
                                        }
                                }
                        }
                }
        }else{
                return true;
        }
}
/* Declna -> local Var | Var, */
bool Declna(){
        tk = leToken();
        if(tk == 25){
                return Var();
        }else
                return Var();
}
/* Booleann ->  true | false, */
bool Booleann(){
        tk = leToken();
        if(tk == 31)
                return true;
        if (tk == 32)
                return false;
        return false;
}
/* Read -> io.read(), */
bool Read(){
        tk = leToken();
        if(tk == 28){
                tk = leToken();
                if(tk == 15){
                        tk = leToken();
                                if(tk == 16)
                                        return true;
                }
        }else{
                return false;
        }
}
/* Write -> io.write(Wexp) Bn, */
bool Write(){
        tk = leToken();
        if(tk == 29){
                tk = leToken();
                if(tk == 15)
                        if(Wexp())
                                tk = leToken();
                                if(tk == 16)
                                        return Bn();
        }else
                return false;
}
/* Wexp -> Wexp1,Wexp1 | Wexp1, */
bool Wexp(){
        if(Wexp1()){
                tk = leToken();
                if (tk == 35)
                        return Wexp1();
                else
                        return false;
        }else
                return Wexp1();
}
/* Wexp1 -> String | Var, */
bool Wexp1(){
        tk = leToken();
        if(tk == 23)
                return String();
        if(tk == 24)
                return Var();
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
        }else{
                tk = leToken();
                if(tk == '(') {
                        if (Exp()) {
                                tk = leToken();
                                if (tk == ')')
                                        return true;
                        }
                        return false;  
                }
                else
                        return Exp2();
        }
}
/* Exp1 -> Uop Exp | (Exp) | Exp2, */
bool Exp1(){
        if(Uop()){
                return Exp();
        }else{
                tk = leToken();
                if(tk == '(')
                        if (Exp()) {
                                tk = leToken();
                                if (tk == ')')
                                        return true;
                        }
                        return false;  
        }
        return Exp2();
}
/* Exp2 -> Num | Var | Boolean | nil, */
bool Exp2(){
        tk = leToken();
        if(tk == 22){
                return Num();
        }
        if(tk == 24){
                return Var();
        }
        if(tk == 31 || tk == 32){
                return Booleann();
        }
        if(tk == 30){
                return false;
        }
        return false;
}
/* Uop -> - | !, */
bool Uop(){
        tk = leToken();
        if(tk == 5 || tk == 19 ){
                return true;
        }else
                return false;
}
/* Bop -> ** | * | / | + | - | > | >= | < | <= | == | & | |, */
bool Bop(){
        tk = leToken();
        if(tk == 8 || tk == 7 || tk == 6 || tk == 4 || tk == 5 || tk == 9 || tk == 10
                || tk == 11 || tk == 12 || tk == 14 || tk == 20 || tk == 21){
                return true;
        }else
                return false;
}
/* Bn -> \n  */
bool Bn(){
        tk = leToken();
        if(tk == 1){
                return true;
        }else
                return false;
}
/* Var -> αVar2, */
bool Var(){
        tk = leToken();
        if(tk == 24){
                return Var2();
        }else
                return false;
}
/* Var2 -> αVar2 | Num2Var2, */
bool Var2(){
        tk = leToken();
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
bool Num(){
        tk = leToken();
        if(tk == 22){
                return true;
        }else return false;
}
/* Num2 -> κnum2 | κ, */
bool Num2(){
        tk = leToken();
        if (tk == 22){
                tk = leToken();
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
        tk = leToken();
        if(tk == 23){
                return STR();
        }else
                return false;
}
/* STR -> γSTR | ε */
bool STR() {
        return true;
}

