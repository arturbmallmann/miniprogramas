#include <math.h>
#include <stdio.h>
#include <string.h>

#define M 4
#define N 4
#define Er 4
void print_matrix(long double matrix[M][N], long double b[M]){
	for(int i=0;i<M;i++){
		printf("|");
		for(int k=0;k<N;k++)
			printf("%.2Lf	",matrix[i][k]);
		printf("|  |%.2Lf| \n",b[i]);
	}
	printf("\n");
}
long double sum(long double vet[M]){
	double sum =0;
	for (int i=0;i<M;i++)
		sum+= vet[i];
	return sum;
}
long double mod(long double x){
	return x<0? -1*x : x;
}
int main(){
//	printf("%d %d\n", sizeof(double),sizeof(long double));
	long double matriz[M][N]={{4, 2, 2, -1},{-1,5,0,-1},{1,-1,4,-1},{1,-1,1,-6}};
	long double b[M]={5,3,2,3};
	long double xm[M],xm1[M]={0,0,0,0};	//VALOR CHUTE
	int it=0;
	printf("insira os valores de chute md%Lf:\n",mod(-1.));
	for(int i=0; i < M ; i++)
		scanf("%Lf",&xm[i]);

	bool flag = 1;
	double erro =  powl(10.,-Er);

			printf("Erro: %lf matriz:\n",erro);
			print_matrix(matriz,b);
	while(mod(sum(xm) - sum(xm1)) > erro ||flag==1){
		for(int i=0;i<M;i++)
			xm1[i]=xm[i];
		printf("xm-1 %Lf xm %Lf\n\n",sum(xm1),sum(xm));
		flag = 0;

			for(int i=0; i <M ; i++){
				long double sum= 0.;
				
				for(int j=0;j<N;j++){
					if(j!=i){
						sum+=matriz[i][j]*xm1[j];
					}
				}
				xm[i]=(b[i]/matriz[i][i])-(sum/matriz[i][i]);
//			printf("b[%d]=%Lf sum=%Lf\n",i,b[i],sum);
			printf("i-1:	| %.4Lf |	i: |%.4Lf|\n",xm1[i],xm[i]);
			}
			printf("sum:	| %.4Lf |	i: |%.4Lf|\n",sum(xm1),sum(xm));
		printf("iteracoes: %d\n",++it);
	}
return 0;
}
