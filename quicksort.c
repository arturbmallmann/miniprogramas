#include<stdio.h>
#include<stdlib.h>
struct{
	int * v;
	int tam;
}typedef vet;
void printv(vet * vet){
	for(int i=0;i<vet->tam;i++){
		printf("%d ",vet->v[i]);
	}
	putc('\n',stdout);
}
void sort(vet * v){
	printf("Antes\n:");
	printv(v);
	if(v->tam > 1){
			vet * v1=(vet*)malloc(sizeof(vet));
			vet * v2=(vet*)malloc(sizeof(vet));
			v1->tam=v->tam/2;
			v2->tam=v->tam/2;
			v1->v=v->v;
			v2->v=v->v + sizeof(int)*v2->tam - sizeof(int);
			sort(v1);
			sort(v2);
			int aux[v->tam];
			int a=0,b=0,i=0;
			while(i<v->tam){
				if(v1->v[a] < v2->v[b])
					aux[i++]=v1->v[a++];
				else
					aux[i++]=v2->v[b++];
			}
			strncpy((char*)v->v,(char*)&aux,v->tam*sizeof(int));
		}else
		return;
}

int main(){
	int entradas;
	printf("Qual será o tamanho do vetor?\n");
	scanf("%d",&entradas);
	int valores[entradas];
	printf("Forneça os valores");
	for(int i=0;i<entradas;i++)
		scanf("%d",&valores[i]);
	vet v;
	v.v=valores;
	v.tam=entradas;
	sort(&v);
	printf("depois:\n");
	printv(&v);
	return 0;
}
