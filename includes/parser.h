#ifndef PARSER_H
# define PARSER_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "../get_next_line/get_next_line.h"

typedef struct	s_temp
{
    int         fd;
    char        *line;
    char        *trim;
    int         x;
    int         y;
    char        *north;
    char        *south;
    char        *west;
    char        *east;
    char        *sprite;
    int         floor_R;
    int         floor_G;
    int         floor_B;
    int         ceiling_R;
    int         ceiling_G;
    int         ceiling_B;
    char         **map;
}				t_temp;

void            init_temp(t_temp *temp, int fd);
int             check_path(char *path, char *ext);
int	            get_arg(t_temp *temp);
void	        parse_resolution(t_temp *temp);
void            parse_no_texture(t_temp *temp);
void            parse_so_texture(t_temp *temp);
void            parse_we_texture(t_temp *temp);
void            parse_ea_texture(t_temp *temp);
void            parse_s_texture(t_temp *temp);
void            parse_floor(t_temp *temp);
void            parse_ceiling(t_temp *temp);
void            parse_map(t_temp *temp);

#endif