#include <stdio.h>
#include <string.h>

int get_int_from_modem(int a);
int get_int_from_timer(int a);
int get_int_from_tile(int a);
int move_1_bit_left(int a);
int move_1_bit_right(int a);
void moving();
char* codificar(char estringulo[100]);
char* decodificar(char destringulo[100]);


void main(void){
	int getANDBit, getORBit, getXORBit, move1bleft, move1bright;
	int buffer = 7;
	char prometus[100] = "Nora Judith";
	
	getANDBit = get_int_from_modem(buffer);
	getORBit = get_int_from_timer(buffer);
	getXORBit = get_int_from_tile(buffer);
	move1bleft = move_1_bit_left(buffer);
	move1bright = move_1_bit_right(buffer);
	
	char stringola[100]; 
	char destringola[100];
	
	strcpy(stringola, codificar(prometus));
	strcpy(destringola, decodificar(stringola));
	
	printf("%d AND 127: %d \n", buffer, getANDBit);
	printf("%d OR 127: %d \n", buffer, getORBit);
	printf("%d XOR 127: %d \n", buffer, getXORBit);
	printf("%d Moved 1 bit to left: %d \n", buffer, move1bleft);
	printf("%d Moved 1 bit to right: %d \n", buffer, move1bright);
	
	moving();
	
	printf("Codificado: %s \n", stringola);
	printf("Decodificado: %s \n", destringola);
	
}

get_int_from_modem(int a){
	return (a & 127);
}

get_int_from_timer(int a){
	return (a | 127);
}

get_int_from_tile(int a){
	return (a ^ 127);
}

move_1_bit_left(int a){
	return (a << 1);
}

move_1_bit_right(int a){
	return (a >> 1);
}

void moving(){
  unsigned int i;
  int j;
  i = 14;

  for(j=0; j<4; j++){
    i = i << 1;
    printf("Deslocamento a Europa Ocidental %d: %d\n", j, i);
  }

  for(j=0; j<4; j++){
    i = i >> 1;
    printf("Deslocamento a China %d: %d\n", j, i);
  }
}

char* codificar(char estringulo[100]){
	static char estringue[100];
	int i;
	
	for(i = 0; estringulo[i] != '\0'; i++){
		estringue[i] = ~estringulo[i];
	}
	estringue[i] = '\0';
	
	return (estringue);
}

char* decodificar(char destringulo[100]){
	static char destringue[100];
	int j;
	
	for(j = 0; destringulo[j] != '\0'; j++){
		destringue[j] = ~destringulo[j];
	}
	destringue[j] = '\0';
	
	return (destringue);
}
