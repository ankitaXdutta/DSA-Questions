#include<stdio.h> 
#include<stdlib.h> 
struct Node{
    int data;
    struct Node *next;
};
struct Node *newNode(int data){
    struct Node *node= (struct Node*)malloc(sizeof(struct Node)); 
    node -> data=data;
    node -> next=NULL;
    return node;
}

struct Node*Enqueue(struct Node *head,int data){
    struct Node*currNode=newNode(data); 
    if(head==NULL){
        return currNode;
    }
    struct Node*temp=head; 
    while(temp -> next!=NULL){
         temp=temp -> next;
    }
    temp -> next=currNode;
    return head;
}

struct Node*Dequeue(struct Node *head){
    if(head==NULL){
        printf("Underflow \n");
        return head;
    }
    struct Node*temp=head; 
    head=head-> next; 
    free(temp);
    return head;
}

void print(struct Node *head){
    printf("The queue is: "); 
    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d ",temp -> data);
        temp=temp -> next;
    }
    printf("\n");
}
int main(){
    struct Node *head=NULL;
    printf("**** Queue Using Linked List ****\n");
    printf("Enter 1 to enter data into the queue\n"); 
    printf("Enter 2 to delete data from the queue\n");
    printf("Enter 3 to print the entire queue\n"); 
    printf("Enter your choice: "); 
    int choice;
    scanf("%d",&choice);
    while (choice!=0){
        if(choice==1){
            int data;
            printf("Enter data , if you want stop; enter -1 \n"); 
            scanf("%d",&data);
            while(data!=-1){
                head=Enqueue(head,data);
                scanf("%d",&data);
            } 
        }
        else if(choice==2){
            head=Dequeue(head);
        }
        else if(choice==3){
            print(head);
        }
        else{ 
            break;
        }
        printf("Enter 1 to enter data into the queue\n"); 
        printf("Enter 2 to delete data from the queue\n"); 
        printf("Enter 3 to print the entire queue\n"); 
        printf("Enter your choice: "); 
        scanf("%d",&choice);
    }   
    return 0;
}