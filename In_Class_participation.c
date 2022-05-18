#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char first_name[20];
    char last_name[20];
    unsigned int age;
    char gender[10];
    float hourly_salary;
}Employee;

void main(void)
{
    Employee emp[3];
    for (size_t i = 0; i < 3; i++)
    {
        printf("For employee %d\n", i+1);
        printf("Enter name      Age     Gender      Hourly_Sal\n ");
        scanf("%s %s", &emp[i].first_name, &emp[i].last_name);
        scanf("%u", &emp[i].age);
        scanf("%s", &emp[i].gender);
        scanf("%f", &emp[i].hourly_salary);
    }
    FILE *fptr;
    if ((fptr = fopen("employees.txt", "w")) == NULL)
    {
        printf("error opening file");
        exit(1);
    }
    else{
        for (size_t i = 0; i < 3; i++)
        {
            fprintf(fptr, "%s\t%s\t%u\t%s\t%.2f\n", emp[i].first_name, emp[i].last_name,
                        emp[i].age, emp[i].gender, emp[i].hourly_salary);    //print all in file
        }
        fclose(fptr);   //close file
    }
}

