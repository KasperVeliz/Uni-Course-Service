#include "../include/CourseService.h"
#include "../include/exceptions/DuplicateCourseException.h"
#include "../include/exceptions/CourseNotFoundException.h"
#include <iostream>


CourseService::CourseService(CourseDao* dao): dao(dao){}

Course* CourseService::create(std::string_view id, std::string_view title, int seats){
    Course* c = new Course(id, title, seats);
    if (dao->findById(id) != nullptr){
        // Duplicate Found
        std::string e {id};
        throw DuplicateCourseException(e);
    }
    std::cout << "creating...\n";
    return dao->save(c);
}

Course* CourseService::getRequired(std::string_view id){
    Course* ptrCourse {dao->findById(id)};
    if (ptrCourse == nullptr){
        std::string e {id};
        throw CourseNotFoundException(e);
    }
    return ptrCourse;
}

std::vector<Course*> CourseService::list(){
    std::vector<Course*> courseVector {};
    for (auto& [k, v] : *dao->findAll()){
        courseVector.push_back(v);
    }
    return courseVector;
}

bool CourseService::deleteCourse(std::string_view id){
    return dao->deleteById(id);
}
