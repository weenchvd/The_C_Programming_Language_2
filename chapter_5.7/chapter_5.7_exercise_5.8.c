/** Chapter 5.7 | Exercise 5.8 */

#include <stdio.h>
#include <stdlib.h>

#define S1SIZE 5
#define S2SIZE 5
#define S3SIZE 5

enum boolean { FALSE, TRUE };

int ngetline(char* ps, int lim, char n);
int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int* pmonth, int* pday);

int main()
{
	printf(
		"--------------------------------------------------------------------------------\n"
		"|  Function day_of_year(y, m, d), month_day(y, yd, pm, pd)                     |\n"
		"|  Use ENTER to complete input or exit                                         |\n"
		"|  Use CTRL+C to exit                                                          |\n"
		"--------------------------------------------------------------------------------\n");
	int s1len, s2len, s3len, fn, n1, n2, n3, tmp, month, day;
	short int loop, err;
	char s1[S1SIZE];
	char s2[S2SIZE];
	char s3[S3SIZE];
	s1len = 0, s2len = 0, s3len = 0;
	loop = TRUE;
	while (loop) {
		err = FALSE;
		printf("\n   Select the function (enter the number):\n"
			"(1) day_of_year(y, m, d)\n(2) month_day(y, yd, pm, pd)\n");
		if ((tmp = getchar()) < '1' || tmp > '2') {
			while (getchar() != '\n');
			printf("-- Error: unknown command\n");
			err = TRUE;
		}
		else {
			while (getchar() != '\n');
			fn = tmp - '0';
		}
		if (err == FALSE) {
			printf("\n\n   Enter the YEAR from 1 to 9999 inclusive:\n");
			if ((s1len = ngetline(s1, S1SIZE, 3)) < 1) {
				printf("-- Error: nothing entered\n");
				err = TRUE;
			}
			else n1 = atoi(s1);
		}
		if (err == FALSE) {
			if (fn == 1) {
				printf("\n   Enter the MONTH from 1 to 12 inclusive:\n");
			}
			else if (fn == 2) {
				printf("\n   Enter the YEARDAY from 1 to 366 inclusive:\n");
			}
			if ((s2len = ngetline(s2, S2SIZE, 3)) < 1) {
				printf("-- Error: nothing entered\n");
				err = TRUE;
			}
			else n2 = atoi(s2);
		}
		if (err == FALSE && fn == 1) {
			printf("\n   Enter the DAY from 1 to 31 inclusive:\n");
			if ((s3len = ngetline(s3, S3SIZE, 3)) < 1) {
				printf("-- Error: nothing entered\n");
				err = TRUE;
			}
			else n3 = atoi(s3);
		}
		if (err == FALSE) {
			switch (fn) {
			case 1:
				if ((tmp = day_of_year(n1, n2, n3)) == -1) {
					break;
				}
				printf(">> Result of the function day_of_year(y, m, d):\nYEAR %d   DAY %d\n", n1, tmp);
				break;
			case 2:
				if ((tmp = month_day(n1, n2, &month, &day)) == -1) {
					break;
				}
				printf(">> Result of the function month_day(y, yd, pm, pd):\n"
					"YEAR %d   MONTH %d   DAY %d\n", n1, month, day);
				break;
			default:
				printf("-- Error: unknown command (switch)\n");
				break;
			}
		}
		else if (s1len == 0 || s2len == 0 || s3len == 0) {
			loop = FALSE;
		}
	}
	return 0;
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	if (year < 1) {
		printf("-- Error: entered YEAR must be greater than 0\n");
		return -1;
	}
	if (month < 1 || month > 12) {
		printf("-- Error: entered MONTH must be from 1 to 12 inclusive\n");
		return -1;
	}
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (day < 1 || day > daytab[leap][month]) {
		printf("-- Error: entered DAY must be from 1 to %d inclusive\n", daytab[leap][month]);
		return -1;
	}
	for (i = 1; i < month; i++) {
		day += daytab[leap][i];
	}
	return day;
}

/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int* pmonth, int* pday)
{
	int i, leap;
	if (year < 1) {
		printf("-- Error: entered YEAR must be greater than 0\n");
		return -1;
	}
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (yearday < 1 || yearday > 365 + leap) {
		printf("-- Error: entered YEARDAY in %d must be from 1 to %d inclusive\n", year, 365 + leap);
		return -1;
	}
	for (i = 1; yearday > daytab[leap][i]; i++) {
		yearday -= daytab[leap][i];
	}
	*pmonth = i;
	*pday = yearday;
	return 0;
}
