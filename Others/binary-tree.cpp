#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
	node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

node *build(){
	// return the head of the tree
	int data;
	cin>>data;
	if(data==-1) return NULL;
	node *root = new node(data);
	root->left = build();
	root->right = build();
	return root;
}

void inorder(node *root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(node *root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(node *root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

void preorder_iterative(node *root){
	if(root==NULL) return;
	stack<node*> st;
	st.push(root); // this is the first node to be processed

	while(not st.empty()){ // st.size()>0
		cout<<st.top()->data<<" ";
		node *curr = st.top();
		st.pop();

		if(curr->right)
			st.push(curr->right);
		if(curr->left)
			st.push(curr->left);
	}
	return;
}

// level order : if we get node first we process it first (FCFS : FIFO)
void level_order(node *root){
	if(root==NULL) return;
	queue<node*> q;
	q.push(root);

	while(not q.empty()){
		node *curr = q.front();
		q.pop();
		cout<<curr->data<<" ";
		if(curr->left)
			q.push(curr->left);
		if(curr->right)
			q.push(curr->right);
	}
}

void level_order_levelwise(node *root){
	if(root==NULL) return;
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(not q.empty()){
		if(q.front()==NULL){
			cout<<"\n";
			q.pop();
			if(q.size()==0) break;
			q.push(NULL);
			continue;
		}
		node *curr = q.front();
		q.pop();
		cout<<curr->data<<" ";
		if(curr->left)
			q.push(curr->left);
		if(curr->right)
			q.push(curr->right);
	}
}

int mx_level = INT_MIN;
void right_view(node *root,int curr_level){
	if(root==NULL) return;
	if(mx_level<curr_level){
		cout<<root->data<<" ";
		mx_level = curr_level;
	}
	right_view(root->right,curr_level+1);
	right_view(root->left,curr_level+1);
}

int main(){
	node *root = build();
	// cout<<"preorder: ";
	// preorder(root);
	// cout<<"\n"<<"postorder: ";
	// postorder(root);
	// cout<<"\n"<<"inorder: ";
	// inorder(root);
	
	// cout<<"\n"<<"preorder iterative: ";
	// preorder_iterative(root);

	// level_order(root);
	// cout<<"\n";
	// level_order_levelwise(root);

	right_view(root,0);

	return 0;
}