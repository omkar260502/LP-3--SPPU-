#include <bits/stdc++.h>

using namespace std;

int knapsack(int capacity, vector<int> &weights, vector<int> &values, int numItems)
{
    vector<vector<int>> dp(numItems + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= numItems; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (weights[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            }
        }
    }

    return dp[numItems][capacity];
}

int main()
{
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<int> weights(numItems);
    vector<int> values(numItems);

    cout << "Enter weights and values for each item:" << endl;
    for (int i = 0; i < numItems; i++)
    {
        cout << "Item " << i + 1 << ": ";
        cin >> weights[i] >> values[i];
    }

    int maxValue = knapsack(capacity, weights, values, numItems);

    cout << "Maximum value obtained = " << maxValue << endl;

    return 0;
}
/*
Time Complexity: O(N * W). As redundant calculations of states are avoided.
Auxiliary Space: O(N * W) + O(N). The use of a 2D array data structure for storing intermediate states and O(N) auxiliary stack space(ASS) has been used for recursion stack
*/
