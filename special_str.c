#include "header.h"

/**
 * print_special_string - Prints a special string with non-printable characters represented in hexadecimal.
 * @str: The input string to be processed and printed.
 *
 * This function processes each character in the input string and appends it to the output buffer. If the
 * character is a printable ASCII character, it is directly appended. If the character is non-printable, it
 * is converted to its hexadecimal representation and then appended to the buffer.
 */
void print_special_string(const char *str)
{
	while (*str != '\0')
	{
		if (*str >= 32 && *str < 127)
		{
			append_to_buffer(*str);
		}
		else
		{
			convert_and_append((unsigned int)*str, 16, 1);
		}
		str++;
	}
}

/**
 * apply_rot13 - Applies the ROT13 encryption algorithm to a string.
 * @str: The input string to be encrypted using ROT13.
 *
 * This function iterates through each character in the input string and applies the ROT13 transformation to it.
 * If the character is a lowercase letter ('a' to 'z'), it is replaced with the letter 13 positions ahead in the
 * alphabet. If the character is an uppercase letter ('A' to 'Z'), the same transformation is applied. Other
 * characters (digits, symbols, spaces, etc.) remain unchanged.
 */
void apply_rot13(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		char c = str[i];
		if ('a' <= c && c <= 'z')
		{
			str[i] = 'a' + (c - 'a' + 13) % 26;
		}
		else if ('A' <= c && c <= 'Z')
		{
			str[i] = 'A' + (c - 'A' + 13) % 26;
		}
	}
}

/**
 * handle_length_modifiers_str - Handles formatting of a string with length modifiers and flags.
 * @str: The input string to be formatted.
 * @flag_plus: Flag indicating the use of the '+' flag.
 * @flag_space: Flag indicating the use of the ' ' (space) flag.
 * @flag_hash: Flag indicating the use of the '#' flag.
 * @flag_minus: Flag indicating the use of the '-' flag.
 * @flag_long: Flag indicating the use of the 'l' length modifier.
 * @flag_short: Flag indicating the use of the 'h' length modifier.
 * @field_width: The specified field width for formatting.
 * @precision: The specified precision for formatting.
 * @conversion_specifier: The conversion specifier character.
 *
 * This function handles the formatting of a string based on the provided length modifiers and flags. It calculates
 * the required padding and alignment based on the parameters and prints the formatted string to the output buffer.
 */
void handle_length_modifiers_str(const char *str, bool flag_plus, bool flag_space, bool flag_hash,
								 bool flag_minus, bool flag_long, bool flag_short, int field_width, int precision,
								 char conversion_specifier)
{
	bool flag_zero = false;
	int length = strlen(str);
	bool adjust_precision = false;

	if (precision >= 0 && precision < length)
	{
		length = precision;
		adjust_precision = true;
	}

	int total_width = length;

	if (field_width > total_width)
	{
		int padding_width = field_width - total_width;

		if (flag_minus)
		{
			// Left-justified, so print the string first
			for (int i = 0; i < length; i++)
			{
				append_to_buffer(str[i]);
			}

			// Fill the remaining space with spaces
			for (int i = 0; i < padding_width; i++)
			{
				append_to_buffer(' ');
			}
		}
		else
		{
			if (flag_zero && !adjust_precision)
			{
				// Zero-padding, so print leading zeros and the string
				for (int i = 0; i < padding_width; i++)
				{
					append_to_buffer('0');
				}
			}
			else
			{
				// Right-justified, so fill with spaces first
				for (int i = 0; i < padding_width; i++)
				{
					append_to_buffer(' ');
				}
			}

			// Print the string content
			for (int i = 0; i < length; i++)
			{
				append_to_buffer(str[i]);
			}
		}
	}
	else
	{
		// No padding needed, just print the string content
		for (int i = 0; i < length; i++)
		{
			append_to_buffer(str[i]);
		}
	}
}

/**
 * convert_int_to_str - Converts an integer to its string representation.
 * @num: The integer to be converted.
 * @str: The buffer to store the resulting string.
 *
 * This function converts the given integer to its string representation and stores it in the provided buffer.
 * It handles negative numbers, zero values, and ensures the correct order of digits in the string.
 *
 * Returns: The length of the resulting string.
 */
int convert_int_to_str(int num, char *str)
{
	int length = 0;
	int original_num = num;

	// Handle negative numbers
	if (num < 0)
	{
		num = -num;
		str[length++] = '-';
	}
	else if (num == 0)
	{
		str[length++] = '0';
	}

	// Convert each digit to a character
	while (num > 0)
	{
		int digit = num % 10;
		str[length++] = '0' + digit;
		num /= 10;
	}

	// Reverse the string
	reverse_str(str, length);

	// Null-terminate the string
	str[length] = '\0';

	return length;
}

/**
 * convert_frac_to_str - Converts the fractional part of a double to its string representation.
 * @frac: The fractional part of the double value.
 * @str: The buffer to store the resulting string.
 * @precision: The number of digits after the decimal point to convert.
 *
 * This function converts the fractional part of the given double value to its string representation
 * and stores it in the provided buffer. It converts each digit of the fractional part to a character
 * and respects the specified precision (number of digits after the decimal point).
 *
 * Returns: The length of the resulting string.
 */
int convert_frac_to_str(double frac, char *str, int precision)
{
	int length = 0;

	// Convert each digit of the fractional part to a character
	while (precision > 0)
	{
		frac *= 10.0;
		int digit = (int)frac;
		str[length++] = '0' + digit;
		frac -= digit;
		precision--;
	}

	// Null-terminate the string
	str[length] = '\0';

	return length;
}

/**
 * reverse_str - Reverses the characters in a string.
 * @str: The string to be reversed.
 * @length: The length of the string.
 *
 * This function reverses the characters in the given string. It swaps characters from the beginning
 * and end of the string until the middle is reached, effectively reversing the string in place.
 */
void reverse_str(char *str, int length)
{
	for (int i = 0, j = length - 1; i < j; i++, j--)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
