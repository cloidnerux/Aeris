//#include "keyboard.h" //TODO: scanf & co


#define PAD_RIGHT 1
#define PAD_ZERO 2

//um mehrfach deklaration zu vermeiden heir extern deklarationen
#include "include/system.h"

void PrintChar(char **str, int c)
{
	if (str) {
		**str = c;
		++(*str);
	}
	else (void)PutChr(c);
}

int Prints(char **out, const char *string, int width, int pad)
{
	register int pc = 0, padchar = ' ';

	if (width > 0) {
		register int len = 0;
		register const char *ptr;
		for (ptr = string; *ptr; ++ptr) ++len;
		if (len >= width) width = 0;
		else width -= len;
		if (pad & PAD_ZERO) padchar = '0';
	}
	if (!(pad & PAD_RIGHT)) {
		for ( ; width > 0; --width) {
			PrintChar (out, padchar);
			++pc;
		}
	}
	for ( ; *string ; ++string) {
		PrintChar (out, *string);
		++pc;
	}
	for ( ; width > 0; --width) {
		PrintChar (out, padchar);
		++pc;
	}

	return pc;
}
#define PRINT_BUF_LEN 12

int Printi(char **out, int i, int b, int sg, int width, int pad, int letbase)
{
	char print_buf[PRINT_BUF_LEN];
	register char *s;
	register int t, neg = 0, pc = 0;
	register unsigned int u = i;

	if (i == 0) {
		print_buf[0] = '0';
		print_buf[1] = '\0';
		return Prints (out, print_buf, width, pad);
	}

	if (sg && b == 10 && i < 0) {
		neg = 1;
		u = -i;
	}

	s = print_buf + PRINT_BUF_LEN-1;
	*s = '\0';

	while (u) {
		t = u % b;
		if( t >= 10 )
			t += letbase - '0' - 10;
		*--s = t + '0';
		u /= b;
	}

	if (neg) {
		if( width && (pad & PAD_ZERO) ) {
			PrintChar (out, '-');
			++pc;
			--width;
		}
		else {
			*--s = '-';
		}
	}

	return pc + Prints (out, s, width, pad);
}

int Print(char **out, int *varg)
{
	register int width, pad;
	register int pc = 0;
	register char *format = (char *)(*varg++);
	char scr[2];

	for (; *format != 0; ++format) {
		if (*format == '%') {
			++format;
			width = pad = 0;
			if (*format == '\0') break;
			if (*format == '%') goto out;
			if (*format == '-') {
				++format;
				pad = PAD_RIGHT;
			}
			while (*format == '0') {
				++format;
				pad |= PAD_ZERO;
			}
			for ( ; *format >= '0' && *format <= '9'; ++format) {
				width *= 10;
				width += *format - '0';
			}
			if( *format == 's' ) {
				register char *s = *((char **)varg++);
				pc += Prints (out, s?s:"(null)", width, pad);
				continue;
			}
			if( *format == 'd' ) {
				pc += Printi (out, *varg++, 10, 1, width, pad, 'a');
				continue;
			}
			if( *format == 'x' ) {
				pc += Printi (out, *varg++, 16, 0, width, pad, 'a');
				continue;
			}
			if( *format == 'X' ) {
				pc += Printi (out, *varg++, 16, 0, width, pad, 'A');
				continue;
			}
			if( *format == 'u' ) {
				pc += Printi (out, *varg++, 10, 0, width, pad, 'a');
				continue;
			}
			if( *format == 'c' ) {
				scr[0] = *varg++;
				scr[1] = '\0';
				pc += Prints (out, scr, width, pad);
				continue;
			}
		}
		else {
		out:
			PrintChar (out, *format);
			++pc;
		}
	}
	if (out) **out = '\0';
	return pc;
}


int Printf(const char *format, ...)
{
	register int *varg = (int *)(&format);
	return Print(0, varg);
}


int SPrintf(char *out, const char *format, ...)
{
	register int *varg = (int *)(&format);
	return Print(&out, varg);
}

