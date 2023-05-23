#ifndef DATA_H
#define DATA_H

#include <stdlib.h>

#ifdef _WIN32
#define HOMEDRIVE getenv("HOMEDRIVE")
#define HOMEPATH getenv("HOMEPATH")
#define HOME strcat(HOMEDRIVE, HOMEPATH)

#elif __APPLE__ || __linux__ || __unix__
#define HOME getenv("HOME")

#else
#define HOME NULL
#endif

/* Represents LPM data. */
typedef struct
{
	char parent[100];
	char email[100];
	char username[100];
	char password[100];
} Data;

extern char *formatData(Data *data);
extern void printData(Data *data);
extern Data createNewDataSet(void);
extern void modifyData(Data *data, char *parent);
extern void checkHomeNull(void);
#endif
