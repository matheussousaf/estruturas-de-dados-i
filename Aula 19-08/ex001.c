#include <stdio.h>
#include <math.h>

int main(){
	int i;
	long long int res;
	
	for(i=0;i<15;i++){
		res = pow(3, i);
		printf("3 elevado a %d = %lli\n", i, res);
		res = 0;
	}
	return 0;
}
