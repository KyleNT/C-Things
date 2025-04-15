
#include <stdio.h>

int main(void) {
    double f;
    int d = 0;
    for (f = 1.0; f < 1.0e+10; f *= 10){
    	printf("%d - 10 elevado a %d : %g \n", (d + 1), d, f);
    	d++;
	}
        
        
    return 0;
} 

