string oneTo9(int num)
    {
        int i;

        string strcur="";

        if(num>=1 && num<=3)
        {
            for(i=0;i<num;i++)
            strcur=strcur+"I";
        }

        else if(num==4)
        strcur="IV";

        else if(num>=5 && num<=8)
        {
            strcur="V";

            for(i=0;i<num-5;i++)
            strcur=strcur+"I";
        }

        else if(num==9)
        strcur="IX";

        return strcur;
    }

    string tenTo99(int num)
    {
        int i;

        string strcur="";

        int d=num%10;
        int q=num/10;

        // finding remDigit
        string remDigit=oneTo9(d);
        
        // finding mainDigit
        if(q>=1 && q<=3)
        {
            for(i=0;i<q;i++)
            strcur=strcur+"X";
        }

        else if(q==4)
        {
            strcur="XL";
        }

        else if(q>=5 && q<=8)
        {
            strcur="L";

            for(i=0;i<q-5;i++)
            strcur=strcur+"X";
        }

        else if(q==9)
        {
            strcur="XC";
        }

        string mainDigit=strcur;

        return mainDigit+remDigit;
    }

    string hundredTo999(int num)
    {
        int i;
        
        string strcur="";
        
        int d=num%100;
        int q=num/100;

        // finding remDigit
        string remDigit=tenTo99(d);

        // finding mainDigit
        if(q>=1 && q<=3)
        {
            for(i=0;i<q;i++)
            strcur=strcur+"C";
        }

        else if(q==4)
        {
            strcur="CD";
        }

        else if(q>=5 && q<=8)
        {
            strcur="D";

            for(i=0;i<q-5;i++)
            {
                strcur=strcur+"C";
            }
        }

        else if(q==9)
        {
            strcur="CM";
        }

        string mainDigit=strcur;

        return mainDigit+remDigit;
    }

    string thousandTo3999(int num)
    {
        int i;

        string strcur="";

        int d=num%1000;
        int q=num/1000;

        // finding remDigit
        string remDigit=hundredTo999(d);

        // finding mainDigit
        for(i=0;i<q;i++)
        {
            strcur=strcur+"M";
        }

        string mainDigit=strcur;

        return mainDigit+remDigit;
    }

    string intToRoman(int num) 
    {
        if(num<10)
        return oneTo9(num);

        else if(num<100)
        return tenTo99(num);

        else if(num<1000)
        return hundredTo999(num);

        else
        return thousandTo3999(num);

        return "";
    }
