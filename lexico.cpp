#include <iostream>
#include <stdio.h>

using namespace std;

/***
	Está cheio de COUT para ver se os retornos estavam corretos
***/

int coluna = 0;
int linha = 1;

int token(char c, FILE *fp);
int lerPalavra(char c, FILE *fp);
int lerVariavel(FILE *fp);
int lerString(FILE *fp);
void lerNumero(FILE *fp);

int lerVariavel(FILE *fp){
	char c = getc(fp);
	while((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
		coluna++;
		c = getc(fp);
	}
	fseek(fp, -sizeof(char), SEEK_CUR);
	return 24;
}

int lerPalavra(char c, FILE *fp){
	if(c >= 'a' && c <= 'z'){
		switch(c){
			case 'l':
				c = getc(fp);
				coluna++;
				if(c == 'o'){
					c = getc(fp);
					coluna++;
					if(c == 'c'){
						c = getc(fp);
						coluna++;
						if(c == 'a'){
							c = getc(fp);
							coluna++;
							if(c == 'l'){
								c = getc(fp);
								if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'))){
									fseek(fp, -sizeof(char), SEEK_CUR);
									return 25;
								}else{
									coluna++;
									return lerVariavel(fp);
								}
							}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
								return lerVariavel(fp);
							}else{
								coluna--;
								fseek(fp, -sizeof(char), SEEK_CUR);
								return 24;
							}
						}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
							return lerVariavel(fp);
						}else{
							coluna--;
							fseek(fp, -sizeof(char), SEEK_CUR);
							return 24;
						}
					}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
						return lerVariavel(fp);
					}else{
						coluna--;
						fseek(fp, -sizeof(char), SEEK_CUR);
						return 24;
					}
				}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
					return lerVariavel(fp);
				}else{
					coluna--;
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 24;
				}
			case 'f':
				c = getc(fp);
				coluna++;
				if(c == 'a'){
					c = getc(fp);
					coluna++;
					if(c == 'l'){
						c = getc(fp);
						coluna++;
						if(c == 's'){
							c = getc(fp);
							coluna++;
							if(c == 'e'){
								c = getc(fp);
								if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'))){
									fseek(fp, -sizeof(char), SEEK_CUR);
									return 26;
								}else{
									coluna++;
									return lerVariavel(fp);
								}
							}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
								return lerVariavel(fp);
							}else{
								coluna--;
								fseek(fp, -sizeof(char), SEEK_CUR);
								return 24;
							}
						}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
							return lerVariavel(fp);
						}else{
							coluna--;
							fseek(fp, -sizeof(char), SEEK_CUR);
							return 24;
						}
					}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
						return lerVariavel(fp);
					}else{
						coluna--;
						fseek(fp, -sizeof(char), SEEK_CUR);
						return 24;
					}
				}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
					return lerVariavel(fp);
				}else{
					coluna--;
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 24;
				}
			case 'i':
				c = getc(fp);
				coluna++;
				if(c == 'f'){
					c = getc(fp);
					if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'))){
						fseek(fp, -sizeof(char), SEEK_CUR);
						return 27;
					}else{
						coluna++;
						return lerVariavel(fp);
					}
				}else if(c == 'o'){
					c = getc(fp);
					coluna++;
					if(c == '.'){
						c = getc(fp);
						coluna++;
						if(c == 'r'){
							c = getc(fp);
							coluna++;
							if(c == 'e'){
								c = getc(fp);
								coluna++;
								if(c == 'a'){
									c = getc(fp);
									coluna++;
									if(c == 'd'){
										c = getc(fp);
										if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
											coluna++;
											return 0;
										}else{
											fseek(fp, -sizeof(char), SEEK_CUR);
											return 28;
										}
									}else{
										return 0;
									}
								}else{
									return 0;
								}
							}else{
								return 0;
							}
						}else if(c == 'w'){
							c = getc(fp);
							coluna++;
							if(c == 'r'){
								c = getc(fp);
								coluna++;
								if(c == 'i'){
									c = getc(fp);
									coluna++;
									if(c == 't'){
										c = getc(fp);
										coluna++;
										if(c == 'e'){
											c = getc(fp);
											if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
												coluna++;
												return 0;
											}else{
												fseek(fp, -sizeof(char), SEEK_CUR);
												return 29;
											}
										}else{
											return 0;
										}
									}else{
										return 0;
									}
								}else{
									return 0;
								}
							}else{
								return 0;
							}
						}else{
							return 0;
						}
					}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
						return lerVariavel(fp);
					}else{
						coluna--;
						fseek(fp, -sizeof(char), SEEK_CUR);
						return 24;
					}
				}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
					return lerVariavel(fp);
				}else{
					coluna--;
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 24;
				}
			case 'n':
				c = getc(fp);
				coluna++;
				if(c == 'i'){
					c = getc(fp);
					coluna++;
					if(c == 'l'){
						c = getc(fp);
						if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'))){
							fseek(fp, -sizeof(char), SEEK_CUR);
							return 30;
						}else{
							coluna++;
							return lerVariavel(fp);
						}
					}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
						return lerVariavel(fp);
					}else{
						coluna--;
						fseek(fp, -sizeof(char), SEEK_CUR);
						return 24;
					}
				}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
					return lerVariavel(fp);
				}else{
					coluna--;
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 24;
				}
			case 't':
				c = getc(fp);
				coluna++;
				if(c == 'r'){
					c = getc(fp);
					coluna++;
					if(c == 'u'){
						c = getc(fp);
						coluna++;
						if(c == 'e'){
							c = getc(fp);
							if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'))){
								fseek(fp, -sizeof(char), SEEK_CUR);
								return 31;
							}else{
								coluna++;
								return lerVariavel(fp);
							}
						}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
							return lerVariavel(fp);
						}else{
							coluna--;
							fseek(fp, -sizeof(char), SEEK_CUR);
							return 24;
						}
					}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
						return lerVariavel(fp);
					}else{
						coluna--;
						fseek(fp, -sizeof(char), SEEK_CUR);
						return 24;
					}
				}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
					return lerVariavel(fp);
				}else{
					coluna--;
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 24;
				}
			case 'e':
				c = getc(fp);
				coluna++;
				if(c == 'l'){
					c = getc(fp);
					coluna++;
					if(c == 's'){
						c = getc(fp);
						coluna++;
						if(c == 'e'){
							c = getc(fp);
							if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'))){
								fseek(fp, -sizeof(char), SEEK_CUR);
								return 32;
							}else{
								coluna++;
								return lerVariavel(fp);
							}
						}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
							return lerVariavel(fp);
						}else{
							coluna--;
							fseek(fp, -sizeof(char), SEEK_CUR);
							return 24;
						}
					}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
						return lerVariavel(fp);
					}else{
						coluna--;
						fseek(fp, -sizeof(char), SEEK_CUR);
						return 24;
					}
				}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
					return lerVariavel(fp);
				}else{
					coluna--;
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 24;
				}
			default:
				coluna++;
				return lerVariavel(fp);
		}
	}else if((c >= 'A' && c <= 'Z') || c == '_'){
		return lerVariavel(fp);
	}
}

