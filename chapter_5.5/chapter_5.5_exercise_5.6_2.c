/** Chapter 5.5 | Exercise 5.6 p2 */

#include <stdio.h>
#include <limits.h>

#define MAXLENNUM 12
#define MAXLENSTR 15
#define FIRSTINDEX 0

enum boolean {FALSE, TRUE};

void itoa(int number, char* ptrstring);
void reverse(char* ptrstring, int lengthstring, int firstindexofarray);

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

void itoa(int n, char* ps)
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
        *(ps + i++) = n % 10 + '1';
        while ((n /= 10) > 0) {
			*(ps + i++) = n % 10 + '0';
        }
    }
    else {
        do {
			*(ps + i++) = n % 10 + '0';
        }
        while ((n /= 10) > 0);
    }
    if(sign < 0) {
		*(ps + i++) = '-';
    }
	*(ps + i) = '\0';
	reverse(ps, i, FIRSTINDEX);
}

void reverse(char* ps, int len, int fi)
{
	char tmp;
	if (len >= 2) {
		reverse(ps, len - 2, fi + 1);
		tmp = *(ps + fi);
		*(ps + fi) = *(ps + len - 1 + fi);
		*(ps + len - 1 + fi) = tmp;
		return;
	}
	else {
		return;
	}
}
