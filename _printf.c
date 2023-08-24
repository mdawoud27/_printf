#include "header.h"

/**
 *  _printf - function that produces output according to a format.
 *
 * @format: character string
 * Return: the lenght of chars.
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;
	const char *ptr = format;

	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;

			bool flag_plus = false;
			bool flag_space = false;
			bool flag_hash = false;
			bool flag_minus = false;
			bool flag_long = false;
			bool flag_short = false;
			bool flag_zero = false;
			int field_width = 0;
			int precision = -1;
			char conversion_specifier = '\0';

			/*Handle flag characters using the function*/
			handle_flags(&ptr, &flag_plus, &flag_space, &flag_hash, &flag_minus, &flag_zero);

			/*Handle field width using the function*/
			if (*ptr >= '0' && *ptr <= '9')
			{
				field_width = handle_field_width(&ptr);
			}

			/*Handle precision using the function*/
			precision = handle_precision(&ptr);

			/*Handle length modifiers*/
			handle_length(&ptr, &flag_long, &flag_short);

			/*Get the conversion specifier*/
			conversion_specifier = *ptr;

			switch (conversion_specifier)
			{
			case 'c':
			{
				char c = (char)va_arg(args, int);
				append_to_buffer(c);
				count++;
				break;
			}
			case 's':
			{
				const char *s = va_arg(args, const char *);
				int length = strlen(s);

				if (precision >= 0 && precision < length)
				{
					length = precision;
				}

				if (flag_hash) /*Handle the '#' flag*/
				{
					append_to_buffer('0'); /*Print the '0' character*/
					append_to_buffer('x'); /*Print the 'x' character*/
					count += 2;			   /* Increment the count for the '0x' */
				}

				handle_length_modifiers_str(s, flag_plus, flag_space, false, flag_minus,
											flag_long, flag_short, field_width, length, conversion_specifier);

				break;
			}

			case '%':
			{
				handle_flags(&ptr, &flag_plus, &flag_space, &flag_hash, &flag_minus, &flag_zero);
				field_width = handle_field_width(&ptr);
				precision = handle_precision(&ptr);

				handle_length_modifiers_str("%", flag_plus, flag_space, flag_hash, flag_minus,
											flag_long, flag_short, field_width, precision, conversion_specifier);

				count++; // Increment the count for the '%' character
				break;
			}

			case 'd':
			case 'i':
			{
				int num = va_arg(args, int);
				if (num < 0)
				{
					append_to_buffer('-');
					num = -num;
					count++;
				}
				handle_length_modifiers(num, flag_plus, flag_space, flag_hash, flag_minus,
										flag_long, flag_short, field_width, precision, conversion_specifier);
				break;
			}

			case 'f':
			{
				double num = va_arg(args, double);
				char num_str[100];								// Adjust the buffer size as needed
				convert_double_to_str(num, precision, num_str); // Convert double to string with precision
				handle_length_modifiers_str(num_str, flag_plus, flag_space, flag_hash, flag_minus,
											flag_long, flag_short, field_width, strlen(num_str), conversion_specifier);
				break;
			}

			case 'b':
			{
				unsigned int num = va_arg(args, unsigned int);
				char *bin = convert(num, 2, 0);
				while (*bin != '\0')
				{
					append_to_buffer(*bin);
					bin++;
					count++;
				}
				break;
			}
			case 'u':
			{
				unsigned int num = va_arg(args, unsigned int);
				char *unsignedNum = convert(num, 10, 0);
				while (*unsignedNum != '\0')
				{
					append_to_buffer(*unsignedNum);
					unsignedNum++;
					count++;
				}
				break;
			}
			case 'o':
			{
				int num = va_arg(args, int);
				char *oct = convert(num, 8, 0);
				while (*oct != '\0')
				{
					append_to_buffer(*oct);
					oct++;
					count++;
				}
				break;
			}
			case 'X':
			{
				unsigned int num = va_arg(args, unsigned int);
				char *hex_str = convert_to_hex(num, flag_hash);

				/*Print the uppercase hexadecimal string*/
				for (int i = 0; hex_str[i] != '\0'; i++)
				{
					append_to_buffer(toupper(hex_str[i]));
					count++;
				}
				break;
			}

			case 'x':
			{
				int num = va_arg(args, int);
				char *hex = convert(num, 16, 0);
				while (*hex != '\0')
				{
					append_to_buffer(*hex);
					hex++;
					count++;
				}
				break;
			}
			case 'S':
			{
				char *str = va_arg(args, char *);
				print_special_string(str);
				count += strlen(str);
				break;
			}
			case 'p':
			{
				uintptr_t ptr = (uintptr_t)va_arg(args, void *);
				convert_and_append_ptr(ptr);
				count += sizeof(void *);
				break;
			}
			case 'r':
			{
				const char *str = va_arg(args, const char *);
				int length = strlen(str);

				for (int i = length - 1; i >= 0; i--)
				{
					append_to_buffer(str[i]);
				}

				count += length;
				break;
			}
			case 'R':
			{
				const char *str = va_arg(args, const char *);
				char rot13_str[strlen(str) + 1];
				strcpy(rot13_str, str);
				apply_rot13(rot13_str);

				int length = strlen(rot13_str);
				for (int i = 0; i < length; i++)
				{
					append_to_buffer(rot13_str[i]);
				}

				count += length;
				break;
			}

			default:
			{
				append_to_buffer(*ptr);
				count++;
				break;
			}
			}
		}
		else
		{
			append_to_buffer(*ptr);
			count++;
		}
		ptr++;
	}

	va_end(args);

	/*Flush any remaining characters in the buffer*/
	flush_buffer();
	return count;
}
