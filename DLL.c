#include <stdio.h>
#include <stdlib.h>

int choice(void)
{
    int ch;
    printf("Enter choce of operation: ");
    scanf("%d", &ch);
    return ch;
}

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void traverse(struct Node* ptr) {
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void count(struct Node* ptr) {
    int c = 0;
    while (ptr != NULL) {
        c++;
        ptr = ptr->next;
    }
    printf("Count = %d", c);
}

struct Node* insert_first(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;
    if (head != NULL) {
        head->prev = ptr;
    }
    return ptr;
}

struct Node* insert_index(struct Node* head, int data, int index) {
    struct Node* ptr, * p;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    p = head;
    int i = 0;
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    ptr->prev = p;
    if (p->next != NULL) {
        p->next->prev = ptr;
    }
    p->next = ptr;
    return head;
}

struct Node* insert_last(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL) {
        ptr->prev = NULL;
        return ptr;
    }
    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    return head;
}

struct Node* delete_first(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, cannot delete from start\n");
        return NULL;
    }
    struct Node* ptr = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(ptr);
    return head;
}

struct Node* delete_index(struct Node* head, int index) {
    struct Node* p = head;
    int i = 0;
    while (i < index && p != NULL) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("Invalid position for deletion\n");
        return head;
    }
    if (p->prev != NULL) {
        p->prev->next = p->next;
    }
    if (p->next != NULL) {
        p->next->prev = p->prev;
    }
    free(p);
    return head;
}

struct Node* delete_last(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, cannot delete from end\n");
        return NULL;
    }
    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    if (p->prev != NULL) {
        p->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(p);
    return head;
}

void reverse(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}

void search(struct Node* head, int key) {
    struct Node* ptr = head;
    int flag = 0;
    while (ptr != NULL) {
        if (ptr->data == key) {
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (flag == 1) {
        printf("Key found :)\n");
    } else {
        printf("Key not found :(\n");
    }
}

void sort(struct Node* head) {
    struct Node* ptr1, * ptr2;
    int temp;
    for (ptr1 = head; ptr1->next != NULL; ptr1 = ptr1->next) {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
            if (ptr1->data > ptr2->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }

    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

struct Node* concat(struct Node* ptr1, struct Node* ptr2) {
    struct Node* p = ptr1;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr2;
    if (ptr2 != NULL) {
        ptr2->prev = p;
    }
    return ptr1;
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    struct Node* fifth = NULL;

    // Assigning memory
    head = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));
    fourth = malloc(sizeof(struct Node));
    fifth = malloc(sizeof(struct Node));

    // Linking nodes
    head->data = 22;
    head->next = second;
    head->prev = NULL;
    second->data = 72;
    second->next = third;
    second->prev = head;
    third->data = 12;
    third->next = fourth;
    third->prev = second;
    fourth->data = 64;
    fourth->next = fifth;
    fourth->prev = third;
    fifth->data = 17;
    fifth->next = NULL;
    fifth->prev = fourth;

    struct Node* head1 = NULL;
    struct Node* first1 = NULL;
    struct Node* second1 = NULL;
    struct Node* head2 = NULL;
    struct Node* first2 = NULL;
    struct Node* second2 = NULL;

    head1 = malloc(sizeof(struct Node));
    first1 = malloc(sizeof(struct Node));
    second1 = malloc(sizeof(struct Node));
    head2 = malloc(sizeof(struct Node));
    first2 = malloc(sizeof(struct Node));
    second2 = malloc(sizeof(struct Node));

    head1->data = 1;
    head1->next = first1;
    head1->prev = NULL;
    first1->data = 2;
    first1->next = second1;
    first1->prev = head1;
    second1->data = 3;
    second1->next = NULL;
    second1->prev = first1;

    head2->data = 4;
    head2->next = first2;
    head2->prev = NULL;
    first2->data = 5;
    first2->next = second2;
    first2->prev = head2;
    second2->data = 6;
    second2->next = NULL;
    second2->prev = first2;

    traverse(head);

    printf("\n\n");

    count(head);

    // head = insert_first(head, 77);
    // p("\n\n");
    // traverse(head);

    // head = insert_index(head, 31, 3);
    // p("\n\n");
    // traverse(head);

    // head = insert_last(head, 31);
    // p("\n\n");
    // traverse(head);

    // head = delete_first(head);
    // p("\n\n");
    // traverse(head);

    // head = delete_index(head, 1);
    // p("\n\n");
    // traverse(head);

    // head = delete_last(head);
    // p("\n\n");
    // traverse(head);

    // p("\n\n");
    // reverse(&head);
    // traverse(head);

    // ("Before:\n\n");
    // traverse(head1);
    // p("\n");
    // traverse(head2);

    // p("After:\n\n");
    // head1 = concat(head1, head2);
    // traverse(head1);

    p("\n\n");
    // search(head, 12);

    sort(head);

    return 0;
}