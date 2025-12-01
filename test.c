#include "libftprintf.h"

int	main(void)
{
	//char **arr;
	//char **arr2;
	//char str[100] = "hello%-20d\nthe%.0sre\n";
	//int i = 0;

	//arr = ft_handle_new_line(str);
	//arr2 = ft_formatter_extract(str);
	//printf("[");
	//while (i < 2)
	//{
	//	printf("%s,", arr2[i]);
	//	i++;
	//}
	//printf("]\n");
	//printf("[");
	//i = 0;
	//while (i < 2)
	//{
	//	printf("%s,", arr[i]);
	//	i++;
	//}
	//printf("]\n");
	
	printf("test: %%\n");

	char	formatbuf[100] = "%# 01231.123234";
	char	*format = formatbuf;
	int		res = 0;
	int		flag = 0;
	int		precision = 0;
	int		specifier = 0;
	t_format format_map;

	ft_initialize_formatter_map(&format_map);
	format++;
	flag = ft_hasflag(&format, &format_map);
	res = ft_haswidth(&format, &format_map);
	precision = ft_hasprecision(&format, &format_map);
	specifier = ft_hasspecifier(&format, &format_map);
	printf("hasflag: %d\n", flag);
	printf("haswidth: %d\n", res);
	printf("hasprecision: %d\n", precision);
	printf("hasspecifier: %d\n", specifier);
	printf("formatter->minus_flag: %d\n", format_map.minus_flag);
	printf("formatter->zero_flag: %d\n", format_map.zero_flag);
	printf("formatter->hash_flag: %d\n", format_map.hash_flag);
	printf("formatter->plus_flag: %d\n", format_map.plus_flag);
	printf("formatter->space_flag: %d\n", format_map.space_flag);
	printf("formatter->width: %d\n", format_map.width);
	printf("formatter->precision: %d\n", format_map.precision);
	printf("formatter->specifier: %c\n", format_map.specifier);
	printf("formatter:%s", format);
}
