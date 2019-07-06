/** Chapter 5.6 | Exercise 5.7 */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000			//max #lines to be sorted
#define MAXLENGTH 10000			//max length of array for lines

int readlines(char* lineptr[], char* plines, int nlines);
void writelines(char* lineptr[], int nlines);
void qsort(char* lineptr[], int left, int right);

char* lineptr[MAXLINES];		//pointers to text lines
char lines[MAXLENGTH];			//array for lines

/* sort input lines */
int main()
{
	int nlines;					//number of input lines read
	if ((nlines = readlines(lineptr, lines, MAXLINES)) > 0) {
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else if (nlines < 0) {
		printf("error: input too big to sort\n");
		return 1;
	}
	else {
		printf("Nothing entered\n");
		return 2;
	}
}

int getline(char*, int);

/* readlines: read input lines */
int readlines(char* lineptr[], char* plines, int maxlines)
{
	int len, tlen, nlines;
	tlen = 0;
	nlines = 0;
	while ((len = getline(plines, MAXLENGTH - tlen)) > 1) {
		if (nlines >= maxlines) {
			return -1;
		}
		else {
			if (*(plines + len - 1) == '\n') {
				*(plines + len - 1) = '\0';		//delete newline
			}
			else tlen++;
			lineptr[nlines++] = plines;
			plines += len;
			tlen += len;
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

/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(char* v[], int left, int right)
{
	int i, last;
	void swap(char* v[], int i, int j);
		if (left >= right) {						//do nothing if array contains fewer than two elements
			return;
		}
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (strcmp(v[i], v[left]) < 0) {
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char* v[], int i, int j)
{
	char* temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
