#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonSubstring(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    
    // DP table to store lengths of longest common suffixes of substrings
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    int maxLength = 0;  // Length of the longest common substring
    int endPos = 0;     // End position of the longest common substring in s1

    // Build the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endPos = i - 1;  // Update the end position
                }
            } else {
                dp[i][j] = 0;  // No common substring at this point
            }
        }
    }

    // Extract the longest common substring
    return s1.substr(endPos - maxLength + 1, maxLength);
}

int main() {
    string s1, s2;

    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    string result = longestCommonSubstring(s1, s2);

    if (result.empty()) {
        cout << "No common substring found!" << endl;
    } else {
        cout << "The longest common substring is: " << result << endl;
    }

    return 0;
}
