#include "../include/CourseController.h"
#include "../include/exceptions/DuplicateCourseException.h"
#include "../include/exceptions/CourseNotFoundException.h"

#include <format>
#include <assert.h>

CourseController::CourseController(){}

CourseController::CourseController(CourseService* s): service(s){}

std::string CourseController::handleCreate(CourseRequest* req){
    try{
        service->create(req->getId(), req->getTitle(), req->getSeats());
        return std::format("Created course: {}\n", req->getId()); 
    }
    catch (DuplicateCourseException e){
        return e.what();
    }
}
std::string CourseController::handleGet(std::string_view id){
    try{
        Course* course = service->getRequired(id);
        return std::format("Course {} found:\n{}", course->getId(), course->print());
    }
    catch (CourseNotFoundException e){
        return e.what();
    }
}
std::string CourseController::handleList(){
    std::vector<Course*> courses = service->list();
    if (courses.empty()){
        return "No courses found\n";
    }
    return std::format("{} courses found\n", courses.size());
}
std::string CourseController::handleDelete(std::string_view id){
    bool deleted = service->deleteCourse(id);

    if (!deleted){
        return std::format("Error: Course: {} not found\n", id);
    }
    return std::format("Deleted course: {}\n", id);
}


