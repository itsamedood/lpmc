#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "include/cli.h"
#include "include/data.h"

char *genPassword(int length)
{
	const char *chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%%^&*()-_=+[{]};:'\",<.>/?|";
	const int charsLen = (int)strlen(chars);

	srand((unsigned int)time(NULL));

	char *password = malloc((length + 1) * sizeof(char));
	password[0] = '\0';

	for (int i = 0; i < length; i++)
	{
		char randChar = chars[rand() % charsLen];
		strncat(password, &randChar, 1);
	}

	return password;
}

void printHelp(void)
{
	char *helpArray[] = {
		"Usage: lpmc --flag | command [arg]",
		"Commands:",
		"╭─ new",
		"⏐  get <parent>",
		"⏐  edit <parent>",
		"⏐  list",
		"⏐  search <parent>",
		"⏐  rm <parent>",
		"⏐  wipe",
		"⏐  export [decrypted]",
		"⏐  gen <len>",
		"╰─ setup",
		"Flags:",
		"╭─ --v",
		"╰─ --h",
		NULL,
	};

	for (int i = 0; helpArray[i] != NULL; i++)
		printf("%s\n", helpArray[i]);
}

void processArgs(int argc, const char **argv)
{
	if (argc < 2)
		printHelp();
	else
	{
		// Iterate over arguments.
		for (int i = 0; i < argc; i++)
		{
			// printf("ARG %i: %s\n", i, argv[i]);

			/* Flags. */
			if (strcmp(argv[i], "--help") == 0)
				printHelp();

			else if (strcmp(argv[i], "--verbose") == 0)
			{
			}

			/* Commands. */
			else if (strcmp(argv[i], "new") == 0)
			{
				Data dataSet = createNewDataSet();
				Data *pDS = &dataSet;
				printData(pDS);
			}
		}
	}
}
