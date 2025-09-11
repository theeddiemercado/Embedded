#define ARRAY_SIZE 9
int main(void) {
  unsigned int source[ARRAY_SIZE] = {3, 2, 1, 3, 2, 1, 3, 2, 1};
  unsigned int destination[ARRAY_SIZE];

  // done is a flag we are using to represent the completion of the copying of
  // the array
  unsigned int done = 0;

  // This loop simply copies elements of the source to the destination array in
  // the reverse order i is the index we are using. We are copying from the end
  // of the array and go backward to the beginning You should fix this bug by
  // changing they type of i (There are other ways, but we need you to fix it
  // this way.)
  int i = ARRAY_SIZE - 1;
  while (i >= 0) {
    destination[i] = source[ARRAY_SIZE - i - 1];
    i--;
  }

  done = 1;
}
