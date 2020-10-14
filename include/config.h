//
// config.h
// media-converter
//
// Created by _ChingC on 2020/10/12.
// GitHub: https://github.com/ChingCdesu
// Copyright © 2020 _ChingC. All right reserved.
//
#ifndef MEDIA_CONVERTER_CONFIG_HPP
#define MEDIA_CONVERTER_CONFIG_HPP

#include "util.h"
#include <INIReader.h>
#include <easylogging++.h>
#include <string>

class ConfigReader {
  private:
    ConfigReader() = delete;

    ConfigReader(const ConfigReader &) = delete;

    ConfigReader &operator=(const ConfigReader &) = delete;

    static INIReader *reader;

  public:
    static INIReader *getInstance() {
        if (nullptr == reader) {
            if (fileExist("config.ini")) {
                reader = new INIReader("config.ini");
            } else {
                try {
                    reader = new INIReader("config.default.ini");
                } catch (...) {
                    CLOG(ERROR, "server") << "config.default.ini not found, use the default config value.";
                }
            }
        }
        return reader;
    }
};

INIReader *ConfigReader::reader = nullptr;

#endif // MEDIA_CONVERTER_CONFIG_HPP
