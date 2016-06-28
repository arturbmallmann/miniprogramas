#include "rush.h"
using namespace std;
int main(){
	char* user;
	char* host = new char[255];
	char* cwd = new char[255];
	string comando;
	string entrada;
	user=getlogin();
	gethostname(host,255);
	int loop=0;
	help();
	while (loop!=-1){
		getcwd(cwd,255);
		std::cout<<user<<"@"<<host<<":"<<cwd<<"$ ";
		getline(cin, comando);
		loop = executar(comando);
	}
}
