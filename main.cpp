#include <iostream>
#include <vector>
#include <algorithm>

struct Patient{
    std::string surname;
    std::string name;
    std::string second_name;
    std::string address;
    long card_number;
    std::string diagnosis;
};

bool menu(std::vector<Patient>& patients){
    std::cout << "1. Add patient" << std::endl;
    std::cout << "2. Delete patient" << std::endl;
    std::cout << "3. Get patients by diagnosis" << std::endl;
    std::cout << "4. Get patients by card number" << std::endl;
    std::cout << "5. Exit" << std::endl;
    int choice;
    std::cin >> choice;
    switch(choice){
        case 1:{
            Patient patient;
            std::cout << "Enter surname of patient: " << std::endl;
            std::cin >> patient.surname;
            std::cout << "Enter name of patient: " << std::endl;
            std::cin >> patient.name;
            std::cout << "Enter second name of patient: " << std::endl;
            std::cin >> patient.second_name;
            std::cout << "Enter address of patient: " << std::endl;
            std::cin >> patient.address;
            std::cout << "Enter card number of patient: " << std::endl;
            long card_number;
            std::cin >> card_number;
            if(std::find_if(patients.begin(), patients.end(), [card_number](const Patient& patient){
                return patient.card_number == card_number;
            }) != patients.end()){
                std::cout << "Patient with this card number already exists!" << std::endl;
                return true;
            }
            patient.card_number = card_number;
            std::cout << "Enter diagnosis of patient: " << std::endl;
            std::cin >> patient.diagnosis;
            patients.push_back(patient);
            std::cout << "Patient successfully added!" << std::endl;
            return true;
        }

        case 2:{
            std::cout << "Enter card number of patient to delete:" << std::endl;
            long card_number;
            std::cin >> card_number;
            if(std::remove_if(patients.begin(), patients.end(), [card_number](const Patient& patient){
                return patient.card_number == card_number;
            }) != patients.end()){
                std::cout << "Patient successfully deleted!" << std::endl;
            } else {
                std::cout << "Patient not found!" << std::endl;
            }
            return true;
        }

        case 3:{
            std::cout << "Enter diagnosis of patient to find:" << std::endl;
            std::string diagnosis;
            std::cin >> diagnosis;
            auto it = std::find_if(patients.begin(), patients.end(), [diagnosis](const Patient& patient){
                return patient.diagnosis == diagnosis;
            });
            if(it != patients.end()){
                std::cout << "Patient found!" << std::endl;
                std::cout << "Surname: " << it->surname << std::endl;
                std::cout << "Name: " << it->name << std::endl;
                std::cout << "Second name: " << it->second_name << std::endl;
                std::cout << "Address: " << it->address << std::endl;
                std::cout << "Card number: " << it->card_number << std::endl;
                std::cout << "Diagnosis: " << it->diagnosis << std::endl;
            } else {
                std::cout << "Patient not found!" << std::endl;
            }
            return true;
        }

        case 4:{
            std::cout << "Enter card number of patient to find:" << std::endl;
            long card_number;
            std::cin >> card_number;
            auto it = std::find_if(patients.begin(), patients.end(), [card_number](const Patient& patient){
                return patient.card_number == card_number;
            });
            if(it != patients.end()){
                std::cout << "Patient found!" << std::endl;
                std::cout << "Surname: " << it->surname << std::endl;
                std::cout << "Name: " << it->name << std::endl;
                std::cout << "Second name: " << it->second_name << std::endl;
                std::cout << "Address: " << it->address << std::endl;
                std::cout << "Card number: " << it->card_number << std::endl;
                std::cout << "Diagnosis: " << it->diagnosis << std::endl;
            } else {
                std::cout << "Patient not found!" << std::endl;
            }
            return true;
        }

        case 5:{
            return false;
        }

        default:{
            std::cout << "Invalid choice!" << std::endl;
            return true;
        }

    }
}


int main() {
    std::vector<Patient> patients;
    while(menu(patients));
    return 0;
}
