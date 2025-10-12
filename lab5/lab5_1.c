#include <stdio.h>

int main() {
    char empID[11];
    int workingHrs;
    double salaryPerHr, totalSalary;

    printf("Input the Employees ID(Max. 10 chars): ");
    scanf("%10s", empID);

    printf("Input the working hrs: ");
    scanf("%d", &workingHrs);

    printf("Salary amount/hr: ");
    scanf("%lf", &salaryPerHr);

    totalSalary = workingHrs * salaryPerHr;

    printf("\nEmployees ID = %s\n", empID);
    printf("Salary = U$ %.2lf\n", totalSalary);

    return 0;
}
