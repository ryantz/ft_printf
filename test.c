#include "libftprintf.h"

int	main(void)
{
	printf("number of form:%d\n", ft_formatter_count("hello %dthere %abc %"));
	printf("%010d", 23);
}
