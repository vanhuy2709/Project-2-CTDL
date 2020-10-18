#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

class Employee
{
protected:
    string userEm;
    string passEm;
    string name;
    string address;
    string number;
    string email;
public:
    void LoginEmployee();
    void NhapEmployee();
    void Info();
    bool CheckEmployee();
    
    string getUser()
    {
        return userEm;
    }
    string getPass()
    {
        return passEm;
    }
    string getName()
    {
        return name;
    }
    string getAddress()
    {
        return address;
    }
    string getNumber()
    {
        return number;
    }
    string getEmail()
    {
        return email;
    }
    
    void setName(string newName)
    {
        name = newName;
    }
    void setAddress(string newAddress)
    {
        address = newAddress;
    }
    void setNumber(string newNumber)
    {
        number = newNumber;
    }
    void setEmail(string newEmail)
    {
        email = newEmail;
    }
    
    Employee();
    ~Employee();
};

Employee::Employee(){}
Employee::~Employee(){}

void Employee::LoginEmployee()
{
    cout << "\n Nhap username: ";
    cin >> userEm;
    
    cout << "\n Nhap password: ";
    cin >> passEm;
}
void Employee::NhapEmployee()
{
    cout << "\n Nhap thong tin cua User: " << endl;
    
    cin.ignore();
    cout << "Nhap username: " << endl;
    cin >> userEm;
    
    cin.ignore();
    
    cout << "Nhap ho va ten: " << endl;
    getline(cin, name);
    
    cout << "Nhap dia chi: " << endl;
    getline(cin, address);
    
    cout << "Nhap so dien thoai: " << endl;
    getline(cin, number);
    
    cout << "Nhap email: " << endl;
    getline(cin, email);
}
void Employee::Info()
{
    cout << "Username: " << userEm << endl;
    cout << "Password: " << 111111 << endl;
    cout << "Ho va ten: " << name << endl;
    cout << "Dia chi: " << address << endl;
    cout << "So dien thoai: " << number << endl;
    cout << "Email: " << email << endl;
    
    ofstream fileOut("[username].txt");
    
    fileOut << "Ho va ten: " << name << endl;
    fileOut << "Dia chi: " << address << endl;
    fileOut << "So dien thoai: " << number << endl;
    fileOut << "Email: " << email << endl;
    
    fileOut.close();
}
bool Employee::CheckEmployee()
{
    ifstream fileIn("inputEmployee.txt");
    string userInput;
    string passInput;
    
    fileIn >> userInput;
    fileIn >> passInput;
    
    fileIn.close();
    
    if (userInput == userEm && passInput == passEm)
    {
        return true;
    }
    else
    {
        return false;
    }
}

class Admin
{
private:
    string userAdmin;
    string passAdmin;
public:
    void LoginAdmin();
    bool CheckAdmin();
    
    void addEmployee();
    void deleteEmployee();
    void findEmployee();
    void updateEmployee();
    void EmployeeInfo();
    
    Admin();
    ~Admin();
};

Admin::Admin(){}
Admin::~Admin(){}

void Admin::LoginAdmin()
{
    cout << "\n Nhap user: ";
    cin >> userAdmin;
    
    cout << "\n Nhap pass: ";
    cin >> passAdmin;
}

