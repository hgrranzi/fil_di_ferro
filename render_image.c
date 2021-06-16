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

int		outside(t_vector point1, t_vector point2, int win_width, int win_height)
{
	if (point1.x < 0 && point2.x < 0 && point1.y < 0 && point2.y < 0)
		return (1);
	if (point1.x >= win_width && point2.x >= win_width && point1.y >= win_height && point2.y >= win_height)
		return (1);
	return (0);
}

void	draw_line(t_data *data, t_vector point1, t_vector point2)
{
	t_vector	step;
	int			count_step;
	int			color;
	int			color2;
	int			color_step;

	point1.z = data->map[(int)point1.y][(int)point1.x];
	point2.z = data->map[(int)point2.y][(int)point2.x];
	if (data->color_flag)
	{
		color = get_color(point1.z);
		color2 = get_color(point2.z);
	}
	else
	{
		color = data->colors[(int)point1.y][(int)point1.x];
		color2 = data->colors[(int)point2.y][(int)point2.x];
	}
	point1 = scale_vector(point1, data->zoom);
	point2 = scale_vector(point2, data->zoom);
	point1 = isometric_matrix(point1, data->angle);
	point2 = isometric_matrix(point2, data->angle);
	move_points(&point1, &point2, data->offset);
	step = know_vector(point1, point2);
	count_step = max_step(step);
	step = get_step(count_step, step);
	color_step = get_color_step(color, color2, count_step);
	if (!outside(point1, point2, data->win_width, data->win_height))
	{
		while (count_step)
		{
			put_pxl(data, (int)point1.x, (int)point1.y, color);
			point1 = sum_vectors(point1, step);
			color = iterate_color(color, color_step);
			count_step--;
		}
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
