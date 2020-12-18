#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Customer
{
public:
    int number;
    string name;
    string address;
    string date;

    void add()
    {
        cin.ignore(100, '\n'); // ignores the '\n' symbol after each std::cin (without this getline() and std::cin works bad together)
        cout << "Enter customer's name: ";
        getline(cin, name);
        cout << "Enter customer's address: ";
        getline(cin, address);
        cout << "Enter customer's date of registration: ";
        getline(cin, date);
    }
};

vector <Customer> init_customers()
{
    ifstream cin("customers_default_list.txt");
    ofstream fout("customers_list.txt");
    int customers_number;
    cin >> customers_number;
    cin.ignore(100, '\n');
    cout << "Getting information about customers from a file..." << endl;
    vector <Customer> in(customers_number);
    for (int i = 0; i < customers_number; i++)
    {
        in[i].number = i + 1;
        getline(cin, in[i].name);
        getline(cin, in[i].address);
        cin >> in[i].date;
        cin.ignore(100, '\n');
        cout << "Customer #" << in[i].number << endl;
        cout << "Customer's name: " << in[i].name << endl;
        cout << "Customer's address: " << in[i].address << endl;
        cout << "Customer's date of registration: " << in[i].date << endl << endl;
        fout << "Customer #" << in[i].number << endl;
        fout << "Customer's name: " << in[i].name << endl;
        fout << "Customer's address: " << in[i].address << endl;
        fout << "Customer's date of registration: " << in[i].date << endl << endl;
    }
    return in;
}

void add_customer(vector <Customer> &customers)
{
    cout << "Enter information about customer #" << customers.size() + 1 << endl;
    Customer new_customer;
    new_customer.add();
    new_customer.number = customers.size() + 1;
    customers.push_back(new_customer);
    ofstream fout;
    fout.open("customers_list.txt", fstream::app);
    fout << "Customer #" << customers.size() << endl;
    fout << "Customer's name: " << new_customer.name << endl;
    fout << "Customer's address: " << new_customer.address << endl;
    fout << "Customer's date of registration: " << new_customer.date << endl << endl;
    fout.close();
}


void delete_customer(vector <Customer> &customers, int pos)
{

    customers.erase(customers.begin() + pos);
}

void print_file()
{
    ifstream cin ("customers_list.txt");
    string temp;
    while (!cin.eof())
    {
        getline(cin, temp);
        cout << temp << endl;
    }
}


int main()
{
    vector <Customer> customers = init_customers();

    while (true)
    {
        cout << "Do you want to add new customer? (Y or N): ";
        char answer;
        cin >> answer;
        if (answer == 'Y') add_customer(customers);
        else if (answer == 'N') break;
    }

    cout << "Do you want to see 'customers_list.txt' before deleting equal records? (Y or N) ";
    char ans;
    cin >> ans;
    cout << endl;
    if (ans == 'Y') print_file();


    for (int i = 0; i < customers.size(); i++)
    {
        for (int j = i + 1; j < customers.size(); j++)
        {
            if (customers[i].name == customers[j].name && customers[i].address == customers[j].address)
            {
                delete_customer(customers, j);
                j--;
            }
        }
    }


    cout << "List after deleting equal records: " << endl;
    for (auto i : customers)
    {
        cout << "Customer #" << i.number << endl;
        cout << "Customer's name: " << i.name << endl;
        cout << "Customer's address: " << i.address << endl;
        cout << "Customer's date of registration: " << i.date << endl << endl;
    }
}
