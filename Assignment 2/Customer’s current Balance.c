#include<stdio.h>
int reduce_credit(unsigned int acc_num , float credit, float balance);//Prototype

int main(){
    printf("Account Number \t New Crdit Limit \t Amount can borrow\n");//Table Names
    reduce_credit(58219701, 2000, 1000);//Call Functions
    reduce_credit(82154721, 4000, 2000);//Call Functions
    reduce_credit(91254210, 1500, 1200);//Call Functions
    
}

int reduce_credit(unsigned int acc_num, float credit, float balance){
    float new_credit=credit*3/4;
    float can_borrow= new_credit-balance;
    if (can_borrow<=0)//For checking if one can borrow money or not
        printf("%u\t %19.2f \t %17.2f\t(Cannot Borrow Any Money)\n",acc_num, new_credit,can_borrow);
    else
        printf("%u\t %19.2f \t %17.2f\n",acc_num, new_credit,can_borrow);

}