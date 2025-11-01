/*
Alwin Labu
26-10-25
MP3 Tag Reader/Editor

This project is a simple program that lets you read and edit MP3 song details like title, artist, album, year, contents
and comments. It works from the command line and helps understand how media players store song information such as Title, 
Artist, Album, Year, Contents and Comment within the MP3 file header. Various Functions such as String functions, 
File handling functions, Built in functions, Pointers, Loops concepts, 2D arrays 
and Operators are used to create this project.

Features:
1. View existing MP3 tag information (-v option)
2. Edit specific tags such as title, artist, or album (-e option)
3. File validation and error handling for missing or invalid MP3 files
4. Uses file I/O and byte-level data manipulation to access tag data
*/

#include "header.h"
#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
    if(argc == 3 && strcmp(argv[1], "-v") == 0)
        mp3view(argc,argv);

    else if (argc == 5 && strcmp(argv[1], "-e") == 0 &&
                        ((strcmp(argv[2], "-t") == 0) ||
                        (strcmp(argv[2], "-a") == 0) ||
                        (strcmp(argv[2], "-A") == 0) ||
                        (strcmp(argv[2], "-y") == 0) ||
                        (strcmp(argv[2], "-C") == 0) ||
                        (strcmp(argv[2], "-c") == 0)))
        mp3edit(argc,argv); 

    else if(argc == 2 && strcmp(argv[1], "--help") == 0)
        usage_help();

    else
        inputcheck(argc,argv);

    return 0;
}