#include<stdio.h>
#include<string.h>

int main()
{
    char str[40];
    printf("Input string: ");
    scanf("%[^\n]s", str);
    char *ptr = strtok(str, " "); 
    printf("Output string: ");
    while(ptr != NULL) { 
        if(ptr[0] == 'H')
            printf("%s ", ptr);
        ptr = strtok(NULL, " ");
    }
}