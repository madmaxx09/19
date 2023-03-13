#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

char	*ft_strjoin(char *stock, char *buff)
{
	char	*new;
	int		i;
	int		j; 

	i = -1;
	j = 0;
	if (!stock)
	{
		stock = (char *)malloc(sizeof(char) * 1);
		stock[0] = '\0';
	}
	if(!stock || !buff)
		return (NULL);
	new = malloc((ft_strlen(stock) + ft_strlen(buff) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	if(stock)
		while (stock[++i] != '\0')
			new[i] = stock[i];
	while (buff[j] != '\0')
		new[i++] = buff[j++];
	new[ft_strlen(stock) + ft_strlen(buff)] ='\0';
	free(stock);
	return(new);	
}

char	*ft_read(int fd, char *stock)
{
	int		readcheck;
	char	*buff;
	
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return(NULL);
	readcheck = 1;
	while (!ft_strchr(stock, '\n') && readcheck != 0)
	{
		readcheck = read(fd, buff, BUFFER_SIZE);
		if (readcheck == -1)
		{
			free(buff);
			return(NULL);
		}
		buff[readcheck] = '\0';
		stock = ft_strjoin(stock, buff);
	}
	free(buff);
	return (stock);
}

char	*ft_getline(char *stock)
{
	char	*line;
	int		i;

	i = 0;
	if(!stock)
		return(NULL);
	while(stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) *sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while(stock[i] && stock[i] != '\n')
	{
		line[i] = stock[i]; 
		i++;
	}
	if(stock[i] == '\n')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clean(char *stock)
{
	char	*cleaned;
	int		i;
	int		j;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if(!stock[i])
	{
		free(stock);
		return (NULL);
	}
	cleaned = (char *)malloc((ft_strlen(stock) - i + 1) * sizeof(char));
	if(!cleaned)
		return(NULL);
	i++;
	j = 0;
	while(stock[i])
		cleaned[j++] = stock[i++]; 
	cleaned[j] = '\0';
	free(stock);
	return(cleaned);	
}
char	*get_next_line(int fd)
{
	static char	*stock[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	stock[fd] = ft_read(fd, stock[fd]);
	if(!stock[fd])
		return(NULL);
	line = ft_getline(stock[fd]);
	stock[fd] = ft_clean(stock[fd]);
	return(line);
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
