/** Chapter 5.10 | Exercise 5.10 */

#include <stdio.h>
#include <stdlib.h>

void push(double f);
double pop(void);

int main(int argc, char *argv[])
{
	double f;
	if (argc < 2) {
		printf(
			"   Reverse Polish expression. Enter the arguments (for example, \"4 3 +\").\n"
			"   List of the arguments: integer numbers, \'+\', \'-\', \'*\', \'/\'.\n");
		return -1;
	}
	else {
		while (--argc > 0) {
			switch (**++argv) {
			case '+':
				push(pop() + pop());
				break;
			case '-':
				f = pop();
				push(pop() - f);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				f = pop();
				if (f != 0) {
					push(pop() / f);
				}
				else {
					printf("---Error: zero divisor\n");
					return -1;
				}
				break;
			default:
				if (**argv >= '0' && **argv <= '9') {
					push(atoi(*argv));
				}
				else {
					printf("---Error: wrong argument\n");
					return -1;
				}
				break;
			}
		}
		printf(">>>The expression evaluated:   %g", pop());
	}
	return 0;
}
