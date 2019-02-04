#include <stdio.h>

char *p_napis = "Alabama";

int main()
{
	while(*p_napis)
	{
		p_napis++;
	}
	p_napis--;
	
	while(*p_napis)
	{
		printf("%c", *p_napis);
		p_napis--;
	}
	
	return 0;
}
