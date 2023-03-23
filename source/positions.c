/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:58:49 by mahender          #+#    #+#             */
/*   Updated: 2023/03/20 19:58:54 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_a(t_data *data)
{
	int	max;
	int	i;

	i = 0;
	max = data->stack_a[0].index;
	while (i < data->len_a)
	{
		if (data->stack_a[i].index > max)
		{
			max = data->stack_a[i].index;
			data->pos_a_max = data->stack_a[i].pos;
		}
		i++;
	}
	return (max);
}

int	min_a(t_data *data)
{
	int	min;
	int	i;

	i = 0;
	min = data->stack_a[0].index;
	data->pos_a_min = data->stack_a[0].pos;
	while (i < data->len_a)
	{
		if (data->stack_a[i].index < min)
		{
			min = data->stack_a[i].index;
			data->pos_a_min = data->stack_a[i].pos;
		}
		i++;
	}
	return (min);
}

int	next_one(t_data *data, int pos)
{
	int	i;
	int	next;

	i = 0;
	next = max_a(data);
	data->pos_a_next = data->pos_a_max;
	while (i < data->len_a)
	{
		if (data->stack_b[pos].index < data->stack_a[i].index
			&& data->stack_a[i].index < next)
		{
			next = data->stack_a[i].index;
			data->pos_a_next = data->stack_a[i].pos;
		}
		i++;
	}
	return (next);
}
