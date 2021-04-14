#include <stddef.h>
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

void	free_map(t_map *map)
{
	size_t i;

	i = 0;
	if (map->map)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}

void	free_mlx(t_mlx	*mlx)
{
	if (mlx->ptr && mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->ptr && mlx->frame.img)
		mlx_destroy_image(mlx->ptr, mlx->frame.img);
}

void	free_sprite(t_sprite *sprite)
{
	t_sprite *next;

	while (sprite)
	{
		next = sprite->next;
		free(sprite);
		sprite = next;
	}
}

void	free_text(t_mlx *m, t_text *t)
{
	if (t->path)
		free(t->path);
	if (t->img.img)
		mlx_destroy_image(m->ptr, t->img.img);
}
