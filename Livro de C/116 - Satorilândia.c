//Nota 1, 775 (1975)
#include <stdio.h>
#include <setjmp.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


#define NUM_FUNC 100
#define NUM_GLOBAL_VARS 100
#define NUM_LOCAL_VARS 200
#define NUM_BLOCK 100
#define ID_LEN 31
#define FUNC_CALLS 31
#define NUM_PARAMS 31
#define PROG_SIZE 10000
#define LOOP_NEST 31

enum tok_types {DELIMITER, IDENTIFIER, NUMBER, KEYWORD, TEMP, STRING, BLOCK
};
//Nota 2, 776 (1976)
enum tokens {ARG, CHAR, INT, IF, ELSE, FOR, DO, WHILE, SWITCH, RETURN, EOL, FINISHED, END
};
//Nota 3, 776
enum double_ops {LT=1, LE, GT, GE, EQ, NE
};
//Nota 4, 776
enum error_msg{SYNTAX, UNBAL_PARENS, NO_EXP, EQUALS_EXPECTED, NOT_VAR, PARAM_ERR, SEMI_EXPECTED, UNBAL_BRACES, FUNC_UNDEF, TYPE_EXPECTED,
NEST_FUNC, RET_NOCALL, PAREN_EXPECTED, WHILE_EXPECTED, QUOTE_EXPECTED, NOT_TEMP, TOO_MANY_LVARS
};
char *prog; //Nota 5, 776
char *p_buf; //Nota 6, 776
jmp_buf e_buf; //Nota 7, 776

//Nota 8, 776
struct var_type {
	char var_name[ID_LEN];
	int var_type;
	int value;
} global_vars[NUM_GLOBAL_VARS];
struct var_type local_var_stack[NUM_LOCAL_VARS];
struct func_type {
	char func_name[ID_LEN];
	char *loc; //Nota 9, 777 (1977)
} func_table[NUM_FUNC];

int call_stack[NUM_FUNC];

struct commands{ //Nota 10, 777
	char command[20];
	char tok;
} table[] = { //Nota 11, 777
	"if", IF, //Nota 12, 777
	"else", ELSE,
	"for", FOR,
	"do", DO,
	"while", WHILE,
	"char", CHAR,
	"int", INT,
	"return", RETURN,
	"end", END,
	"", END //Nota 13, 777
};


char token[80];
char token_type, tok;

int functos; //Nota 14, 777
int func_index; //Nota 15, 777
int gvar_index; //Nota 16, 777
int lvartos; //Nota 17, 777
int ret_value; //Nota 18, 777

void print(void), prescan(void);
void decl_global(void), call(void), putback(void);
void decl_local(void), local_push(struct var_type i);
void exec_if(void), find_eob(void), exec_for(void);
void get_params(void), get_args(void);
void exec_while(void), func_push(int i), exec_do(void);
void assign_var(char *var_name, int value);
int load_program(char *p, char *fname), find_var(char *s);
void interp_block(void), func_ret(void);
int func_pop(void), is_var(char *s), get_token(void);

char *find_func(char *name);

main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	if(argc!=2) {
		printf("Uso: satorilandc <nome_de_arquivo>\n");
		exit(1);
	}
	//Nota 19, 778 (1978)
	if((p_buf=(char *) malloc(PROG_SIZE)) == NULL) {
		printf("Falha de alocação");
		exit(1);
	}
	//Nota 20, 778
	if(!load_program(p_buf, argv[1])) exit(1);
	if(setjmp(e_buf)) exit(1); //Nota 21, 778
	//Nota 22, 778
	prog = p_buf;
	prescan(); //Nota 23, 778
	gvar_index = 0; //Nota 24, 778
	lvartos = 0; //Nota 25, 778
	functos = 0; //Nota 26, 778
	
	//Nota 27, 778
	prog = find_func("main"); //Nota 28, 778
	prog--; //Nota 29, 778
	strcpy(token, "main");
	call(); //Nota 30, 779 (1979)
	return 0;
}

//Nota 31, 779
void interp_block(void){
	int value;
	char block = 0;
	
	do {
		token_type = get_token();
		//Nota 32, 779
		//Nota 33, 779
		if(token_type==IDENTIFIER) {
			//Nota 34, 779
			putback(); //Nota 35, 779
			eval_exp(&value); //Nota 36, 779
			if(*token!=';') sntx_err(SEMI_EXPECTED);
		}
		else if(token_type==BLOCK){ //Nota 37, 779
			if(*token=='{') //Nota 38, 779
				block = 1; //Nota 39, 779
			else return; //Nota 40, 779
		}
		else //Nota 41, 779
			switch(tok) {
				case CHAR:
				case INT: //Nota 42, 779
					putback();
					decl_local();
					break;
				case RETURN: //Nota 43, 779
					func_ret();
					return;
				case IF: //Nota 44, 779
					exec_if();
					break;
				case ELSE: //Nota 45, 780 (1980)
					find_eob(); //Nota 46, 780
					break;
				case WHILE: //Nota 47, 780
					exec_while();
					break;
				case DO: //Nota 48, 780
					exec_do();
					break;
				case FOR: //Nota 49, 780
					exec_for();
					break;
				case END:
					exit(0);
			}
	} while(tok != FINISHED && block);
}

