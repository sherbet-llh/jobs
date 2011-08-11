#ifndef _CRCCHECK_H_
#define _CRCCHECK_H_

#include <iostream>
enum CRC_DIVISOR
{
	CRC1 = 0x3,//0000 0011
	CRC4 = 0x13,//0001 0011
	CRC5_EPC = 0x29,//0010 1001
	CRC5_ITU = 0x35,//0011 0101
	CRC5_USB = 0x25,//0010 0101
	CRC6_ITU = 0x43,//0100 0011
	CRC7 = 0x89,//1000 1001
};
class CRCCheck
{
		
	public:
		CRCCheck ();
		~CRCCheck ();
		CRCCheck& operator = ( const CRCCheck &other )
		{
			this->divisor = other.divisor;
		}
		inline void setDivisor(const CRC_DIVISOR type)
		{
			divisor = type;
		}
		int crc(void *const buf, const int size);
		bool check(void *const buf, const int size, const int checkSum);
	private:
		unsigned int divisor;
		char changeCRC(const int divisor);
		char changeResult(const char crc);
		char changeCheckSum(const int divisor);
		CRCCheck ( const CRCCheck &other );
}; /* -----  end of class CRCCheck  ----- */

void transByte(char &former, char behind, int location, char div);
#endif /* end of include guard: _CRCCHECK_H_ */
