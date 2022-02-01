#include <stdio.h>
#include <stdlib.h>
#include "my_func.h"
#define TXT 1024
#define WORD 30

int main()
{
	char* word=(char*)malloc(WORD*sizeof(char));
	char* txt=(char*)malloc(TXT*sizeof(char));
		if(word==NULL||txt==NULL)
		{
			printf("Memory not allocated.\n");
		}
	int wordlen=0;
	int txtlen=0;
	int i=0;
	char c;
	int gem=0;
	scanf("%c",&c);
	while(c!=','&&c!='\t'&&c!='\n')
	{
		wordlen++;
		*(word+i++)=c;
		scanf("%c",&c);		
	}
	i=0;
	scanf("%c",&c);
	while(c!='~')
	{
		*(txt+i++)=c;	
		scanf("%c",&c);
		txtlen++;
	}
	gem=Gem(word,wordlen);
	printf("Gematria Sequences: ");
	f1(txt,gem,txtlen);
	char* azby1=(char*)malloc(wordlen*sizeof(char));
	char* trans1=(char*)malloc(wordlen*sizeof(char));
		if(azby1==NULL||trans1==NULL)
		{
			printf("Memory not allocated.\n");
		}
	azba(word,azby1,wordlen);
	trans(azby1,trans1,wordlen);
	printf("Atbash Sequences: ");
	f2(txt,azby1,trans1,txtlen,wordlen);
	printf("Anagram Sequences: ");
	f3(txt,word,wordlen,txtlen);
	free(word);
	free(txt);
	return 0;
}
