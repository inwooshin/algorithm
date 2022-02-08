#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAX_BUF_SIZE 4096

void myPrintf(const char* str, ...) {
	va_list ap;

	va_start(ap, str);

	char* p = str, *outStr;
	int count = 0;

	outStr = (char*)malloc(sizeof(char) * MAX_BUF_SIZE);
	memset(outStr, 0, sizeof(char) * MAX_BUF_SIZE);

	while (*p) {
		char ch = *p++;
		
		if (ch == '%') {
			ch = *p++;
			
			switch (ch) {
			case 'd': 
				sprintf(outStr, "%s%d" ,outStr ,va_arg(ap, int));
				break;
			case 'f':
				sprintf(outStr, "%s%f", outStr, va_arg(ap, float));
				break;
			case 'x':
				sprintf(outStr, "%s%x", outStr, va_arg(ap, int));
				break;
			case 'X':
				sprintf(outStr, "%s%X", outStr, va_arg(ap, int));
			break;
			case 's':
				sprintf(outStr, "%s%s", outStr, va_arg(ap, char *));
				break;
			case 'l':
				sprintf(outStr, "%s%lf", outStr, va_arg(ap, double));
				break;
			case 'c':
				sprintf(outStr, "%s%c", outStr, va_arg(ap, char));
				break;
			default :
				sprintf(outStr, "%s", outStr);
				break;
			}
		}
		else {
			sprintf(outStr, "%s%c", outStr, ch);
		}
	}

	va_end(ap);

	fprintf(stdout, outStr);
	free(outStr);
};

int main(void) {

	char* myName = "inwoo shin";

	myPrintf("hello %d\n", 4);
	myPrintf("hello %s\n", myName);
	myPrintf("%d %l %c %s %f\n", 3, 3.4, 'c', "sdflksd", 3.4);
	myPrintf("%x\n", 346346);
	myPrintf("%X\n", 346346);

	return 0;
}