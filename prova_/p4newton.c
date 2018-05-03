#include <math.h>
#include <stdio.h>
long double eq(long double x){
	return 1/2+1/4*pow(x,2)-x*sin(x)-1/2*cos(2*x);
}
long double deriv(long double x){
	return x/2 - sin(x)-x*cos(x)+sin(2*x);
}
long double newton(long double x1){
		
}
int check(long double a,long double b){
	long double dif = a-b;
	dif = dif > 0 ? dif: dif*-1;
//	printf("dif |%Lf - %Lf| = %Lf",a,b,dif);
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
		printf("f(%Lg) = %Lg, f'=%Lg \n",x,eq(x),deriv(x));
		aux = x;
		x=aux - eq(x)/deriv(x);
		i++;
	}
	printf("\nraiz da equacao é: %Lg\niterações: %d\n",x,i);
}
