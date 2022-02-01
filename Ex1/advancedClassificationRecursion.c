#include <math.h>
#include "NumClass.h"

int checkArmstrong(int x,int y,int len)
{
    if (x<10)
    {
        return pow(x,y);
    } 
    return pow(x%10,y)+checkArmstrong(x/10,y,len/10);
}
int isArmstrong(int x) 
{
    int sum=0;
    int i=1;
    if (x<10)
    {
        return 1;
    }
    for( i=1;i<=x;i*=10)
    {
       sum++;
    }
    return (x==checkArmstrong(x,sum,i/10));       
}
int helpPal(int x){
 	if (x==0)
    	{
        	return 0;    
        }
	int len=log10(x);
   	return (x%10*pow(10,len))+helpPal(x/10);  
}
 int isPalindrome(int x){
 	if (x<10)
     	{
  		return 1;
     	}
     	int t=helpPal(x);
     	if (x==t)
     	{
     		return 1;
     	}      
	return 0;
}
