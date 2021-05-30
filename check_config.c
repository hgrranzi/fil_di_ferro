/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

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
	while (line_len > 0)
	{
		line_len = take_line(fd, &line);
		//if (*line != '\0')
		free(line);
	}
	if (line_len == -1)
		finish_it(ERR_READ, data);
}
