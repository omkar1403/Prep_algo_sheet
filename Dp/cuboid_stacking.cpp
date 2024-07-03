#include <bits/stdc++.h>
class Solution
{
    static bool comp(vector<int> &d1, vector<int> &d2)
    { // In this function we just sort the different arrays on basis of 3 elements
        if (d1[0] == d2[0])
        {
            if (d1[1] == d2[1])
            {
                return d1[2] < d2[2];
            }
            return d1[1] < d2[1];
        }
        return d1[0] < d2[0];
    }

    int solve(vector<vector<int>> &cuboid, int ind, int prev, vector<vector<int>> &dp)
    { // memoization approrach
        if (ind == cuboid.size())
        {
            return 0;
        }
        if (dp[ind][prev + 1] != -1)
        {
            return dp[ind][prev + 1]; // we store into prev+1
        }
        int notake = solve(cuboid, ind + 1, prev, dp); // here we maintain it as it is
        int take = 0;
        if (prev == -1 || (cuboid[prev][0] <= cuboid[ind][0] && cuboid[prev][1] <= cuboid[ind][1] && cuboid[prev][2] <= cuboid[ind][2]))
        {
            take = cuboid[ind][2] + solve(cuboid, ind + 1, ind, dp); // isme hamne ascending order me kiya hai so first element small hoga uske next element se that's why we have wrote that cuboid[prev][0]<=cuboid[ind][0]
        }
        return dp[ind][prev + 1] = max(take, notake);
    }

public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (int i = 0; i < cuboids.size(); i++)
        {
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        sort(cuboids.begin(), cuboids.end(), comp);
        vector<vector<int>> dp(cuboids.size() + 1, vector<int>(cuboids.size() + 1, 0)); // here it is for tabulation apporach else for memoization it should be 1
        for (int pos = cuboids.size() - 1; pos >= 0; pos--)
        { // loop is staring from n-1
            for (int prev = pos - 1; prev >= -1; prev--)
            {                                     // this loop is till -1 that's why we took extra ele.
                int skip = dp[pos + 1][prev + 1]; // here we are storing it into pos+1
                int take = 0;
                if (prev == -1 || (cuboids[prev][0] <= cuboids[pos][0] && cuboids[prev][1] <= cuboids[pos][1] && cuboids[prev][2] <= cuboids[pos][2]))
                { // here we are storing it into pos+1
                    take = cuboids[pos][2] + dp[pos + 1][pos + 1];
                }
                dp[pos][prev + 1] = max(skip, take);
            }
        }
        return dp[0][0];
    }
};