int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int max_amount = 0, account_sum = 0;
    for (int i = 0; i < accountsSize; i++)
    {
        for (int  j= 0; j < accountsColSize[i]; j++)
        {
            account_sum += accounts[i][j];
        }
        max_amount = max_amount<account_sum? account_sum: max_amount;
        account_sum = 0;
    }
    return max_amount;
}