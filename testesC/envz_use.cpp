#include <iostream>

#include <envz.h>
#include <stdlib.h>

#include <cstdlib>

using namespace std;
int main(int argc, char **argv, char * envp[]) {
	    int e_len = 0;
    char *str;
    for (int i = 0; envp[i] != NULL; i++){
        e_len += strlen(envp[i]) + 1;
    }
    str = envz_entry(*envp, e_len, "HOME");
    cout<<str<<endl;
    str = envz_get(*envp, e_len, "HOME");
    cout<<str<<endl;

	char * r = getenv("COLUMNS");
	cout << ((r==0) ? "nop" : r) << '\n';
	r = getenv("PATH");
	cout << ((r==0) ? "nop" : r) << '\n';
	return 0;
}
