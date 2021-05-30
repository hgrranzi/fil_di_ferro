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
# include "mlx/mlx.h"

# include <string.h>

# define ERR_ARGS 222

void	display_error(int errnum);

int		aka_isdigit(char c);
size_t	aka_strlen(const char *s);
int		aka_strcmp(const char *s1, const char *s2);

#endif
