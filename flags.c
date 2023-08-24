#include "header.h"

/**
 * handle_length - Handles the length modifiers in the input format string.
 * @ptr: Pointer to a pointer to the input format string.
 * @flag_long: Pointer to a boolean indicating the "long" length modifier.
 * @flag_short: Pointer to a boolean indicating the "short" length modifier.
 *
 * This function processes the length modifiers in the input format string and updates
 * the corresponding boolean flags.
 */
void handle_length(const char **ptr, bool *flag_long, bool *flag_short)
{
    while (**ptr == 'l' || **ptr == 'h')
    {
        if (**ptr == 'l')
        {
            *flag_long = true;
        }
        else if (**ptr == 'h')
        {
            *flag_short = true;
        }
        (*ptr)++;
    }
}

/**
 * handle_precision - Handles the precision specifier in the input format string.
 * @ptr: Pointer to a pointer to the input format string.
 *
 * This function processes the precision specifier in the input format string and
 * returns the precision value as an integer. If no precision is specified, -1 is returned.
 */
int handle_precision(const char **ptr)
{
    int precision = -1;
    if (**ptr == '.')
    {
        (*ptr)++;
        precision = 0;
        while (**ptr >= '0' && **ptr <= '9')
        {
            precision = precision * 10 + (**ptr - '0');
            (*ptr)++;
        }
    }
    return precision;
}

/**
 * handle_field_width - Handles the field width specifier in the input format string.
 * @ptr: Pointer to a pointer to the input format string.
 *
 * This function processes the field width specifier in the input format string and
 * returns the field width value as an integer. The function assumes that the field
 * width is specified as a sequence of digit characters.
 */
int handle_field_width(const char **ptr)
{
    int field_width = 0;
    while (**ptr >= '0' && **ptr <= '9')
    {
        field_width = field_width * 10 + (**ptr - '0');
        (*ptr)++;
    }
    return field_width;
}

/**
 * handle_flags - Handles flag characters in the input format string.
 * @ptr: Pointer to a pointer to the input format string.
 * @flag_plus: Pointer to a boolean variable for the '+' flag.
 * @flag_space: Pointer to a boolean variable for the ' ' (space) flag.
 * @flag_hash: Pointer to a boolean variable for the '#' flag.
 * @flag_minus: Pointer to a boolean variable for the '-' flag.
 * @flag_zero: Pointer to a boolean variable for the '0' flag.
 *
 * This function processes the flag characters in the input format string and
 * updates the corresponding boolean variables accordingly.
 */
void handle_flags(const char **ptr, bool *flag_plus, bool *flag_space, bool *flag_hash, bool *flag_minus, bool *flag_zero)
{
    while (**ptr == '+' || **ptr == ' ' || **ptr == '#' || **ptr == '-' || **ptr == '0')
    {
        switch (**ptr)
        {
        case '+':
            *flag_plus = true;
            break;
        case ' ':
            *flag_space = true;
            break;
        case '#':
            *flag_hash = true;
            break;
        case '-':
            *flag_minus = true;
            break;
        case '0':
            *flag_zero = true;
            break;
        }
        (*ptr)++;
    }
}

/**
 * handle_percent - Handles the '%' format specifier and associated flags, field width, and precision.
 * @ptr: Pointer to a pointer to the input format string.
 * @flag_plus: Pointer to a boolean variable for the '+' flag.
 * @flag_space: Pointer to a boolean variable for the ' ' (space) flag.
 * @flag_hash: Pointer to a boolean variable for the '#' flag.
 * @flag_minus: Pointer to a boolean variable for the '-' flag.
 * @field_width: Pointer to an integer variable for the field width.
 * @precision: Pointer to an integer variable for the precision.
 *
 * This function processes the '%' format specifier and its associated flags,
 * field width, and precision. It updates the corresponding variables based on
 * the encountered characters in the input format string.
 */
void handle_percent(const char **ptr, bool *flag_plus, bool *flag_space, bool *flag_hash, bool *flag_minus, int *field_width, int *precision)
{
    // Handle flag characters
    handle_flags(ptr, flag_plus, flag_space, flag_hash, flag_minus, NULL);

    // Handle field width
    if (**ptr >= '0' && **ptr <= '9')
    {
        *field_width = handle_field_width(ptr);
    }

    // Handle precision
    if (**ptr == '.')
    {
        (*ptr)++;
        *precision = handle_precision(ptr);
    }

    // Print the '%' character
    handle_length_modifiers_str("%", *flag_plus, *flag_space, *flag_hash, *flag_minus,
                                false, false, *field_width, *precision, '%');
}
