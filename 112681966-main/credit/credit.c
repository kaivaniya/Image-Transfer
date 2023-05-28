#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>

int main(void)
{

  //taking input of credit card number from user
  string cc = get_string("enter the cc number \n ");

  char c;
  int cnt=0 , sum , mul , ext;


  int len = strlen(cc);

  while(len>0)
  {
    c=cc[len-1];
    if(isdigit(c))
    {
        int ext = atoi(&c);

        cnt++;
        if(cnt%2==0)
        {
          mul=ext*2;
          sum=sum+mul;

        }
    }
    len--;
  }
  cnt=0;
 len = strlen(cc);
 while(len>0)
  {
    c=cc[len-1];
    if(isdigit(c))
    {
        int ext = atoi(&c);
        cnt++;
        if(cnt%2!=0)
        {
            sum=sum+ext;
        }
    }
    len--;
  }
 int rem=sum%10;
 if(rem==0)
  {
    printf("congralutions!!!!!! your credit card number is RIGHT \n ");
  }
else
  {
    printf("you fraud your credit card number is wrong \n ");
  }
}