/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:24:16 by mahender          #+#    #+#             */
/*   Updated: 2023/04/01 16:52:41 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	value;
	int	index;
	int	pos;
	int	target_pos;
	int	cost_a;
	int	cost_b;
	int	total_cost;
}	t_stack;

typedef struct s_data
{
	int			*num_list;
	char		**num_mat;
	int			num_len;
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			len_a;
	int			len_b;
	int			cheap;
	int			pos_a_max;
	int			pos_a_min;
	int			pos_a_next;
}	t_data;

// validación

void			check_args(t_data *data, int argc, char **argv);
void			check_arg(t_data *data, char **argv);
int				check_signs(char *num);
long long		ft_atoli(const char *str);
int				is_int(char *num);
int				word_count(char const *s, char c);
void			exit_num(t_data *data, char *str);
void			free_mat(t_data *data);
void			exit_mat(t_data *data, char *str);
void			print_err(char *str);
void			free_all(t_data *data);
void			is_rep(t_data *data);

// movimientos

void			swap_a(t_data *data, int flag);
void			swap_b(t_data *data, int flag);
void			swap_ab(t_data *data);
void			push_a(t_data *data);
void			push_b(t_data *data);
void			rotate_a(t_data *data, int flag);
void			rotate_b(t_data *data, int flag);
void			rotate_ab(t_data *data);
void			reverse_a(t_data *data, int flag);
void			reverse_b(t_data *data, int flag);
void			reverse_ab(t_data *data);

// data y ordenamiento de indices

void			create_stack(t_data *data);
void			ft_index(t_data *data);
void			put_index(t_data *data);
void			sort_num_lis(int *array, int len);
int				is_sorted(t_stack *stack, int len);

// ordenamiento y algoritmo

void			sort_three(t_data *data);
void			lets_sort(t_data *data);
void			whereiam(t_data *data, char c);
void			targetpos(t_data *data, int i);
void			costs(t_data *data, int i);
void			total_cost(t_data *data, int i);
void			lets_move(t_data *data);
void			the_cheapest(t_data *data);
int				max_a(t_data *data);
int				min_a(t_data *data);
int				next_one(t_data *data, int pos);
void			move(t_data *data);
void			move_ab(t_data *data);
void			move_a(t_data *data);
void			move_b(t_data *data);
void			final_rev(t_data *data);

#endif
