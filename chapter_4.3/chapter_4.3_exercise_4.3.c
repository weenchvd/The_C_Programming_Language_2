/** Chapter 4.3 | Exercise 4.7 */

#include "common.h"

int getop(char[]);
void push(double);
double pop(void);
void printstack(int);
void command(char s[], double var[], bool ispresentvar[]);

double last = 0.0;

/* reverse Polish calculator */
int main()
{
	int type;
	double op1, op2;
	char s[MAXOP];
	double var[NUMVAR];
	bool ispresentvar[NUMVAR];
	for (int i = 0; i < NUMVAR; i++) {
		ispresentvar[i] = false;
	}
	
	printf(
		"--------------------------------------------------------------------------------\n"
		"|  Reverse Polish calculator                                                   |\n"
		"|  Use +, - , *, /, %%                                                          |\n"
		"|  Use function sin, exp, pow                                                  |\n"
		"|  Use variables from \"a\" to \"z\"                                               |\n"
		"|  Use variable assignment in the form \"a=\" ... \"z=\"                           |\n"
		"|  Use variable \"last\" for the most recently printed value                     |\n"
		"|  Use ENTER to complete input                                                 |\n"
		"|  Use commands $prints, $printv, $clear, $dup, $swap on a new line            |\n"
		"|  Use CTRL+C to exit                                                          |\n"
		"--------------------------------------------------------------------------------\n");

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case COMMAND:
			command(s, var, ispresentvar);
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
		case SIN:
			push(sin(pop()));
			break;
		case EXP:
			push(exp(pop()));
			break;
		case POW:
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case ASSIGNVAR:
			var[s[0] - 'a'] = pop();
			ispresentvar[s[0] - 'a'] = true;
			break;
		case USEVAR:
			if (ispresentvar[s[0] - 'a']) {
				push(var[s[0] - 'a']);
			}
			else printf("Error: variable \"%c\" is not present\n", s[0]);
			break;
		case LAST:
			push(last);
			break;
		case '\n':
			printstack(1);
			break;
		case CONTINUE:
			continue;
			break;
		default:
			printf("Error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
