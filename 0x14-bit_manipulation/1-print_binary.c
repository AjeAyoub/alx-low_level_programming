#include <stdio.h>
#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 *
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	int i, cnt = 0;
	unsigned long int current;

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;

		if (current & 1)
		{
			_putchar('1');
			cnt++;
		}
		else if (cnt)
			_putchar('0');
	}
	if (!cnt)
		_putchar('0');
}

