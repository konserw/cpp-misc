#include "head.h"

typedef enum
 {
 b0000 = 0x00,
 b0001 = 0x01,
 b0010 = 0x02,
 b0011 = 0x03,
 b0100 = 0x04,
 b0101 = 0x05,
 b0110 = 0x06,
 b0111 = 0x07,
 b1000 = 0x08,
 b1001 = 0x09,
 b1010 = 0x0A,
 b1011 = 0x0B,
 b1100 = 0x0C,
 b1101 = 0x0D,
 b1110 = 0x0E,
 b1111 = 0x0F
 } T_BIN_NIBBLE;

 /* 2 nibbles to 8 bit */
 #define B8(msn,lsn) ( ( b##msn<<4 ) \
 |( b##lsn ) )

 /* 4 nibbles to 16 bit */

 #define B16(msn,n2, n1,lsn) ( (unsigned short)( b##msn<<12 ) \
 |(unsigned short)( b##n2 <<8 ) \
 |(unsigned short)( b##n1 <<4 ) \
 |(unsigned short)( b##lsn ) )

 /* Sample usage:
 B8(0101,0101) = 85
 B16(1010,1010 , 0101,0101) = 43605
 */

 #define CRC bytes[8] = bytes[0] ^ bytes[1] ^ bytes[2] ^ bytes[3] ^ bytes[4] ^ bytes[5] ^ bytes[6] ^ bytes[7]; \
    bytes[8] = bytes[8] | B8(1000, 0000);

using namespace std;

int main(int argc, char *argv[])
{
    const int n=9;
	int fd = OpenAdrPort();
	if (fd< 0)
	    return 1;

	__int8_t bytes[n];
	for(int i=1; i<n-1; i++)
	    bytes[i] = B8(1000, 0000);



    while(1)
    {
        for(int i=0; i<14; ++i)
        {

            switch(i)
            {
                case 0:
                case 13:
                    bytes[0] = B8(0100, 0000);
                    CRC
                    break;
                case 1:
                case 12:
                    bytes[0] = B8(0100, 0001);
                    CRC
                    break;
                case 2:
                case 11:
                    bytes[0] = B8(0100, 0010);
                    CRC
                    break;
                case 3:
                case 10:
                    bytes[0] = B8(0100, 0011);
                    CRC
                    break;
                case 4:
                case 9:
                    bytes[0] = B8(0100, 0100);
                    CRC
                    break;
                case 5:
                case 8:
                    bytes[0] = B8(0100, 0101);
                    CRC
                    break;
                case 6:
                case 7:
                    bytes[0] = B8(0100, 0111);
                    break;
            }

            sleep(1);
            WriteAdrPort(bytes, n);

        }

    }

    CloseAdrPort();
    return 0;
}
