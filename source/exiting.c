/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:30:04 by mahender          #+#    #+#             */
/*   Updated: 2023/04/01 16:45:14 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_err(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	exit_num(t_data *data, char *str)
{
	int	i;

	i = 0;
	free(data->num_list);
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	free_mat(t_data *data)
{
	int	i;

	i = data->num_len;
	while (i >= 0)
	{
		free(data->num_mat[i]);
		i--;
	}
	free(data->num_mat);
}

void	exit_mat(t_data *data, char *str)
{
	int	i;

	i = data->num_len;
	while (i >= 0)
	{
		free(data->num_mat[i]);
		i--;
	}
	free(data->num_mat);
	free(data->num_list);
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	free_all(t_data *data)
{
	free(data->stack_a);
	free(data->stack_b);
	free(data->num_list);
}
