#include<iostream>
#include<vector>
#include <cstdlib>

using namespace std;

struct node {
	
	int data;
	struct node* left;
	struct node* right;
	
	node(int val){
		
		data = val;
		left = NULL;
		right = NULL;
	} 
};

void insert_binarySearch_tree(struct node* root, int val){
	
	if(root->data==NULL){
		cout<<"Empty tree";
		root->data = val;
	}
	
	if(val > root->data){
		while(root->data != NULL){
			
		}
	}
}

void preorder(struct node* root){
	
	if(root==NULL){
		return;
	}
	cout<<root->data;
	preorder(root->left);
	preorder(root->right);
	
}

void inorder(struct node* root){
	
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
	
}

void postorder(struct node* root){
	
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data;
}

node* BST_Search(struct node* root, int val){
	
	if(root->data==NULL){
		return NULL;
	}
	if(root->data==val){
		return root;
	}
	
	if(root->data>val){
		return BST_Search(root->left,val);
	}
	return BST_Search(root->left,val);
	
}

node* inorderSucc(node* root){
	node* curr = root;
	while(curr && curr->left != NULL){
		curr = curr->left;		
	}
	return curr;
}

node* BST_delete(struct node* root, int val){
	
	if(val<root->data){
		root->left = BST_delete(root->left,val);
		
	}
	else if(val>root->data){
		root->right = BST_delete(root->right,val);
	}
	else{
		if(root->left==NULL){
			node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			node* temp = root->left;
			free(root);
			return temp;
		}
		
		node* temp = inorderSucc(root->right);
		root->data = temp->data;
		root->right	=BST_delete(root->right,temp->data);		
	}
	return root;	
}

int main(){
	
	struct node* root = new node(4);
	root->left = new node(2);
	root->right = new node(5);
	root->left->left = new node(1);
	root->left->right = new node(3);	 
	//root->right->left = new node(6);
	root->right->right = new node(6);
	
	inorder(root);
	cout<<endl;
	root = BST_delete(root, 2);
	inorder(root);
	return 0;
	
}
