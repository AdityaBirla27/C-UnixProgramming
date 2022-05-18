// Manager-> Weakly Fixed salary
//Hourly worker -> For 40 Hrs & 40 Hrs< 1.5 times the usual amount
//Commition worker -> recive $350 + 6.5% gross weely sales
//pieceworkers -> fixed amount of money for each of the items they produce

#include <stdio.h>
int manager(float amount);//ProtoType
int hourly_worker(float amount,int hrs);//ProtoType
int communications_worker(float sales);//ProtoType
int pieceworkers(float amount, float sales);//ProtoType

int main(){
    float amount,sales;
    int hrs;
    int choice;
    printf("1. Manger\n2. Hourly Worker\n3. Communications Worker\n4. Piece Worker\nChoose whos Salary you wanna know:");
    scanf("%d",&choice);
    switch(choice){
        case 1://Case 1 for managers
            printf("\nEnter Amount Earned per month: $ ");
            scanf("%f",&amount);
            manager(amount);
            break;//Break of case
        case 2://Case 2 for Hourly workers
            printf("\nEnter Number of Hours Worked: ");
            scanf("%d",&hrs);
            printf("\nEnter amount Earned Per Hour: $ ");
            scanf("%f",&amount);
            hourly_worker(amount,hrs);
            break;
        case 3://Case 3 for communications_worker
            printf("\nEnter Gross Weekly Sale: $");
            scanf("%f",&sales);
            communications_worker(sales);
            break;
        case 4://Case 4 for pieceworkers
            printf("\nEnter number of items sold: ");
            scanf("%f",&sales);
            printf("\nEnter Cut per produce: $");
            scanf("%f",&amount);
            pieceworkers(amount,sales);
    }

}
// Manager-> Weakly Fixed salary
int manager(float amount){
    printf("\nManagers Weekly Pay:$ %.2f",amount);
}
//Hourly worker -> For 40 Hrs & 40 Hrs< 1.5 times the usual amount
int hourly_worker(float amount,int hrs){
    float sum=0;
    int extra=0;
    if (hrs > 40){//As the amount earned incresses with incress hrs excedding above 40
        extra=hrs-40;
        hrs=40;
    }
    sum=extra*amount*1.5+hrs*amount; //Total Amount Earned
    printf("\nHourly Workers:$ %.2f",sum);
}
//Commition worker -> recive $350 + 6.5% gross weely sales
int communications_worker(float sales){
    float sum=350+sales*6.5/100;//As communications_worker earns 350 on defult and 6.5%on sales
    printf("\nCommunication worker:$ %.2f",sum);
}
//pieceworkers -> fixed amount of money for each of the items they produce
int pieceworkers(float amount, float sales){
    float sum=sales*amount;
    printf("\nPiece Worker: $ %.2f",sum);
}
