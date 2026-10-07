#pragma once
#include <exception>
#include <string>

class CourseNotFoundException : public std::exception {
    public:
        CourseNotFoundException(const std::string& message);
        const char* what() const noexcept override;
    private:
        std::string message;
};
