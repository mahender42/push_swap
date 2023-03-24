/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:54:26 by mahender          #+#    #+#             */
/*   Updated: 2023/03/24 16:54:28 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_rev(t_data *data)
{
	int	i;

	i = data->cheap;
	while (data->stack_b[i].cost_a < 0 && data->stack_b[i].cost_b < 0)
	{
		data->stack_b[i].cost_a++;
		data->stack_b[i].cost_b++;
		reverse_ab(data);
		i = (i + 1) % data->len_b;
	}
	if (data->stack_b[i].cost_a < 0)
	{
		while (data->stack_b[i].cost_a < 0)
		{
			data->stack_b[i].cost_a++;
			reverse_a(data, 0);
		}
	}
	if (data->stack_b[i].cost_b < 0)
	{
		while (data->stack_b[i].cost_b < 0)
		{
			data->stack_b[i].cost_b++;
			reverse_b(data, 0);
			i = (i + 1) % data->len_b;
		}
	}
}

void	move_rot(t_data *data)
{
	int	i;

	i = data->cheap;
	while (data->stack_b[i].cost_a > 0 && data->stack_b[i].cost_b > 0)
	{
		data->stack_b[i].cost_a--;
		data->stack_b[i].cost_b--;
		rotate_ab(data);
		i = (i - 1) % data->len_b;
	}
	if (data->stack_b[i].cost_a > 0)
	{
		while (data->stack_b[i].cost_a > 0)
		{
			data->stack_b[i].cost_a--;
			rotate_a(data, 0);
		}
	}
	if (data->stack_b[i].cost_b > 0)
	{
		while (data->stack_b[i].cost_b > 0)
		{
			data->stack_b[i].cost_b--;
			rotate_b(data, 0);
			i = (i - 1) % data->len_b;
		}
	}
}
