/** Chapter 5.5 | Exercise 5.5 */

#include <stdio.h>
#include <stdlib.h>

#define SSIZE 10004
#define TSIZE 104
#define NSIZE 6

enum boolean { FALSE, TRUE };

int getstr(char string[], int lim);
char* strncpy(char* ps, char* pt, int sn);
char* strncat(char* ps, char* pt, int sn);
int strncmp(char* ps, char* pt, int sn);

int main()
{
	printf(
		"--------------------------------------------------------------------------------\n"
		"|  Function strncpy(s,t,n), strncat(s,t,n), strncmp(s,t,n)                     |\n"
		"|  Use \'New line\'+``+ENTER to complete input or exit                           |\n"
		"|  Use CTRL+C to exit                                                          |\n"
		"--------------------------------------------------------------------------------\n");
	int slen, tlen, snlen, fn, n, c;
	short int trig, err;
	char s[SSIZE];
	char t[TSIZE];
	char sn[NSIZE];
	slen = 0, tlen = 0, snlen = 0;
	trig = TRUE;
	while (trig) {
		err = FALSE;
		printf("\n\n| Select the function (enter the number):\n"
			"(1) strncpy(s,t,n)\n(2) strncat(s,t,n)\n(3) strncmp(s,t,n)\n");
		if ((c = getchar()) < '1' || c > '3') {
			printf("| Error: unknown command\n");
			err = TRUE;
		}
		else {
			while (getchar() != '\n');
			fn = c - '0';
		}
		if (err == FALSE) {
			printf("\n\n| Enter the string s:\n");
			if ((slen = getstr(s, SSIZE)) <= 0) {
				printf("| Entered string is empty\n");
				err = TRUE;
			}
		}
		if (err == FALSE) {
			printf("\n\n| Enter the string t:\n");
			if ((tlen = getstr(t, TSIZE)) <= 0) {
				printf("| Entered string is empty\n");
				err = TRUE;
			}
		}
		if (err == FALSE) {
			printf("\n\n| Enter the number n:\n");
			if ((snlen = getstr(sn, NSIZE)) <= 0) {
				printf("| Entered string is empty\n");
				err = TRUE;
			}
			else if ((n = atoi(sn)) < 0) {
				printf("| Entered number must be greater or equal than 0\n");
				err = TRUE;
			}
		}
		if (err == FALSE) {
			switch (fn) {
			case 1:
				printf("| Result of the function strncpy(s,t,n):\n%s\n", strncpy(s, t, n));
				break;
			case 2:
				printf("| Result of the function strncat(s,t,n):\n%s\n", strncat(s, t, n));
				break;
			case 3:
				printf("| Result of the function strncmp(s,t,n):\t%d\n", strncmp(s, t, n));
				break;
			default:
				printf("| Error: unknown command (switch)\n");
				break;
			}
		}
		else if (slen == -1 || tlen == -1 || snlen == -1) {
			trig = FALSE;
		}
		else if (slen == -2) {
			printf("| Text entered is too long. Enter text not longer than %d characters\n"
				"| Line breaks and spaces are treated as characters\n", SSIZE - 4);
			return -1;
		}
		else if (tlen == -2) {
			printf("| Text entered is too long. Enter text not longer than %d characters\n"
				"| Line breaks and spaces are treated as characters\n", TSIZE - 4);
			return -1;
		}
		else if (snlen == -2) {
			printf("| Text entered is too long. Enter text not longer than %d characters\n"
				"| Line breaks and spaces are treated as characters\n", NSIZE - 4);
			return -1;
		}
		else if (slen == -100 || tlen == -100 || snlen == -100) {
			printf("| An error has occurred\n");
			return -1;
		}
	}
	return 0;
}

char* strncpy(char* ps, char* pt, int sn)
{
	int slen, tlen;
	char* ps1, * pt1;
	const char* cps;
	for (ps1 = cps = ps, slen = 0; *ps1 != '\0'; ps1++, slen++);
	for (pt1 = pt, tlen = 0; *pt1 != '\0'; pt1++, tlen++);
	for (; sn > 0; sn--, ps++, pt++) {
		if (*pt != '\0') {
			*ps = *pt;
		}
		else {
			for (; sn > 0; sn--, ps++) {
				*ps = '\0';
			}
			return cps;
		}
	}
	if (slen >= tlen) {
		return cps;
	}
	else {
		*ps = '\0';
		return cps;
	}
}

char* strncat(char* ps, char* pt, int sn)
{
	const char* cps;
	cps = ps;
	for (; *ps != '\0'; ps++);
	for (; sn > 0 && *pt != '\0'; sn--, ps++, pt++) {
		*ps = *pt;
	}
	*ps = '\0';
	return cps;
}

int strncmp(char* ps, char* pt, int sn)
{
	int rval;
	rval = 0;
	do {
		if ((rval = *ps - *pt) != 0) {
			return rval;
		}
	} while (--sn > 0 && *ps++ != '\0' && *pt++ != '\0');
	return rval;
}
