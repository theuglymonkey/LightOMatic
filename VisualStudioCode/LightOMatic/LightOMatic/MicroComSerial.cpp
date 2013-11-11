#include "MicroComSerial.h"


MicroComSerial::MicroComSerial(void)
{
	serialPort = new boost::asio::serial_port(io);
	io.run();
}


MicroComSerial::~MicroComSerial(void)
{
	 serialPort->close();
	 delete serialPort;
}

