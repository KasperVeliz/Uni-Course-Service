#include "../include/Course.h"
#include <iostream>

Course::Course(): id(""), title(""), seats(0){}

Course::Course(std::string_view id, std::string_view title, int seats): id(id), title(title), seats(seats){}

std::string_view Course::getId(){
    return this->id;
}

std::string_view Course::getTitle(){
    return this->title;
}

int Course::getSeats(){
    return this->seats;
}

std::string_view Course::updateId(std::string id){
    this->id = id;
    return this->id;
}

std::string_view Course::updateTitle(std::string title){
    this->title = title;
    return this->title;
}

int Course::updateSeats(int seats){
    this->seats = seats;
    return this->seats;
}

void Course::remove(){
    delete this;
}

std::string Course::print(){
    return std::format("Course ID: {}\nCourse Title: {}\nSeats: {}\n\n", id, title, seats);
}
