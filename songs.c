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
        printf(" NOT FOUND\n");
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
void print_letter(char x){
    printf("= %c artists: ", x);
    if(table[x-97]){
        print_struct(table[x-97]);
    }else{
        printf("NO SONGS FROM %c ARTISTS\n", x);
    }
};

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
    int counter=0;
    for(i=0; i<26; i++){
        if(table[i]){
            counter++;
            printf("%c artists: ", i+97);
            print_struct(table[i]);
        }
    }
    if(!counter){
        printf("PLAYLIST EMPTY\n");
    }
};

void * print_first(song_node * list){
    printf("%s-%s", list->name, list->artist);
}

//Shuffle - print out a series of randomly chosen songs.
void shuffle(){
    int artist_count=0;
    int counter=0;
    int index[26];
    while(counter<26){
        if(table[counter]){
            index[artist_count]=counter;
            artist_count++;
        }
        counter++;
    }
    counter=0;

    int artists_list[artist_count];
    while(counter<artist_count){
        artists_list[counter]=index[counter];
        counter++;
    }

    counter=0;
    srand(time(NULL));
    printf("| ");
    int which = rand() % artist_count;
    print_first(find_random(table[artists_list[which]]));
    while(counter<2){
        which = rand() % artist_count;
        printf(" -> ");
        print_first(find_random(table[artists_list[which]]));
        counter++;
    }
    printf(" |");
};

//Delete a song
void delete_song(char name[256], char artist[256]){
    int index = artist_where(artist);
    table[index] = remove_song(table[index], name);
};

//Delete all the nodes.
void clear(){
    int i=0;
    while(i<26){
        if(table[i]){
            printf("Freeing %c artists... ", i+97);
            free(table[i]);
            table[i]=0;
        }
        i++;
    }
    printf("DONE REMOVING ALL NODES\n");
};
