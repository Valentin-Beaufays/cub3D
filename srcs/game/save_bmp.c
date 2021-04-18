#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "libft.h"
#include "error.h"
#include "struct.h"
#include "utils.h"
#include <stdint.h>

uint32_t get_line_length(int initial)
{
	uint32_t	length;

	length = initial * 3;
	while (length % 4)
		length++;
	return (length);
}

uint32_t get_size(t_img *frame)
{
	uint32_t	w;

	w = get_line_length(frame->w);
	return (w * frame->h);
}

void	save_header(int fd, t_img *frame)
{
	uint32_t	offset;
	uint32_t	size;

	offset = 54;
	size = offset + get_size(frame);
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &offset, 4);
}

void	save_info(int fd, t_img *frame)
{
	uint32_t	size;
	uint16_t	plane;
	uint16_t	bpp;
	uint32_t	len;

	size = 40;
	plane = 1;
	len = get_size(frame);
	bpp = 24;
	write(fd, &size, 4);
	write(fd, &frame->w, 4);
	write(fd, &frame->h, 4);
	write(fd, &plane, 2);
	write(fd, &bpp, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &len, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

void save_img(int fd, t_img *frame)
{
	int				x;
	int				y;
	uint32_t		color;
	unsigned char	rgb;

	y = frame->h -1;
	while (y >= 0)
	{
		x = 0;
		while (x < frame->w)
		{
			color = (uint32_t)ft_mlx_pixel_get(frame, x, y);
			rgb = get_blue(color);
			write(fd, &rgb, 1);
			rgb = get_green(color);
			write(fd, &rgb, 1);
			rgb = get_red(color);
			write(fd, &rgb, 1);
			x++;
		}
		while (x % 4)
		{
			write(fd, "\0", 1);
			x++;
		}
		y--;
	}
}

int		save_bmp(t_img *frame, t_cub3d *data)
{
	int	fd;

	if ((fd = open("./image.bmp", O_CREAT | O_RDWR, 0666)) < 0)
		free_data_err(strerror(errno), NULL, data);
	save_header(fd, frame);
	save_info(fd, frame);
	save_img(fd, frame);
	close(fd);
}