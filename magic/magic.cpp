/*
魔术师数牌，第一次取第一张为1，第二次数两张，第一张放在最下面，第二张为2，依次，数到的牌按顺序输出
求：原始牌的序列
*/

#include <iostream>
#include <conio.h>
using namespace std;

//定义链表的节点
typedef struct Node
{
	int num;
	int listNo;
	struct Node *next;
}Node,*List;

void magicNum();
void search(List l,int listNo);

int main()
{
	magicNum();
	getch();
	return 0;
}

void magicNum()
{
	//由用户输入扑克牌的总数
	int totalNum;
	cout << "Please input the total number: ";
	cin >>totalNum;
	if(totalNum <= 0)
	{
		cout << "The input total number is error." << endl;
		return;
	}

	//申请第一个节点的空间并初始化，num在初始化的时候始终为0，在数数排序的时候再给其赋值
	List first = (List)malloc(sizeof(Node));
	if(!first)
	{
		cout << "Failed to ask the space." << endl;
		return;
	}
	first->num = 0;
	first->listNo = 1;
	first->next = first;
	
	//初始化所有节点，listNo递增
	List prev = first;
	for(int i = 2; i <= totalNum; i++)
	{
		List next = (List)malloc(sizeof(Node));
		if(!next)
		{
			cout << "Error." << endl;
			return;
		}
		next->num = 0;
		next->listNo = i;
		next->next = first;
		prev->next = next;
		prev = next;
	}
	
	//把从初始化链表中删除的节点依次插入到head节点的末尾，这里初始化head链表首节点
	List head = (List)malloc(sizeof(Node));
	if(!head)
	{
		cout << "Failed to ask the space." << endl;
		return;
	}
	head->num = 0;
	head->listNo = 0;
	head->next = NULL;

	int deleteNum = 0;//已经删除的节点数
	int increaseNum = 1;//要删除的节点的数数数，即为输出的节点的num
	int count = 1;//数数中。。。

	List last = prev;//要删除节点的前一个节点
	List finallyList = head;//要插入节点的前一个节点
	while(deleteNum < totalNum)
	{
		if(count == increaseNum)
		{
			List s = last->next;
			last->next = s->next;
			s->num = increaseNum;//给num赋值
			s->next = NULL;
			finallyList->next = s;
			finallyList = s;

			count = 1;
			increaseNum++;
			deleteNum++;
		}
		else
		{
			last = last->next;
			count ++;
		}
	}
	for(int i = 1; i < increaseNum; i++)
		search(head, i);//输出序列并依次删除
}

void search(List l,int listNo)
{
	List p = l;
	l = l->next;
	while(1)
	{
		if(l->listNo == listNo)
		{
			cout << l->num << "\t";
			p->next = l->next;
			free(l);
			return;
		}
		else
		{
			p = l;
			l = l->next;
		}
	}
}