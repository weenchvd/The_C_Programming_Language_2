/** Chapter 5.11 | Exercise 5.15 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000			/* max #lines to be sorted */
#define MAXLENGTH 10000			/* max length of array for lines */

char* lineptr[MAXLINES];		/* pointers to text lines */
char lines[MAXLENGTH];			/* array for lines */
char lowercaselines[MAXLENGTH];

int ngetline(char* ps, int lim, char n);
int readlines(char* lineptr[], char* plines, int maxlines);
void writelines(char* lineptr[], int nlines);

void qsort(void* lineptr[], int left, int right, int (*comp) (void*, void*), int fold);
int numcmp(char* s1, char* s2);

/* sort input lines */
int main(int argc, char* argv[])
{
	int nlines;					/* number of input lines read */
	int numeric = 0;			/* 1 if numeric sort */
	int decr = 0;
	int fold = 0;
	int i, j;
	for (i = 1; argc-- > 1; i++) {
		if (strcmp(argv[i], "-n") == 0) {
			numeric = 1;
		}
		else if (strcmp(argv[i], "-r") == 0) {
			decr = 1;
		}
		else if (strcmp(argv[i], "-f") == 0) {
			fold = 1;
		}
	}
	if (numeric && fold) {
		fold = 0;
	}
	if ((nlines = readlines(lineptr, lines, MAXLINES)) >= 0) {
		qsort((void**)lineptr, 0, nlines - 1, (int (*) (void*, void*)) (numeric ? numcmp : strcmp), fold);
		if (decr) {
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
void qsort(void* v[], int left, int right, int (*comp) (void*, void*), int fold)
{
	int i, last;
	void swap(void* v[], int i, int j);
	if (left >= right) {			/* do nothing if array contains */
		return;						/* fewer than two elements */
	}
	swap(v, left, (left + right) / 2);
	last = left;
	if (fold) {
		void* viptr, * vleftptr;
		int j, len;
		len = 0;
		for (i = left + 1; i <= right; i++) {
			viptr = (void*)strcpy(lowercaselines, (const char*)v[i]);
			len = strlen(lowercaselines);
			for (j = 0; lowercaselines[j] != '\0'; j++) {
				lowercaselines[j] = (char)tolower((int)lowercaselines[j]);
			}
			vleftptr = (void*)strcpy(lowercaselines + len + 1, (const char*)v[left]);
			for (j = len + 1; lowercaselines[j] != '\0'; j++) {
				lowercaselines[j] = (char)tolower((int)lowercaselines[j]);
			}
			if ((*comp) (viptr, vleftptr) < 0) {
				swap(v, ++last, i);
			}
		}
	}
	else {
		for (i = left + 1; i <= right; i++) {
			if ((*comp) (v[i], v[left]) < 0) {
				swap(v, ++last, i);
			}
		}
	}
	swap(v, left, last);
	qsort(v, left, last - 1, comp, fold);
	qsort(v, last + 1, right, comp, fold);
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
