#include <stdio.h>
#include <stdlib.h>
#include "basic.h"

song_node *table[26];

int arist_where(struct song_node *song){
  return (int)song->artist[0] - 97;
}
struct song_node * insert_front(struct song_node *song){
  return 0;
};
struct song_node * insert_order(struct song_node *song){
  return 0;
};
struct song_node * print_struct(){
  return 0;
};
struct song_node * find_name(struct song_node *song){
  return 0;
};
struct song_node * find_artist(struct song_node *arist){
  return 0;
};
struct song_node * find_random(){
  return 0;
};
struct song_node * remove_song(){
  return 0;
};
struct song_node * freeL(){
  return 0;
};

int main(){
  struct song_node *try;
  try = (struct song_node *)malloc(sizeof(struct song_node));
  try->name="hello";
  try->artist="ad";
  printf("%d\n", artist_where(try));
  return 0;
}
