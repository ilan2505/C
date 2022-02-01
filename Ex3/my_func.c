#include <stdio.h>
#include "my_func.h"
#include <stdlib.h>
#include <string.h>
#define TXT 1024
#define WORD 30
#include <string.h>
int checker(char* str1,char* str2,int wordlen)
{
    int i,result=1;
    for(i=0; i<wordlen; i++) {
        if(*(str1+i) != *(str2+i)) {
            result=0;
            break;
        }
    }
    return result;
}
void swap(char *a, char *b )
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void sort(char* sort,int len)
{

    for (int i = 0; i <len- 1; i++)
    {
        for (int j = i + 1; j <len; j++)
        {
            if (*(sort+i) > *(sort+j))
            {
                swap(sort+i, sort+j);
        	}
        }
	}
}
int Gem(char* word,int wordlen)
{
	int counter=wordlen;
	int i;
	for(i=0;i<wordlen;i++)
	{
		char c=*(word+i);
		if(c<'z'&&c>'a')
		{
			counter+=(c-'a');
		}else if(c<'Z'&&c>'A')
		{
			counter+=(c-'A');	
		}		
	}
	return counter;

}
char* azba(char* word,char* azby1,int wordlen)
{
	int i;
	for(i=0;i<wordlen;i++)
	{
		if(*(word+i)>='a'&&(*(word+i))<='z')
		{
			*(azby1+i)='z'-(*(word+i)-'a');
		}else if(*(word+i)>='A'&&(*(word+i))<='Z')
		{
			*(azby1+i)='Z'-(*(word+i)-'A');
		
		}else
		{
		*(azby1+i)=*(word+i);
		}
		
	}


	return azby1;	
}
int trans(char* azby,char* word,int wordlen)
{

	char* trans2=malloc(sizeof(char)*wordlen);
		if(trans2==NULL)
		{
			printf("Memory not allocated.\n");
		}
	int i;
	for(i=0;i<wordlen;i++)
	{
		trans2[i]=*(azby+wordlen-1-i);
	}
	for(i=0;i<wordlen;i++)
	{
		*(word+i)=trans2[i];
	}
	free(trans2);
	return 0;
}
int f1(char* txt,int size,int sizetxt)
{
	int firstime=1;
	int i=0;
	int j=0;
	int s=0;
	int mat[sizetxt][sizetxt];
	for( i=0;i<sizetxt;i++)
	{

		if(txt[i]>='a'&&txt[i]<='z')
		{
		
			mat[0][i]=*(txt+i)-'a'+1+s;
			s=mat[0][i];
		}else if (txt[i]>='A'&&txt[i]<='Z')
		{
			mat[0][i]=*(txt+i)-'A'+1+s;
			s=mat[0][i];
		
		}else
		{
			mat[0][i]=mat[0][i-1];
		}
	}
	for( i=1;i<sizetxt;i++)
	{
		for( j=i;j<sizetxt;j++)
		{
			mat[i][j]=mat[i-1][j]-mat[i-1][i-1];		
		}
	}
	for( i=0;i<sizetxt;i++)
	{
		for( j=i;j<sizetxt;j++)
		{
			if(mat[i][j]==size&&mat[i][i]!=0)
			{
				if(firstime)
				{
					firstime=0;
					for(int j1=i;j1<=j;j1++)
					{
						if(mat[i][j1]>0){
							printf("%c",*(txt+j1));
						}
					}
					j=sizetxt;
				}else
				{
					printf("~");
					for(int j1=i;j1<=j;j1++)
					{
						if(mat[i][j1]>0){
							printf("%c",*(txt+j1));
						}
					}
					j=sizetxt;
				}
			}		
		}
	}
	printf("\n");
	return 0;
}
int f2(char* txt,char* azby,char* trans,int txtlen,int wordlen)
{


	char* azby3=(char*)malloc(wordlen);
	char* trans3=(char*)malloc(wordlen);
		if(azby3==NULL||trans3==NULL)
		{
			printf("Memory not allocated.\n");
		}
	char* check=(char*)malloc(txtlen);
	char* check1=(char*)malloc(wordlen);
	trans3=trans;
	azby3=azby;
	int countword=0;
	int coupoi=0;
	int firstime=1;
	int sizeal;
	for (int i=0;i<=txtlen-wordlen;i++)
	{
		check=(char*)malloc(txtlen);
		check1=(char*)malloc(wordlen);
		if(check==NULL||check1==NULL)
		{
			printf("Memory not allocated.\n");
		}
		countword=0;
		coupoi=0;
		sizeal=0;
		for(int j=i;j<=txtlen;j++)
		{
			if(countword<wordlen)
			{
				if(*(txt+i)!=','&&*(txt+i)!='\n'&&*(txt+j)!='\n')
				{
					*(check+coupoi++)=*(txt+j);
					*(check1+countword++)=*(txt+j);
				}else
				{
					check=(char*)realloc(check,wordlen+(++sizeal));
					*(check+coupoi++)=*(txt+j);
				}	
			}else
			{
				if(checker(check1,azby3,wordlen)||checker(check1,trans3,wordlen))
				{
					if(firstime){
						printf("%s",check);
						firstime=0;
					}else
					{
						printf("~%s",check);
					}
				}
				j=txtlen;
			}


		}
	}
	free(check);
	free(check1);	
	free(trans3);
	free(azby3);
	printf("\n");
	return 0;
}
int f3(char*txt,char* word,int wordlen,int txtlen)
{
	int firstime=1;
	char* check2=(char*)malloc(txtlen);
	char* check3=(char*)malloc(wordlen);
	char* sortword=(char*)malloc(wordlen);
	if(sortword==NULL)
	{
		printf("Memory not allocated.\n");
	}
	for(int i=0;i<wordlen;i++)
	{
		*(sortword+i)=*(word+i);
	}
	sort(sortword,wordlen);
	int countword=0;
	int coupoi=0;
	for (int i=0;i<=txtlen-wordlen;i++)
	{
		check2=(char*)malloc(txtlen);
		check3=(char*)malloc(wordlen);
		if(check2==NULL||check3==NULL)
		{
			printf("Memory not allocated.\n");
		}
		countword=0;
		coupoi=0;
		for(int j=i;j<txtlen;j++)
		{
			if(countword<wordlen)
			{
				if(*(txt+i)!=','&&*(txt+i)!='\t'&&*(txt+i)!='\n'&&*(txt+i)!='.')
				{
					*(check2+coupoi++)=*(txt+j);
					*(check3+countword++)=*(txt+j);
				}else if(coupoi!=0)
				{
					*(check2+coupoi++)=*(txt+j);
				}
				
			}else
			{
				j=txtlen;

			}
			if(countword==wordlen)
			{
				j=txtlen;
				sort(check3,wordlen);	
				if(checker(check3,sortword,wordlen))
				{
					if(firstime){
						printf("%s",check2);
						firstime=0;
					}else
					{
						printf("~%s",check2);
					}
				}
			}
		}
	}
	free(check2);
	free(check3);
	free(sortword);
	return 0;	
}
