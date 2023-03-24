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
		ft_printf("\nlen_b = %d\n", data->len_b);
	}
	//chequear si ha quedado ordenado
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
	print_stack(data); // borrar
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
	if (data->stack_b[i].cost_a > 0 || data->stack_b[i].cost_b > 0)
		move_rot(data);
	push_a(data);
}
/*
void	move_new(t_data *data)
{
	int	pos;

	pos = data->cheap;

	// fijarse si hay que hacer movimientos en a
	if (data->stack_b[pos].cost_a != 0)
	{
		// sino, fijarse en b y hacer mov
		if (data->stack_b[pos].cost_b != 0)
		{
			if (data->stack_b[pos].cost_a > 0 && data->stack_b[pos].cost_b > 0)
			{
					//funcion rotate a b
			}
			else if (data->stack_b[pos].cost_a < 0 && data->stack_b[pos].cost_b < 0)
			{
				//funci'on reverse a b
			}
		}
		else
		{
			// funcion rotate solo a
		}
	}
	// si hay 0 movimientos en a continuar
	else
	{
		//  fijarse si hay movimientos en b
		if (data->stack_b[pos].cost_b > 0)
		{
		// funcon rotate b
		}
		else if (data->stack_b[pos].cost_b < 0)
		{
			// funcion reverse b
		}
	}
	// si hay 0 movimientos continuar
	push_a(data);	
}


void	move(t_data *data)
{
	int	pos;

	pos = data->cheap;

	while (data->stack_b[pos].cost_a > 0 && data->stack_b[pos].cost_b > 0)
	{
		data->stack_b[pos].cost_a--;
		data->stack_b[pos].cost_b--;
		rotate_ab(data);
	}
	while (data->stack_b[pos].cost_a < 0 && data->stack_b[pos].cost_b < 0)
	{
		data->stack_b[pos].cost_a++;
		data->stack_b[pos].cost_b++;
		reverse_ab(data);
	}
	while (data->stack_b[pos].cost_a > 0)
	{
		data->stack_b[pos].cost_a--;
		rotate_a(data, 0);
	}
	while (data->stack_b[pos].cost_b > 0)
	{
		data->stack_b[pos].cost_b--;
		rotate_b(data, 0);
	}
	while (data->stack_b[pos].cost_a < 0)
	{
		data->stack_b[pos].cost_a++;
		reverse_a(data, 0);
	}
	while (data->stack_b[pos].cost_b < 0)
	{
		data->stack_b[pos].cost_b++;
		reverse_b(data, 0);
	}
	push_a(data);	
}
*/