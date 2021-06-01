/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "utils.h"

t_lst	*new_lst(void *content)
{
	t_lst	*new_lst;

	new_lst = malloc(sizeof(t_lst));
	if (new_lst)
	{
		new_lst->content = content;
		new_lst->next = NULL;
	}
	return (new_lst);
}

t_lst	*last_lst(t_lst **first_lst)
{
	t_lst	*last_lst;

	last_lst = *first_lst;
	if (last_lst)
		while (last_lst->next)
			last_lst = last_lst->next;
	return (last_lst);
}

void	add_lst(t_lst **first_lst, t_lst *new_lst)
{
	t_lst *lst_p;

	lst_p = last_lst(first_lst);
	if (lst_p)
		lst_p->next = new_lst;
	else
		*first_lst = new_lst;
}
