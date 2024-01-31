#include <iostream>
#include <boost/asio.hpp>

int main() {
    // 初始化 Boost.Asio 的 I/O 上下文
    boost::asio::io_service io_service;

    // 创建一个 TCP 解析器对象
    boost::asio::ip::tcp::resolver resolver(io_service);

    // 使用解析器解析服务器地址和端口
    boost::asio::ip::tcp::resolver::query query("github.com", "http");

    // 通过解析器获取远程服务器的终结点
    boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

    // 创建一个 TCP socket
    boost::asio::ip::tcp::socket socket(io_service);

    // 尝试连接到远程服务器
    boost::asio::connect(socket, endpoint_iterator);

    // 构造 HTTP 请求
    std::string request = "GET / HTTP/1.1\r\nHost: github.com\r\nConnection: close\r\n\r\n";

    // 发送 HTTP 请求
    boost::asio::write(socket, boost::asio::buffer(request));

    // 读取并输出服务器的响应
    boost::asio::streambuf response;
    boost::asio::read_until(socket, response, "</html>");
    std::cout << "Response: " << &response << std::endl;
    return 0;
}


