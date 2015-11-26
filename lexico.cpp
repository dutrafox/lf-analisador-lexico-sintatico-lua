#include <iostream>
#include <stdio.h>

using namespace std;

int token(char c, FILE *fp);
int lerPalavra(char c, FILE *fp);
int lerVariavel(FILE *fp);
int lerString(FILE *fp);
void lerNumero(FILE *fp);

int lerVariavel(FILE *fp){
	char c = getc(fp);
	while((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
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
				if(c == 'o'){
					c = getc(fp);
					if(c == 'c'){
						c = getc(fp);
						if(c == 'a'){
							c = getc(fp);
							if(c == 'l'){
								c = getc(fp);
								if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'))){
									fseek(fp, -sizeof(char), SEEK_CUR);
									return 25;
								}else{
									return lerVariavel(fp);
								}
							}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
								return lerVariavel(fp);
							}else{
								fseek(fp, -sizeof(char), SEEK_CUR);
								return 24;
							}
						}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
							return lerVariavel(fp);
						}else{
							fseek(fp, -sizeof(char), SEEK_CUR);
							return 24;
						}
					}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
						return lerVariavel(fp);
					}else{
						fseek(fp, -sizeof(char), SEEK_CUR);
						return 24;
					}
				}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
					return lerVariavel(fp);
				}else{
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 24;
				}
			case 'f':
				c = getc(fp);
				if(c == 'a'){
					c = getc(fp);
					if(c == 'l'){
						c = getc(fp);
						if(c == 's'){
							c = getc(fp);
							if(c == 'e'){
								c = getc(fp);
								if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'))){
									fseek(fp, -sizeof(char), SEEK_CUR);
									return 26;
								}else{
									return lerVariavel(fp);
								}
							}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
								return lerVariavel(fp);
							}else{
								fseek(fp, -sizeof(char), SEEK_CUR);
								return 24;
							}
						}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
							return lerVariavel(fp);
						}else{
							fseek(fp, -sizeof(char), SEEK_CUR);
							return 24;
						}
					}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
						return lerVariavel(fp);
					}else{
						fseek(fp, -sizeof(char), SEEK_CUR);
						return 24;
					}
				}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
					return lerVariavel(fp);
				}else{
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 24;
				}
			case 'i':
				c = getc(fp);
				if(c == 'f'){
					c = getc(fp);
					if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'))){
						fseek(fp, -sizeof(char), SEEK_CUR);
						return 27;
					}else{
						return lerVariavel(fp);
					}
				}else if(c == 'o'){
					c = getc(fp);
					if(c == '.'){
						c = getc(fp);
						if(c == 'r'){
							c = getc(fp);
							if(c == 'e'){
								c = getc(fp);
								if(c == 'a'){
									c = getc(fp);
									if(c == 'd'){
										c = getc(fp);
										if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
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
							if(c == 'r'){
								c = getc(fp);
								if(c == 'i'){
									c = getc(fp);
									if(c == 't'){
										c = getc(fp);
										if(c == 'e'){
											c = getc(fp);
											if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
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
						fseek(fp, -sizeof(char), SEEK_CUR);
						return 24;
					}
				}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
					return lerVariavel(fp);
				}else{
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 24;
				}
			case 'n':
				c = getc(fp);
				if(c == 'i'){
					c = getc(fp);
					if(c == 'l'){
						c = getc(fp);
						if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'))){
							fseek(fp, -sizeof(char), SEEK_CUR);
							return 30;
						}else{
							return lerVariavel(fp);
						}
					}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
						return lerVariavel(fp);
					}else{
						fseek(fp, -sizeof(char), SEEK_CUR);
						return 24;
					}
				}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
					return lerVariavel(fp);
				}else{
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 24;
				}
			case 't':
				c = getc(fp);
				if(c == 'r'){
					c = getc(fp);
					if(c == 'u'){
						c = getc(fp);
						if(c == 'e'){
							c = getc(fp);
							if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'))){
								fseek(fp, -sizeof(char), SEEK_CUR);
								return 31;
							}else{
								return lerVariavel(fp);
							}
						}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
							return lerVariavel(fp);
						}else{
							fseek(fp, -sizeof(char), SEEK_CUR);
							return 24;
						}
					}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
						return lerVariavel(fp);
					}else{
						fseek(fp, -sizeof(char), SEEK_CUR);
						return 24;
					}
				}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
					return lerVariavel(fp);
				}else{
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 24;
				}
			case 'e':
				c = getc(fp);
				if(c == 'l'){
					c = getc(fp);
					if(c == 's'){
						c = getc(fp);
						if(c == 'e'){
							c = getc(fp);
							if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'))){
								fseek(fp, -sizeof(char), SEEK_CUR);
								return 32;
							}else{
								return lerVariavel(fp);
							}
						}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
							return lerVariavel(fp);
						}else{
							fseek(fp, -sizeof(char), SEEK_CUR);
							return 24;
						}
					}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
						return lerVariavel(fp);
					}else{
						fseek(fp, -sizeof(char), SEEK_CUR);
						return 24;
					}
				}else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9')){
					return lerVariavel(fp);
				}else{
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 24;
				}
			default:
				return lerVariavel(fp);
		}
	}else if((c >= 'A' && c <= 'Z') || c == '_'){
		return lerVariavel(fp);
	}
}

