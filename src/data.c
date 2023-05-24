#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/data.h"
#include "include/out.h"

char *formatData(Data *data)
{
	if (data == NULL)
		printf("data found null when attempting to format.\n");

	size_t bytes = (strlen(data->parent) + strlen(data->email) + strlen(data->username) + strlen(data->password)) + 6;
	char *buffer = malloc(bytes + 1 * sizeof(char)); // Add `1` to bytes to account for '\0'.

	if (buffer == NULL)
		printf("failed to allocate memory for formatted data.\n");

	sprintf(buffer, "%s::%s::%s::%s", data->parent, data->email, data->username, data->password);
	return buffer;
}

void printData(Data *data)
{
	printf("%s\nParent:%s %s%s%s", TEXT_YELLOW, PRST_RESET, STYLE_LIGHT, data->parent, PRST_RESET);
	printf("%s\nEmail:%s %s%s%s", TEXT_YELLOW, PRST_RESET, STYLE_LIGHT, data->email, PRST_RESET);
	printf("%s\nUsername:%s %s%s%s", TEXT_YELLOW, PRST_RESET, STYLE_LIGHT, data->username, PRST_RESET);
	printf("%s\nPassword:%s %s%s%s\n", TEXT_YELLOW, PRST_RESET, STYLE_LIGHT, data->password, PRST_RESET);
}

Data createNewDataSet(void)
{
	char username[100];
	Data data;

	while (strlen(data.parent) < 2)
	{
		printf("Parent (no spaces): ");
		scanf("%99s", data.parent);
	}

	while (strlen(data.email) < 2)
	{
		printf("Email: ");
		scanf("%99s", data.email);
	}

	while (strlen(username) < 2)
	{
		printf("Username: ");
		scanf("%99s", username);
	}
	strcpy(data.username, username);

	while (strlen(data.password) < 2)
	{
		printf("Password: ");
		scanf("%99s", data.password);
	}

	return data;
}

void modifyData(Data *data, char *parent)
{
}

void checkHomeNull(void)
{
	if (HOME == NULL)
		printf("unknown OS.\n");
}
