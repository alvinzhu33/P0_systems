#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basic.h"

song_node *table[26];

int artist_where(song_node *song){
    int i = strcmp((song->artist), "a");
    if(i == 100){
        return 0;
    }
    return i;
}
song_node * insert_front(char name[256], char artist[256]){
    song_node *song = (song_node *)malloc(sizeof(song_node));
    strcpy(song->name, name);
    strcpy(song->artist, artist);
    song->next=table[artist_where(song)];
    return song;
};
song_node * insert_order(song_node *song){
    return 0;
};
song_node * print_struct(){
    int i;
    for(i=0; i<26; i++){
        printf("%c", i+97);
        printf("%s\n", " songs:");
        while(table[i]){}
    }
    return 0;
};
song_node * find_name(song_node *song){
    return 0;
};
song_node * find_artist(song_node *arist){
    return 0;
};
song_node * find_random(){
    return 0;
};
song_node * remove_song(){
    return 0;
};
song_node * freeL(){
    return 0;
};

int main(){
    song_node *try;
    try = (song_node *)malloc(sizeof(song_node));
    strcpy(try->name, "hello");
    strcpy(try->artist, "adele");
    //printf("%d\n", artist_where(try));
    print_struct();
    return 0;
}
