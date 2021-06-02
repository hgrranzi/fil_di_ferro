/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

void	check_line(char *line, t_data *data)
{
	int	i;

	i = 0;
	if (line == '\0')
	{
		free(line);
		line = NULL;
	}
	else
	{
		while (line[i] && (aka_isdigit(line[i]) || aka_strchr(VALID_CHARS, line[i])))
			i++;
		if (line[i] != '\0')
			finish_it(ERR_MAP, data);
	}
	// probably better to count number of points in the line here
}
int	check_point(char *point, t_data *data)
{
	//here coordinates will be writen into map
	return (SUCCES);
}

int	get_points(char *line, t_data *data)
{
	char	**points;
	int		i;

	i = 0;
	points = split_line(line, ' ');
	if (points)
	{
		while (points[i])
		{
			if (!(check_point(points[i], data)))
				break ;
			i++;
		}
		if (points[i])
			return (FAIL);
	}
	return (SUCCES);
}

void	save_config(t_lst **first_lst, t_data *data)
{
	t_lst	*lst_p;

	lst_p = *first_lst;
	data->map = calloc(data->map_height + 1, sizeof(int *)); // need my own calloc
	data->colors = calloc(data->map_height + 1, sizeof(int *));
	if (data->map && data->colors)
	{
		while (lst_p)
		{
			if (!(get_points(lst_p->content, data)))
				break ;
			lst_p = lst_p->next;
		}
	}
	if (lst_p)
	{
		// remove lst
		finish_it(errno, data);
	}
	// remove lst

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
		check_line(line, data); // probably no need to check line before save config
		if (*line)
			add_lst(&line_lst, new_lst(line));
	}
	if (line_len == -1)
		finish_it(ERR_READ, data);
	save_config(&line_lst, data);
}
