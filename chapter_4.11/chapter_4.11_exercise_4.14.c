/** Chapter 4.11 | Exercise 4.14 */

#include <stdio.h>
#include <stdbool.h>

#define swap(t, x, y) { t tmpvar; \
						tmpvar = x; \
						x = y; \
						y = tmpvar; }

int main()
{
	bool q, p;
	char c, s;
	int i, j;
	double f, h;
	q = false, p = true;
	c = 'a', s = 'z';
	i = 2, j = 17;
	f = 1.234, h = 9.8;
	printf("Before swap:\n");
	printf("\t%d, %d\n", q, p);
	printf("\t%c, %c\n", c, s);
	printf("\t%d, %d\n", i, j);
	printf("\t%f, %f\n", f, h);
	swap(bool, q, p);
	swap(char, c, s);
	swap(int, i, j);
	swap(double, f, h);
	printf("After swap:\n");
	printf("\t%d, %d\n", q, p);
	printf("\t%c, %c\n", c, s);
	printf("\t%d, %d\n", i, j);
	printf("\t%f, %f\n", f, h);
    return 0;
}
