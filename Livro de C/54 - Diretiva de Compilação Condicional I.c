#include <stdio.h>

#line 100
#define MAX 45

#define EUA 0
#define INGLATERRA 1
#define FRANCA 2

#define PAIS_ATIVO EUA

#define MAXWELL 99

#define DAG 1

void main(void)
{
	#if MAX>99
	printf("Compilado para matriz maior que 99. \n");
	#else
	printf("Compilado para uma matriz menor que 45. \n");
	#endif
	
	#if PAIS_ATIVO==EUA
		char circulante[]="dollar";
	#elif PAIS_ATIVO==INGLATERRA
		char circulante[]="pound";
	#else
		char circulante[]="euro";
	#endif
	printf(circulante);
	
	#if MAXWELL > 100
		#if SERIAL_VERSION
			int port=198;
		#elif
			int port=200;
		#endif
		#else
			int port=1;
			//char out_buffer[100];
	#endif
	printf("\nPorta: %d \n", port);
	
	//Não está definido
	#ifndef __TALTBRO__
		printf("\nTALTBRO não definido\n");
	#endif
	
	//Esta definido
	#ifdef EUA
		printf("EUA \n");
	#else
		printf("Nao e EUA \n");
	#endif
	
	//ifndef
	#if !defined STARLY
		printf("Versao Final\n");
	#endif
	
	//ifdef
	#if defined STARLY
		printf("Versao Inicial\n");
	#endif
	
	#undef DAG
	
	printf("%d \n", __LINE__); //Linha atual sendo compilada
	
}
