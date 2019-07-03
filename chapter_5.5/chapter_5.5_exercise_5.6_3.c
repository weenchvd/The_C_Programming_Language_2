/** Chapter 5.5 | Exercise 5.6 p3 */

#include <stdio.h>

#define MAXLEN1 10004
#define MAXLEN2 104

enum boolean { FALSE, TRUE };
int getstr(char string[], int lim);
int strindex(char* ps, char* pt);


int main()
{
	printf(
		"--------------------------------------------------------------------------------\n"
		"|  Function strindex(s,t)                                                      |\n"
		"|  Use \'New line\'+``+ENTER to complete input or exit                         |\n"
		"|  Use CTRL+C to exit                                                          |\n"
		"--------------------------------------------------------------------------------\n");
	int len1, len2, i;
	short int trig, err;
	char str1[MAXLEN1];
	char str2[MAXLEN2];
	len1 = 0, len2 = 0, i = -2;
	trig = TRUE;
	while (trig) {
		err = FALSE;
		printf("\n\n| Enter the string s:\n");
		if ((len1 = getstr(str1, MAXLEN1)) <= 0) {
			err = TRUE;
		}
		if (err == FALSE) {
			printf("\n\n| Enter the string t:\n");
			if ((len2 = getstr(str2, MAXLEN2)) <= 0) {
				err = TRUE;
			}
		}
		if (err == FALSE && (i = strindex(str1, str2)) >= 0) {
			printf("| The position of the rightmost occurrence of t:\n%d\n", i);
		}
		else if (i == -1) {
			printf("| The occurrence is not found");
		}
		else if (len1 == -1 || len2 == -1) {
			trig = FALSE;
		}
		else if (len1 == -2) {
			printf("| Text entered is too long. Enter text not longer than %d characters\n"
				"| Line wrap is considered a character\n", MAXLEN1 - 4);
			return -1;
		}
		else if (len2 == -2) {
			printf("| Text entered is too long. Enter text not longer than %d characters\n"
				"| Line wrap is considered a character\n", MAXLEN2 - 4);
			return -1;
		}
		else if (len1 == -100 || len2 == -100) {
			printf("| An error has occurred\n");
			return -1;
		}
	}
	return 0;
}

int strindex(char* ps, char* pt)
{
	int i, j, ii, jj;
	for (i = 0; *(ps + i) != '\0'; i++);
	i--;
	for (j = 0; *(pt + j) != '\0'; j++);
	j--;
	for (; i >= 0; i--) {
		if (*(ps + i) == *(pt + j)) {
			for (ii = i - 1, jj = j - 1; ii >= 0 && jj >= 0 && *(ps + ii) == *(pt + jj); ii--, jj--);
			if (jj == -1) {
				return ii + 2;
			}
		}
	}
	return -1;
}
