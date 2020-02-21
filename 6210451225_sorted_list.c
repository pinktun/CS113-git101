// 6210451225 Tunwaporn Thammacharoenpong
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

int main() {
    Node *head = NULL;

    int data;
    while (scanf("%d", &data) == 1) {
        if (data <= -1)
            break;

        Node *current_node = (Node *)malloc(sizeof(Node));
        current_node->data = data;
        current_node->next = NULL;

        if (head) {
            Node *ptr = head;
            if (ptr->data > data) {
                current_node->next = ptr;
                head = current_node;
            } else {
                while (ptr->next) {
                    if (ptr->next->data > data) {
                        current_node->next = ptr->next;
                        break;
                    }
                    ptr = ptr->next;
                }
                ptr->next = current_node;
            }
        } else {
            head = current_node;
        }
    }

    for (Node *ptr = head; ptr; ptr = ptr->next)
        printf("%d\n", ptr->data);

    return 0;
}