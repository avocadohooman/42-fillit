/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readjust_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:03:44 by gmolin            #+#    #+#             */
/*   Updated: 2019/11/19 13:26:33 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			*purify(char *adjusted, size_t total)
{
	char			*pure;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	pure = ft_strnew(total);
	while (adjusted[i])
	{
		if (adjusted[i] == '\n' && adjusted[i + 1] == '\n')
			i++;
		pure[j] = adjusted[i];
		i++;
		j++;
	}
	ft_strdel(&adjusted);
	pure[j] = '\0';
	return (pure);
}

static char			*upsize(char *tblock, size_t len)
{
	char			*adjusted;
	size_t			i;
	size_t			j;
	size_t			c;

	i = 0;
	j = 0;
	c = 0;
	adjusted = ft_strnew((len + 1) * len);
	while (tblock[j])
	{
		while (tblock[j] == '\n' && c++ < (len - ft_strclen(tblock, '\n')))
		{
			adjusted[i++] = '.';
		}
		c = 0;
		(i % (len + 1) == 0) ? adjusted[i] = '\n' : 0;
		adjusted[i++] = tblock[j++];
	}
	adjusted[i] = '\0';
	return (adjusted = purify(adjusted, ((len + 1) * len)));
}

void				increase_block(t_list **alst, size_t len)
{
	t_list			*cur_list;
	char			*tmp;

	cur_list = *alst;
	tmp = NULL;
	while (cur_list)
	{
		tmp = cur_list->content;
		cur_list->content = upsize(cur_list->content, len);
		ft_strdel(&tmp);
		cur_list = cur_list->next;
	}
}
