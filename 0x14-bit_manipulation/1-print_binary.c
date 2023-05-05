#include <stdio.h>
#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 *
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;

	mask <<= (sizeof(unsigned long int) * 8 - 1);

	while (mask > 0)
	{
		if (n & mask)
			putchar('1');
		else
			putchar('0');

		mask >>= 1;
	}
}
