#ifndef LIST_H
#define LIST_H

typedef struct s_list
{
    struct s_list *next;
    int data;
} t_list;

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));
int cmp(int a, int b);

#endif