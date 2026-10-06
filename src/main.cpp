#include "../include/Course.h"
#include "../include/CourseDao.h"
#include <stdio.h>

CourseDao courses {CourseDao()};
Course cmp408 {Course("cmp408", "Software Engineering", 24)};

int main(){
    Course* added {courses.save(cmp408)};
    Course* found = courses.findById("cmp408");

    if(added == found){
        std::printf("Course added = Course found\n\n");
        added->print();
    }
    return 0;
}
