#pragma once
#include <string>

class Course {
    public:

        Course();
        Course(std::string_view id, std::string_view title, int seats);

        virtual std::string_view getId();
        virtual std::string_view getTitle();
        virtual int getSeats();

        virtual std::string_view updateId(std::string id);
        virtual std::string_view updateTitle(std::string title);
        virtual int updateSeats(int seats);
        virtual void remove();

        virtual std::string print(); 

    private:
        std::string id;
        std::string title;
        int seats;
};
