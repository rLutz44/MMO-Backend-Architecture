
#include <iostream>
#include <asio.hpp>
#include "messages.pb.h"
#include "Session.h"

Session::Session(asio::ip::tcp::socket socket) : socket(std::move(socket)), buffer( {} ) {

}

void Session::do_read() {

	auto self = shared_from_this();

	socket.async_read_some(asio::buffer(buffer), [this, self](const asio::error_code& read_error, size_t length ) {
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

void Session::start( ) {
	do_read();
}