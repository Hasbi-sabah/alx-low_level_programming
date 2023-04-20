#ifndef VAR_FUN_H
#define VAR_FUN_H

#include <stdarg.h>
#include <stddef.h>

/**
 * struct list - list of chars
 * @chars: characters to look for
 * @f: function to be executed
 */
struct list
{
	char chars;
	void (*f)(va_list);
};
typedef struct list char_list;
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
void c_print(va_list pars);
void i_print(va_list pars);
void f_print(va_list pars);
void s_print(va_list pars);

#endif
