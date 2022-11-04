char*   strchr(char* str, int ch)
{
   int i;

   i = -1; 
   while (str[++i])
   { 
        if (str[i] == ch)
            return (str[i]);
    }
    return (*str);
}