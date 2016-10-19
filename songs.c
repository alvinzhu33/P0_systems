#include "list.c"

int artist_where(song_node *song){
    int i = strcmp((song->artist), "a");
    if(i == 100){
        return 0;
    }
    return i;
}
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
song_node * print_all(){
    int i;
    for(i=0; i<26; i++){
        printf("%c artists:\n", i+97);
        while(table[i]){
            print_struct(table[i]);
        }
    }
    return 0;
};

//Shuffle - print out a series of randomly chosen songs.
void print_random();

//Delete a song
void delete_song(char name[256]);

//Delete all the nodes.
void clear();

int main(){
    int clearing = 0;
    for(clearing; clearing<26; clearing++){
        table[clearing]=0;
    }
}
