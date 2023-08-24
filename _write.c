#include "header.h"

#define BUFFER_SIZE 1024

char buffer[BUFFER_SIZE];
int buffer_index = 0;

/**
 * flush_buffer - func writes the contents of the buffer to the standard output
 */
void flush_buffer()
{
	write(STDOUT_FILENO, buffer, buffer_index);
	buffer_index = 0;
}

/**
 * append_to_buffer - add a character `c` to the buffer in the `_printf()` implementation
 *
 * @c: character you would to print.
 */
void append_to_buffer(char c)
{
	if (buffer_index >= BUFFER_SIZE - 1)
		flush_buffer();

	buffer[buffer_index++] = c;
}