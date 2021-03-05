#ifndef PARSER_H
# define PARSER_H

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
t_cub3d         *get_data(t_temp *temp);
void            get_resolution(t_temp *temp, t_cub3d *data);
void            get_textures(t_temp *temp, t_cub3d *data);
void            get_fc(t_temp *temp, t_cub3d *data);

#endif