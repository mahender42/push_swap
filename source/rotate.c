/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:31:10 by mahender          #+#    #+#             */
/*   Updated: 2023/04/01 16:51:38 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_data *data, int flag)
{
	int		i;
	t_stack	aux;

	i = 0;
	aux = data->stack_a[0];
	while (i < (data->len_a - 1))
	{
		data->stack_a[i] = data->stack_a[i + 1];
		i++;
	}
	data->stack_a[i] = aux;
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	rotate_b(t_data *data, int flag)
{
	int		i;
	t_stack	aux;

	i = 0;
	if (data->len_b > 1)
	{
		aux = data->stack_b[0];
		while (i < (data->len_b - 1))
		{
			data->stack_b[i] = data->stack_b[i + 1];
			i++;
		}
		data->stack_b[i] = aux;
	}
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	rotate_ab(t_data *data)
{
	rotate_a(data, 1);
	rotate_b(data, 1);
	write(1, "rr\n", 3);
}
