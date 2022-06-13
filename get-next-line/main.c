#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *line = NULL;
	int ret = 0;

	printf("=============================================Start testing===================================================\n");

	printf("\n============================================test null pointer===============================================\n");

	int fd = open("main.c", O_RDWR);
	printf("fd = %d, %s, return : %d\n", fd, !line ? "NULL pointer" : "wtf", get_next_line(fd, NULL));
	close(fd);

	printf("\n============================================test invalid fd=================================================\n");

	int fd1 = -1;
	printf("fd = %d, %s, return : %d\n", fd1, !line ? "empty string" : "smth", get_next_line(fd1, &line));
	free(line);

	printf("\n");

	int fd2 = 34523;
	printf("fd = %d, %s, return : %d\n", fd2, !line ? "empty string" : "smth", get_next_line(fd2, &line));
	free(line);

	printf("\n============================================test emty file==================================================\n");

	int fd3 = open("test/empty_file.txt", O_RDWR);
	printf("fd = %d, %s, return : %d\n", fd3, !line ? "empty string" : "empty file", get_next_line(fd3, &line));
	free(line);
	close(fd3);

	printf("\n============================================test newlines===================================================\n");

	int fd4 = open("test/nl1.txt", O_RDWR);
	printf("1 newline symbol, fd = %d\n", fd4);
	while ((ret = get_next_line(fd4, &line)))
	{
		printf("|%s|, return : %d\n", line, ret);
		free(line);
	}
	printf("|%s|, return : %d\n", line, ret);
	free(line);
	close(fd4);

	printf("\n");

	int fd5 = open("test/nl2.txt", O_RDWR);
	printf("2 newline symbol, fd = %d\n", fd5);
	while ((ret = get_next_line(fd5, &line)))
	{
		printf("|%s|, return : %d\n", line, ret);
		free(line);
	}
	printf("|%s|, return : %d\n", line, ret);
	free(line);
	close(fd5);

	printf("\n");

	int fd6 = open("test/nl4.txt", O_RDWR);
	printf("4 newline symbol, fd = %d\n", fd6);
	while ((ret = get_next_line(fd6, &line)))
	{
		printf("|%s|, return : %d\n", line, ret);
		free(line);
	}
	printf("|%s|, return : %d\n", line, ret);
	free(line);
	close(fd6);

	printf("\n============================================test smth=======================================================\n");

	int fd7 = open("test/file1.txt", O_RDWR);
	printf("file 1, fd = %d\n", fd7);
	while ((ret = get_next_line(fd7, &line)))
	{
		printf("|%s|, return : %d\n", line, ret);
		free(line);
	}
	printf("|%s|, return : %d\n", line, ret);
	free(line);
	close(fd7);

	printf("\n");

	int fd8 = open("test/file2.txt", O_RDWR);
	printf("file 2, fd = %d\n", fd8);
	while ((ret = get_next_line(fd8, &line)))
	{
		printf("|%s|, return : %d\n", line, ret);
		free(line);
	}
	printf("|%s|, return : %d\n", line, ret);
	free(line);
	close(fd8);

	printf("\n");

	int fd9 = open("test/file3.txt", O_RDWR);
	printf("file 3, fd = %d\n", fd9);
	while ((ret = get_next_line(fd9, &line)))
	{
		printf("|%s|, return : %d\n", line, ret);
		free(line);
	}
	printf("|%s|, return : %d\n", line, ret);
	free(line);
	close(fd9);

	printf("\n============================================test DRACULA====================================================\n");

	int fd10 = open("test/extra_large.txt", O_RDWR);
	printf("dracula, fd = %d\n", fd10);
	while ((ret = get_next_line(fd10, &line)))
	{
		printf("|%s|, return : %d\n", line, ret);
		free(line);
	}
	printf("|%s|, return : %d\n", line, ret);
	free(line);
	close(fd10);

	printf("\n============================================test different fd===============================================\n");

	int fd11 = open("test/file1.txt", O_RDWR);
	int fd12 = open("test/file2.txt", O_RDWR);
	int fd13 = open("test/file3.txt", O_RDWR);
	printf("file1 : fd1 = %d, file2 : fd2 = %d, file3 : fd3 = %d\n", fd11, fd12, fd13);

	get_next_line(fd12, &line);
	printf("read string from file 2 :\n|%s|\n", line);
	free(line);

	while ((ret = get_next_line(fd11, &line)))
	{
		printf("|%s|, return : %d\n", line, ret);
		free(line);
	}
	free(line);

	get_next_line(fd12, &line);
	printf("read string from file 2 again :\n|%s|\n", line);
	free(line);

	get_next_line(fd13, &line);
	printf("read string from file 3 :\n|%s|\n", line);
	free(line);

	get_next_line(fd12, &line);
	printf("read string from file 2 again :\n|%s|\n", line);
	free(line);

	get_next_line(fd13, &line);
	printf("read string from file 3 again :\n|%s|\n", line);
	free(line);

	get_next_line(fd13, &line);
	printf("read string from file 3 again :\n|%s|\n", line);
	free(line);

	close(fd11);
	close(fd12);
	close(fd13);


	printf("\n============================================test alphabet===================================================\n");
	int fd14 = open("test/alphabet.txt", O_RDWR);
	while ((ret = get_next_line(fd14, &line)))
	{
		printf("|%s|, return : %d\n", line, ret);
		free(line);
	}
	printf("|%s|, return : %d\n", line, ret);
	free(line);
	close(fd14);

	printf("\n============================================test large line=================================================\n");
	int fd15 = open("test/large_line.txt", O_RDWR);
	while ((ret = get_next_line(fd15, &line)))
	{
		printf("|%s|, return : %d\n", line, ret);
		free(line);
	}
	printf("|%s|, return : %d\n", line, ret);
	free(line);
	close(fd15);

	// printf("\n============================================test Stdin======================================================\n");

	// printf("stdin, fd = 0\n");
	// while ((ret = get_next_line(0, &line)))
	// {
	// 	printf("|%s|, return : %d\n", line, ret);
	// 	free(line);
	// }
	// printf("|%s|, return : %d\n", line, ret);
	// free(line);

	printf("\n=============================================End testing=====================================================\n");

	return (0);
}
