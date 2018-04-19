#include "opera.h"

void lermatriz(FILE * stream, matriz &m){
	for(int i=0; i < m.l ;i++){
		putc('(',stream);
		int o;
		for(o=0; o < m.c-1 ;o++)
			fprintf(stream,"%LF,",m.vet[i][o]);
		fprintf(stream,"%LF)\n",m.vet[i][o]);
	}
}
void copyv(long double *dest,long double *origin, int n){
	for(int i=0;i<n;i++)
		dest[i]=origin[i];
}
long double prodint(long double * vet1,long double * vet2,int g){
	int res=0;
	for(int i=0;i<g;i++){
		res+=vet1[i]*vet2[i];
	}
	return res;
}
long double * prodext(long double * vet,long double val,int g){
	long double * res=(long double *)malloc(sizeof(long double)*g);
	for(int i=0;i<g;i++){
		res[i]=vet[i]*val;
	}
	return res;
}
void sumvet(long double * dest, long double * vet1,long double * vet2,int g){
	for(int i=0;i<g;i++){
		dest[i]=vet1[i]+vet2[i];
	}
}

matriz * gs(matriz &v){ //classico
	matriz * w = (matriz *) malloc(sizeof(matriz));
	w->l=v.l;
	w->c=v.c;
	for(int i=0;i<v.l;i++)
		copyv(w->vet[i],v.vet[i],v.c);
	for(int i=1;i<v.l;i++){
			long double valor = prodint(w->vet[i-1],w->vet[i],v.c);
			long double div = prodint(w->vet[i],w->vet[i],v.c);
			printf("%LF / %LF = ", valor,div);
				valor/=div;
				printf("%LF\n", valor);
				sumvet(w->vet[i],w->vet[i],prodext(w->vet[i],valor * -1,v.c),v.c); //soma Vk
	}

	return w;
}


// matriz * gs(matriz &v){ //classico
// 	matriz * w = (matriz *) malloc(sizeof(matriz));
// 	w->l=v.l;
// 	w->c=v.c;
// 	copyv(w->vet[0],v.vet[0],v.c);
// 	for(int i=1;i<v.l;i++){
// 		printf("%d\n", i);
// 		copyv(w->vet[i],v.vet[i],v.c);
// 		for(int o=i;o>0;o--){
// 			printf("o: %d\n", o-1	);
// 			double valor = prodint(v.vet[i],w->vet[o-1],v.c);
// 			printf("%lf / ", valor);
// 			double div = prodint(w->vet[o],w->vet[o],v.c);
// 			printf("%lf\n", div);
// 			if(div!=0){
// 				valor/=div;
// 				sumvet(w->vet[i],w->vet[i],prodext(w->vet[o],valor * -1,v.c),v.c);
// 			}else
// 				sumvet(w->vet[i],w->vet[i],prodext(w->vet[0],0,v.c),v.c);
// 		}
// 	}
// 	return w;
// }
