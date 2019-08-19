/** Chapter 7.3 | Exercise 7.3 */

#include <stdio.h>
#include <stdarg.h>

int main()
{
	void minprintf(char* fmt, ...);

	char* string = "It's a just string";
	char c = 'A';
	int i = -100;
	double d = 211643747.555;
	double de = 0.000000351;
	unsigned int ui = 3999456;
	void* ps = (void*) string;
	minprintf("String: %s\t\tSingle character: %c\n", string, c);
	minprintf("Unsigned decimal: %u\t\tSigned decimal: %d\n", ui, i);
	minprintf("Unsigned octal: %o\t\tUnsigned hexadecimal: %x\n", ui, ui);
	minprintf("Decimal floating-point: %f or %e, %f of %e\n", d, d, de, de);
	minprintf("Percent character: %%\t\tBackslash character \b: \\\n");
	minprintf("JIBBERJABBER_JIBBERJABBER_JIBBERJABBER\rPointer: %p", ps);
	return 0;
}

/* minprintf: minimal printf with variable argument list */
void minprintf(char* fmt, ...)
{
	va_list ap;				/* points to each unnamed arg in turn */
	char* p, * sval;
	char c;
	int ival;
	unsigned int uival;
	double dval;
	void* ptr;
	va_start(ap, fmt);		/* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'u':
			uival = va_arg(ap, unsigned int);
			printf("%u", uival);
			break;
		case 'o':
			uival = va_arg(ap, unsigned int);
			printf("%o", uival);
			break;
		case 'x':
			uival = va_arg(ap, unsigned int);
			printf("%x", uival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 'e':
			dval = va_arg(ap, double);
			printf("%e", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char*); *sval; sval++) {
				putchar(*sval);
			}
			break;
		case 'c':
			c = va_arg(ap, char);
			putchar(c);
			break;
		case 'p':
			ptr = va_arg(ap, void*);
			printf("%p", ptr);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);				/* clean up when done */
}
