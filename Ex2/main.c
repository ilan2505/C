
#include <stdio.h>
#include "my_mat.h"
#include <stdbool.h>
#define Size 10

int main()
{
	char p;
	int mymat[Size][Size];
	int *ptr=&mymat[0][0];
	 do{
		scanf("%c",&p); 
		if(p=='A')
		{
			fastest(ptr);
		}
		if(p=='B')
		{
			f2(ptr);
		}
		if(p=='C')
		{
			f3(ptr);
		}
	}while(p!='D');
}


