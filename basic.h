typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

struct song_node * insert_front(struct song_node *song);
struct song_node * insert_order(struct song_node *song);
struct song_node * print_struct();
struct song_node * find_name(struct song_node *song);
struct song_node * find_artist(struct song_node *arist);
struct song_node * find_random();
struct song_node * remove_song();
struct song_node * freeL();
