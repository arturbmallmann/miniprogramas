#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

#define R 9
#define E 2.7182818284590452354

int flag = pow(10,4);
long double f(long double x)x{
	return x*powl(E,-x * R) - powl(E, - 5);
}

int check(long double a,long double b){
        flag--;
        if (flag==0)
            exit(0);
	long double dif = a-b;
	dif = dif > 0 ? dif: dif*-1;
//	printf("dif |%Lf - %Lf| = %Lf",a,b,dif);
	if(dif >= powl(10.,-10))
		return true;
	return false;
}

int main (){
	long double x,y;
	int i=0;
	printf("Entre com valor de a e b \n");
	scanf("%Lg %Lg", &x, &y);
	printf("a=%Lg b=%Lg\n", x, y);
//	int first=1;
	while(check(x,y)){
//		first=0;
		int xp=f(x) >= 0,	yp=f(y)>=0,	xyp=f((x+y)/2) >= 0;
		printf("f(%.10Lg) = %.10Lg, f(%.10Lg)=%Lg )/2\n",x,f(x),y,f(y));
		if(xp==yp){
			printf("não existem raizes neste intervalo");
			return 0;
		}
		if(xp==xyp)
			x=(x+y)/2;
		else
			y=(x+y)/2;
		i++;
	}
	printf("\nraiz da equacao é: %.12Lg\niterações: %d\n",x,i);
	return 0;
}
