#include<bit/stdc++.h>
using namespace std;

struct Node{
	Node* arr[26];
	bool flag = false;

	bool contains(char c){
		return (node.arr[c-'a']!=NULL);
	}

	void put(char c, Node* newNode){
		arr[c-'a'] = newNode;
	}

	Node* getNext(char c){
		return arr[c-'a'];
	}

	void setFlag(){
		flag = true;
	}

	bool isFlagSet(){
		return flag;
	}
};

Node* root = new Node();

void insert(string word){
	Node* temp = root;
	for(int i=0;i<word.size();i++){
		if(not temp->contains(temp, word[i])){
			Node* newNode = new Node();
			temp->put(word[i], newNode);
		}
		// move temp to next
		temp = temp->getNext(word[i]);
	}
	temp->setFlag();
}

bool search(string word){
	Node* temp = root;
	for(int i=0;i<word.size();i++){
		if(temp->contains(word[i])){
			temp = temp->getNext(word[i]);
		}
		else{
			return false;
		}
	}
	return temp->isFlagSet();
}

bool startsWith(string word){
	Node* temp = root;
	for(int i=0;i<word.size();i++){
		if(temp->contains(word[i])){
			temp = temp->getNext(word[i]);
		}
		else{
			return false;
		}
	}
	return true;
}

int main(){


	return 0;
}