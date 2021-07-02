/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 04:11:30 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/02 02:12:51 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_re_index(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = a;
	i = 0;
	while (a)
	{
		a->n = i;
		a = a->next;
		i++;
	}
	temp = b;
	i = 0;
	while (b)
	{
		b->n = i;
		b = b->next;
		i++;
	}
}

static t_stack	*ps_set_head(t_stack *list)
{
	t_stack	*temp;

	temp = list;
	if (list == NULL)
		return (NULL);
	while (temp != NULL)
	{
		temp->head = list;
		temp = temp->next;
	}
	list->head->prev = NULL;
	return (list->head);
}

static t_stack	*ps_head(t_stack **src, t_stack *dest, char stack)
{
	t_stack	*temp;

	temp = (*src)->head;
	dest = malloc(sizeof(t_stack));
	if (dest == NULL)
		return (NULL);
	dest->head = dest;
	dest->tail = dest;
	dest->index = (*src)->index;
	dest->next = NULL;
	dest->prev = NULL;
	*src = ps_set_head((*src)->next);
	free(temp);
	if (stack == 'a')
		write(1, "pa\n", 3);
	if (stack == 'b')
		write(1, "pb\n", 3);
	return (dest);
}

t_stack	*ps_push(t_stack **src, t_stack *dest, char stack)
{
	t_stack	*temp;

	if (*src == NULL)
		return (dest);
	if (dest == NULL)
		return (ps_head(src, dest, stack));
	dest->prev = malloc(sizeof(t_stack));
	if (dest->prev == NULL)
		return (ps_clear_stack(dest->head));
	dest->prev->index = (*src)->index;
	dest->prev->next = dest;
	dest->prev->prev = NULL;
	dest = ps_set_head(dest->prev);
	ps_set_tail(dest);
	dest->head->n = (*src)->n;
	temp = (*src)->head;
	*src = ps_set_head((*src)->next);
	free(temp);
	if (stack == 'a')
		write(1, "pa\n", 3);
	if (stack == 'b')
		write(1, "pb\n", 3);
	ps_re_index(*src, dest);
	return (dest->head);
}
