/** Chapter 5.5 | Exercise 5.3 */

#include <stdio.h>

#define SSIZE 10004
#define TSIZE 104

enum boolean { FALSE, TRUE };

int getstr(char string[], int lim);
void strcat(char* ps, char* pt);

int main()
{
	printf(
		"--------------------------------------------------------------------------------\n"
		"|  Function strcat(s,t)                                                        |\n"
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
			strcat(s, t);
			printf("| Result:\n%s\n", s);
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


/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char* ps, char* pt)
{
	while (*ps++ != '\0'); /* find end of s */
	*ps--;
	while ((*ps++ = *pt++) != '\0'); /* copy t */
}
