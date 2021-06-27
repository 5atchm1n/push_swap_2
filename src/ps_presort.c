/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:01:34 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/26 12:17:22 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_set_index(int *list, t_stack *stack, int size)
{
	int	n;

	while (stack != NULL)
	{
		n = size;
		while (n > -1)
		{
			if (list[n] == stack->n)
				stack->index = n;
			n--;
		}
	stack = stack->next;
	}
}

int	ps_npivots(int size)
{
	if (size < 100)
		return (0);
	if (size < 200)
		return (1);
	if (size >= 200)
		return (size / 150);
	return (0);
}

static void	ps_bubble_sort(int *list, int size)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*ps_pivots(int *list, int size)
{
	int	n;
	int	i;
	int	*keys;

	i = 0;
	n = ps_npivots(size);
	if (n == 0)
		return (NULL);
	keys = malloc(sizeof(int) * n);
	if (keys == NULL)
		return (NULL);
	while (i < n)
	{
		if (n == 1)
			keys[i] = list[(int)(size / 2)];
		else
			keys[i] = list[(int)(i * (size / n))];
		i++;
	}
	return (keys);
}

int	*ps_presort(t_stack *a)
{
	int		size;
	int		*list;
	int		i;

	i = 0;
	size = ps_size(a);
	list = malloc(sizeof(int) * size);
	if (list == NULL)
		return (NULL);
	while (i < size)
	{
		list[i] = a->n;
		a = a->next;
		i++;
	}
	ps_bubble_sort(list, size);
	return (list);
}
