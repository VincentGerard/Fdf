/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:34:36 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/20 15:22:07 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Returns the duplicates the first part of the buffer
char	*ft_get_buff_start(char *buff)
{
	int		i;
	char	*res;

	i = 0;
	if (buff == NULL || buff[0] == '\0')
		return (NULL);
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	res = (char *)malloc(i + 2);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		res[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

//Return the dupicate of the end of buff and free's buff
char	*ft_get_buff_end(char *str)
{
	int		i;
	int		j;
	char	*ptr;

	j = 0;
	i = ft_strlen(str);
	if (!str)
		return (NULL);
	while (str[j] != '\n' && str[j])
		j++;
	if (str[j] == '\0')
	{
		free(str);
		return (NULL);
	}
	ptr = malloc(sizeof(char) * (i - j));
	if (!ptr)
		return (NULL);
	i = 0;
	j++;
	while (str[j])
		ptr[i++] = str[j++];
	ptr[i] = '\0';
	free(str);
	return (ptr);
}

int	ft_is_char_in_str(char *buff, char character)
{
	if (buff == NULL)
		return (0);
	while (*buff != '\0')
	{
		if (*buff == character)
			return (1);
		buff++;
	}
	return (0);
}

//Read jusqu'au '\n'
char	*ft_read_line(int fd, char *buff, char *temp, char *temp2)
{
	int		read_size;

	read_size = 1;
	while (read_size != 0)
	{
		read_size = read(fd, temp, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[read_size] = '\0';
		temp2 = buff;
		if (temp2 == NULL)
		{
			if (ft_alloc_temp(&temp2))
				return (NULL);
		}
		buff = ft_strjoin_gnl(temp2, temp);
		free(temp2);
		if (ft_is_char_in_str(buff, '\n'))
			break ;
	}
	free(temp);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*temp;
	char		*temp2;
	char		*res;

	temp2 = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (temp == NULL)
		return (NULL);
	buff = ft_read_line(fd, buff, temp, temp2);
	if (buff == NULL)
		return (NULL);
	res = ft_get_buff_start(buff);
	buff = ft_get_buff_end(buff);
	return (res);
}
