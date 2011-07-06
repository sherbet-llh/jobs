#include "Vvector.h"
#include <conio.h>

int main()
{
	int num;
	Vvector<int> test1;
	cout << "size:" << test1.size() << "		capacity:" << test1.capacity() << endl;
	test1.push_back(1);
	test1.push_back(2);
	test1.push_back(3);
	test1.push_back(4);
	test1.push_back(5);
	test1.push_back(6);
	test1.push_back(7);
	test1.push_back(8);//1	2	3	4	5	6	7	8	
	cout << "size:" << test1.size() << "		capacity:" << test1.capacity() << endl;

	test1.insert(5,9);//1	2	3	4	5	9	6	7	8
	test1.erase(4);//1	2	3	4	9	6	7	8
	test1.pop_back();//1	2	3	4	9	6	7
	for(num = 0; num < test1.size(); num++)
	{
		cout << test1[num] << "\t";
	}
	cout << endl;

	cout << "The first item is:" << test1.front() << endl;
	cout << "The last item is:" << test1.back() << endl;

	test1.resize(12);
	cout << "size:" << test1.size() << "		capacity:" << test1.capacity() << endl;
	for(num = 0; num < test1.size(); num++)
	{
		cout << test1[num] << "\t";
	}
	cout << endl;

	test1.resize(16);
	cout << "size:" << test1.size() << "		capacity:" << test1.capacity() << endl;
	for(num = 0; num < test1.size(); num++)
	{
		cout << test1[num] << "\t";
	}
	cout << endl;

	test1.reserve(50);
	cout << "size:" << test1.size() << "		capacity:" << test1.capacity() << endl;
	for(num = 0; num < test1.size(); num++)
	{
		cout << test1[num] << "\t";
	}
	cout << endl;

	test1.resize(8);
	cout << "size:" << test1.size() << "		capacity:" << test1.capacity() << endl;
	for(num = 0; num < test1.size(); num++)
	{
		cout << test1[num] << "\t";
	}
	cout << endl;

	test1.clear();
	cout << "size:" << test1.size() << "		capacity:" << test1.capacity() << endl;
	for(num = 0; num < test1.size(); num++)
	{
		cout << test1[num] << "\t";
	}
	cout << endl;
	test1.resize(-1);
	test1.pop_back();
	getch();
	return 0;
}