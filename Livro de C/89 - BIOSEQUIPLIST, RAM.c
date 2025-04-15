#include <stdio.h>
#include <bios.h>

void acionador_disco_flex(void);
void memoria_ram(void);

void main(void)
{
	acionador_disco_flex();
	memoria_ram();
}

void acionador_disco_flex(void){
	unsigned eq;
	eq = _bios_equiplist();
	eq >>= 6;
	printf("### ACIONARDOR DE DISCO EM DOS ### \n");
	printf("Numero de acionadores de disco: %d", (eq & 3)+1);
}

void memoria_ram(void){
	printf("### MEMORIA RAM DISPONIVEL ### \n");
	printf("%u bytes de memoria ram", _bios_memsize());
}
