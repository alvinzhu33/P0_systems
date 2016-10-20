#include "list.c"

int artist_where(const char artist[256]){
    char first = artist[0];

    int i = 97;
    while(i < 122){
        if(i == first){
            return (i - 97);
        }
        i++;
    }
}
//Add songs.
void add_song(char name[256], char artist[256]){
    int index = artist_where(artist);
    if(! table[index]){
        song_node *song = (song_node *)malloc(sizeof(song_node));
        table[index]= song;
    }
    table[index] = insert_order(table[index], name, artist);
};

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
        if(table[i]){
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
    //printf("%d\n", artist_where("adele"));
    print_all();
    add_song("hello", "adele");
    print_all();
    return 0;
}
