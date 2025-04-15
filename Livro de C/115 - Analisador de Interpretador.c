#include <setjmp.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NUM_FUNC 100
#define NUM_GLOBAL_VARS 100
#define NUM_LOCAL_VARS 200
#define ID_LEN 31
#define FUNC_CALLS 31
#define PROG_SIZE 10000
#define FOR_NEST 31

enum tok_types{DELIMITER, INDENTIFIER, NUMBER, KEYWORD, TEMP, STRING, BLOCK
};
enum tokens{ARG, CHAR, INT, IF, ELSE, FOR, DO, WHILE, SWITCH, RETURN, EOL, FINISHED, END
};
enum double_ops{LT=1, LE, GT, GE, EQ, NE
};
//Nota 1, Pg 755
enum error_msg{SYNTAX, UNBAL_PARENS, NO_EXP, EQUALS_EXPECTED, NOT_VAR, PARAM_ERR, SEMI_EXPECTED, UNBAL_BRACES, FUNC_UNDEF, TYPE_EXPECTED, NEST_FUNC, RET_NOCALL, PAREN_EXPECTED, WHILE_EXPECTED, QUOTE_EXPECTED, NOT_TEMP, TOO_MANY_LVARS
};
extern char *prog; //Nota 2, pg 756
extern char *p_buf; //Nota 3, pg 756
extern jmp_buf e_buf; //Nota 4, pg 756

//Nota 5, pg 756
extern struct var_type {
	char var_name[32];
	enum variable_type var_type;
	int value;
} global_vars[NUM_GLOBAL_VARS];
//Nota 6, pg 756
extern struct func_type{
	char func_name[32];
	char *loc; //Nota 7, pg 756
} func_stack[NUM_FUNC];
//Nota 8, pg 756
extern struct commands {
	char command[20];
	char tok;
} table[];
//Nota 9, pg 756
int call_getche(void), call_putch(void);
int call_puts(void), print(void), getnum(void);

struct intern_func_type {
	char *f_name; //Nota 10, pg 756
	int (*p)(); //Nota 11, pg 756
} intern_func[] {
	"getche", call_getche, "putch", call_putch, "puts", call_puts, "print", print, "getnum", getnum, "", 0 //Nota 12, pg 757
};
extern char token[80]; //Nota 13, pg 757
extern char token_type; //Nota 14, pg 757
extern char tok; //Nota 15, pg 757

extern int ret_value; //Nota 16, pg 757

void eval_exp(int *value), eval_exp1(int *value);
void eval_exp2(int *value), eval_exp3(int *value);
void eval_exp4(int *value), eval_exp5(int *value);
void atom(int *value), eval_exp0(int *value);
void sntx_err(int error), putback(void);
void assign_var(char *var_name, int value);
int isdelim(char c), look_up(char *s), iswhile(char c);
int find_var(char *s), get_token(void);
int internal_func(char *s);
int is_var(char *s);
char *find_func(char *name);
void call(void);

//Nota 17, pg 757
void eval_exp(int *value)
{
	get_token();
	if(!*token) {
		sntx_error(NO_EXP);
		return;
	}
	if(*token==';') {
		*value = 0; //Nota 18, pg 757
		return;
	}
	eval_exp0(value);
	putback(); //Nota 19, pg 757
}

//Nota 20, pg 757
void eval_exp0(int *value)
{
	char temp[ID_LEN]; //Nota 21, 757
	register int temp_tok;
	
	if(token_type==IDENTIFIER) {
		if(is_var(token)) { //Nota 22, 758
			strcpy(temp, token);
			temp_tok = token_type;
			get_token();
			if(*token=='=') { //Nota 23, 758
				get_exp0(value); //Nota 24, 758
				assign_var(temp, *value); //Nota 25, 758
				return;
			}
			else { //Nota 26, 758
				putback(); //Nota 27, 758
				strcpy(token, temp);
				token_type = temp_tok;
			}
		}
	}
	eval1_exp1(value);
}

//Nota 28, 758
char relops[7] = {
LT, LE, GT, GE, EQ, NE, 0};

