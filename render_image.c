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

int	get_color_step(int color, int color2, int count_step)
{
	int	color_step;
	int	r;
	int	g;
	int	b;

	r = (int)((float)(((color2 >> 16) - (color >> 16))) / count_step);
	g = (int)((float)(((color2 >> 8 & 0x00FF) - (color >> 8 & 0x00FF))) / count_step);
	b = (int)((float)(((color2 & 0x0000FF) - (color & 0x0000FF))) / count_step);
	color_step = (r << 16) + (g << 8) + b;
	return (color_step);
}

int	iterate_color(int color, int step)
{
	int			new_color;
	int			r;
	int			g;
	int			b;

	r = (color >> 16) + (step >> 16);
	g = (color >> 8 & 0x00FF) + (step >> 8 & 0x00FF);
	b = (color & 0x0000FF) + (step & 0x0000FF);
	new_color = (r << 16) + (g << 8) + b;
	return (new_color);
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
	int			count_step;
	int			current_step;
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
	current_step = 0;
	while (current_step++ < count_step)
	{
		put_pxl(data, (int)point1.x, (int)point1.y, color);
		point1 = sum_vectors(point1, step);
		color = iterate_color(color, color_step);
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
