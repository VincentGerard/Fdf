/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerard <vgerard@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:40:11 by vgerard           #+#    #+#             */
/*   Updated: 2022/01/11 10:50:32 by vgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_res(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (res[i] != NULL)
			free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

int	ft_nbr_words(const char *str, char separator)
{
	int	nbr;
	int	i;
	int	lenght;

	lenght = ft_strlen(str);
	i = 0;
	nbr = 0;
	if (str == NULL)
		return (0);
	while (i < lenght)
	{
		if (str[i] != separator && (i + 1) <= lenght
			&& (str[i + 1] == separator || str[i + 1] == '\0'))
			nbr++;
		i++;
	}
	return (nbr);
}

char	*ft_get_word(char *str, char separator, int n)
{
	int		i;
	int		j;
	int		nbr;

	nbr = 0;
	i = -1;
	while (i++ < (int)ft_strlen(str))
	{
		if (str[i] != separator && str[i] != '\0' && nbr == n)
		{
			j = 0;
			while (str[i + j] != separator && str[i + j] != '\0')
			{
				j++;
			}
			return (ft_substr(str, i, j));
		}
		if (str[i] != separator && (i + 1) <= (int)ft_strlen(str)
			&& (str[i + 1] == separator || str[i + 1] == '\0'))
			nbr++;
	}
	return (NULL);
}

char	**ft_split(char const *str, char separator)
{
	char	**res;
	int		nbr_words;
	int		i;
	char	*temp_word;

	i = 0;
	if (str == NULL)
		return (0);
	nbr_words = ft_nbr_words(str, separator);
	res = (char **)malloc(sizeof(char *) * nbr_words + 1);
	if (res == NULL)
		return (NULL);
	res[nbr_words] = NULL;
	while (i < nbr_words)
	{
		temp_word = ft_get_word((char *)str, separator, i);
		if (temp_word == NULL)
			return (ft_free_res(res));
		res[i] = temp_word;
		i++;
	}
	return (res);
}
