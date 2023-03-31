/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:27:37 by mahender          #+#    #+#             */
/*   Updated: 2023/02/08 17:27:38 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_int(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]) && num[i] != '-' && num[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

int	check_signs(char *num)
{
	int	i;

	i = 0;
	while (num[i] != '\0')
	{
		if ((num[i] == '-' || num[i] == '+') && num[i + 1] == '\0')
			return (0);
		if (num[i + 1] == '-' || num[i + 1] == '+')
			return (0);
		i++;
	}
	return (1);
}

// función que corrobora y guarda el argumento "..." en la estructura.
void	check_arg(t_data *data, char **argv)
{
	int		i;

	i = 0;
	data->num_len = word_count(argv[1], ' ');
	data->num_mat = ft_split(argv[1], ' ');
	data->num_list = calloc(data->num_len, sizeof(int));
	while (i < data->num_len)
	{
		if (!is_int(data->num_mat[i]) || !check_signs(data->num_mat[i]))
			exit_mat(data, "Error\n");
		if (ft_atoli(data->num_mat[i]) > INT_MAX
			|| ft_atoli(data->num_mat[i]) < INT_MIN)
			exit_mat(data, "Error\n");
		else
			data->num_list[i] = ft_atoli(data->num_mat[i]);
		i++;
	}
	free_mat(data);
	is_rep(data);
}

// función que corrobora y guarda los argumentos (+2) en la estructura.
void	check_args(t_data *data, int argc, char **argv)
{
	int		i;

	data->num_len = argc - 1;
	i = 1;
	data->num_list = ft_calloc(data->num_len, sizeof(int));
	while (i <= data->num_len)
	{
		if (!is_int(argv[i]) || !check_signs(argv[i]))
			exit_num(data, "Error\n");
		else if (ft_atoli(argv[i]) > INT_MAX || ft_atoli(argv[i]) < INT_MIN)
			exit_num(data, "Error\n");
		else
		{
			data->num_list[i - 1] = ft_atoli(argv[i]);
			i++;
		}
	}
	is_rep(data);
}

/*static void	leaks(void)
{
	system ("leaks -q push_swap");
}*/

int	main(int argc, char **argv)
{
	t_data	data;

//	atexit(leaks);
	if (argc <= 1)
		return (0);
	else if (argc == 2)
		check_arg(&data, argv);
	else if (argc > 2)
		check_args(&data, argc, argv);
	create_stack(&data);
	if (data.len_a <= 3)
		sort_three(&data);
	else if (data.len_a > 3)
		lets_sort(&data);
	free_all(&data);
	return (0);
}
/*
i = 0;
	ft_printf("\nstack_a - push b\n");
	while (i < data->len_a)
	{
		ft_printf("%d, ", data->stack_a[i].value);
		i++;
	}
	ft_printf("\nstack_b\n");
	i = 0;
	while (i < data->len_b)
	{
		ft_printf("%d, ", data->stack_b[i].value);
		i++;
	}*/