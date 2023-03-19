/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:22:36 by mahender          #+#    #+#             */
/*   Updated: 2023/03/14 18:22:39 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lets_sort(t_data *data)
{
	int	med;
	int	i;

	med = data->len_a / 2;
	i = 0;
	while (data->len_a > 3)
	{	
		if (data->stack_a[i].index > med && data->len_b < med)
			rotate_a(data, 0);
		else
			push_b(data);
		i++;
	}
	sort_three(data);
	lets_move(data);
}

void	lets_move(t_data *data)
{
	int	i;

	whereiam(data->stack_a);
	whereiam(data->stack_b);
	targetpos(data);
	i = 0;
	while (i < data->len_b)
	{
		costs(data, i);
		i++;
	}
}

void targetpos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->len_a)
	{
		j = 0;
		while (j <= data->len_b)
		{
			if (data->stack_b[j].index == (data->stack_a[i].index + 1))
			{
				if ((i + 1) == data->len_a)
					data->stack_b[j].target_pos = data->stack_a[0].pos;
				else
					data->stack_b[j].target_pos = data->stack_a[i + 1].pos;
			}	
			j++;
		}
		i++;
	}
}

void costs(t_data *data, int i)
{
	if (data->stack_b[i].target_pos > (data->len_a - data->stack_b[i].target_pos))
		data->stack_b[i].cost_a = (data->len_a - data->stack_b[i].target_pos) * -1;
	else
		data->stack_b[i].cost_a = data->stack_b[i].target_pos;
	if (data->stack_b[i].pos > (data->len_b - data->stack_b[i].pos))
		data->stack_b[i].cost_b = (data->len_b - data->stack_b[i].pos) * -1;
	else
		data->stack_b[i].cost_b = data->stack_b[i].pos;
	total_cost(data, i);
}

void	total_cost(t_data *data, int i)
{
	int	a_cost;
	int	b_cost;

	if (data->stack_b[i].cost_a < 0)
		a_cost = data->stack_b[i].cost_a * -1;
	else
		a_cost = data->stack_b[i].cost_a;
	if (data->stack_b[i].cost_b < 0)
		b_cost = data->stack_b[i].cost_b * -1;
	else
		b_cost = data->stack_b[i].cost_b;
	if ((data->stack_b[i].cost_a > 0 && data->stack_b[i].cost_b > 0) || (data->stack_b[i].cost_a < 0 && data->stack_b[i].cost_b < 0))
	{
		if (a_cost > b_cost)
			data->stack_b[i].total_cost = a_cost;
		else
			data->stack_b[i].total_cost = b_cost;
	}
	else
		data->stack_b[i].total_cost = a_cost + b_cost;
}

