/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

void	put_pxl(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0)
	{
		dst = data->image->addr + (y * data->image->line + x * (data->image->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	positive(int n)
{
	if (n < 0)
		return ((-1) * n);
	return (n);
}

t_vector	get_step(t_vector point1, t_vector point2)
{
	t_vector	step;
	int		max_step;

	step.x = point2.x - point1.x;
	step.y = point2.y - point1.y;
	if (positive(step.x) > positive(step.y))
		max_step = step.x;
	else
		max_step = step.y;
	step.x = step.x / max_step;
	step.y = step.y / max_step;
	return (step);
}

void	draw_line(t_data *data, t_vector point1, t_vector point2)
{
	t_vector	step;

	step = get_step(point1, point2);
	while ((int)(point1.x - point2.x) || (int)(point1.y - point2.y))
	{
		put_pxl(data, (int)point1.x, (int)point1.y, 0x00FFFF);
		point1 = sum_vectors(point1, step);
	}
}

int	render_image(t_data *data)
{
	mlx_put_image_to_window(data->mlx_p, data->win_p, data->image->img, 0, 0);
	return (0);
}
