/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:06:30 by mahender          #+#    #+#             */
/*   Updated: 2023/03/08 19:06:31 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_data *data, int flag)
{
	t_stack	aux;

	if (data->len_a > 1)
	{
		aux = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = aux;
	}
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	swap_b(t_data *data, int flag)
{
	t_stack	aux;

	if (data->len_a > 1)
	{
		aux = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = aux;
	}
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	swap_ab(t_data *data)
{
	swap_a(data, 1);
	swap_b(data, 1);
	write(1, "ss\n", 3);
}
