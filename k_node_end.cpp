/*FIND THE Kth NODE FROM THE EBD OF SINGLY LINKED LIST*/

#include<iostream>
#include <bits/stdc++.h> 

using namespace std;

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node node;
/*METHOD 1*/
/*node* find_from_end(node *Head,int k)
{
    node *p,*q;
    p = Head;
    q = Head;
    while(p)
    { 
        int count = 0;
        q = p ->next;
        while(q)
            count++;
            q = q->next;
            cout<<count;
        }
        cout<<endl;
        cout<<count;
        cout<<"after while of q";
        if(count == k-1)
        {
            cout<<"in";
            return(p);        
        }
        if(count <k-1)
        {
            cout<<"Position does not exist in linked list";
        }
        p = p->next;
    }
}
*/
/*METHOD 2*/
void getkthfromend(node* Head, int k){
    node *p;
    int n=0;
    cout<<"o";
    while(p){
        p =p->next;
        n++;
    }
    cout<<"in";
    if(n>=k)
    {

        p = Head;
        for(int i;i<n-k;i++){
            p =p->next;
        }
        cout<<p->data;
    }
}


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
    cout<<"\n\t 1.INSERTION\n\t 2.FINDING FROM END\n\t 3.DISPLAY\n\t 4.EXIT"<<endl;

    node* Head,*newnode, *node1;
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

            case 3:display(&Head);
                    break;
            case 4:
                    cout<<"EXIT POINT";
                    break;

            case 2: cout<<"Enter the position from end : ";
                    cin>>position;
                    getkthfromend(Head, position);
                    break;

            default:
                   cout<<"\n\t Please Enter a Valid Choice(1/2/3/4)"<<endl;
                    break;
        }
    } while (i!=4);
   return 0; 
} 
