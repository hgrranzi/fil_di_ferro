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
	v.z = 0;
	return (v);
}

t_vector		sum_vectors(t_vector v1, t_vector v2)
{
	t_vector	res_v;

	res_v.x = v1.x + v2.x;
	res_v.y = v1.y + v2.y;
	res_v.z = v1.z;
	return (res_v);
}

t_vector		scale_vector(t_vector v, float scale)
{
	t_vector	scaled_v;

	scaled_v.x = v.x * scale;
	scaled_v.y = v.y * scale;
	scaled_v.z = v.z;
	return (scaled_v);
}

t_vector		isometric_matrix(t_vector v)
{
	t_vector	new_v;

	new_v.x = (v.x - v.y) * cos(ANGLE);
	new_v.y = (v.x + v.y) * sin(ANGLE) - v.z;
	new_v.z = v.z;
	return (new_v);
}
