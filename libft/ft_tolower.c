int ft_tolower(int digit)
{
    if (digit >= 65 && digit <= 90)
    {
        digit += 32;
        return (digit);
    }
    else
        return (digit);
}