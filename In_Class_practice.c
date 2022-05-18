#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void main()
{
    FILE *fptr, *fptru;
    char str;
    int counter = 0;
    if ((fptr = fopen("C_Language.txt","r")) == NULL){
        printf("Error! opening file");
        exit(1);
    }
    int sum = 0, words = 0, wcount;
    fscanf(fptr, "%c", &str);
    while (!feof(fptr))
    {
        if(isdigit(str)){
            sum += str - '0';
            printf("%c ", str);
        }
        if (str == ' ' || str == '\t' || str == '\n' || str == '\0')
        {
            words++;
        }
        fscanf(fptr, "%c", &str);
    }
    printf("\nSum is %d", sum);
    printf("\nNumber of words is %d", words);
    rewind(fptr);
    char s[words][50];
    char string[50];
    int count[words], index, i, len, isUnique;
    for (int i = 0; i < words; i++)
    {
        count[i] = 0;
    }
    index = 0;
    while (fscanf(fptr, "%s", string) != EOF)
    {
        strlwr(string);
        len = strlen(string);
        if (ispunct(string[len - 1]))
        {
            string[len - 1] = '\0';
        }
        isUnique = 1;
        for (i=0; i<index && isUnique; i++)
        {
            if (strcmp(s[i], string) == 0)
                isUnique = 0;
        }
        if (isUnique)
        {
            strcpy(s[index], string);
            count[index]++;

            index++;
        }
        else
        {
            count[i - 1]++;
        }
    }
    printf("\nOccurrences of all distinct words in file: \n");
    for (int i=0; i<index; i++)
    {
        printf("%-18s => %2d\n", s[i], count[i]);
    }
    rewind(fptr);
    char ch;
    if ((fptru = fopen("C_Language_upper.txt","w")) == NULL){
        printf("Error! opening file");
        exit(1);
    }
    while((ch=fgetc(fptr))!=EOF){
        if(islower(ch)){
            ch=ch-32;
        }
        fputc(ch, fptru);
    }
    fclose(fptr);
    fclose(fptru);
}
