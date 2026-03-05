#include <iostream>
#include <asio.hpp>

#include "messages.pb.h"
#include "CoreStateEngine.h"



int main() {

	asio::io_context io;

	asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), 8080);

	asio::ip::tcp::socket socket(io);

	asio::ip::tcp::acceptor acceptor(io, endpoint);

	acceptor.accept(socket);

	std::cout << "Client connected" << std::endl;

	io.run();

	return 0;

}