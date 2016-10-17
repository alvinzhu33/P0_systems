typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node * insert_front(song_node *list, char name[256], char artist[256]);
song_node * insert_order(song_node *list, char name[256], char artist[256]);
void print_struct(song_node *list);
song_node * find_name(song_node *list, char name[256]);
song_node * find_artist(song_node *list, char artist[256]);
song_node * find_random(song_node *list);
song_node * remove_song(song_node *list, char name[256]);
song_node * freeL(song_node *list);
