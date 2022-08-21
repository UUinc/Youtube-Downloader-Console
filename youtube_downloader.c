#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include <windows.h>
#include <Lmcons.h>

int main()
{
    char path_destination[100] = "C:\\Users\\";
    char username[UNLEN+1];
    char youtube_Link[100];
    char extention[5];
    char command[255];
    int choice;
    
    //get the current username
    DWORD username_len = UNLEN+1;
    GetUserName(username, &username_len);

    strcat(path_destination, username);
    strcat(path_destination, "\\");

    printf("Youtube downloader\n\n");
    puts("Download:");
    puts(" 1.Video");
    puts(" 2.Audio");

    printf(" >> ");
    scanf("%d", &choice);

    system("cls");

    printf("Youtube downloader\n\n");
    printf(" Youtube Video URL : ");
    fflush(stdin);
    gets(youtube_Link);

    strcpy(command, "youtube-dl.exe -f ");
    switch (choice)
    {
        case 1:
            strcpy(extention, "mp4");
            strcat(command, "mp4 ");

            strcat(path_destination, "Videos\\");
            break;
        case 2:
            strcpy(extention, "m4a");
            strcat(command, "m4a ");

            strcat(path_destination, "Music\\");
            break;
    }
    
    strcat(command, "-o ");
    strcat(command, path_destination);
    strcat(command, "%(title)s.%(ext)s ");
    strcat(command, youtube_Link);
    system(command);

    printf("Done\n");

    getch();
    return 0;
}