bool isValid(char *s){
    int size = sizeof(s) / sizeof(s[0]);
    int stackIndex = -1;
    // char *rev_Paren = calloc(10001, sizeof(char));
    char rev_Paren[strlen(s)];

    for(int i = 0; *s != '\0'; i++, s++) {
        if(*s == '(' || *s == '{' || *s == '[') {
            rev_Paren[stackIndex == -1 ? 0 : stackIndex + 1] = *s;
            stackIndex++;
        }
        else {
            if(stackIndex == -1) {
                return false;
            }
            else if((rev_Paren[stackIndex] == '(' && *s == ')') || (rev_Paren[stackIndex] == '{' && *s == '}') || rev_Paren[stackIndex] == '[' && *s == ']') {
                stackIndex -= 1;
            }
            else {
                return false;
            }
        }
    }
    if(stackIndex != -1) {
        return false;
    }
    return true;
}