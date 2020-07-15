#include "ft_printf.h"

int main()
{
	ft_printf("hello");
	int a;
	int *ptr;
				
	a = 10;
 //printf("\n%o , %u, %#x, %X\n", -200, -200, -200, -200);
//ft_printf("\n%o , %u, %#x, %X\n", -200, -200, -200, -200);
	printf("\n%%yesmine\n");
	ft_printf("\n%%yesmine\n");
	printf("yesmine %*dbesbes %xyyyy%X\n",3, 5, -15, -200);
	ft_printf("yesmine %*dbesbes %xyyyy%X\n",3, 5, -15, -200);
	int length1 = printf("%*d.\n", 10, 250);
	int length2 = ft_printf("%*d.\n", 10, 250);
	printf("length 1 = %d\t, length 2 = %d\n", length1, length2);
	length1 = printf("%010d\t -%10s-\t -%-10s-\n", 23, "medos", "medos");
	length2 = ft_printf("%010d\t -%10s-\t -%-10s-\n", 23, "medos", "medos");
	printf("length 1 = %d\t, length 2 = %d\n", length1, length2);
	return 0;
}
