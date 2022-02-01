#include <math.h>
#include "NumClass.h"

int isArmstrong(int x) {
	int ans=0;
	int y=log10(x);
	int m=pow(10,y);
   
	for (int i = 0; i <=y; i++)
	{
      		int t=pow(10,i);
        	int ch=x%(10*t);
        	ch=ch/t;
      		ans+=pow(ch,y+1);
	}
  
	if (x==ans)
   	{
   		return 1;
   	}
   return 0;
}
int isPalindrome(int x){
    int ans=0;
    int y=log10(x)+1;
    int m=pow(10,y-1);
    int t=x;
 
   for (int i = 0; i <y/2; i++)
   {
 	int len= pow(10,i);
        int s=x/(m/len);
        s=s%10;
        int e=x%(10*len);
        e=e/len;
        if (s!=e)
        {
            return 0;
        }
        
   }
   
       return 1;
}  
   
