/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 6 - Linked List
*Percobaan        : -
*Hari dan Tanggal : Rabu, 30 Maret 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>

// Struct linked list
struct buffer {
	int data;
	struct buffer* next;
	struct buffer* prev;
};

int main() {
	// Input jumlah elemen
	int n;
	printf("Masukkan jumlah elemen: ");
	scanf("%d", &n);

	// Inisialisasi head dan tail dari masing-masing linked list
	struct buffer* head1; head1 = (struct buffer*)malloc(sizeof(struct buffer));
	struct buffer* head2; head2 = (struct buffer*)malloc(sizeof(struct buffer));
	struct buffer* tail1; tail1 = (struct buffer*)malloc(sizeof(struct buffer));
	struct buffer* tail2; tail2 = (struct buffer*)malloc(sizeof(struct buffer));

	// Temporary variables, untuk passing pointer
	struct buffer* temp1 = head1; struct buffer* temp2 = head2;
	struct buffer* temp3 = tail1; struct buffer* temp4 = tail2;

	temp3->next = temp1;
	temp4->next = temp2;

	// Pengisian LL pertama
	printf("Masukkan elemen linked list pertama: ");
	int i = 0;
	for (i=0; i<n-1; ++i) {
		temp1->prev = temp3;
		scanf("%d", &(temp1->data));
		if (i != n-2) {
			temp1->next = (struct buffer*)malloc(sizeof(struct buffer));
		}
		else {
			temp1->next = tail1;
		}
		temp1 = temp1->next;
		temp3 = temp3->next;
	}
	scanf("%d", &(temp1->data));
	temp1->prev = temp3;

	// Pengisian LL kedua
	printf("Masukkan elemen linked list kedua: ");
	i = 0;
	for (i=0; i<n-1; ++i) {
		temp2->prev = temp4;
		scanf("%d", &(temp2->data));
		if (i != n-2) {
			temp2->next = (struct buffer*)malloc(sizeof(struct buffer));
		}
		else {
			temp2->next = tail2;
		}
		temp2 = temp2->next;
		temp4 = temp4->next;
	}
	scanf("%d", &(temp2->data));\
	temp2->prev = temp4;

	// Input flip logic
	printf("Flip linked list kedua: ");
	int flip = 0;
	scanf("%d", &flip);

	// Input shift value
	printf("Shift linked list kedua: ");
	int shift = 0;
	scanf("%d", &shift);

	// Penghitungan hasil
	int res = 0;
	if (flip == 1) {
		while (shift != 0) {
			if (shift > 0) {
				head2 = head2->prev;
				temp2 = temp2->prev;
				shift--;
			}
			else {
				head2 = head2->next;
				temp2 = temp2->next;
				shift++;
			}
		}
		temp1 = head1;
		temp2 = head2;
		for (i=0; i<n; i++) {
			res = res + temp1->data*temp2->data;
			temp1 = temp1->next; temp2 = temp2->prev;
		}
	}
	else if (flip == 0) {
		while (shift != 0) {
			if (shift > 0) {
				head2 = head2->next;
				temp2 = temp2->next;
				shift--;
			}
			else {
				head2 = head2->prev;
				temp2 = temp2->prev;
				shift++;
			}
		}
		temp1 = head1;
		temp2 = head2;
		for (i=0; i<n; i++) {
			res = res + temp1->data*temp2->data;
			temp1 = temp1->next; temp2 = temp2->next;
		}
	}

	printf("Hasil: %d", res);

}
