#include "../include/CourseRequests.h"

CourseRequest::CourseRequest(std::string_view id, std::string_view title, int seats)
    : id(id), title(title), seats(seats){}

std::string_view CourseRequest::getId(){
    return id;
}
std::string_view CourseRequest::getTitle(){
    return title;
}
int CourseRequest::getSeats(){
    return seats;
}
