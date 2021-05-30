/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "fil_di_ferro.h"

void	display_error()
{
	write(2, "Error\n", 6);
	exit(0);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2 || aka_strlen(argv[1]) < 5
	|| aka_strcmp(&argv[1][aka_strlen(argv[1]) - 4], ".fdf"))
		display_error();
}

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	return (0);
}
