#include "rush.h"

using namespace std;
void split(string entrada, string *comando, string *parametro){
	int pos = entrada.find(" ",0);
	if(pos!=-1)
		*parametro = entrada.substr(pos+1);
	*comando = entrada.substr(0,pos);
}
using namespace std;
int executar(string com){
	string parametro,comando;
	split(com,&comando,&parametro);
	if(comando.compare("exit")==0)
		return -1;
	else if(comando.compare("setsid")==0)
		ss(parametro);
	else if(comando.compare("setpgid")==0)
		setgroup(parametro);
	else if(comando.compare("getpgid")==0)
		getgroup(parametro);
	else if(comando.compare("tcgetpgrp")==0)
		tcgetpgroup(parametro);
	else if(comando.compare("tcsetpgrp")==0)
		tcsetpgroup(parametro);
	else if(comando.compare("help")==0)
		help();
	return 0;
}
using namespace std;
void ss(string comando){//set group id
//	string parametro;
//	split(comando,&comando,&parametro);

    char com[100], path[100]="/usr/bin/";
	strcpy (com, comando.c_str());
	
	char *args[] = { com , NULL };
//	extern char * const environ[];
	if(fork()==0){
		setsid();
		strcat(path,com);
		if(execve(path,args,environ) == -1){
				strcpy(path,"/usr/local/bin/");
				strcat(path,com);
				if(execve(path,args,environ) == -1)
					exit(0);
			}
	}
}
using namespace std;
void setgroup(string valores){//set group id
	string grupo;

	int pid,pgid;
	split(valores,&valores,&grupo);
	stringstream convert(valores);
	if(!(convert>>pid))
		return;
	stringstream convert2(grupo);
	if(!(convert2>>pgid))
		return;	
	cout<<"movendo processo: "<<pid<<"\n para o grupo: "<<pgid<<"\n";
	setpgid(pid,pgid);

}
using namespace std;
void getgroup(string pid){
	stringstream converte(pid);
	int id;
	converte >> id;
	cout<<"Processo "<<id<<" pertence ao grupo: "<<getpgid(id)<<"\n";
}
using namespace std;
void tcgetpgroup(string valor){
	stringstream converte(valor);
	int fd;
	if(!(converte >> fd))
		return;
	cout<<"O fd "<<fd<<" pertence ao grupo: "<<tcgetpgrp(fd)<<"\n";
}
using namespace std;
void tcsetpgroup(string valor){
	int fd,gid;
	string grupo;
	split(valor, &valor,&grupo);
	stringstream converte(valor);
	if(!(converte >> fd))
		return;
	stringstream converte2(grupo);
	if(!(converte2 >> gid))
		return;
	cout<<"O fd "<<fd<<" agora pertence ao grupo: "<<gid;
	tcsetpgrp(fd,gid);
}
void help(){
	cout<<"Comandos suportados:\n"
		<<"		setsid [comando]\n"
	    <<"		setpgid [pid] [gid]\n"
		<<"		getpgid [pid]\n"
		<<"		tcgetpgrp [fd]\n"
		<<"		tcsetpgrp [fd] [gid]\n"
		<<"		help\n"
		<<"		exit\n"
		<<"obs: gid = id do grupo\n"
		<<"	pid = id do processo\n"
		<<"	fd  = terminal\n";
}
