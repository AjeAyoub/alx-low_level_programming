#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fdd);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: A pointer to the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
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
*This function closes the file descriptor specified by @fdd.
*/
void close_file(int fdd)
{
	int cc;

	cc = close(fdd);

	if (cc == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fdd %d\n", fdd);
		exit(100);
	}
}

/**
*main - Copies the contents of one file to another file.
*@argc: The number of arguments supplied to the program.
*@argv: An array of pointers to the arguments.
*Return: 0 on success, or a non-zero exit code on failure.
*Description: If the argument count is incorrect (i.e., not 3) - exit code 97.
*If file_from does not exist or cannot be read - exit code 98.
*If file_to cannot be created or written to - exit code 99.
*If an error occurs while closing a file - exit code 100.
*/
int main(int argc, char *argv[])
{
	int from, t, r, wr;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buff, 1024);
	t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
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

		r = read(from, buff, 1024);
		t = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buff);
	close_file(from);
	close_file(t);

	return (0);
}

