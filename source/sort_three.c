/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:38:46 by mahender          #+#    #+#             */
/*   Updated: 2023/04/01 16:51:12 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_data *data)
{
	if (data->len_a == 2)
		swap_a(data, 0);
	else if (data->len_a == 3)
	{
		while (is_sorted(data->stack_a, data->len_a) == 0)
		{
			if (data->stack_a[0].index > data->stack_a[1].index
				&& data->stack_a[0].index > data->stack_a[2].index)
				rotate_a(data, 0);
			if (data->stack_a[1].index > data->stack_a[0].index
				&& data->stack_a[1].index > data->stack_a[2].index)
				reverse_a(data, 0);
			if (data->stack_a[0].index > data->stack_a[1].index
				&& data->stack_a[2].index > data->stack_a[0].index)
				swap_a(data, 0);
		}
	}
}

int	is_sorted(t_stack *stack, int len)
{
	int	i;

	i = 0;
	if (len == 1)
		return (1);
	while (i < (len - 1))
	{
		if (stack[i].value < stack[i + 1].value)
			i++;
		else
			return (0);
	}
	return (1);
}
