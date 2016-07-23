#include "SerialPort.h"



SerialPort::SerialPort(char *filename)
{
	this->filename = filename;
}

void SerialPort::initialize()
{
	fd  = open(filename,O_RDWR | O_NOCTTY | O_SYNC);
	struct termios port_settings;
	tcgetattr(fd,&port_settings);
	cfsetispeed(&port_settings, B9600);
	cfsetospeed(&port_settings, B9600);
	port_settings.c_cflag |= ( CLOCAL | CREAD );

	port_settings.c_cflag &= ~PARENB;
	port_settings.c_cflag &= ~CSTOPB;
	port_settings.c_cflag &= ~CSIZE;
	port_settings.c_cflag |= CS8;
	tcflush( fd, TCIOFLUSH );
	tcsetattr(fd, TCSANOW, &port_settings);



}

bool SerialPort::sendInt(int num)
{
	char command[4];
	sprintf(command,"%d",num);
	if(write(fd,command,sizeof(int)) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

