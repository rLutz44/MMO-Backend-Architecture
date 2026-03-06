#include <iostream>
#include <asio.hpp>
#include <array>

#include "messages.pb.h"
#include "CoreStateEngine.h"



int main() {

	asio::io_context io;
	asio::error_code errorcode;

	asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), 8080);

	asio::ip::tcp::socket socket(io);

	asio::ip::tcp::acceptor acceptor(io, endpoint);

	acceptor.accept(socket);

	std::array<char, 1024> buffer;

	auto length = socket.read_some(asio::buffer(buffer), errorcode);

	std::cout << "Client connected" << std::endl;
	std::cout << "Buffer output: ";
	std::cout.write(buffer.data(), length);
	std::cout << std::endl;
	

	io.run();

	return 0;

}