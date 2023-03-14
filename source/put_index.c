/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:47:34 by mahender          #+#    #+#             */
/*   Updated: 2023/03/13 19:47:36 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_num_lis(int *array, int len)
{
	int	i;
	int	aux;

	i = 0;
	while (i < (len - 1))
	{
		if (array[i] < array[i + 1])
			i++;
		else
		{
			aux = array[i];
			array[i] = array[i + 1];
			array[i + 1] = aux;
			i = 0;
		}
	}
}

void	put_index(t_data *data)
{
	int	i;
	int	j;
	int	index;
	int	aux;

	i = 0;
	index = 1;
	while (i < data->num_len)
	{
		aux = data->num_list[i];
		j = 0;
		while (j < data->num_len)
		{
			if (aux == data->stack_a[j].value)
			{
				data->stack_a[j].index = index;
				index++;
			}
			j++;
		}
		i++;
	}
}

void	ft_index(t_data *data)
{
	if (is_sorted(data->stack_a, data->len_a) == 0)
	{
		sort_num_lis(data->num_list, data->num_len);
		put_index(data);
	}
	else // ya está ordenado, me salgo
	{
		free_all(data);
		exit(EXIT_SUCCESS);
	}
}


void	create_stack(t_data *data)
{
	int	i;

	data->stack_a = ft_calloc(data->num_len, sizeof(t_stack));
	data->stack_b = ft_calloc(data->num_len, sizeof(t_stack));
	i = 0;
	while (i < data->num_len)
	{
		data->stack_a[i].value = data->num_list[i];
		i++;
	}
	data->len_a = data->num_len;
	data->len_b = 0;
	i = 0; // borrar
	ft_printf("stack_a\n");
	while (i < data->len_a)
	{
		ft_printf("%d, ", data->stack_a[i].value);
		i++;
	}
	ft_printf("\n");  // hasta aquí
	ft_index(data);
}
