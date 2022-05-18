#include<stdio.h>
int de_morgan(int i, int j);//Prototype

int main(){
    //Cases
    de_morgan(5,5);
    de_morgan(5,7);
    de_morgan(3,5); 
    de_morgan(3,7);
    printf("As both outputs are same \nHence Proved!");
}
/* && -> Is true only when both are true
   || -> Is true when either of the conditions are true
    ! -> If answer is true it coverts it to false and vise-versa  
*/
int de_morgan(int i, int j){
    if (!((i > 4) || (j <= 6)))
        printf("T\t");
    else
        printf("F\t");
    if (!(i > 4) && !(j <= 6))
        printf("T\n");
    else
        printf("F\n");
}