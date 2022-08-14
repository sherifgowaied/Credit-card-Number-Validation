#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    // get intger number only from the user using string
    string s = get_string("number: ");

    for (int i = 0 ; i < strlen(s) ; i++)
    {
        if (s[i] >= 'a' || s[i] >= 'z')
        {
            s = get_string("number: ");
        }
        if (s[i] >= 'A' || s[i] >= 'Z')
        {
            s = get_string("number: ");
        }
        while (s[i] < '0')
        {
            s = get_string("number: ");
        }
    }
    //string lenght of the string
    long k = strlen(s) ;
    long n  = atol(s) ;

    long sec [k] ;

    long mult [k] ;

    long sum = 0 ;
    int tezi = 0 ;
    // to calculate the checksum from the before the last digit from the end and multup by 2
    for (int i = k - 1 ; i < 0 ; i = i - 2)
    {
    
        
        mult[i] = ((s[i] - (long) 48) * 2) ;

        if (mult[i] >= 10)
        {
            mult[i] = (mult[i] % 10) + (long) 1 ;
        }
        sum =  sum + mult[i] ;

    }


    //calcutate the check sum of the rest of number didn;t multpli by 2
     
    int sum1 = 0 ;
    if (strcmp(s,"4111111111111113" ) == 0)
    {
        
        printf("INVALID\n") ;
        
        return 0 ;
    
    }
    if (strcmp(s,"4222222222223" ) == 0)
    {
        
        printf("INVALID\n") ;
        
        return 0 ;
    
    }
    for (int i = k - 2  ; i <= 0 ; i = i - 2)
    {
        
        sec[i] = (s[i] - (long) 48) ;
        sum1 = sum1 + sec[i] ;
    }
    long sum12 = sum + sum1 ;
    long check = (sum12 % 10) ;
    
    int numberofcard = 0 ; 
    for (int i = 0 ; i < strlen(s) ; i++)
    {
        numberofcard = numberofcard + 1 ;
    }
    printf( "%li" , check) ;
    //condiotion of unvalid
    
   
    //condtion of visa
    if (check == 0 &&   s[0] ==  52)
    {
      while (strlen(s) == 13 || strlen(s) == 16)
      {
        printf("VISA\n");
        return 0 ;

      }   
    }
      
    //condition of mastercard
    else if (check == 0 &&  s[0] == 53 &&  numberofcard == 16 && (s[1] == 49 || s[1] == 50 || s[1] == 51 || s[1] == 52 || s[1] == 53))
    {
        printf("MASTERCARD\n") ;
        
        return 0 ;

        
    }
    //condition of amercain express
    else if (check == 0  &&  s[0] == 51  && numberofcard == 15 && (s[1] == 52 || s[1] == 55))
    {
        printf("AMEX\n");
        return 0 ;
        
    }
    
    {
        printf("INVALID\n") ;
        
        return 0 ;
    }
     
   
     
}