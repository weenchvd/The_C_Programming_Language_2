#include "common.h"

int sp = 0;			//next free stach position
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
