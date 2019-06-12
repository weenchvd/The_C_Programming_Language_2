/** Chapter 4.2 | Exercise 4.2 */

#include <stdio.h>

#define MAXLEN 100

enum boolean { FALSE, TRUE };
int getline(char line[], int lim);
double atof(char s[]);

int main()
{
	printf(
		"--------------------------------------------------------------------------------\n"
		"|  Function atof                                                               |\n"
		"|  Use ENTER to complete input                                                 |\n"
		"|  Use CTRL+C to exit                                                          |\n"
		"--------------------------------------------------------------------------------\n");
	double sum;
	char line[MAXLEN];
	sum = 0;
	while (getline(line, MAXLEN) > 0) {
		printf("\t%g\n", sum += atof(line));
	}
	return 0;
}