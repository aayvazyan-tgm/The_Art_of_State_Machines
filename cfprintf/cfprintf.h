https://github.com/n00btime/cprintf/blob/master/cprintf.hpp
#ifndef CFPRINTF_H
#define CFPRINTF_H
#include <stdio.h>
/*	supports 16 foreground and background colors:
	[0-15]=[black,navy,green,teal,maroon,purple,olive,silver,gray,blue,lime,aqua,red,fuchsia,yellow,white]
	using the <color>{your text here} syntax. for example:
	red{text printed in red-on-black color}
	redwhite{text printed in red-on-white color}
*/
#define CFPRINTF_MAX_BUFFER_SIZE (8192)
int		cfprintf(FILE *f, const char *fmt, ...); // exactly as fprintf but with color support 
#endif
