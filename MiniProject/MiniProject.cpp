#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class address {
    int aID;
    int street_number;
    char* street_name;
    char* city;
    char* state_abbreviation;
    int zip_code;
    static int matchedAddresses;

public:
    address() {
        aID = -1;
        street_number = 0;
        street_name = nullptr;
        city = nullptr;
        state_abbreviation = nullptr;
        zip_code = 0;
    }
    ~address() {
        delete[] street_name;
        delete[] city;
        delete[] state_abbreviation;
    }
    address(int i, int s, char* sn, char* c, char* sa, int z) {
        aID = i;
        street_number = s;
        setStreetName(sn);
        setCity(c);
        setState(sa);
        zip_code = z;

    }

    virtual void setID(int i) { aID = i; }
    void setStreetNum(int i) { street_number = i; }
    void setStreetName(char* src) {
        if (src == nullptr) {
            street_name = nullptr;
            return;
        }
        int l = 0;
        while (src[l] != '\0') l++;
        street_name = new char[l + 1];
        l = 0;
        while (src[l] != '\0') {
            street_name[l] = src[l];
            l++;
        }
        street_name[l] = '\0';
    }
    void setCity(char* src) {
        if (src == nullptr) {
            city = nullptr;
            return;
        }
        int l = 0;
        while (src[l] != '\0') l++;
        city = new char[l + 1];
        l = 0;
        while (src[l] != '\0') {
            city[l] = src[l];
            l++;
        }
        city[l] = '\0';
    }

    void setState(char* src) {
        if (src == nullptr) {
            state_abbreviation = nullptr;
            return;
        }
        int l = 0;
        while (src[l] != '\0') l++;
        state_abbreviation = new char[l + 1];
        l = 0;
        while (src[l] != '\0') {
            state_abbreviation[l] = src[l];
            l++;
        }
        state_abbreviation[l] = '\0';
    }
    void setZip(int i) { zip_code = i; }

    virtual int getID() { return aID; }
    int getStreetNum() { return street_number; }
    char* getStreetName() { return street_name; }
    char* getCity() { return city; }
    char* getState() { return state_abbreviation; }
    int getZip() { return zip_code; }

    friend void print(address& a) {
        cout << "ID: " << a.getID() << " Street Number: " << a.getStreetNum() << " Street Name: ";
        if (a.getStreetName() == nullptr)
            cout << "NONAME";
        else
            cout << a.getStreetName();
        cout << " City: ";

        if (a.getCity() == nullptr)
            cout << "NONAME";
        else
            cout << a.getCity();

        cout << " State: ";

        if (a.getState() == nullptr)
            cout << "NONAME";
        else
            cout << a.getState();
        cout << "Zip Code: " << a.getZip() << endl;
    }

    void print() {
        cout << "ID: " << aID << endl;
        cout << "Street Number: " << street_number << endl;
        cout << "Street Name: ";
        if (street_name == nullptr)
            cout << "NONAME" << endl;
        else
            cout << street_name << endl;
        cout << "City: ";
        if (city == nullptr)
            cout << "NONAME" << endl;
        else
            cout << city << endl;
        cout << "State Abbreviation: ";
        if (state_abbreviation == nullptr)
            cout << "NONAME" << endl;
        else
            cout << state_abbreviation << endl;
        cout << "Zip Code: " << zip_code << endl;
        cout << "Counter: " << matchedAddresses << endl;
    }



};

enum DEPARTMENT { DEFAULT = 0, SALES, CUSTOMER_SERVICE, PRODUCTION, HUMAN_RESOURCES, ACCOUNTING, RESEARCH_AND_DEVELOPMENT };

class employee {
    int aID;
    char* full_name;
    DEPARTMENT department;

public:
    static int numEmployees;

