#pragma once
#include <stdexcept>
#include <string>

class MainException : public std::runtime_error {
public:
    MainException(const std::string& msg) : std::runtime_error(msg) {}
};
