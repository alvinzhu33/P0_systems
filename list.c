#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headers.h"

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
  if(list){
    printf("| %s-%s ", list->name, list->artist);
    list = list->next;
    while(list->name){
      printf("-> %s-%s ", list->name, list->artist);
      list = list->next;
    }
    printf("|\n");
  }
};
song_node * find_name(song_node *list, char name[256]){
  while(list){
    if(strcmp(list->name, name)==0){
      return list;
    }
    list = list->next;
  }
  printf("No song titled: %s\n", name);
  return 0;
};
song_node * find_artist(song_node *list, char artist[256]){
  while(list){
    if(strcmp(list->artist, artist)==0){
      return list;
    }
    list = list->next;
  }
  printf("No song with artist: %s\n", artist);
  return 0;
};
song_node * find_random(song_node *list){
  int counter=0;
  song_node *index=list;
  while(index){
    counter++;
    index = index->next;
  }
  int ran = rand() % counter;
  while(ran){
    list = list->next;
    ran--;
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
