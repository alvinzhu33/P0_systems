#include "songs.c"

int main(){
    int clearing = 0;
    for(clearing; clearing<26; clearing++){
        table[clearing]=0;
    }

    printf("\nInitial print all:\n");
    print_all();

    printf("\nAdding: \n");
    add_song("mamma mia", "abba");
    add_song("dancing queen", "abba");
    add_song("hello", "adele");
    add_song("send my love", "adele");
    add_song("thunderstruck", "ac/dc");
    add_song("alive","pearl jam");
    add_song("even flow","pearl jam");
    add_song("time","pink floyd");
    add_song("yellow ledbetter","pearl jam");
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

    printf("\nFinding artists by letter:\n");
    print_letter('a');
    print_letter('p');
    print_letter('k');
    print_letter('z');
    print_letter('w');

    printf("\nBefore remove: \n");
    print_all();
    printf("Remove songs: dancing queen, mamma mia, yellow ledbetter, replay\n");
    delete_song("dancing queen", "abba");
    delete_song("mamma mia", "abba");
    delete_song("yellow ledbetter", "pearl jam");
    delete_song("replay", "zendaya");
    print_all();

    printf("\nShuffling:\n");
    shuffle();
    printf("\n");

    printf("\nClearing:\n");
    clear();
    printf("Print all:\n");
    print_all();
    return 0;
}
