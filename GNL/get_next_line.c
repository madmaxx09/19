/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:13:17 by mdor              #+#    #+#             */
/*   Updated: 2023/01/24 21:52:23 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

/* Projet consiste a lire un fd ligne par ligne, le fichier pouvant être lu en entier en rappelant plusieurs fois 
get next line get next line prend pour arg fd. J'ai droit aux fonctions read, malloc et free. 
Read se comporte en gardant en buffer ce qu'elle a lu. 
L'idée générale est donc:
	- de stocker ce que read lit
	- regarder dans le stock si il y a un retour à la ligne 
	- si oui renvoyer la ligne et vider le stock de celle-ci 
	- recommencer jusqu'à ce que read renvoie 0 ce qui voudra dire qu'elle n'a plus rien à lire
	- On utilise un static char pour le stock afin de garder sa valeur entre les différentes itérations de GNL
	- Le buffer size (le nombre de byte que va lire read) est donné en argument
*/

char	*ft_getline(char *stock)
{
	int		i;
	char	*line;

	i = 0;
	if (!stock[i])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] && stock[i] == '\n')
		line[i++] = '\n';
	return (line);
}

//rajoute le contenu du buffer dans notre variable statique
char	*ft_append(char *stock, char *buff)
{
	char	*stash;

	stash = ft_strjoin(stock, buff);
	free(stock);
	return (stash);
}

//delete la ligne déjà renvoyée par GNL de notre static Char et renvoie ce qu'il reste
char	*ft_clean(char	*stock)
{
	int		j;
	int		i;
	char	*delete;

	j = 0;
	i = 0;
	while (stock[j] && stock[j] != '\n')
		j++;
	if (!stock[j])
	{
		free(stock);
		return (NULL);
	}
	delete = ft_calloc((ft_strlen(stock) - j + 1), sizeof(char));
	j++;
	while (stock[j])
		delete[i++] = stock[j++];
	free(stock);
	return (delete);
}

char	*ft_read(int fd, char *stock)
{
	char	*buff;
	int		readcheck;

	if (!stock)
		stock = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	readcheck = 1999;
	while (readcheck > 0)
	{
		readcheck = read(fd, buff, BUFFER_SIZE);
		if (readcheck == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readcheck] = 0;
		stock = ft_append(stock, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stock = ft_read(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_getline(stock);
	stock = ft_clean(stock);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}