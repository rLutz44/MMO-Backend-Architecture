#include <iostream>
#include <asio.hpp>
#include "messages.pb.h"


int main() {
	asio::io_context io;
	asio::ip::tcp::endpoint endpoint(asio::ip::make_address("127.0.0.1"), 8080);
	asio::ip::tcp::socket socket(io);
	asio::error_code errorcode;
	socket.connect(endpoint, errorcode);

	if (errorcode) {
		std::cout << "Failed to conect: " << errorcode.message() << std::endl;
		return 1;
	}

	std::cout << "Connected" << std::endl;


	while (true) {

		std::cout << "Enter Y to connect " << std::endl;
		std::string input;
		std::cin >> input;
		if (input != "Y") {continue;}

		mmo::network::LoginRequest loginRequest;
		loginRequest.set_username("abc");
		loginRequest.set_password("123");

		std::string transmission;
		loginRequest.SerializeToString(&transmission);

		asio::write(socket, asio::buffer(transmission));
		std::cout << "Message sent" << std::endl;

		std::array<char, 1024> buffer{};
		size_t length = socket.read_some(asio::buffer(buffer), errorcode);

		std::cout << "Server answer:  " << std::string(buffer.data(), length) << std::endl;;
	}
}