    int getNumEmployees() { return numEmployees; }
    employee() {
        aID = -1;
        full_name = nullptr;
        department = DEFAULT;
    }
    employee(int i, char* name, DEPARTMENT d) {
        employee::numEmployees++;
        aID = i;
        setFullName(name);
        department = d;
    }
    ~employee() {
        if (full_name != nullptr) {
            delete[] full_name;
            numEmployees--;
        }
    }
    virtual void setID(int i) { aID = i; }
    void setFullName(char* src) {
        if (src == nullptr) {
            full_name = nullptr;
            return;
        }
        int l = 0;
        while (src[l] != '\0') l++;
        delete[] full_name;
        full_name = new char[l + 1];
        l = 0;
        while (src[l] != '\0') {
            full_name[l] = src[l];
            l++;
        }
        full_name[l] = '\0';
    }
    void setDepartment(DEPARTMENT d) { department = d; }

    virtual int getID() { return aID; }
    char* getFullName() { return full_name; }
    DEPARTMENT getDepartment() { return department; }

    friend void print(employee& e) {
        cout << "ID: " << e.getID() << " Name: ";
        if (e.getFullName() == nullptr)
            cout << "NONAME";
        else
            cout << e.getFullName();
        cout << " Department: " << e.getDepartment() << endl;
    }

    void print() {
        cout << "ID: " << aID << endl;
        cout << "Full Name: ";
        if (full_name == nullptr)
            cout << "NONAME" << endl;
        else
            cout << full_name << endl;
        cout << "Department: " << department << endl;
        cout << "Counter: " << numEmployees << endl;
    }



};

class record : public employee, public address {

public:


    const char* printDpt() {
        switch (getDepartment()) {
        case SALES:
            return "SALES";
            break;
        case CUSTOMER_SERVICE:
            return "CUSTOMER SERVICE";
            break;
        case PRODUCTION:
            return "PRODUCTION";
            break;
        case HUMAN_RESOURCES:
            return "HUMAN RESOURCES";
            break;
        case ACCOUNTING:
            return "ACCOUNTING";
            break;
        case RESEARCH_AND_DEVELOPMENT:
            return "RESEARCH AND DEVELOPMENT";
            break;
        default:
            return "DEFAULT";
            break;
        }
    }

    friend void print(record& r) {
        if (r.getStreetName() == nullptr)
            cout << left << setw(5) << r.employee::getID() << setw(20) << r.getFullName() << setw(30) << "NOSTREET" << setw(25) << "NOCITY" << setw(13) << "NOSTATE" << setw(11) << r.getZip() << setw(12) << r.printDpt();
        else
            cout << left << setw(5) << r.employee::getID() << setw(20) << r.getFullName() << right << setw(4) << setfill('0') << r.getStreetNum() << left << setfill(' ') << " " << setw(25) << r.getStreetName() << setw(25) << r.getCity() << setw(13) << r.getState() << setw(11) << r.getZip() << setw(12) << r.printDpt();;

        cout << endl;

    }
};

int getLengthOfFile(char* fn) {
    ifstream input;
    input.open(fn);
    if (!input.is_open()) {
        cout << "Error opening file\n";
        return -1;
    }
    char buffer[5000];

    int i = 0;

    while (!input.eof()) {
        input.getline(buffer, sizeof(buffer));
        i++;
    }
    return i;
}

int readDataFromFile(char* filename, int size, address*& arr) {

    ifstream input;
    input.open(filename);
    if (!input.is_open()) {
        cout << "Error opening file\n";
        return -1;
    }
    int i = 0;
    int t;
    char buffer[5000];
    bool duplicate = false;

    while (!input.eof() && i < size) {
        duplicate = false;
        input >> t;
        for (int k = 0; k < size; k++) {
            if (arr[k].getID() == t) {
                duplicate = true;
                break;
            }
        }
        arr[i].setID(t);
        input >> t;
        arr[i].setStreetNum(t);
        input.get();
        input.getline(buffer, sizeof(buffer));
        arr[i].setStreetName(buffer);
        input.getline(buffer, sizeof(buffer));
        arr[i].setCity(buffer);
        input >> buffer;
        arr[i].setState(buffer);
        input >> t;
        arr[i].setZip(t);
        i++;

    }
    return i;
}

