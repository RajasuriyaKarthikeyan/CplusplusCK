#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the longest common subsequence (LCS)
int longestCommonSubsequence(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    
    // DP table to store lengths of longest common subsequence
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Fill the DP table using the recurrence relation
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;  // If characters match, extend the subsequence
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // Otherwise, take the max value
            }
        }
    }

    // The value at dp[m][n] is the length of the longest common subsequence
    return dp[m][n];
}

// Function to reconstruct the LCS from the DP table
string reconstructLCS(string s1, string s2, vector<vector<int>>& dp) {
    int i = s1.length();
    int j = s2.length();
    string lcs = "";

    // Reconstruct the LCS from the DP table
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs;  // If characters match, add to LCS
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;  // Move up in the table
        } else {
            j--;  // Move left in the table
        }
    }

    return lcs;
}

int main() {
    string s1, s2;

    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    // Calculate the length of the longest common subsequence
    int lcsLength = longestCommonSubsequence(s1, s2);

    // Print the length of the LCS
    cout << "Length of the Longest Common Subsequence: " << lcsLength << endl;

    // Reconstruct the LCS
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    // Fill the DP table for LCS length
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct and print the LCS
    string lcs = reconstructLCS(s1, s2, dp);
    cout << "The Longest Common Subsequence is: " << lcs << endl;

    return 0;
}
