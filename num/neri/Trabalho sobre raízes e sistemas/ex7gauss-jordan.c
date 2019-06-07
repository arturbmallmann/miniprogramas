#include <math.h>
#include <stdio.h>
#include <string.h>
#define M 8
#define N 8
#define E 10
#define R 9
void print_2matrix(long double matrix[M][N], long double adjunta[M][N]){
	for(int i=0;i<M;i++){
		printf("|");
		for(int k=0;k<N;k++)
			printf("%.3Lf	",matrix[i][k]);
		printf("|  || ");
		for(int k=0;k<N;k++)
			printf("%.3Lf	",adjunta[i][k]);
		printf("|  || \n");
	}
	printf("\n");
}
void print_matrix(long double matrix[M][N]){
	for(int i=0;i<M;i++){
		printf("\n|");
		for(int k=0;k<N;k++)
			printf("%.3Lf	",matrix[i][k]);
	}
	putchar('\n');
}
int main(){
//	printf("%d %d\n", sizeof(double),sizeof(long double));
	
	long double matrix[M][N]=
{
    {   4, 1,-1, 0, 0, 0, 0, 0},
    {   1, 6,-2, 1,-1, 0, 0, 0},
    {   0, 1, 5, 0,-1, 0, 0, 0},
    {   0, 2, 0, 5,-1, 1,-1,-1},
    {   0, 0,-1,-1, 6, 0, 0,-1},
    {   0, 0,-1, 0,-1,-1, 0, 0},
    {   0, 0, 0,-1, 0, 5, 4,-1},
    {   0, 0, 0,-1,-1, 0,-1, 5}
};


	long double A[M][N];
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			A[i][j]= i==j?1:0;//povoar a inversa!!!
	printf("matrizes antes:\n");
	print_2matrix(matrix,A);
//	return 0;
//}
///*


//	for(
	//printf("%Lf", powl(10.,-5));
	for(int k=0;k<N;k++)//operação com o pivo
	{
		for(int i=0;i<M;i++){
			if(i!=k){
				long double Mik = matrix[i][k]/matrix[k][k];//zera os adjacentes ao pivo em todas as linhas
			//	matrix[i][k]=0;
				for(int j=0;j<N;j++)
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
	printf("matrizes depois:\n");
	print_2matrix(matrix,A);
//transforma a primeira matriz em identidade
	for(int i=0;i<M;i++){
		if (matrix[i][i]!=1.0){
			long double aux = matrix[i][i];
			for(int j=0;j<N;j++){
				matrix[i][j] = matrix[i][j] / aux;
				A[i][j] = A[i][j]/aux;
			}
		}
	}
	printf("primeira matriz convertida em Identidade\n");
	print_2matrix(matrix,A);
	printf("agora multiplico por rI ou seja x,y,z etc .. por r=%d\n",R);
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			A[i][j]=A[i][j]*R;
	print_matrix(A);
	fflush(stdout);
	

}
//*/
