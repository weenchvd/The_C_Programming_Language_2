#include "common.h"

int sp = 0;			//next free stack position
double val[MAXVAL];	//value stack

/* push: push f onto value stack*/
void push(double f)
{
	if (sp < MAXVAL) {
		val[sp++] = f;
	}
	else printf("Error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack*/
double pop(void)
{
	if (sp > 0) {
		return val[--sp];
	}
	else {
		printf("Error: stack empty\n");
		return 0.0;
	}
}

void printstack(int n)
{
	if (sp == 0) {
		printf("Stack empty\n");
	}
	else {
		for (int sptemp = sp; n > 0 && sptemp > 0; n--) {
			printf("\t%.8g\n", val[--sptemp]);
		}
	}
}

void command(char s[])
{
	if (s[0] == 'p' && s[1] == 'r' && s[2] == 'i' && s[3] == 'n' && s[4] == 't') {
		printstack(sp);
	}
	else if (s[0] == 'c' && s[1] == 'l' && s[2] == 'e' && s[3] == 'a' && s[4] == 'r') {
		sp = 0;
		printf("Stack cleared\n");
	}
	else if (s[0] == 'd' && s[1] == 'u' && s[2] == 'p') {
		if (sp < MAXVAL - 1 && sp > 0) {
			val[sp] = val[sp - 1];
			sp++;
			printf("Top element of the stack has duplicated\n");
		}
		else if (sp >= MAXVAL) {
			printf("Error: stack full\n");
		}
		else if (sp == 0) {
			printf("Error: stack empty\n");
		}
	}
	else if (s[0] == 's' && s[1] == 'w' && s[2] == 'a' && s[3] == 'p') {
		if (sp > 1) {
			double tempval;
			tempval = val[sp - 1];
			val[sp - 1] = val[sp - 2];
			val[sp - 2] = tempval;
			printf("Two top elements of the stack has swapped\n");
		}
		else {
			printf("Stack contain less two elements\n");
		}
	}
	else printf("Error: unknown command\n");
}
