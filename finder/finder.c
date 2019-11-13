// Recursively searches for a query in a directory.

#define _BSD_SOURCE
#define _GNU_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAXLENGTH 50

// Struct to hold the file name and type
typedef struct
{
    string name;
    string type;
}
path;

// Struct to hold the directory info
typedef struct
{
    string name;
    int npaths;
    path *paths;
}
directory;

// String to hold the word to seek
string key;

// The function to search for files in a directory and populate the struct
directory populate(directory dir);

// The function to recursively iterate through directories and handle files
int seek(directory dir);


int main(int argc, char *argv[])
{

    //Ensure proper number of command line arguments
    if (argc != 2 || argc != 3)
    {
        printf("Usage: ./finder <string> [directory/]\n");
        return 1;
    }

    //set key variable
    key = argv[1];

    // Create initial directory and set name string
    directory dir;

    //Set "dir"s name based on command line arguments entered
    if (argc == 3)
    {
        dir.name = argv[2];
    }
    else
    {
        dir.name = "./";
    }



    return seek(dir);
}

directory populate(directory dir)
{
    // Initialize all pointers and values in the given struct
    dir.npaths = 0;
    dir.paths = NULL;
    DIR *dirp;
    struct dirent* entry;

    dirp = opendir(dir.name);
    if (dirp == NULL)
    {
        printf("Opening directory failed. Check your input filepath!\n");
        return dir;
    }

    while ((entry = readdir(dirp)) != NULL)
    {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            // Allocate zeroed-out memory for the construction of the file name
            string name = calloc(1, strlen(dir.name) + strlen(entry->d_name) + 2);
            strcat(name, dir.name);
            strcat(name, entry->d_name);
            strcat(name, "/");

            // Reallocate memory to expand the array
            dir.paths = realloc(dir.paths, (dir.npaths + 1) * sizeof(path));

            // Add a new element to the array containing names and types
            path newPath = {.name = name, .type = "directory"};
            dir.paths[dir.npaths] = newPath;

            // Increase file count for the directory
            dir.npaths++;
        }

        // Else if entry is a file, increase file count and populate the struct
        else if (entry->d_type == DT_REG)
        {
            // Allocate zeroed-out memory for the construction of the file name
            string name = calloc(1, strlen(dir.name) + strlen(entry->d_name) + 1);
            strcat(name, dir.name);
            strcat(name, entry->d_name);

            // Reallocate memory to expand the array
            dir.paths = realloc(dir.paths, (dir.npaths + 1) * sizeof(path));

            // Add a new element to the array containing names and types
            path newPath = {.name = name, .type = "file"};
            dir.paths[dir.npaths] = newPath;

            // Increase file count for the directory
            dir.npaths++;
        }
    }

    // Close directory stream using system call closedir and return struct
    closedir(dirp);
    return dir;
}

// Recursive function to iterate through directories and search files
int seek(directory dir)
{
    //poulate directory
    populate(dir);
    /*  typedef struct
        {
        string name;
        string type;
        }
        path;

        typedef struct
        {
        string name;
        int npaths;
        path *paths;
        }
        directory;
        */
    for (int i = 0; i < dir.npaths; i++)
    {
        string file = "file";
        if (strcmp(dir.paths -> type, file) == 0)
        {
            //open the file
            FILE* fp = fopen(dir.paths -> name, "r");

            //error check on file open
            if (fp == NULL)
            {
                printf("File does not exist.\n");
                return -2;
            }

            //scan the file for key
            char keyfound [strlen(key)];

            //iterate through strings found in fp until key is found or returns null
            while (fgets(keyfound, 50, fp) != NULL && fgets(keyfound, 50, fp) != key)
            {
                fgets(keyfound, 50, fp);
            }

            if (strcmp(keyfound, key) == 0)
            {
                //open output file and error check
                FILE* fpf = fopen("found.txt", "a");
                if (fpf == NULL)
                {
                    printf("File could not be opened.\n");
                    return -2;
                }

                //Put name and file of found keyword
                for (int k = 0; k < strlen(key); k++)
                {
                    fputc(key[k], fpf);
                }
                //separating with ","
                fputc(',', fpf);

                for (int j = 0; j < strlen(key); j++)
                {
                    fputc(dir.paths -> name[j], fpf);
                }
                //seprating with newline
                fputs("\n", fpf);

                //close file
                fclose(fpf);

            }
            fclose(fp);
        }

        string dire = "directory";
        if (strcmp(dir.paths -> type, dire) == 0)
        {
            directory subdir;
            subdir.name = "subdir";
            populate(subdir);
            seek(subdir);
        }

    }

    return 0;
}
