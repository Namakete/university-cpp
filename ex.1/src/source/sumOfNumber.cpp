namespace math {
    int sumOfNumber(int number){
        if(number != 0)
            return ((number % 10) + sumOfNumber(number / 10));
        
        return 0;
    }
}