int readDataFromFile(char* filename, int size, employee*& arr) {

    ifstream input;
    input.open(filename);
    if (!input.is_open()) {
        cout << "Error opening file\n";
        return -1;
    }

    int i = 0;
    int t;
    int d;
    char buffer[5000];

    while (!input.eof() && i < size) {
        input >> t;
        input.get();
        input.getline(buffer, sizeof(buffer));
        input >> d;
        arr[i].setID(t);
        arr[i].setFullName(buffer);
        arr[i].setDepartment(static_cast<DEPARTMENT>(d));
        i++;
    }
    return i;
}

void combineInfo(employee* emp, address* add, record*& data, int emLen, int adSize, int size) {
    for (int i = 0; i < emLen; i++) {
        for (int k = 0; k < adSize; k++) {
            data[i].employee::setID(emp[i].getID());
            data[i].setFullName(emp[i].getFullName());
            data[i].setDepartment(emp[i].getDepartment());
            if (emp[i].getID() == add[k].getID()) {
                data[i].address::setID(add[k].getID());
                data[i].setStreetNum(add[k].getStreetNum());
                data[i].setStreetName(add[k].getStreetName());
                data[i].setState(add[k].getState());
                data[i].setZip(add[k].getZip());
                data[i].setCity(add[k].getCity());
                break;
            }
        }
    }
}

void printByAddressID(record* data, int size, int look) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (data[i].address::getID() == look) {
            print(data[i]);
            found = true;
        }
    }
    if (!found)
        cout << "No Matching address ids found\n";
}

void printByAddressZip(record* data, int size, int look) {
    bool foundZip = false;
    for (int i = 0; i < size; i++) {
        if (data[i].address::getZip() == look) {
            print(data[i]);
            foundZip = true;
        }
    }
    if (!foundZip)
        cout << "No matching zip codes found\n";
}


void swapRecords(record& a, record& b) {
    record* temp = new record();
    temp->setDepartment(a.getDepartment());
    temp->setCity(a.getCity());
    temp->setState(a.getState());
    temp->setFullName(a.getFullName());
    temp->employee::setID(a.employee::getID());
    temp->setStreetName(a.getStreetName());
    temp->setStreetNum(a.getStreetNum());
    temp->setZip(a.getZip());

    a.setDepartment(b.getDepartment());
    a.setCity(b.getCity());
    a.setState(b.getState());
    a.setFullName(b.getFullName());
    a.employee::setID(b.employee::getID());
    a.setStreetName(b.getStreetName());
    a.setStreetNum(b.getStreetNum());
    a.setZip(b.getZip());

    b.setDepartment(temp->getDepartment());
    b.setCity(temp->getCity());
    b.setState(temp->getState());
    b.setFullName(temp->getFullName());
    b.employee::setID(temp->employee::getID());
    b.setStreetName(temp->getStreetName());
    b.setStreetNum(temp->getStreetNum());
    b.setZip(temp->getZip());

    delete temp;
}


void sortByID(record*& data, int size) {
    record* temp = new record();
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (data[j - 1].employee::getID() > data[j].employee::getID()) {
                swapRecords(data[j - 1], data[j]);

            }
        }
    }
    delete temp;
}

void sortByZip(record* data, int size) {
    record* temp = new record();
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (data[j - 1].getZip() > data[j].getZip()) {
                swapRecords(data[j - 1], data[j]);

            }
        }
    }
    delete temp;
}

