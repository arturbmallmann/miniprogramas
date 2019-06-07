#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;

#define R 9
int flag = pow(10,4);
long double eq(long double x){
	return ( cos(50*x + R) - sin(50*x -R));
}
long double deriv(long double x){
	return ( -50*( sin(50*x + R) + cos(50*x - R) ) );
}

int check(long double a,long double b){
	if(flag--==0){
		printf("execuções em excesso");
		exit(0);
	}
	long double dif = a-b;
	dif = dif > 0 ? dif: dif*-1;
//	printf("dif |%Lf - %Lf| = %Lf",a,b,dif);
	if(dif >= powl(10.,-10))
		return true;
	return false;
}
int main (){
	long double x,aux=0;
	int i=0;
	printf("Entre com valor de X0 \n");
	scanf("%Lg", &x);
	printf("%Lg\n", x);
	int first=1;
	while(check(x,aux)||first){
		first=0;
		printf("f(%Lg) = %Lg, f'=%Lg \n",x,eq(x),deriv(x));
		aux = x;
		x=aux - eq(x)/deriv(x);
		i++;
	}
	printf("\nraiz da equacao é: %Lg\niterações: %d\n",x,i);
}
