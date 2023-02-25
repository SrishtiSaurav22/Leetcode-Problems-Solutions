int reverse(int num) 
    {
    int nnum;
    int d,sum=0;
    int c=0;

    if(num>INT_MAX || num<INT_MIN)
        return 0;

    if(num==INT_MIN) return 0; 

    // this should be 'else if' but the previous 'if' returns 0, so it's fine
    if(num<0) nnum=num*(-1);
    else nnum=num;

    while(nnum)
    {
        if((++c)==10) // the sum is 9 digits long now, about to be made 10 digits in this 10th iteration
        {
            int diff=(INT_MAX/10)-sum;

            if(diff<0)
                return 0;

            else
            {
                if((nnum%10)>7)
                    return 0;

                else
                {
                    d=nnum%10;
                    sum=(sum*10)+d;
                    break;
                }
            }
        }

        d=nnum%10;
        sum=sum*10+d;
        nnum=nnum/10;
    }

    if(num<0) return sum*(-1);
    else return sum;
        
    }
