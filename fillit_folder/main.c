/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:33:33 by vkuokka           #+#    #+#             */
/*   Updated: 2019/11/14 11:56:04 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

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
	{
		ft_putstr("Reading Error");
		return (0);
	}
	return (file);
}

int				main(int argc, char **argv)
{
	int			fd;
	char		*file;

	if (argc == 1)
	{
		ft_putstr("usage: fillit [] source_file");
		return (0);
	}
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(file = read_file(fd)))
			return (-1);
		close(fd);
		if (!create_mode(file))
		 	return (-1);
	}
	else
	{
		ft_putstr("Too many arguments");
		return (-1);
	}
	return (0);
}
