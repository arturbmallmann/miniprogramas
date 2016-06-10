#include<stdio.h>
int entradas;
struct{
	int * v;
	int tam;
}typedef vet;
void printv(vet &vet){
	for(int i=0;i<vet.tam;i++){
		printf("%d ",vet.v[i]);
	}
	putc('\n',stdout);
}
void sort(vet &v){
	printv(v);
	if(v.tam > 1){
			vet v1;
			vet v2;
			v1.tam=v.tam/2;
			v2.tam=v.tam/2;
			v1.v=v.v;
			v2.v=v.v + sizeof(int)*v2.tam - sizeof(int);
			sort(v1);
			sort(v2);
			int aux[tamanho],a=0,b=0,i=0;
			while(i<v.tam){
				if(v1.v[a] < v2.v[b])
					aux.v[i++]=v1.v[a++];
				else
					aux.v[i++]=v2.v[b++];
			}
			strcpy(v.v,aux,v.tam*sizeof(int));
		}else
		return;
}

int main(){
	scanf("%d",&entradas);
	int valores[entradas];
	for(int i=0;i<entradas;i++)
		scanf("%d",&valores[i]);
	vet v;
	v.v=valores;
	v.tam=entradas;
	sort(v);
	printv(v);
	return 0;
}
