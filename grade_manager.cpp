#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ranges>
#include <fstream>
#include <chrono>

struct Student {
    std::string name;
    int id;
    std::vector<double> grades; 
};

double findAverage(const std::vector<double>& grade) {
    double sum = 0;
    int length{static_cast<int>(grade.size())};
    for (auto a : grade) {
        sum += a;
    }
    return sum/length;
}

bool compareAverage(const Student& a, const Student& b) {
    return findAverage(a.grades) > findAverage(b.grades);
}

const Student* findStudent(const std::vector<Student>& students, const std::string& name) {
    for(auto& i : students) {
        if(i.name == name) {
            return &i;
        }
    }
    return nullptr;
}


void printDetails(const Student& student) {
    std::cout << "Student Name: " << student.name << '\n';
    std::cout << "Student ID: " << student.id << '\n';
    std::cout << "Student Grades: " << '\n';
    for(auto i : student.grades) {
        std::cout << i << '\n';
    }
    double average = findAverage(student.grades);
    std::cout << "Average Grade: " << average << '\n' << '\n';
} 

int main() {
    std::vector<Student> students{};
    Student s;
    std::ifstream inFile ("students.txt");
    if(inFile) {
    while (std::getline(inFile, s.name)) {
        inFile >> s.id;
        int gradeCount;
        inFile >> gradeCount;
        double grade;
        s.grades.clear();
        for(int a = 0; a < gradeCount; ++a) {
            inFile >> grade;
            s.grades.push_back(grade);
        }
        inFile.ignore();
        students.push_back(s);
    }
    }  else {
    students.push_back({"James Bond", 7, {67, 89, 85, 90}});
    students.push_back({"John Doe", 5, {88, 56, 80, 78}});
    students.push_back({"Alice Chen", 3, {92, 88, 95, 91}});
    students.push_back({"Bob Mensah", 12, {71, 65, 70, 68}});
    students.push_back({"Sara Otieno", 8, {55, 60, 58, 62}});
    }

    std::ofstream file ("students.txt");
    for(auto a : students) {
        file << a.name << '\n';
        file << a.id << '\n';
        file << a.grades.size() << '\n';
        for(int i = 0; i < a.grades.size(); ++i) {
            file << a.grades[i] << '\n';
        }
    }
    file.close();
    
    auto start = std::chrono::high_resolution_clock::now();
    std::ranges::sort(students, compareAverage);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time = " << duration.count() << " microseconds" << '\n';
    for (auto& i : students) {
        printDetails(i);
    }
    std::string name;
    std::cout << "Enter the full name of the student you are searching for: ";
    std::getline(std::cin, name);
    auto result = findStudent(students, name);
    if (result == nullptr) {
        std::cout << "Student not found." << '\n';
    } else printDetails(*result);

}