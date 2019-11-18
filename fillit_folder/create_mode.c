/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:27:40 by vkuokka           #+#    #+#             */
/*   Updated: 2019/11/15 11:15:55 by gmolin           ###   ########.fr       */
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

/*
static void			ft_printlst(t_list **alst) // DELETE AFTER!!!!!!!!!!!!!
{
	t_list			*cur_list;

	cur_list = *alst;
	while (cur_list)
	{
		ft_putstr(cur_list->content);
		cur_list = cur_list->next;
		//ft_putchar('\n');
	}
	return ;
}
*/

static char *position_swap(char *s)
{
	size_t i;
	size_t begin;
	size_t j;
	size_t row;

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
			continue;
		}
		if (j > 20 || i > 20)
			break;
		s[i] = s[j];
		s[j] = '.';
		i++;
		j++;
	}
	return (s);
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
	position_swap(s);
	if (!lstbegin)
		lstbegin = ft_lstnew(s, ft_strlen(s) + 1);
	else
		ft_lstaddback(&lstbegin, ft_lstnew(s, ft_strlen(s) + 1));
	ft_strdel(&s);
	return (lstbegin);
}


static char				*purify(char *adjusted, size_t total)
{
	char		*pure;
	size_t 		i;
	size_t		j;

	i = 0;
	j = 0;
	pure = (char*)malloc(sizeof(char) * total + 1);
	while (adjusted[i])
	{
		if (adjusted[i] == '\n' && adjusted[i + 1] == '\n')
			i++;
		pure[j] = adjusted[i];
		i++;
		j++; 
	}
	ft_strdel(&adjusted);
	adjusted = NULL;
	pure[j] = '\0';
	//printf("LEN OF PURE: %zu\n", ft_strlen(pure));
	return (pure);
}


static char 			*re_adjust(char *tblock, size_t len)
{
	char		*adjusted;
	size_t		i;
	size_t		j;
	size_t		c;

	i = 0;
	j = 0;
	c = 0;
	//printf("%zu\n", len);
	adjusted = ft_strnew((len + 1) * len); //(char *)malloc(sizeof(char) * ((len + 1) * len) + 1);  //If we use here strnew and fill it with NULL terminators, we can skipp the second while loop
	//printf("THIS IS TBLOCK BEFORE: \n%s", tblock);
	while (tblock[j])
	{
		//printf("LOOKING FOR SEG FAULT!!\n");
		while (tblock[j] == '\n' && c++ < (len - ft_strclen(tblock, '\n')))
		{
			//printf("THIS IS C%zu\n", c);
			adjusted[i++] = '.';
			//c++;
			//printf("ADJUSTED IN C LOOP: \n%s\n", adjusted);
		}
		c = 0;
		//printf("ADJUSTED IN LOOP: \n%s\n", adjusted);
		(i % (len + 1) == 0) ? adjusted[i] = '\n' : 0;
		adjusted[i++] = tblock[j++];
	}
	//printf("ADJUSTED: \n%s", adjusted);
	//Without it makes it much faster, but perhaps it is not as safe. See comment above.
	/*
	while (i < (((len + 1) * len) + 1))
	{	
		adjusted[i] = '.';
		(i % (len + 1) == 0 && i != 0) ? adjusted[i] = '\n' : 0;
		i++;
	}
	*/
	adjusted[i] = '\0';
	//printf("LEN OF ADJUSTED: %zu\n", ft_strlen(adjusted));
	//printf("TOTAL SIZE: %zu\n", (len + 1) * len);
	return (adjusted = purify(adjusted, ((len + 1) * len)));
	//return (adjusted);
}

static void		increase_block(t_list **alst, size_t len)
{
	t_list			*cur_list;
	char			*tmp;

	cur_list = *alst;
	tmp = NULL;
	while (cur_list)
	{
		tmp = cur_list->content;
		//printf("THIS IS LEN %zu\n", len);
		cur_list->content = re_adjust(cur_list->content, len);
		//printf("AFTER INCREASE:\n%s", cur_list->content);
		ft_strdel(&tmp);
		cur_list = cur_list->next;
	}
}

int					create_mode(char *file)
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
			ft_putchar('\n');
			return (-1);
		}
		file[i] ? i++ : 0;
	}
	//ft_printlst(&lst);
	begin = ft_lstlen(&lst);
	while(!(solve_mode(board_mode(begin), lst, 0, board_mode(begin))))
	{
		begin++;
		if (begin > 3)
			increase_block(&lst, board_size(begin));
	}
	return (1); //if file is valid
}
