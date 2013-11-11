#include <boost/asio.hpp>
#include <string>
#pragma once

class MicroComSerial
{
private:
	boost::asio::io_service io;
	boost::asio::serial_port* serialPort;
	int m_buadRate;
	std::string m_comPort;
public:
	MicroComSerial(void);
	~MicroComSerial(void);
	void OpenCom(
		   const std::string& portname, 
           int baudrate, 
           int charactersize, 
           boost::asio::serial_port_base::parity::type parity, 
           boost::asio::serial_port_base::stop_bits::type stopbits,
           boost::asio::serial_port_base::flow_control::type flowcontrol);
	void CloseCom();

	size_t send(void* data, size_t length);
};

