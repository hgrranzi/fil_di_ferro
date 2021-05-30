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

char	*aka_strdup(const char *s)
{
	char	*new_s;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = aka_strlen(s);
	i = 0;
	new_s = malloc((len + 1) * sizeof(char));
	new_s[len] = '\0';
	if (new_s)
	{
		while (s[i])
		{
			new_s[i] = s[i];
			i++;
		}
	}
	return (new_s);
}

char	*aka_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] - 0 == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*aka_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	new_str = malloc((aka_strlen(s1) + aka_strlen(s2) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	display_error(int errnum)
{
	write(2, "Error\n", 6);
	if (errnum == ERR_ARGS)
		write(2, "Something wrong with arguments", 30);
	else if (errnum == ERR_READ)
		write(2, "Something wrong with the config file", 36);
	else
		write(2, strerror(errnum), aka_strlen(strerror(errnum)));
	write(2, "\n", 1);
}
