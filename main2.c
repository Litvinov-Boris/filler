#include "stdio.h"
#include "unistd.h"
int main(void)
{
	char str[7];
	str[6] = '\0';
	read(0, str, 6);
	printf("%s\n", str);
	return (0);
}