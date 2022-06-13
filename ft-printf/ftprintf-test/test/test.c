#include <stdio.h>
#include "include/ft_printf.h"
#include <limits.h>

void	test_percent()
{
	int my, real;

	my = ft_printf("%%\n");
	real =  printf("%%\n");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%10%\n");
	real =  printf("%10%\n");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-10%\n");
	real =  printf("%-10%\n");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%010%\n");
	real =  printf("%010%\n");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%*%\n", 10);
	real =  printf("%*%\n", 10);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.10%\n");
	real =  printf("%.10%\n");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-.10%\n");
	real =  printf("%-.10%\n");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%0.10%\n");
	real =  printf("%0.10%\n");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.*%\n", 10);
	real =  printf("%.*%\n", 10);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%10.10%\n");
	real =  printf("%10.10%\n");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-10.10%\n");
	real =  printf("%-10.10%\n");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%010.10%\n");
	real =  printf("%010.10%\n");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%*.*%\n", 10, 10);
	real =  printf("%*.*%\n", 10, 10);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.%\n");
	real =  printf("%.%\n");
	printf("|%d -- %d|\n\n", my, real);
}

void	test_char()
{
	int my, real;

	my = ft_printf("%c\n", 0);
	real =  printf("%c\n", 0);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%c\n", 9);
	real =  printf("%c\n", 9);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%c\n", -1);
	real =  printf("%c\n", -1);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%c\n", 32);
	real =  printf("%c\n", 32);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%c\n", 65);
	real =  printf("%c\n", 65);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%c\n", 97);
	real =  printf("%c\n", 97);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%c\n", 126);
	real =  printf("%c\n", 126);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%c\n", 127);
	real =  printf("%c\n", 127);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%c\n", 128);
	real =  printf("%c\n", 128);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%c\n", INT_MAX);
	real =  printf("%c\n", INT_MAX);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%5c\n", 65);
	real =  printf("%5c\n", 65);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-5c\n", 65);
	real =  printf("%-5c\n", 65);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%05c\n", 65);
	real =  printf("%05c\n", 65);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-*c\n", 5, 65);
	real =  printf("%-*c\n", 5, 65);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.5c\n", 65);
	real =  printf("%.5c\n", 65);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-.5c\n", 65);
	real =  printf("%-.5c\n", 65);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%0.5c\n", 65);
	real =  printf("%0.5c\n", 65);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-.*c\n", 5, 65);
	real =  printf("%-.*c\n", 5, 65);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%5.5c\n", 65);
	real =  printf("%5.5c\n", 65);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-5.5c\n", 65);
	real =  printf("%-5.5c\n", 65);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%05.5c\n", 65);
	real =  printf("%05.5c\n", 65);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-*.*c\n", 5, 5, 65);
	real =  printf("%-*.*c\n", 5, 5, 65);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.c\n", 65);
	real =  printf("%.c\n", 65);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.0c\n", 65);
	real =  printf("%.0c\n", 65);
	printf("|%d -- %d|\n\n", my, real);

}

