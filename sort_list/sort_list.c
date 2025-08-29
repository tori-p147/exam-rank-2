#include "list.h"
#include "stdio.h"
#include "stdlib.h"

int	cmp(int a, int b)
{
	return (a >= b);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*ptr;
	int		tmp;

	ptr = lst;
	while (lst && lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = ptr;
		}
		else
			lst = lst->next;
	}
	return (ptr);
}

int	main(void)
{
	t_list	*list1 = malloc(sizeof(t_list));
	t_list	*list2 = malloc(sizeof(t_list));
	t_list	*list3 = malloc(sizeof(t_list));

	list1->data = 2;
	list1->next = list2;
	list2->data = 1;
	list2->next = list3;
	list3->data = 3;
	list3->next = NULL;
    t_list *ptr = list1;
	while (ptr)
	{
		printf("%d data %p next \n", ptr->data, ptr->next);
		ptr = ptr->next;
	}
    sort_list(list1, cmp);
    ptr = list1;
	while (ptr)
	{
		printf("%d data %p next \n", ptr->data, ptr->next);
		ptr = ptr->next;
	}
	return (0);
}
