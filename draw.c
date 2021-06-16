/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

void	put_pxl(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < data->win_width && y < data->win_height)
	{
		dst = data->image->addr + (y * data->image->line + x * (data->image->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	fill_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			put_pxl(data, x, y, BLACK_COLOR);
			x++;
		}
		y++;
	}
}

int	get_color(int z)
{
	int	color;
	int	r;
	int	g;
	int	b;

	if (z == 0)
		return (WHITE_COLOR);
	if (z > 0)
		color = HIGH_COLOR;
	else
		color = DEEP_COLOR;
	z = abs(z);
	r = color >> 16;
	g = color >> 8 & 0x00FF;
	b = color & 0x0000FF;
	while (z > 0)
	{
		r = (int)((float)r / COLOR_DIVIZER);
		g = (int)((float)g / COLOR_DIVIZER);
		b = (int)((float)b / COLOR_DIVIZER);
		z >>= 1;
	}
	color = (r << 16) + (g << 8) + b;
	return (color);
}

int	get_color_step(int color, int color2, int count_step)
{
	int	color_step;
	int	r;
	int	g;
	int	b;

	r = (int)((float)(((color2 >> 16) - (color >> 16))) / count_step);
	g = (int)((float)(((color2 >> 8 & 255) - (color >> 8 & 255))) / count_step);
	b = (int)((float)(((color2 & 255) - (color & 255))) / count_step);
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
	g = (color >> 8 & 255) + (step >> 8 & 255);
	b = (color & 255) + (step & 255);
	new_color = (r << 16) + (g << 8) + b;
	return (new_color);
}
