//
// util.h
// media-converter
// 
// Created by _ChingC on 2020/10/12.
// GitHub: https://github.com/ChingCdesu
// Copyright © 2020 _ChingC. All right reserved.
//
#ifndef MEDIA_CONVERTER_UTIL_H
#define MEDIA_CONVERTER_UTIL_H

#include <string>
#include <fstream>

static bool fileExist(const std::string &path) {
    std::ifstream fin(path);
    if (!fin) {
        return false;
    } else {
        fin.close();
        return true;
    }
}


#endif //MEDIA_CONVERTER_UTIL_H
