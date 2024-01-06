/*
QUESTION LINK: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
*/

/*
 Here, the first function did not pass some test cases. The second did pass the known test cases (don't know about edge cases), but exceeded the time limit. The third passed the known test cases in CodeBlocks but not in the leetcode compiler (again, don't know about the edge cases).
*/

#include<bits/stdc++.h>

using namespace std;

int strStr1(string haystack, string needle) 
    {
        int i=0, j=0;

        while(i<=haystack.size()) 
        {
            if(j==needle.size())
            return i-j; // or i-needle.size(), means the same since j is now = needle.size()

            if(haystack[i]==needle[j])
            {
                ++i;
                ++j;
            }

            else
            {
                if(j==0)
                {
                    ++i;
                }

                else
                {
                    i=i-j;
                    j=0;
                }
            }
        }
        return -1;
    }

int strStr2(string haystack, string needle)
{
        int i=0, j=0, matching=-1;

        int sizeHaystack=haystack.size();
        int sizeNeedle=needle.size();

        while(i<sizeHaystack && j<sizeNeedle)
        {
            if(haystack[i]==needle[j])
            {
                if(matching==-1)
                {
                    matching=i;
                }

                ++i;
                ++j;
            }

            else
            {
                j=0;
                matching=-1;
            }
        }

        return matching;
}

int strStr3(string haystack, string needle)
    {
        int i;

        while(i<haystack.size()-needle.size()+1)
        {
            string temp=haystack.substr(i,needle.size());
            cout<<"\ntemp="<<temp<<endl;
            //Using substr(<beginning_position>, <size>);

            if(needle.compare(temp)==0)
            {
                return i;
            }

            else
            {
                ++i;
            }
        }

        return -1;
    }

int main()
{
    string haystack="sadbutsad", needle="sad";

    cout<<strStr2(haystack, needle)<<endl;
    cout<<strStr3(haystack, needle)<<endl;

    cout<<endl;
    return 0;
}


