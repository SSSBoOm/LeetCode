int reverse(int x){
    short int prefix = 1;
    if(x < 0) {
        if(x == -2147483648){
            return 0;
        }
        prefix = -1;
        x *= -1;
    }
    long output = 0;
    while(x > 0) {
        if((10 * output) >= 2147483647l){
            return 0;
        }
        output = (output * 10) + (x % 10);
        x /= 10;
    }

    return prefix * output;
}