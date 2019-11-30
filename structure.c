#include "structure.h"
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>


void make_mot(mot* m, char const* str) {
  m->size = strlen(str);
  m->disparu = false;
  m->m = (char*)malloc(sizeof(char) * (m->size + 1));
  strcpy(m->m, str);
}

void destroy_mot(mot* m) {
  free(m->m);
}

static size_t const INT_STR_SIZE = 20;

void send_mot(mot* m, int socket_dsc) {
  // 1. send the word size without including the \0
  // 2. send the chars(the word)
  // 3. other metadata
  //note : tout en caractères
  char buf[INT_STR_SIZE]; // size max of int converted in chars
  snprintf(buf, INT_STR_SIZE, "%d", m->size);
  // 1. sending the word size (w/o \0)
  send(socket_dsc, buf, sizeof(buf), 0);
  
  // 2. sending the chars(the word)
  send(socket_dsc, m->m, m->size, 0);
}

void receive_mot(mot* m, int socket_dsc) {
    char buf[INT_STR_SIZE];
    if (recv(socket_dsc, buf, sizeof(buf), 0)==-1){
        //erreur
    }
    m->size = atoi(buf);
    m->m = (char*)malloc(sizeof(char) * (m->size + 1));
    if (recv(socket_dsc, m->m, m->size, 0)==1){
        //erreur
    }
}
 