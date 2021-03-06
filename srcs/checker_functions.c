/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:16:08 by jde-agr           #+#    #+#             */
/*   Updated: 2018/08/08 12:01:10 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stacks *s, int flag, int p_flag)
{
	int tmp;

	if (s->len_a > 1)
	{
		tmp = s->stack_a[s->len_a - 2];
		s->stack_a[s->len_a - 2] = s->stack_a[s->len_a - 1];
		s->stack_a[s->len_a - 1] = tmp;
		if (flag)
			write(1, "sa\n", 3);
		if (p_flag)
			print_win(s, flag, p_flag);
	}
}

void	ft_swap_b(t_stacks *s, int flag, int p_flag)
{
	int tmp;

	if (s->len_b > 1)
	{
		tmp = s->stack_b[s->len_b - 2];
		s->stack_b[s->len_b - 2] = s->stack_b[s->len_b - 1];
		s->stack_b[s->len_b - 1] = tmp;
		if (flag)
			write(1, "sb\n", 3);
		if (p_flag)
			print_win(s, flag, p_flag);
	}
}

void	ft_swap_ab(t_stacks *s, int flag, int p_flag)
{
	ft_swap_a(s, flag, p_flag);
	ft_swap_b(s, flag, p_flag);
	if (flag)
		write(1, "ss\n", 3);
	if (p_flag)
		print_win(s, flag, p_flag);
}

void	ft_push_a(t_stacks *s, int flag, int p_flag)
{
	if (s->len_b > 0)
	{
		s->stack_a[s->len_a] = s->stack_b[s->len_b - 1];
		s->len_a++;
		s->len_b--;
		if (flag)
			write(1, "pa\n", 3);
		if (p_flag)
			print_win(s, flag, p_flag);
	}
}

void	ft_push_b(t_stacks *s, int flag, int p_flag)
{
	if (s->len_a > 0)
	{
		s->stack_b[s->len_b] = s->stack_a[s->len_a - 1];
		s->len_b++;
		s->len_a--;
		if (flag)
			write(1, "pb\n", 3);
		if (p_flag)
			print_win(s, flag, p_flag);
	}
}
