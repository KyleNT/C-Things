/*
ax² + bx + c = 0

x1 = -b + sqrt(b²-4ac)/2a
x2 = -b - sqrt(b²-4ac)/2a

*/

#include <stdio.h>
#include <math.h>
#include <time.h>

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

int main(){
	double a = 0, b = 0, c = 0, dp = 0, dn = 0, dpvat = 0;
	
	int count = 0;
	int volante = 80;
	
	float ponto_de_parada = 60000/volante;
		
		
	while(count < volante){
		a = count;
		b = -(count)+2;
		c = b*2;
		
		dp = ((-b) + sqrt(pow(b, 2) - 4 * a * c))/ (2*a);
		dn = ((-b) - sqrt(pow(b, 2) - 4 * a * c))/ (2*a);
		
		dpvat = dn/dp;
		
		printf("A: %0.lf, B: %0.lf, C: %0.lf, ", a, b, c);
		printf("dp: %.5lf, dn: %.5lf, dpvat: %.5lf \n", dp, dn, dpvat);
		delay(ponto_de_parada);
		count++;
	}
	
	return 0;
}
