#include <stdio.h>
#include <stdlib.h>

#include "error.h"

static void
print(const char *type, const char *format, va_list args)
{
	fprintf(stderr, "%s: ", type);
	vfprintf(stderr, format, args);
	fprintf(stderr, "\n");
}

_Noreturn void
fatal_error(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	print("Fatal error", format, args);
	va_end(args);

	exit(EXIT_FAILURE);
}

void
error(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	print("Error", format, args);
	va_end(args);
}

void
warning(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	print("Warning", format, args);
	va_end(args);
}
