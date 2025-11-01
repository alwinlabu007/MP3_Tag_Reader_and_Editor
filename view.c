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
#include<stdlib.h>
#include<string.h>


void mp3view(int argc, char* argv[])
{ 
    FILE* fp = fopen(argv[2], "r");                         //opening musicfile
    if(fp == NULL)                                          //Function for file checking
    {
        printf("\nThere is no such file!\n");
        inputcheck(argc, argv);
        exit(0);
    }

    char header[4];                                         //create header varible
    fread(header, 3, 1, fp);                                //read id to header variable
    header[3] = '\0';
    if(headercheck(header))                                 //To print it's an mp3 file
    {
        //printf("___________________________________________________________________________________________\n\n");
        printf("File is mp3\n");
    }
    printf("===========================================================================================\n\n");
    printf("🎼 MP3 Tag Reader and Editor for ID3v2 🎼\n");
    printf("___________________________________________________________________________________________\n\n");

    fseek(fp,7,SEEK_CUR);                                   //skip 7 bytes

    for(int i = 0; i <6; i++)                               //loop 6 times for all 6 tags
    {
        char tag[5];                                        //create a tag variable to store the tag
        fread(tag, 4, 1, fp);                               //read tag
        tag[4] = '\0';

        char mp3tag[6][5] = {"TIT2", "TPE1", "TALB", "TYER", "TCON", "COMM"};                                     //character array to store tags
        char mp3tit[6][15] = {"🎵 Title", "🎤 Artist", "💽 Album", "📅 Year", "🎧 Music", "📜 Comment"};   //Character array to store titles
        for(int j = 0; j < 6; j++)
        {
            if(strcmp(tag,mp3tag[j]) == 0)
            {
                printf("%-20s     :   ",mp3tit[j]);
            }
        }

        int size;
        fread(&size, 4, 1 ,fp);                             //reading size of content

        endianness_conversion(&size);                       //function for converting size in big endian to little endian

        fseek(fp,3,SEEK_CUR);                               //skipping flag and null
        
        char content[size];                                 //creating char array of content size
        for(int i = 0; i < size - 1; i++)
        {
            fread(&content[i], 1, 1,fp);                    //reading characters to array byte by byte
        }
        content[size - 1] = '\0';

        printf("%s\n",content);                             //printing characters

    }
    printf("===========================================================================================\n");
    fclose(fp);
}

void endianness_conversion(int *size)                       //function for converting Big endian to little endian
{
    char* ptr = (char*) size;
    for (int i = 0; i < 2; i++)
    {
        char temp = ptr[i];
        ptr[i] = ptr[3 - i];
        ptr[3 - i] = temp;
    }
}



