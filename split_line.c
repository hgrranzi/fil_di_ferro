/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "utils.h"

static char	*strdup_char(const char *s, char c)
{
	char	*new_str;
	size_t	i;
	size_t	len;

	if (aka_strchr(s, c) == NULL)
		len = aka_strlen(s);
	else
		len = aka_strchr(s, c) - s + 1;
	i = 0;
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str)
	{
		while (s[i] != c && s[i] != '\0')
		{
			new_str[i] = s[i];
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}

static char	**free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}

size_t	words_count(const char *s, char delimiter)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == delimiter)
			i++;
		if (s[i] != '\0')
			res++;
		while (s[i] && s[i] != delimiter)
			i++;
	}
	return (res);
}

char	*trim_line(char *s, char c)
{
	char	*trimmed_str;
	size_t	start_trim;
	size_t	finish_trim;

	if (s == NULL)
		return (NULL);
	start_trim = 0;
	finish_trim = aka_strlen(s) - 1;
	while (start_trim < finish_trim && c == s[start_trim])
		start_trim++;
	while (finish_trim > start_trim && c == s[finish_trim])
	{
		s[finish_trim] = '\0';
		finish_trim--;
	}
	trimmed_str = aka_strdup(&s[start_trim]);
	free(s);
	s = NULL;
	return (trimmed_str);
}

char	**split_line(char *s, char c, int *arr_len)
{
	char	*new_str;
	char	**arr;
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	arr = NULL;
	new_str = trim_line(s, c);
	if (!new_str)
		return (NULL);
	*arr_len = words_count(new_str, c);
	arr = calloc(*arr_len + 1, sizeof(char *)); // my own
	while (arr && i < *arr_len)
	{
		arr[i] = strdup_char(&new_str[start], c);
		if (!arr)
			return (free_all(arr));
		start = start + aka_strlen(arr[i]);
		while (new_str[start] == c)
			start++;
		i++;
	}
	return (arr);
}
