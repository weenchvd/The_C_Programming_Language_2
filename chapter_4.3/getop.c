#include "common.h"

int getline(char s[], int lim);

char line[MAXLINE];
int n = 0;
int i = 0;

/* getop: get next character or numeric operand */
int getop(char s[])
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
				s[j] = line[i];
			}
			i = n;
			return COMMAND;
		}
		if (islower(line[i])) {
			s[j++] = line[i++];
			while (islower(line[i])) {
				s[j++] = line[i++];
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
			if (s[0] == 'l' && s[1] == 'a' && s[2] == 's' && s[3] == 't') {
				return LAST;
			}
			else if (s[0] == 's' && s[1] == 'i' && s[2] == 'n') {
				return SIN;
			}
			else if (s[0] == 'e' && s[1] == 'x' && s[2] == 'p') {
				return EXP;
			}
			else if (s[0] == 'p' && s[1] == 'o' && s[2] == 'w') {
				return POW;
			}
			else {
				s[j] = '\0';
				return UNKNOWNCOMMAND;
			}
		}
		if (!isdigit(line[i]) && line[i] != '.' && line[i] != '-') {
			s[j++] = line[i];
			s[j] = '\0';
			return line[i++];		//not a number
		}
		if (line[i] == '-') {
			if (isdigit(line[++i]));
			else {
				return '-';
			}
		}
		while (isdigit(line[i])) {		//collect integer part
			s[j++] = line[i++];
		}
		if (line[i] == '.') {		//collect fraction part
			i++;
			while (isdigit(line[i])) {
				s[j++] = line[i++];
			}
		}
		s[j] = '\0';
		return NUMBER;
	}
}