int employee::numEmployees = 0;
int address::matchedAddresses = 0;
int main() {

    char addressesFile[100];//
    char employeesFile[100];//
    static int size = 0;
    int lenOfEmployees = 0;
    int lenOfAddresses = 0;
    record* data = nullptr;
    employee* em = nullptr;
    address* add = nullptr;
    char option;
    bool addressFile = false;
    bool employeeFile = false;
    bool dataMade = false;
    int choice;
    do {
        if (dataMade)
            cout << "a.Enter address file fullpath \nb.Enter employee file fullpath\nc.Read files\n\t1) Print record by index\nd.Print data\ne.Search:\nf.Sort\ng.Exit\nChoose your option: ";
        else
            cout << "a.Enter address file fullpath \nb.Enter employee file fullpath\nc.Read files\nd.Print data\ne.Search:\nf.Sort\ng.Exit\nChoose your option: ";
        cin >> option;
        while (getchar() != '\n');
        switch (option) {
        case 'a': {
            cout << "Enter the fullpath for addresses file: " << endl;
            cin >> addressesFile;

            lenOfAddresses = getLengthOfFile(addressesFile) / 3;
            if (lenOfAddresses > 0)
                cout << "[SUCCESS] -  File reading is complete ..." << endl << endl;
            else {
                cout << "[ERROR] - Enter file location first..." << endl << endl;
                break;
            }
            addressFile = true;
            add = new address[lenOfAddresses];
            readDataFromFile(addressesFile, lenOfAddresses, add);


            break;
        }
        case 'b': {

            cout << "Enter the fullpath for employees file: " << endl;
            cin >> employeesFile;
            lenOfEmployees = getLengthOfFile(employeesFile) / 2;
            if (lenOfEmployees >= 0)
                cout << "[SUCCESS] -  File reading is complete ..." << endl << endl;
            else {
                cout << "[ERROR] - Enter file location first..." << endl << endl;
                break;
            }

            employeeFile = true;
            em = new employee[lenOfEmployees];
            readDataFromFile(employeesFile, lenOfEmployees, em);
            size = lenOfEmployees;

            break;
        }
        case 'c': {
            if (!dataMade) {
                if (!(addressFile && employeeFile)) {
                    cout << "[ERROR] - Enter file location first..." << endl;
                    break;
                }
                data = new record[size];
                combineInfo(em, add, data, lenOfEmployees, lenOfAddresses, size);
                cout << "[SUCCESS] -  File reading is complete ...\n";

                delete[] em;
                delete[] add;
                dataMade = true;
            }
            else {
                int index;
                cout << "Enter index: ";
                cin >> index;
                if (index < 0 || index > size) {
                    cout << "[ERROR] -  Invalid index value ..." << endl << endl;
                    break;
                }
                print(data[index]);
            }

            break;
        }
        case 'd':
        {
            //  cout << employee::numEmployees << endl;
            if (dataMade) {
                cout << "ID   FULL NAME\t\t STREET ADDRESS\t\t       CITY\t\t\tSTATE\t     ZIP\tDEPARTMENT\n";
                for (int i = 0; i < size; i++)
                    if (data[i].employee::getID() != -1)
                        print(data[i]);
            }
            else {
                cout << "Data hasn't been made yet";
            }
            break;
        }
        case 'e':
        {
            cout << "\t1. Address ID\n\t2. ZipCode\n";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter the id: ";
                cin >> choice;
                printByAddressID(data, size, choice);
            }
            else if (choice == 2) {
                cout << "Enter the ZipCode: ";
                cin >> choice;
                printByAddressZip(data, size, choice);

            }
            else {
                cout << "Invalid choice\n";
            }


            break;
        }
        case 'f':
        {
            cout << "\t1. Sort the records by Address Id\n\t2. Sort the records by Zip Code.\n";
            cin >> choice;

            if (choice == 1) {
                sortByID(data, size);
            }
            else if (choice == 2) {
                sortByZip(data, size);

            }
            else {
                cout << "Invalid choice\n";
            }
            break;
        }
        case 'g':
            cout << "Ending the program ...\n";
            break;
        default:
            cout << "Invalid option, try again!\n";
            break;
        }

    } while (option != 'g' && option != 'G');


    return 0;
}