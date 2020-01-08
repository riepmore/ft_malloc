/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:14:39 by pmore             #+#    #+#             */
/*   Updated: 2019/04/04 18:14:40 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>

char	*ft_strdupc(char *src, char c)
{
	int		i;
	int		len;
	char	*ret;

	i = -1;
	len = 0;
	if (src == 0 || src[0] == 0)
		return (0);
	while (src[++i] != '\0' && src[i] != c)
		len++;
	ret = malloc((sizeof(char) * len) + 1);
	if (ret == 0)
		return (0);
	i = -1;
	while (src[++i] != '\0' && src[i] != c)
		ret[i] = src[i];
	ret[i] = '\0';
	return (ret);
}

char	*ft_concat_str(char *src, char *to_add, int size1, int size2)
{
	char		*ret;
	int			i;
	int			j;

	i = -1;
	j = -1;
	if (to_add == 0)
		return (0);
	else if (src == 0)
	{
		if ((ret = malloc((sizeof(char) * size2) + 1)) == 0)
			return (0);
		while (++i < size2)
			ret[i] = to_add[i];
		ret[i] = '\0';
		return (ret);
	}
	if ((ret = malloc((sizeof(char) * (size1 + size2)) + 1)) == 0)
		return (0);
	while (++i < size1)
		ret[i] = src[i];
	while (++j < size2)
		ret[i++] = to_add[j];
	ret[i] = '\0';
	return (ret);
}

int		gnl_buffer_not_empty(char **line, char buffer[])
{
	int		i;
	char	*tmp;
	char	*ptr;
	int		len;

	i = -1;
	tmp = 0;
	ptr = 0;
	len = 0;
	ptr = ft_strchr(buffer, '\n');
	if (ptr != 0)
	{
			tmp = ft_strdupc(buffer, '\n'); // met dans tmp le contenu de buffer jusquau \n
			ptr++;
			len = ft_strlen(ptr);
			while (++i < len)
				buffer[i] = ptr[i]; // // génie ?
			buffer[i] = '\0';
			*line = tmp;
			return (1);
	}
	return (0);
}

int		gnl_last_line(char **line, char *tmp, char buffer[])
{
	if (tmp != 0) // for the last line.
	{
		*line = tmp;
		ft_bzero(buffer, BUFF_SIZE);
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		buffer[BUFF_SIZE + 1] = { 0 }; // buffer
	t_gnl	gnl;

	gnl.rd = 0;
	gnl.new_line = 0;
	gnl.gnl_ret = 0;
	gnl.tmp = 0;
	// check si BUFF_SIZE a une taille correcte
	if (line == 0 || BUFF_SIZE < 1 || BUFF_SIZE > 65535) // voir UINT_MAX
		return (-1);
	if (buffer[0] != 0 && gnl_buffer_not_empty(line, buffer) == 1) // si le buffer contient des choses
			return (1);
	gnl.tmp = ft_strdupc(buffer, '\0'); // duplicate buffer dans tmp si encore a read
	ft_bzero(buffer, BUFF_SIZE);
	if (((gnl.rd = read(fd, buffer, BUFF_SIZE))) == -1) // read
		return (-1);
	else if (gnl.rd == 0)
		return (gnl_last_line(line, gnl.tmp, buffer));
	gnl.gnl_ret = get_next_line(fd, line); // relance GNL avec ce qui a ete lu
	gnl.new_line = ft_concat_str(gnl.tmp, *line, ft_strlen(gnl.tmp), ft_strlen(*line)); // concatene tmp et ce qui a ete mit dans line
	free(*line); // libere ce qui a ete alloc en relancant gnl
	free(gnl.tmp);
	*line = gnl.new_line;
	return (gnl.gnl_ret);
}
