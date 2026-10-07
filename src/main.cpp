#include "../include/Course.h"
#include "../include/CourseDao.h"
#include "../include/CourseService.h"
#include "../include/CourseController.h"
#include "../include/CourseRequests.h"

#include <unordered_map>
#include <stdio.h>
#include <iostream>


int main(){
    std::unordered_map<std::string_view, Course*> map;
    CourseDao* ptrDao = new CourseDao(map);
    CourseService* ptrService = new CourseService(ptrDao);
    CourseController* ptrController = new CourseController(ptrService);

    
    CourseRequest* ptrReq1 = new CourseRequest("cmp408", "Software Engineering", 24);
    CourseRequest* ptrReq2 = new CourseRequest("cmp410", "Algorithms", 30);
    CourseRequest* ptrReq3 = new CourseRequest("cmp405", "Networking", 26);

    std::array<CourseRequest*, 3> reqs {{ptrReq1, ptrReq2, ptrReq3}};

    for (CourseRequest* req : reqs){
        std::cout << ptrController->handleCreate(req) << '\n';
    }
    
    std::cout << ptrController->handleList() << '\n';


    std::cout << ptrController->handleDelete("cmp000") << '\n';
    std::cout << ptrController->handleDelete("cmp405") << '\n';

    std::cout << ptrController->handleList() << '\n';

    std::cout <<  ptrController->handleGet("cmp405") << '\n';
    std::cout <<  ptrController->handleGet("cmp408") << '\n';

    return 0;
}
