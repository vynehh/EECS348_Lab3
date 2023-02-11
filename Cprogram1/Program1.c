#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *months[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
// Driver code
float* read_data_from(char *file_name)
    {
        const int months = 12;
        float* month_sales_data = (float*)malloc(sizeof(float) * months);
        
        FILE *filename = fopen(file_name, "r+");
        if(filename == NULL)
        {
            printf("Please check your file again!\n");
        }

        for(int i = 0; i < months; i++)
        {
            fscanf(filename, "%f\n", &month_sales_data[i]);
        }

        return month_sales_data;
    }

void CalMaxMinAve(float *sales)
{
    float sum = 0;
    float average = 0;
    int minMonth = 0;
    int maxMonth = 0;
    float min = sales[0];
    float max = sales[0];

    for (int i = 0; i < 12; i++) 
    {
        if (sales[0] > sales[i])
        {
            min = sales[i];
            minMonth = i;
        }
        if (sales[0] < sales[i])
        {
            max = sales[i];
            maxMonth = i;
        }

        sum += sales[i];
    }
    average = sum/12;

    printf("Minimum sales: $%.2f (%s)\n", min, months[minMonth]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[maxMonth]);
    printf("Average sales: $%.2f\n", average);
}

void SixMonthAverage(float *sales)
{
    float monAverage[7];

    for (int i = 0; i <= 6; i++)
    {
        float sum = 0;
        for (int j = i; j < i+6; j++){
            sum += sales[j];
        }
    
    monAverage[i]=sum/6;
    }
    for (int i = 0; i <=6; i++)
    {
        printf("%s - %s  $%.2f\n", months[i], months[i+5],monAverage[i]);
    }
    
}

void HighesttoLowest(float *sales)
{
    int sort[12];

    for (int i = 0; i < 12; i++) 
    {
        sort[i] = i;
    }

    for (int i = 0; i < 12; i++) 
    {
        for (int j = i + 1; j < 12; j++) 
        {
            if (sales[sort[i]] < sales[sort[j]]) 
            {
                float temp = sort[i];
                sort[i] = sort[j];
                sort[j] = temp;
            }
        }
    }

    for (int i = 0; i < 12; i++) 
    {
        printf("%s : $%.2f\n", months[sort[i]], sales[sort[i]]);
    }
}



int main()
{
FILE *file;
    file = fopen("input.txt", "r");

    float *sales = read_data_from("input.txt");
    printf("\nMonthly sales report for 2022: \n");
    printf("Months    Sales\n");

    for (int i=0; i<12; i++) 
    {
        printf(" %s     $%.2f\n", months[i], sales[i]);
    }

    printf("\nSales summary\n");
    CalMaxMinAve(sales);

    printf("\nSix-Month Moving Average Report \n");
    SixMonthAverage(sales);

    printf("\nSales Report (Highest to Lowest) \n");
    HighesttoLowest(sales);

}