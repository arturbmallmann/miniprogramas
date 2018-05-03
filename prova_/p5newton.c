#include <math.h>
#include <stdio.h>
long double eq(long double x){
	return ((10*x-8.3)*x+2.295)*x-0.21141;
}
long double deriv(long double x){
	return (30*x - 16.6)*x + 2.295;
}
long double newton(long double x1){
		
}
int check(long double a,long double b){
	long double dif = a-b;
	dif = dif > 0 ? dif: dif*-1;
	printf("err |%Lf - %Lf| = %Lf\n",a,b,dif);
	if(dif >= powl(10.,-5))
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
		printf("f(%Lg) = %Lg, f'=%Lg \n\n",x,eq(x),deriv(x));
		aux = x;
		x=aux - eq(x)/deriv(x);
		i++;
	}
	printf("\nraiz da equacao é: %Lg\niterações: %d\n",x,i);
}
