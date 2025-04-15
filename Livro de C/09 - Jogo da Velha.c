#include <stdio.h>
#include <stdlib.h>

#define LINHA 3
#define COLUNA 3

char matrix[LINHA][COLUNA];

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

void main(void){
	char done;
	
	printf("Este e o jogo-da-velha. \n");
	printf("Voce estara jogando contra o computador. \n");
	
	do{
		done = ' ';
		init_matrix();
		get_player_move();
		printf("Movido! \n");
		done = check(); //Verifica se há vencedor
		if(done!=' ') break; //Vencedor!
		get_computer_move();
		printf("PC Movido! \n"); 
		done = check(); //Verifica se ha vencedor
		disp_matrix();

	} while(done == ' ');
	if (done=='X') printf("Voce e bem branco");
	else printf("Sou mais branco que voce!!!\n");
	disp_matrix(); //Posicoes finais
}

//Inicializa a matriz
void init_matrix(void){
	int i, j;
	
	for(i = 0; i<LINHA; i++)
		for(j=0; j<COLUNA; j++) matrix[i][j] = ' ';
}

//Obtem a sua jogada
void get_player_move(void){
	int x, y;
	printf("Digite as coordenadas para X:");
	scanf("%d%d", &x, &y);
	
	x--; y--;
	
	if(matrix[x][y] != ' '){
		printf("Posicao invalida. Tente novamente \n");
		get_player_move();
	}
	else matrix[x][y] = 'X';
}

//Obtém uma jogada do computador
void get_computer_move(void){
	int i, j;
	for(i=0; i<LINHA; i++){
		for(j=0; j<COLUNA; j++)
			if(matrix[i][j]==' ') break;
		if(matrix[i][j]==' ') break;
	}
	
	if(i*j==(LINHA * COLUNA)){
		printf("Ninguem e branco\n");
		exit(0);
	}
	else
		matrix[i][j] = 'O';
}

//Mostra a matriz da Tela
void disp_matrix(void){
	int t;
	
	for(t=0; t<LINHA; t++){
		printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
		if(t!=(2)) printf("\n---|---|---|\n");
	}
	
	printf("\n");
}

//Verifica se há um vencedor
char check(void){
	int i;
	
	for(i=0; i<LINHA; i++) //Verifica as linhas
		if(matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2]) return matrix[i][0];
		
	for(i=0; i<LINHA; i++) //Verifica as linhas
		if(matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i]) return matrix[0][i];
		
	//Testa as diagonais
	if(matrix[0][0] == matrix[1][1] && matrix[1][1]==matrix[2][2]) return matrix[0][0];
	if(matrix[0][2] == matrix[1][1] && matrix[1][1]==matrix[2][0]) return matrix[0][2];
	
	return ' ';
}
