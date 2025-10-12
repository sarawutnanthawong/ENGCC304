#include <stdio.h>

int main() {
    int position;
    int yearsExperience;
    int projectsCompleted;
    int baseSalary = 0;
    double experienceBonus = 0;
    double specialBonus = 0;
    double netSalary = 0;

    printf("Enter Position (1=Junior, 2=Mid-Level, 3=Senior): ");
    scanf("%d", &position);

    printf("Enter Years of Experience: ");
    scanf("%d", &yearsExperience);

    printf("Enter Number of Projects Completed this Year: ");
    scanf("%d", &projectsCompleted);

    switch (position) {
        case 1: baseSalary = 20000; break;
        case 2: baseSalary = 35000; break;
        case 3: baseSalary = 50000; break;
        default: 
            printf("Invalid position!\n");
            return 1;
    }

    if (yearsExperience < 1) {
        experienceBonus = 0;
    } else if (yearsExperience <= 3) {
        experienceBonus = baseSalary * 0.10;
    } else if (yearsExperience <= 5) {
        experienceBonus = baseSalary * 0.15;
    } else {
        experienceBonus = baseSalary * 0.20;
    }

    // คำนวณโบนัสพิเศษตามจำนวนโปรเจค
    if (projectsCompleted > 5) {
        specialBonus = baseSalary * 0.05;
    } else {
        specialBonus = 0;
    }

    netSalary = baseSalary + experienceBonus + specialBonus;

    printf("\nBase Salary: %d THB\n", baseSalary);
    printf("Experience Bonus: %.0f THB\n", experienceBonus);
    printf("Special Bonus: %.0f THB\n", specialBonus);
    printf("Net Salary: %.0f THB\n", netSalary);

    return 0;
}
