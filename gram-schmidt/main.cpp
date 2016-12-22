#include <stdio.h>
#include <stdlib.h>

#include "opera.h"

int main (){
	FILE* f = fopen("ortogonaliza.txt","r+");
//	long mat[10][10];
	matriz m;
	m.l=5;
	m.c=5;
	char temp=0;
	char num[10];
	int vcount=0;

	while(!feof(f)){
//		getc(f);
		if(getc(f)=='('){
	//		printf("entrou\n");
//			/*

			int col=0;
			int si=0;//string index
			while((temp=getc(f)) && temp!=')'){
	//			fprintf(stdout,"%c",temp);
				fflush(stdout);
				if(temp == ','){
					num[si++]='\0';
					m.vet[vcount][col] = (long double) atol(num);
					col++;
					si=0;
				}else
					num[si++]=temp;
			}
			num[si++]='\0';
			m.vet[vcount][col] = (long double) atol(num);
			vcount++;
//			*/
		}
	}
	//*/
	printf("acabou\n");
	lermatriz(stdout,m);
	printf("===============\n");
	lermatriz(f,*gs(m));
	//printf("produto interno de 0 e 1: %.2lf\n",prodint(m.vet[0],m.vet[1],m.c));
	return 0;
}
