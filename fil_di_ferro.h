/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef FIL_DI_FERRO_H
# define FIL_DI_FERRO_H

# include "utils.h"
# include "vector.h"
# include "mlx/mlx.h"
# include "minilibx-linux/mlx.h"

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line;
	int			endian;
}				t_image;

typedef struct s_data
{
	void		*mlx_p;
	void		*win_p;
	int			win_width;
	int			win_height;
	t_image		*image;
	int			**map;
	int			**colors;
	int			map_width;
	int			map_height;
	int			zoom;
	int			zoom_diviser;
	t_intvector	offset;
	int			color_flag;
	float		iso_angle;
	float		rot_angle;
}				t_data;

void		check_args(int argc, char **argv, t_data *data);
void		start_mlx(t_data *data);
void		count_win_config(t_data *data, int screen_width, int screen_height);
int			press_key(int key, t_data *data);
int			krestik(int key, t_data *data);

void		check_config(t_data *data, char *filename);
void		save_config(t_lst **first_lst, t_data *data);
int			get_points(char *line, t_data *data, int map_i);
int			check_point(char *point, t_data *data, int map_i, int i);
int			get_nbr(char *point);

void		init_data(t_data *data);
void		remove_data(t_data *data);
void		finish_it(int errnum, t_data *data);

void		put_pxl(t_data *data, int x, int y, int color);
void		fill_background(t_data *data);
int			get_color(int z);
int			get_color_step(int color, int color2, int count_step);
int			iterate_color(int color, int step);

int			render_image(t_data *data);
void		draw_map(t_data *data);
void		draw_line(t_data *data, t_vector point1, t_vector point2);
void		pre_draw(t_data *data, t_vector *point1, t_vector *point2, t_intvector *color);

int			outside(t_vector point1, t_vector point2, int win_width, int win_height);
void		move_points(t_vector *v1, t_vector *v2, t_intvector offset);
t_vector	get_step(int count_step, t_vector step);
int			max_step(t_vector v);

#endif
