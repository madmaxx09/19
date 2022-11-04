char    *ft_strlcat(char *source, char *destination)
{
    int i;
    int j;

    i = 0;
    while (source[i])
    {
        i++;
    }
    while (destination[j])
    {
        source[i] = destination[j];
        i++;
        j++;
    }
    return (source);
}