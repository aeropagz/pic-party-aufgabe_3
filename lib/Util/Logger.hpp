#pragma once
#include <iostream>

using std::string;

namespace logger
{
    class Logger;
}

class logger::Logger
{
    string logfile_;

public:
    Logger init(const string &path);
    Logger operator<<(string msg);
    void log(const string &msg);
    void append(const string &msg);
};
