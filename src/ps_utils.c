/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 03:42:38 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/02 02:24:37 by sshakya          ###   ########.fr       */
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

int	ps_lower(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ps_islower(t_stack *list, int key)
{
	while (list != NULL)
	{
		if (list->index < key)
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

double	ps_atoi(const char *str)
{
	int		sign;
	double	num;

	sign = 1;
	num = 0;
	while (*str)
	{
		if (*str == '-')
			sign = -1;
		if (*str == '-' || *str == '+')
			str++;
		if (ps_isdigit(*str))
		{
			num = num * 10 + (*str - '0');
			str++;
		}
		if (!(ps_isdigit(*str)))
			return (num * sign);
	}
	return (num * sign);
}

int	ps_limit(double num)
{
	if (num > 2147483647)
		return (0);
	if (num < -2147483648)
		return (0);
	return (1);
}

int	ps_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
