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
//	int	i;

	med = data->len_a / 2;
	while (data->len_a > 3)
	{	
//		ft_printf("index: %d, len_b: %d, med: %d\n", data->stack_a[0].index, data->len_b, med);
		if ((data->stack_a[0].index > med) && (data->len_b < med))
			rotate_a(data, 0);
		else
			push_b(data);
	}
	sort_three(data);
	whereiam(data, 'a');
	whereiam(data, 'b');
	while (data->len_b > 0)
	{
		lets_move(data);
		print_stack(data); // borrar
//		ft_printf("\nlen_b = %d\n", data->len_b);
	}
	//chequear si ha quedado ordenado
	if (!is_sorted(data->stack_a, data->len_a))
		final_rev(data);
}

void	lets_move(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->len_b)
	{
		targetpos(data, i);
		costs(data, i);
		i++;
	}
	the_cheapest(data);
	move(data);
	whereiam(data, 'a');
	whereiam(data, 'b');
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
	int	i;

	i = data->cheap;
	if (data->stack_b[i].cost_a < 0 || data->stack_b[i].cost_b < 0)
		move_rev(data);
	else if (data->stack_b[i].cost_a > 0 || data->stack_b[i].cost_b > 0)
		move_rot(data);
	push_a(data);
}

void	final_rev(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = data->len_a - 1;
//	ft_printf("\nOrdenado. Re-organizando\n");
	while (data->stack_a[len].index < data->stack_a[0].index)
		reverse_a(data, 0);
}
