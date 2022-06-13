#include <libasm.h>

int		main(void)
{
	int		errno1, errno2;

	/* ft_write test */
	ssize_t res1, res2;

	res1 = write(1, "wqerasd\n", 4);
	errno1 = errno;
	res2 = ft_write(1, "wqerasd\n", 4);
	errno2 = errno;

	printf("Result\nreal : %ld | my : %ld\n", res1, res2);
	if (errno != 0)
		printf("Errno\nreal : %d | my : %d\n", errno1, errno2);

	errno = 0;

	res1 = write(-1, "wqerasd\n", 4);
	errno1 = errno;
	res2 = ft_write(-1, "wqerasd\n", 4);
	errno2 = errno;

	printf("Result\nreal : %ld | my : %ld\n", res1, res2);
	if (errno != 0)
		printf("Errno\nreal : %d | my : %d\n", errno1, errno2);

	errno = 0;

	/* ft_read test */
	char	*buf1 = malloc(10), *buf2 = malloc(10);
	int		fd = open("pasd", O_RDONLY);

	res1 = read(fd, buf1, 10);
	errno1 = errno;
	res2 = ft_read(fd, buf2, 10);
	errno2 = errno;

	printf("Result\nreal : %ld | my : %ld\n", res1, res2);
	printf("Buffer\nreal : %s | my : %s\n", buf1, buf2);
	if (errno != 0)
		printf("Errno\nreal : %d | my : %d\n", errno1, errno2);

	free(buf1);
	free(buf2);
	errno = 0;

	buf1 = malloc(10), buf2 = malloc(10);
	fd = open("./Makefile", O_RDONLY);

	res1 = read(fd, buf1, 10);
	errno1 = errno;
	res2 = ft_read(fd, buf2, 10);
	errno2 = errno;

	printf("Result\nreal : %ld | my : %ld\n", res1, res2);
	printf("Buffer\nreal : %s | my : %s\n", buf1, buf2);
	if (errno != 0)
		printf("Errno\nreal : %d | my : %d\n", errno1, errno2);

	free(buf1);
	free(buf2);
	errno = 0;

	/* ft_strlen test */
	size_t	res_u1, res_u2;

	res_u1 = strlen("zxcvb");	
	res_u2 = ft_strlen("zxcvb");	
	
	printf("Result\nreal : %ld | my : %ld\n", res_u1, res_u2);

	res_u1 = strlen(buf1);	
	res_u2 = ft_strlen(buf1);	
	
	printf("Result\nreal : %ld | my : %ld\n", res_u1, res_u2);

	res_u1 = strlen("");	
	res_u2 = ft_strlen("");	
	
	printf("Result\nreal : %ld | my : %ld\n", res_u1, res_u2);

	/* ft_strcpy test */
	char	*res_s1, *res_s2;

	buf1 = malloc(7);
	buf2 = malloc(7);
	res_s1 = strcpy(buf1, "zxcvbn");
	res_s2 = ft_strcpy(buf2, "zxcvbn");

	printf("Result\nreal : %s | my : %s\n", res_s1, res_s2);

	free(buf1);
	free(buf2);

	buf1 = malloc(17);
	buf2 = malloc(17);
	res_s1 = strcpy(buf1, "zxcvbn");
	res_s2 = ft_strcpy(buf2, "zxcvbn");

	printf("Result\nreal : %s | my : %s\n", res_s1, res_s2);

	free(buf1);
	free(buf2);

	/* ft_strcmp test */
	int		res_i1, res_i2;

	res_i1 = strcmp("zxcvbn", "zxcvbn");
	res_i2 = ft_strcmp("zxcvbn", "zxcvbn");

	printf("Result\nreal : %d | my : %d\n", res_i1, res_i2);

	res_i1 = strcmp("zxcvbn", "asd");
	res_i2 = ft_strcmp("zxcvbn", "asd");

	printf("Result\nreal : %d | my : %d\n", res_i1, res_i2);

	res_i1 = strcmp("asd", "zxcvbn");
	res_i2 = ft_strcmp("asd", "zxcvbn");

	printf("Result\nreal : %d | my : %d\n", res_i1, res_i2);

	/* ft_strdup test */
	res_s1 = strdup("copy");
	res_u1 = strlen(res_s1);
	res_s2 = ft_strdup("copy");
	res_u2 = strlen(res_s2);

	printf("Result\nreal : %s / %ld | my : %s / %ld\n", res_s1, res_u1, res_s2, res_u2);

	free(res_s1);
	free(res_s2);

	res_s1 = strdup("asdsadgfdsfsdf");
	res_u1 = strlen(res_s1);
	res_s2 = ft_strdup("asdsadgfdsfsdf");
	res_u2 = strlen(res_s2);

	printf("Result\nreal : %s / %ld | my : %s / %ld\n", res_s1, res_u1, res_s2, res_u2);

	free(res_s1);
	free(res_s2);


	// list test
	/*t_list	*list = NULL;
	
	char s1[] = "qwe";
	char s2[] = "zxc";
	char s3[] = "asd";
	char s4[] = "abcd";

	ft_list_push_front(&list, s1);
	ft_list_push_front(&list, s4);
	ft_list_push_front(&list, s3);
	ft_list_push_front(&list, s2);
	ft_list_push_front(&list, s1);
	
	printf("------------------List content----------------\n");
	t_list *tmp = list;
	while (tmp)
	{
		printf("%s\n", (char*)tmp->data);
		tmp = tmp->next;
	}

	printf("size : %d\n", ft_list_size(list));

	ft_list_sort(&list, &(ft_strcmp));

	printf("------------------After sort----------------\n");
	tmp = list;
	while (tmp)
	{
		printf("%s\n", (char*)tmp->data);
		tmp = tmp->next;
	}

	ft_list_remove_if(&list, s4, &ft_strcmp);
	ft_list_remove_if(&list, s3, &ft_strcmp);

	printf("------------------After removing----------------\n");
	tmp = list;
	while (tmp)
	{
		printf("%s\n", (char*)tmp->data);
		tmp = tmp->next;
	}

	printf("size : %d\n", ft_list_size(list));

	ft_list_remove_if(&list, s2, &ft_strcmp);
	ft_list_remove_if(&list, s1, &ft_strcmp);

//	 atoi base test 
	char base[] = "0123456789abcdef";
	char num[] = "-7e4";

	printf("%d\n", ft_atoi_base(num, base));
	printf("%d\n", atoi("-2020"));*/

	return (0);
}
