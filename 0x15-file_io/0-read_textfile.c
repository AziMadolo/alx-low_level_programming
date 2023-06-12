#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
*read_textfile - Read a text file and print its contents to STDOUT.
*@filename: The name of the text file to be read.
*@letters: The number of letters to be read.
*Return: The actual number of bytes read and printed.
*0 if the function fails or if the filename is NULL.
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
char *buf;
ssize_t bytesRead, bytesWritten, totalBytesRead;

if (filename == NULL)
	return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
	return (0);

buf = malloc(sizeof(char) * letters);
if (buf == NULL)
{
	close(fd);
	return (0);
}

bytesRead = read(fd, buf, letters);
if (bytesRead == -1)
{
	free(buf);
	close(fd);
	return (0);
}

bytesWritten = write(STDOUT_FILENO, buf, bytesRead);
if (bytesWritten == -1 || bytesWritten != bytesRead)
{
	free(buf);
	close(fd);
	return (0);
}

totalBytesRead = bytesRead;

free(buf);
close(fd);

return (totalBytesRead);
}

