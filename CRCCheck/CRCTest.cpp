#include "CRCCheck.h"
#include "conio.h"
#include <bitset>
using namespace std;
int main()
{
	CRCCheck crc;
	crc.setDivisor(CRC4);
	char buf[2];
	buf[0] = 'j';
	buf[1] = 'k';
	char checkbuf[2];
	int sum = crc.crc(buf,2);
	int checksum;
	cout << "The true info is :" << buf[0] << "\t" << buf[1] << endl; 
	cout << "The CRC4 check sum is: " << sum << endl;
	cout << "Please input the info :";
	cin >> checkbuf[0];
	cin >> checkbuf[1];
	if(crc.check(checkbuf,2,sum))
		cout << "The info is true!" << endl;
	else
		cout << "The info is error!" << endl;

	crc.setDivisor(CRC1);
	sum = crc.crc(buf,2);
	cout << "The CRC1 check sum is: " << sum << endl;
	cout << "Please input the info :";
	cin >> checkbuf[0];
	cin >> checkbuf[1];
	if(crc.check(checkbuf,2,sum))
		cout << "The info is true!" << endl;
	else
		cout << "The info is error!" << endl;

	crc.setDivisor(CRC5_EPC);
	sum = crc.crc(buf,2);
	cout << "The CRC5_EPC check sum is: " << sum << endl;
	cout << "Please input the info :";
	cin >> checkbuf[0];
	cin >> checkbuf[1];
	if(crc.check(checkbuf,2,sum))
		cout << "The info is true!" << endl;
	else
		cout << "The info is error!" << endl;

	crc.setDivisor(CRC5_ITU);
	sum = crc.crc(buf,2);
	cout << "The CRC5_ITU check sum is: " << sum << endl;
	cout << "Please input the info :";
	cin >> checkbuf[0];
	cin >> checkbuf[1];
	if(crc.check(checkbuf,2,sum))
		cout << "The info is true!" << endl;
	else
		cout << "The info is error!" << endl;

	crc.setDivisor(CRC5_USB);
	sum = crc.crc(buf,2);
	cout << "The CRC5_USB check sum is: " << sum << endl;
	cout << "Please input the info :";
	cin >> checkbuf[0];
	cin >> checkbuf[1];
	if(crc.check(checkbuf,2,sum))
		cout << "The info is true!" << endl;
	else
		cout << "The info is error!" << endl;

	crc.setDivisor(CRC6_ITU);
	sum = crc.crc(buf,2);
	cout << "The CRC6_ITU check sum is: " << sum << endl;
	cout << "Please input the info :";
	cin >> checkbuf[0];
	cin >> checkbuf[1];
	if(crc.check(checkbuf,2,sum))
		cout << "The info is true!" << endl;
	else
		cout << "The info is error!" << endl;

	crc.setDivisor(CRC7);
	sum = crc.crc(buf,2);
	cout << "The CRC7 check sum is: " << sum << endl;
	cout << "Please input the info :";
	cin >> checkbuf[0];
	cin >> checkbuf[1];
	if(crc.check(checkbuf,2,sum))
		cout << "The info is true!" << endl;
	else
		cout << "The info is error!" << endl;

	getch();
	return 0;
}