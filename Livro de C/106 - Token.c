#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

#define DELIMITADOR 1
#define VARIAVEL 2
#define NUMERO 3

char *prog;
char token[80];
char tok_type;

void eval_exp(double *answer), eval_exp2(double *answer);
void eval_exp3(double *answer), eval_exp4(double *answer);
void eval_exp5(double *answer), eval_exp6(double *answer);
void atom(double *answer);
void get_token(void), putback(void);
void serror(int error);
int isdelim(char c);

//Ponto de entrada do analisador
void eval_exp(double *answer) {
	get_token();
	if(!*token) {
		serror(2);
		return;
	}
	eval_exp2(answer);
	if (*token) serror(0); //último token deve ser null
}

void eval_exp2(double *answer) {
	register char op;
	double temp;
	
	eval_exp3(answer);
	while((op = *token) == '+' || op == '-') {
		get_token();
		eval_exp3(&temp);
		switch(op) {
			case '-':
				*answer = *answer - temp;
				break;
			case '+':
				*answer = *answer + temp;
				break;
		}
	}
}
//Multiplica ou divide dois fatores
void eval_exp3(double *answer) {
	register char op;
	double temp;
	
	eval_exp4(answer);
	while((op = *token) == '*' || op == '/' || op == '%') {
		get_token();
		eval_exp4(&temp);
		switch(op) {
			case '*':
				*answer = *answer * temp;
				break;
			case '/':
				if (temp == 0) serror(3); // Evitar divisão por zero
                else *answer = *answer / temp;
				break;
			case '%':
				*answer = (int) *answer % (int) temp;
				break;
		}
	}
}

//Processa um expoente
void eval_exp4(double *answer) {
	double temp, ex;
	register int t;
	
	eval_exp5(answer);
	if(*token=='^') {
		get_token();
		eval_exp4(&temp);
		ex = *answer;
		if(temp==0.0) {
			*answer = 1.0;
			return;
		}
		for(t=temp-1; t>0; --t) *answer = (*answer) * (double) ex;
	}
}

//Avalia um + ou - unário
void eval_exp5(double *answer)
{
	register char op;
	
	op = 0;
	if(tok_type == DELIMITADOR && (*token=='+' || *token=='-')) {
		op = *token;
		get_token();
	}
	eval_exp6(answer);
	if(op=='-') *answer = -(*answer);
}

//Processa uma expressão entre parenteses
void eval_exp6(double *answer) 
{
	if((*token == '(')) {
		get_token();
		eval_exp2(answer);
		if(*token != ')')
			serror(1);
		get_token();
	} else {
		atom(answer);
	}
		
}

//Obtém o valor real de um número
void atom(double *answer)
{
	if(tok_type==NUMERO) {
		*answer = atof(token);
		get_token();
		return;
	}
	serror(0); //Caso contrário, erro de sintaxe na expressão
}

//Devolve um token à stream de entrada
void putback(void)
{
	char *t;
	t = token;
	for(; *t; t++) prog--;
}

//Apresenta um erro de sintaxe
void serror(int error)
{
	static char *e[] = {
	"Erreur de syntaxe",
	"Parenthèses manquantes",
	"Aucune expression présente",
	"Division par zéro"
	};
	printf("%s \n", e[error]);
}

//Devolve o prox. token
void get_token(void) {
	register char *temp;
	
	tok_type = 0;
	temp = token;
	*temp = '\0';
	
	if(!*prog) return; //Final da expressão
	while(isspace(*prog)) ++prog; //Ignora os espaços em branco
	
    if (strchr("+-*/%^=()", *prog)) {
        tok_type = DELIMITADOR;
        *temp++ = *prog++;
    } else if (isalpha(*prog)) {
        while (!isdelim(*prog) && *prog) *temp++ = *prog++;
        tok_type = VARIAVEL;
    } else if (isdigit(*prog) || *prog == '.') {
        while (!isdelim(*prog) && *prog) *temp++ = *prog++;
        tok_type = NUMERO;
    }
	
	*temp = '\0';
}

//Devolve verdadeiro de c e um delimitador
int isdelim(char c) {
    return (strchr("+-*/%^=() \t\n", c) != NULL || c == 0);
}

void main(void)
{
	double answer;
	char *p;
	setlocale(LC_ALL, "French");
	
	p = malloc(100);
	if(!p) {
		printf("L'allocation de mémoire a échoué. \n");
		exit(1);
	}
	//Processa expressões até que uma linha em branco seja digitada
	do {
		prog = p;
		printf("Entrez l'expression : ");
        fgets(p, 100, stdin); // Substituído gets por fgets para segurança
        p[strcspn(p, "\n")] = 0; // Remove o '\n' do final
        if (!*prog) break;
        eval_exp(&answer);
		printf("La réponse est %.2f \n", answer);
	} while(*p);
	
	 free(p);
}
