#include <iostream>
#include <string>
#include <vector>

// Abstract Base Class
class HospitalStaff {
protected:
    std::string staffName;

public:
    // Constructor
    HospitalStaff(std::string name) : staffName(name) {}

    // Virtual destructor (crucial for abstract classes to prevent memory leaks)
    virtual ~HospitalStaff() {}

    // Pure virtual function
    virtual void performDuty() = 0;

    // Getter for the name
    std::string getName() const {
        return staffName;
    }
};

// Derived Class: Doctor
class Doctor : public HospitalStaff {
public:
    Doctor(std::string name) : HospitalStaff(name) {}

    void performDuty() override {
        std::cout << "[Doctor] " << staffName << " is diagnosing patients and prescribing treatments." << std::endl;
    }
};

// Derived Class: Nurse
class Nurse : public HospitalStaff {
public:
    Nurse(std::string name) : HospitalStaff(name) {}

    void performDuty() override {
        std::cout << "[Nurse] " << staffName << " is administering medication and checking patient vitals." << std::endl;
    }
};

// Derived Class: Receptionist
class Receptionist : public HospitalStaff {
public:
    Receptionist(std::string name) : HospitalStaff(name) {}

    void performDuty() override {
        std::cout << "[Receptionist] " << staffName << " is managing patient appointments and handling check-ins." << std::endl;
    }
};

int main() {
    // Create a collection of hospital staff using base class pointers
    std::vector<HospitalStaff*> hospitalRoster;

    // Instantiate different staff members dynamically
    hospitalRoster.push_back(new Doctor("Dr. Avery Smith"));
    hospitalRoster.push_back(new Nurse("Nurse Sarah Jones"));
    hospitalRoster.push_back(new Receptionist("Mark Miller"));

    std::cout << "--- Hospital Daily Shift Duties ---" << std::endl;
    
    // Demonstrate polymorphism: call performDuty() on each staff member
    for (HospitalStaff* staff : hospitalRoster) {
        staff->performDuty();
    }

    // Clean up dynamic memory
    for (HospitalStaff* staff : hospitalRoster) {
        delete staff;
    }
    hospitalRoster.clear();

    return 0;
}
