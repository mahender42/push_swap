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
		if (data->stack_a[i].index > med && data->len_b < med)
			rotate_a(data, 0);
		else
			push_b(data);
		i++;
	}
	sort_three(data);
}
