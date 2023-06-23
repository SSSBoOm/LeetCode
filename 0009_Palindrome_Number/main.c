bool isPalindrome(long int x){
    if(x < 0) {
        return false;
    }
    else if(x == 0) {
        return true;
    }

    long int rev_x = 0, temp = x;
    for(int i = 0; temp > 0; i++) {
        rev_x = (rev_x * 10) + (temp % 10);
        temp /= 10;
    }

    if(x == rev_x) {
        return true;
    }
    return false;
}