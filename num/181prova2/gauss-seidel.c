#include <math.h>
#include <stdio.h>
#include <string.h>

#define M 20
#define N 20
#define Er 2
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
void gera_matriz(long double matriz[M][N], long double b[M]){
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if (i==j)
				matriz[i][j]=4;
			else if(i-j==1||i-j==-1)
				matriz[i][j]=-1;
			else matriz[i][j]=0;
		}
		b[i]=0;
	}
	matriz[0][N-1]=1;
	matriz[N-1][0]=1;
	b[N-1]=100;
}
int main(){
//	printf("%d %d\n", sizeof(double),sizeof(long double));
	long double matriz[M][N];//={{4, 2, 2, -1},{-1,5,0,-1},{1,-1,4,-1},{1,-1,1,-6}};
	long double b[M];//={5,3,2,3};
	long double xm[M];//,xm1[M]={0,0,0,0};	//VALOR CHUTE
	gera_matriz(matriz,b);
	print_matrix(matriz,b);
	int it=0;

//	printf("insira os valores de chute md%Lf:\n",mod(-1.));
	for(int i=0; i < M ; i++)
		xm[i]=0;
//		scanf("%Lf",&xm[i]);

	double erro =  powl(10.,-10);

			printf("Erro: %lf matriz:\n",erro);
			print_matrix(matriz,b);
	long double old = powl(2,63);
	while(mod(old - sum(xm)) > erro){
//		for(int i=0;i<M;i++)
//			xm1[i]=xm[i];
		old = sum(xm);
			for(int i=0; i <M ; i++){
				long double sum= 0.;
				
				for(int j=0;j<N;j++){
					if(j!=i){
						sum+=matriz[i][j]*xm[j];
					}
				}
				xm[i]=(b[i]/matriz[i][i])-(sum/matriz[i][i]);
//			printf("b[%d]=%Lf sum=%Lf\n",i,b[i],sum);
			printf("i: |%.4Lf|\n",xm[i]);
			}
			printf("sum:	i: |%.4Lf|\n",sum(xm));
		printf("iteracoes: %d\n Erro: %d",++it,erro);
	}
return 0;
}
