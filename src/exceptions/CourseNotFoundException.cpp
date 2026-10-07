#include "../../include/exceptions/CourseNotFoundException.h"

CourseNotFoundException::CourseNotFoundException(const std::string& message)
    : message("Error 404: Course " + message + " not found") {}

const char* CourseNotFoundException::what() const noexcept {
    return message.c_str();
}
