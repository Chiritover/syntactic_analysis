#include "logger.h"

#include <iostream>
#include <string>

#include "../location.h"
#include "../base/common.h"
#include "../base/config.h"

void Logger::Log(const std::string& msg, const yy::location* p_location, std::ostream& os) {
    if (p_location) {
        auto location = *p_location;
        os << location.begin.line << ":" << location.begin.column << "-" << location.end.line << ":" << location.end.column << ": ";
    }
    os << msg;
    if (&os == &std::cout) os << RESET;
    os << "\n";
}

void Logger::Trace(const std::string& msg, const yy::location* p_location, std::ostream& os) {
    if (LOG_LEVEL <= TRACE) {
        if (&os == &std::cout) os << CYAN;
        os << "[TRACE] ";
        Log(msg, p_location, os);
    }
}

void Logger::Debug(const std::string& msg, const yy::location* p_location, std::ostream& os) {
    if (LOG_LEVEL <= DEBUG) {
        if (&os == &std::cout) os << GREEN;
        os << "[DEBUG] ";
        Log(msg, p_location, os);
    }
}

void Logger::Info(const std::string& msg, const yy::location* p_location, std::ostream& os) {
    if (LOG_LEVEL <= INFO) {
        if (&os == &std::cout) os << BLUE;
        os << "[INFO ] ";
        Log(msg, p_location, os);
    }
}

void Logger::Warn(const std::string& msg, const yy::location* p_location, std::ostream& os) {
    if (LOG_LEVEL <= WARN) {
        if (&os == &std::cout) os << YELLOW;
        os << "[WARN ] ";
        Log(msg, p_location, os);
    }
}

void Logger::Error(const std::string& msg, const yy::location* p_location, std::ostream& os) {
    if (LOG_LEVEL <= ERROR) {
        if (&os == &std::cout) os << RED;
        os << "[ERROR] ";
        Log(msg, p_location, os);
    }
}

void Logger::Fatal(const std::string& msg, const yy::location* p_location, std::ostream& os) {
    if (LOG_LEVEL <= FATAL) {
        if (&os == &std::cout) os << RED;
        os << "[FATAL] ";
        Log(msg, p_location, os);
    }
}
