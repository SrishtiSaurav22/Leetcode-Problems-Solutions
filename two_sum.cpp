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

// NAIVE APPROACH, TIME COMPLEXITY: O(n^2)
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

// BETTER APPROACH, TIME COMPLEXITY: O(n*log(n)+n)
vector<int> twoSumTwoCounter(vector<int>& nums, int target)
{
    // this method will work on sorted vector so sort it first

    sort(nums.begin(),nums.end());

    int i,j;
    i=0;
    j=nums.size()-1;

    vector<int> ans;

    while(i<j) // no equality allowed as then the common element will be repeated, which is not allowed
    {
        if(nums[i]+nums[j]==target)
        {
            ans.push_back(i);
            ans.push_back(j);

            return ans;
        }

        else if(nums[i]+nums[j]>target)
            --j;

        else if(nums[i]+nums[j]<target)
            ++i;
    }

    return ans;
}

// SIMPLE BINARY SEARCH
int binarySearchRecursive(vector<int> vec, int key, int low, int high)
{
    int mid=(low+high)/2;

    if(low>high)
        return -1;

    if(key==vec[mid])
        return mid;

    if(key>vec[mid])
        return binarySearchRecursive(vec,key,mid+1,high);

    if(key<vec[mid])
        return binarySearchRecursive(vec,key,low,mid-1);

    return -1;
}

// ANOTHER BETTER APPROACH, TIME COMPLEXITY: O(n*log(n))
vector<int> twoSumBinarySearch(vector<int>& nums, int target)
{
    int i;

    vector<int> ans;

    for(i=0;i<nums.size();i++)
    {
        int pos=binarySearchRecursive(nums,target-nums[i],0,nums.size()-1);

        if(pos!=-1)
        {
            ans.push_back(i);
            ans.push_back(pos);

            return ans;
        }
    }

    return ans;
}

int main()
{
    vector<int> vec;

    vec.push_back(-8);
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(10);
    vec.push_back(45);

    int target=16;

    cout<<twoSumIterative(vec,target)[0]<<"\t"<<twoSumIterative(vec,target)[1]<<endl;
    cout<<twoSumTwoCounter(vec,target)[0]<<"\t"<<twoSumTwoCounter(vec,target)[1]<<endl;
    cout<<twoSumBinarySearch(vec,target)[0]<<"\t"<<twoSumBinarySearch(vec,target)[1]<<endl;

    cout<<endl;
    return 0;
}
