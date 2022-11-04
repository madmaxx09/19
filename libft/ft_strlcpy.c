char* strcpy(char* destination, char* source)
{
    int i;

    i = 0; 
    while (source[i])
    {
        destination[i] = source[i];
        i++;
    }
    return (destination);
} 