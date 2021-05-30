/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "utils.h"

int	aka_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

size_t	aka_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	aka_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	display_error(int errnum)
{
	write(2, "Error\n", 6);
	if (errnum == ERR_ARGS)
		write(2, "Something wrong with arguments.\n", 32);
	else
		write(2, strerror(errnum), aka_strlen(strerror(errnum)));
}
