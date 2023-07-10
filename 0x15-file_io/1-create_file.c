#include "main.h"

/**
 * create_file - Creates a file and writes content to it.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function succeeds, returns 1.
 *         If an error occurs, returns -1.
 */
int create_file(const char *filename, const char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	w = write(fd, text_content, len);
	if (w == -1 || w != len)
	{
		close(fd);
		return (-1);
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}
