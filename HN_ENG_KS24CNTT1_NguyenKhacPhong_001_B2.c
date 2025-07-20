// Bài 2:
// Viết chương trình mô phỏng quá trình soạn thảo văn bản. Người dùng có thể thực hiện chương trình với các chức năng cơ bản sau:
// ——————————— TEXT EDITOR ———————————
// INSERT x: thêm ký tự x vào cuối văn bản
// UNDO: hoàn tác thao tác gần nhất (xóa ký tự cuối)
// REDO: phục hồi thao tác vừa undo
// HIỂN THỊ: in văn bản hiện tại
// THOÁT: kết thúc chương trình

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