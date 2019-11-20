/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:33:33 by vkuokka           #+#    #+#             */
/*   Updated: 2019/11/20 17:03:18 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*read_file(int fd)
{
	char		rline[BUFF_SIZE + 1];
	char		*file;
	char		*tmp;
	int			count;

	if (!(file = ft_strnew(0)))
		return (NULL);
	while ((count = read(fd, rline, BUFF_SIZE)) > 0)
	{
		rline[count] = '\0';
		tmp = file;
		file = ft_strjoin(file, rline);
		free(tmp);
	}
	if (count < 0)
		return (NULL);
	return (file);
}

int				main(int argc, char **argv)
{
	int			fd;
	char		*file;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(file = read_file(fd)) || !create_mode(file))
			ft_putendl("error");
		ft_strdel(&file);
		close(fd);
	}
	else
		ft_putendl("usage: ./fillit [] source_file");
	return (0);
}
