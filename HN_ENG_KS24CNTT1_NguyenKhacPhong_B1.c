
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct task {
    int id;
    char title[100];
    int priority;
    char deadline[100];
} Task;

typedef struct taskList {
    Task task;
    struct taskList* next;
} TaskList;

typedef struct historyList {
    Task task;
    struct historyList* next;
    struct historyList* prev;
} HistoryList;
void addTask(TaskList** head, Task task) {
    TaskList* newTask = (TaskList*) malloc(sizeof(TaskList));
    newTask->task =task;
    newTask->next = *head;
    *head = newTask;
}
void printTask(TaskList* head) {
    TaskList* current= head;
    while (current!=NULL) {
        printf("ID: %d \n",current->task.id);
        printf("Title: %s \n",current->task.title);
        printf("Priority: %d \n",current->task.priority);
        printf("Deadline: %s \n",current->task.deadline);
        printf("\n");
        current = current->next;
    }
    printf("\n");
    printf("---------------------------------\n");

}
void deleteTask(TaskList** head, int id) {
    TaskList* current = *head;
    TaskList* prev = NULL;
    while (current !=NULL && current->task.id!= id) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Task not found\n");
        return;
    }
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;

    }
}

void updateTask(TaskList** head, int id, char title[100], int priority, char deadline[100]) {
    TaskList* current = *head;
    while (current !=NULL && current->task.id!= id) {
        current = current->next;


    }
    if (current == NULL) {
        printf("Task not found\n");

    }
    else {
        strcpy(current->task.title, title);
        current->task.priority = priority;
        strcpy(current->task.deadline, deadline);
    }


}
void markTask(HistoryList** head, Task task,int id) {
    HistoryList* newHistory = (HistoryList*) malloc(sizeof(HistoryList));
    newHistory->task = task;
    newHistory->next = *head;
    if (*head !=NULL) {
        (*head)->prev = newHistory;
    }
    TaskList* current = *head;
    while (current !=NULL && current->task.id!= id) {
        current = current->next;


    }
    if (current == NULL) {
        printf("Task not found\n");

    }
    else {
        deleteTask(&current, task.id);
    }

}


void sortTask(TaskList **head) {
    TaskList *current = *head;
    TaskList *temp = NULL;
    TaskList *index = NULL;
    while (current !=NULL) {
        index = current;
        while (index->next !=NULL && index->next->task.priority < current->task.priority) {
            temp = index->next;
            index->next = temp->next;
            temp->next = current;
            current = temp;
        }
        current = current->next;
    }


}
void searchTask(TaskList* head, char title[100]) {
    TaskList* current = head;
    while (current !=NULL) {
        if (strcmp(current->task.title, title) == 0) {
            printf("ID: %d \n",current->task.id);
            printf("Title: %s \n",current->task.title);
            printf("Priority: %d \n",current->task.priority);
            printf("Deadline: %s \n",current->task.deadline);
            printf("\n");
            return;
        }
    }
}

int main() {
    TaskList* taskList = NULL;
    HistoryList* historyList = NULL;
    int choice;
    while (true) {
        printf("Chon chuc nang cua ban:\n");
        printf("1.Them nhiem vu\n");
        printf("2.Hien thi danh sach nhiem vu\n");
        printf("3.Xoa nhiem vu\n");
        printf("4.Cap nhat thong tin nhiem vu\n");
        printf("5.Danh dau nhiem vu hoan thanh\n");
        printf("6.Sap xep nhiem vu\n");
        printf("7.Tim kiem nhiem vu\n");
        printf("8.Thoat chuong trinh\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                Task task;
                printf("Nhap ID: ");
                scanf("%d", &task.id);
                printf("Nhap Title: ");

                scanf("%s", task.title);
                printf("Nhap Priority: ");
                scanf("%d", &task.priority);
                printf("Nhap Deadline: ");
                scanf("%s", task.deadline);
                addTask(&taskList, task);
                break;
            }case 2: {
                printTask(taskList);
                break;
            }case 3: {
                int id;
                printf("Nhap ID cua nhiem vu can xoa: ");
                scanf("%d", &id);
                deleteTask(&taskList, id);
                break;
            }case 4: {
                int id;
                printf("Nhap ID cua nhiem vu can cap nhat: ");
                scanf("%d", &id);
                char title[100];
                printf("Nhap Title cua nhiem vu: ");
                scanf("%s", title);
                int priority;
                printf("Nhap Priority cua nhiem vu: ");
                scanf("%d", &priority);
                char deadline[100];
                printf("Nhap Deadline cua nhiem vu: ");
                scanf("%s", deadline);
                updateTask(&taskList, id, title, priority, deadline);
                break;
            }case 5: {
                int id;
                printf("Nhap ID cua nhiem vu can danh dau hoan thanh: ");
                scanf("%d", &id);
                Task task;
                task.id = id;
                markTask(&historyList, task, id);

                break;
            }case 6: {
                sortTask(&taskList);
                break;
            }case 7: {
                char title[100];
                printf("Nhap Title cua nhiem vu can tim: ");
                scanf("%s", title);
                searchTask(taskList, title);
                break;
            }case 8: {
                exit(0);
                break;
            }default: {
                printf("Lua chon khong dung, vui long nhap lai\n");
                break;
            }
        }
    }
}
