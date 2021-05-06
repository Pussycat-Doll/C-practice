/*’ª-push pop min  ±º‰∏¥‘”∂»O(1)*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<class T>
class mystack
{
public:
	void pop()
	{
		int data = _st.back();
		if (data == _min.back())
			_min.pop_back();
		_st.pop_back();
	}
	void push(const T& data)
	{
		_st.push_back(data);
		if (_min.empty())
			_min.push_back(data);
		if (data <= _min.back())
			_min.push_back(data);
	}
	int getmin()
	{
		return _min.back();
	}
	void print()
	{
		for (auto e : _st)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	bool empty()
	{
		return _st.empty();
	}
private:
	vector<T> _st;
	vector<T> _min;
};
int main()
{
	mystack<int> st;
	st.push(4);
	cout << st.getmin() << endl;
	st.push(3);
	cout << st.getmin() << endl;
	st.push(2);
	cout << st.getmin() << endl;
	st.pop();
	cout << st.getmin() << endl;
	st.push(1);
	cout << st.getmin() << endl;
	st.push(-1);
	cout << st.getmin() << endl;
	st.push(-1);
	cout << st.getmin() << endl;
	st.pop();
	cout << st.getmin() << endl;
	st.push(5);
	cout << st.getmin() << endl;
	//st.print();

	while (!st.empty())
	{
		st.print();
		st.pop();
	}
	return 0;
}