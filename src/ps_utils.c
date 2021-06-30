/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 03:42:38 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/30 02:27:46 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_size(t_stack *a)
{
	int	size;

	size = 0;
	while (a != NULL)
	{
		size++;
		a = a->next;
	}
	return (size);
}

int	ps_islower(t_stack *list, int key)
{
	while (list != NULL)
	{
		if (list->n < key)
			return (1);
		list = list->next;
	}
	return (0);
}

int	ps_min(t_stack *a, int *index)
{
	int	min;

	*index = 0;
	if (a == NULL)
		return (0);
	min = a->index;
	while (a)
	{
		if (a->index < min)
		{
			min = a->index;
			*index = a->n;
		}
		a = a->next;
	}
	return (min);
}

int	ps_max(t_stack *a, int *index)
{
	int	max;

	*index = 0;
	if (a == NULL)
		return (0);
	max = a->index;
	while (a)
	{
		if (a->index > max)
		{
			max = a->index;
			*index = a->n;
		}
		a = a->next;
	}
	return (max);
}

int	ps_min_stack(t_stack *a)
{
	int	min;

	if (a == NULL)
		return (0);
	min = a->index;
	while (a)
	{
		if (a->index < min)
			min = a->index;
		a = a->next;
	}
	return (min);
}

int	ps_max_stack(t_stack *a)
{
	int	max;

	if (a == NULL)
		return (0);
	max = a->index;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	return (max);
}


