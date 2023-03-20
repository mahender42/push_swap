/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:44:36 by mahender          #+#    #+#             */
/*   Updated: 2023/03/20 18:44:39 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	the_cheapest(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->len_b)
	{
		if (data->stack_b[i].total_cost < data->stack_b[i + 1].total_cost)
			data->cheap = data->stack_b[i].pos;
		i++;
	}
}

void	costs(t_data *data, int i)
{
	if (data->stack_b[i].target_pos
		> (data->len_a - data->stack_b[i].target_pos))
		data->stack_b[i].cost_a
			= (data->len_a - data->stack_b[i].target_pos) * -1;
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
	if ((data->stack_b[i].cost_a > 0 && data->stack_b[i].cost_b > 0)
		|| (data->stack_b[i].cost_a < 0 && data->stack_b[i].cost_b < 0))
	{
		if (a_cost > b_cost)
			data->stack_b[i].total_cost = a_cost;
		else
			data->stack_b[i].total_cost = b_cost;
	}
	else
		data->stack_b[i].total_cost = a_cost + b_cost;
}
