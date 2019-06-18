#include "common.h"

char buf[BUFSIZE];		//buffer for ungetch
int bufp = 0;			//next free position in buf

int getch(void)			//get a (possibly pushed-back) character
{
	if (bufp > 0) {
		return buf[--bufp];
	}
	else printf("getch: buffer is empty\n");
}

void ungetch(int c)		//push character back on input
{
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many character\n");
	}
	else buf[bufp++] = c;
}

void ungets(char s[])
{
	int i;
	for (i = 0; s[i] != '\n' && s[i] != EOF; i++);
	while (i >= 0) {
		ungetch(s[i--]);
	}
}