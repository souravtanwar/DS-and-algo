#include<iostream>
#include <bits/stdc++.h> 

using namespace std;

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node node;


void insert_node_SLL(node **Head, node* newnode, int pos)
{
    int k=1;
    node *p,*q;
    p =*Head;
    if(pos ==1){
        newnode->next =p;
        *Head = newnode;
    }
    else{
        while(p !=NULL && k<pos)
        {
            k++;
            q=p;
            p =p->next; 
        }
        if(p==NULL)
        {
            q ->next =newnode;
            newnode -> next =NULL;
        }
        else
        {
            q->next =newnode;
            newnode ->next =p;
        }
    }
}

void delete_node_SLL(node **Head, int pos)
{
    node *p,*q;
    int k=1;
    if(!Head)
    {
        cout<<"List is empty";
    }
    p = *Head;
    if(pos==1)
    {
        *Head = p->next;
        free(p);
        p =NULL;
    }
    else
    {
        while(p && k<pos)
        {
            k++;
            q=p;
            p = p->next;
        }
        if(p==NULL)
        {
            cout<<"Position does not exist";
        }
        else
        {
            q ->next = p ->next;
            free(p);
            p = NULL;
        }
    }

}

void display(node **Head){ 
   node* ptr;  
   int count =0; 
   ptr = *Head;
   while (ptr) { 
       count++;
       cout<< ptr->data <<" ";
       ptr = ptr->next; 
       
   } 
   
} 
int main() { 
    int position, data ,i;

    cout<<"\n\t LINKED LIST OPERATIONS";
    cout<<"\n\t--------------------------------";
    cout<<"\n\t 1.INSERTION\n\t 2.DELETITION\n\t 3.DISPLAY\n\t 4.EXIT"<<endl;

    node* Head,*newnode;
    do
    {
        cout<<"Enter the operation : ";
        cin>>i;
        switch(i){
            case 1:
                cout<<"Enter the position in which you want to insert a node : ";
                cin>>position;
                newnode = (node*)malloc(sizeof(node));
                cout<<"Enter the data : ";
                cin>>data; 
                newnode->data = data; 
                newnode ->next = NULL; 
                insert_node_SLL(&Head, newnode,position);
                break;
                
            case 2:
                cout<<"Enter the position in which you want to delete a node : ";
                cin>>position;
                delete_node_SLL(&Head,position);
                break;

            case 3:display(&Head);
                    break;
            case 4:
                    cout<<"EXIT POINT";
                    break;
            default:
                   cout<<"\n\t Please Enter a Valid Choice(1/2/3/4)"<<endl;
                    break;

        }
    } while (i!=4);
   return 0; 
} 