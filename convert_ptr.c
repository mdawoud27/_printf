#include "header.h"

/**
 * convert_and_append_ptr - Converts and appends a pointer value to the buffer in hexadecimal format.
 * @ptr: The pointer value to be converted and appended.
 */
void convert_and_append_ptr(uintptr_t ptr)
{
	append_to_buffer('0');
	append_to_buffer('x');

	char hexValue[16]; // Buffer to store hexadecimal characters
	int index = 15;

	while (ptr > 0)
	{
		int remainder = ptr % 16;
		if (remainder < 10)
		{
			hexValue[index] = remainder + '0';
		}
		else
		{
			hexValue[index] = remainder - 10 + 'a';
		}
		ptr /= 16;
		index--;
	}

	// Print the hexadecimal characters
	for (int i = index + 1; i < 16; i++)
	{
		append_to_buffer(hexValue[i]);
	}
}