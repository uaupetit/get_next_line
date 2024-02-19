/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:27:35 by uaupetit          #+#    #+#             */
/*   Updated: 2022/12/09 12:16:04 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strlen2(char *s);
char	*ft_line(char *stash);
char	*get_next_line(int fd);
char	*ft_delline(char *stash, int resread);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strchr2(char *s, int c);

#endif