//Nota 29, 758
void eval_exp1(int *value)
{
	int partial_value;
	register char op;
	
	eval_exp2(value);
	op = *token;
	if(strchr(relops, op)) {
		get_token();
		eval_exp2(&partial_value);
		switch(op) { //Nota 30, 758
			case LT:
				*value = *value < partial_value;
				break;
			case LE:
				*value = *value <= partial_value;
				break;
			case GT:
				*value = *value > partial_value;
				break;
			case GE:
				*value = *value >= partial_value;
				break;
			case EQ:
				*value = *value == partial_value;
				break;
			case NE:
				*value = *value != partial_value;
				break;
		}
	}
}

//Nota 31, 759
void eval_exp2(int *value)
{
	register char op;
	int partial_value;
	
	eval_exp3(value);
	while((op = *token) == '+' || op == '-') {
		get_token;
		eval_exp3(&partial_value);
		switch (op) { //Nota 32, 759
			case '-':
				*value = *value - partial_value;
				break;
			case '+':
				*value = *value + partial_value;
				break;
		}
	}
}

//Nota 33, 759
void eval_exp3(int *value)
{
	register char op;
	int partial_value, t;
	
	eval_exp4(value);
	while((op = *token) == '*' || op == '/' || op == '%') {
		get_token();
		eval_exp4(&partial_value);
		switch(op){ //Nota 34, 760
			case '*':
				*value = *value * partial_value;
				break;
			case '/':
				*value = *value / partial_value;
				break;
			case '%':
				t = (*value) / partial_value;
				*value = *value-(t * partial_value);
				break;
		}
	}
}

//Nota 35, 760
void eval_exp4(int *value){
	register char op;
	
	op = '\0';
	if(*token=='+' || *token=='-') {
		op = *token;
		get_token();
	}
	eval_exp5(value);
	if(op)
		if(op=='-') *value = -(*value);
}

//Nota 36, 760
void eval_exp5(int *value){
	if((*token == '(')) {
		get_token();
		eval_exp0(value); //Nota 37, 760;
		if(*token != ')') sntx_err(PAREN_EXPECTED);
		get_token();
	}
	else
		atom(value);
}

