/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <math.h>

# define ISO_ANGLE 0.463734
# define ROT_ANGLE 0

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_intvector
{
	int			x;
	int			y;
}				t_intvector;

t_vector	know_vector(t_vector from_v, t_vector to_v);
t_vector	sum_vectors(t_vector v1, t_vector v2);
t_vector	scale_vector(t_vector v, float scale, int diviser);
t_vector	isometric_matrix(t_vector v, float angle);

t_vector	rotate(t_vector v, float angle);
#endif
