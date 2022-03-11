/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutch <dutch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:21:28 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/11 22:47:11 by dutch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		buffer[BUFFER_SIZE + 1];
	int			c_read;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	if (leftover == NULL)
		leftover = malloc_leftover();
	if (ft_strchr_gnl(leftover, '\n') == -1)
	{
		c_read = read(fd, &buffer, BUFFER_SIZE);
		while (c_read > 0)
		{
			*(buffer + c_read) = '\0';
			leftover = ft_strjoin_gnl(leftover, buffer);
			if (ft_strchr_gnl(leftover, '\n') != -1)
				break ;
			c_read = read(fd, &buffer, BUFFER_SIZE);
		}
	}
	line = chop_string(&leftover);
	leftover = save_leftovers(leftover);
	return (line);
}

// Norm issues. If leftover is NULL (not malloc()-ed),
// this function creaates a malloc()-ed (kinda) NULL value
char	*malloc_leftover(void)
{
	char	*empty;

	empty = malloc(sizeof(char));
	*empty = '\0';
	return (empty);
}

char	*save_leftovers(char *leftover)
{
	char	*ret_str;
	int		chop_at;
	int		i;

	if (leftover == NULL || ft_strchr_gnl(leftover, '\0') == 0)
		return (NULL);
	chop_at = ft_strchr_gnl(leftover, '\n');
	if (chop_at < 0)
		return (NULL);
	else
	{
		ret_str = malloc(sizeof(char) * (ft_strlen(leftover) - chop_at + 1));
		i = -1;
		while (*(leftover + (++i) + chop_at + 1))
			*(ret_str + i) = *(leftover + i + chop_at + 1);
		*(ret_str + i) = '\0';
	}
	free(leftover);
	return (ret_str);
}

char	*chop_string(char **leftover)
{
	char	*return_str;
	int		chop_at;
	int		i;

	chop_at = ft_strchr_gnl(*leftover, '\n');
	if (chop_at < 0)
	{
		if (ft_strchr_gnl(*leftover, '\0') != 0)
			return (*leftover);
		free(*leftover);
		*leftover = NULL;
		return (NULL);
	}
	return_str = malloc(sizeof(char) * (chop_at + 2));
	*(return_str + chop_at + 1) = '\0';
	i = -1;
	while (++i <= chop_at)
		*(return_str + i) = *(*(leftover) + i);
	return (return_str);
}
