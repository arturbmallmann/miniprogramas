#include <stdio.h>
#include <string.h>
int lol() {return ;};
void biruta();
int main(){
	int minha_f(int i);
/*	int minha_f (int i){
		return i * 5;
	}*/
	struct my_stc {
		int a;
		int (*metodo)();
	} typedef the_stc;
	the_stc stc;
	stc.a = 22;
	int geta(){ return stc.a;};
	stc.metodo = geta;
	int v =  stc.metodo();
	printf("stc.a: %d\n",v);
	int a;
	a;
	a = 1 ? 1 : 0;

	printf("%d\n",a);
 
	int (*f_ptr)(int) = minha_f;
	printf("metodo %d\n",f_ptr(5));
	{a=5;int b =0;}
	
	int b;

	while( a++ == 5 && 1 )
		printf("%d\n",a);
	int z=0;
	if ( z = 1 ,z==1)
		printf("z: %d\n",z);
	
	b,a,z = 2,3,4;
	printf("z %d b %d a %d\n",z,b);
    int x = 10;
    int y = 15;

    printf("%d\n", (x++, ++y));

	printf("%x.20\n",(int *) &a);
	//biruta();
	return 1==0? lol():printf("aaaaaaaaaa\n");
}

int minha_f(int i){
	void biruta(){printf("lolpqp\n");}
	biruta();
	return i+1;
}
/*

class Pessoa
{
    private:
        char nome[10];

    public:
        char * getNome();
        void setNome(char * nome);
		int (*metodo) (int a) = minha_f;
};

// Definição dos métodos

char * Pessoa::getNome()
{
    return this->nome;
}

void Pessoa::setNome(char * nome)
{
    strcpy (this->nome,nome);
}
*/
