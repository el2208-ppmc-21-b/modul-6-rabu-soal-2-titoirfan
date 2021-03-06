#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
 
// Node Link List
struct Node{
    char data;
    struct Node* next;
};
 
void reverse(struct Node**);
bool cekList(struct Node*, struct Node*);
bool palindrom(struct Node* head);
void push(struct Node** newHead, char *word);
void gabungLists(struct Node* head1,struct Node* head2);
 
// fungsi mengecek suatu linked list palindrom atau tidak
bool palindrom(struct Node* head){
    struct Node* slow_ptr = head; 
    struct Node* fast_ptr = head;
    struct Node* second_half;
    struct Node* prev_of_slow_ptr = head;
    struct Node* midnode = NULL; // untuk menyimpan data tengah linked list ganjil
    
    bool hasil = true; // hasil penentuan linked list palindrom

    // linked list memiliki data
    if (head != NULL && head->next != NULL) {
        // mengambil data tengah dari list
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next;
 
            // untuk elemen ganjil
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        // kalau linked list genap fast_ptr menjadi NULL
        // menyimpan node tengah linked list ganjil di midnode
        if (fast_ptr != NULL) {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
 
        // komparasi huruf
        second_half = slow_ptr;
        prev_of_slow_ptr->next = NULL; 
        reverse(&second_half); 
        hasil = cekList(head, second_half); 
 
        // mengembalikan data dalam linked list ke posisi semula
        reverse(&second_half); 
 
        // untuk data tengah linked list ganjil
        if (midnode != NULL){
            prev_of_slow_ptr->next = midnode;
            midnode->next = second_half;
        }
        else{
            prev_of_slow_ptr->next = second_half;
        }
    }
    return hasil;
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

 
// fungsi mengecek dua buah linked list mempunyai data yang sama atau tidak
bool cekList(struct Node* head1, struct Node* head2){
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
 
    while (temp1 && temp2){
        // jika data sama, akan dilanjutkan pengecekan
        if (temp1->data == temp2->data){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }else{
            return 0; // jika tidak maka akan dikembalikan salah
        }
    }
 
    // Kalau keduanya sampai di akhir (benar)
    if (temp1 == NULL && temp2 == NULL){
        return 1;
    }
    
    // jika tidak akan dikembalikan salah
    return 0;
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


// fungsi untuk menggabungkan 2 buah linked list dalam salah satu linked list
// linked list head2 akan digabung ke linked list head1
void gabungLists(struct Node* head1,struct Node* head2){
    if(head1 != NULL && head2 != NULL ){ // jika a dan b memiliki isi
        // menggabungkan tail list dari a dengan b
        if (head1->next == NULL){
            head1->next = head2;
        }
        else{ // jika a->next tidak null maka akan diiterasi
            gabungLists(head1->next,head2);
        }
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
