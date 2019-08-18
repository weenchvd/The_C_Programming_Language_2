/** Chapter 7.2 | Exercise 7.2 */

#include <stdio.h>

#define LINELENGTH 80

int main()
{
	int c, num;				/* number of printed values */
	for (num = 0; (c = getchar()) != EOF; ) {
		if (num >= LINELENGTH) {
			num = 0;
			putchar('\n');
		}
		if (c < 32 || c == 127 || c == 255) {
			num += printf("`0x%02X`", c);
		}
		else {
			num++;
			putchar(c);
		}
	}
	return 0;
}