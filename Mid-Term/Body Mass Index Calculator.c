#include<stdio.h>  
int main()  
{  
    float height, weight, bmi;  
    printf("Enter weight in kg\n");  
    scanf("%f", &weight);
 
    printf("Enter height in meter\n");  
    scanf("%f", &height);  
    bmi = weight / (height * height);  
 
    printf("Your Body Mass Index(BMI) is %f\n", bmi);  //BMI VALUES
 
    if(bmi < 15)  //Underweight: less than 18.5
    {  
        printf("Your BMI category is: UnderWeight\n");  
    }  
    else if(bmi >= 18.5 && bmi <= 24.9)  //Normal: between 18.5 and 24.9
    {  
        printf("Your BMI category is: Normal\n");  
    }  
    else if(bmi > 25 && bmi <= 29.9)  //Overweight: between 25 and 29.9
    {  
        printf("Your BMI category is: Over Weight\n");  
    }  
    else if(bmi >= 30)  //Obese: 30 or greater
    {  
        printf("Your BMI category is: Obese\n");  
    }  
    else  
    {  
        printf("Wrong entry\n");  
    }  
    return 0;  
}  