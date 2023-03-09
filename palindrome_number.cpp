/*
Given an integer x, return true if x is a palindrome, and false otherwise.
 
EXAMPLE 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

EXAMPLE 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

EXAMPLE 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 
Constraints:
-231 <= x <= 231 - 1
*/

// Here, I'm reversing the whole number and performing overflow check (needed as I'm storing num in int)
bool isPalindrome1(int num) 
    {
        if(num<0)
            return false;
        
        int nnum=num,d,sum=0,cnt=0;

        while(nnum)
        {
            if(cnt==9)
            {
                if(sum-INT_MAX/10 >= 0)
                {
                    if(nnum%10 <= 7)
                    {
                        sum+=nnum%10;
                        break; 
                    }
                }
            }

            d=nnum%10;
            sum=sum*10+d;
            nnum=nnum/10;
            ++cnt; // if cnt is i, then d will be i-th digit of nnum
        }

        if(sum==num)
            return true;
  
        return false;  
    }

// Here, I'm reversing the whole number, but without overflow check (I'm storing num in long long)
bool isPalindrome2(int num) 
    {
        if(num<0)
            return false;
        
        long long nnum=num,d,sum=0,cnt=0;

        while(nnum)
        {
            /*
            // checking if I really need to perform this 10 digit number check

            if(cnt==9)
            {
                if(sum-INT_MAX/10 >= 0)
                {
                    if(nnum%10 <= 7)
                    {
                        sum+=nnum%10;
                        break; 
                    }
                }
            }
            */

            d=nnum%10;
            sum=sum*10+d;
            nnum=nnum/10;
            ++cnt; // if cnt is i, then d will be i-th digit of nnum
        }

        if(sum==num)
            return true;

        return false;     
    }

// Here, I'm reversing only half the number, and storing num in long long 
bool isPalindrome3(int num) 
    {
        if(num<0)
        return false;

        if(num && num%10==0) // conditions: non-zero and ends with zero
        return false;
        // if the number ends with zero, to be a palindrome, it would also have to start with a zero

        if(num<10)
        return true;
        
        long long nnum=num,d,sum=0;
        // if we use 'long long' datatype then we don't need to perform the 10 digit number check

        while(nnum)
        {
            d=nnum%10;
            sum=sum*10+d;
            nnum=nnum/10;

            if( sum==nnum || (num>99 && sum==nnum/10 ) )
            // sum==nnum is for even no. of digits
            // sum==nnum/10 is for odd no. of digits
            return true;  
        }

        return false; 
    }
