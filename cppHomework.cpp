#include <iostream>
#include <vector>
#include <string>

struct Student {
    int id;
    std::string name;
    int year_of_enrollment;

    Student(int id, const std::string& name, int year_of_enrollment)
        : id(id), name(name), year_of_enrollment(year_of_enrollment) {}
};

void addStudent(std::vector<Student>& students) {
    int id, year;
    std::string name;
    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cout << "Enter Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter Year of Enrollment: ";
    std::cin >> year;
    students.emplace_back(id, name, year);
    std::cout << "Student added successfully.\n";
}

void viewStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No students available.\n";
        return;
    }

    std::cout << "\nStudents List:\n";
    for (const auto& s : students) {
        std::cout << "ID: " << s.id << ", Name: " << s.name << ", Year: " << s.year_of_enrollment << "\n";
    }
}

void updateStudent(std::vector<Student>& students) {
    int id;
    std::cout << "Enter ID of the student to update: ";
    std::cin >> id;
    for (auto& student : students) {
        if (student.id == id) {
            std::cout << "Enter new Name: ";
            std::cin.ignore();
            std::getline(std::cin, student.name);
            std::cout << "Enter new Year of Enrollment: ";
            std::cin >> student.year_of_enrollment;
            std::cout << "Student updated successfully.\n";
            return;
        }
    }
    std::cout << "Student with ID " << id << " not found.\n";
}

void removeStudent(std::vector<Student>& students) {
    int id;
    std::cout << "Enter ID of the student to remove: ";
    std::cin >> id;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            std::cout << "Student removed successfully.\n";
            return;
        }
    }
    std::cout << "Student with ID " << id << " not found.\n";
}

int main() {
    std::vector<Student> students;
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. View Students\n";
        std::cout << "3. Update Student\n";
        std::cout << "4. Remove Student\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                viewStudents(students);
                break;
            case 3:
                updateStudent(students);
                break;
            case 4:
                removeStudent(students);
                break;
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}