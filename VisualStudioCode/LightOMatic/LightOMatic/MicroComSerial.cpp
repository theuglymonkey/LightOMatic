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


void MicroComSerial::OpenCom(const std::string& devname, unsigned int baud_rate,
	boost::asio::serial_port_base::parity opt_parity=boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none),
    boost::asio::serial_port_base::character_size opt_csize=boost::asio::serial_port_base::character_size(8),
    boost::asio::serial_port_base::flow_control opt_flow=boost::asio::serial_port_base::flow_control( boost::asio::serial_port_base::flow_control::none),
    boost::asio::serial_port_base::stop_bits opt_stop= boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one))
{



}

void MicroComSerial::CloseCom()
{
	serialPort->close();
}

size_t MicroComSerial::Send(void* data, size_t length)
{
	return serialPort->write_some(boost::asio::buffer(data, length));
}