#include<stdio.h>
#include<stdlib.h>
#define R 9 //huehuehueheuheuehueheue
int A[3][3]={{3,0,1},{1,-1,0},{3,1,R}};
int M[3][3]={{5,1,1},{3,4,1},{3,3,R}};
int D[8][8]=
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
int S[3][3]={{3,0,1},{1,-1,0},{3,1,2}};
int test(int dim,int m[][dim]){
    printf("matris %d x %d:\n",dim,dim);
    double * b = malloc(sizeof(double)*dim);
    double res=0;
    for (int i=0; i<dim; i++)
        b[i]=1.0;

    for (int l=0; l<dim; l++){//linha
        double sum=0, div=0;
        for (int c=0; c<dim; c++){//coluna
            printf("    %d * b[%.2f]",m[l][c],b[c]);
            if (c==l){
                putchar('/');
                div=m[l][c];
            }
            else
                sum+=m[l][c]*b[c];
        }
        res=sum/div;
        printf("        %f / %f = %f",sum,div,res);
        b[l]=res<0?-res:res;
        printf(" B[%d] %f\n",l,b[l]);
        if (res>=1)
            return 0;
    }
    return 1;
}
int main(){
    int ba = test(3,A);
    int bm = test(3,M);
    int bd = test(8,D);
	int bs = test(3,S);
    printf("Matris A %d\n Matris M %d\nMatris D %d\nMatris S %d\n",ba,bm,bd,bs);

    return 0;
}
