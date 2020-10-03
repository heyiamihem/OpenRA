#include<stdio.h>
#include<stdlib.h>
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};
struct Node *create(int val)
{
    struct Node* temp=NULL;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->val=val;
    temp->left=temp->right=NULL;
    return temp;
}
struct Node* insert(int val,struct Node *root){
    if(root==NULL)
        return(create(val));
    if(val<root->val)
       root->left=insert(val,root->left);
    if(val>root->val)
       root->right=insert(val,root->right);
    return root;
}
void preorder(struct Node* root)
{
    if(root!=NULL)
    {
    printf("%d\t",root->val);
    preorder(root->left);
    preorder(root->right);
    }
    return;
}
void inorder(struct Node* root)
{

    if(root!=NULL)
    {
    inorder(root->left);
    printf("%d\t",root->val);
    inorder(root->right);
    }
    return;
}
void postorder(struct Node* root)
{

    if(root!=NULL)
    {
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->val);
    }
    return;
}
struct Node* search(int key,struct Node* root){
    if(root!=NULL){
    if(key==root->val) {
        printf("\nkey found in tree");
        return(root);
        }
    if(key<root->val) search(key,root->left);
    if(key>root->val) search(key,root->right);
    }
    
}
}
void displayall(struct Node* root)
{
    printf("\ninorder:\t");
    inorder(root);
    printf("\npreorder:\t");
    preorder(root);
     printf("\npostorder:\t");
    postorder(root);
}

int main()
{
    int val,q;
    struct Node* root=NULL;
    do{
    printf("\nEnter 0 to quit, 1 to insert, 2 to search\n :");
    scanf("%d",&q);
    if(q==1)
    {
    printf("\nEnter value to enter in BST:");
    scanf("%d",&val);
    root=insert(val,root);
    displayall(root);
    }
    else if(q==5){
        printf("\nEnter node key to delete (1child/2child/leaf automatic): ");
        scanf("%d",&val);
        Delete(val,root);
        displayall(root);
        }
    else if(q==2)
    {
    printf("\nEnter key to search:");
    scanf("%d",&val);
    if(search(val,root)==NULL){
        printf("\n No key found with value\n");
    }
    }
    else if(q==3){
        printf("\nmax value is %d",max(root)->val);
    }
    else if(q==4){
        printf("\nmin value is %d",min(root)->val);
    }
    else printf("\nInvalid input, try again\n");
    }
    while(q!=0);
    return 0;
}
