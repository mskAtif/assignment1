#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Time complexity O(n) 
// Space complexity O(string length)
char* findSum(const char* str, const char* strs) {
    int n1 = strlen(str);
    int n2 = strlen(strs);
    
    
    int maxLength = (n1 > n2) ? n1 : n2;

    char* final = (char*)malloc((maxLength + 2) * sizeof(char));
    final[maxLength + 1] = '\0'; 
    
    int carry = 0;
    int i = n1 - 1, j = n2 - 1, k = maxLength;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0)
            sum += str[i--] - '0';
        if (j >= 0)
            sum += strs[j--] - '0';
        
        carry = sum / 10;
        final[k--] = (sum % 10) + '0';
    }

    char* finalresult = final + k + 1;
    
   
    return finalresult;
}

int main() {
    char* string1;
    char* string2;
    char x[1000],y[1000];
    printf("enter first number: ");
    scanf("%s",x);
    printf("enter second number: ");
    scanf("%s",y);
    string1=x,string2=y;
    char* final = findSum(string1, string2);
    
    printf("Sum: %s\n", final);
    
    free(final);
    
    return 0;
}
