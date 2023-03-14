/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:04:01 by mahender          #+#    #+#             */
/*   Updated: 2023/03/08 18:04:03 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_data *data)
{
	int		i;
	t_stack	aux_a;

	if (data->len_b > 0)
	{
		data->len_a++;
		i = data->len_a;
		aux_a = data->stack_b[0];
		while (i > 0)
		{
			data->stack_a[i] = data->stack_a[i - 1];
			i--;
		}
		data->stack_a[0] = aux_a;
		i = 0;
		while (i < data->len_b)
		{
			data->stack_b[i] = data->stack_b[i + 1];
			i++;
		}
		data->len_b--;
		write(1, "pa\n", 3);
	}
}

void	push_b(t_data *data)
{
	int		i;
	t_stack	aux_b;

	if (data->len_a > 0)
	{
		data->len_b++;
		i = data->len_b;
		aux_b = data->stack_a[0];
		while (i > 0)
		{
			data->stack_b[i] = data->stack_b[i - 1];
			i--;
		}
		data->stack_b[0] = aux_b;
		i = 0;
		while (i < data->len_a)
		{
			data->stack_a[i] = data->stack_a[i + 1];
			i++;
		}
		data->len_a--;
	}
	write(1, "pb\n", 3);
}