//Nota 50, 780
load_program(char *p, char *fname)
{
	FILE *fp;
	int i=0;
	
	if((fp=fopen(fname, "rb"))==NULL) return 0;
	
	i = 0;
	do {
		*p = getc(fp);
		p++; i++;
	} while(!feof(fp) && i<PROG_SIZE);
	if(*(p-2)==0x1a) *(p-2) = '\0'; //Nota 51, 780
	
	else *(p-1) = '\0';
	fclose(fp);
	return 1;
}
//Nota 52, 780
void prescan(void)
{
	char *p;
	char temp[32];
	int brace = 0; //Nota 53, 781 (1981)
	p = prog;
	func_index = 0;
	do {
		while(brace) { //Nota 54, 781
			get_token();
			if(*token=='{') brace++;
			if(*token=='}') brace--;
		}
		get_token();
		
		if(tok==CHAR || tok==INT) { //Nota 55, 781
			putback();
			decl_global();
		}
		else if(token_type==IDENTIFIER){
			strcpy(temp, token);
			get_token();
			if(*token=='(') { //Nota 56, 781
				func_table[func_index].loc = prog;
				strcpy(func_table[func_index].func_name, temp);
				func_index++;
				while(*prog!=')') prog++;
				prog++;
				//Nota 57, 781
			}
			else putback();
		}
		else if(*token=='{') brace++;
	} while (tok!=FINISHED);
	prog = p;
}
//Nota 58, 781
char *find_func(char *name)
{
	register int i;
	for(i=0; i<func_index; i++)
		if(!strcmp(name, func_table[i].func_name))
			return func_table[i].loc;
			
	return NULL;
}
//Nota 59, 782 (1982)
void decl_global(void)
{
	get_token(); //Nota 60, 782
	global_vars[gvar_index].var_type = tok;
	global_vars[gvar_index].value = 0; //Nota 61, 782
	
	do { //Nota 62, 782
		get_token(); //Nota 63, 782
		strcpy(global_vars[gvar_index].var_name, token);
		get_token();
		gvar_index++;
	} while(*token==',');
	if(*token!=';') sntx_err(SEMI_EXPECTED);
}
//Nota 64, 782
void decl_local(void)
{
	struct var_type i;
	get_token(); //Nota 65, 782
	
	i.var_type = tok;
	i.value = 0; //Nota 66, 782
	
	do { //Nota 67, 782
		get_token(); //Nota 68, 782
		strcpy(i.var_name, token);
		local_push(i);
		get_token();
		gvar_index++;
	} while(*token==',');
	if(*token!=';') sntx_err(SEMI_EXPECTED);
}

//Nota 69, 782
void call(void)
{
	char *loc, *temp;
	int lvartemp;
	
	loc = find_func(token); //Nota 70, 783 (1983)
	if(loc==NULL)
		sntx_err(FUNC_UNDEF); //Nota 71, 783
	else {
		lvartemp = lvartos; //Nota 72, 783
		get_args(); //Nota 73, 783
		temp = prog; //Nota 74, 783
		func_push(lvartemp); //Nota 75, 783
		prog = loc; //Nota 76, 783
		get_params(); //Nota 77, 783
		interp_block(); //Nota 78, 783
		prog = temp; //Nota 79, 783
		lvartos = func_pop(); //Nota 80, 783
	}
}

//Nota 81, 783
void get_args(void)
{
	int value, count, temp[NUM_PARAMS];
	struct var_type i;
	
	count = 0;
	get_token();
	if(*token!='(') sntx_err(PAREN_EXPECTED);
	//Nota 82, 783
	do {
		eval_exp(&value);
		temp[count] = value; //Nota 83, 783
		get_token();
		count++;
	} while(*token==',');
	count--;
	//Nota 84, 783
	for(; count>=0; count--) {
		i.value = temp[count];
		i.var_type = ARG;
		local_push(i);
	}
}
//Nota 85, 784 (1984)
void get_params(void)
{
	struct var_type *p;
	int i;
	
	i = lvartos-1;
	do { //Nota 86, 784
		get_token();
		p = &local_var_stack[i];
		if(*token!=')') {
			if(tok!=INT && tok!= CHAR) sntx_err(TYPE_EXPECTED);
			p->var_type = token_type;
			get_token();
			
			//Nota 87, 784
			strcpy(p->var_name, token);
			get_token();
			i--;
		}
		else break;
	} while(*token==',');
	if(*token!=')') sntx_err(PAREN_EXPECTED);
}

