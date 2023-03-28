### printf
##### Flags main.h

```c
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
```

##### handle_write_char function
```c
#include "main.h"

/**
 * handle_write_char - Writes a character to the buffer with padding
 *
 * @c: Character to write
 * @buffer: Buffer array to write to
 * @flags: Flag options
 * @width: Width specifier
 * @precision: Precision specifier (unused)
 * @size: Size specifier (unused)
 *
 * Return: Number of characters written
 */
int handle_write_char(char c, char buffer[], int flags, int width,
                      int precision, int size)
{
    int num_written = 0; // Number of characters written
    char padding_char = ' '; // Character to use for padding

    // Use '0' instead of ' ' for padding if the '0' flag is set
    if (flags & F_ZERO)
        padding_char = '0';

    // Add the character to the buffer
    buffer[0] = c;
    buffer[1] = '\0';
    num_written++;

    // Add padding to the left of the character if necessary
    if (width > 1)
    {
        int padding_width = width - 1; // Width of padding to add
        int i; // Loop counter

        // Add padding characters to the buffer
        for (i = 0; i < padding_width; i++)
            buffer[BUFF_SIZE - i - 2] = padding_char;

        // Write the buffer to the output with padding on the left or right
        if (flags & F_MINUS)
        {
            num_written += write(1, &buffer[0], 1);
            num_written += write(1, &buffer[BUFF_SIZE - i - 1], padding_width);
        }
        else
        {
            num_written += write(1, &buffer[BUFF_SIZE - i - 1], padding_width);
            num_written += write(1, &buffer[0], 1);
        }
    }
    else // No padding needed, write the character directly
    {
        num_written += write(1, &buffer[0], 1);
    }

    return num_written;
}
```
The function takes in six parameters:

c: the character to be printed
buffer: an array to hold the output string
flags: a flag to specify formatting options
width: the width specifier
precision: the precision specifier
size: the size specifier
The function returns the number of characters printed.

The implementation of the function starts by setting a variable padd to ' ', which will be used as the default padding character.

Then, if the F_ZERO flag is set, padd is set to '0' instead of ' '.

The character to be printed is stored at the left of the buffer and padding is added to the buffer's right.

If the width specifier is greater than 1, the buffer is filled with padd characters until the desired width is reached.

If the F_MINUS flag is set, the character is printed first and then the padding, while if it is not set, the padding is printed first and then the character.

Finally, the function returns the number of characters printed using the write function. If the width specifier is less than or equal to 1, only the character is printed.


##### print_char function
```c
/**
 * print_char - Writes a single character to the specified buffer with
 *              the given formatting options.
 *
 * @types:     A variable argument list containing the character to be written.
 * @buffer:    The buffer array to write the character to.
 * @flags:     An integer containing the active flag options for the character.
 *             See the flag constants defined in the main.h header file.
 * @width:     An integer specifying the minimum width of the printed character.
 *             If the character is shorter than this, it will be padded with
 *             spaces or zeros according to the active flag options.
 * @precision: An integer specifying the maximum number of characters to be
 *             written. If the character is longer than this, it will be
 *             truncated according to the active flag options.
 * @size:      An integer specifying the size of the character. See the size
 *             constants defined in the main.h header file.
 *
 * Return:     The number of characters written to the buffer.
 */
int print_char(va_list types, char buffer[], int flags, int width,
	      int precision, int size)
{
    // Extract the character from the variable argument list
    char c = va_arg(types, int);

    // Call the handle_write_char function to write the character to the buffer
    return handle_write_char(c, buffer, flags, width, precision, size);
}
```

The print_char function writes a single character to the specified buffer with the given formatting options. The character to be written is extracted from the variable argument list types. The function returns the number of characters written to the buffer.

Here is a brief description of the function parameters:

types: A variable argument list containing the character to be written.
buffer: The buffer array to write the character to.
flags: An integer containing the active flag options for the character. See the flag constants defined in the main.h header file.
width: An integer specifying the minimum width of the printed character. If the character is shorter than this, it will be padded with spaces or zeros according to the active flag options.
precision: An integer specifying the maximum number of characters to be written. If the character is longer than this, it will be truncated according to the active flag options.
size: An integer specifying the size of the character. See the size constants defined in the main.h header file.
