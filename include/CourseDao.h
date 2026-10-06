#pragma once
#include "Course.h"
#include <unordered_map>
#include <string>

class CourseDao {
    public:
        CourseDao();
        CourseDao(std::unordered_map<std::string_view, Course*> courses);

        virtual Course* save(Course course);
        virtual Course* findById(std::string_view id);
        virtual std::unordered_map<std::string_view, Course*>* findAll();
        virtual bool deleteById(std::string_view id);

    private:
        std::unordered_map<std::string_view, Course*> courses;
};
