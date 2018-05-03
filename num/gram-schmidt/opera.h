#ifndef LER_ARQUIVO_H
#define LER_ARQUIVO_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct{
	int l,c;
	long double vet[10][10];
} typedef matriz;
void lermatriz(FILE * stream, matriz &m);
long double prodint(long double * vet1[],long double * vet2[],int g);
long double * prodext(long double * vet,long double val,int g);
void sumvet(long double * dest, long double * vet1,long double * vet2,int g);
matriz * gs(matriz &v);
void copyv(long double *dest,long double *origin, int n);
#endif
