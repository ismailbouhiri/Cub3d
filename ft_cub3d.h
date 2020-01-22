/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:09:30 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/22 20:18:06 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H

# define FT_CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include <string.h>
# define BUFFER_SIZE 1

typedef struct	s_objet
{
	float			x_sprit;
	float			y_sprit;
	float			ds_sprit;
	struct s_objet	*next;
}				t_list;
float g_sprit[2560];
t_list	*g_head;
t_list	*g_new;
t_list	*g_tmp;
t_list	*g_draw;
static const float g_fov_angle = 60.0 * (M_PI / 180);

typedef struct	s_bmp
{
	int				width;
	int				height;
	unsigned	int	bitcount;
	int				width_in_bytes;
	unsigned	int	imagesize;
	unsigned	int	bisize;
	unsigned	int	ffbits;
	unsigned	int	filesize;
	char			*header;
	unsigned int	biplanes;
}				t_str;

struct			s_key
{
	short front;
	short back;
	short left;
	short right;
	short cam_left;
	short cam_right;
	short esc;
}				go;

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
	void	*img_xpm_sprit;
	char	*sprit;
	char	*texture_n;
	char	*texture_s;
	char	*texture_e;
	char	*texture_w;
	int		s_x;
	int		s_y;
	float	offs_x;
	float	offs_y;
	float	off_y;
	float	size_square;
	char	**file;
	int		spt_size;
	int		x_sp;
	int		y_sp;
	float	sp_dr;
	int		fcolor;
	int		ccolor;
	int		argc;
}				t_win;
void			ft_initionsation(t_win *ptr);
void			img_put(int x, int y, t_win *ptr);
void			ft_gestion(t_win *ptr);
int				ft_keybord(t_win *ptr);
void			ft_keypress(t_win *ptr);
char			ft_wallstop(t_win *ptr, float x, float y);
float			ft_normalizangle(float angle);
void			ft_vuangle(t_win *ptr);
void			ft_herizontal(t_win *ptr);
void			ft_hericalcul(t_win *ptr);
void			ft_vertcalcul(t_win *ptr);
void			ft_vertical(t_win *ptr);
void			ft_chosethepoint(t_win *ptr);
void			ft_readmap(t_win *ptr);
void			ft_wall3d(t_win *ptr);
void			ft_playerposition(t_win *ptr);
void			ft_draw_line(t_win *ptr);
void			ft_calcul_wall(t_win *ptr);
void			ft_initionsation1(t_win *ptr);
void			ft_color(t_win *ptr);
void			ft_texture(t_win *ptr);
void			ft_color2(t_win *ptr);
size_t			ft_map_strlen(const char *s);
char			*ft_map_strdup(const char *s1);
void			ft_check_map(t_win *ptr);
void			ft_resulotion(t_win *ptr, char *line);
int				ft_atoi(const char *str);
void			ft_error(t_win *ptr, int a);
void			ft_help_player(t_win *ptr, int *mapx, int *mapy);
void			ft_colotex(t_win *ptr, char *line);
void			ft_map_help(t_win *ptr, char *line);
void			ft_clean(t_win *ptr);
void			ft_sprit_corr(t_win *ptr);
t_list			*ft_lstnew(float x, float y, float ds);
void			ft_lstadd_back(t_list **head, t_list *new);
int				get_next_line(int fd, char **line);
int				check(int *p, char *buff);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t count, size_t size);
void			ft_cal_ds(t_win *ptr);
void			ft_draw_sprit(t_win *ptr);
void			ft_swap(float *a, float *b);
void			ft_swap_ds();
void			ft_what(t_win *ptr, int *mapx, int *mapy);
void			ft_rgb(t_win *ptr, char *line);
void			ft_rgb_help(t_win *ptr, char *line);
void			ft_ini_bmp(t_win *ptr, t_str *bmp);
long long		ft_get_img_pix(t_win *ptr, int x, int y);
void			ft_bmp_last(t_str *bmp, unsigned char *buf);
void			ft_bmp_next(t_win *ptr, t_str *bmp);
void			ft_bmp_file(t_win *ptr);
char			*ft_memcpy(char *dst, const void *src, size_t n);
int				ft_check_arg(int argc, char *dst);
void			ft_move(t_win *ptr);
int				ft_rel(int key);
int				ft_press(int key);
int				ft_x(t_win *ptr);
void			ft_draw_line1(t_win *ptr);
void			ft_hep_spri(t_win *ptr);
void			ft_help(t_win *ptr, int a);

#endif
