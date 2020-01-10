/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:09:30 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/10 11:14:18 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3d_H

#define FT_CUB3d_H
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# define BUFFER_SIZE 100

static const float fov_angle = 60.0 * (M_PI / 180);
typedef struct	s_x
{
	int		count;
	float	xstep;
	float	ystep;
	float	xintercept;
	float	yintercept;
	float	alpha;
	void	*mlx_ptr;
	void	*mlx_win;
	float	rayon;
	void	*img;
	float	norangle;
	int		size_map_y;
	int		size_map_x;
	int		size_y;
	int		size_x;
	float	distancepplane;
	float	wallstriph;
	char	**map;
	float	xherowall;
	float	yherowall;
	int		up;
	int		down;
	int		left;
	int		right;
	float	x;
	float	y;
	float	x_origine;
	float	y_origine;
	float	angle;
	int		start;
	int		color;
	float	origine_angle;
	float	ray_angle;
	char	wall;
	int		y_end;
	int		y_start;
	int		true_v;
	int		true_h;
	int		x_img_x;
	int		y_img_x;
	int		x_img_x1;
	int		y_img_x1;
	int		x_img_x2;
	int		y_img_x2;
	int		x_img_x3;
	int		y_img_x3;
	void	*img_xpm_x_n;
	void	*img_xpm_x1_s;
	void	*img_xpm_x2_e;
	void	*img_xpm_x3_w;
	char	*texture_n;
	char	*texture_s;
	char	*texture_e;
	char	*texture_w;
	float	offs_x;
	float	offs_y;
	float	off_y;
	float	size_square;
	char	**file;
}				t_win;
void	ft_initionsation(t_win *ptr);
void	img_put(int x, int y, t_win *ptr);
void	ft_gestion(t_win *ptr);
int		ft_keybord(int key, t_win *ptr);
void	ft_keypress(int key, t_win *ptr);
char	ft_wallstop(t_win *ptr, float x, float y);
float	ft_normalizangle(float angle);
void	ft_vuangle(t_win *ptr);
void	ft_herozontal(t_win *ptr);
void	ft_herocalcul(t_win *ptr);
void	ft_vertcalcul(t_win *ptr);
void	ft_vertical(t_win *ptr);
void	ft_chosethepoint(t_win *ptr);
void	ft_readmap(t_win *ptr);
char	*ft_strdup(const char *s1);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
int		ft_check(char *dst);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_position(char *dst);
char	*ft_devision(char *dst, char *src);
void	ft_wall3d(t_win *ptr);
void	ft_playerposition(t_win *ptr);
void	ft_draw_line(t_win *ptr);
void	ft_calcul_wall(t_win *ptr);
void	ft_initionsation1(t_win *ptr);
void	ft_color(t_win *ptr);
void	ft_texture(t_win *ptr);
void	ft_color2(t_win *ptr);
size_t	ft_map_strlen(const char *s);
char	*ft_map_strdup(const char *s1);
void	ft_check_map(t_win *ptr);
void	ft_resulotion(t_win *ptr, char *line);
int		ft_atoi(const char *str);
void	ft_error(int a);
void	ft_help_player(t_win *ptr, int *mapx, int *mapy);
void	ft_colotex(t_win *ptr, char *line);
void	ft_map_help(t_win *ptr, char *line);

#endif
