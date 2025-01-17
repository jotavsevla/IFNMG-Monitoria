#include "lista.h"
#include <stdlib.h>

void inicializa_lista(Lista * ap_lista){
    *ap_lista = NULL;
}

No* cria_no (No* proximo, int valor){
    No* novo_no = (No*) malloc (sizeof (No));
    novo_no->valor = valor;
    novo_no->proximo = proximo;
    return novo_no;
}

void insere_fim(Lista * ap_lista, int valor){

    //percorrendo a lista
    if((*ap_lista) == NULL){  
       insere_inicio(ap_lista,valor);
       return;
    }

    // criar novo no.
    No* novo_no = cria_no (NULL, valor);
    No* temp = *ap_lista;  // FEEDBACK: podemos comecar do primeiro elemento

    while (temp->proximo != NULL ){  
        temp = temp->proximo;
    }

    temp->proximo = novo_no; 
}

void insere_inicio(Lista * ap_lista, int valor){
    //No* novo_no = (No*) malloc (sizeof(No));
    //novo_no->valor = valor;
    //novo_no->proximo = *ap_lista;
    No* novo_no = cria_no (*ap_lista, valor);
    *ap_lista = novo_no;
    return;
}

int remove_fim(Lista * ap_lista){
    No* temp_1 = *ap_lista;
    
    int valor;    

    // no caso de 0 ou 1 elementos.
    if (temp_1 == NULL)
        exit(EXIT_FAILURE);

    if (temp_1->proximo == NULL){
        valor = temp_1->valor;
        free (temp_1);
        *ap_lista = NULL;
        return valor;
    }
    // demais casos.
    while (temp_1->proximo != NULL){
        temp_1 = temp_1->proximo;
    }
    valor = temp_1->valor;
    
    free (temp_1);
    return valor;
}

int remove_inicio(Lista * ap_lista){
  
    int valor = (*ap_lista)->valor;
    No* temp = *ap_lista;
    *ap_lista = (*ap_lista)->proximo;
    
    free (temp); 
    return valor;
}

void imprime(Lista lista){
    // TODO: arrumar printf
    printf("(");
    for (No* temp = lista; temp != NULL; temp = temp->proximo)
        printf (",%d",temp->valor);
    printf (")\n");
}

void desaloca_lista(Lista *ap_lista){
    No* apagar;
    for (No* temp = *ap_lista; temp != NULL; temp = temp->proximo){
      apagar = temp;
      free (apagar);
    }
    return;
}
int busca(Lista lista, int valor){
    int i = 0; //contador de ocorrencias    
    for (No* busca = lista; busca != NULL; busca = busca->proximo){
      if (busca->valor == valor) i++; 
    }
    i > 0 ? return i : return -1;
}
int remove_ocorrencias(Lista *ap_lista, int valor){ 
    int i = 0;
    No* apagar;
    No* novo_no = *ap_lista;
    if (novo_no->valor == valor){
      apagar = novo_no;
      *ap_lista = novo_no->proximo;
      free (apagar);
      i++;
    }
    for (novo_no = *ap_lista; novo_no != NULL; novo_no = novo_no->proximo){
      if (novo_no->proximo->valor == valor){
        apagar = novo_no->proximo;
        novo_no->proximo = novo_no->proximo->proximo;
        free (apagar);
        i++;
      }
    }
    return i;
}
