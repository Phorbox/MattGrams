#include <string.h>

struct SongDLL
{
    char songName[100];
    struct SongDLL *next;
    struct SongDLL *previous;
} SongDLL;

int frontTraverse(SongDLL *playlist, char *searchKey)
{
    int found;
    while (playlist && found != 1)
    {
        if (!strcmp(playlist,searchKey){
                found = 1;
        }
        playlist = playlist->next
    }
    return found;
}

#inclu
add_s_es(char *string){
    
}