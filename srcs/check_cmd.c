/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:15:40 by jde-agr           #+#    #+#             */
/*   Updated: 2018/08/08 09:46:33 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_ccmd(char *l)
{
	if (!ft_strcmp(l, "sa") || !ft_strcmp(l, "sb") ||
		!ft_strcmp(l, "ss") || !ft_strcmp(l, "pa") ||
		!ft_strcmp(l, "pb") || !ft_strcmp(l, "ra") ||
		!ft_strcmp(l, "rb") || !ft_strcmp(l, "rr") ||
		!ft_strcmp(l, "rra") || !ft_strcmp(l, "rrb") ||
		!ft_strcmp(l, "rrr"))
		return (1);
	if (!ft_strcmp(l, "-v"))
		return (2);
	if (!ft_strcmp(l, "-c"))
		return (3);
	return (0);
}

void	ft_select_function(t_stacks *s, char *str, int p_flag)
{
	if (ft_strcmp(str, "sa") == 0)
		ft_swap_a(s, 0, p_flag);
	else if (ft_strcmp(str, "sb") == 0)
		ft_swap_b(s, 0, p_flag);
	else if (ft_strcmp(str, "ss") == 0)
		ft_swap_ab(s, 0, p_flag);
	else if (ft_strcmp(str, "pa") == 0)
		ft_push_a(s, 0, p_flag);
	else if (ft_strcmp(str, "pb") == 0)
		ft_push_b(s, 0, p_flag);
	else if (ft_strcmp(str, "ra") == 0)
		ft_rotate_a(s, 0, p_flag);
	else if (ft_strcmp(str, "rb") == 0)
		ft_rotate_b(s, 0, p_flag);
	else if (ft_strcmp(str, "rr") == 0)
		ft_rotate_ab(s, 0, p_flag);
	else if (ft_strcmp(str, "rra") == 0)
		ft_rr_a(s, 0, p_flag);
	else if (ft_strcmp(str, "rrb") == 0)
		ft_rr_b(s, 0, p_flag);
	else if (ft_strcmp(str, "rrr") == 0)
		ft_rr_ab(s, 0, p_flag);
}

int		ft_is_dup(t_stacks *s)
{
	int i;
	int j;

	i = 0;
	while (i < s->size - 1)
	{
		j = i + 1;
		while (j < s->size)
		{
			if (s->stack_a[i] == s->stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_print_arr(t_stacks *s, int x, int y)
{
	int i;
	int j;

	start_color();
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	i = s->len_a - 1;
	j = 0;
	mvprintw(y + j, x, "TOP OF A\n");
	mvprintw(y + j + 1, x, "---\n");
	mvprintw(y + j++, x + 20, "TOP OF B\n");
	mvprintw(y + j++, x + 20, "---\n");
	while (i >= 0)
	{
		attron(COLOR_PAIR(2));
		mvprintw(y + j++, x, "%d\n", s->stack_a[i--]);
	}
	i = s->len_b - 1;
	j = 2;
	while (i >= 0)
		mvprintw(y + j++, x + 20, "%d\n", s->stack_b[i--]);
}

void	print_win(t_stacks *s, int flag, int p_flag)
{
	newterm(NULL, stderr, stdin);
	curs_set(0);
	if (p_flag == 1)
		ft_print_arr(s, 0, 0);
	else if (p_flag == 2)
		ft_viz_cool(s, 0, 0);
	refresh();
	if (flag == 0)
		usleep(5000000 / (s->size));
	else
		usleep(5000000 / (s->size));
	clear();
	endwin();
}
