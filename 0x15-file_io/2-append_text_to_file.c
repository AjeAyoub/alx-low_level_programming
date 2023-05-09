#include "main.h"

/**
*append_text_to_file - Appends text to the end of a file.
*@filename: A pointer to the name of the file to append to.
*@text_content: A pointer to the text to append.
*Return: On success - 1.
*On failure - (-1).
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int o, wr, ln = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (ln = 0; text_content[ln];)
			ln++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	wr = write(o, text_content, ln);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}

