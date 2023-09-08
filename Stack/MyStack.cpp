#pragma once
#include "MyStack.h"

using namespace std;

template <typename Type>
//注意要加上尖括号模板类型
MyStack<Type>::MyStack(int size)
{
	MAXN = size;
	top = -1;
	stk = new Type[MAXN];
}

template <typename Type>
MyStack<Type>::~MyStack()
{
	delete stk;
}

template <typename Type>
bool MyStack<Type>::isEmpty()
{
	return top == -1;
}

template <typename Type>
bool MyStack<Type>::isFull()
{
	return  MAXN == top - 1;
}

template <typename Type>
int MyStack<Type>::size()
{
	return top + 1;
}

template <typename Type>
int MyStack<Type>::pushStack(Type model)
{
	if (isFull())
	{
		//入栈时要判断栈已经满了，无法插入的情况，所以要带返回值
		return -1;
	}
	stk[++top] = model;
	return top;
}

template <typename Type>
Type MyStack<Type>::topStack()
{
	if (isEmpty())
	{
		return -1;
	}
	return stk[top];
}

template <typename Type>
int MyStack<Type>::popStack(Type* popResult)
{
	if (isEmpty())
	{
		return -1;
	}
	*popResult = stk[top--];
	return top;
}

template <typename Type>
void MyStack<Type>::clear()
{
	Type* popResult;
	while (!isEmpty())
	{
		popStack(Type* popResult);
	}
}

//int main()
//{
//	MyStack<int>testStack(20);
//	std::cout << "是否是空栈:" << testStack.isEmpty() << std::endl;
//	testStack.pushStack(1);
//	testStack.pushStack(2);
//	testStack.pushStack(3);
//	testStack.pushStack(4);
//	testStack.pushStack(5);
//	testStack.pushStack(6);
//
//	std::cout << "栈内有几个元素:" << testStack.size() << std::endl;
//	std::cout << "栈顶元素是:" << testStack.topStack() << std::endl;
//	int temp = 0;
//	testStack.popStack(&temp);
//	std::cout << "弹出元素是:" << temp << std::endl;
//	std::cout << "栈内有几个元素:" << testStack.size() << std::endl;
//
//}









