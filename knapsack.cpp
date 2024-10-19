#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;


void printKnapsackSolution( vector<vector<int>>& dp, vector<int>& wt,  vector<int>& profit, int cap) {
    int n = wt.size();
    int totalValue = dp[n][cap];
    int totalWeight = 0;

    cout << "Items included in the knapsack:\n";
    for (int i = n; i > 0; i--) {
        if (dp[i][cap] != dp[i - 1][cap]) {  // This item was included
            cout << "Item " << i << ": Weight = " << wt[i - 1] << ", Value = " << profit[i - 1] << '\n';
            totalWeight += wt[i - 1];
            cap -= wt[i - 1];
        }
    }

    cout << "Total weight: " << totalWeight << '\n';
    cout << "Total value: " << totalValue << '\n';
}

void knapsack(int cap,vector<int>& wt,vector<int>& profit)
{
    int n= wt.size();
    vector<vector<int>> dp(n+1,vector<int>(cap+1,0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= cap; w++)
        {
            if(wt[i-1]<=w)
            {
                dp[i][w]= max(dp[i-1][w],dp[i-1][w-wt[i-1]]+profit[i-1]);
            }
            else
            {
                dp[i][w]=dp[i-1][w];
            }
        }
        
    }
    printKnapsackSolution(dp, wt, profit, cap);
    
    
}

int main()
{
    int cap =8;
    vector<int> wt={2,3,4,5};
    vector<int> profit={10,20,50,60};
    knapsack(cap,wt,profit);
    return 0;

}