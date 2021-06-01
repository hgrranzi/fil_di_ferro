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
		check_line(line, data);
		if (*line)
			add_lst(&line_lst, new_lst(line));
	}
	if (line_len == -1)
		finish_it(ERR_READ, data);
	// save coordinates into struct
}
