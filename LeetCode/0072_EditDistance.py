class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        def cost(i, j):
            if word1[i - 1] == word2[j - 1]:
                return 0
            else:
                return 1
            
        m, n = len(word1), len(word2)
        distance = [[0] * (n + 1) for i in range(m + 1)]
        for i in range(1, m + 1):
            distance[i][0] = distance[i - 1][0] + 1
        
        for j in range(1, n + 1):
            distance[0][j] = distance[0][j - 1] + 1
        
        
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                distance[i][j] = min(distance[i][j - 1] + 1,
                                    distance[i - 1][j] + 1,
                                    distance[i - 1][j - 1] + cost(i, j))
        
        return distance[m][n]