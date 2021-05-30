/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef FIL_DI_FERRO_H
# define FIL_DI_FERRO_H

# include "utils.h"

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
}				t_data;

void	check_args(int argc, char **argv, t_data *data);
void	finish_it(int errnum, t_data *data);

#endif
