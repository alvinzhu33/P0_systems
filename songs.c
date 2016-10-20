#include "list.c"

int artist_where(const char artist[256]){
    char first = artist[0];
    return first - 97;
}

//Add songs.
void add_song(char name[256], char artist[256]){
    int index = artist_where(artist);
    if(! table[index]){
        song_node *song = (song_node *)malloc(sizeof(song_node));
        make_song(song, name, artist);
        table[index]= song;
    }else{
        table[index] = insert_order(table[index], name, artist);
    }
};

//Search for a song.
song_node * search_song(char name[256], char artist[256]){
    int index = artist_where(artist);
    printf("= %s-%s :", name, artist);
    if(! table[index]){
        printf(" NOT FOUND :'('\n");
    }else{
        if(find_name(table[index], name)){
            printf(" %s-%s\n", name, artist);
            return(find_name(table[index],name));
        };
    }
};

//Search for an artist.
song_node * search_artist(char artist[256]){
  int index = artist_where(artist);
  if(table[index]){
    return find_artist(table[index], artist);
  }
};

//Print out all the entries under a certain letter.
void print_letter(char x);

//Print out all the songs of a certain artist
void print_artist(char artist[256]){
    printf("= %s's songs: ", artist);
    if(search_artist(artist)){
        print_struct(search_artist(artist));
    }else{
        printf("NO SONGS BY %s\n", artist);
    }
};

//Print out the entire library.
void print_all(){
    int i;
    for(i=0; i<26; i++){
        if(table[i]){
            printf("%c artists:\n", i+97);
            print_struct(table[i]);
        }
    }
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
    //print_all();
    //table[25]=6;
    printf("\nAdding\n");
    add_song("mamma mia", "abba");
    add_song("dancing queen", "abba");
    add_song("hello", "adele");
    add_song("send my love", "adele");
    add_song("thunderstruck", "ac/dc");
    add_song("alive","pearl jam");
    add_song("even flow","pearl jam");
    add_song("time","pink floyd");
    add_song("yello ledbetter","pearl jam");
    add_song("spectrum","zedd");
    add_song("replay", "zendaya");
    add_song("my baby", "zendaya");
    add_song("clarity","zedd");
    print_all();

    printf("\nFinding songs:\n");
    search_song("dancing queen", "abba");
    search_song("even flow", "pearl jam");
    search_song("cookie", "blah");
    search_song("replay", "zendaya");

    printf("\nFinding artist:\n");
    print_artist("ac/dc");
    print_artist("pearl jam");
    print_artist("kesha");
    print_artist("zendaya");
    return 0;
}
