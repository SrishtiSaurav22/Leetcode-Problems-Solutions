int strStr(string haystack, string needle) 
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
