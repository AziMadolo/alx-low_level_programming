#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error_exit(const char *message, int exit_code);

/**
 * create_buffer - Allocates BUFFER_SIZE bytes for a buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(void)
{
	char *buffer = malloc(sizeof(char) * BUFFER_SIZE);

	if (buffer == NULL)
		error_exit("Error: Failed to allocate memory for buffer\n", 99);

	return buffer;
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
		error_exit("Error: Failed to close file descriptor\n", 100);
}

/**
 * error_exit - Prints an error message and exits with the specified code.
 * @message: The error message to be printed.
 * @exit_code: The exit code to be used.
 */
void error_exit(const char *message, int exit_code)
{
	dprintf(STDERR_FILENO, "%s", message);
	exit(exit_code);
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
		error_exit("Usage: cp file_from file_to\n", 97);

	buffer = create_buffer();

	from = open(argv[1], O_RDONLY);
	if (from == -1)
		error_exit("Error: Failed to open source file\n", 98);

	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
	{
		free(buffer);
		error_exit("Error: Failed to create or write to destination file\n", 99);
	}

	while ((r = read(from, buffer, BUFFER_SIZE)) > 0)
	{
		if (r == -1)
		{
			free(buffer);
			error_exit("Error: Failed to read from source file\n", 98);
		}

		w = write(to, buffer, r);
		if (w == -1)
		{
			free(buffer);
			error_exit("Error: Failed to write to destination file\n", 99);
		}
	}

	free(buffer);
	close_file(from);
	close_file(to);

	return 0;
}
