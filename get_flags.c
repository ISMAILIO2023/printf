#include "main.h"

/**
 * get_flag - Calculates just the active flags
 * @format1: Formatted string in which to print the arguments
 * @i: to take a parameter.
 * Return: Flags:
 */
int get_flag(const char *format1, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i1;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i1 = *i + 1; format1[curr_i1] != '\0'; curr_i1++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format1[curr_i1] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_i1 - 1;

	return (flags);
}
