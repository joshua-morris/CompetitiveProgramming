class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [10e9] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for c in coins:
                if i - c >= 0:
                    dp[i] = min(dp[i - c] + 1, dp[i])
                        
        return dp[amount] if dp[amount] != 10e9 else -1