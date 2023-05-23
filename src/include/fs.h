#ifndef FS_H
#define FS_H

extern int exists(const char *path);
extern void writeData(Data *data);
extern void readData(char *parent);
#endif
