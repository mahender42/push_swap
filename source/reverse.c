/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:41:01 by mahender          #+#    #+#             */
/*   Updated: 2023/04/01 16:52:21 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_a(t_data *data, int flag)
{
	int		i;
	int		len;
	t_stack	aux;

	i = 0;
	len = data->len_a - 1;
	aux = data->stack_a[len];
	while (len > 0)
	{
		data->stack_a[len] = data->stack_a[len - 1];
		len--;
	}
	data->stack_a[len] = aux;
	if (flag == 0)
		write(1, "rra\n", 4);
}

void	reverse_b(t_data *data, int flag)
{
	int		i;
	int		len;
	t_stack	aux;

	i = 0;
	len = data->len_b - 1;
	aux = data->stack_b[len];
	while (len > 0)
	{
		data->stack_b[len] = data->stack_b[len - 1];
		len--;
	}
	data->stack_b[len] = aux;
	if (flag == 0)
		write(1, "rrb\n", 4);
}

void	reverse_ab(t_data *data)
{
	reverse_a(data, 1);
	reverse_b(data, 1);
	write(1, "rrr\n", 4);
}
