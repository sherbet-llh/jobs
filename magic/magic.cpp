/*
ħ��ʦ���ƣ���һ��ȡ��һ��Ϊ1���ڶ��������ţ���һ�ŷ��������棬�ڶ���Ϊ2�����Σ��������ư�˳�����
��ԭʼ�Ƶ�����
*/

#include <iostream>
#include <conio.h>
using namespace std;

//��������Ľڵ�
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
	//���û������˿��Ƶ�����
	int totalNum;
	cout << "Please input the total number: ";
	cin >>totalNum;
	if(totalNum <= 0)
	{
		cout << "The input total number is error." << endl;
		return;
	}

	//�����һ���ڵ�Ŀռ䲢��ʼ����num�ڳ�ʼ����ʱ��ʼ��Ϊ0�������������ʱ���ٸ��丳ֵ
	List first = (List)malloc(sizeof(Node));
	if(!first)
	{
		cout << "Failed to ask the space." << endl;
		return;
	}
	first->num = 0;
	first->listNo = 1;
	first->next = first;
	
	//��ʼ�����нڵ㣬listNo����
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
	
	//�Ѵӳ�ʼ��������ɾ���Ľڵ����β��뵽head�ڵ��ĩβ�������ʼ��head�����׽ڵ�
	List head = (List)malloc(sizeof(Node));
	if(!head)
	{
		cout << "Failed to ask the space." << endl;
		return;
	}
	head->num = 0;
	head->listNo = 0;
	head->next = NULL;

	int deleteNum = 0;//�Ѿ�ɾ���Ľڵ���
	int increaseNum = 1;//Ҫɾ���Ľڵ������������Ϊ����Ľڵ��num
	int count = 1;//�����С�����

	List last = prev;//Ҫɾ���ڵ��ǰһ���ڵ�
	List finallyList = head;//Ҫ����ڵ��ǰһ���ڵ�
	while(deleteNum < totalNum)
	{
		if(count == increaseNum)
		{
			List s = last->next;
			last->next = s->next;
			s->num = increaseNum;//��num��ֵ
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
		search(head, i);//������в�����ɾ��
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