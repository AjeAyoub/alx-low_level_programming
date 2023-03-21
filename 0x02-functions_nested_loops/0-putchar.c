#include <stdio.h>
#include <unistd.h>
int main(void)
{
	write(STDOUT_FILENO,"_putchar",8);
	return(0);
}

