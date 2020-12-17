#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Ticket
{
public:
    string name;
    string date;
    string status;
    int number;

    Ticket()
    {
        name = "default_name";
        date = "01.01.2020";
        status = "not ready";
        number = -1;
    }

    print()
    {
        printf("Ticket #%d\n", number);
        printf("Name of the product: %s\n", name.c_str());
        printf("Receipt date: %s\n", date.c_str());
        printf("Status: %s\n", status.c_str());
        printf("\n");
    }

    get()
    {
        printf("Enter the name of the product (of - to set default value): ");
        scanf("%s", name.c_str());
        if (name[0] == '-') name = "default name";
        printf("Enter the receipt date of the product (of - to set default value): ");
        scanf("%s", date.c_str());
        if (date[0] == '-') date = "01.01.2020";
        printf("Enter the current status of the product (of - to set default value): ");
        scanf("%s", status.c_str());
        if (status[0] == '-') status = "not ready";
        printf("\n");
    }
};

void sorting(vector <Ticket> &tickets) // sorts tickets by status
{
    for (int i = 0; i < tickets.size(); i++)
    {
        for (int j = i + 1; j < tickets.size(); j++)
        {
            if (tickets[i].status > tickets[j].status) // n < r
            {
                swap(tickets[i], tickets[j]);
            }
        }
    }
}

void get_tickets(vector <Ticket> &tickets) // gets default tickets
{
    for (int i = 0; i < tickets.size(); i++)
    {
        printf("Entering the information about ticket #%d\n", i + 1);
        tickets[i].get();
        tickets[i].number = i + 1;
    }
}

void print_tickets(vector <Ticket> &tickets) // prints new tickets
{
    for (int i = 0; i < tickets.size(); i++)
    {
        printf("Printing the information...\n");
        tickets[i].print();
    }
}

void add_new(vector <Ticket> &tickets) // adds new ticket
{
    Ticket tmp;
    tmp.get();
    tmp.number = tickets.size() + 1;
    tickets.push_back(tmp);
}

void find_notready(vector <Ticket> &tickets) // finds not-ready tickets
{
    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i].status[0] == 'n')
        {
            printf("Ticket #%d is not ready\n", tickets[i].number);
        }
        else break;
    }
    printf("\n");
}

int main()
{
    int tickets_number;
    printf("tickets number: ");
    scanf("%d", &tickets_number);

    vector <Ticket> tickets(tickets_number);

    get_tickets(tickets);
    print_tickets(tickets);

    while (true)
    {
        string tmp;
        printf("Want to add new ticket? (Y or N): ");
        scanf("%s", tmp.c_str());
        if (tmp[0] == 'N') break;
        else if (tmp[0] == 'Y')
        {
            add_new(tickets);
            print_tickets(tickets);
        }
    }

    sorting(tickets);
    find_notready(tickets);
    print_tickets(tickets);
}
