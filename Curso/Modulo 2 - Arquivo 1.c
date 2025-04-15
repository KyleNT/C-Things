#include <stdio.h>
#include <stdlib.h>
//Computar = Calcular
/*
Input = Entrada
Output = Saída

Input -> Computado -> Output

*/

/*
Código totalmente opcional, mas dá para ter um entendimento
*/
int main(){
	
	float a = 7.5, b = 2.54;
	
	float resultado = a * b;
	
	printf("Resultado: %.2f", resultado);
	
	return 0;
}

// + - * /
//#include <stdlib.h> alocação de memória e alguns cálculos matemáticos
//Printf imprime
//Imprimir um inteiro: "%d", variável
//Imprimir várias variáveis: "%d, %d", variável1, variável2

/*
Computar: Calcular seguindo regras
Algoritmo: Conjunto de comandos a serem seguidos em determinada ordem
IDE: O programa de computador usado para escrever códigos
Compilador: Responsável por transformar o código escrito por humanos em 010101
Variável: Parte reservada na memória do computador para armazenar valores
Input: Um valor que entra no programa
Output: Um valor que é retornado pelo programa
Função: Um conjunto de comandos com determinada "Função"
Biblioteca: Conjunto de funções

*/

/* Sequências de conver~soa de varoáveis
As principais seqüências de conversão para variáveis caracteres e inteiras são:

%c
imprime o conteúdo da variável com representação ASCII;
%d
imprime o conteúdo da variável com representação decimal com sinal;
%u
imprime o conteúdo da variável com representação decimal sem sinal;
%o
imprime o conteúdo da variável com representação octal sem sinal;
%x
imprime o conteúdo da variável com representação hexadecimal sem sinal.
Uma largura de campo pode ser opcionalmente especificada logo após o caráter %, como em %12d para especificar que o número decimal terá reservado um espaço de doze caracteres para sua representação. Se a largura de campo for negativa, então o número será apresentado alinhado à esquerda ao invés do comportamento padrão de alinhamento à direita. Para a conversão de variáveis do tipo long, o caráter l também deve ser especificado, como em %ld.
Para converter variáveis em ponto flutuante, as seqüências são:

%f
imprime o conteúdo da variável com representação com ponto decimal;
%e
imprime o conteúdo da variável com representação em notação científica (exponencial);
%g
formato geral, escolhe a representação mais curta entre %f e %e.
*/
