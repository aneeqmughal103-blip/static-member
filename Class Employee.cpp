#include <iostream>
#include <string>

class Employee {
private:
    int employeeID;
    std::string employeeName;

    // Static variable shared by all instances
    static std::string companyName;

public:
    // Constructor
    Employee(int id, std::string name) {
        employeeID = id;
        employeeName = name;
    }

    // Regular member function to display employee details
    void displayEmployeeInfo() const {
        std::cout << "ID: " << employeeID 
                  << " | Name: " << employeeName 
                  << " | Company: " << companyName << std::endl;
    }

    // Static member function to display company information
    static void displayCompanyInfo() {
        std::cout << "--- Company Info ---" << std::endl;
        std::cout << "Welcome to " << companyName << "!" << std::endl;
        std::cout << "--------------------" << std::endl;
    }
};

// Initialize the static variable outside the class
std::string Employee::companyName = "TechCorp Global";

int main() {
    // 1. Access the static function using the class name (before creating objects)
    Employee::displayCompanyInfo();
    std::cout << std::endl;

    // 2. Create multiple employee objects
    Employee emp1(101, "Alice Johnson");
    Employee emp2(102, "Bob Smith");
    Employee emp3(103, "Charlie Davis");

    // 3. Demonstrate that the company name is shared among all instances
    std::cout << "Displaying individual employee records:" << std::endl;
    emp1.displayEmployeeInfo();
    emp2.displayEmployeeInfo();
    emp3.displayEmployeeInfo();

    return 0;
}
