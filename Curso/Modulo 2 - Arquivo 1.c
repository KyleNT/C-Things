#include <stdio.h>
#include <stdlib.h>
//Computar = Calcular
/*
Input = Entrada
Output = Sa�da

Input -> Computado -> Output

*/

/*
C�digo totalmente opcional, mas d� para ter um entendimento
*/
int main(){
	
	float a = 7.5, b = 2.54;
	
	float resultado = a * b;
	
	printf("Resultado: %.2f", resultado);
	
	return 0;
}

// + - * /
//#include <stdlib.h> aloca��o de mem�ria e alguns c�lculos matem�ticos
//Printf imprime
//Imprimir um inteiro: "%d", vari�vel
//Imprimir v�rias vari�veis: "%d, %d", vari�vel1, vari�vel2

/*
Computar: Calcular seguindo regras
Algoritmo: Conjunto de comandos a serem seguidos em determinada ordem
IDE: O programa de computador usado para escrever c�digos
Compilador: Respons�vel por transformar o c�digo escrito por humanos em 010101
Vari�vel: Parte reservada na mem�ria do computador para armazenar valores
Input: Um valor que entra no programa
Output: Um valor que � retornado pelo programa
Fun��o: Um conjunto de comandos com determinada "Fun��o"
Biblioteca: Conjunto de fun��es

*/

/* Sequ�ncias de conver~soa de varo�veis
As principais seq��ncias de convers�o para vari�veis caracteres e inteiras s�o:

%c
imprime o conte�do da vari�vel com representa��o ASCII;
%d
imprime o conte�do da vari�vel com representa��o decimal com sinal;
%u
imprime o conte�do da vari�vel com representa��o decimal sem sinal;
%o
imprime o conte�do da vari�vel com representa��o octal sem sinal;
%x
imprime o conte�do da vari�vel com representa��o hexadecimal sem sinal.
Uma largura de campo pode ser opcionalmente especificada logo ap�s o car�ter %, como em %12d para especificar que o n�mero decimal ter� reservado um espa�o de doze caracteres para sua representa��o. Se a largura de campo for negativa, ent�o o n�mero ser� apresentado alinhado � esquerda ao inv�s do comportamento padr�o de alinhamento � direita. Para a convers�o de vari�veis do tipo long, o car�ter l tamb�m deve ser especificado, como em %ld.
Para converter vari�veis em ponto flutuante, as seq��ncias s�o:

%f
imprime o conte�do da vari�vel com representa��o com ponto decimal;
%e
imprime o conte�do da vari�vel com representa��o em nota��o cient�fica (exponencial);
%g
formato geral, escolhe a representa��o mais curta entre %f e %e.
*/
