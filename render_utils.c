/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

int	max_step(t_vector v)
{
	t_vector	step;

	step.x = fabs(v.x);
	step.y = fabs(v.y);
	if (step.x > step.y)
		return (step.x);
	else
		return (step.y);
}

t_vector	get_step(int count_step, t_vector step)
{
	t_vector	final_step;

	final_step.x = step.x / count_step;
	final_step.y = step.y / count_step;
	return (final_step);
}

void	move_points(t_vector *v1, t_vector *v2, t_intvector offset)
{
	v1->x += offset.x;
	v1->y += offset.y;
	v2->x += offset.x;
	v2->y += offset.y;
}

int	outside(t_vector point1, t_vector point2, int win_width, int win_height)
{
	if (point1.x < 0 && point2.x < 0 && point1.y < 0 && point2.y < 0)
		return (1);
	if (point1.x >= win_width && point2.x >= win_width && point1.y >= win_height && point2.y >= win_height)
		return (1);
	return (0);
}
