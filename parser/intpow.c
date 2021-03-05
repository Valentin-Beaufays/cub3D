int intpow(int x, int y)
{
    int res;
    
    res = 1;
    if (x < 0 || y < 0)
     return (0);
    if (y >= 1)
        res = x; 
    if (y > 1)
    {
        y--;
        while (y > 0)
        {
         res = res * x;
         y--;
        }
    }
    return (res);
}