#include <stdio.h>

#define MONTHS 12

void read_sales_data(float monthly_sales[MONTHS], const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%f", &monthly_sales[i]);
    }

    fclose(file);
}

void generate_sales_report(float monthly_sales[MONTHS]) {
    printf("Monthly sales report for 2022:\n");
    printf("%-10s %-10s\n", "Month", "Sales");

    for (int i = 0; i < MONTHS; i++) {
        printf("%-10d $%.2f\n", i + 1, monthly_sales[i]);
    }
}

void generate_sales_summary(float monthly_sales[MONTHS]) {
    int min_month = 1;
    int max_month = 1;

    for (int i = 1; i < MONTHS; i++) {
        if (monthly_sales[i] < monthly_sales[min_month - 1]) {
            min_month = i + 1;
        }
        if (monthly_sales[i] > monthly_sales[max_month - 1]) {
            max_month = i + 1;
        }
    }

    float average_sales = 0;
    for (int i = 0; i < MONTHS; i++) {
        average_sales += monthly_sales[i];
    }
    average_sales /= MONTHS;

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (Month %d)\n", monthly_sales[min_month - 1], min_month);
    printf("Maximum sales: $%.2f (Month %d)\n", monthly_sales[max_month - 1], max_month);
    printf("Average sales: $%.2f\n", average_sales);
}

void generate_six_month_moving_average(float monthly_sales[MONTHS]) {
    printf("\nSix-Month Moving Average Report:\n");

    for (int i = 0; i < MONTHS - 5; i++) {
        float sum = 0;
        for (int j = 0; j < 6; j++) {
            sum += monthly_sales[i + j];
        }
        float average = sum / 6;
        printf("%s - %s $%.2f\n", get_month_name(i + 1), get_month_name(i + 6), average);
    }
}

void generate_sales_report_highest_to_lowest(float monthly_sales[MONTHS]) {
    printf("\nSales Report (Highest to Lowest):\n");
    printf("%-10s %-10s\n", "Month", "Sales");

    // Create an array of indices to sort by sales
    int indices[MONTHS];
    for (int i = 0; i < MONTHS; i++) {
        indices[i] = i;
    }

    // Bubble sort (you can use more efficient sorting algorithms)
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = 0; j < MONTHS - i - 1; j++) {
            if (monthly_sales[indices[j]] < monthly_sales[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    // Print sorted sales
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10d $%.2f\n", indices[i] + 1, monthly_sales[indices[i]]);
    }
}

const char *get_month_name(int month_number) {
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month_number - 1];
}

int main() {
    const char *input_file_path = "path/to/your/input_file.txt";
    float monthly_sales[MONTHS];

    read_sales_data(monthly_sales, input_file_path);
    generate_sales_report(monthly_sales);
    generate_sales_summary(monthly_sales);
    generate_six_month_moving_average(monthly_sales);
    generate_sales_report_highest_to_lowest(monthly_sales);

    return 0;
}
