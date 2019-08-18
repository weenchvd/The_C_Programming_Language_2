/** Chapter 7.1 | Exercise 7.1 */

#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
	char c;
	if (islower(**argv)) {
		while ((c = getchar()) != EOF) {
			putchar(tolower(c));
		}
	}
	else {
		while ((c = getchar()) != EOF) {
			putchar(toupper(c));
		}
	}
	return 0;
}