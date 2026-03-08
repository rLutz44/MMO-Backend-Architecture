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

	mmo::network::LoginRequest incomingRequest;
	if (!incomingRequest.ParseFromArray(buffer.data(), length)) {
		std::cout << "Failed to parse message" << std::endl;
	}
	
	std::cout << "Login request received: " << incomingRequest.username() << " | Password: " << incomingRequest.password() << std::endl;

	io.run();

	return 0;

}