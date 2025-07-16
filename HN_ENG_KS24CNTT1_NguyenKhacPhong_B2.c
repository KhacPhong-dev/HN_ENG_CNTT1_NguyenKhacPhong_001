#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

 int main() {
     int choice;
     while (true) {
         printf("Chon chuc nang cua ban:\n");
         printf("1.Them ky tu vao cuoi vat ban\n");
         printf("2.Hoan tac thao tac gan nhat\n");
         printf("3.Phuc hoi thao tac vua undo\n");
         printf("4.Hien thi vat ban hien tai\n");
         printf("5.Thoat chuong trinh\n");
         printf("Nhap lua chon: ");
         scanf("%d", &choice);
         switch (choice) {
             case 1: {} break;
             case 2: {} break;
             case 3: {} break;
             case 4: {} break;
             case 5: {
                 printf("Chao ban!\n");
                 exit(0);
             } break;
             default: {
                 printf("vui long nhap lai lua chon\n");
             }
         }
     }
     return 0;
 }
