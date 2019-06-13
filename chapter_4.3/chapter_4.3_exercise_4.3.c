/** Chapter 4.3 | Exercise 4.4 */

#include "common.h"

int getop(char[]);
void push(double);
double pop(void);
void printstack(int);
void command(char[]);

/* reverse Polish calculator */
int main()
{
	int type;
	double op1, op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case COMMAND:
			command(s);
			break;
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0) {
				push(pop() / op2);
			}
			else printf("Error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0) {
				op1 = pop();
				push(op1 - (op2 * (int) (op1 / op2)));
			}
			else printf("Error: \"X mod 0\" is undefined\n");
			break;
		case '\n':
			printstack(1);
			break;
		default:
			printf("Error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
