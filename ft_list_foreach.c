# include "stdlib.h"
# include "stdio.h"

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

void f(void *data)
{
    char *ptr = (char *)data;
    ptr[0] = 'a';
}

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list *ptr = begin_list;
    while (begin_list)
    {
        printf("%s", (char *)begin_list->data);
        
            (*f)(begin_list->data);
        printf("%s", (char *)begin_list->data);
        begin_list = begin_list->next;
    }
    begin_list = ptr;
}

int main(void)
{
    char str1[2] = "b";
    char str2[2] = "c";
    t_list *head = malloc(sizeof(t_list));
    t_list *node = malloc(sizeof(t_list));
    head->next = node;
    head->data = str1;
    node->data = str2;
    node->next = NULL;
    ft_list_foreach(head, f);
    // while (head)
    // {
    //     printf("%s", (char *)head->data);
    //     head = head->next;
    // }
    return (0);
}