//Nota 88, 784
void func_ret(void)
{
	int value;
	
	value = 0;
	//Nota 89, 784
	eval_exp(&value);
	ret_value = value;
}

//Nota 90, 784
void local_push(struct var_type i)
{
	if(lvartos>NUM_LOCAL_VARS)
		sntx_err(TOO_MANY_LVARS);
		
	local_var_stack[lvartos] = i;
	lvartos++;
}

//Nota 91, 785 (1985)
func_pop(void)
{
	functos--;
	if(functos<0) sntx_err(RET_NOCALL);
	return (call_stack[functos]);
}

//Nota 92, 785
void func_push(int i)
{
	if(functos>NUM_FUNC)
		sntx_err(NEST_FUNC);
	call_stack[functos] = i;
	functos++;
}

//Nota 93, 785
void assign_var(char *var_name, int value)
{
	register int i;
	//Nota 94, 785
	for (i=lvartos-1; i>=call_stack[functos-1]; i--) {
		if(!strcmp(local_var_stack[i].var_name, var_name)) {
			local_var_stack[i].value = value;
			return;
		}
	}
	if(i < call_stack[functos-1])
		//Nota 95, 785
		if(!strcmp(global_vars[i].var_name, var_name)) {
			global_vars[i].value = value;
			return;
		}
	sntx_err(NOT_VAR); //Nota 96, 785
}

//Nota 97, 786 (1986)
int find_var(char *s)
{
	register int i;
	//Nota 98, 786
	for(i=lvartos-1; i>=call_stack[functos-1]; i--)
		if(!strcmp(global_vars[i].var_name, s))
			return global_vars[i].value;
	
	sntx_err(NOT_VAR); //Nota 99, 786
}

//Nota 100, 786
int is_var(char *s)
{
	register int i;
	
	//Nota 101, 786
	for(i=lvartos-1; i>=call_stack[functos-1]; i--)
		if(!strcmp(local_var_stack[i].var_name, token))
			return 1;
	
	//Nota 102, 786
	for(i=0; i<NUM_GLOBAL_VARS; i++)
		if(!strcmp(global_vars[i].var_name, s))
			return 1;
	
	return 0;
}

//Nota 103, 786
void exec_if(void)
{
	int cond;
	eval_exp(&cond); //Nota 104, 787 (1987)
	if(cond){ //Nota 105, 787
		interp_block();
	}
	else { //Nota 106, 787
		find_eob(); //Nota 107, 787
		get_token();
		
		if(tok!=ELSE) {
			putback(); //Nota 108, 787
			return;
		}
		interp_block();
	}
}

//Nota 109, 787
void exec_while(void)
{
	int cond;
	char *temp;
	
	putback();
	temp = prog; //Nota 110, 787
	get_token();
	eval_exp(&cond); //Nota 111, 787
	if(cond) interp_block(); //Nota 112, 787
	else { //Nota 113, 787
		find_eob();
		return;
	}
	prog = temp; //Nota 114, 787
}

//Nota 115, 787
void exec_do(void)
{
	int cond;
	char *temp;
	
	putback();
	temp = prog; //Nota 116, 787
	get_token(); //Nota 117, 788 (1988)
	interp_block(); //Nota 118, 788
	get_token();
	if(tok!=WHILE) sntx_err(WHILE_EXPECTED);
	eval_exp(&cond); //Nota 119, 788
	if(cond) prog = temp; //Nota 120, 788
}

//Nota 121, 788
void find_eob(void)
{
	int brace;
	
	get_token();
	brace = 1;
	do {
		get_token();
		if(*token=='{') brace++;
		else if(*token=='}') brace--;
	} while(brace);
}

//Nota 122, 788
void exec_for(void){
	int cond;
	char *temp, *temp2;
	int brace;
	
	get_token();
	eval_exp(&cond); //Nota 123, 788
	if(*token!=';')  sntx_err(SEMI_EXPECTED);
	prog++; //Nota 124, 788
	temp = prog;
	for(;;){
		eval_exp(&cond); //Nota 127, 788
		if(*token!=';') sntx_err(SEMI_EXPECTED);
		prog++; //Nota 128, 788
		temp2 = prog;
		
		//Nota 129, 788
		brace = 1;
		while(brace) {
			get_token();
			if(*token=='(') brace++;
			if(*token==')') brace--;
		}
		
		if(cond) interp_block(); //Nota 130, 789 (1989)
		else { //Nota 131, 789
			find_eob();
			return;
		}
		prog = temp2;
		eval_exp(&cond); //Nota 132, 789
		prog = temp; //Nota 133, 789
	}
}

