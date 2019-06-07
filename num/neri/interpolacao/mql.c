#include<math.h>
#include<stdio.h>

/*
-0.2,   -0.764080645739455,
-0.3,	-1.53836452983804,
-0.4,	-0.846787658975495,
-0.5,	-0.122409978892242,
-0.6,	0.407495215822348,
-0.7,	0.768380510234934,
-0.8,	1.00718052873169,
-1.2,	1.30531367616324,
-1.6,	1.13999050320709,
-1.7,	1.0684407169124,
-1.8,	0.990845515301564,
-1.9,	0.909485721325133,
-2,	    0.826384382227648,
-2.1,	0.743358385804844,
-2.2,	0.662051936793094,
-2.3,	0.583957870432893,
-2.4,	0.510430776739371,
-2.5,	0.442694627274298,
-2.6,	0.381846761052565,
-2.7,	0.328859532052398,
-2.8,	0.284580546333897,
-3.2,	0.207100574186043,
-3.6,	0.304004235322449,
-4,	    0.56964125378033,
-4.4,	0.970002286438544,
-4.8,	1.4494752045635,
-5.2,	1.94042878252895,
-5.6,	2.37429680423322,
-5.7,	2.46661956925426,
-5.8,	2.55086290136597,
-5.9,	2.62635511800892,
-6,	    2.69251508861534,
-6.4,	2.85566074137102,
-6.8,	2.84941874780725,
-7.2,	2.68649802911606,
-7.6,	2.40425343800739,
-8, 	2.05843998196245,
-8.4,	1.71412506300573,
-8.8,	1.43521992323121,
-9.2,	1.27429533678208,
-9.6,	1.26428812995407,
-10,	1.413394894043,
-10.4,	1.7039373065791,
-10.8,	2.09535127894607,
-11.2,	2.5307997196893,
-11.6,	2.94633880660777,
-12,	3.2811696398838,
*/
#define N 13
    long double fx[]= { 
                        -0.2,
                        -1.2,
                        -1.7,
                        -2.8,
                        -4,
                        -4.8,
                        -5.6,
                        -6,
                        -8,
                        -9.6,
                        -10.4,
                        -11.2,
                        -12
                        
    };
    long double x[]=  {
                        -0.764080645739455,
                        1.30531367616324,
                        1.0684407169124,
                        0.284580546333897,
                        0.56964125378033,
                        1.4494752045635,
                        2.37429680423322,
                        2.69251508861534,
                        2.05843998196245,
                        1.26428812995407,
                        1.7039373065791,
                        2.5307997196893,
                        3.2811696398838
    }; 
    
    long double matrix[N][N];
    
void printMatrix(){
    printf("x       fx");
    
    for(int i=0; i < N ; i++){//linha
        printf("\n%.2Lf",x[i]);
        for (int o=0; o < N; o++){//coluna
            printf("    %.2Lf",matrix[i][o]);
        }
    }
}
    
void prepMatrix(){
//copia para a matris os valores de ordem 0 que estao no vetor fx
for(int i=0; i < N; i++)
    matrix[i][0]=fx[i];

// não quero escrever um monte de 0's preenchendo ela manualmente
for(int i=0; i < N; i++)//linha
    for(int o=1; o<N; o++)//coluna
        matrix[i][o]=0;    

 for(int ordem=1; ordem < N; ordem ++){//coluna
     printf("operações na matrix:\n");
     printf("y ordem\n");
    for(int y=0;y < (N-ordem);y++){//linha
        printf("[%d] [%d] = (%Lf - %Lf) / (%Lf - %Lf)\n",y,ordem,matrix[y+1][ordem-1],matrix[y][ordem-1],x[y+ordem],x[y]);
        
        matrix[y][ordem]=(matrix[y+1][ordem-1] - matrix[y][ordem-1]) / (x[y+ordem] - x[y]);
    }
 }
}
void calcula(long double xis){
    long double pn=matrix[0][0];//y0
    
    for(int i=1; i<N ; i++){
        printf("grau %d\n",i);
        long double multi=1.0;//começar com um elemento neutro sempre é bom :) kkkk
        for(int o=0; o<i; o++){
            printf("%Lf * (%Lf - %Lf)=",multi, xis,x[o]);
            multi+=multi*(xis-x[o]);
            printf("%Lf\n",multi);
        }
        pn+=matrix[0][i]*multi;
    }
    printf("p(%Lf) = %Lf\n",xis,pn);
}
int main(){
    prepMatrix();
    printMatrix();
       printf("passou\n");
    fflush(stdout);
    calcula(-0.99);
    calcula(-2.35);
    calcula(-2.87);
    calcula(-6.234);
    calcula(-9);
    return 0;
    for(int i=0; i < N; i++){
        long double sup=0.0,inf=0.0;
        for(int k=0;i < N; k++){
            if (i!=k){
                //sup.=x[i]
            }
        }
    }
    
    /*ajuste de curva:
     * 
     */
    
    long double a=0.0,ys=0.0,xs=0.0 ,xys=0.0,xsq=0.0,b=0.0;
    
    for(int i=0;i < N;i++){
        xys += x[i]*fx[i];
        ys += fx[i];
        xs += x[i];
        xsq += x[i]*x[i];
    }
    a=(N*xys - ys*xs)/(N*xsq - xs*ys);//a
    b=(xsq*ys-xs*ys)/(N*xsq - xs*ys);
//y=ax+b
	
	printf("a=%Lf b=%Lf\n",a,b);
    printf("x=0 %Lf\n",	a*0	+	b);
    printf("x=6 %Lf\n",	a*6	+	b);


}
