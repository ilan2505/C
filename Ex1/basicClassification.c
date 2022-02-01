#include <math.h>
#include "NumClass.h"

int isPrime(int x)
{    
	for( int i=2;i<x;i++)
    	{
    		if(x%i==0)
    		{
      			return 0;
    		}
	}
    	return 1;
}
int HelpFunc(int x)
{
	int ans=1;
     	while (x>1)
     	{
		ans*=x;
       	x--;
	}
	return ans;      
}
 
int isStrong(int x){
	int ans=0;
  	 int t=x;
   	while (t>0){
   		ans+=HelpFunc(t%10); 
   		t=t/10; 
   	}
   	if (x==ans)
   	{
      		return 1;
   	}
   	return 0;
}

   

  
