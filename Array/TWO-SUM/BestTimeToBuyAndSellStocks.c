// bruitforce approach
int max_(int a , int b) {
    return ((a > b)?a:b);
}
int maxProfit(int* prices, int pricesSize) {
    int max = INT_MIN;
    int min = INT_MAX;
    int profit = 0;

    for (int i = 0; i < pricesSize; i++) {
            int currentProfit = prices[j] - prices[i];

            profit = max_(currentProfit, profit);
    }

    return profit;
}
