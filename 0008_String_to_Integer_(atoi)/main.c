int myAtoi(char *s){
    if(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')) {
        long int output = 0, prefix = 1;
        if(*s == '+') {
            s++;
        }
        else if(*s == '-') {
            prefix = -1;
            s++;
        }
    
        for(char *p = s; *p >= '0' && *p <= '9'; p++) {
            if(output > INT_MAX || output < INT_MIN) {
                break;
            }
            output = (output * 10) + (int)(*p - '0');
        }
        return (output > INT_MAX) ? (prefix == 1) ? (INT_MAX) : (INT_MIN) : (output * prefix);
    }
    else if(*s == ' ')
        return myAtoi(s+1);
    else
        return 0;
}