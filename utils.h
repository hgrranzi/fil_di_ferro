/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <errno.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include <string.h>

# define MAX_INT 2147483647
# define ERR_ATOI 1073741824
# define BUFFER_SIZE 64
# define VALID_CHARS "+-x, ABCDEFabcdef"
# define BLACK_COLOR 0
# define WHITE_COLOR 16777215
# define SUCCES 1
# define FAIL 0
# define ERR_ARGS 222
# define ERR_READ 223
# define ERR_MAP 224

typedef struct		s_lst
{
	void			*content;
	struct s_lst	*next;
}					t_lst;

void	display_error(int errnum);

int		aka_isdigit(char c);
size_t	aka_strlen(const char *s);
int		aka_strcmp(const char *s1, const char *s2);
int		take_line(int fd, char **line);
char	*aka_strdup(const char *s);
char	*aka_strchr(const char *s, int c);
char	*aka_strjoin(char const *s1, char const *s2);
int		aka_atoi_base(char *line, int base);

t_lst	*new_lst(void *content);
t_lst	*last_lst(t_lst **first_lst);
void	add_lst(t_lst **first_lst, t_lst *new_lst);

char	**split_line(char *s, char c);
char	*trim_line(char *s, char const *set);
size_t	words_count(const char *s, char delimiter);

#endif
