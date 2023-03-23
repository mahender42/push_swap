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
		if ((data->stack_a[i].index > med) && (data->len_b < med))
			rotate_a(data, 0);
		else
			push_b(data);
		i++;
	}
	sort_three(data);
	while (data->len_b > 0)
		lets_move(data);
	//chequear si ha quedado ordenado
}

void	lets_move(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->len_b)
	{
		whereiam(data, 'a');
		whereiam(data, 'b');
		targetpos(data, i);
		costs(data, i);
		i++;
	}
	the_cheapest(data);
	move(data);
}

void	targetpos(t_data *data, int i)
{
	if (data->stack_b[i].index > max_a(data))
	{
		min_a(data);
		data->stack_b[i].target_pos = data->pos_a_min;
	}
	else
	{
		next_one(data, i);
		data->stack_b[i].target_pos = data->pos_a_next;
	}
}

void	move(t_data *data)
{
	int	pos;

	pos = data->cheap;
	while (data->stack_b[pos].cost_a > 0 && data->stack_b[pos].cost_b > 0)
	{
		rotate_ab(data);
		data->stack_b[pos].cost_a--;
		data->stack_b[pos].cost_b--;
	}
	while (data->stack_b[pos].cost_a < 0 && data->stack_b[pos].cost_b < 0)
	{
		reverse_ab(data);
		data->stack_b[pos].cost_a++;
		data->stack_b[pos].cost_b++;
	}
	while (data->stack_b[pos].cost_a > 0)
	{
		rotate_a(data, 0);
		data->stack_b[pos].cost_a--;
	}
	while (data->stack_b[pos].cost_b > 0)
	{
		rotate_b(data, 0);
		data->stack_b[pos].cost_b--;
	}
	while (data->stack_b[pos].cost_a < 0)
	{
		reverse_a(data, 0);
		data->stack_b[pos].cost_a++;
	}
	while (data->stack_b[pos].cost_b < 0)
	{
		reverse_b(data, 0);
		data->stack_b[pos].cost_b++;
	}
	push_a(data);	
}
