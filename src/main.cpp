#include <sys/stat.h>

#include <boost/asio/io_context.hpp>
#include <iostream>
#include <memory>

#include "boost/asio/ip/tcp.hpp"

namespace ip = boost::asio::ip;

void hande_request(std::shared_ptr<boost::asio::ip::tcp::socket>) {}

void start_accept(boost::asio::io_context &ioc, ip::tcp::acceptor &acceptor) {
	auto socket = std::make_shared<ip::tcp::socket>(ioc);
	acceptor.async_accept(*socket, [socket, &acceptor, &ioc](boost::system::error_code ec) {
		if (!ec) {
			std::cout << "Клиент подключился: " << socket->remote_endpoint() << std::endl;
		} else {
			std::cerr << "Ошибка подключения: " << ec.message() << std::endl;
		}

		start_accept(ioc, acceptor);
	});
}

int main() {
	boost::asio::io_context ioc;
	ip::tcp::acceptor acceptor(ioc, ip::tcp::endpoint(ip::tcp::v4(), 8080));

	start_accept(ioc, acceptor);
	ioc.run();
}
