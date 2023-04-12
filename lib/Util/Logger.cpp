#include <fstream>
#include "Logger.hpp"

using logger::Logger;
using std::cout;
using std::endl;

Logger Logger::init(const string &path)
{
    std::ofstream out{path};
    out << "Loveletter Game Log" << endl;
    out.close();
    logfile_ = path;
    return *this;
}

Logger Logger::operator<<(const string msg)
{
    log(msg);
    return *this;
}

void Logger::log(const string &msg)
{
    cout << msg;
    if (!(logfile_.length() == 0))
    {
        append(msg);
    }
}

void Logger::append(const string &msg)
{
    std::ofstream outfile;
    outfile.open(logfile_, std::ios_base::app);
    outfile << msg;
}