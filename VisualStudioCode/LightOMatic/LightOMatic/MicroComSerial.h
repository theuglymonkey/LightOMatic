#include <boost/asio.hpp>
#include <string>
#pragma once

class MicroComSerial
{
private:
	boost::asio::io_service io;
	boost::asio::serial_port* serialPort;
public:

	MicroComSerial();
	MicroComSerial(const std::string& devname, unsigned int baud_rate,
        boost::asio::serial_port_base::parity opt_parity=boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none),
        boost::asio::serial_port_base::character_size opt_csize=boost::asio::serial_port_base::character_size(8),
        boost::asio::serial_port_base::flow_control opt_flow= boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none),
        boost::asio::serial_port_base::stop_bits opt_stop=boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
	~MicroComSerial(void);
	void OpenCom(const std::string& devname, unsigned int baud_rate,
		boost::asio::serial_port_base::parity opt_parity=boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none),
        boost::asio::serial_port_base::character_size opt_csize=boost::asio::serial_port_base::character_size(8),
        boost::asio::serial_port_base::flow_control opt_flow=boost::asio::serial_port_base::flow_control( boost::asio::serial_port_base::flow_control::none),
        boost::asio::serial_port_base::stop_bits opt_stop= boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
	void CloseCom();
	size_t Send(void* data, size_t length);
	void write(const char *data, size_t size);

    void write(const std::vector<char>& data);

    void writeString(const std::string& s);
};

