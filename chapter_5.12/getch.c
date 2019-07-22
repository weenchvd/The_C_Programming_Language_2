#include <stdio.h>
#include <stdbool.h>

int buf;		//buffer for ungetch
bool bufisfull = false;

int getch(void)			//get a (possibly pushed-back) character
{
	if (bufisfull) {
		bufisfull = false;
		return buf;
	}
	else return getchar();
}

void ungetch(int c)		//push character back on input
{
	if (bufisfull) {
		printf("ungetch: buffer is full\n");
	}
	else {
		bufisfull = true;
		buf = c;
	}
}
