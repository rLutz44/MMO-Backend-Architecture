
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
			do_write();
		}
		else {
			std::cout << "Error reading from socket: " << read_error.message() << std::endl;
		}

	});

}

void Session::do_write()
{
	auto self = shared_from_this();

	auto response = std::make_shared<std::string>("Login succesful ");

	asio::async_write(socket, asio::buffer(*response), [this, self, response](const asio::error_code& error, size_t length) {
		if (!error) {
			std::cout << "Response sent to client: " << *response << std::endl;
			do_read();
		}
		else {
			std::cout << "Error writing to socket: " << error.message() << std::endl;
		}
	});
}

void Session::start( ) {
	do_read();
}