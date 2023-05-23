#include <stdio.h>
#include <unistd.h>
#include "include/data.h"
#include "include/fs.h"
#include "include/out.h"

int exists(const char *path)
{
	return access(path, F_OK) == 0;
}

void writeData(Data *data)
{
	FILE *file = fopen("../.lpmc/lpm.bin", "w");
	if (file == NULL)
		raiseLPMerr("failed to open lpm.bin.", 1);
}

void readData(char *parent)
{
}
