#pragma once
#include <exception>
#include <string>

class DuplicateCourseException : public std::exception {
    public:
        DuplicateCourseException(const std::string& message);
        const char* what() const noexcept override;
    private:
        std::string message;
};
