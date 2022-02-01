#include <stdio.h>
#include "NumClass.h"
int main()
{
	int s;
	int e;
	scanf("%d",&s);
	scanf("%d",&e);
	printf("The Armstrong numbers are:");
	for (int i = s; i <= e; i++)
    	{
        	if (isArmstrong(i)==1)
            	{
                	printf(" %d",i);
            	}     
    	}
    	printf("\n");
     	printf("The Palindromes are:");
    	for (int i = s; i <= e; i++)
    	{
        	if (isPalindrome(i)==1)
            	{
                	printf(" %d",i);
            	}     
    	}
    	printf("\n");
     	printf("The Prime numbers are:");
    	for (int i = s; i <= e; i++)
    	{
        	if (isPrime(i)==1)
            	{
               	 printf(" %d",i);
            	}     
    	}
    	printf("\n");
        printf("The Strong numbers are:");
    	for (int i = s; i <= e; i++)
    	{
        	if (isStrong(i)==1)
            	{
                	printf(" %d",i);
            	}     
    	}
    	printf("\n");
    	return 0;
    
}
