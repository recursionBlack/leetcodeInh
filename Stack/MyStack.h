#pragma once
#include<iostream>

using namespace std;

template <typename Type>
class MyStack
{
public:
	MyStack(int size);//初始化是要指定stack的大小
	~MyStack();

	bool isEmpty();
	bool isFull();
	int size();											//获取栈的尺寸

	int pushStack(Type model);			// 往栈种压入元素
	Type topStack();								// 取出栈顶元素,但不删除他
	int popStack(Type* popResult);		//	删除栈顶元素。
	void clear();										// 清空栈

private:
	Type *stk;//栈是由动态数组实现的，stk表示数组的首地址
	int top;//始终指向栈顶元素，是栈顶元素在动态数组中的下标值
	int MAXN;//栈的最大容量
};
