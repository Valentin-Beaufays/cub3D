#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "libft.h"
#include "error.h"
#include "struct.h"
#include "utils.h"

void	save_header(int fd, t_img *frame)
{
	int	offset;
	int	size;

	offset = 14 + 40;
	size = offset + (24 * frame->h * frame->w);
	ft_putstr_fd("BM", fd);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &offset, 4);
}

void	save_info(int fd, t_img *frame)
{
	int	size;
	int	plane;

	size = 40;
	plane = 1;
	write(fd, &size, 4);
	write(fd, &frame->w, 4);
	write(fd, &frame->h, 4);
	write(fd, &plane, 2);
	write(fd, &frame->bpp, 2);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 24);
}

void save_img(int fd, t_img *frame)
{
	int		x;
	int		y;
	int		color;
	char	rgb;

	y = frame->h -1;
	while (y >= 0)
	{
		x = 0;
		while (x < frame->w)
		{
			color = ft_mlx_pixel_get(frame, x, y);
			rgb = get_blue();
			write(fd, &color, 4);
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
}