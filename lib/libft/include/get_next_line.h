/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:34:37 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/20 12:09:14 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdlib.h"
# include "unistd.h"
# include "libft.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

char	*ft_get_buff_start(char *buff);
char	*ft_get_buff_end(char *buff);
int		ft_is_char_in_str(char *buff, char character);
char	*ft_read_line(int fd, char *buff, char *temp, char *temp2);
char	*get_next_line(int fd);

char	*ft_strjoin_gnl(char *str1, char *str2);
int		ft_alloc_temp(char **temp);

#endif