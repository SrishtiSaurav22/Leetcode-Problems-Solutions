/*
 Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

 Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 EXAMPLE 1:
 Input: x = 123
 Output: 321

 EXAMPLE 2:
 Input: x = -123
 Output: -321

 EXAMPLE 3:
 Input: x = 120
 Output: 21

Constraints:
-231 <= x <= 231 - 1
*/

#include<bits/stdc++.h>
#include<typeinfo>

using namespace std;

/*
 INT_MIN:
 -2^31:
 -2147483648

 INT_MAX:
 (2^31)-1:
 2147483647
*/

int reverseInteger(int num)
{
    int nnum,d,sum=0;
    int c=0;

    if(num<0) nnum=num*-1;
    else nnum=num;

    while(nnum)
    {
        if((++c)==10) // the sum is 9 digits long now, about to be made 10 digits in this 10th iteration
        {
            int diff=INT_MAX/10-sum;

            if(diff<0)
                return 0;

            else
            {
                if(nnum%10>7)
                    return 0;

                else
                {
                    sum=sum*10+d;
                    break;
                }
            }
        }

        d=nnum%10;
        sum=sum*10+d;
        nnum=nnum/10;
    }

    if(num<0) return sum*-1;
    else return sum;
}

int main()
{
    int num=-2147483412;

    cout<<"Original number: "<<num<<endl;
    cout<<"Reversed number: "<<reverseInteger(num)<<endl;

    cout<<endl;
    return 0;
}
