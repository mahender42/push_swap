/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:38:46 by mahender          #+#    #+#             */
/*   Updated: 2023/03/14 15:55:02 by mahender         ###   ########.fr       */
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
/*If the index of the first number is highest, do ra,
Otherwise, if the index of the second number is highest, do rra,
Then, if the index of the first number is bigger than the index of the second number, do sa.*/

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
