#include "ft_printf.h"

int main()
{
	int a;
	int *ptr;
				
	a = 10;
	printf("%.0p\n", 0);
	printf("%.0i\n", 0);
	printf("%.0d\n", 0);
	printf("%.0p\n", 5);
	printf("------\n");
	ft_printf("%.0p\n", 0);
	printf("------\n");
/*	printf("yesmine %*dbesbes %xyyyy%X\n",3, 5, -15, -200);
	ft_printf("yesmine %*dbesbes %xyyyy%X\n",3, 5, -15, -200);
	printf("------\n");
	int length1 = printf("%*d.\n", 10, 250);
	int length2 = ft_printf("%*d.\n", 10, 250);
	printf("length 1 = %d\t, length 2 = %d\n", length1, length2);
	length1 = printf("%010d\t -%10s-\t -%-10s-\n", 23, "medos", "medos");
	length2 = ft_printf("%010d\t -%10s-\t -%-10s-\n", 23, "medos", "medos");
	printf("length 1 = %d\t, length 2 = %d\n", length1, length2);*/
	return 0;
}
