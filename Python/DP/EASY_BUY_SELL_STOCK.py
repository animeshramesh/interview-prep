"""
You just need to consider the min_val. I was trying to keep track of
max_val too. But you don't need that. For every price you encounter,
compute the profit by comparing it with min_val.
"""

class Solution(object):
    def maxProfit(self, prices):
        if not prices: return 0
        min_val, profit = prices[0], 0
        for price in prices:
            min_val = min(min_val, price)
            profit = max(profit, price - min_val)
        return profit
