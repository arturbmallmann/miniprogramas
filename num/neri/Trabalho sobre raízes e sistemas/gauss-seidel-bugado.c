#include <math.h>
#include <stdio.h>
#include <string.h>
	int m,n;
void print_matrix(long double ** matrix, long double * b){
	for(int i=0;i<m;i++){
		printf("|");
		for(int k=0;k<n;k++)
			printf("%Lf	",matrix[i][k]);
		printf("|  |%Lf| \n",b[i]);
	}
	printf("\n");
}
int main(){
//	printf("%d %d\n", sizeof(double),sizeof(long double));
	printf("entre o tamanho da matris(_x_)");
	scanf("%d %d",&m,&n);
//	long double matriz[3][3]={{5, -2, -1},{1,-4,2},{1,+2,+4}};
//	long double b[3]={2,-2,7};
	long double ** matriz = (long double**) malloc(sizeof(long double)*m*n);
	printf("entre os valores da matriz");
	for(int i=0;i<m;i++){
		printf("\nlinha %d:	",i+1);
		for(int o=0;o<n;o++){
			scanf("%Lf",&matriz[i][o]);
		}
	}
	long double b[n];
	long double x[n];	
//	for(
	//printf("%Lf", powl(10.,-5));
	print_matrix(matriz,b);
	for(int k=0;k<n;k++)
	{
		int zero=0;
		while(matriz[k][k] == 0){
			zero++;
			long double aux[n],baux;
			strncpy((char*)&aux,(char*)&matriz[k],sizeof(long double )*3);
			strncpy((char*)&matriz[k],(char*)matriz[k+zero],sizeof(long double)*3);
			strncpy((char*)&matriz[k+zero],(char*)&aux,sizeof(long double)*3);
			baux=b[k];
			b[k]=b[k+zero];
			b[k+zero]=baux;
		}
		fflush(stdout);
		printf("chegou aqui 1\n");
		for(int i=0;i<3;i++){
			if(i!=k){
				long double Mik = matriz[i][k]/matriz[k][k];
			//	matriz[i][k]=0;
				for(int j=0;j<3;j++)
					//if(j!=i && i!=k)
						matriz[i][j]=Mik*matriz[k][j] - matriz[i][j];
			}
		}
	}
	printf("chegou aqui 2\n");
	fflush(stdout);
	print_matrix(matriz,b);	
	long double Xj=matriz[m][n];
	for(int i=0; i <3 ; i++){
		long double lol = 0;
		
		for(int k=0;k<5;k++){
			if(k!=i)
			lol+=matriz[k][i]*Xj;
		}
		Xj=b[i]-lol/matriz[i][i];
		printf("| %lf |\n",Xj);
	}

}
