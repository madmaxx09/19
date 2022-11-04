int ft_isalnum(int digit)
{
    if (digit >= 48 && digit <= 57)
        return (1);
    if (digit >= 65 && digit <= 90)
        return (1);
    if (digit >= 97 && digit <= 122)
        return (1);
    else
        return (0);   
}