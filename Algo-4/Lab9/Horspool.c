#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* ShiftTable(char* pattern, int pattern_len)
{
	int* table=(int*)calloc(256,sizeof(int));
	for(int i=0; i<256; i++) table[i]=pattern_len;
	for(int j=0; j<pattern_len-1; j++) table[pattern[j]]=pattern_len-1-j;

	return table;
}

int Horspool(char* pattern, char* text)
{
	int pattern_len=strlen(pattern);
	int text_len=strlen(text);
	int* BSTable=ShiftTable(pattern, pattern_len);
	int i=pattern_len-1; int comparsions=0;

	while(i<text_len)
	{
		int k=0;
		while(k<pattern_len && pattern[pattern_len-1-k]==text[i-k]) 
		{
			k++;
			comparsions++;
		}
		comparsions++;

		if(k==pattern_len) 
		{
			printf("Comparions: %d\n", comparsions-1);
			return i-pattern_len+1;
		}
		else i=i+BSTable[text[i]];
	}
	printf("Comparions: %d\n", comparsions);
	return -1;
}

int main()
{
	char* text; char* pattern;
	text=(char*)malloc(sizeof(char)*100);
	pattern=(char*)malloc(sizeof(char)*100);

	printf("Enter text: ");
	fgets(text, 100, stdin);
	text[strlen(text)-1]='\0';

	printf("Enter pattern: ");
	fgets(pattern, 100, stdin);
	pattern[strlen(pattern)-1]='\0';

	int index=Horspool(pattern, text);
	if(index==-1) printf("Pattern not found.\n");
	else printf("Pattern found at index: %d\n", index);
}