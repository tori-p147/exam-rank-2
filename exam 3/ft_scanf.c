#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
    
    int c_read;
    while ((c_read = getc(f)) != EOF)
    {
        if (!isspace(c_read))
        {
            ungetc(c_read, f);
            return (0);
        }
    }
    if (ferror(f))
        return (-1);
    return (0);
}

int match_char(FILE *f, char c)
{
    int c_read = getc(f);
    if (c_read == EOF)
    {
        if (ferror(f))
            return (-1);
        return (0);
    }
    if (c_read == c)
        return (1);
    else
    {
        ungetc(c_read, f);
        return (0);
    }
}

int scan_char(FILE *f, va_list ap)
{
    int c_read = getc(f);
    if (c_read == EOF)
    {
        if (ferror(f))
            return(-1);
        return (0);
    }
    char *c = va_arg(ap, char *);
    *c = (char)c_read;
    return (1);
}

int scan_int(FILE *f, va_list ap)
{
    int c_read;
    int was_read = 0;
    int sign = 1;
    int *num = va_arg(ap, int *);
    c_read = getc(f);
    if (c_read == EOF)
    {
        if (ferror(f))
            return (-1);
        return (0);
    }
    else if ((char)c_read == '-')
        sign = -sign;
    else if (isdigit(c_read))
    {
        ungetc(c_read, f);
    }
    *num = 0;
    while ((c_read = getc(f)) != EOF)
    {
        if (isspace(c_read) || !isdigit(c_read))
        {
            ungetc(c_read, f);
            break;
        }
        *num = *num * 10 + (c_read - '0');
        was_read++;
    }
    if (!was_read)
        return (0);
    *num *= sign;
    return (1);
}

int scan_string(FILE *f, va_list ap)
{
    int c_read;
    char *str = va_arg(ap, char *);
    int len = 0;
    while ((c_read = getc(f)) != EOF)
    {
        if (isspace(c_read))
        {
            ungetc(c_read, f);
            break;
        }
        *str = (char)c_read;
        str++;
        len++;
    }
    if (ferror(f))
        return (-1);
    if (len == 0)
        return (0);
    *str = '\0';
    return (1);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
	va_list ap;
    va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}

int main(int ac, char **av)
{
    char c;
    char s[10];
    int size;
    int n = 0;
    // size = ft_scanf(" %c", &c);
    // printf("%c %d", c, size);
    // size = ft_scanf("%s", s);
    // printf("%s %d", s, size);
    size = ft_scanf("%d", &n);
    printf("%d %d", n, size);
    return (0);
}