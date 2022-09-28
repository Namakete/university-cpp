namespace math
{
    double pow(double base, int exponent){
        double result = 1;

        if(exponent > 0)
            for (int i = 0; i < exponent; i++)
                result *= base;

        for (int i = 0; i > exponent; i--)
            result /= base;

        return result;
    }
}
