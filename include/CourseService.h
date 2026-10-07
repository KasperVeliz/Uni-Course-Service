#pragma once
#include "CourseDao.h"
#include "Course.h"
#include <vector>

class CourseService {
    public:
        CourseService(CourseDao* dao);

        virtual Course* create(std::string_view id, std::string_view title, int seats);
        virtual Course* getRequired(std::string_view id);
        virtual std::vector<Course*> list();
        virtual bool deleteCourse(std::string_view id);

    private:
        CourseDao* dao;
};
