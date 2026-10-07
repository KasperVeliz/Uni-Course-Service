#include "../include/Course.h"
#include "../include/CourseDao.h"
#include "../include/CourseService.h"
#include <unordered_map>
#include <stdio.h>
#include <iostream>


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
    std::printf(service.deleteCourse("cmp408") == true ? "deleted" : "not deleted");

    return 0;
}

int _main(){
    std::unordered_map<int, std::vector<int>*> map;
    std::vector<int>* v = new std::vector<int> {{1, 2, 3, 4}};
    map[1] = v;
    std::cout << map.size() << std::endl;
    std::cout << map[1];

    return 0;
}
