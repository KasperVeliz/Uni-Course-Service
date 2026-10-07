#pragma once
#include <string_view>

class CourseRequest {
    public:
        CourseRequest(std::string_view id, std::string_view title, int seats);

        virtual std::string_view getId();
        virtual std::string_view getTitle();
        virtual int getSeats();

    private:
        std::string_view id;
        std::string_view title;
        int seats;
};
