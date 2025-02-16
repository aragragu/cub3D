/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_libe_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:00:58 by aragragu          #+#    #+#             */
/*   Updated: 2025/02/16 16:06:45 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d_bonus.h"

char	*ft_substr2(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	len = ft_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (char) c)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*p;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	p = (char *)ft_malloc(len + 1, ALLOC);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strdup2(char *s1)
{
	int		len;
	char	*p;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
