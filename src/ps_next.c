/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 11:23:51 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/27 13:06:54 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_count_min(int find, int *stack, int n)
{
	int i;
	i = 0;
	while (stack[i] < find)
		i++;
	return (i + n);
}

int	ps_count_max(int find, int *stack, int n, int min)
{
	int i;
	i = 0;
	while (stack[i] > find && stack[i] != min)
		i++;
	return (i + n);
}

static int	*ps_array(t_stack *stack, int *size)
{
	int n;
	int	*list;
	t_stack *temp;

	n = 0;
	temp = stack;
	*size = ps_size(stack);
	list = malloc(sizeof(int) * (*size));
	while (n < *size)
	{
		list[n] = temp->index;
		temp = temp->next;
		n++;
	}
	return (list);
}

static int	ps_move_max(int min, int *a, int n, int *size)
{
	if (n <= size[1] / 2)
		return (ps_count_min(min, a, n));
	else
		return (ps_count_min(min, a, n % size[1]));
}

static int	ps_move_min(int *lim, int *a, int n, int *size)
{	
	if (n <= size[1] / 2)
		return(ps_count_max(lim[1], a, n, lim[0]));
	else
		return(ps_count_max(lim[1], a, n % size[1], lim[0]));
}

static int	ps_move(int n, int i, int *size)
{
	if (n <= size[1] / 2)
		return (i + n);
	else
		return (i + n % size[1]);
}

static int	*ps_move_count(int *a, int *b, int *size, t_psdata *stack)
{
	int n;
	int	i;
	int	lim[2];
	int	*c;
	n = 0;
	lim[0] = ps_min_stack(stack->a);
	lim[1] = ps_max_stack(stack->a);
	c = malloc(sizeof(int) * size[1]);
	while (n < size[1])
	{
		i = 0;
		while (i < size[0] - 1)
		{
			if (b[n] < lim[0])
				c[n] = ps_move_max(lim[0], a, n, size);
			if (b[n] > lim[1])
				c[n] = ps_move_min(lim, a, n, size);
			if (a[i] < b[n] && a[i + 1] > b[n] && b[n] < lim[1] && b[n] > lim[0])
				c[n] = ps_move(n , i, size);
				i++;
		}
		n++;
	}
	return (c);
}

static int	*ps_get_count(t_psdata *stack, int **b)
{
	int *a;
	int *c;
	int	size[2];

	a = ps_array(stack->a, &size[0]);
	*b = ps_array(stack->b, &size[1]);
	c = ps_move_count(a, *b, size, stack);

	return (c);
}

int	ps_next(t_psdata *stack, int *dir)
{
	int *c;
	int *b;
	int n;
	int moves;

	c = ps_get_count(stack, &b);
	int	index;
	n = 0;
	moves = c[n];
	index = b[n];
	*dir = 0;
	while (n < ps_size(stack->b))
	{
		if (c[n] < moves)
		{
			moves = c[n];
			index = b[n];
			if (n >= ps_size(stack->b) / 2)
				*dir = 1;
		//	printf("b => n = %d\t value = %d\n", n, index);
		//	printf("c => n = %d\t moves = %d\n", n, moves);
		}
		n++;
	}
	//printf("smallest = %d & dir = %d\n", index, *dir);
	return (index);
}
