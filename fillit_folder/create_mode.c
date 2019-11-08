/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:27:40 by vkuokka           #+#    #+#             */
/*   Updated: 2019/11/08 15:21:40 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			verify_block(char *s)
{
	int i;
	int count;

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
	t_list *cur_list;

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
	static t_list *lstbegin;

	if (!verify_block(s))
	{
		ft_lstdel(&lstbegin, &ft_del);
		return (NULL);
	}
	if (!lstbegin)
	{
		if (!(lstbegin = ft_lstnew(s, ft_strlen(s) + 1)))
			return (NULL);
		ft_strdel(&s);
		return (lstbegin);
	}
	ft_lstaddback(&lstbegin, ft_lstnew(s, ft_strlen(s) + 1));
	ft_strdel(&s);
	return (lstbegin);
}

int			create_mode(char *file)
{
	size_t			i;
	size_t			begin;
	unsigned int	ascii;
	t_list			*lst;
	
	i = 0;
	ascii = 0;
	while (file[i])
	{
		begin = i;
		while ((file[i] != '\n' || file[i - 1] != '\n') && file[i])
		{
			ascii = ascii + file[i];
			i++;
		}
		ft_putnbr(i - begin);
		ft_putchar('\n');
		ft_putnbr(ascii);
		ft_putchar('\n');
		if (ascii % 732 != 0 || ((i - begin) != 20))
		{
			ft_putstr("Invalid File");
			return (-1); //if file is invalid
		}
		if (!(lst = add_block(ft_strsub(file, begin, i - begin))))
		{
			ft_putstr("Invalid block");
			return (-1);
		}
		if (file[i])
			i++;
	}
	ft_printlst(&lst);
	return (1); //if file is valid
	return (-1); //if file is invalid
}
