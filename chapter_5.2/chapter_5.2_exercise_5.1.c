/** Chapter 5.2 | Exercise 5.1 */

#include <stdio.h>

#define SIZE 10

int getint(int*);

int main()
{
	int n, array[SIZE];
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++);
	for (int i = 0; i < SIZE; i++) {
		printf("%d\n", array[i]);
	}
}
