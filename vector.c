/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "vector.h"

t_vector		know_vector(t_vector from_v, t_vector to_v)
{
	t_vector	v;

	v.x = to_v.x - from_v.x;
	v.y = to_v.y - from_v.y;
	return (v);
}

t_vector		sum_vectors(t_vector v1, t_vector v2)
{
	t_vector	res_v;

	res_v.x = v1.x + v2.x;
	res_v.y = v1.y + v2.y;
	return (res_v);
}

t_vector		scale_vector(t_vector v, float scale)
{
	t_vector	scaled_v;

	scaled_v.x = v.x * scale;
	scaled_v.y = v.y * scale;
	return (scaled_v);
}
