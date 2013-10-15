#include <stdio.h>
#define MAX_LEN 100

//create type 'CipherText'
typedef struct{
  int shift;
  char text[MAX_LEN];
}CipherText;

//declare variant
int i;

//declare function
void cipher(const char* plain_text, int shift, CipherText* cipher);
void decipher(const CipherText* cipher, char* plain_text);

//coding function 'cipher'
//input... ("HELLO WORLD", 3, &a)
//output... &a->text: KHOOR#ZRUOG
void cipher(const char* plain_text, int shift, CipherText* ioCipher){
  ioCipher->shift = shift;
  for(i = 0; i < MAX_LEN; i++){
    if(plain_text[i] == 0){
      ioCipher->text[i] = 0;
      break;
    }
    ioCipher->text[i] = plain_text[i] + ioCipher->shift;
  }
}

//decode function 'decipher'
//input... (&a, plain_text)
//output... plain_text: HELLO WORLD
void decipher(const CipherText* cipher, char* plain_text){
  for(i = 0; i < MAX_LEN; i++){
    if(cipher->text[i] == 0){
      plain_text[i] = 0;
      break;
    }
    plain_text[i] = cipher->text[i] - cipher->shift;
  }
}

int main(int argc, const char* argv[]){
  CipherText a;
  char plain[MAX_LEN];
  cipher("Hello world!", 3, &a);
  decipher(&a, plain);
  printf("%s = %s\n", plain, a.text);
  return 0;
}
