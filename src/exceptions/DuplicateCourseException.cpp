#include "../../include/exceptions/DuplicateCourseException.h"

DuplicateCourseException::DuplicateCourseException(const std::string& message)
    : message("Error 422: Duplicate course id -> " + message){}

const char* DuplicateCourseException::what() const noexcept {
    return message.c_str();
}
