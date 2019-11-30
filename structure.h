#include <stdio.h>
#include <stdbool.h>

typedef struct mot{
    char* m;
    bool disparu;
    int size;
} mot;

// make_mot(&m, "chaine de caractere");
void make_mot(mot* m, char const* str);
void destroy_mot(mot* m);
void send_mot(mot* m, int socket_dsc);
void receive_mot(mot* m, int socket_dsc);

typedef struct phraseM{
    int taille;
    mot* listeMots;
}phraseM;

// char const* tab[] = {"nane", "truc", "bidule"};
// make_phraseM(&ph, 5, tab);
void make_phraseM(phraseM* ph, int nb_mot, char const** words);
void destroy_phraseM(phraseM* ph);
void send_phraseM(phraseM* ph, int socket_dsc);
void receive_phraseM(phraseM* ph, int socket_dsc);

typedef struct memoire{
    phraseM p;
} memoire;
