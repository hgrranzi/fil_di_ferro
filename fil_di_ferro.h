/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef FIL_DI_FERRO_H
# define FIL_DI_FERRO_H

#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "mlx/mlx.h"

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


#endif
