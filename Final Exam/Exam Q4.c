    #include <stdio.h>
struct student {
    char firstName[20];
    char lastName[20];
    char studentID[20];
    float programming;
    float math;
} s[3];

int main() {
    int i;
    float avg_programming=0,avg_math=0,max_math=0,min_math=100;
    printf("Enter information of students:\n");

    // storing information
    for (i = 0; i < 3; ++i){
        printf("----------------------------------------------\n");
        printf("Enter first name: ");
        scanf("%s", s[i].firstName);
        printf("Enter Last name: ");
        scanf("%s", s[i].lastName);
        printf("Enter grade for programming: ");
        scanf("%f", &s[i].programming);
        printf("Enter grade for Math: ");
        scanf("%f", &s[i].math);

    }
    printf("----------------------------------------------\n");

    printf("----------------------------------------------\n");

    printf("Displaying Information:\n\n");

    // displaying information
    for (i = 0; i < 3; ++i) {
        printf("----------------------------------------------\n");
        avg_programming=avg_programming+s[i].programming;
        avg_math=avg_math+s[i].math;
        printf("First name: ");
        puts(s[i].firstName);
        printf("Last name: ");
        puts(s[i].lastName);
        printf("grade for programming: %.1f\n", s[i].programming);
        printf("grade for Math: %.1f", s[i].math);
        printf("\n");
        if (min_math>s[i].math)
            min_math=s[i].math;
        if (max_math<s[i].math)
            max_math=s[i].math;

    }
    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");
    printf("Average of Programming: %.1f\n",avg_programming/3);
    printf("Average of Math: %.1f\n",avg_math/3);
    printf("Max Score in Math: %.1f\n",max_math);
    printf("Min Score in Math: %.1f\n",min_math);
    return 0;
}
