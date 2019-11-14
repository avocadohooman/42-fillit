/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:27:40 by vkuokka           #+#    #+#             */
/*   Updated: 2019/11/14 13:16:21 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> // remove

static int			verify_block(char *s)
{
	int				i;
	int				count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			while (s[i] == '#')
			{
				(s[i + 1] == '#') ? count++ : 0;
				(s[i - 1] == '#') ? count++ : 0;
				(s[i + 5] == '#') ? count++ : 0;
				(s[i - 5] == '#') ? count++ : 0;
				break ;
			}
			if (count == 0)
				return (0);
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

static void			ft_printlst(t_list **alst) // DELETE AFTER!!!!!!!!!!!!!
{
	t_list			*cur_list;

	cur_list = *alst;
	while (cur_list)
	{
		ft_putstr(cur_list->content);
		cur_list = cur_list->next;
		ft_putchar('\n');
	}
	return ;
}

static t_list		*add_block(char *s)
{
	static t_list	*lstbegin;
	static int		letter;
	size_t			i;

	if (!verify_block(s) || letter > 26)
	{
		ft_lstdel(&lstbegin, &ft_del);
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
			s[i] = s[i] + 30 + letter;
		i++;
	}
	letter++;
	if (!lstbegin)
		lstbegin = ft_lstnew(s, ft_strlen(s) + 1);
	else
		ft_lstaddback(&lstbegin, ft_lstnew(s, ft_strlen(s) + 1));
	ft_strdel(&s);
	return (lstbegin);
}

int					create_mode(char *file)
{
	size_t			i;
	size_t			begin;
	unsigned int	ascii;
	char			*board;
	t_list			*lst;

	i = 0;
	ascii = 0;
	while (file[i])
	{
		begin = i;
		while ((file[i] != '\n' || file[i - 1] != '\n') && file[i])
		{
			if (file[i] != '#' && file[i] != '.' && file[i] != '\n')
			{
				ft_putstr("Invalid style");
				return (-1);
			}
			ascii = ascii + file[i];
			i++;
		}
		if (ascii % 732 != 0 || (i - begin) != 20)
		{
			ft_putstr("Invalid File");
			return (-1); //if file is invalid
		}
		if (!(lst = add_block(ft_strsub(file, begin, i - begin))))
		{
			ft_putstr("Invalid block");
			return (-1);
		}
		file[i] ? i++ : 0;
	}
	ft_printlst(&lst);
	board = board_mode(ft_lstlen(&lst));
	solve_mode(board, lst, 1, board_mode(ft_lstlen(&lst)));
	return (1); //if file is valid
}
