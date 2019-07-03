#include <stdio.h>

int getline(char* ps, int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
		*(ps + i++) = c;
	}
	if (c == '\n') {
		*(ps + i++) = c;
	}
	*(ps + i) = '\0';
	return i;
}