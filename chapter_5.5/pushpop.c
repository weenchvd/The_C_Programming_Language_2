#include "common.h"

int sp = 0;			//next free stack position
double val[MAXVAL];	//value stack
double last;

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
			last = val[sptemp];
		}
	}
}

void command(char* ps, double* pvar, bool* pispresentvar)
{
	if (*ps == 'p' && *(ps + 1) == 'r' && *(ps + 2) == 'i'
		&& *(ps + 3) == 'n' && *(ps + 4) == 't' && *(ps + 5) == 's') {
		printstack(sp);
	}
	else if (*ps == 'p' && *(ps + 1) == 'r' && *(ps + 2) == 'i'
		&& *(ps + 3) == 'n' && *(ps + 4) == 't' && *(ps + 5) == 'v') {
		for (int i = 0; i < NUMVAR; i++) {
			if (*(pispresentvar + i)) {
				printf("Variable \"%c\" = %.8g\n", i + 'a', *(pvar + i));
			}
		}
		printf("\n");
	}
	else if (*ps == 'c' && *(ps + 1) == 'l' && *(ps + 2) == 'e' && *(ps + 3) == 'a' && *(ps + 4) == 'r') {
		sp = 0;
		printf("Stack cleared\n");
	}
	else if (*ps == 'd' && *(ps + 1) == 'u' && *(ps + 2) == 'p') {
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
	else if (*ps == 's' && *(ps + 1) == 'w' && *(ps + 2) == 'a' && *(ps + 3) == 'p') {
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
