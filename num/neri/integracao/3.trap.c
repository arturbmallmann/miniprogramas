#include <math.h>
#include <stdio.h>
#define A 0. //ponto A
#define B 2.* M_PI  //ponto B
#define N 1200. //numero de pontos
#define H (B-A)/N //calcula o passo já...

long double fun(long double x){ //funcao que será utilizada:
	return x * sin (x);
}
int main(){
	printf("Tamanho de H: %f\n", H);
    long double sum = 0, integral;
    for(int i=0;i<=N;i++){
        long double t = H*i+A,fx;
        printf("x = %Lf ",t);
		fx=fun(t);
		printf("fx = %Lf * ",fx);
		if(i==0 || i==N){
			printf("1\n");
			sum+=fx;//soma o primeiro e o último uma única vez
		}
		else{
			printf("2\n");
        	sum+=2*fx; //soma os restantes duas
		}
    }
	integral = (H * sum)/2;
    printf("Integral da funcao = %LF\n",integral);

	return 0;
}
