/** Chapter 5.2 | Exercise 5.2 */

#include <stdio.h>

#define SIZE 10

int getfloat(float*);

int main()
{
	int n;
	float array[SIZE];
	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++);
	for (n = 0; n < SIZE; n++) {
		printf("%.15f\n", array[n]);
	}
}
