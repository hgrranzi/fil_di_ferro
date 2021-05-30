/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

void	finish_it(int errnum, t_data *data)
{
	if (errnum != 0)
		display_error(errnum);
	//here will be the cleaning all function
	exit (0);
}

void	check_args(int argc, char **argv, t_data *data)
{
	if (argc != 2 || aka_strlen(argv[1]) < 5
	|| aka_strcmp(&argv[1][aka_strlen(argv[1]) - 4], ".fdf"))
		finish_it(ERR_ARGS, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, argv, &data);
	return (0);
}
