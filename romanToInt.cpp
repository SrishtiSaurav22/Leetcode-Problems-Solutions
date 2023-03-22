/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

EXAMPLE 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

EXAMPLE 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

EXAMPLE 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 
Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/

// APPROACH 1
// Longer runtime
int countStringLengthManually(string str)
    {
        int i, cnt=0;
        
        for(i=0;str[i]!='\0';i++)
        ++cnt;

        return cnt;
    }
    
    int romanToInt(string str) 
    {
        int i=str.length()-1;
        int sum=0;

    while(i>=0)
    {
        if(str[i]=='I')
        {
            sum=sum+1;
            --i;
        }

        // V, X special case
        else if(str[i]=='V')
        {
            if(i-1>=0 && str[i-1]=='I')
            {
                sum=sum+4;
                i-=2;
            }

            else
            {
                sum=sum+5;
                --i;
            }
        }

        else if(str[i]=='X')
        {
            if(i-1>=0 && str[i-1]=='I')
            {
                sum=sum+9;
                i-=2;
            }

            else
            {
                sum=sum+10;
                --i;
            }
        }

        // L, C special case
        else if(str[i]=='L')
        {
            if(i-1>=0 && str[i-1]=='X')
            {
                sum=sum+40;
                i-=2;
            }

            else
            {
                sum=sum+50;
                --i;
            }
        }

        else if(str[i]=='C')
        {
            if(i-1>=0 && str[i-1]=='X')
            {
                sum=sum+90;
                i-=2;
            }

            else
            {
                sum=sum+100;
                --i;
            }
        }

        // D, M special case
        else if(str[i]=='D')
        {
            if(i-1>=0 && str[i-1]=='C')
            {
                sum=sum+400;
                i-=2;
            }

            else
            {
                sum=sum+500;
                --i;
            }
        }

        else if(str[i]=='M')
        {
            if(i-1>=0 && str[i-1]=='C')
            {
                sum=sum+900;
                i-=2;
            }

            else
            {
                sum=sum+1000;
                --i;
            }
        }
    }

    return sum;
    }

// APPROACH 2
// Shorter runtime
int val(char ch)
    {
        switch(ch)
        {
            case 'I':
            return 1;

            case 'V':
            return 5;

            case 'X':
            return 10;

            case 'L':
            return 50;

            case 'C':
            return 100;

            case 'D':
            return 500;

            case 'M':
            return 1000;

            default:
            return 0;
        }
    }

    int romanToInt(string s) 
    {
        int n=s.size(),sum=0;

        for(int i=0;i<n;i++)
        {
            if( val(s[i]) < val(s[i+1]) )
            {
                sum=sum+val(s[i+1])-val(s[i]);
                ++i;
            }

            else
            {
                sum=sum+val(s[i]);
            }
        }

        return sum;
    }

// NB

/*
Here, there's no segmentation fault or any exception thrown when i+1 is beyond the string length (in the if condition). 
This is because [] operator does not perform bound checks, so compiles and runs successfully, while string.at(integer_index) does perform bound checks, compiling succesfully but throwing runtime exception. 

EXAMPLE:
string str="XIV";
cout<<str[6]<<endl; // compiles and runs successfully
cout<<str.at(6)<<endl; // compiles successfully but throws runtime exception
*/
