/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:11:15 by gmolin            #+#    #+#             */
/*   Updated: 2019/11/14 11:47:45 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft_folder/includes/libft.h"
# define BUFF_SIZE 1

int			create_mode(char *file);
void		ft_putlst(t_list **alst); //delete after!
char		*board_mode(size_t len);
int			solve_mode(char *board, t_list *lst, size_t start, char *backup);
int			slap(char *board, char *tblock, size_t start);

 #endif