/** Chapter 5.11 | Exercise 5.14 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000			/* max #lines to be sorted */
#define MAXLENGTH 10000			/* max length of array for lines */

char* lineptr[MAXLINES];		/* pointers to text lines */
char lines[MAXLENGTH];			/* array for lines */

int ngetline(char* ps, int lim, char n);
int readlines(char* lineptr[], char* plines, int maxlines);
void writelines(char* lineptr[], int nlines);

void qsort(void* lineptr[], int left, int right, int (*comp) (void*, void*));
int numcmp(char* s1, char* s2);

/* sort input lines */
int main(int argc, char* argv[])
{
	int nlines;					/* number of input lines read */
	int numeric = 0;			/* 1 if numeric sort */
	int decr = 0;
	int i, j;
	for (i = 1; argc-- > 1; i++) {
		if (strcmp(argv[i], "-n") == 0) {
			numeric = 1;
		}
		else if (strcmp(argv[i], "-r") == 0) {
			decr = 1;
		}
	}
	if ((nlines = readlines(lineptr, lines, MAXLINES)) >= 0) {
		qsort((void**)lineptr, 0, nlines - 1, (int (*) (void*, void*)) (numeric ? numcmp : strcmp));
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
void qsort(void* v[], int left, int right, int (*comp) (void*, void*))
{
	int i, last;
	void swap(void* v[], int i, int j);
	if (left >= right) {			/* do nothing if array contains */
		return;						/* fewer than two elements */
	}
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if ((*comp) (v[i], v[left]) < 0) {
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort(v, left, last - 1, comp);
	qsort(v, last + 1, right, comp);
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
