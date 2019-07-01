/** Chapter 5.5 | Exercise 5.4 */

#include <stdio.h>

#define SSIZE 10004
#define TSIZE 104

enum boolean { FALSE, TRUE };

int getstr(char string[], int lim);
int strend(char* ps, char* pt);

int main()
{
	printf(
		"--------------------------------------------------------------------------------\n"
		"|  Function strend(s,t)                                                        |\n"
		"|  Use \'New line\'+``+ENTER to complete input or exit                           |\n"
		"|  Use CTRL+C to exit                                                          |\n"
		"--------------------------------------------------------------------------------\n");
	int len1, len2;
	short int trig, err;
	char s[SSIZE];
	char t[TSIZE];
	len1 = 0, len2 = 0;
	trig = TRUE;
	while (trig) {
		err = FALSE;
		printf("\n\n| Enter the string s:\n");
		if ((len1 = getstr(s, SSIZE)) <= 0) {
			err = TRUE;
		}
		if (err == FALSE) {
			printf("\n\n| Enter the string t:\n");
			if ((len2 = getstr(t, TSIZE)) <= 0) {
				err = TRUE;
			}
		}
		if (err == FALSE) {
			if (strend(s, t)) {
				printf("| Success! The string t was found at the end of the string s\n");
			}
			else printf("| Fail. The string t was not found at the end of the string s\n");
		}
		else if (len1 == -1 || len2 == -1) {
			trig = FALSE;
		}
		else if (len1 == -2) {
			printf("| Text entered is too long. Enter text not longer than %d characters\n"
				"| Line breaks and spaces are treated as characters\n", SSIZE - 4);
			return -1;
		}
		else if (len2 == -2) {
			printf("| Text entered is too long. Enter text not longer than %d characters\n"
				"| Line breaks and spaces are treated as characters\n", TSIZE - 4);
			return -1;
		}
		else if (len1 == -100 || len2 == -100) {
			printf("| An error has occurred\n");
			return -1;
		}
	}
	return 0;
}

int strend(char* ps, char* pt)
{
	int i;

	while (*ps != '\0') {
		ps++;
	}
	i = 0;
	while (*pt != '\0') {
		pt++;
		i++;
	}
	if (i > 0) {
		for (; i > 0; i--) {
			if (*--ps != *--pt) {
				return 0;
			}
		}
		return 1;
	}
	else return 0;
}
