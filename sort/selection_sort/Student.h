//
// Created by yy on 2019-03-02.
//

#ifndef ALGORITHM_STUDENT_H
#define ALGORITHM_STUDENT_H

#include <iostream>
#include <string>

struct Student{
    std::string name;
    int score;

    bool operator<(const Student &otherStudent){
        return score < otherStudent.score;
    }

    friend std::ostream&operator<<(std::ostream &os, const Student &student){
        os << "Student" << student.name << " " << student.score << std::endl;
        return os;
    }
};

#endif //ALGORITHM_STUDENT_H
