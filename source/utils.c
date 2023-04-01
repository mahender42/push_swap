/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:24:42 by mahender          #+#    #+#             */
/*   Updated: 2023/04/01 16:50:07 by mahender         ###   ########.fr       */
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
				exit_num(data, "Error\n");
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
