#pragma once
template<typename F>
class Stack {
private:

	struct SqStack
	{
		F* base;
		F* top;
		string index;

	}Stack0;

public:
	Stack()
	{
		Stack0.base = new F[100000];
		Stack0.top = Stack0.base;
		index = "0";
	}
	void SqPush(F nums)
	{
		Stack0.top++;
		*Stack0.top = nums;
	}
	F SqPop()
	{
		F tem = *Stack0.top;
		Stack0.top--;
		return tem;
	}
	F SqGetPop()
	{
		return *Stack0.top;
	}

};