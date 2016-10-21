#include "list.c"

int main(){
  srand(time(NULL));
  song_node *try = (song_node *)malloc(sizeof(song_node));
  make_song(try, "boom boom pow", "black eyed peas");
  printf("Initial test:\n");
  print_struct(try);

  printf("\nTesting insert: true colors, hello, lights, get lucky\n");
  try = insert_order(try, "true colors", "cyndi lauper");print_struct(try);
  try = insert_order(try, "hello", "adele");print_struct(try);
  try = insert_order(try, "lights", "ellie goulding");print_struct(try);
  try = insert_order(try, "get lucky", "daft punk");print_struct(try);

  printf("\nTesting artist finds: adele, ellie goulding, daft punk, fetty wap\n");
  print_struct(find_artist(try, "adele"));
  print_struct(find_artist(try, "ellie goulding"));
  print_struct(find_artist(try, "daft punk"));
  print_struct(find_artist(try, "fetty wap"));

  printf("\nTesting song finds: lights, get lucky, trap queen, hello\n");
  print_struct(find_name(try, "lights"));
  print_struct(find_name(try, "get lucky"));
  print_struct(find_name(try, "trap queen"));
  print_struct(find_name(try, "hello"));

  printf("\nTesting random finds\n");
  print_struct(find_random(try));
  print_struct(find_random(try));
  print_struct(find_random(try));

  printf("\nTesting delete: get lucky, lights, hello\n");
  print_struct(try);
  try = remove_song(try, "get lucky");print_struct(try);
  try = remove_song(try, "lights");print_struct(try);
  try = remove_song(try, "hello");print_struct(try);

  printf("\nFreeing\n");
  freeL(try);

  printf("\n***If you want to see tests for the second group of functions, run: make list\n\n");
  return 0;
}
