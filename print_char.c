/*
 * File: print_char.c
 * Author: Chukwuka Akibor
 */

#include "main.h"

/**
 * print_char - Prints a character
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Flag options
 * @width: Width specifier
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
