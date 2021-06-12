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

t_vector	get_step(t_vector point1, t_vector point2)
{
	t_vector	step;
	int		max_step;

	step.x = point2.x - point1.x;
	step.y = point2.y - point1.y;
	if (fabs(step.x) > fabs(step.y))
		max_step = fabs(step.x);
	else
		max_step = fabs(step.y);
	step.x = step.x / max_step;
	step.y = step.y / max_step;
	return (step);
}

void	draw_line(t_data *data, t_vector point1, t_vector point2)
{
	t_vector	step;
	int			color;

	point1.z = data->map[(int)point1.y][(int)point1.x];
	point2.z = data->map[(int)point2.y][(int)point2.x];
	color = data->colors[(int)point1.y][(int)point1.x];
	point1 = scale_vector(point1, data->zoom);
	point2 = scale_vector(point2, data->zoom);
	step = get_step(point1, point2);
	while ((int)(point1.x - point2.x) || (int)(point1.y - point2.y))
	{
		put_pxl(data, (int)point1.x, (int)point1.y, color);
		point1 = sum_vectors(point1, step);
	}
}

void	draw_map(t_data *data)
{
	t_vector	point;
	t_vector	step_x;
	t_vector	step_y;

	point.y = 0;
	step_x.x = 1;
	step_x.y = 0;
	step_y.x = 0;
	step_y.y = 1;
	while (point.y < data->map_height)
	{
		point.x = 0;
		while (point.x < data->map_width)
		{
			if (point.x < data->map_width - 1)
				draw_line(data, point, sum_vectors(point, step_x));
			if (point.y < data->map_height - 1)
				draw_line(data, point, sum_vectors(point, step_y));
			point = sum_vectors(point, step_x);
		}
		point = sum_vectors(point, step_y);
	}
}

int	render_image(t_data *data)
{
	draw_map(data);
	mlx_put_image_to_window(data->mlx_p, data->win_p, data->image->img, 0, 0);
	return (0);
}