int lerString(FILE *fp){
	char c=getc(fp);
	while(c != '\"'){
		coluna++;
		c=getc(fp);
	}
	if(c == '\"'){
		coluna++;
		return 1;
	}
	else return 0;
}

void lerNumero(FILE *fp){
	char c=getc(fp);
	while(c >= '0' && c <= '9'){
		coluna++;
		c=getc(fp);
	}
	fseek(fp, -sizeof(char), SEEK_CUR);
}

/** Retornos função token
	1 - 	\n
	2 -		\t
	3 -		espaço
	4 -		+
	5 -		-
	6 -		/
	7 -		*
	8 -		**
	9 -		>
	10 -	>=
	11 -	<
	12 -	<=
	13 -	=
	14 -	==
	15 -	(
	16 -	)
	17 -	{
	18 -	}
	19 -	!
	20 -	&
	21 -	|
	22 -	numero
	23 -	"string"
	24 -	variavel
	25 -	local
	26 -	false
	27 -	if
	28 -	io.read
	29 -	io.write
	30 -	nil
	31 -	true
	32 -	false
	FALTAM:
	33 - 	.
	34 - 	num . flutuante
	35 - ,
*/
int token(char c, FILE *fp){
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_'){
		coluna++;
		int lp = lerPalavra(c, fp);
		if(lp != 0){
			cout << "palavra" << lp << "@" << linha << ":" << coluna << endl;
			return lp;
		}else return 0;
	}else if(c == '\"'){
		coluna++;
		if(lerString(fp) == 1){
			cout << "string" << "@" << linha << ":" << coluna << endl;
			return 23;
		}else return 0;
	}else if(c >= '0' && c <= '9'){
		coluna++;
		lerNumero(fp);
		cout << "numero" << "@" << linha << ":" << coluna << endl;
		return 22;
	}else{
		switch(c){
			case '\n':
				cout << "barra n" << "@" << linha << ":" << coluna << endl;
				linha++;
				coluna = 0;
				return 1;
			case '\t':
				coluna += 4;
				cout << "tabulação" << "@" << linha << ":" << coluna << endl;
				return 2;
			case ' ':
				coluna++;
				cout << "espaço" << "@" << linha << ":" << coluna << endl;
				return 3;
			case '+':
				coluna++;
				cout << "mais" << "@" << linha << ":" << coluna << endl;
				return 4;
			case '-':
				coluna++;
				cout << "menos" << "@" << linha << ":" << coluna << endl;
				return 5;
			case '/':
				coluna++;
				cout << "divisão" << "@" << linha << ":" << coluna << endl;
				return 6;
			case '*':
				if(getc(fp)=='*'){
					coluna += 2;
					cout << "exponenciação" << "@" << linha << ":" << coluna << endl;
					return 7;
				}else{
					coluna++;
					cout << "multiplicação" << "@" << linha << ":" << coluna << endl;
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 8;
				}
			case '>':
				if(getc(fp)=='='){
					coluna += 2;
					cout << "maior igual" << "@" << linha << ":" << coluna << endl;
					return 9;
				}else{
					coluna++;
					cout << "maior" << "@" << linha << ":" << coluna << endl;
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 10;
				}
			case '<':
				if(getc(fp)=='='){
					coluna += 2;
					cout << "menor igual" << "@" << linha << ":" << coluna << endl;
					return 11;
				}else{
					coluna++;
					cout << "menor" << "@" << linha << ":" << coluna << endl;
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 12;
				}
			case '=':
				if(getc(fp)=='='){
					coluna += 2;
					cout << "atribuição" << "@" << linha << ":" << coluna << endl;
					return 13;
				}else{
					coluna++;
					cout << "igualdade" << "@" << linha << ":" << coluna << endl;
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 14;
				}
			case '(':
				coluna++;
				cout << "abre parenteses" << "@" << linha << ":" << coluna << endl;
				return 15;
			case ')':
				coluna++;
				cout << "fecha parenteses" << "@" << linha << ":" << coluna << endl;
				return 16;
			case '{':
				coluna++;
				cout << "abre chaves" << "@" << linha << ":" << coluna << endl;
				return 17;
			case '}':
				coluna++;
				cout << "fecha chaves" << "@" << linha << ":" << coluna << endl;
				return 18;
			case '!':
				coluna++;
				cout << "negação" << "@" << linha << ":" << coluna << endl;
				return 19;
			case '&':
				coluna++;
				cout << "e" << "@" << linha << ":" << coluna << endl;
				return 20;
			case '|':
				coluna++;
				cout << "ou" << "@" << linha << ":" << coluna << endl;
				return 21;
		}
	}
}

int main(int argc, char *argv[]){
	FILE *fp;
	fp=fopen(argv[1],"r");
	int coluna=0, linha=0;
	char c;
	while((c=getc(fp)) != EOF){
		token(c, fp);
	}
}