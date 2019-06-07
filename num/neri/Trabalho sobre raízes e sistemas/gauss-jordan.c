#include <math.h>
#include <stdio.h>
#include <string.h>
#define M 3
#define N 3
#define E 10
void print_matrix(long double matrix[M][N], long double adjunta[M][N]){
	for(int i=0;i<M;i++){
		printf("|");
		for(int k=0;k<N;k++)
			printf("%.10Lf	",matrix[i][k]);
		printf("|  || ");
		for(int k=0;k<N;k++)
			printf("%.10Lf	",adjunta[i][k]);
		printf("|  || \n");
	}
	printf("\n");
}
int main(){
//	printf("%d %d\n", sizeof(double),sizeof(long double));
	
	long double matrix[M][N]={
								{ 3, 0, 1},
								{ 1,-1, 0},
								{ 3, 1, 2}
							};
	long double A[M][N]={//matrix inversa
								{ 1, 0, 0},
								{ 0, 1, 0},
								{ 0, 0, 1}
							};
	print_matrix(matrix,A);
//	return 0;
//}
///*


//	for(
	//printf("%Lf", powl(10.,-5));
	for(int k=0;k<N;k++)
	{
		for(int i=0;i<3;i++){
			if(i!=k){
				long double Mik = matrix[i][k]/matrix[k][k];
			//	matrix[i][k]=0;
				for(int j=0;j<3;j++)
					//if(j!=i && i!=k)
					if(Mik==0){
						matrix[i][j]=0 - matrix[i][j];
						A[i][j]=0 - A[i][j];
					}else{
						matrix[i][j]= Mik*matrix[k][j] - matrix[i][j];//não tem pq multiplicar por zero...
						A[i][j]=Mik*A[k][j] - A[i][j]; 
					}
			}
		}
	}
	print_matrix(matrix,A);
	printf("chegou aqui 2\n");
	fflush(stdout);
	

}
//*/
