#include <iostream>
#include <asio.hpp>
#include <array>

#include "messages.pb.h"
#include "CoreStateEngine.h"
#include <Session.h>


void handle_accept(asio::ip::tcp::acceptor& acceptor, asio::io_context& io) {

	acceptor.async_accept([&](const asio::error_code& error, asio::ip::tcp::socket socket) {
		if (!error) {
			std::cout << "Client connected" << std::endl;
			auto session = std::make_shared<Session>(std::move(socket));
			session->start();
			
		}
		else {
			std::cout << "Failed to accept connection: " << error.message() << std::endl;
		}

		handle_accept(acceptor, io);
		
		});


}

int main() {

	asio::io_context io;
	asio::error_code errorcode;
	asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), 8080);
	asio::ip::tcp::acceptor acceptor(io, endpoint);
	
	handle_accept(acceptor, io);

	io.run();

	return 0;

}