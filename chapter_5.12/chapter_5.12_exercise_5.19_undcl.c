/** Chapter 5.12 | Exercise 5.19 */

#include <stdio.h>
#include <string.h>
#include "gen.h"

int gettoken(void);

int iserr;
int tokentype;
char token[MAXTOKEN];
char out[LENGTHOUT];

/* undcl: convert word description to declaration */
int main()
{
	int type, len;
	int isstar = 0;
	char temp[MAXTOKEN];
	while (gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n') {
			if (type == PARENS || type == BRACKETS) {
				strcat(out, token);
				isstar = 0;
			}
			else if (type == '*') {
				sprintf(temp, "(*%s)", out);
				strcpy(out, temp);
				isstar = 1;
			}
			else if (type == NAME) {
				if (isstar) {
					len = strlen(out);
					strncpy(temp, out + 1, len - 2);
					temp[len - 2] = '\0';
					strcpy(out, temp);
					isstar = 0;
				}
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			}
			else {
				printf("invalid input at %s\n", token);
			}
		}
		printf("%s\n", out);
	}
	return 0;
}
