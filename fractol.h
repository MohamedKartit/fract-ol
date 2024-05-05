/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:05:05 by mkartit           #+#    #+#             */
/*   Updated: 2024/04/27 13:46:02 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define JULIA 1
# define MANDELBROT 2
# define BURNINGSHIP 3

# define HEIGHT 900
# define WIDTH 900

# define EVENT_CLOSE_BTN 17
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_SPACE 32
# define KEY_ONE 49
# define KEY_TWO 50
# define KEY_THREE 51
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_WHEEL_BTN 3
# define MOUSE_BTN 1
# define KEY_K 107
# define KEY_J 106

typedef struct s_set
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	nr;
	double	ni;
}			t_set;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		max_iter;
	int		set_flag;
	int		color_flag;
	int		color;
	int		color_shift;
	int		*color_range;
	t_set	set;
}			t_data;

typedef enum s_bool
{
	FALSE = 0,
	TRUE = 1
}			t_bool;

/*========== Printers ==========*/
void		ft_putstr_fd(char *s, int fd);
void		display_menu(void);
void		ft_usagemsg(void);

/*========== parsing ===========*/
int			ft_strncmp(const char *s1, const char *s2, size_t n);
t_bool		ft_ishexadiigt(char c);
int			ft_tolower(int c);
double		ft_atof(char *str);
int			ft_ato_color(char *str);
size_t		ft_strlen(const char *s);
void		ft_get_choice(int ac, char **av, t_data *image);

/*========== render ==========*/
void		ft_init(t_data *image);
void		*ft_calloc(size_t count, size_t size);
void		build_img(t_data *image);
void		ft_render(t_data *image);

/*========== colors_utils ==========*/
void		colors_changer(t_data *image);
int			ft_lighter(int color, double percent);
void		color_1(t_data *image, int color);
void		color_2(t_data *iamge, int *colors, int n);
void		color_3(t_data *image, int color);
void		color_4(t_data *image);

/*========== fractals ==========*/
int			julia_shift(int x, int y, t_data *image);
int			ft_julia(double zr, double zi, t_data *image);
int			ft_mandelbrot(double cr, double ci, t_data *image);
int			ft_burningship(double cr, double ci, t_data *image);

/*========== events ==========*/
void		set_limits(t_data *image);
int			mouse_event(int keycode, int x, int y, t_data *image);
int			key_event(int keycode, t_data *image);
int			end_fractol(t_data *image);
void		move(t_data *image, double distance, char direction);
void		zoom(t_data *image, double zoom);

/*========== init ==========*/
void		exit_fractol(t_data *image);

#endif
