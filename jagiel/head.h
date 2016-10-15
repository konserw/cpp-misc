#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // UNIX standard function definitions
#include <termios.h> // POSIX terminal control definitionss
#include <time.h>   // time calls
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <string.h>
#include <sys/ioctl.h>

int OpenAdrPort();
int WriteAdrPort(__int8_t* psOutput, int n);
void CloseAdrPort();

//int open_port();
//int configure_port(int fd);

#endif // HEAD_H_INCLUDED
