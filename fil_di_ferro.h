/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef FIL_DI_FERRO_H
# define FIL_DI_FERRO_H

# include "utils.h"
# include "mlx/mlx.h"

typedef struct s_vector
{
	int	x;
	int	y;
	int	z;
}				t_vector;

typedef struct s_data
{
	void	*mlx_p;
	void	*win_p;
	int		**map;
	int		**colors;
	int		map_width;
	int		map_height;
}				t_data;

void	check_args(int argc, char **argv, t_data *data);

void	check_config(t_data *data, char *filename);
void	save_config(t_lst **first_lst, t_data *data);
int		get_points(char *line, t_data *data, int map_i);
int		check_point(char *point, t_data *data, int map_i, int i);
int		get_nbr(char *point);

void	init_data(t_data *data);
void	remove_data(t_data *data);
void	finish_it(int errnum, t_data *data);

#endif
