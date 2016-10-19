typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node *table[26];

song_node * insert_front(song_node *list, char name[256], char artist[256]);
song_node * insert_order(song_node *list, char name[256], char artist[256]);
void print_struct(song_node *list);
song_node * find_name(song_node *list, char name[256]);
song_node * find_artist(song_node *list, char artist[256]);
song_node * find_random(song_node *list);
song_node * remove_song(song_node *list, char name[256]);
song_node * freeL(song_node *list);

void add_song(char name[256], char artist[256]);
void search_song(char name[256]);
void search_artist(char artist[256]);
song_node * print_letter(char x);
song_node * print_artist(char artist[256]);
song_node * print_all();
void print_random();
void delete_song(char name[256]);
void clear();
