#include <stdio.h>
#include <stdlib.h>
#include <float.h>

typedef struct
{
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
} ITEM;

void merge(ITEM items[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    ITEM *L = (ITEM *)malloc(n1 * sizeof(ITEM));
    ITEM *R = (ITEM *)malloc(n2 * sizeof(ITEM));

    if (L == NULL || R == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (i = 0; i < n1; i++)
    {
        L[i] = items[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = items[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i].profit_weight_ratio >= R[j].profit_weight_ratio)
        {
            items[k] = L[i];
            i++;
        }
        else
        {
            items[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        items[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        items[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(ITEM items[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(items, l, m);
        mergeSort(items, m + 1, r);

        merge(items, l, m, r);
    }
}

void fractionalKnapsack(double capacity, ITEM items[], int n)
{
    mergeSort(items, 0, n - 1);

    double currentWeight = 0.0;
    double totalProfit = 0.0;
    double *taken_amount = (double *)malloc(n * sizeof(double));

    if (taken_amount == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        taken_amount[i] = 0.0;
    }

    printf("\nItem No\t\tprofit\t\t\tWeight\t\t\tAmount to be taken\n");
    for (int i = 0; i < n; ++i)
    {
        if (currentWeight + items[i].item_weight <= capacity)
        {
            currentWeight += items[i].item_weight;
            totalProfit += items[i].item_profit;
            taken_amount[i] = 1.0;
        }
        else
        {
            double remaining_capacity = capacity - currentWeight;
            taken_amount[i] = remaining_capacity / items[i].item_weight;
            totalProfit += items[i].item_profit * taken_amount[i];
            currentWeight = capacity;
            break;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        printf("%d\t\t%f\t\t%f\t\t%f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, taken_amount[i]);
    }

    printf("\n\tMaximum profit: %f\n", totalProfit);

    free(taken_amount);
}

int main()
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    ITEM *items = (ITEM *)malloc(n * sizeof(ITEM));
    if (items == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; ++i)
    {
        items[i].item_id = i + 1;
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%lf %lf", &items[i].item_profit, &items[i].item_weight);
        if (items[i].item_weight > 0)
        {
            items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
        }
        else
        {
            items[i].profit_weight_ratio = DBL_MAX;
        }
    }

    double capacity;
    printf("\tEnter the capacity of knapsack: ");
    scanf("%lf", &capacity);

    fractionalKnapsack(capacity, items, n);

    free(items);

    return 0;
}
