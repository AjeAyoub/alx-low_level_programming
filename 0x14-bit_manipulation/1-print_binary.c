#include <stdio.h>
#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: Number to be printed in binary
 */
void print_binary(unsigned long int n)
{
	/* Bit manipulation loop */
	unsigned long int mask = 1UL << ((sizeof(unsigned long int) * 8) - 1);

	while (mask > 0)
	{
		/* Use bitwise AND to get the value of the current bit */
		unsigned long int bit = n & mask;

		/* If the current bit is 0, print 0. Otherwise, print 1. */
		if (bit == 0)
			putchar('0');
		else
			putchar('1');

		/* Shift the mask one bit to the right */
		mask = mask >> 1;

	}
}
