//
// init.h
// media-converter
// 
// Created by _ChingC on 2020/10/12.
// GitHub: https://github.com/ChingCdesu
// Copyright © 2020 _ChingC. All right reserved.
//
#ifndef MEDIA_CONVERTER_INIT_H
#define MEDIA_CONVERTER_INIT_H

#include <easylogging++.h>

INITIALIZE_EASYLOGGINGPP // 初始化logger

void init() {
    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput); // 带颜色log输出
    el::Loggers::getLogger("server");
}


#endif //MEDIA_CONVERTER_INIT_H
