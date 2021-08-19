/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
//# include "keys_mac.h"
# include "keys_linux.h"

# define MAX_INT 2147483647
# define ERR_ATOI 1073741824
# define BUFFER_SIZE 64
# define HEX_CHARS "0123456789abcdef"
# define OCT_CHARS "01234567"
# define DEC_CHARS "0123456789"
# define BLACK_COLOR 0
# define WHITE_COLOR 16777215
# define HIGH_COLOR 16568903
# define DEEP_COLOR 6053119
# define COLOR_DIVIZER 1.2
# define SUCCES 1
# define FAIL 0
# define ERR_ARGS 222
# define ERR_READ 223
# define ERR_MAP 224
# define WIN_SCALE 3 / 4
# define ZOOM_MAX 2000
# define ZOOM_DIVIZER 64
# define STEP_OFFSET 10
# define ISO_ANGLE 0.463734
# define ISO_MAX_ANGLE 0.785398
# define ROT_ANGLE 0
# define STEP_ANGLE 0.05

typedef struct s_lst
{
	void			*content;
	struct s_lst	*next;
}					t_lst;

void	display_error(int errnum);

int		aka_isdigit(char c);
size_t	aka_strlen(const char *s);
int		aka_tolower(int c);
void	aka_tolower_line(char *line);
int		aka_strcmp(const char *s1, const char *s2);
int		take_line(int fd, char **line);
char	*aka_strdup(const char *s);
char	*aka_strchr(const char *s, int c);
void	*aka_calloc(size_t count, size_t size);
char	*aka_strjoin(char const *s1, char const *s2);
int		aka_atoi_base(char *line, int base, char *base_line);

t_lst	*new_lst(void *content);
t_lst	*last_lst(t_lst **first_lst);
void	add_lst(t_lst **first_lst, t_lst *new_lst);
void	remove_lst(t_lst **lst);
void	remove_all_lst(t_lst **first_lst);

char	**split_line(char *s, char c, int *arr_len);
char	*trim_line(char *s, char c);
size_t	words_count(const char *s, char delimiter);
char	**free_all(char **arr);

#endif
