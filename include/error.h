#ifndef ERROR_H
#define ERROR_H

#include <stdarg.h>

_Noreturn void
fatal_error(const char *format, ...);

void
error(const char *format, ...);

void
warning(const char *format, ...);

#endif
