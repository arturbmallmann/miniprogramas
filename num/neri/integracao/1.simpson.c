#include<math.h>
#include<stdio.h>
#define N 100
#define A 0
#define B 2*M_PI
double funcao(double x){
	//double res = exp(x)/pow((x +1),2);
	double res = x * sin(x);
	printf("f(%lf) = %lf\n",x,res);
	return res;
}

int main(){
	double sum=0;
	double final, h=(B-A)/N;
	printf("h: %lf\n",h);
	sum = funcao(A);
	for(int i=1; i < N; i++){
		double val = funcao(A+h*i);
		sum += i%2==0 ? 2*val:4*val;
	}
	sum += funcao (A+h*N);
	final = h/3 * sum;
	printf("Valor é igual a: %.12lf \n", final);
}
