# Custom printf Function (_printf)

`_printf` is a custom implementation of the well-known C standard library function printf. This project aims to replicate the behavior of printf while providing extensibility and customization options.

## Introduction

The `_printf` function is designed to provide similar functionality to the C standard library's printf. It allows you to format and print output to the console with various format specifiers, providing more control over the output formatting.

## Features

- Supports common format specifiers such as `%d`, `%s`, `%c`, `%f`, `%x`, and more.

- Handles various **flags** and **modifiers**, including *field width*, *precision*, and *length specifiers*.

- Supports custom conversion specifiers for special formatting requirements.

- Provides extensibility for adding new format specifiers.

- Offers functionality to print special characters and handle special cases.

- Utilizes a buffer for efficient output.

## Usage

Include the _printf header in your code: #include "printf.h"
Call the _printf function with the desired format string and arguments.

Example:
``` c
#include "printf.h"

int main() {
    _printf("Hello, %s!\n", "world");
    _printf("Value: %d\n", 42);
    return 0;
}
```

## Supported Format Specifiers

The `_printf` function supports the following format specifiers:

- `%d` or `%i`: Signed integer

- `%u`: Unsigned integer

- `%o`: Octal representation
- `%x` or `%X`: Hexadecimal representation
- `%c`: Character
- `%s`: String
- `%p`: Pointer address
- `%f`: Floating-point number
- `%%`: Percentage character
- Flags: `-`, `+`, space, `#`, `0`

## Building and Running

To use the _printf function in your C projects, follow these steps:

- Clone the repository to your local machine:

    ```bash
    git clone https://github.com/mdawoud27/_printf.git
    ```
- To compile the code and run the example program, you can follow these steps:

    ```bash
    $ gcc *.c -o main
    $ ./main
    ```
Use the `_printf` function just like you would use the standard printf function. Pass the format string and any additional arguments as needed.

## Contributing

Contributions to this project are welcome! If you find any issues or want to enhance the functionality, feel free to create pull requests or open issues in the repository.

Feel free to modify and expand this `README` to suit your project's specific details and requirements.
