#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 1

void	die(const char *str, int err)
{
	perror(str);
	printf("error code : %d\n", err);
	exit(1);
}

void	print_buff(char *buf, int rbytes)
{
	for (int i = 0; i < rbytes; i++)
		write(1, &buf[i], 1);
}

void cat_file(char *filename)
{
	int fd;
	int rbytes;
	char buf[BUFFER_SIZE];
	int err;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		die(filename, errno);
	rbytes = 1;
	while (rbytes > 0)
	{
		rbytes = read(fd, buf, 1);
		if (rbytes == 0)
			break;
		if (rbytes < 0)
			die(filename, errno);
		print_buff(buf, rbytes);
	}
	if (close(fd) < 0)
	{
		die(filename, errno);
		err = errno;
	}
}

void cat_stdin(void)
{
	char buf[BUFFER_SIZE];
	int rbytes = 1;
	int err;

	printf("There's no input file...\nprinting standard input\n\n");
	while (rbytes > 0)
	{
		rbytes = read(0, buf, BUFFER_SIZE);
		if (rbytes == 0)
			break;
		if (rbytes < 0)
			die("stdin error", errno);
		print_buff(buf, rbytes);
	}
}

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		cat_stdin();
		return 0;
	}
	for (int i = 1; i < argc; i++)
		cat_file(argv[i]);
	return 0;
}