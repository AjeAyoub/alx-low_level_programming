#include "main.h"
#include <stdlib.h>

/**
*
*read_textfile - Reads a text file and prints its contents to STDOUT.
*@filename: The name of the file to read.
*@letters: The number of letters to be read and printed.
*Return: The actual number of bytes read and printed. Returns 0 if the function fails or if the filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t fdd;
	ssize_t wr;
	ssize_t t;

	fdd = open(filename, O_RDONLY);
	if (fdd == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	t = read(fdd, buff, letters);
	wr = write(STDOUT_FILENO, buff, t);

	free(buff);
	close(fdd);
	return (wr);
}

