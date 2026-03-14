#pragma once
#include <asio.hpp>

class Session: public std::enable_shared_from_this<Session>
{
public:
	Session(asio::ip::tcp::socket );
	~Session() = default;
	void start();

private:
	asio::ip::tcp::socket socket;
	std::array<char, 1024> buffer{};
	void do_read();


};