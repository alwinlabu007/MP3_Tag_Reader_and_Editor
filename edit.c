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

void mp3edit(int argc, char* argv[])
{
    FILE* fp = fopen(argv[4], "r");                         //Sample file opening in read mode
    if(fp == NULL)                                          //Function for file checking
    {
        printf("\nThere is no such file!\n");
        inputcheck(argc,argv);
        exit(0);
    }
    FILE* tp = fopen("temp.mp3", "w");                      //Temp file opening in write mode
    if(tp == NULL)                                          //Function for file checking
    {
        printf("\nThere is no such file!\n");
        inputcheck(argc,argv);
        exit(0);
    }

    char header[4];
    fread(header, 3, 1, fp);                                //read id to header variable
    header[3] = '\0';
    headercheck(header);                                    //header checking
    fwrite(header, 3, 1, tp);

    char buffer[7];                                         //initialising a variable to copy 10 bytes of header to tempfile
    fread(buffer, 7, 1, fp);
    fwrite(buffer, 7, 1, tp);                               //writing into file
    
    for(int i = 0; i < 6; i++)                              //Looping 6 times to check all tags
    {

        char tag[5];                                        //tag variable to copy tag 
        fread(tag, 4, 1, fp);
        tag[4] = '\0';

        int edittag = -1;
        char mp3tag[6][5] = {"TIT2", "TPE1", "TALB", "TYER", "TCON", "COMM"};               //character array to store tags
        char mp3arg[6][3] = {"-t", "-a", "-A", "-y", "-C", "-c"};                           //character array to store arguments
        char mp3tit[6][9] = {"Title", "Artist", "Album", "Year", "Contents", "Comment"};   //Character array to store titles
        for(int j = 0; j < 6; j++)
        {
            if(strcmp(argv[2],mp3arg[j]) == 0)
            {
                edittag = j;                                //edittag variable to store index
                break;
            }
        }

        if(strcmp(tag, mp3tag[edittag]) == 0)               //Compares tag with array of tags
        {
            fwrite(tag, 4, 1, tp);
            
            int oldsize;                                    //variable to store the content size
            fread(&oldsize, 4, 1 ,fp);

            int newsize = strlen(argv[3]);                  //varible to store new string lenth
            newsize = newsize + 1;
            int ognewsize = newsize;

            endianness_conversion(&newsize);                //Function for endianess conversion

            fwrite(&newsize, 4, 1, tp);                     //writing newsize to temp file
    
            char flagtag[4];
            fread(flagtag, 3, 1, fp);
            flagtag[3] = '\0';
            fwrite(flagtag, 3, 1, tp);                      //write 3 bytes(flag and null) to temp

            fwrite(argv[3], ognewsize - 1 , 1, tp);         //writes newname to temp 

            endianness_conversion(&oldsize);
            fseek(fp, oldsize - 1, SEEK_CUR);               //skips the remaining contents in content frame

            int ch;
            while ((ch = fgetc(fp)) != EOF) 
            {
                fputc(ch, tp);                              //writes all the remaining characters to temp file
            }
            printf("___________________________________________________________________________________________\n\n");
            printf("Selected %s changed to %s succesfully\n",mp3tit[edittag],argv[3]);
            printf("___________________________________________________________________________________________\n\n");
            break;
        }
        else
        {
            fwrite(tag, 4, 1, tp);                          //copies all the tags and contents to temp file
            int oldsize;
            fread(&oldsize, 4, 1 ,fp);
            fwrite(&oldsize, 4, 1, tp);

            char flagtag[4];
            fread(flagtag, 3, 1, fp);
            flagtag[3] = '\0';
            fwrite(flagtag, 3, 1, tp);

            endianness_conversion(&oldsize);
            char content[oldsize];                                 //creating char array of content size
            for(int i = 0; i < oldsize - 1; i++)
            {
                fread(&content[i], 1, 1,fp);                       //reading characters to array byte by byte
                fwrite(&content[i], 1, 1,tp);
            }    
        }
    }

        fclose(fp);                                           //closing original file
        fclose(tp);                                           //closing new file

        remove(argv[4]);                                      //removing original mp3 file
        rename("temp.mp3",argv[4]);                           //renaming new file to original file
}