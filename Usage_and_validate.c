#include"header.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void usage_help()                                           //function for help
{
printf("===========================================================================================\n");
    printf("                              ::: Help Menu :::\n");
    printf("===========================================================================================\n");
    printf("USAGE :\nTo view please pass like     : ./a.out -v mp3filename\n");
    printf("To edit please pass like     : ./a.out -e -t/-a/-A/-y/-C/-c mp3filename\n");
    printf("    -t      Modifies Title tag\n");
    printf("    -a      Modifies Artist tag\n");
    printf("    -A      Modifies Album tag\n");
    printf("    -y      Modifies Year tag\n");
    printf("    -c      Modifies Content tag\n");
    printf("    -C      Modifies Comment tag\n");
    printf("===========================================================================================\n");
}

void inputcheck(int argc,char* argv[])                      //function for input check
{
    printf("===========================================================================================\n");
    printf("ERROR:");
    for(int i = 0; i < argc; i++)
    {
        printf("%s ",argv[i]);
    }
    printf(":INVALID ARGUMENTS\n");
    printf("USAGE :\nTo view please pass like     : ./a.out -v mp3filename\n");
    printf("To edit please pass like     : ./a.out -e -t/-a/-A/-y/-C/-c mp3filename\n");
    printf("For help please pass like    : ./a.out --help\n");
    printf("===========================================================================================\n");
}

int headercheck(char* str)                                 //function for id check
{
if(strcmp("ID3",str) != 0)
    {
        printf("___________________________________________________________________________________________\n\n");
        printf("File is not an MP3 file\n");
        printf("___________________________________________________________________________________________\n");
        exit(0);
    }
    else
    {
        return 1;
    }   
}