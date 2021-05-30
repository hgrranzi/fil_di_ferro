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
	while (line[i] && (aka_isdigit(line[i]) || line[i] == ' '))
		i++;
	if (line[i] != '\0')
		finish_it(ERR_MAP, data);
	if (i - 1 > data->map_width)
		data->map_width = i - 1;
}

void	check_config(t_data *data, char *filename)
{
	int		fd;
	char	*line;
	int		line_len;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		finish_it(errno, data);
	line = NULL;
	line_len = 1;
	data->map_width = -MAX_INT;
	while (line_len > 0)
	{
		line_len = take_line(fd, &line);
		if (*line != '\0')
			check_line(line, data);
			// add to list?
		free(line);
		line = NULL;
	}
	free(line);
	if (line_len == -1)
		finish_it(ERR_READ, data);
}
