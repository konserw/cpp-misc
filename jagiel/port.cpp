// adrport.c - Serial Port Handler
// Copyright MMI, MMII by Sisusypro Incorporated

// Permission is hereby granted to freely copy,
// modify, utilize and distribute this example in
// whatever manner you desire without restriction.
#include "head.h"

/*

int open_port()
{
	int fd; // file description for the serial port

	fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);

	if(fd == -1) // if open is unsucessful
	{
		//perror("open_port: Unable to open /dev/ttyS0 - ");
		printf("open_port: Unable to open /dev/ttyUSB0. \n");
	}
	else
	{
		fcntl(fd, F_SETFL, 0);
		printf("port is open.\n");
	}

	return(fd);
} //open_port

int configure_port(int fd)      // configure the port
{
	struct termios port_settings;      // structure to store the port settings in

	cfsetispeed(&port_settings, B115200);    // set baud rates
	cfsetospeed(&port_settings, B115200);

	port_settings.c_cflag &= ~PARENB;    // set no parity, stop bits, data bits
	port_settings.c_cflag &= ~CSTOPB;
	port_settings.c_cflag &= ~CSIZE;
	port_settings.c_cflag |= CS8;

	tcsetattr(fd, TCSANOW, &port_settings);    // apply the settings to the port
	return(fd);

} //configure_port

*/



static int fd = 0;

// opens the serial port
// return code:
//   > 0 = fd for the port
//   -1 = open failed
int OpenAdrPort()
{
    // make sure port is closed
    CloseAdrPort();

    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd < 0)
    {
        printf("open error %d %s\n", errno, strerror(errno));
    }
    else
    {
        struct termios my_termios;
        printf("fd is %d\n", fd);
        tcgetattr(fd, &my_termios);
        // NOTE: you may want to save the port attributes
        //       here so that you can restore them later
        printf("old cflag=%08x\n", my_termios.c_cflag);
        printf("old oflag=%08x\n", my_termios.c_oflag);
        printf("old iflag=%08x\n", my_termios.c_iflag);
        printf("old lflag=%08x\n", my_termios.c_lflag);
        printf("old line=%02x\n", my_termios.c_line);

        tcflush(fd, TCIFLUSH);

        my_termios.c_cflag = B9600 | CS8 |CREAD | CLOCAL | HUPCL;

        cfsetospeed(&my_termios, B9600);
        tcsetattr(fd, TCSANOW, &my_termios);

        printf("new cflag=%08x\n", my_termios.c_cflag);
        printf("new oflag=%08x\n", my_termios.c_oflag);
        printf("new iflag=%08x\n", my_termios.c_iflag);
        printf("new lflag=%08x\n", my_termios.c_lflag);
        printf("new line=%02x\n", my_termios.c_line);

int serial;
        ioctl(fd, TIOCMGET, &serial);
        if (serial & TIOCM_DTR)
            puts("TIOCM_DTR is not set\n");
        else
            puts("TIOCM_DTR is set\n");
        } // end if

    return fd;
} // end OpenAdrPort

// writes zero terminated string to the serial port
// return code:
//   >= 0 = number of characters written
//   -1 = write failed
int WriteAdrPort(__int8_t* psOutput, int n)
{
    int iOut;
    if (fd < 1)
    {
        printf(" port is not open\n");
        return -1;
    }

    printf("%d\twrote: ", psOutput[0]);

    for(int i=0; i<n; ++i)
    {
        iOut = write(fd, &psOutput[i], 1);
        if (iOut < 0)
        {
            printf("write error %d %s\n", errno, strerror(errno));
        }
        else
        {
            printf("%d ", i);

        }
    }
    printf("\n");

    return iOut;
} // end WriteAdrPort
/*
// read string from the serial port
// return code:
//   >= 0 = number of characters read
//   -1 = read failed
int ReadAdrPort(char* psResponse, int iMax)
{
    int iIn;
    printf("in ReadAdrPort iMax=%d\n", iMax);
    if (fd < 1)
    {
        printf(" port is not open\n");
        return -1;
    } // end if
    strncpy (psResponse, "N/A", iMax<4?iMax:4);
    iIn = read(fd, psResponse, iMax-1);
    if (iIn < 0)
    {
    	if (errno == EAGAIN)
    	{
		return 0; // assume that command generated no response
	}
	else
	{
		printf("read error %d %s\n", errno, strerror(errno));
	} // end if
    }
    else
    {
    	psResponse[iIn<iMax?iIn:iMax] = '\0';
	    printf("read %d chars: %s\n", iIn, psResponse);
    } // end if

    return iIn;
} // end ReadAdrPort
*/
// closes the serial port
void CloseAdrPort()
{
	// you may want to restore the saved port attributes
    if (fd > 0)
    {
        close(fd);
    } // end if
} // end CloseAdrPort

