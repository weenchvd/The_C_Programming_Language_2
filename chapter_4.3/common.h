#include <stdio.h>
#include <stdlib.h>		//for atof()
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define MAXOP 100		//max size of operand or operator
#define BUFSIZE 100
#define MAXVAL 100		//max depth of val stack
#define NUMVAR 26		//number of variables

#define NUMBER '0'		//signal that a number was found
#define COMMAND 0		//signal that a command was found: $prints, $printv, $clear, $dup, $swap
#define SIN 301			//signal that a function sin(x) was found
#define EXP 302			//signal that a function exp(x) was found
#define POW 303			//signal that a function pow(x,y) was found
#define LAST 400		//signal: take the most recently printed value
#define ASSIGNVAR 501	//signal: assign value to variable
#define USEVAR 502		//signal: take value of variable
#define UNKNOWNCOMMAND -1	//signal that a unknown command was found
#define CONTINUE -2		//signal to continue the loop