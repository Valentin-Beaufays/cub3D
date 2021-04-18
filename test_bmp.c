#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "./includes/struct.h"

void	save_header(int fd)
{
	uint32_t	offset;
	uint32_t	file_size;

	offset = 54;
	file_size = 54 + 16;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &offset, 4);
}

void	save_info(int fd)
{
	uint32_t	size;
	uint32_t	width;
	uint32_t	height;
	uint16_t	plane;
	uint16_t	bpp;
	uint32_t	len;

	size = 40;
	width = 2;
	height = 2;
	plane = 1;
	bpp = 24;
	len = 16;
	write(fd, &size, 4);
	write(fd, &width, 4);
	write(fd, &height, 4);
	write(fd, &plane, 2);
	write(fd, &bpp, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &len, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

void	save_img(int fd)
{
	write(fd, "\255\0\0", 3);
	write(fd, "\0\255\0", 3);
	write(fd, "\0\0", 2);
	write(fd, "\0\0\255", 3);
	write(fd, "\255\255\255", 3);
	write(fd, "\0\0", 2);
}

int main()
{
	int	fd;

	if ((fd = open("./image.bmp", O_CREAT | O_RDWR, 0666)) < 0)
		exit (-1);
	save_header(fd);
	save_info(fd);
	save_img(fd);
	close(fd);
	return (0);
}