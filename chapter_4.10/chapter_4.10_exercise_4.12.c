/** Chapter 4.10 | Exercise 4.12 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAXLENNUM 12
#define MAXLENSTR 15
#define FIRSTINDEX 0

int itoa(int n, char str[], int indexpositionofnextchar);

bool ismin;

int main()
{
    int i;
    int number[MAXLENNUM] = {0, 15, 5345, 345655, 123456789, 2147483646, 2147483647,
                            -2, -3456, -345098, -2147483647, -2147483648};
    char str[MAXLENSTR];
    printf("--------------------------------------------------------------------------------\n"
           "|  Recursive function itoa(n, s[], p)                                          |\n"
           "--------------------------------------------------------------------------------\n");
    printf("Numbers:                 ");
    for(i = 0; i < MAXLENNUM; i++) {
        printf(" %d", number[i]);
    }
    printf("\nFunction itoa(n, s[], p):");
    for(i = 0; i < MAXLENNUM; i++) {
        itoa(number[i], str, FIRSTINDEX);
        printf(" %s", str);
    }
    printf("\n");
    return 0;
}

int itoa(int n, char str[], int p)
{
	if (n < 0) {
		if (n == INT_MIN) {
			ismin = true;
			n = INT_MAX;
			str[p++] = '-';
		}
		else {
			n = -n;
			str[p++] = '-';
		}
	}
	if (n / 10) {
		p = itoa(n / 10, str, p);
	}
	if (ismin && n == INT_MAX) {
		str[p++] = n % 10 + '1';
		ismin = false;
	}
	else str[p++] = n % 10 + '0';
	str[p] = '\0';
	return p;
}
