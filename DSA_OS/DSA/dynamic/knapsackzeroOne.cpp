#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    // Create a DP table to store the maximum value for each subproblem
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    // Build the table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            // If the weight of the current item is less than or equal to the current capacity
            if (weights[i-1] <= w) {
                // Take the maximum of either including or excluding the current item
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i-1]] + values[i-1]);
            } else {
                // If the current item cannot be included, just carry forward the previous value
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    // The answer is the value in the bottom-right corner of the table
    return dp[n][W];
}

int main() {
    // Number of items
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    // Maximum weight the knapsack can hold
    int W;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    vector<int> weights(n);
    vector<int> values(n);

    // Input the weights and values of the items
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    // Call the knapsack function
    int result = knapsack(W, weights, values, n);

    // Output the maximum value that can be obtained
    cout << "Maximum value in knapsack: " << result << endl;

    return 0;
}
