int maxProfit(int* prices, int pricesSize) {
    int min_price = INT_MAX;
    int max_profit = 0;

    for (int i = 0; i < pricesSize; i++) {
        min_price = (prices[i] < min_price) ? prices[i] : min_price;
        max_profit = (prices[i] - min_price > max_profit) ? prices[i] - min_price : max_profit;
    }
    return max_profit;
}

// striver approach 
int min_(int a, int b) {
    return (a < b) ? a : b;
}

int max_(int a, int b) {
    return (a > b) ? a : b;
}
int maxProfit(int* prices, int pricesSize) {
    int min_price = prices[0];
    int max_profit = 0;
    
    for (int i = 1; i < pricesSize; i++) {
        int cost = prices[i] - min_price;
        max_profit = max_(cost, max_profit);

        min_price = min_(min_price, prices[i]);
    }
    return max_profit;
}
