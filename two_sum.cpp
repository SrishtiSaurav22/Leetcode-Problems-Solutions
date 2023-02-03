/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
*/

#include<bits/stdc++.h>

using namespace std;

vector<int> twoSumIterative(vector<int>& nums, int target)
{
    int i,j;

    vector<int> ans;

    for(i=0;i<nums.size();i++)
    {
        for(j=0;j<nums.size();j++)
        {
            if(i!=j && nums[i]+nums[j]==target)
            {
                ans.push_back(i);
                ans.push_back(j);

                return ans;
            }
        }
    }

    return ans;
}

// twoSumRecursive(vector<int>& nums, int target)
// use sorting (O of n) and then two pointers to iterate through the list
// that will be 2O(n) which is less than O(n^2)


int main()
{
    vector<int> vec;

    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(4);

    int target=6;

    cout<<twoSumIterative(vec,target)[0]<<"\t"<<twoSumIterative(vec,target)[1]<<endl;

    cout<<endl;
    return 0;
}
