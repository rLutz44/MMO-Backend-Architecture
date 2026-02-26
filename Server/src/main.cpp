#include <iostream>
#include "messages.pb.h"


int main() {

	mmo::network::LoginRequest request;
	request.set_username("test");
	request.set_password("abc123");

	std::string network_data;
	request.SerializeToString(&network_data);

	std::cout << "--- MMO Server Start ---" << std::endl;
	std::cout << "Das fertige Netzwerk-Paket ist " << network_data.size() << " Bytes gross." << std::endl;

	return 0;
}