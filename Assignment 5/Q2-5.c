#include <stdio.h>
#include <string.h>
int main()
{
   char lines[10][81];
    char input_char;
    int i = 0, j = 0;
    int line_count = 0;
    int total_word_count = 0;
    int l;
    printf("Enter number of lines:");
    scanf("%d",&l);
    for(i=0; i<l; i++){
        scanf("%c", &input_char);
        if(input_char == '\n')
            break;
        line_count += 1;
        for(j=0; j<80; j++){
            lines[i][j] = input_char;
            lines[i][j+1] = '\0';
            scanf("%c", &input_char);
            if(input_char == '\n')
                break;
        }
    }
    for(i=0; i<line_count; i++){
        char * curr_word = strtok(lines[i], " ");
        while(curr_word != NULL){
            total_word_count += 1;
            curr_word = strtok(NULL, " ");
        }
    }
    printf("Total number of words are: %d\n", total_word_count);
    return 0;
}
