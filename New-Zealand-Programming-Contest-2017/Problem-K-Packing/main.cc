#include <bits/stdc++.h>

using namespace std;

int max(int a, int b) { return (a>b)?a:b; }

int weights[101], values[101];
int dp[101][1001][1001];
int knapsack(int N, int W1, int W2) {
  if (N == 0) return 0;
  if (dp[N-1][W1][W2] != -1) return dp[N-1][W1][W2];
  
  int w1, w2, none;
  w1 = 0; w2 = 0; none = 0;
  if (W1 >= weights[N-1])
    w1 = values[N-1]+knapsack(N-1, W1-weights[N-1], W2);
  if (W2 >= weights[N-1])
    w2 = values[N-1]+knapsack(N-1, W1, W2-weights[N-1]);
  none = knapsack(N-1,W1, W2);
  dp[N-1][W1][W2] = max(none, max(w1, w2));
  return dp[N-1][W1][W2];
}

int main() {
  int P;
  cin >> P;
  int N, W1, W2;
  for (int i=0; i<P; i++) {
    memset(dp, -1, sizeof(dp));
    cin >> N >> W1 >> W2;
    for (int i=0; i<N; i++) {
      cin >> weights[i];
    }
    for (int i=0; i<N; i++) {
      cin >> values[i];
    }
    int total = knapsack(N, W1, W2);
    cout << "Problem " << i+1 << ": " << total << "\n";
  }
}
