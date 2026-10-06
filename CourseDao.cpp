#include "CourseDao.h"

CourseDao::CourseDao(): courses(std::unordered_map<std::string_view, Course*>{}){

}

CourseDao::CourseDao(std::unordered_map<std::string_view, Course*> courses): courses(courses){}

Course* CourseDao::save(Course course){
    if(course.getId() != "" && !courses[course.getId()]){
        Course* val {&course};
        std::string_view key {course.getId()};
        courses[key] = val;
        return val;
    }
    return nullptr;
}

Course* CourseDao::findById(std::string_view id){
    const auto& iter = courses.find(id);
    if(iter != courses.end()){
        return iter->second;
    }
    return nullptr; 
}

std::unordered_map<std::string_view, Course*>* CourseDao::findAll(){
    auto* ptrCourses = &courses;
    return ptrCourses;
}

bool CourseDao::deleteById(std::string_view id){
    auto iter = courses.find(id);
    if(iter != courses.end()){
        courses.erase(iter);
        return true;
    }
    return false;
}
