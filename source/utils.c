/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:24:42 by mahender          #+#    #+#             */
/*   Updated: 2023/03/07 17:54:53 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long long	ft_atoli(const char *str)
{
	int				i;
	long long int	res;
	int				neg;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			neg = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

//función que recorre el array de ints verificando si hay repetidos.
void	is_rep(t_data *data)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (i < data->num_len)
	{
		nb = data->num_list[i];
		j = i + 1;
		while (j < data->num_len)
		{
			if (data->num_list[i] == data->num_list[j])
				exit_num(data, "Error\n"); // borrar repeated num
			j++;
		}
		i++;
	}
}

void	whereiam(t_data *data, char c)
{
	int	i;

	i = 0;
	if (c == 'a')
	{
		while (i < data->len_a && data->len_a > 0)
		{
			data->stack_a[i].pos = i;
			i++;
		}
	}
	else if (c == 'b')
	{
		while (i < data->len_b && data->len_b > 0)
		{
			data->stack_b[i].pos = i;
			i++;
		}
	}
}

//borrar
void	print_stack(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("The cheapest: pos %d\n", data->cheap);
	ft_printf("stack_a (index)\n");
	while (i < data->len_a)
	{
		ft_printf("%d(i%d)<p%d>, ", data->stack_a[i].value,
			data->stack_a[i].index, data->stack_a[i].pos);
		i++;
	}
	ft_printf("\nstack_b (index)\n");
	i = 0;
	while (i < data->len_b)
	{
		ft_printf("%d[i%d]<p%d>{tp%d}(ca%d)(cb%d)(tc%d), ", data->stack_b[i].value,
			data->stack_b[i].index, data->stack_b[i].pos, data->stack_b[i].target_pos,
			data->stack_b[i].cost_a, data->stack_b[i].cost_b, data->stack_b[i].total_cost);
		i++;
	}
	ft_printf("\n");
}