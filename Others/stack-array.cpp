#include<bits/stdc++.h>
using namespace std;
#define max 100

class Stack{
private:
	int top;
	int arr[max];
public:
	Stack(){
		top = -1;
	}

	bool isFull(){
		if(top==max-1)
			return true;
		else
			return false;
	}

	bool isEmpty(){
		if(top==-1)
			return true;
		else
			return false;
	}

	void push(int val){
		if(isFull()){
			cout<<"stack overflow"<<"\n";
			return;
		}
		arr[++top] = val;
		cout<<val<<" inserted into stack"<<"\n";
	}

	void pop(){
		if(isEmpty()){
			cout<<"stack underflow"<<"\n";
			return;
		}
		int delval = arr[top--];
		cout<<delval<<" deleted from stack"<<"\n";
	}

	void peek(){
		if(isEmpty()){
			cout<<"stack is empty"<<"\n";
			return;
		}
		int topval = arr[top];
		cout<<topval<<" is at the top"<<"\n";
	}

	void display(){
		for(int i=top;i>=0;i--){
			cout<<arr[i]<<"\n";
		}
	}
};

int main(){
	Stack st;
	st.push(15);
	st.push(30);
	st.push(45);
	st.push(60);
	st.peek();
	st.pop();
	st.pop();
	st.peek();
	// st.display();

	return 0;
}