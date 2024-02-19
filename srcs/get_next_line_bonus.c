/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:26:05 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 15:05:18 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	int			resread;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	resread = 1;
	while (!(ft_strchr2(stash[fd], '\n')) && (resread != 0))
	{
		resread = read(fd, buffer, BUFFER_SIZE);
		if (resread == -1 && !stash[fd])
		{
			free (buffer);
			return (NULL);
		}
		buffer[resread] = '\0';
		stash[fd] = ft_strjoin2(stash[fd], buffer);
	}
	free(buffer);
	buffer = ft_line(stash[fd]);
	stash[fd] = ft_delline(stash[fd], resread);
	return (buffer);
}

int	main()
{
	int	fd;
	int	fd2;
	int	i;
	char	*res;
	char	*res2;
	char *file_path = "/mnt/nfs/homes/uaupetit/Documents/projetsgit/get_next_line/GNLtest.txt";
	
	i = 0;
	fd = open(file_path, O_RDONLY);
	fd2 = open("/mnt/nfs/homes/uaupetit/Documents/projetsgit/get_next_line/test/GNLtest2.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	if (fd > -1)
	{
		while (i <= 30)
		{
			res = get_next_line(fd);
			res2 = get_next_line(fd2);
			printf("%s%s", res, res2);
			free(res);
			i++;
		}
		close(fd);
	}
	else
		 perror("Erreur lors de l'ouverture du fichier");
}