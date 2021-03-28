#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
 
// Node Link List
struct Node{
    char data;
    struct Node* next;
};
 
void reverse(struct Node**);
bool palindrom(struct Node* head);
void push(struct Node** newHead, char *word);
void gabungLists(struct Node* head1,struct Node* head2);
 
// fungsi mengecek suatu linked list palindrom atau tidak
bool palindrom(struct Node* head){
    // Isi dengan implementasi Anda!
    // Bisa menambahkan fungsi lain untuk mempermudah fungsi ini
}

// fungsi untuk menggabungkan 2 buah linked list dalam salah satu linked list
// linked list head2 akan digabung ke linked list head1
void gabungLists(struct Node* head1,struct Node* head2){
    // Isi dengan implementasi Anda!
}
 
 
// fungsi membalikkan isi linked list
void reverse(struct Node** head){
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return;
}


// fungsi untuk memasukkan kata kedalam list
void push(struct Node** newHead, char *word){
    struct Node* temp;
    int i;

    for(i = 0; word[i]!=0; i++){
        // membuat node untuk data baru
        temp = (struct Node*)malloc(sizeof(struct Node));
        
        // memasukkan data ke dalam list
        temp->data = word[i];

        // mengganti head
        temp->next = *newHead; 
        *newHead = temp;
    }
}



int main(){
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* head3 = NULL;
    char kata1[20];
    char kata2[20];
    int i;
    
    // input 
    printf("Masukkan kata pertama : ");
    scanf("%s", &kata1);
    printf("Masukkan kata kedua   : ");
    scanf("%s", &kata2);

    // memasukkan kata pertama kedalam linked list pertama
    push(&head1, kata1);

    // cek kata pertama palindrom atau tidak
    if(palindrom(head1)){
        printf("\nKata %s palindrom.\n", kata1);
    } else{
        printf("\nKata %s tidak palindrom.\n", kata1);
    }

    // memasukkan kata kedua kedalam linked list kedua
    push(&head2, kata2);

    // cek kata kedua palindrom atau tidak
    if(palindrom(head2)){
        printf("Kata %s palindrom.\n\n", kata2);
    } else{
        printf("Kata %s tidak palindrom.\n\n", kata2);
    }

    // menggabungkan kata kedua ke kata pertama
    // ketika kata dimasukkan ke linked list, kata menjadi terbalik
    // maka untuk menggabungkan kedua linked list akan dibalik kemudian digabung
    reverse(&head1);
    reverse(&head2);
    gabungLists(head1, head2);

    // cek kata gabungan palindrom atau tidak
    if(palindrom(head1)){
        printf("Gabungan kedua kata palindrom.\n");
    } else{
        printf("Gabungan kedua kata tidak palindrom.\n");
    }

    return 0;
}
