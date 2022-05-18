/*
4-> Sales Man (1,2,3,4)
5-> Products(1,2,3,4,5)
Slip contain: a) The salesperson number b) The product number c) The total dollar value of that product sold that day
Number of sale slip(per employee): 0-5(based on the product number)
Assume that the information from all of the slips for last month is available

*/

#include <stdio.h>
int main(){
    float sale;
    int emp_num,product_num; //assume employee number is 1,2,3,4,5
    float sum_row,sum_col;
    float sum_total=0;
    /* For Last Month */
    //salesman=[Number of Products][Number of Saleman]
    float salesman[5][4]= {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};//array with all 0 values
    for(;;){
        printf("Enter employee number(1,2,3,4)Anything else breaks loop: ");
        scanf("%d",&emp_num);
        if (emp_num >4 || emp_num <1)//break loop for wrong input
            break;
        printf("Enter Product Number(1,2,3,4,5) Anything else break loop: ");//break loop for wrong input
        scanf("%d",&product_num);
        if (product_num>5 || product_num<1)
            break;
        printf("Enter sale amount: $");
        scanf("%f",&sale);
        salesman[product_num-1][emp_num-1]=salesman[product_num-1][emp_num-1]+sale; //add value to the array aka edit the array

    }
    //float salesman[5][4]={{5000.00,6000.00,7000.00,8000.00},{2000.00,500.00,1000.00,200.00},{5000.00,6000.00,7000.00,2000.00},{2000.00,1000.00,200.00,600.00},{400.00,500.00,100.00,2000.00}};
    //Print Table form
    printf("Last Month Sales:\n");
    printf("\t1 \t\t2 \t\t3 \t\t4 \t\t Total Sale For Produt \n");
    for (int i=0;i<5;i++){
        sum_col=0;
        printf("%d\t",i+1);
        for(int j=0;j<4;j++){
            printf("%.2f\t\t",salesman[i][j]);
            sum_col=sum_col+salesman[i][j];
        }
        printf("\t%.2f",sum_col);
        printf("\n");
    }
    printf("-----------------------------------------------------------------------------------------\n\t");
    //To Find final sum of each col
    for (int j=0;j<4;j++){
        sum_row=0;
        for(int i=0; i<5;i++){
            sum_row=sum_row+salesman[i][j];
        }
        sum_total=sum_total+sum_row;
        printf("%.2f\t\t",sum_row);
    }
    printf("\t%.2f",sum_total);//Find total of each row or col
}
