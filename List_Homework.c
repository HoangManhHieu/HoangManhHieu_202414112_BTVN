#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct Sinhvien{
    char Hoten[1001];
    char mssv[1001];
    int year;
    float gpa;
}Sinhvien;
typedef struct Node{
    Sinhvien SV;
    struct Node* next;
}Node;
typedef struct List{
    Node* firstNode;
}List;
//
void listnull(List* list){
    list->firstNode = NULL;
}
Sinhvien DSSV( char* name, char* masosv, int yearr, float GPA){
    Sinhvien sv;
    strcpy(sv.Hoten, name);
    strcpy(sv.mssv, masosv);
    sv.year = yearr;
    sv.gpa = GPA;
    return sv;
}
Node* newnode(Sinhvien sv){
    Node* p = (Node*)malloc(sizeof(Node));
    if( p == NULL){
        return NULL;
    }
    p->SV = sv;
    p->next = NULL;
    return p;
}
void addlist( List* list, Sinhvien sv){
    Node* p = newnode(sv);
    p->next = list->firstNode;
    list->firstNode = p;
}
void exportDS(List* list){
    Node* node = list->firstNode;
    if( node == NULL){
        return;
    }
    int i = 1;
    while( node != NULL){
        printf("%d. %-20s | MSSV: %-10s | Nam: %d | GPA: %.2f\n", i, node->SV.Hoten, node->SV.mssv, node->SV.year, node->SV.gpa);
        node = node->next;
        i++;
    }
    printf("\n");
}
int lengthList( List* list){
    int length = 0;
    Node* node = list->firstNode;
    while( node != NULL){
        length++;
        node = node->next;
    }
    return length;
}
int searchGpa( List* list){
    int count = 0;
    Node* node = list->firstNode;
    while( node != NULL){
        if( node->SV.gpa > 3.2){
            count++;
        }
        node = node->next;
    }
    return count;
}
void swap(Sinhvien* a, Sinhvien* b){
    Sinhvien tmp = *a;
    *a = *b;
    *b = tmp;
}
void Sortgpa( List* list){
    if (list->firstNode == NULL) return;
    for (Node* p = list->firstNode; p != NULL; p = p->next) {
        for (Node* q = p->next; q != NULL; q = q->next) {
            if (p->SV.gpa > q->SV.gpa) {
                swap(&(p->SV), &(q->SV));
            }
        }
    }
}
void addSv( List* list, Sinhvien sv){
    Node* newNode = newnode(sv);
    if( list->firstNode == NULL || sv.gpa < list->firstNode->SV.gpa){
        newNode->next = list->firstNode;
        list->firstNode = newNode;
        return;
    }
    Node* tmp = list->firstNode;
    while( tmp->next != NULL && tmp->next->SV.gpa < sv.gpa){
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
}
int main() {
    List myList;
    listnull(&myList);
    addlist(&myList, DSSV("Hoang Manh Hieu", "202414112", 2006, 3.9));
    addlist(&myList, DSSV("Hoang Minh Hieu", "202414113", 2006, 2.1));
    addlist(&myList, DSSV("Hoang van Hieu", "202414114", 2006, 3.4));
    printf("1. Danh sach ban dau:\n");
    exportDS(&myList);
    printf("Chieu dai danh sach: %d\n", lengthList(&myList));
    printf("So luong GPA > 3.2: %d\n", searchGpa(&myList));
    Sortgpa(&myList);
    exportDS(&myList);
    Sinhvien svMoi = DSSV("Hoang Van Hieu", "202414115", 2004, 2.4);
    addSv(&myList, svMoi);
    
    exportDS(&myList);

    return 0;
}