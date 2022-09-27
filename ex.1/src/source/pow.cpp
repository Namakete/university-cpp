namespace math
{
    double multiply(double x, int y)
    {
        return (y ? x + multiply(x, y - 1) : 0);
    }

    double pow(double base, int exponent)
    {
        return (exponent ? multiply(base, pow(base, exponent - 1)) : 1);
    }
}
