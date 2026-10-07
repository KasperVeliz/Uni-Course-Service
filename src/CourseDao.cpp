#include "../include/CourseDao.h"
#include <unordered_map>
#include <iostream>

CourseDao::CourseDao(){}

CourseDao::CourseDao(std::unordered_map<std::string_view, Course*> courses): courses(courses){}

Course* CourseDao::save(Course* course){
    std::cout << "In DAO:\n" << course->getId() << "\n";
    if(course->getId() != "" && !courses.contains(course->getId())){
        std::string_view key {course->getId()};
        courses[key] = course;
        std::cout << "[" << key << " , " << course << "]\n";
        return course;
    }
    std::cout << "nullptr\n\n";
    return nullptr;
}

Course* CourseDao::findById(std::string_view id){
    if(courses.contains(id)){
        return courses[id];
    }
    return nullptr; 
}

std::unordered_map<std::string_view, Course*>* CourseDao::findAll(){
    auto* ptrCourses = &courses;
    return ptrCourses;
}

bool CourseDao::deleteById(std::string_view id){
    if(courses.contains(id)){
        courses.erase(id);
        return true;
    }
    return false;
}

void CourseDao::print(){
    std::cout << courses.size();
}