void	test_string()
{
	int my, real;

	my = ft_printf("%s\n", "");
	real =  printf("%s\n", "");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%s\n", NULL);
	real =  printf("%s\n", NULL);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%s\n", "1");
	real =  printf("%s\n", "1");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%s\n", "a");
	real =  printf("%s\n", "a");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%s\n", "abcdefghijklmnopqrstuwvxyz");
	real =  printf("%s\n", "abcdefghijklmnopqrstuwvxyz");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%s\n", "abcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyz");
	real =  printf("%s\n", "abcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyzabcdefghijklmnopqrstuwvxyz");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%10s\n", "asfj34");
	real =  printf("%10s\n", "asfj34");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-10s\n", "asfj34");
	real =  printf("%-10s\n", "asfj34");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%010s\n", "asfj34");
	real =  printf("%010s\n", "asfj34");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%*s\n", 10, "asfj34");
	real =  printf("%*s\n", 10, "asfj34");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.3s\n", "asfj34");
	real =  printf("%.3s\n", "asfj34");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.10s\n", "asfj34");
	real =  printf("%.10s\n", "asfj34");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-.10s\n", "asfj34");
	real =  printf("%-.10s\n", "asfj34");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%0.10s\n", "asfj34");
	real =  printf("%0.10s\n", "asfj34");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.*s\n", 10, "asfj34");
	real =  printf("%.*s\n", 10, "asfj34");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%10.3s\n", "asfj34");
	real =  printf("%10.3s\n", "asfj34");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-10.3s\n", "asfj34");
	real =  printf("%-10.3s\n", "asfj34");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%010.3s\n", "asfj34");
	real =  printf("%010.3s\n", "asfj34");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%10.10s\n", "asfj34");
	real =  printf("%10.10s\n", "asfj34");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%010.10s\n", "asfj34");
	real =  printf("%010.10s\n", "asfj34");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%*.*s\n", 10, 10, "asfj34");
	real =  printf("%*.*s\n", 10, 10, "asfj34");
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.s\n", "asfj34");
	real =  printf("%.s\n", "asfj34");
	printf("|%d -- %d|\n\n", my, real);
}

