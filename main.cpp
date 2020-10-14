//
// main.cpp
// media-converter
//
// Created by _ChingC on 2020/10/12.
// GitHub: https://github.com/ChingCdesu
// Copyright © 2020 _ChingC. All right reserved.
//

#include "config.h"
#include "init.h"
#include <fmt/core.h>
#include <httplib.h>

using namespace httplib;

int main() {
    Server svr;
    init();
    auto config = ConfigReader::getInstance();

    int port = config->GetInteger("server", "port", 3000);         // 服务端端口
    std::string host = config->Get("server", "bind", "127.0.0.1"); // 服务端地址
    std::string static_folder = config->Get("server", "static-folder", "./public");

    auto ret = svr.set_mount_point("/", static_folder.c_str()); // 装载静态资源文件夹
    if (!ret) {
        CLOG(FATAL, "server") << "The specified base directory doesn't exist!";
    }
    // 设置access logger
    svr.set_logger([](const Request &req, const Response &res) {
        CLOG(INFO, "server") << req.path << " Accessed by " << req.remote_addr
                             << ", User-Agent: " << req.get_header_value("User-Agent");
    });
    // 设置error logger
    svr.set_error_handler([](const Request &req, Response &res) {
        std::stringstream _params, _headers, _files;
        for (const auto &p : req.params) {
            _params << p.first << "=" << p.second << std::endl;
        }
        for (const auto &h : req.headers) {
            _headers << h.first << ": " << h.second << std::endl;
        }
        CLOG(ERROR, "server") << req.method << " " << req.path << "\n"
                              << "Header: \n"
                              << _headers.str() << "\n"
                              << "Query: \n"
                              << _params.str() << "\n"
                              << "Body: \n"
                              << req.body;
        res.set_content("<h3>500 Internal Server Error</h3>", "text/html");
    });
    CLOG(INFO, "server") << fmt::format("Server is listening on {}:{}", host, port);
    svr.listen(host.c_str(), port); // 启动服务器监听

    return 0;
}