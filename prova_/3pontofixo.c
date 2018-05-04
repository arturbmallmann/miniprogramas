#include <math.h>
#include <stdio.h>
long double euler=2.718281828;
long double phix(long double t){
    return (300 + 201.0625*(1-pow(euler,-0.4*t)))/80.425;
}
long double fx(long double t){
    return 300 - 80.425*t + 201.0625*(1-pow(euler,-0.4*t));
}
int check(long double a,long double b){
	long double dif = a-b;
	dif = dif > 0 ? dif: dif*-1;
//	printf("dif |%Lf - %Lf| = %Lf",a,b,dif);
	if(dif >= powl(10.,-4))
		return true;
	printf("dif: %Lf",dif);
	return false;
}
int main (){
	long double x,aux=0;
	int i=0;
	printf("Entre o valor de chute \n");
	scanf("%Lg", &x);
	printf("%Lg\n", x);
	int first=1;
    long double result=fx(x);
	while(check(result,0)||first){
		first=0;
		printf("x = %Lg, phix = %Lg, fx=%Lg \n",x,phix(x),fx(x));
		aux=result;
        result = fx(x);
		x=phix(x);
		i++;
	}
	printf("\nraiz da equacao é: %Lg\niterações: %d\n",x,i);
}
