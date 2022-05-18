#include<stdio.h>

int sum(float num1, float num2) { //For sum
   float s;
   s = num1 + num2;
   return (s);
}

int average(float num, int i){ //For average
    float avg;
    avg=num/i;
    return avg;
}
int product(float num, int num1){ //for product
    float pro;
        pro= num*num1;
    return pro;
}
int smallest(float num1, float num2){ //for smallest
    if (num1 > num2)
        return num2;
    else    
        return num1;
}

int largest(float num1, float num2){//for largest
    if (num1 > num2)
        return num1;
    else    
        return num2;
}


int main(){
    int i,j;
    float num1,avg;
    float small=200;
    float large=-200;
    float s=0;
    float num;
    float pro=1;
    printf("Number of elements: ");
    scanf("%d",&i);
    for(j=1;j<=i;j++){
        printf("Enter %d number between -100 and 100:",j);
        scanf("%f",&num1);
        s=sum(s,num1); //gets sum and saves in s
        avg=average(s,j); 
        pro=product(pro,num1); //gets product of the numebrs and saves in pro
        small=smallest(small,num1); //gets smallest number and saves it in small
        large=largest(large,num1); //gets largest and saves in large
    }
    printf("Sum:%.2f\n",s);
    printf("Average is:%.2f\n",avg);
    printf("Product is:%.2f\n",pro);
    printf("Smallest is:%.2f\n",small);
    printf("Largest is:%.2f\n",large);

}