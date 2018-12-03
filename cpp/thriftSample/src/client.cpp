#include "sample.h"
#include <thrift/transport/TSocket.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>

#include <iostream>

#include <boost/lexical_cast.hpp>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

int main(int argc, char **argv) {
	stdcxx::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
	stdcxx::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	stdcxx::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
	stdcxx::shared_ptr<sampleClient> client(new sampleClient(protocol));

	transport->open();
	
	try {
		std::string hello;
		client->hello(hello, "World");
		std::cout << hello << std::endl;

		std::string ipaddr;
		client->ipaddr(ipaddr);
		std::cout << ipaddr << std::endl;

		int random = client->random(5);
		std::cout << boost::lexical_cast<std::string>(random) << std::endl;

		std::string uuid;
		client->uuid(uuid);
		std::cout << uuid << std::endl;

		Calc calc;
		client->calculator(calc, 7, 13);
		std::cout << calc << std::endl;
	}
	catch (sampleException &e) {
		std::cerr << e << std::endl;
	}

	transport->close();

	getchar();
	return 0;
}