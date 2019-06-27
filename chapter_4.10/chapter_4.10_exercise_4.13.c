/** Chapter 4.10 | Exercise 4.13 */

#include <stdio.h>
#include <limits.h>

#define MAXLENNUM 12
#define MAXLENSTR 15
#define FIRSTINDEX 0

enum boolean {FALSE, TRUE};

void itoa(int number, char string[]);
void reverse(char string[], int lengthstring, int firstindexofarray);

int main()
{
    int i;
    int number[MAXLENNUM] = {0, 15, 5345, 345655, 123456789, 2147483646, 2147483647,
                            -2, -3456, -345098, -2147483647, -2147483648};
    char str[MAXLENSTR];
    printf("--------------------------------------------------------------------------------\n"
           "|  Function itoa(n, s[]) with recursive function reverse(s[], l, fi)           |\n"
           "--------------------------------------------------------------------------------\n");
    printf("Numbers:              ");
    for(i = 0; i < MAXLENNUM; i++) {
        printf(" %d", number[i]);
    }
    printf("\nFunction itoa(n, s[]):");
    for(i = 0; i < MAXLENNUM; i++) {
        itoa(number[i], str);
        printf(" %s", str);
    }
    printf("\n");
    return 0;
}

void itoa(int n, char str[])
{
    int i, sign, ismin;
    ismin = FALSE;
    if((sign = n) < 0) {
        if(n == INT_MIN) {
            ismin = TRUE;
            n = INT_MAX;
        }
        else {
            n = -n;
        }
    }
    i = 0;
    if(ismin == TRUE) {
        str[i++] = n % 10 + '1';
        while ((n /= 10) > 0) {
            str[i++] = n % 10 + '0';
        }
    }
    else {
        do {
            str[i++] = n % 10 + '0';
        }
        while ((n /= 10) > 0);
    }
    if(sign < 0) {
        str[i++] = '-';
    }
    str[i] = '\0';
	reverse(str, i, FIRSTINDEX);
}

void reverse(char str[], int len, int fi)
{
	char tmp;
	if (len >= 2) {
		reverse(str, len - 2, fi + 1);
		tmp = str[fi];
		str[fi] = str[len - 1 + fi];
		str[len - 1 + fi] = tmp;
		return;
	}
	else {
		return;
	}
}
