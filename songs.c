#include "list.c"

//Add songs.
void add_song(char name[256], char artist[256]);
//Search for a song.
void search_song(char name[256]);
//Search for an artist.
void search_artist(char artist[256]);
//Print out all the entries under a certain letter.
song_node * print_letter(char x);
//Print out all the songs of a certain artist
song_node * print_artist(char artist[256]);
//Print out the entire library.
song_node * print_all();
//Shuffle - print out a series of randomly chosen songs.
void print_random();
//Delete a song
void delete_song(char name[256]);
//Delete all the nodes.
void clear();
