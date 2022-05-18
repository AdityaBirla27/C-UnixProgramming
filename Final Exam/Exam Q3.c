#include <stdio.h>
int main() {
    char line[50];
    int vow=0, con=0, digit=0;

    printf("Input a string: ");
    fgets(line, sizeof(line), stdin);

    for (int i = 0; line[i] != '\0'; ++i) {
        if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u' || line[i] == 'A' ||line[i] == 'E' || line[i] == 'I' || line[i] == 'O' ||line[i] == 'U')
            vow=vow+1;

        else if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))
            con=con+1;

        else if (line[i] >= '0' && line[i] <= '9')
            digit=digit+1;

    }

    printf("Number of Vowels: %d", vow);
    printf("\nNumber of Consonants: %d", con);
    printf("\nNumber of Digits: %d", digit);
    return 0;
}
