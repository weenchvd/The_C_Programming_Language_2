/** Chapter 5.11 | Exercise 5.17 */

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

int wqsort(void* v[], int left, int right, int (*comp) (void*, void*), int fold, int dir, int pos1, int pos2);
int numcmp(char* s1, char* s2);

/* sort input lines */
int main(int argc, char* argv[])
{
	int nlines;					/* number of input lines read */
	int numeric = 0;			/* 1 if numeric sort */
	int rev = 0;
	int fold = 0;
	int dir = 0;
	int i, j, pos1, pos2;
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
	pos1 = pos2 = 0;
	for (argc -= 2; argc > 0; argc--) {
		const char* ps = *++argv + 1;
		if (**argv == '+' && (pos1 = atoi(ps)) <= 0) {
			pos1 = 0;
		}
		else if (**argv == '-' && (pos2 = atoi(ps)) <= 0) {
			pos2 = 0;
		}
	}
	if (pos1 && pos2 && pos1 >= pos2) {
		printf("---Error: The Position 1 argument must always be less than the Position 2 argument\n");
		pos1 = pos2 = 0;
	}
	if ((nlines = readlines(lineptr, lines, MAXLINES)) >= 0) {
		if (wqsort((void**)lineptr, 0, nlines - 1, (int (*) (void*, void*)) (numeric ? numcmp : strcmp),
			fold, dir, pos1, pos2) < 0) {
			printf("---Error: Field boundaries are outside the line boundaries\n");
			return 1;
		}
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

/* wqsort: sort v[left]...v[right] into increasing order */
int wqsort(void* v[], int left, int right, int (*comp) (void*, void*), int fold, int dir, int pos1, int pos2)
{
	int i, last;
	void* viptr, * vleftptr;
	int j, len, field, cond;
	void swap(void* v[], int i, int j);
	if (left >= right) {						/* do nothing if array contains */
		return 0;								/* fewer than two elements */
	}
	swap(v, left, (left + right) / 2);
	last = left;
	field = pos1 || pos2;
	cond = fold || dir || field;
	for (i = left + 1; i <= right; i++) {
		if (cond) {
			len = 0;
			viptr = (void*)strcpy(lc, (const char*)v[i]);
			len = (int)strlen((const char*)viptr);
			if (field) {
				if (pos2 > len + 1) {
					return -1;
				}
				int p1, p2;
				for (j = 0, p1 = pos1 - 1, p2 = pos2 - 1; p1 < p2; j++, p1++) {
					lc[j] = lc[p1];
				}
				lc[j] = '\0';
				len = pos2 - pos1;
			}
			if (fold || dir) {
				for (j = 0; lc[j] != '\0'; j++) {
					if (fold) {
						lc[j] = (char)tolower((int)lc[j]);
					}
					if (dir && !(isalnum(lc[j]) || isspace(lc[j]))) {
						lc[j] = ' ';
					}
				}
			}
			vleftptr = (void*)strcpy(lc + len + 1, (const char*)v[left]);
			if (field) {
				int len2;
				len2 = (int)strlen((const char*)vleftptr);
				if (pos2 > len2 + 1) {
					return -1;
				}
				int p1, p2;
				for (j = len + 1, p1 = pos1 - 1 + len + 1, p2 = pos2 - 1 + len + 1; p1 < p2; j++, p1++) {
					lc[j] = lc[p1];
				}
				lc[j] = '\0';
			}
			if (fold || dir) {
				for (j = len + 1; lc[j] != '\0'; j++) {
					if (fold) {
						lc[j] = (char)tolower((int)lc[j]);
					}
					if (dir && !(isalnum(lc[j]) || isspace(lc[j]))) {
						lc[j] = ' ';
					}
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
	if (wqsort(v, left, last - 1, comp, fold, dir, pos1, pos2) < 0) {
		return -1;
	}
	if (wqsort(v, last + 1, right, comp, fold, dir, pos1, pos2) < 0) {
		return -1;
	}
	return 0;
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
