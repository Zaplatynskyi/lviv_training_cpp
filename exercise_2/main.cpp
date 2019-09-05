#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "Exam.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include <string>


void addExamToMap(std::istringstream &iss_record, std::map<int,Exam> &exams) {
    int id, courseId, studentId, result;
    iss_record>>id>>courseId>>studentId>>result;
    Exam exam(id, courseId, studentId, result);
    exams.insert(std::pair<int, Exam>(exam.getId(), exam));
}

void addStudentToMap(std::istringstream &iss_record, std::map<int,Student> &students) {
    int id;
    std::string name;
    iss_record>>id>>name;
    Student student(id, name);
    students.insert(std::pair<int, Student>(student.getId(), student));
}

void addTeacherToMap(std::istringstream &iss_record, std::map<int,Teacher> &teachers) {
    int id;
    std::string name;
    iss_record>>id>>name;
    Teacher teacher(id, name);
    teachers.insert(std::pair<int, Teacher>(teacher.getId(), teacher));
}

void addCourseToMap(std::istringstream &iss_record, std::map<int,Course> &courses) {
    int id, teacherId;
    std::string name;
    iss_record>>id>>teacherId>>name;
    Course course(id,name, teacherId);
    courses.insert(std::pair<int, Course>(course.getId(), course));
}


template <class T>
void writeToFile(const std::string &fileName, const std::map<int, T> &dataMap){
    std::ofstream output_file(fileName);
    if(output_file) {
        for(const auto &data : dataMap) {
            output_file << data.second.getFormatted() << std::endl;
        }
    } else {
        std::cerr << "Unable to create file." << std::endl;
    }
}

int main(int argc, char **argv) {
    std::map<int, Course> courses;
    std::map<int, Exam> exams;
    std::map<int, Student> students;
    std::map<int, Teacher> teachers;
    std::string fileData,marker;
    std::ifstream file(argv[1]);
    if (file.is_open()) {
        while (getline(file,fileData)){
            std::istringstream iss_record(fileData);
            std::getline(iss_record, marker, ',');
            if (marker == "E") {
                addExamToMap(iss_record,exams);
            } else if (marker == "T")  {
                addTeacherToMap(iss_record,teachers);
            } else if (marker == "C")  {
                addCourseToMap(iss_record,courses);
            } else if (marker == "S")  {
                addStudentToMap(iss_record,students);
            }
        }
    }
    else
        perror("file not open");
    writeToFile("./Exams.txt", exams);
    writeToFile("./Teachers.txt", teachers);
    writeToFile("./Cources.txt", courses);
    writeToFile("./Students.txt", students);
    return 0;
}
