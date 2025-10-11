#include <stdio.h>

void swapNumbers(int *Num1, int *Num2);

int main(){
    int Num1 = 0, Num2 = 0 ;
    int *prt1 = &Num1 , *prt2 = &Num2;
    printf("Enter your numder\n");
    scanf("%d",&Num1);
    printf("Enter your numder\n");
    scanf("%d",&Num2);



    printf("Before swap (num1=%d & num2=%d)\n",Num1,Num2);
    swapNumbers(prt1,prt2);
    printf("After swap (num1=%d & num2=%d)\n",Num1,Num2);

    return 0;

}
void swapNumbers (int *Num1, int *Num2){
int temp = *Num1;
*Num1 = *Num2 ;
*Num2 = temp ;
}