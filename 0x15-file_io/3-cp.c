#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fdd);


/**
*create_buffer - Allocates 1024 bytes of memory for a buffer.
*@file: The name of the file for which the buffer is storing characters.
*Return: A pointer to the newly-allocated buffer.
*/
char *create_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
*close_file - Closes a file descriptor.
*@fdd: The file descriptor to be closed.
*Return: 0 on success, -1 on failure.
*/
void close_file(int fdd)
{
	int c;

	c = close(fdd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fdd %d\n", fdd);
		exit(100);
	}
}

/**
*main - Copies the contents of a file to another file.
*@argc: The number of arguments supplied to the program.
*@argv: An array of pointers to the arguments.
*Return: 0 on success.
*Description: If the argument count is incorrect - exit code 97.
*If file_from does not exist or cannot be read - exit code 98.
*If file_to cannot be created or written to - exit code 99.
*If file_to or file_from cannot be closed - exit code 100.
*/
int main(int argc, char *argv[])
{
	int frm, t, r, wr;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	frm = open(argv[1], O_RDONLY);
	r = read(frm, buff, 1024);
	t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (frm == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		wr = write(t, buff, r);
		if (t == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		r = read(frm, buff, 1024);
		t = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buff);
	close_file(frm);
	close_file(t);

	return (0);
}

