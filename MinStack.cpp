#include "helper.h"

//very simple one
template<typename T>
class MinStack{
public:
	T min(){
		return m.top();
	}

	void push(const T val){
		s.push(val);
		//pay attention here
		if(!m.empty() && m.top() < val)
			m.push(m.top());
		else
			m.push(val);
	}

	void pop(){
		s.pop();
		m.pop();
	}

	T top(){
		return s.top();
	}

	bool empty(){
		return s.empty();
	}
private:
	stack<T> s;
	stack<T> m;
};


int main(){
	//test
	MinStack<int> ms; 

	ms.push(1);
	ms.push(10);
	ms.push(13);
	ms.push(0);
	ms.push(110);


	while(!ms.empty()){
		cout<<"top: "<<ms.top()<<", min: "<<ms.min()<<endl;
		ms.pop();
	}

	return 0;
}