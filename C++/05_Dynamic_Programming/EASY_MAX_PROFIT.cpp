int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    
    int lowest = prices[0];
    int profit = 0;
    
    for (int i = 1; i<prices.size();i++)
    {
        lowest = min(lowest, prices[i]);
        profit = max(profit, prices[i]-lowest);
    }
    return profit;
    
}