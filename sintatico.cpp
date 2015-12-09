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

/* Q0 -> lQ44 | {-}Q44 | ""Q | \tQ | (Q | \Q | +Q | -Q | *Q62 | "Q60 | nQ58 |
	       )Q | {Q | iQ | }Q | |Q | &Q | <Q50 | >Q48 | =Q46 | \nQ */
bool Q0(){
	if(tk == '""'){
		hasname = true;
		tk = leToken();
		if(){ //se for vazio
			return Q();
		}else{
			return false;
		}
	}else if(tk == '\t'){
		if(){ //se for vazio
			return Q();
		}else{
			return false;
		}
	}else if(tk == '('){
		if(){ //se for vazio
			return Q();
		}else{
			return false;
		}
	}else if(tk == "\ "){
		if(){ //se for vazio
			return Q();
		}else{
			return false;
		}
	}else if(tk == '+'){
		if(){ //se for vazio
			return Q();
		}else{
			return false;
		}
	}else if(tk == '-'){
		if(){ //se for vazio
			return Q();
		}else{
			return false;
		}
	}else if(tk == ')'){
		if(){ //se for vazio
			return Q();
		}else{
			return false;
		}
	}else if(tk == '{'){
		if(){ //se for vazio
			return Q();
		}else{
			return false;
		}
	}else if(tk == '}'){
		if(){ //se for vazio
			return Q();
		}else{
			return false;
		}
	}else if(tk == '|'){
		if(){ //se for vazio
			return Q();
		}else{
			return false;
		}
	}else if(tk == '&'){
		if(){ //se for vazio
			return Q();
		}else{
			return false;
		}
	}else if(tk == '\n'){
		if(){ //se tk for vazio
			return Q();
		}else{
			return false;
		}
	}else if(tk == '<'){
		return Q50();
	}else if(tk == '>'){
		return Q48();
	}else if(tk == '='){
		return Q46();
	}else if(tk == '*'){
		return Q62();
	}else if(tk == '"'){
		return Q60();
	}else{
		return false;
	}
}
//falt iQ, nQ58
/* Q0 -> lQ44 | {-}Q44 | ""Q | \tQ | (Q | \Q | +Q | -Q | *Q62 | "Q60 | nQ58 |
	       )Q | {Q | iQ | }Q | |Q | &Q | <Q50 | >Q48 | =Q46 | \nQ */
bool Q(){
	return true;
}
