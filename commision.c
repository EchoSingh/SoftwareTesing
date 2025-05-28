#include <stdio.h>

int main() {
    int locks, stocks, barrels, t_sales, flag = 0;
    float commission;

    printf("Enter the total number of locks: ");
    scanf("%d", &locks);
    if ((locks < 1) || (locks > 70)) flag = 1;

    printf("Enter the total number of stocks: ");
    scanf("%d", &stocks);
    if ((stocks < 1) || (stocks > 80)) flag = 1;

    printf("Enter the total number of barrels: ");
    scanf("%d", &barrels);
    if ((barrels < 1) || (barrels > 90)) flag = 1;

    if (flag == 1) {
        printf("Invalid input\n");
        return 0;
    }

    t_sales = (locks * 45) + (stocks * 30) + (barrels * 25);

    if (t_sales <= 1000) {
        commission = 0.10f * t_sales;
    } else if (t_sales < 1800) {
        commission = 0.10f * 1000;
        commission += 0.15f * (t_sales - 1000);
    } else {
        commission = 0.10f * 1000;
        commission += 0.15f * 800;
        commission += 0.20f * (t_sales - 1800);
    }

    printf("Total sales: $%d\n", t_sales);
    printf("Commission: $%.2f\n", commission);

    return 0;
}
