int ft_toupper(int digit)
{
    if (digit >= 97 && digit <= 122)
    {
        digit -= 32;
        return (digit);
    }
    else 
        return (digit);
}