#include <stdio.h>
#include <stdlib.h>
#include "include/out.h"

void raiseLPMerr(char *message, int code)
{
	printf("lpmc: %serror%s: %s\n", PRST_ERROR, PRST_RESET, message);
	exit(code);
}
