#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void traverse(struct Node *ptr) {
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int count(struct Node *ptr) {
    int c = 0;
    while (ptr != NULL) {
        c++;
        ptr = ptr->next;
    }
    return c;
}

struct Node *insert_first(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node *insert_index(struct Node *head, int data, int index) {
    struct Node *ptr, *p;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }
    p = head;
    int i = 0;
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *insert_last(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL) {
        return ptr;
    }
    struct Node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    return head;
}

struct Node *delete_first(struct Node *head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete :(\n");
        return head;
    }
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *delete_index(struct Node *head, int index) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return head;
    }
    if (index < 0) {
        printf("Invalid index. Cannot delete.\n");
        return head;
    }
    if (index == 0) {
        struct Node *ptr = head;
        head = head->next;
        free(ptr);
        return head;
    }
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;
    while (q != NULL && i < index - 1) {
        p = p->next;
        q = q->next;
        i++;
    }
    if (q == NULL) {
        printf("Invalid index. Cannot delete.\n");
        return head;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *delete_last(struct Node *head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

void reverse(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *curr = *head;
    struct Node *nxt = NULL;
    while (curr != NULL) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    *head = prev;
}

void search(struct Node *head, int key) {
    struct Node *ptr = head;
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

struct Node *sort(struct Node *head) {
    struct Node *ptr1, *ptr2;
    int temp;
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next) {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {
            if (ptr1->data > ptr2->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }
    return head;
}

struct Node *concat(struct Node *ptr1, struct Node *ptr2) {
    if (ptr1 == NULL) {
        return ptr2;
    }
    struct Node *p = ptr1;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr2;
    return ptr1;
}

int main() {
    struct Node *head = NULL;

    int choice;
    int data, index, key;

    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Traverse\n");
        printf("2. Count\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at a specific index\n");
        printf("5. Insert at the end\n");
        printf("6. Delete first node\n");
        printf("7. Delete node at a specific index\n");
        printf("8. Delete last node\n");
        printf("9. Reverse the linked list\n");
        printf("10. Search for a key\n");
        printf("11. Sort the linked list\n");
        printf("12. Concatenate two linked lists\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
            {    
                traverse(head);
                break;
            }
            case 2:
            {    
                count(head);
                break;
            }
            case 3:
            {
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insert_first(head, data);
                traverse(head);
                break;
            }
            case 4:
            {
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter index to insert at: ");
                scanf("%d", &index);
                head = insert_index(head, data, index);
                traverse(head);
                break;
            }
            case 5:
            {
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insert_last(head, data);
                traverse(head);
                break;
            }
            case 6:
            {
                head = delete_first(head);
                traverse(head);
                break;
            }
            case 7:
            {
                printf("Enter index to delete: ");
                scanf("%d", &index);
                head = delete_index(head, index);
                traverse(head);
                break;
            }
            case 8:
            {
                head = delete_last(head);
                traverse(head);
                break;
            }
            case 9:
            {
                reverse(&head);
                traverse(head);
                break;
            }
            case 10:
            {
                printf("Enter key to search for: ");
                scanf("%d", &key);
                search(head, key);
                break;
            }
            case 11:
            {
                sort(head);
                traverse(head);
                break;
            }
            case 12:
            {
                struct Node *head2 = NULL;
                head = concat(head, head2);
                break;
            }
            case 0:
            {
                printf("Exiting the program.\n");
                exit(0);
            }
            default:
            {
                printf("Invalid choice. Please enter a valid option.\n");
            }
        }
    }
    return 0;
}