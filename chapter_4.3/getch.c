#include "common.h"

char buf;		//buffer for ungetch
bool bufisfull = false;

int getch(void)			//get a (possibly pushed-back) character
{
	if (bufisfull) {
		bufisfull = false;
		return buf;
	}
	else getchar();		//there is error, but getch still return value getchar(), why???
}

void ungetch(int c)		//push character back on input
{
	if (bufisfull) {
		printf("ungetch: buffer is full\n");
	}
	else buf = c;
}
