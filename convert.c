#include "header.h"

/**
 * convert - Converts a number to a specified base representation.
 * @num: The number to be converted.
 * @base: The base of the desired representation.
 * @uppercase: Indicates whether to use uppercase letters for hexadecimal (1) or not (0).
 *
 * Return: A pointer to the resulting string representing the number in the specified base.
 */
char *convert(unsigned int num, int base, int uppercase)
{
    static char Representation[] = "0123456789abcdef";
    static char RepresentationUpper[] = "0123456789ABCDEF";
    char *rep = (uppercase) ? RepresentationUpper : Representation;

    static char num_buffer[50];
    char *ptr = &num_buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = rep[num % base];
        num /= base;
    } while (num != 0);

    return ptr;
}

/**
 * convert_and_append - Converts and appends a number to its hexadecimal representation.
 * @num: The number to be converted and appended.
 * @base: The base for the conversion (e.g., 16 for hexadecimal).
 * @uppercase: Indicates whether to use uppercase letters for hexadecimal (1) or not (0).
 *
 * This function converts the given number to its hexadecimal representation and appends it
 * to the output buffer. If the resulting value is less than 16, it adds a '0' character as the
 * most significant digit.
 */

void convert_and_append(unsigned int num, int base, int uppercase)
{
    static char hexValue[3]; // Static buffer for the hexadecimal representation
    hexValue[0] = (num / base < 16) ? '0' : '\0';
    hexValue[1] = (num / base < 16) ? "0123456789ABCDEF"[num % base] : '\0';
    hexValue[2] = '\0';

    if (hexValue[0] != '\0')
    {
        append_to_buffer('\\');
        append_to_buffer('x');
        append_to_buffer(hexValue[0]);
        append_to_buffer(hexValue[1]);
    }
}

/**
 * convert_to_hex - Converts an unsigned integer to its hexadecimal representation.
 * @num: The number to be converted.
 * @with_prefix: Indicates whether to include the '0x' prefix (1) or not (0).
 *
 * This function converts the given unsigned integer to its hexadecimal representation
 * and returns the result as a string. If @with_prefix is true, it includes the '0x' prefix
 * in the output.
 *
 * Returns: A pointer to the hexadecimal representation string.
 */
char *convert_to_hex(unsigned int num, bool with_prefix)
{
    char hex_digits[] = "0123456789ABCDEF";
    static char hex_buffer[12]; // Adjust the buffer size as needed
    char *ptr = hex_buffer;

    if (with_prefix)
    {
        *ptr++ = '0';
        *ptr++ = 'x';
    }

    if (num == 0)
    {
        *ptr++ = '0';
    }
    else
    {
        int start = with_prefix ? 2 : 0; // Start index for digits

        // Convert the number to hexadecimal digits
        while (num > 0)
        {
            int digit = num % 16;
            *ptr++ = hex_digits[digit];
            num /= 16;
        }

        // Reverse the order of digits in the buffer
        for (int i = start, j = ptr - hex_buffer - 1; i < j; i++, j--)
        {
            char temp = hex_buffer[i];
            hex_buffer[i] = hex_buffer[j];
            hex_buffer[j] = temp;
        }
    }

    *ptr = '\0'; // Null-terminate the string
    return hex_buffer;
}

/**
 * convert_double_to_str - Converts a double to its string representation with a given precision.
 * @num: The double value to be converted.
 * @precision: The number of decimal places for the fractional part.
 * @str: The buffer to store the resulting string.
 *
 * This function converts the given double value to its string representation with the specified
 * precision for the fractional part. The resulting string is stored in the provided buffer.
 */
void convert_double_to_str(double num, int precision, char *str)
{
    int wholePart = (int)num;
    double fractionalPart = num - wholePart;

    // Convert the whole part to string
    convert_int_to_str(wholePart, str);

    // Append the decimal point if precision is specified
    if (precision > 0)
    {
        strcat(str, ".");
        int len = strlen(str);

        // Convert the fractional part to string with specified precision
        while (precision > 0)
        {
            fractionalPart *= 10;
            int digit = (int)fractionalPart;
            str[len++] = digit + '0';
            fractionalPart -= digit;
            precision--;
        }

        str[len] = '\0';
    }
}