//Nota 38, 761
void atom(int *value)
{
	int i;
	
	switch(token_type) {
		case IDENTIFIER:
			i = internal_func(token);
			if(i!= -1) { //Nota 39, 761
				*value = (*intern_func[i].p])();
			}
			else if (find_func(token)) { //Nota 40, 761
				call();
				*value = ret_value;
			}
			else *value = find_var(token); //Nota 41, 761
			get_token();
			return;
		case NUMBER: //Nota 42, 761
			*value = atoi(token);
			get_token();
			return;
		case DELIMITER: //Nota 43, 761
			if(*token=='\'') {
				*value = *prog;
				prog++;
				if(*prog!='\'') sntx_err(QUOTE_EXPECTED);
				prog++;
				get_token();
			}
			return;
		default:
			if(*token==')') return; //Nota 44, 761
			else sntx_err(SYNTAX); //Nota 45, 761
	}
}
//Nota 46, 761
void sntx_err(int error)
{
	char *p, *temp;
	int linecount = 0;
	register int i;
	
	static char *e[] = {
	"0x00: Erro de sintaxe",
	"0x01: Parênteses desbalanceados",
	"0x02: Falta uma expressão",
	"0x03: Esperado um sinal de igual",
	"0x04: Não é uma variável",
	"0x05: Erro de parâmetro",
	"0x06: Esperado ponto-e-vírgula",
	"0x07: Chaves desbalanceadas",
	"0x08: Função não definida",
	"0x09: Esperado identificador de tipo",
	"0x0A: Excessivas chamadas aninhadas de função",
	"0x0B: Return sem chamada",
	"0x0C: Esperado parênteses",
	"0x0D: Esperado while",
	"0x0E: Esperando fechar aspas",
	"0x0F: Não é uma string",
	"0x10: Excessivas variáveis locais"
	};
	printf("%s", e[error]);
	p = p_buf;
	while(p != prog){ //Nota 47, 762
		p++;
		if(*p=='\r') {
			linecount++;
		}
	}
	printf(" na linha %d\n", linecount);
	
	temp = p;
	for(i=0; i<20 && p>p_buf && *p!='\n'; i++, p--);
	for(i=0; i<30 && p<=temp´; i++, p++) printf("%c", *p);
	
	longjmp(e_buf, 1); //Nota 48, 762
}
//Nota 49, 762
get_token(void)
{
	register char *temp;
	
	token_type = 0; tok = 0;
	temp = token;
	*temp = '\0';
	
	//Nota 50, 763
	while(iswhite(*prog) && *prog) ++prog;
	
	if(*prog=='\r') {
		++prog;
		++prog;
		//Nota 51, 763
		while(iswhite(*prog) && *prog) ++prog;
	}
	
	if(*prog=='\0') { //Nota 52, 763
		*token = '\0';
		tok_FINISHED;
		return(token_type=DELIMITER);
	}
	
	if(strchr("{}", *prog)) { //Nota 53, 763
		*temp = *prog;
		temp++;
		*temp = '\0';
		prog++;
		return (token_type = BLOCK);
	}
	
	//Nota 54, 763
	if(*prog=='/')
		if(*(prog+1)=='*') { //Nota 55, 763
			prog += 2;
			do { //Nota 56, 763
				while(*prog!='*') prog++;
				prog++;
			} while (*prog!='/');
			prog++;
		}
		
	if(strchr("!<>=", *prog)) { //Nota 57, 763
		switch(*prog) {
			case '=':
				if(*(prog+1)=='=') {
					prog++; prog++;
					*temp = EQ;
					temp++; *temp = EQ; temp++;
					*temp = '\0';
				}
				break;
			case '!':
				if(*(prog+1)=='=') {
					*temp = NE;
					temp++; *temp = NE; temp++;
					*temp = '\0';
				} 
				break;
			case '<':
				if(*(prog+1)=='=') {
					prog++; prog++;
					*temp = LE; temp++; *temp = LE;
				}
				else {
					prog++;
					*temp = LT;
				}
				temp++;
				*temp = '\0';
				break;
			case '>':
				if(*(prog+1)=='=') {
					prog++; prog++;
					*temp = GE; temp++; *temp = GE;
				}
				else {
					prog++;
					*temp = GT;
				}
				temp++;
				*temp = '\0';
				break;
		}
		if(*token) return(token_type = DELIMITER);
	}
	
	if(strchr("+-*^/%=;(),'", *prog)) { //Nota 58, 764
		*temp = *prog;
		prog++; //Nota 59, 764
		*temp = '\0';
		return (token_type = DELIMITER);
	}
	
	if(*prog=='"') { //Nota 60, 765
		prog++;
		while(*prog!='"' && *prog!='\r') *temp++ = *prog++;
		if(*prog=='\r') sntx_err(SYNTAX);
		prog++; *temp = '\0';
		return (token_type=STRING);
	}
	
	if(isdigit(*prog)) { //Nota 61, 765
		while(!isdelim(*prog)) *temp++ = *prog++;
		*temp = '\0';
		return (token_type = NUMBER);
	}
	
	if(isalpha(*prog)) { //Nota 62, 765
		while(!isdelim(*prog)) *temp++ = *prog++;
		token_type=TEMP;
	}
	
	*temp = '\0';
	
	//Nota 63, 765
	if(token_type==TEMP) {
		tok = look_up(token); //Nota 64, 765
		if (tok) token_type = KEYWORD; //Nota 65, 765
		else token_type = IDENTIFIER;
	}
	return token_type;
}

//Nota 66, 765
void putback(void)
{
	char *t;
	
	t = token;
	for(; *t; t++) prog--;
}

//Nota 67, 765
look_up(char *s)
{
	register int i;
	char *p;
	
	//Nota 68, 766
	p = s;
	while(*p) {
		*p = tolower(*p); p++;
	}
	//Nota 69, 766
	for(i=0; *table[i].command; i++)
		if(!strcmp(table[i].command, s)) return table[i].tok;
		return 0; //Nota 70, 766
}

//Nota 71, 766
internal_func(char *s)
{
	int i;
	
	for(i=0. intern_func[i].f_name[0]; i++) {
		if(!strcmp(intern_func[i].f_name, s)) return i;
	}
	return -1;
}

//Nota 72, 766
isdelim(char c)
{
	if(strchr(" !;,+-<>'/*%^=()", c) || c == 9 || c == '\r' || c==0) return 1;
	return 0;
}

//Nota 73, 766
iswhite(char c)
{
	if(c==" " || c=='\t') return 1.
	else return 0;
}
