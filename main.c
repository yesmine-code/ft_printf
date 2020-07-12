#include <stdio.h>

//%[flags][width][.precision][length]specifier
int main()
{
	int a = 287412;
	char b = 'b';
	char str[]="yesmine";

	printf("%Zu\n", 3);
	printf("%4d %4d %4d\n", 170, 1, 15 );
	printf("----------------\n");
	printf("%-4d %-4d %-4d\n", a, 130, 15 );
	printf("%-4d %-4d %-4d\n", 170, 1, 15 );
	printf("--------------\n");
	printf("%+4d %+4d %+4d\n", a, 130, 15 );
	printf("%+4d %+4d %+4d\n", 170, 1, 15 );
	printf("--------------\n");
	printf("% d % d % d\n", a, 130, 15 );
	printf("%+ d % d % d\n", 170, 1, 15 );
	printf("--------------\n");
	printf("decimal: %d octal : %o hexa: %x HEXA: %X\n", a, a, a, a);
//	printf("", );
//	printf("", );
//	printf("", );
//	printf("", );
	return 0;
}