int lerString(FILE *fp){
	char c=getc(fp);
	while(c != '\"'){
		c=getc(fp);
	}
	if(c == '\"') return 1;
	else return 0;
}

void lerNumero(FILE *fp){
	char c=getc(fp);
	while(c >= '0' && c <= '9'){
		c=getc(fp);
	}
	fseek(fp, -sizeof(char), SEEK_CUR);
}

int token(char c, FILE *fp){
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_'){
		int lp = lerPalavra(c, fp);
		if(lp != 0){
			cout << "palavra " << lp << endl;
			return lp;
		}else return 0;
	}else if(c == '\"'){
		if(lerString(fp) == 1){
			cout << "string" << endl;
			return 23;
		}else return 0;
	}else if(c >= '0' && c <= '9'){
		lerNumero(fp);
		cout << "numero" << endl;
		return 22;
	}else{
		switch(c){
			case '\n':
				cout << "barra n" << endl;
				return 1;
			case '\t':
				cout << "tabulação" << endl;
				return 2;
			case ' ':
				cout << "espaço" << endl;
				return 3;
			case '+':
				cout << "mais" << endl;
				return 4;
			case '-':
				cout << "menos" << endl;
				return 5;
			case '/':
				cout << "divisão" << endl;
				return 6;
			case '*':
				if(getc(fp)=='*'){
					cout << "exponenciação" << endl;
					return 7;
				}else{
					cout << "multiplicação" << endl;
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 8;
				}
			case '>':
				if(getc(fp)=='='){
					cout << "maior igual" << endl;
					return 9;
				}else{
					cout << "maior" << endl;
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 10;
				}
			case '<':
				if(getc(fp)=='='){
					cout << "menor igual" << endl;
					return 11;
				}else{
					cout << "menor" << endl;
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 12;
				}
			case '=':
				if(getc(fp)=='='){
					cout << "atribuição" << endl;
					return 13;
				}else{
					cout << "igualdade" << endl;
					fseek(fp, -sizeof(char), SEEK_CUR);
					return 14;
				}
			case '(':
				cout << "abre parenteses" << endl;
				return 15;
			case ')':
				cout << "fecha parenteses" << endl;
				return 16;
			case '{':
				cout << "abre chaves" << endl;
				return 17;
			case '}':
				cout << "fecha chaves" << endl;
				return 18;
			case '!':
				cout << "negação" << endl;
				return 19;
			case '&':
				cout << "e" << endl;
				return 20;
			case '|':
				cout << "ou" << endl;
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