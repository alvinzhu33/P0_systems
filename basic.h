typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node * insert_front(char name[256], char artist[256]);
song_node * insert_order(song_node *song);
song_node * print_struct();
song_node * find_name(song_node *song);
song_node * find_artist(song_node *arist);
song_node * find_random();
song_node * remove_song();
song_node * freeL();
