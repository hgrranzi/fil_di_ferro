/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

int	get_nbr(char *point)
{
	int	nbr;

	if (point[0] == '0')
	{
		if (point[1] == 'x' || point[1] == 'X')
			nbr = aka_atoi_base(&point[2], 16, HEX_CHARS);
		else
			nbr = aka_atoi_base(&point[1], 8, OCT_CHARS);
	}
	else
		nbr = aka_atoi_base(point, 10, DEC_CHARS);
	return (nbr);
}

int	check_point(char *point, t_data *data, int map_i, int i)
{
	int		base;
	char	*comma_p;

	comma_p = aka_strchr(point, ',');
	if (comma_p)
	{
		*comma_p = '\0';
		comma_p++;
		data->colors[map_i][i] = get_nbr(comma_p);
	}
	else
		data->colors[map_i][i] = WHITE_COLOR;
	data->map[map_i][i] = get_nbr(point);
	if (data->map[map_i][i] == ERR_ATOI || data->colors[map_i][i] == ERR_ATOI || data->colors[map_i][i] < BLACK_COLOR || data->colors[map_i][i] > WHITE_COLOR)
		return (FAIL);
	return (SUCCES);
}

int	get_points(char *line, t_data *data, int map_i)
{
	char	**points;
	int		i;

	i = 0;
	aka_tolower_line(line);
	points = split_line(line, ' ', &data->map_width);
	if (points)
	{
		data->map[map_i] = calloc(data->map_width + 1, sizeof(int));
		data->colors[map_i] = calloc(data->map_width + 1, sizeof(int));
		while (points[i])
		{
			if (!(check_point(points[i], data, map_i, i)))
				break ;
			i++;
		}
		if (points[i])
			return (FAIL);
		free_all(points);
		return (SUCCES);
	}
	return (FAIL);
}

void	save_config(t_lst **first_lst, t_data *data)
{
	t_lst	*lst_p;
	int		map_i;

	lst_p = *first_lst;
	data->map = calloc(data->map_height + 1, sizeof(int *)); // need my own calloc
	data->colors = calloc(data->map_height + 1, sizeof(int *));
	if (data->map && data->colors)
	{
		map_i = 0;
		while (lst_p)
		{
			if (!(get_points(lst_p->content, data, map_i)))
				break ;
			free(lst_p->content);
			lst_p = lst_p->next;
			map_i++;
		}
	}
	if (lst_p)
	{
		remove_all_lst(first_lst);
		finish_it(ERR_READ, data);
	}
	remove_all_lst(first_lst);
}

void	check_config(t_data *data, char *filename)
{
	int		fd;
	char	*line;
	int		line_len;
	t_lst	*line_lst;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		finish_it(errno, data);
	line = NULL;
	line_len = 1;
	line_lst = NULL;
	while (line_len > 0)
	{
		line_len = take_line(fd, &line);
		if (*line)
		{
			add_lst(&line_lst, new_lst(line));
			data->map_height++;
		}
		else
		{
			free(line);
			line = NULL;
		}
	}
	if (line_len == -1)
		finish_it(ERR_READ, data);
	save_config(&line_lst, data);
}
