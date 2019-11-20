/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:27:40 by vkuokka           #+#    #+#             */
/*   Updated: 2019/11/19 13:38:15 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
				(s[i + 1] == '#' && i + 1 <= 19) ? count++ : 0;
				(s[i - 1] == '#' && i - 1 >= 0) ? count++ : 0;
				(s[i + 5] == '#' && i + 5 <= 19) ? count++ : 0;
				(s[i - 5] == '#' && i - 5 >= 0) ? count++ : 0;
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

static char			*position_swap(char *s)
{
	size_t			i;
	size_t			begin;
	size_t			j;
	size_t			row;

	i = 0;
	row = 0;
	begin = start(s);
	j = begin;
	while (s[j] && s[i] && begin != 0)
	{
		if (s[j] == '\n')
		{
			j = begin + 5;
			begin = begin + 5;
			row++;
			i = row * 5;
			continue ;
		}
		if (j > 20 || i > 20)
			break ;
		s[i++] = s[j];
		s[j++] = '.';
	}
	return (s);
}

static t_list		*add_block(char *s)
{
	static t_list	*lstbegin;
	static int		letter;
	size_t			i;

	if (letter > 26 || !verify_block(s))
	{
		if (letter > 26)
			ft_strdel(&s);
		else
			ft_lstdel(&lstbegin, &ft_del);
		return (NULL);
	}
	i = -1;
	while (s[++i])
		if (s[i] == '#')
			s[i] = s[i] + 30 + letter;
	letter++;
	position_swap(s);
	if (!lstbegin)
		lstbegin = ft_lstnew(s, ft_strlen(s) + 1);
	else
		ft_lstaddback(&lstbegin, ft_lstnew(s, ft_strlen(s) + 1));
	ft_strdel(&s);
	return (lstbegin);
}

static int			setup(t_list **alst)
{
	size_t			len;

	if (!(*alst)->next)
		if (ft_strequ((*alst)->content, "AA..\nAA..\n....\n....\n"))
		{
			ft_putstr("AA\nAA\n");
			return (1);
		}
	len = ft_lstlen(alst);
	while (!(solve_mode(board_mode(len), *alst, 0, board_mode(len))))
	{
		len++;
		if (len > 3)
			increase_block(alst, board_size(len));
	}
	ft_lstdel(alst, ft_del);
	return (1);
}

int					create_mode(char *file)
{
	size_t			i;
	size_t			begin;
	unsigned int	ascii;
	t_list			*lst;

	i = 0;
	ascii = 0;
	if (ft_strlen(file) < 20)
		return (0);
	while (file[i])
	{
		begin = i;
		while ((file[i] != '\n' || file[i - 1] != '\n') && file[i])
		{
			if (file[i] != '#' && file[i] != '.' && file[i] != '\n')
				return (0);
			ascii = ascii + file[i++];
		}
		if (ascii % 732 != 0 || (i - begin) != 20)
			return (0);
		if (!(lst = add_block(ft_strsub(file, begin, i - begin))))
			return (0);
		file[i] ? i++ : 0;
	}
	return (setup(&lst));
}
