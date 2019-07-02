#include<iostream>
#include<stack>
using namespace std;

class Queue{
public:
	void push(int x){
		s1.push(x);
	}
	int front(){
		if (s2.empty()){
			if (s1.size() == 0) throw;
			while (!s1.empty()){
				int tmp = s1.top();
				s1.pop();
				s2.push(tmp);
			}
		}
		return s2.top();

	}
	int pop(){
		if (s2.empty()){
			while (!s1.empty()){
				int tmp = s1.top();
				s1.pop();
				s2.push(tmp);
			}
		}
		int res = s2.top();
		s2.pop();
		return res;
	}
private:
	stack<int> s1;
	stack<int> s2;
};
int main(){
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << "q.front(): " << q.front() << endl;
	q.pop();
	cout << "q.front(): " << q.front() << endl;
	q.pop();
	cout << "q.front(): " << q.front() << endl;
	system("pause");
	return 0;
}