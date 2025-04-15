#include <stdio.h>

int main(){

	int count = 48;
	int divisor = 4;
	
	while(count >= 0){
		
		if(count % divisor == 0){
			printf("---> %d / %d = %d <--- \n", count, divisor, count/divisor);
		} else {
			printf("%d nao e divisivel por %d. \n", count, divisor);
		}
		count = count - 6;
	}
	
	return 0;

}


