#include "ft_printf.h"

int main()
{
	int l1 = printf("%-10");
	printf("---------------");
	int l2 = ft_printf("%-10");
	printf("---------------");
	printf("\n l1 = %d, l2 = %d\n", l1, l2);
	return 0;
}
