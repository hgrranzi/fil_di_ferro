/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

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

void	move_points(t_vector *v1, t_vector *v2, int offset)
{
	v1->x += offset;
	v1->y += offset;
	v2->x += offset;
	v2->y += offset;
}

void	draw_line(t_data *data, t_vector point1, t_vector point2)
{
	t_vector	step;
	int			color;

	point1.z = data->map[(int)point1.y][(int)point1.x];
	point2.z = data->map[(int)point2.y][(int)point2.x];
	if (data->color_flag)
		color = get_color(point1.z);
	else
		color = data->colors[(int)point1.y][(int)point1.x];
	point1 = scale_vector(point1, data->zoom);
	point2 = scale_vector(point2, data->zoom);
	point1 = isometric_matrix(point1, data->angle);
	point2 = isometric_matrix(point2, data->angle);
	move_points(&point1, &point2, data->offset);
	step = get_step(point1, point2);
	while ((int)(point2.x - point1.x) || (int)(point2.y - point1.y))
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
	fill_background(data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_p, data->win_p, data->image->img, 0, 0);
	return (0);
}
