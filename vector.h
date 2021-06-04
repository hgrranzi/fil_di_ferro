/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <math.h>

typedef struct	s_vector
{
	float		x;
	float		y;
}				t_vector;

typedef struct	s_intvector
{
	int			x;
	int			y;
}				t_intvector;

t_vector	know_vector(t_vector from_v, t_vector to_v);
t_vector	sum_vectors(t_vector v1, t_vector v2);

#endif
