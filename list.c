#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

song_node *table[26];

int artist_where(song_node *song){
    int i = strcmp((song->artist), "a");
    if(i == 100){
        return 0;
    }
    return i;
}
song_node * insert_front(song_node *list, char name[256], char artist[256]){
    song_node *song = (song_node *)malloc(sizeof(song_node));
    strcpy(song->name, name);
    strcpy(song->artist, artist);
    song->next=list;
    return song;
};
song_node * insert_order(song_node *list, char name[256], char artist[256]){
    song_node *song = (song_node *)malloc(sizeof(song_node));
    strcpy(song->name, name);
    strcpy(song->artist, artist);
    song_node *current = list;
    if(strcmp(artist, list->artist)<0){
        return insert_front(list, name, artist);
    }
    while(current->next){
        if(strcmp(artist, current->artist)>0 && strcmp(artist, current->next->artist)<0){
            song->next = current->next;
            current->next = song;
            return list;
        }
        current = current->next;
    }
    current->next = song;
    return list;
};
void print_struct(song_node *list){
    /*int i;
    for(i=0; i<26; i++){
        printf("%c", i+97);
        printf("%s\n", " songs:");
        while(table[i]){}
    }
    return 0;*/
    printf("%s-%s ", list->name, list->artist);
    list = list->next;
    while(list->name){
        printf("-> %s-%s ", list->name, list->artist);
        list = list->next;
    }
    printf("\n");
};
void find_name(song_node *list, char name[256]){
    while(list){
        if(strcmp(list->name, name)==0){
	  return list;;
        }
        list = list->next;
    }
    return 0;
};
song_node * find_artist(song_node *list, char artist[256]){
    while(list){
        if(strcmp(list->artist, artist)==0){
            return list;
        }
        list = list->next;
    }
    return 0;
};
song_node * find_random(song_node *list){
    int counter=0;
    song_node *index;
    while(index){
        counter++;
        index->next;
    }
    int ran = rand() % counter;
    while(counter){
        list = list->next;
        counter--;
    }
    return list;
};
song_node * remove_song(song_node *list, char name[256]){
    song_node *current = list;
    if(strcmp(name, current->name)==0){
        return list->next;
    }
    while(current->next){
        if(strcmp(name, current->next->name)==0){
            current->next = current->next->next;
            return list;
        }
        current = current->next;
    }
    return list;
};
song_node * freeL(song_node *list){
    song_node *current = list;
    song_node *nextSong = (song_node *)malloc(sizeof(song_node));
    while(current){
        nextSong = current->next;
        free(current);
        current = nextSong;
    }
    return list;
};

int main(){
    song_node *try;
    try = (song_node *)malloc(sizeof(song_node));
    strcpy(try->name,"boom boom pow");
    strcpy(try->artist, "black eyed peas");
    print_struct(try);
    printf("\nTesting insert\n");
    try = insert_order(try, "true colors", "cyndi lauper");
    try = insert_order(try, "hello", "adele");
    try = insert_order(try, "lights", "ellie goulding");
    try = insert_order(try, "get lucky", "daft punk");
    print_struct(try);
    printf("\nTesting delete\n");
    try = remove_song(try, "get lucky");
    try = remove_song(try, "lights");
    try = remove_song(try, "hello");
    print_struct(try);
    //freeL(try);

    printf("\nTesting finds\n");
    find_artist(try, "daft punk");
    /*printf("%s\n", find_artist(try, "adele"));
    printf("%s\n", find_artist(try, "ellie goulding"));
    printf("%s\n", find_artist(try, "fetty wap"));*/

    /*printf("%d\n", i);
    //printf("%d\n", artist_where(try));
    print_struct();*/
    return 0;
}
