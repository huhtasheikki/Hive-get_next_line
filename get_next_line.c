/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:23:12 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/11/06 17:14:10 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h> // poista valmiista, openin kirjasto

char	*ft_realloc(char *str, size_t size)
{
	char		*str2;
	size_t		len;

	len = ft_strlen(str);
	if (!(str2 = ft_memalloc(size)))
		return (NULL);
	ft_strncpy(str2, str, len);
	return (str2);
}

int		get_next_line(const int fd, char **line)
{
	char		*str;
	char		*str2;
	size_t		size;
	size_t		i;

	size = 0;
	if (!(str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while (read(fd, str[i], 1) && str[i] != '\n')
	{
		i++;
		size++;
		if (size == BUFF_SIZE)
		{
			str[size] = '\0';
			size++;
			str2 = ft_realloc(str, size + ft_strlen(str2));
			str2 = ft_strncat(str2, str, size + ft_strlen(str2));
			size = 0;
		}
		str[size] = '\0';
	}
	return (fd);
}

int		main(int argc, char **argv)
{
	int			fd;
	int			ret;
	char		*str;

	argc = 0;

	fd = open(argv[1], O_RDONLY);
	str = &fd;
	while (ret = get_next_line(fd, &str))
	{
		ft_putendl(ret);
	}
	return (0);
}
