/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:19:40 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 13:29:56 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	i = 0;
	j = 0;
	if (!s1)
	{	
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * ft_strlen2(s1) + ft_strlen2(s2) + 1);
	if (!s3)
		return (NULL);
	while (s1[j])
		s3[i++] = s1[j++];
	j = 0;
	free(s1);
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

char	*ft_strchr2(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c > 127)
		return (s);
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (s[i] == c)
		return (&s[i]);
	return (NULL);
}

int	ft_strlen2(char	*s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_line(char *stash)
{
	int		i;
	char	*res;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	res = malloc (sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		res[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*ft_delline(char *stash, int resread)
{
	int		i;
	int		j;
	char	*stash2;

	i = 0;
	j = 0;
	if (resread == 0)
	{
		free(stash);
		return (NULL);
	}
	while (stash[i] && stash[i] != '\n')
		i++;
	stash2 = malloc(sizeof(char) * ft_strlen2(stash) - i + 1);
	if (!stash2)
		return (NULL);
	i++;
	while (stash[i])
		stash2[j++] = stash[i++];
	free (stash);
	stash2[j] = '\0';
	return (stash2);
}
