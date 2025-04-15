#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

void matinas(void);
void prima(void);
void terca(void);
void sexta(void);
void noa(void);
void vesperas(void);
void completas(void);

void oracao(void);
void oferecimento();

char sede[] = "Sede em meu favor, Virgem soberana, livrai-me do inimigo com o vosso valor.\nGlória seja ao Pai, ao Filho e ao Amor também, que é um só Deus em três Pessoas, agora e para sempre, e sem fim. Amém.";

int main(void){
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "C.UTF-8");
	
	struct tm *datal;
	time_t segundos;
	int tal = 5;
	
	time(&segundos);
	
	datal = localtime(&segundos);
	
	//printf("Hora: %d \n", datal->tm_hour);
	
	int tempo = tal * 1;
	//sleep(tempo);
	//printf("\nHora: %d", datal->tm_hour);
	
	int hora_santa = datal->tm_hour;
	
	char ch;

	printf("\nOração completa ou por horário? (c/h): ");
	ch = getche();

	if(toupper(ch) != 'C'){

	printf("\n\t\t\tOfício da Imaculada Conceição da Virgem Maria \n\n");
	
	if(hora_santa < 6) matinas();
	else if (hora_santa >= 6 && hora_santa < 9) prima();
	else if (hora_santa >= 9 && hora_santa < 12) terca();
	else if (hora_santa >= 12 && hora_santa < 15) sexta();
	else if (hora_santa >= 15 && hora_santa < 18) noa();
	else if (hora_santa >= 18 && hora_santa < 21) vesperas();
	else completas();

	oferecimento();

	} else {

	printf("\n\t\t\tOfício da Imaculada Conceição da Virgem Maria \n\n");
	matinas();
	prima();
	terca();
	sexta();
	noa();
	vesperas();
	completas();
	oferecimento();
	}
	
	return 0;
}

void oracao()
{
	char oracao[] = "Santa Maria, Rainha dos céus, Mãe de Nosso Senhor Jesus Cristo, Senhora do mundo, que a nenhum pecador desamparais nem desprezais; ponde, Senhora, em mim os olhos de Vossa piedade e alcançai-me de Vosso amado Filho o perdão de todos os meus pecados, para que eu que agora venero com devoção a Vossa santa e Imaculada Conceição, mereça na outra vida alcançar o prêmio da bem-aventurança, por mercê do Vosso benditíssimo Filho, Jesus Cristo, Nosso Senhor, que, com o Pai e o Espírito Santo, vive e reina para sempre. Amém.";
	
	printf("\n\t\t\tOração: \n");
	printf("%s \n", oracao);
	sleep(10);
}

void matinas(){
	char preintro[] = "Deus vos salve Virgem, Filha de Deus Pai!\nDeus vos salve Virgem, Mãe de Deus Filho!\nDeus vos salve Virgem, Esposa do Divino Espírito Santo!\nDeus vos salve Virgem, Templo e Sacrário da Santíssima Trindade!";
	char intro[] = "Agora, lábios meus, dizei e anunciai os grandes louvores da Virgem Mãe de Deus.";
	char matinas[] = "Deus vos salve, cidade de torres guarnecida de Davi, com armas bem fortalecida. De suma caridade sempre abrasada, do dragão a força foi por Vós prostrada. A mulher tão forte! A invicta Judite! Que Vós alentastes o sumo Davi. Do Egito, o curador de Raquel nasceu; do mundo, o Salvador Maria no-Lo deu. Toda é formosa minha companheira, nela não há mácula da culpa primeira. Ouvi, Mãe de Deus, minha Oração. Toquem o Vosso peito os clamores meus.";
	
	printf("\n\t\t\tMatinas e Laudes (Manhã e Madrugada): \n");
	printf("%s \n", preintro);
	printf("%s \n", intro);
	printf("%s \n", sede);
	printf("%s \n", matinas);
	sleep(10);
	oracao();
}

void prima(){
	char prima[] = "Deus vos salve, mesa para Deus ornada, coluna sagrada de grande firmeza; casa dedicada a Deus sempiterno, sempre preservada Virgem do pecado. Antes que nascida, foste, Virgem santa no ventre ditoso de Ana concebida. Sois Mãe criadora dos mortais viventes. Sois dos Santos porta; dos Anjos, Senhora. Sois forte esquadrão contra o inimigo, estrela de Jacó, refúgio do cristão. A Virgem, a criou Deus no Espírito Santo, e todas as suas obras com elas as ornou. Ouvi, Mãe de Deus, minha Oração. Toque Vosso peito os clamores meus.";
	printf("\n\t\t\tPrima (6:00): \n");
	printf("%s \n", sede);
	printf("%s \n", prima);
	sleep(10);
	oracao();
}

