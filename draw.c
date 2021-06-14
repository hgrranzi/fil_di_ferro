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
	int		color;
	int			r;
	int			g;
	int			b;

	if (z == 0)
		return (WHITE_COLOR);
	if (z > 0)
		color = HIGH_COLOR; // define
	else
		color = DEEP_COLOR; // define
	z = abs(z);
	r = color >> 16;
	g = color >> 8 & 0x00FF;
	b = color & 0x0000FF;
	while (z > 0)
	{
		r = (int)((float)r / 1.25);
		g = (int)((float)g / 1.25);
		b = (int)((float)b / 1.25);
		z >>= 1;
	}
	color = (r << 16) + (g << 8) + b;
	return (color);
}
