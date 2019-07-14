/** Chapter 5.11 | Exercise 5.16 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000			/* max #lines to be sorted */
#define MAXLENGTH 10000			/* max length of array for lines */

char* lineptr[MAXLINES];		/* pointers to text lines */
char lines[MAXLENGTH];			/* array for lines */
char lc[MAXLENGTH];				/* array for lower case lines */

int ngetline(char* ps, int lim, char n);
int readlines(char* lineptr[], char* plines, int maxlines);
void writelines(char* lineptr[], int nlines);

void qsort(void* lineptr[], int left, int right, int (*comp) (void*, void*), int fold, int dir);
int numcmp(char* s1, char* s2);

/* sort input lines */
int main(int argc, char* argv[])
{
	int nlines;					/* number of input lines read */
	int numeric = 0;			/* 1 if numeric sort */
	int rev = 0;
	int fold = 0;
	int dir = 0;
	int i, j;
	char c;
	if (argc > 1 && **++argv == '-') {
		for (i = 1; (c = *(*argv + i)) != '\0'; i++) {
			switch (c) {
			case ('n'):
				numeric = 1;
				break;
			case ('r'):
				rev = 1;
				break;
			case ('f'):
				fold = 1;
				break;
			case ('d'):
				dir = 1;
				break;
			default:
				printf("---Error: unknown argument\n");
				break;
			}
		}
	}
	if (numeric && fold) {
		fold = 0;
	}
	if (numeric && dir) {
		dir = 0;
	}
	if ((nlines = readlines(lineptr, lines, MAXLINES)) >= 0) {
		qsort((void**)lineptr, 0, nlines - 1, (int (*) (void*, void*)) (numeric ? numcmp : strcmp), fold, dir);
		if (rev) {
			void swap(void* v[], int i, int j);
			for (i = 0, j = nlines - 1; i < j; i++, j--) {
				swap((void**)lineptr, i, j);
			}
		}
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("input too big to sort\n");
		return 1;
	}
}

/* readlines: read input lines */
int readlines(char* lineptr[], char* plines, int maxlines)
{
	int len, tlen, nlines;
	tlen = 0;
	nlines = 0;
	while ((len = ngetline(plines, MAXLENGTH - tlen, 7)) > 0) {
		if (nlines >= maxlines) {
			return -1;
		}
		else {
			lineptr[nlines++] = plines;
			plines += len + 1;
			tlen += len + 1;
		}
	}
	return nlines;
}

/* writelines: write output lines */
void writelines(char* lineptr[], int nlines)
{
	while (nlines-- > 0) {
		printf("%s\n", *lineptr++);
	}
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void* v[], int left, int right, int (*comp) (void*, void*), int fold, int dir)
{
	int i, last;
	void* viptr, * vleftptr;
	int j, len;
	void swap(void* v[], int i, int j);
	if (left >= right) {			/* do nothing if array contains */
		return;						/* fewer than two elements */
	}
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (fold || dir) {
			len = 0;
			viptr = (void*)strcpy(lc, (const char*)v[i]);
			len = strlen(lc);
			for (j = 0; lc[j] != '\0'; j++) {
				if (fold) {
					lc[j] = (char)tolower((int)lc[j]);
				}
				if (dir && !(isalnum(lc[j]) || isspace(lc[j]))) {
					lc[j] = ' ';
				}
			}
			vleftptr = (void*)strcpy(lc + len + 1, (const char*)v[left]);
			for (j = len + 1; lc[j] != '\0'; j++) {
				if (fold) {
					lc[j] = (char)tolower((int)lc[j]);
				}
				if (dir && !(isalnum(lc[j]) || isspace(lc[j]))) {
					lc[j] = ' ';
				}
			}
			if ((*comp) (viptr, vleftptr) < 0) {
				swap(v, ++last, i);
			}
		}
		else {
			if ((*comp) (v[i], v[left]) < 0) {
				swap(v, ++last, i);
			}
		}
	}
	swap(v, left, last);
	qsort(v, left, last - 1, comp, fold, dir);
	qsort(v, last + 1, right, comp, fold, dir);
}

void swap(void* v[], int i, int j)
{
	void* temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char* s1, char* s2)
{
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2) {
		return -1;
	}
	else if (v1 > v2) {
		return 1;
	}
	else {
		return 0;
	}
}
