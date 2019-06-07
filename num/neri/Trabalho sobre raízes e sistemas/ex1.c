#include<stdio.h>
#define D 5
#define A 7
int main(){
    int mat=1511100032;
    printf("%d + (%d mod %d)=%d\n",A,mat,D,A+mat%D);

} 
