#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void pre_order(struct node* node){
    if(node == NULL){
        return;
    }
    pre_order(node->left);
    pre_order(node->right);
    printf("%d ->", node->data);
}


int main() {
     struct node *s1, *s2, *s3 , *s4, *s5, *s6;
     s1 = malloc(sizeof(struct node));
     s2 = malloc(sizeof(struct node));
     s3 = malloc(sizeof(struct node));
     s4 = malloc(sizeof(struct node));
     s5 = malloc(sizeof(struct node));
     s6 = malloc(sizeof(struct node));
     
     s1->data = 10;
     s1->left = s2;
     s1->right = s5;

     s2->data = 20;
     s2->left = s3;
     s2->right = s4;

     s3->data = 30;
     s3->left = NULL;
     s3->right = NULL;

     s4->data = 40;
     s4->left = NULL;
     s4->right = NULL;

     s5->data = 50;
     s5->left = NULL;
     s5->right = s6;

     s6->data = 60;
     s6->left = NULL;
     s6->right = NULL;

     pre_order(s1);

     return 0;
}