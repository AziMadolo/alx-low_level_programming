#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - returns -1.
 *         If the file does not exist or the user lacks write permissions - returns -1.
 *         Otherwise, returns 1.
 */
int append_text_to_file(const char *filename, const char *text_content)
{
	int file_descriptor, bytes_written, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length])
			length++;
	}

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (-1);

	bytes_written = write(file_descriptor, text_content, length);
	if (bytes_written == -1)
	{
		close(file_descriptor);
		return (-1);
	}

	if (close(file_descriptor) == -1)
		return (-1);

	return (1);
}
