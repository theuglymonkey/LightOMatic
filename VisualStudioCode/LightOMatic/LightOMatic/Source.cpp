#include <iostream>
#include <string>
#include "MicroComSerial.h"
#include "TimeoutSerial.h"
using namespace std;
using namespace boost;

int main()
{
	const std::string comport = "COM6";
	//MicroComSerial serial();
	//MicroComSerial.OpenCom(comport, 9600,);

	try{
		TimeoutSerial serial("COM6",115200);
		serial.setTimeout(posix_time::seconds(5));
		char test[] = {'a'};
		serial.write(test,sizeof(test));
		serial.close();

	}catch(boost::system::system_error& e)
	{
		cout << "error: " << e.what() << endl;
		return 1;
	}
	return 0;
}