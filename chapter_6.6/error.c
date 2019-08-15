#include <stdio.h>
#include "gen2.h"

void printerr(int errcode)
{
	char* code[CODELENGTH];
	code[ERRMALLOC] =			"\n\t\t-----Error: no memory allocated for string-----\n";
	code[ERRREALLOC] =			"\n\t\t-----Error: no memory reallocated for string-----\n";
	code[ERRSTRCPY] =			"\n\t\t-----Error: the string is not copied-----\n";
	code[ERRSTRCAT] =			"\n\t\t-----Error: the string is not concatenated-----\n";
	code[ERRNULLPNP] =			"\n\t\t-----Error: pnp is NULL-----\n";
	code[ERRPPNOINSTALL] =		"\n\t\t-----Preprocessor install error: install not done-----\n";
	code[ERRPPNOINPUT] =		"\n\t\t-----Preprocessor input error: no input, NL (\\n) is found-----\n";
	code[ERRPPUNALLOWSYM] =		"\n\t\t-----Preprocessor input error: unallowed symbol in the directive name-----\n";
	code[ERRPPINPUTGLIM] =		"\n\t\t-----Preprocessor input error: input too long-----\n";
	code[ERRPPNLFOUND] =		"\n\t\t-----Preprocessor input error: NL (\\n) is found-----\n";

	printf("%s", code[errcode]);
	return;
}