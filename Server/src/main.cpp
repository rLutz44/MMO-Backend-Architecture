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
	
	std::array<char, 1024> buffer;

	acceptor.async_accept(socket, [&](const asio::error_code& error) {
		if (!error) {
			std::cout << "Client connected" << std::endl;

			
			//auto length = socket.read_some(asio::buffer(buffer), errorcode);
			socket.async_read_some(asio::buffer(buffer), [&](const asio::error_code& read_error, size_t length) {
				if (!read_error) {

					mmo::network::LoginRequest incomingRequest;
					if (!incomingRequest.ParseFromArray(buffer.data(), length)) {
						std::cout << "Failed to parse message" << std::endl;
					}
	
					std::cout << "Login request received: " << incomingRequest.username() << " | Password: " << incomingRequest.password() << std::endl;

				}
				else {
					std::cout << "Error reading from socket: " << read_error.message() << std::endl;
				}
				
				});

			
		}
		else {
			std::cout << "Failed to accept connection: " << error.message() << std::endl;
		}
	});


	io.run();

	return 0;

}