void	test_uint()
{
	int my, real;

	my = ft_printf("%u\n", 123);
	real =  printf("%u\n", 123);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%u\n", -123);
	real =  printf("%u\n", -123);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%u\n", 123456789);
	real =  printf("%u\n", 123456789);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%u\n", 0);
	real =  printf("%u\n", 0);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%u\n", UINT_MAX);
	real =  printf("%u\n", UINT_MAX);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%u\n", INT_MAX + 1);
	real =  printf("%u\n", INT_MAX + 1);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%3u\n", 3792);
	real =  printf("%3u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-3u\n", 3792);
	real =  printf("%-3u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%03u\n", 3792);
	real =  printf("%03u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%10u\n", 3792);
	real =  printf("%10u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-10u\n", 3792);
	real =  printf("%-10u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%010u\n", 3792);
	real =  printf("%010u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%*u\n", 10, 3792);
	real =  printf("%*u\n", 10, 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.3u\n", 3792);
	real =  printf("%.3u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-.3u\n", 3792);
	real =  printf("%-.3u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%0.3u\n", 3792);
	real =  printf("%0.3u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.10u\n", 3792);
	real =  printf("%.10u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-.10u\n", 3792);
	real =  printf("%-.10u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%0.10u\n", 3792);
	real =  printf("%0.10u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.*u\n", 10, 3792);
	real =  printf("%.*u\n", 10, 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%3.2u\n", 3792);
	real =  printf("%3.2u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-3.4u\n", 3792);
	real =  printf("%-3.4u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%03.1u\n", 3792);
	real =  printf("%03.1u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%10.6u\n", 3792);
	real =  printf("%10.6u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-10.7u\n", 3792);
	real =  printf("%-10.7u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%010.6u\n", 3792);
	real =  printf("%010.6u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%*.*u\n", 10, 10, 3792);
	real =  printf("%*.*u\n", 10, 10, 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.u\n", 3792);
	real =  printf("%.u\n", 3792);
	printf("|%d -- %d|\n\n", my, real);
}

void	test_int()
{
		int my, real;

	my = ft_printf("%d\n", 123);
	real =  printf("%d\n", 123);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%d\n", -123);
	real =  printf("%d\n", -123);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%d\n", 123456789);
	real =  printf("%d\n", 123456789);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%d\n", 0);
	real =  printf("%d\n", 0);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%d\n", UINT_MAX);
	real =  printf("%d\n", UINT_MAX);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%d\n", INT_MAX);
	real =  printf("%d\n", INT_MAX);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%d\n", INT_MIN);
	real =  printf("%d\n", INT_MIN);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%3d\n", 3792);
	real =  printf("%3d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-3d\n", 3792);
	real =  printf("%-3d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%03d\n", 3792);
	real =  printf("%03d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%10d\n", 3792);
	real =  printf("%10d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-10d\n", 3792);
	real =  printf("%-10d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%010d\n", 3792);
	real =  printf("%010d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%*d\n", 10, 3792);
	real =  printf("%*d\n", 10, 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.3d\n", 3792);
	real =  printf("%.3d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-.3d\n", 3792);
	real =  printf("%-.3d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%0.3d\n", 3792);
	real =  printf("%0.3d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.10d\n", 3792);
	real =  printf("%.10d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-.10d\n", 3792);
	real =  printf("%-.10d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%0.10d\n", 3792);
	real =  printf("%0.10d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.*d\n", 10, 3792);
	real =  printf("%.*d\n", 10, 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%3.2d\n", 3792);
	real =  printf("%3.2d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-3.4d\n", 3792);
	real =  printf("%-3.4d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%03.1d\n", 3792);
	real =  printf("%03.1d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%10.6d\n", 3792);
	real =  printf("%10.6d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-10.7d\n", 3792);
	real =  printf("%-10.7d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%010.6d\n", 3792);
	real =  printf("%010.6d\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%*.*d\n", 10, 10, 3792);
	real =  printf("%*.*d\n", 10, 10, 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.d\n", -3792);
	real =  printf("%.d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%3d\n", -3792);
	real =  printf("%3d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-3d\n", -3792);
	real =  printf("%-3d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%03d\n", -3792);
	real =  printf("%03d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%10d\n", -3792);
	real =  printf("%10d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-10d\n", -3792);
	real =  printf("%-10d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%010d\n", -3792);
	real =  printf("%010d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%*d\n", 10, -3792);
	real =  printf("%*d\n", 10, -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.3d\n", -3792);
	real =  printf("%.3d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-.3d\n", -3792);
	real =  printf("%-.3d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%0.3d\n", -3792);
	real =  printf("%0.3d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.10d\n", -3792);
	real =  printf("%.10d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-.10d\n", -3792);
	real =  printf("%-.10d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%0.10d\n", -3792);
	real =  printf("%0.10d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.*d\n", 10, -3792);
	real =  printf("%.*d\n", 10, -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%3.2d\n", -3792);
	real =  printf("%3.2d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-3.4d\n", -3792);
	real =  printf("%-3.4d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%03.1d\n", -3792);
	real =  printf("%03.1d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%10.6d\n", -3792);
	real =  printf("%10.6d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-10.7d\n", -3792);
	real =  printf("%-10.7d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%010.6d\n", -3792);
	real =  printf("%010.6d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%*.*d\n", 10, 10, -3792);
	real =  printf("%*.*d\n", 10, 10, -3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.d\n", -3792);
	real =  printf("%.d\n", -3792);
	printf("|%d -- %d|\n\n", my, real);
}

void	test_hex()
{
	int my, real;

	my = ft_printf("%x\n", 123);
	real =  printf("%x\n", 123);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%X\n", 123);
	real =  printf("%X\n", 123);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%x\n", -123);
	real =  printf("%x\n", -123);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%x\n", 123456789);
	real =  printf("%x\n", 123456789);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%x\n", 0);
	real =  printf("%x\n", 0);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%x\n", UINT_MAX);
	real =  printf("%x\n", UINT_MAX);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%x\n", INT_MAX + 1);
	real =  printf("%x\n", INT_MAX + 1);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%3x\n", 3792);
	real =  printf("%3x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-3x\n", 3792);
	real =  printf("%-3x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%03x\n", 3792);
	real =  printf("%03x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%10x\n", 3792);
	real =  printf("%10x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-10x\n", 3792);
	real =  printf("%-10x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%010x\n", 3792);
	real =  printf("%010x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%*x\n", 10, 3792);
	real =  printf("%*x\n", 10, 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.3x\n", 3792);
	real =  printf("%.3x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-.3x\n", 3792);
	real =  printf("%-.3x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%0.3x\n", 3792);
	real =  printf("%0.3x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.10x\n", 3792);
	real =  printf("%.10x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-.10x\n", 3792);
	real =  printf("%-.10x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%0.10x\n", 3792);
	real =  printf("%0.10x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.*x\n", 10, 3792);
	real =  printf("%.*x\n", 10, 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%3.2x\n", 3792);
	real =  printf("%3.2x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-3.4x\n", 3792);
	real =  printf("%-3.4x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%03.1x\n", 3792);
	real =  printf("%03.1x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%10.6x\n", 3792);
	real =  printf("%10.6x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-10.7x\n", 3792);
	real =  printf("%-10.7x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%010.6x\n", 3792);
	real =  printf("%010.6x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%*.*x\n", 10, 10, 3792);
	real =  printf("%*.*x\n", 10, 10, 3792);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.x\n", 3792);
	real =  printf("%.x\n", 3792);
	printf("|%d -- %d|\n\n", my, real);
}

void	test_ptr()
{
	int my, real;

	my = ft_printf("%p\n", NULL);
	real =  printf("%p\n", NULL);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%10p\n", NULL);
	real =  printf("%10p\n", NULL);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%010p\n", NULL);
	real =  printf("%010p\n", NULL);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-10p\n", NULL);
	real =  printf("%-10p\n", NULL);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.0p\n", NULL);
	real =  printf("%.0p\n", NULL);
	printf("|%d -- %d|\n\n", my, real);
	
	my = ft_printf("%.10p\n", NULL);
	real =  printf("%.10p\n", NULL);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.20p\n", NULL);
	real =  printf("%.20p\n", NULL);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-.20p\n", NULL);
	real =  printf("%-.20p\n", NULL);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%0.20p\n", NULL);
	real =  printf("%0.20p\n", NULL);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%10.0p\n", NULL);
	real =  printf("%10.0p\n", NULL);
	printf("|%d -- %d|\n\n", my, real);
	
	my = ft_printf("%10.10p\n", NULL);
	real =  printf("%10.10p\n", NULL);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%20.20p\n", NULL);
	real =  printf("%20.20p\n", NULL);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-20.20p\n", NULL);
	real =  printf("%-20.20p\n", NULL);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%020.20p\n", NULL);
	real =  printf("%020.20p\n", NULL);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%p\n", &my);
	real =  printf("%p\n", &my);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%p\n", &real);
	real =  printf("%p\n", &real);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%20p\n", &real);
	real =  printf("%20p\n", &real);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%020p\n", &real);
	real =  printf("%020p\n", &real);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-20p\n", &real);
	real =  printf("%-20p\n", &real);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.0p\n", &real);
	real =  printf("%.0p\n", &real);
	printf("|%d -- %d|\n\n", my, real);
	
	my = ft_printf("%.10p\n", &real);
	real =  printf("%.10p\n", &real);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%.20p\n", &real);
	real =  printf("%.20p\n", &real);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-.20p\n", &real);
	real =  printf("%-.20p\n", &real);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%0.20p\n", &real);
	real =  printf("%0.20p\n", &real);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%20.0p\n", &real);
	real =  printf("%20.0p\n", &real);
	printf("|%d -- %d|\n\n", my, real);
	
	my = ft_printf("%20.10p\n", &real);
	real =  printf("%20.10p\n", &real);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%20.20p\n", &real);
	real =  printf("%20.20p\n", &real);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%-20.20p\n", &real);
	real =  printf("%-20.20p\n", &real);
	printf("|%d -- %d|\n\n", my, real);

	my = ft_printf("%020.20p\n", &real);
	real =  printf("%020.20p\n", &real);
	printf("|%d -- %d|\n\n", my, real);
}

int main()
{
	int real, my;

	// test_percent();

	// test_char();

	// test_string();

	// test_uint();

	// test_int();

	// test_hex();

	// test_ptr();

	// my = ft_printf("%*uzxc- %.2s %c%c%d%c%i %20p %% %x %020X\n", 10, 3792, "hello", 'a', 'b', 26, 'y', 'z', &real, 10000, 123456);
	// real =  printf("%*uzxc- %.2s %c%c%d%c%i %20p %% %x %020X\n", 10, 3792, "hello", 'a', 'b', 26, 'y', 'z', &real, 10000, 123456);
	// printf("|%d -- %d|\n\n", my, real);
	
	return (0);
}
