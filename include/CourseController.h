#pragma once
#import "CourseService.h"
#import "CourseRequests.h"

class CourseController {
    public:
        CourseController();
        CourseController(CourseService* s);

        virtual std::string handleCreate(CourseRequest* req);
        virtual std::string handleGet(std::string_view id);
        virtual std::string handleList();
        virtual std::string handleDelete(std::string_view id);

    private:
        CourseService* service;
};
