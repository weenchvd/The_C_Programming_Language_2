#include "common.h"

int getline(char* ps, int lim);

char line[MAXLINE];
int n = 0;
int i = 0;

/* getop: get next character or numeric operand */
int getop(char* ps)
{
	if (n - i <= 0) {
		i = 0;
		if ((n = getline(line, MAXLINE)) == 0) {
			return EOF;
		}
		else if (line[n - 1] != '\n') {
			int c;
			n = 0;
			while ((c = getchar()) != EOF && c != '\n');
			printf("\t\tText entered is too long. Enter text not longer than %d characters\n"
				"\t\tLine breaks and spaces are treated as characters\n", MAXLINE - 1);
			return CONTINUE;
		}
	}
	if (n - i > 0) {
		int j = 0;
		while (line[i] == ' ' || line[i] == '\t') {
			i++;
		}
		if (line[i] == '$') {
			for ( ; j < MAXOP && line[++i] != '\n'; j++) {
				*(ps + j) = line[i];
			}
			i = n;
			return COMMAND;
		}
		if (islower(line[i])) {
			*(ps + j++) = line[i++];
			while (islower(line[i])) {
				*(ps + j++) = line[i++];
			}
			if (line[i] == '=') {
				if (j == 1) {
					i++;
					return ASSIGNVAR;
				}
				else {
					printf("Error: the variable must consist of one letter\n");
					i = n;
					return CONTINUE;
				}
			}
			if (j == 1) {
				return USEVAR;
			}
			if (*ps == 'l' && *(ps + 1) == 'a' && *(ps + 2) == 's' && *(ps + 3) == 't') {
				return LAST;
			}
			else if (*ps == 's' && *(ps + 1) == 'i' && *(ps + 2) == 'n') {
				return SIN;
			}
			else if (*ps == 'e' && *(ps + 1) == 'x' && *(ps + 2) == 'p') {
				return EXP;
			}
			else if (*ps == 'p' && *(ps + 1) == 'o' && *(ps + 2) == 'w') {
				return POW;
			}
			else {
				*(ps + j) = '\0';
				return UNKNOWNCOMMAND;
			}
		}
		if (!isdigit(line[i]) && line[i] != '.' && line[i] != '-') {
			*(ps + j++) = line[i];
			*(ps + j) = '\0';
			return line[i++];		//not a number
		}
		if (line[i] == '-') {
			if (isdigit(line[++i])) {
				*(ps + j++) = line[i - 1];
			}
			else {
				return '-';
			}
		}
		while (isdigit(line[i])) {		//collect integer part
			*(ps + j++) = line[i++];
		}
		if (line[i] == '.') {		//collect fraction part
			i++;
			while (isdigit(line[i])) {
				*(ps + j++) = line[i++];
			}
		}
		*(ps + j) = '\0';
		return NUMBER;
	}
}
