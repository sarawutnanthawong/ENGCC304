#include <stdio.h>

int main(){
    char Employees[10];
    int working = 0;
    int Salary = 0;
    printf("Input the Employees ID(Max. 10 chars):\n");
    scanf("%10s", Employees);
    printf("Input working/hrs):\n");
    scanf("%d", &working);
    printf("Input Salary/hrs):\n");
    scanf("%d", &Salary);
    Salary = Salary * working;
    printf("Employees ID = %s\n", Employees);
    printf("Salary = %d", Salary);
    return 0;
}