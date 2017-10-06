#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int V=10;
int A=10;
typedef unsigned int uint;
typedef struct{
	int v;
	int pai;
	uint valor;
	bool visto;
	bool check;
} ver;

void visit(int ** matrix,ver * vertices,const uint arrestas[], int vertice){
	ver atual = vertices[vertice];
	for (int a=0; a<A; a++){
		if(matrix[a][atual.v]!=0){
			for (int v=0; v<V; v++){
				if(v!=atual.v && matrix[a][v]!=0 && (atual.valor + arrestas[a]) < vertices[v].valor){
						vertices[v].pai=atual.v;
						vertices[v].valor=atual.valor + arrestas[a];
						vertices[v].visto=true;
				}
			}
		}
	}

}

void printMatrix(int ** matrix){
	printf("\nMatriz de incidencia\n");
	for(int v=0;v<V;v++){
		putchar('|');
		for(int a=0;a<A;a++){
			printf("%d	",matrix[a][v]);
		}
		printf("|\n");
	}	
}
void printInfo(const ver vertices[]){
	printf("\nINFO=================================\nvertices:	");	
	for(int i=0;i<V;i++)
		printf("%d	",vertices[i].v);
	printf("\nPai:		");
	for(int i=0;i<V;i++)
		printf("%d	",vertices[i].pai);
	printf("\nPeso:		");
	for(int i=0;i<V;i++)
		printf("%d	",vertices[i].valor);
	printf("\nCheck:		");
	for(int i=0;i<V;i++)
		printf("%s	",vertices[i].check ? "true":"false");
	printf("\nVisto:		");
	for(int i=0;i<V;i++)
		printf("%s	",vertices[i].visto ? "true":"false");

}
void printArrestas(const uint arrestas[]){
	printf("\n\nArrestas: ");
	for(int i=0;i<A;i++)
		printf("%c	",'a'+i);
	printf("\nPeso:	");
	for(int i=0;i<A;i++)
		printf("%d	",arrestas[i]);
	putchar('\n');

}
int main(){
		printf("entre o número de Vertices e Arrestas:\n");
		scanf("%d %d",&V,&A);
		uint arrestas[A];
		printf("Insira o peso de cada arresta:");
		for(int i;i<A;i++){
			printf("\narresta %c:\n",'a'+i);
			scanf("%d",&arrestas[i]);
		}
		int ** matrix = (int**) malloc(sizeof(void*)*A);
		int * mat = (int*)malloc(sizeof(int)*A*V);
		for(int a=0;a<A;a++){
			matrix[a]= mat + sizeof(int)*V*a;
	//		matrix[a]=(int*)malloc(sizeof(int)*V);
		}
		for(int v=0;v<V;v++){
			for(int a=0;a<A;a++){
				scanf("%d",&matrix[a][v]);
			}
		}	


		printMatrix(matrix);
		ver * vertices = (ver *) malloc(sizeof(ver)*V);
		for(int i=0;i<V;i++){
			ver * aux = &vertices[i];
			aux->v=i;
			aux->pai=-1;
			aux->valor=(uint)-1;
			aux->visto=false;
			aux->check=false;
		}
		printInfo(vertices);
		int first=0;
		printf("\nEscolha o vertice inicial\n");
		scanf("%d",&first);
		int restantes=V-1;
		ver * lol = &vertices[first];
		lol->pai=-1;
		lol->valor=0;
		lol->visto=true;
		lol->check=true;
		visit(matrix,vertices,arrestas,first);

			for(int i;restantes!=0;i++){
				i = i % V;
				ver * aux = &vertices[i];
				if(!aux->check && aux->visto){
					printf("\ni: %d",i);
					printInfo(vertices);
					printMatrix(matrix);
					restantes--;
					aux->check=true;
					visit(matrix,vertices,arrestas,i);
				}
					
			}
		printInfo(vertices);
		printArrestas(arrestas);
	return 0;
}
