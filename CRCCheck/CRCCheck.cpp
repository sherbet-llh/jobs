#include "CRCCheck.h"
using namespace std;

int CRCCheck::crc(void *const buf, const int size)
{
	int i,j;
	char former,behind;
	char div = changeCRC(this->divisor);
	char *p = (char*)buf;
	former = *p;
	for (i = 0; i < size - 1; i++)
	{
		behind = *(++p);
		for(j = 0; j < 8; j++)
		{
			transByte(former, behind, j, div);
		}
	}
	behind = 0x00;//���һλ��0���
	for(j = 0; j < 8; j++)
	{		
		transByte(former,behind,j,div);
	}
	return changeResult(former);
}

bool CRCCheck::check(void *const buf, const int size, const int checkSum)
{
	int i,j;
	char former,behind;//formerǰһλbehind��һλ
	char div = changeCRC(this->divisor);
	char *p = (char*)buf;
	former = *p;
	for (i = 0; i < size - 1; i++)
	{
		behind = *(++p);
		for(j = 0; j < 8; j++)
		{
			transByte(former,behind,j,div);
		}
	}
	behind = changeCheckSum(checkSum);//���һλ��֮ǰ���ɵ�У�������
	for(j = 0; j < 8; j++)
	{		
		transByte(former,behind,j,div);
	}
	if(former == 0)
		return true;
	else
		return false;
}

char CRCCheck::changeCRC(const int divisor)//��ԭʼУ���������λ
{
	char div = divisor;
	switch(this->divisor)
	{
	case CRC1:
		div <<= 6;
		break;
	case CRC4:
		div <<= 3;
		break;
	case CRC5_EPC:
		div <<= 2;
		break;
	case CRC5_ITU:
		div <<= 2;
		break;
	case CRC5_USB:
		div <<= 2;
		break;
	case CRC6_ITU:
		div <<= 1;
		break;
	default:
		break;	
	}
	return div;
}

char CRCCheck::changeResult(const char crc)//�����ɵĽ��������λ�ҽ������������
{
	char rst = crc;
	switch(this->divisor)
	{
	case CRC1:
		rst >>= 7;
		rst &= 0x01;
		break;
	case CRC4:
		rst >>= 4;
		rst &= 0x0f;
		break;
	case CRC5_EPC:
		rst >>= 3;
		rst &= 0x1f;
		break;
	case CRC5_ITU:
		rst >>= 3;
		rst &= 0x1f;
		break;
	case CRC5_USB:
		rst >>= 3;
		rst &= 0x1f;
		break;
	case CRC6_ITU:
		rst >>= 2;
		rst &= 0x3f;
	case CRC7:
		rst >>= 1;
		rst &= 0x7f;
		break;
	default:
		break;	
	}
	return rst;
}

char CRCCheck::changeCheckSum(const int divisor)//�����ɵ�У���������λ
{
	char div = divisor;
	switch(this->divisor)
	{
	case CRC1:
		div <<= 7;
		break;
	case CRC4:
		div <<= 4;
		break;
	case CRC5_EPC:
		div <<= 3;
		break;
	case CRC5_ITU:
		div <<= 3;
		break;
	case CRC5_USB:
		div <<= 3;
		break;
	case CRC6_ITU:
		div <<= 2;
	case CRC7:
		div <<= 1;
		break;
	default:
		break;	
	}
	return div;
}

CRCCheck::CRCCheck()
{
}

CRCCheck::~CRCCheck()
{
}

//����Ϣ��У������򲢺���һλ
void transByte(char &former, char behind, int location, char div)
{
	if((former & 0x80) != 0)
		former ^= div;
	if((behind & (0x01<< (7 - location))) > 0)
		former = (former << 1) + 0x01;
	else
		former = (former << 1);
}