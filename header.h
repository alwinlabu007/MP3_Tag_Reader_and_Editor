#ifndef header_h
#define header_h

void mp3view(int argc, char* argv[]);
void endianness_conversion(int *size);
void inputcheck(int argc,char* argv[]);
void mp3edit(int argc, char* argv[]);
void usage_help();
int headercheck(char* str);

#endif