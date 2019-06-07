#include<math.h>
#include<stdio.h>


int main(){
	//					0	1	 2 	 3	  4		5	6
    long double fx[]= {0.01,1.01,1.4,3.81,4.01,4.55,4.2};
    long double a=0.0,ys=0.0,xs=0.0 ,xys=0.0,xsq=0.0,b=0.0;
	int n=7;
    for(int i=0;i < n;i++){
        xys += i*fx[i];
        ys += fx[i];
        xs += i;
        xsq += i*i;
    }
    a=(n*xys - ys*xs)/(n*xsq - xs*ys);//a
    b=(xsq*ys-xs*ys)/(n*xsq - xs*ys);
//y=ax+b
	
	printf("a=%Lf b=%Lf\n",a,b);
    printf("x=0 %Lf\n",	a*0	+	b);
    printf("x=6 %Lf\n",	a*6	+	b);


}
