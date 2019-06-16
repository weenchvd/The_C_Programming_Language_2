#include <stdio.h>
#include <stdlib.h>		//for atof()
#include <ctype.h>
#include <math.h>

#define MAXOP 100		//max size of operand or operator
#define NUMBER '0'		//signal that a number was found
#define BUFSIZE 100
#define MAXVAL 100		//max depth of val stack
#define COMMAND 0		//signal that a command was found: $print, $clear, $dup, $swap
#define UNKNOWNCOMMAND -1	//signal that a unknown command was found
#define SIN 301			//signal that a function sin(x) was found
#define EXP 302			//signal that a function exp(x) was found
#define POW 303			//signal that a function pow(x,y) was found