bool Admin::CheckAdmin()
{
    ifstream fileIn("inputAdmin.txt");
    string userInput;
    string passInput;
    
    fileIn >> userInput;
    fileIn >> passInput;
    
    fileIn.close();
    
    if (userInput == userAdmin && passInput == passAdmin)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void deleteEmployee(Employee a[], int n, int index)
{
    for (int i = index; i < n; i++)
    {
        a[i] = a[i + 1];
    }
}
void Menu(Employee ds[], int &n)
{
    int choice;
    Employee nv;
    
    while (true)
    {
        cout << "\n\n\t\t * * * * * * * * * Menu * * * * * * * * *" << endl;
        cout << "\t\t       1. Them Employee" << endl;
        cout << "\t\t       2. Xoa Employee" << endl;
        cout << "\t\t       3. Tim Employee" << endl;
        cout << "\t\t       4. Cap nhat Employee" << endl;
        cout << "\t\t       5. Hien thi thong tin Employee" << endl;
        cout << "\t\t       6. Thoat!" << endl;
        cout << "\t\t * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << endl;
        
        cout << "\n Nhap lua chon: ";
        cin >> choice;
        
        if (choice < 1 || choice > 6)
        {
            cout << "Lua chon khong hop le. Xin kiem tra lai !" << endl;
        }
        else if (choice == 1)
        {
            nv.NhapEmployee();
            ds[n] = nv;
            n++;
        }
        else if (choice == 2)
        {
            cout << "\n Nhap user can xoa: ";
            
            string user_delete;
            cin >> user_delete;
            
            for (int i = 0; i < n; i++)
            {
                if (user_delete == ds[i].getUser())
                {
                    deleteEmployee(ds, n, i);
                }
            }
            n--;
            
            cout << "\n Danh sach sau khi xoa: " << endl;
            for (int i = 0; i < n; i++)
            {
                ds[i].Info();
                cout << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "\n Nhap user can tim: ";
            
            string user_find;
            cin >> user_find;
            
            for (int i = 0; i < n; i++)
            {
                if (user_find == ds[i].getUser())
                {
                    ds[i].Info();
                    break;
                }
            }
        }
        else if (choice == 4)
        {
            cout << "\n Nhap user can cap nhat thong tin: ";
            
            string user_update;
            cin >> user_update;
            
            for (int i = 0; i < n; i++)
            {
                if (user_update == ds[i].getUser())
                {
                    string newName, newAddress, newNumber, newEmail;
                    
                    while (true) {
                        cout << "\n 1. Ho va ten" << endl;
                        cout << "\n 2. Dia chi" << endl;
                        cout << "\n 3. So dien thoai" << endl;
                        cout << "\n 4. Email" << endl;
                        cout << "\n 5. Thoat cap nhat !" << endl;
                        
                        cout << "\n Chon thong tin can cap nhat: ";
                        
                        int option;
                        cin >> option;
                        if (option < 1 || option > 5)
                        {
                            cout << "Lua chon sai. Xin vui long chon lai !";
                        }
                        else if (option == 1)
                        {
                            cout << "Nhap ho va ten moi: ";
                            cin.ignore();
                            getline(cin, newName);
                            ds[i].setName(newName);
                        }
                        else if (option == 2)
                        {
                            cout << "Nhap dia chi moi: ";
                            cin.ignore();
                            getline(cin, newAddress);
                            ds[i].setAddress(newAddress);
                        }
                        else if (option == 3)
                        {
                            cout << "Nhap so dien thoai moi: ";
                            cin.ignore();
                            getline(cin, newNumber);
                            ds[i].setNumber(newNumber);
                        }
                        else if (option == 4)
                        {
                            cout << "Nhap email moi: ";
                            cin.ignore();
                            getline(cin, newEmail);
                            ds[i].setEmail(newEmail);
                        }
                        else if (option == 5)
                        {
                            break;
                        }
                    }
                }
            }
        }
        else if (choice == 5)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "Thong tin User thu " << i + 1 << ":" << endl;
                ds[i].Info();
                cout << endl;
            }
        }
        else if (choice == 6)
        {
            break;
        }
    }
}

int main()
{
    int select;
    
    while (true) {
        cout << "\n\n\t\t 1. Admin" << endl;
        cout << "\n\n\t\t 2. Employee" << endl;
        cout << "\n\n\t\t 3. Thoat chuong trinh !" << endl;
        cout << endl;
        
        cout << "\n\n Lua chon: ";
        cin >> select;
        
        if (select < 1 || select > 3)
        {
            cout << "Lua chon khong nam trong pham vi. Xin moi nhap lai";
        }
        else if (select == 1)
        {
            cout << "\n\n\t\t * * * * * * * * * * * * * * * * * * * *" << endl;
            cout << "\n\n\t\t *           DANG NHAP ADMIN           *" << endl;
            cout << "\n\n\t\t * * * * * * * * * * * * * * * * * * * *" << endl;
            cout << endl;
            
            while (true)
            {
                Admin ad;
                
                ad.LoginAdmin();
                if (ad.CheckAdmin() == true)
                {
                    cout << "Dang nhap thanh cong" << endl;
                    break;
                }
                else
                {
                    cout << "Dang nhap khong thanh cong" << endl;
                }
            }
            
            Employee ds[1001];
            int n = 0;
            
            Menu(ds, n);
            
        }
        else if (select == 2)
        {
            cout << "\n\n\t\t * * * * * * * * * * * * * * * * * * * *" << endl;
            cout << "\n\n\t\t *         DANG NHAP EMPLOYEES         *" << endl;
            cout << "\n\n\t\t * * * * * * * * * * * * * * * * * * * *" << endl;
            cout << endl;
            
            while (true)
            {
                Employee em;
                
                em.LoginEmployee();
                if (em.CheckEmployee() == true)
                {
                    cout << "Dang nhap thanh cong" << endl;
                    break;
                }
                else
                {
                    cout << "Dang nhap khong thanh cong. Xin moi thu lai" << endl;
                }
            }
        }
        else if (select == 3)
        {
            break;
        }
    }

    return 0;
}
