#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char * lang;
//	strncpy(language, getenv("LANGUAGE"),4);
	lang=getenv("LANGUAGE");
	char idioma[2];
	char regiao[2];
	char * pegaInfo=idioma;
	int i;
	int v;
	for( i=0, v=0;lang[i] != 0;i++, v++){
		if(lang[i] != ':'){
			printf("%c \n",lang[i]);
			if(lang[i]!='_'){
				pegaInfo[v]=lang[i];
			}else{
				pegaInfo=&regiao[0];
				v=-1;
			}
		}else{
			pegaInfo[v]=0;
			break;
		}
	}
	if(idioma[0] == 'p' && idioma[1]== 't')
		printf("português");
	printf("Idioma %s, região %s \n",idioma,regiao);
//	printf("%s",language);
//	printf("%s \n",lang);
	int valor;
	printf("Entre o valor que deseja saber a funcionalidade");
	scanf("%i",&valor);
	printf("%i \n",valor);
//*	
	if(valor/4)
		printf("PODE LER \n");
	if(valor%4/2)
		printf("PODE GRAVAR \n");
	if(valor%2)
		printf("PODE EXECUTAR \n");
	return 0;
	// */
}
