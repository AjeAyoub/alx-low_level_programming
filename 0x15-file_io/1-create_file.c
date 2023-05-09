#include "main.h"

/**
*create_file - Creates a file with the specified name and writes the content to it.
*@filename: A pointer to the name of the file to create.
*@text_content: A pointer to a string to write to the file.
*Return: On success, returns 1. On failure, returns -1.
*/
int create_file(const char *filename, char *text_content)
{
	int fdd, wr, ln = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (ln = 0; text_content[ln];)
			ln++;
	}

	fdd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(fdd, text_content, ln);

	if (fdd == -1 || wr == -1)
		return (-1);

	close(fdd);

	return (1);
}

