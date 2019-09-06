#include "stdio.h"
#include "./get_next_line/get_next_line.h"

int main(void)
{
	char *str;
	while(1)
	{get_next_line(STDIN_FILENO, &str);
	printf("%s", str);
	free(str);}
	return(0);
}