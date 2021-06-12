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

# define WIN_W 1280

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
	t_image		*image;
	int			**map;
	int			**colors;
	int			map_width;
	int			map_height;
	t_vector	*point;
	int			zoom;
	int			color_flag;
}				t_data;

void		check_args(int argc, char **argv, t_data *data);
void		start_mlx(t_data *data);
int			press_key(int key, t_data *data);

void		check_config(t_data *data, char *filename);
void		save_config(t_lst **first_lst, t_data *data);
int			get_points(char *line, t_data *data, int map_i);
int			check_point(char *point, t_data *data, int map_i, int i);
int			get_nbr(char *point);

void		init_data(t_data *data);
void		remove_data(t_data *data);
void		finish_it(int errnum, t_data *data);

int			render_image(t_data *data);
void		put_pxl(t_data *data, int x, int y, int color);
void		fill_background(t_data *data);
void		draw_line(t_data *data, t_vector point1, t_vector point2);
t_vector	get_step(t_vector point1, t_vector point2);
void		draw_map(t_data *data);

#endif