void terca(){
	char terca[] = "Deus Vos salve, trono do grão Salomão, arca de concerto, velo de Gedeão; Íris do céu clara, sarça de visão, favo de Sansão, florescente vara; a qual escolheu para ser Mãe sua, e de Vós nasceu o Filho de Deus. Assim Vos livrou da culpa original, nenhum pecado há em Vós sinal. Vós, que habitais lá nessas alturas, e tendes Vosso Trono sobre as nuvens puras, ouvi, Mãe de Deus, minha oração, toque em Vossos peitos os clamores meus.";
	printf("\n\t\t\tTerça (9:00): \n");
	printf("%s \n", sede);
	printf("%s \n", terca);
	sleep(10);
	oracao();
}

void sexta(){
	char sexta[] = "Deus Vos salve, Virgem de trindade templo, alegria dos anjos, da pureza exemplo; que alegrais os tristes com vossa clemência, horto de deleite, palma da paciência. Sois terra bendita e sacerdotal. Sois de castidade símbolo real. Cidade do Altíssimo, porta oriental, sois a mesma graça, Virgem singular. Qual lírio cheiroso, entre espinhas duras, tal sois Vós, Senhora entre as criaturas. Ouvi, Mãe de Deus, minha Oração. Toque em Vosso peito os clamores meus.";
	printf("\n\t\t\tSexta (12:00): \n");
	printf("%s \n", sede);
	printf("%s \n", sexta);
	sleep(10);
	oracao();
}

void noa(){
	char noa[] = "Deus vos salve, cidade de torres guarnecida de Davi, com armas bem fortalecida. De suma caridade sempre abrasada, do dragão a força foi por Vós prostrada. A mulher tão forte! A invicta Judite! Que Vós alentastes o sumo Davi. Do Egito, o curador de Raquel nasceu; do mundo, o Salvador Maria no-Lo deu. Toda é formosa minha companheira, nela não há mácula da culpa primeira. Ouvi, Mãe de Deus, minha Oração. Toquem o Vosso peito os clamores meus.";
	printf("\n\t\t\tNona (15:00): \n");
	printf("%s \n", sede);
	printf("%s \n", noa);
	sleep(10);
	oracao();
}

void vesperas(){
	char vesperas[] = "Deus vos salve, mesa para Deus ornada, coluna sagrada de grande firmeza; casa dedicada a Deus sempiterno, sempre preservada Virgem do pecado. Antes que nascida, foste, Virgem santa no ventre ditoso de Ana concebida. Sois Mãe criadora dos mortais viventes. Sois dos Santos porta; dos Anjos, Senhora. Sois forte esquadrão contra o inimigo, estrela de Jacó, refúgio do cristão. A Virgem, a criou Deus no Espírito Santo, e todas as suas obras com elas as ornou. Ouvi, Mãe de Deus, minha Oração. Toque Vosso peito os clamores meus.";
	printf("\n\t\t\tVésperas (18:00): \n");
	printf("%s \n", sede);
	printf("%s \n", vesperas);
	sleep(10);
	oracao();
}

void completas(){
	char rogai[] = "Rogai a Deus, Vós, Virgem, nos converta, que a sua ira aparte de nós.";
	char prima[] = "Deus Vos salve, Virgem Imaculada, Rainha de clemência, de estrelas coroada. Vós sobre os Anjos sois purificada; de Deus à mão direita estais de ouro ornada. Por Vós, Mãe de graça, mereçamos ver a Deus nas alturas, com todo prazer. Pois sois esperança dos pobres errantes, e seguro porto dos navegantes. Estrela do mar e saúde certa, e porta que estais para o céu aberta. É óleo derramado, Virgem, Vosso nome, e os vossos servos vos hão sempre amado. Ouvi, Mãe de Deus, minha Oração. Toquem Vosso peito os clamores meus.";
	printf("\n\t\t\tCompletas (21:00): \n");
	printf("%s \n", rogai);
	printf("%s \n", sede);
	printf("%s \n", prima);
	sleep(10);
	oracao();
}

void oferecimento(){
	char oferecimento[] = "Humildes, oferecemos a Vós, Virgem pia, essas orações, porque, em nossa guia, vades Vós adiante. E na agonia, Vós nos animeis, ó doce Virgem Maria. Amém.";
	printf("\n\t\t\tOferecimento: \n");
	printf("%s \n", oferecimento);

}
