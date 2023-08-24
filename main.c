#include "header.h"

/**
 * main - entry point
 * 
 * Return: 0 always wins
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Unknown:[%r]\n");

	_printf("%b\n", 98);
	_printf("%S\n", "Best\nSchool");

	int value = 42;
	_printf("Value with +: %+d\n", value);
	printf("Value with +: %+d\n", value);

	_printf("Value with space: % d\n", value);
	printf("Value with space: % d\n", value);

	_printf("Value with # and uppercase: %#X\n", value);
	printf("Value with # and uppercase: %#X\n", value);

	_printf("Non-flag character: %c\n", 'A');
	printf("Non-flag character: %c\n", 'A');

	_printf("String with flags: %#+s\n", "Hello");

	_printf("Double percent: %%\n");
	printf("Double percent: %%\n");


	// Test cases with precision
	_printf("Precision: %.4d\n", 123);
	printf("Precision: %.4d\n", 123);

	_printf("Precision and field width: %8.3f\n", 123.456);
	printf("Precision and field width: %8.3f\n", 123.456);

	// Test cases with multiple flags and precision

	_printf("Multiple flags and precision: % 10.4d\n", -123);
	printf("Multiple flags and precision: % 10.4d\n", -123);

	_printf("ROT13: %R\n", "Hello");
	// Output: ROT13: Uryyb

	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);

	_printf("Positive with sign and space: %+d % d\n", 42, 42);
	printf("Positive with sign and space: %+d % d\n", 42, 42);

	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);

	_printf("Percent:[%%]\n");
	printf("Percent:[%%]\n");

	_printf("Reversed: %r\n", "Hello");

	return (0);
}