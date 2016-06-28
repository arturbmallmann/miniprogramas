#ifndef RUSH_H
#define RUSH_H
#include <iostream>//io c++
#include <string>//string c++
#include <string.h>//string c
#include <sstream>

#include <unistd.h>//biblioteca base do syscall
#include <stdlib.h>
void split(std::string com,std::string ncom,std::string par);
int executar(std::string cmd);
void ss(std::string com);
void setgroup(std::string valores);
void getgroup(std::string pid);
#include <termios.h>

void tcgetpgroup(std::string valor);
void tcsetpgroup(std::string valor);
void help();
#endif
