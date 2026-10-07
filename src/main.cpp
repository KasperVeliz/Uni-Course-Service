#include "../include/Course.h"
#include "../include/CourseDao.h"
#include "../include/CourseService.h"
#include <unordered_map>
#include <stdio.h>


int main(){
    std::unordered_map<std::string_view, Course*> map;
    CourseDao* courses = new CourseDao(map);
    CourseService service(courses);

    Course* cmp408 = service.create("cmp408", "Software Engineering", 24);
    Course* cmp410 = service.create("cmp410", "Algorithms", 30);

    courses->print();
//    std::vector<Course*> courses {service.list()};
//    for (Course* c : courses){
//        c->print();
//    }
//    service.getRequired("cmp1");
    service.deleteCourse("cmp408");
    courses->print();

    return 0;
}
