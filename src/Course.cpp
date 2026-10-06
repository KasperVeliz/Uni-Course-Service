#include "Course.h"
#include <iostream>

Course::Course(): id(""), title(""), seats(0){}

Course::Course(std::string id, std::string title, int seats): id(id), title(title), seats(seats){}

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

void Course::print(){
    std::cout << "Course ID: " << id << "\nCourse Title: " << title << "%s\nSeats: " << seats << "\n\n";
}
