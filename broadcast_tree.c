#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct treenode{
	int data;
	struct treenode* left;
	struct treenode* right;
}treenode;

treenode* createnode(int data){
	treenode* newnode =(treenode*) malloc(sizeof(treenode));
	newnode->data = data;
	newnode->left = newnode->right =NULL;
	
	return newnode;
}

void broadcast(treenode* node,int parent,const char* msg){
	if(node==NULL) return;
	
	printf("Node %d message %s from %d\n",node->data,msg,parent);
	broadcast(node->left,node->data,msg);
	broadcast(node->right,node->data,msg);}
int main(){
	treenode* root= createnode(0);
	root->left = createnode(1);
	root->right = createnode(2);
	root->left->left = createnode(3);
	root->left->right = createnode(4);
	root->right->left = createnode(5);
	
	const char* msg = "i am dark";
	printf("broat casting msg from root 0\n");
	broadcast(root,-1,msg);
	
	return 0;
}