/*
Problem Statement:
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing
the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.



Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/
#include<bits/stdc++.h>
using namespace std;

int lcs(int index1, int index2, string text1, string text2)
{
    if (index1 == 0 || index2 == 0)
    {
        return 0;
    }
    if (text1[index1 - 1] == text2[index2 - 1])
    {
        return 1 + lcs(index1 - 1, index2 - 1, text1, text2);
    }
    else
    {
        int op1 = lcs(index1 - 1, index2, text1, text2);
        int op2 = lcs(index1, index2 - 1, text1, text2);
        return max(op1, op2);
    }
}


int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                int op1 = dp[i - 1][j];
                int op2 = dp[i][j - 1];
                dp[i][j] = max(op1, op2);
            }
        }
    }
    int i = n;
    int j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            ans += text1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    return dp[n][m];
}

/*
Time Complexity:- O(m*n) m,n->length of 2 strings
Space Complextiy:- O(m*n)
*/