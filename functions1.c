#include "main.h"

/****Print unsigned number***/
/**
 * print_unsigned - Prints unsigned number
 * @types: List of argument
 * @buffer: Buffer arr
 * @flags: Calculate active flgs
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int widt, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[k--] = '0';
	while (num > 0)
	{
		buffer[k--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsignd(0, k, buffer, flags, width, precision, size));
}
/****Print unsigned number in OCTAL****/
/**
 * print_octal - Prints an unsigned number in octal
 * @types: List of arguments
 * @buffer: Buffer arr
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters
 */
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[k--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[k--] = '0';
	k++;
	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}

/**** Print unsigned number in hexa ****/
/**
 * print_hexadecimal - Prints an unsigned number in hexa
 * @types: List of arguments
 * @buffer: Buffer arr
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}

/**** Print Hex num in lower or upper ****/
/**
 * print_hexa - Prints a hexadecimal number in L or U
 * @types: List of arguments
 * @map_to: Array of values to map this number
 * @buffer: Buffer arr
 * @flags: Calculate active flgs
 * @flag_ch: Calculate active flgs
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters
 */

int print_hesxa(va_ list types, char map_to[], char buffer[],
int flags, char flags_ch, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[k--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[k--] = flag_ch;
		buffer[k--] = '0';
	}
k++;
return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}
