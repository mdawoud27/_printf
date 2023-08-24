#include "header.h"

/**
 * handle_length_modifiers - Handles formatting and printing an integer value based on flags, width, and precision.
 * @num: The integer value to be formatted and printed.
 * @flag_plus: Boolean flag for the '+' sign.
 * @flag_space: Boolean flag for the ' ' (space) sign.
 * @flag_hash: Boolean flag for the '#' sign.
 * @flag_minus: Boolean flag for left-justification.
 * @flag_long: Boolean flag for long length modifier.
 * @flag_short: Boolean flag for short length modifier.
 * @field_width: Width of the field.
 * @precision: Precision of the field.
 * @conversion_specifier: The conversion specifier character.
 *
 * This function formats and prints an integer value based on the provided flags, width,
 * precision, and other parameters. It considers various formatting scenarios and adjusts
 * the output accordingly.
 */
void handle_length_modifiers(int num, bool flag_plus, bool flag_space, bool flag_hash, bool flag_minus,
                                bool flag_long, bool flag_short, int field_width, int precision,
                                char conversion_specifier)
{
    bool flag_zero = false;

    // Convert the integer to a string
    char num_str[20];
    int int_str_len = convert_int_to_str(num, num_str);

    int num_width = int_str_len;

    // Adjust width based on sign and flags
    if (num < 0 || flag_plus || flag_space)
    {
        num_width++;
    }

    // Apply precision
    if (precision > num_width)
    {
        precision = num_width; // Override precision to match the number's width
    }

    int total_width = num_width;

    if (field_width > total_width)
    {
        int padding_width = field_width - total_width;

        // Print the sign characters
        if (num < 0)
        {
            append_to_buffer('-');
            num = -num;
        }
        else if (flag_plus)
        {
            append_to_buffer('+');
        }
        else if (flag_space)
        {
            append_to_buffer(' ');
        }

        // Print leading spaces (if applicable)
        if (!flag_minus && !flag_zero)
        {
            for (int i = 0; i < padding_width; i++)
            {
                append_to_buffer(' ');
            }
        }

        // Print leading zeros (if applicable)
        if (flag_zero)
        {
            for (int i = 0; i < padding_width; i++)
            {
                append_to_buffer('0');
            }
        }

        // Print the integer content
        for (int i = 0; i < int_str_len; i++)
        {
            append_to_buffer(num_str[i]);
        }

        // Print trailing spaces (if applicable)
        if (flag_minus)
        {
            for (int i = 0; i < padding_width; i++)
            {
                append_to_buffer(' ');
            }
        }
    }
    else
    {
        // Print the sign characters
        if (num < 0)
        {
            append_to_buffer('-');
            num = -num;
        }
        else if (flag_plus)
        {
            append_to_buffer('+');
        }
        else if (flag_space)
        {
            append_to_buffer(' ');
        }

        // Print leading zeros (if applicable)
        if (flag_zero)
        {
            for (int i = 0; i < precision - num_width; i++)
            {
                append_to_buffer('0');
            }
        }

        // Print the integer content
        for (int i = 0; i < int_str_len; i++)
        {
            append_to_buffer(num_str[i]);
        }
    }
}
