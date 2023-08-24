#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

/*_printf() function*/
int _printf(const char *format, ...);

/*_write file*/
void flush_buffer();
void append_to_buffer(char c);

/*convert_ptr*/
void convert_and_append_ptr(uintptr_t ptr);

/*convert file*/
char *convert(unsigned int num, int base, int uppercase);
void convert_and_append(unsigned int num, int base, int uppercase);
char *convert_to_hex(unsigned int num, bool with_prefix);
void convert_double_to_str(double num, int precision, char *str);

/*Handle length modifiers*/
void handle_length_modifiers(int num, bool flag_plus, bool flag_space, bool flag_hash, bool flag_minus,
                             bool flag_long, bool flag_short, int field_width, int precision,
                             char conversion_specifier);

/*Flags*/
void handle_length(const char **ptr, bool *flag_long, bool *flag_short);
int handle_precision(const char **ptr);
int handle_field_width(const char **ptr);
void handle_flags(const char **ptr, bool *flag_plus, bool *flag_space, bool *flag_hash, bool *flag_minus, bool *flag_zero);
void handle_percent(const char **ptr, bool *flag_plus, bool *flag_space, bool *flag_hash, bool *flag_minus, int *field_width, int *precision);

/*special_str*/
void print_special_string(const char *str);
void apply_rot13(char *str);
void handle_length_modifiers_str(const char *str, bool flag_plus, bool flag_space, bool flag_hash,
                                    bool flag_minus, bool flag_long, bool flag_short, int field_width, int precision,
                                    char conversion_specifier);
int convert_int_to_str(int num, char *str);
int convert_frac_to_str(double frac, char *str, int precision);
void reverse_str(char *str, int length);

#endif
