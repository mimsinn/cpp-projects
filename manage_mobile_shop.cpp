#include <iostream>
#include <tuple>
#include <vector> // برای دخیره اطلاعات موبایل نیست
using namespace std;

enum Os
{
    ios,
    android,
    windows,
    phone
};
enum Ram
{
    twoGB = 2,
    fourGB = 4,
    sixGB = 6,
    eightGB = 8,
    twelveGB = 12,
    sixteenGB = 16,
    thirtytwogb = 32,
    sixtyfourgb = 64
};
enum Storage
{
    sixtyGB = 16,
    thirtytwoGB = 32,
    sixtyfourGB = 64,
    onehundredtwentyeightGB = 128,
    twohundredfiftysixGB = 256,
    fivehundredtwelveGB = 512,
    oneT = 1,
    twoT = 2
};
enum Color
{
    black,
    white,
    blue,
    red,
    silver,
    gold
};
struct info
{
    string name;
    string compony;
    Os os;
    Ram Ram;
    Storage storage;
    float price;
    Color color;
    int numberofphone;
    int numberofsold;
};

pair<info *, int> add_phone(info *, int, vector<string> &, vector<string> &);
pair<info *, int> remove_phone(info *, int, vector<string> &, vector<string> &);
void search(string, string, info *, int);
void sort_by_price(info *&, int);
void change_mobile_info(string, string, info *&, int);
void sell_a_phone(string, string, info *&, int);
void print_phone(info *, int);
void most_sold_item(info *, int);
void printios(Os);
void printcolor(Color);

int main()
{
    info *phone;
    phone = new info[0];
    vector<string> temp_name;
    vector<string> temp_company;
    int size = 0;
    int select;
    do
    {
        cout << "1. add phone\n2. remove phone\n3. sort phone by price\n4. search phone\n5. change mobile info\n6. sell a phone\n7. print phones\n8. print phones sorted by the most sold to the least\n9. quit\n";
        cin >> select;
        if (select == 1)
        {
            tie(phone, size) = add_phone(phone, size, temp_name, temp_company);
        }
        if (select == 2)
        {
            tie(phone, size) = remove_phone(phone, size, temp_name, temp_company);
        }
        if (select == 3)
        {
            sort_by_price(phone, size);
            cout << "the least sorted\n";
        }
        if (select == 4)
        {
            string name;
            string company;
            cout << "enter name of phone: ";
            cin >> name;
            cout << "enter company: ";
            cin >> company;
            search(name, company, phone, size);
        }
        if (select == 7)
        {
            print_phone(phone, size);
        }
        if (select == 5)
        {
            string name;
            string company;
            cout << "enter name of phone: ";
            cin >> name;
            cout << "enter company: ";
            cin >> company;
            change_mobile_info(name, company, phone, size);
        }
        if (select == 6)
        {
            string name;
            string company;
            cout << "enter name of phone: ";
            cin >> name;
            cout << "enter company: ";
            cin >> company;
            sell_a_phone(name, company, phone, size);
        }
        if (select == 8)
        {
            most_sold_item(phone, size);
        }
    } while (select != 9);

    delete[] phone;
    system("pause");
    return 0;
}

pair<info *, int> add_phone(info *arr, int size, vector<string> &temp_name, vector<string> &temp_company)
{
    info *arr1;
    arr1 = new info[size + 1];
    if (size > 0)
    {
        for (int i = 0; i < size; i++)
        {
            arr1[i].name = arr[i].name;
            arr1[i].compony = arr[i].compony;
            arr1[i].os = arr[i].os;
            arr1[i].Ram = arr[i].Ram;
            arr1[i].storage = arr[i].storage;
            arr1[i].price = arr[i].price;
            arr1[i].color = arr[i].color;
            arr1[i].numberofphone = arr[i].numberofphone;
            arr1[i].numberofsold = arr[i].numberofsold;
        }
    }
    info add;
    int x = 0;
    int y;
    cout << "enter name of phone: ";
    cin >> add.name;
    cout << "enter compony of phone: ";
    cin >> add.compony;
    if (size > 0)
    {
        for (int i = 0; i < sizeof(temp_name); i++)
        {
            if (temp_name[i] == add.name)
            {
                x++;
            }
        }
        for (int i = 0; i < sizeof(temp_company); i++)
        {
            if (temp_company[i] == add.compony)
            {
                x++;
                y = i;
            }
        }
    }
    if (x == 2)
    {
        int num;
        cout << "how many phone you want to add? ";
        cin >> num;
        arr[y].numberofphone += num;
        return {arr, size};
    }
    else
    {
        string cnt0;
        do
        {
            cout << "enter Os of phone: ";
            cin >> cnt0;
            if (cnt0 == "ios")
            {
                add.os = Os::ios;
            }
            else if (cnt0 == "android")
            {
                add.os = Os::android;
            }
            else if (cnt0 == "windows")
            {
                add.os = Os::windows;
            }
            else if (cnt0 == "phone")
            {
                add.os = Os::phone;
            }
            else
            {
                cout << "the Os of phone is not corroct please try again\n";
            }
        } while (cnt0 != "ios" && cnt0 != "android" && cnt0 != "windows" && cnt0 != "phone");
        int cnt;
        do
        {
            cout << "enter Ram of phone: ";
            cin >> cnt;
            if (cnt == 2)
            {
                add.Ram = Ram::twoGB;
            }
            else if (cnt == 4)
            {
                add.Ram = Ram::fourGB;
            }
            else if (cnt == 6)
            {
                add.Ram = Ram::sixGB;
            }
            else if (cnt == 8)
            {
                add.Ram = Ram::eightGB;
            }
            else if (cnt == 12)
            {
                add.Ram = Ram::twelveGB;
            }
            else if (cnt == 16)
            {
                add.Ram = Ram::sixteenGB;
            }
            else if (cnt == 32)
            {
                add.Ram = Ram::thirtytwogb;
            }
            else if (cnt == 64)
            {
                add.Ram = Ram::sixtyfourgb;
            }
            else
            {
                cout << "the amunt of Ram is not corroct please try again\n";
            }
        } while (cnt != 2 && cnt != 4 && cnt != 6 && cnt != 8 && cnt != 12 && cnt != 16 && cnt != 32 && cnt != 64);
        int cnt1;
        do
        {
            cout << "enter Storage of phone: ";
            cin >> cnt1;
            if (cnt1 == 16)
            {
                add.storage = Storage::sixtyGB;
            }
            else if (cnt1 == 32)
            {
                add.storage = Storage::thirtytwoGB;
            }
            else if (cnt1 == 64)
            {
                add.storage = Storage::sixtyfourGB;
            }
            else if (cnt1 == 128)
            {
                add.storage = Storage::onehundredtwentyeightGB;
            }
            else if (cnt1 == 256)
            {
                add.storage = Storage::twohundredfiftysixGB;
            }
            else if (cnt1 == 512)
            {
                add.storage = Storage::fivehundredtwelveGB;
            }
            else if (cnt1 == 1)
            {
                add.storage = Storage::oneT;
            }
            else if (cnt1 == 2)
            {
                add.storage = Storage::twoT;
            }
            else
            {
                cout << "the amunt of Ram is not corroct please try again\n";
            }
        } while (cnt1 != 16 && cnt1 != 32 && cnt1 != 64 && cnt1 != 128 && cnt1 != 256 && cnt1 != 512 && cnt1 != 1 && cnt1 != 2);
        cout << "enter Price of phone: ";
        cin >> add.price;
        string cnt2;
        do
        {
            cout << "enter Color of phone: ";
            cin >> cnt2;
            if (cnt2 == "black")
            {
                add.color = Color::black;
            }
            else if (cnt2 == "white")
            {
                add.color = Color::white;
            }
            else if (cnt2 == "gold")
            {
                add.color = Color::gold;
            }
            else if (cnt2 == "blue")
            {
                add.color = Color::blue;
            }
            else if (cnt2 == "red")
            {
                add.color = Color::red;
            }
            else if (cnt2 == "silver")
            {
                add.color = Color::silver;
            }
            else
            {
                cout << "the Os of phone is not corroct please try again\n";
            }
        } while (cnt2 != "black" && cnt2 != "white" && cnt2 != "gold" && cnt2 != "blue" && cnt2 != "red" && cnt2 != "silver");
        cout << "enter number of phone: ";
        cin >> add.numberofphone;
        cout << "enter number of sold: ";
        cin >> add.numberofsold;
        temp_name.push_back(add.name);
        temp_company.push_back(add.compony);
        delete[] arr;
        arr1[size] = add;
        return {arr1, size + 1};
    }
}

pair<info *, int> remove_phone(info *arr, int size, vector<string> &temp_name, vector<string> &temp_company)
{
    string name;
    string company;
    cout << "enter name of phone: ";
    cin >> name;
    cout << "enter company: ";
    cin >> company;
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].name == name && arr[i].compony == company)
        {
            result = 1;
            info temp;
            temp = arr[size - 1];
            arr[size - 1] = arr[i];
            arr[i] = temp;
            swap(temp_name.at(i), temp_name.at(size - 1));
            swap(temp_company.at(i), temp_company.at(size - 1));
        }
    }
    if (result == 1)
    {
        info *arr1;
        arr1 = new info[size - 1];
        for (int i = 0; i < size - 1; i++)
        {
            arr1[i] = arr[i];
        }
        temp_company.pop_back();
        temp_name.pop_back();
        delete[] arr;
        return {arr1, size - 1};
    }
    else
    {
        cout << "the number not found" << endl;
        return {arr, size};
    }
}

void sort_by_price(info *&arr, int size)
{
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size - j - 1; i++)
        {
            if (arr[i].price < arr[i + 1].price)
            {
                string temp;
                temp = arr[i + 1].name;
                arr[i + 1].name = arr[i].name;
                arr[i].name = temp;
                temp = arr[i + 1].compony;
                arr[i + 1].compony = arr[i].compony;
                arr[i].compony = temp;
                Os temp1;
                temp1 = arr[i + 1].os;
                arr[i + 1].os = arr[i].os;
                arr[i].os = temp1;
                Color temp2;
                temp2 = arr[i + 1].color;
                arr[i + 1].color = arr[i].color;
                arr[i].color = temp2;
                Ram temp3;
                temp3 = arr[i + 1].Ram;
                arr[i + 1].Ram = arr[i].Ram;
                arr[i].Ram = temp3;
                Storage temp4;
                temp4 = arr[i + 1].storage;
                arr[i + 1].storage = arr[i].storage;
                arr[i].storage = temp4;
                int temp5;
                temp5 = arr[i + 1].numberofphone;
                arr[i + 1].numberofphone = arr[i].numberofphone;
                arr[i].numberofphone = temp5;
                temp5 = arr[i + 1].numberofsold;
                arr[i + 1].numberofsold = arr[i].numberofsold;
                arr[i].numberofsold = temp5;
                float temp6;
                temp6 = arr[i + 1].price;
                arr[i + 1].price = arr[i].price;
                arr[i].price = temp6;
            }
        }
    }
}

void most_sold_item(info *arr1, int size)
{
    info *arr;
    arr = new info[size];
    if (size > 0)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i].name = arr1[i].name;
            arr[i].compony = arr1[i].compony;
            arr[i].os = arr1[i].os;
            arr[i].Ram = arr1[i].Ram;
            arr[i].storage = arr1[i].storage;
            arr[i].price = arr1[i].price;
            arr[i].color = arr1[i].color;
            arr[i].numberofphone = arr1[i].numberofphone;
            arr[i].numberofsold = arr1[i].numberofsold;
        }
    }
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size - j - 1; i++)
        {
            if (arr[i].numberofsold < arr[i + 1].numberofsold)
            {
                string temp;
                temp = arr[i + 1].name;
                arr[i + 1].name = arr[i].name;
                arr[i].name = temp;
                temp = arr[i + 1].compony;
                arr[i + 1].compony = arr[i].compony;
                arr[i].compony = temp;
                Os temp1;
                temp1 = arr[i + 1].os;
                arr[i + 1].os = arr[i].os;
                arr[i].os = temp1;
                Color temp2;
                temp2 = arr[i + 1].color;
                arr[i + 1].color = arr[i].color;
                arr[i].color = temp2;
                Ram temp3;
                temp3 = arr[i + 1].Ram;
                arr[i + 1].Ram = arr[i].Ram;
                arr[i].Ram = temp3;
                Storage temp4;
                temp4 = arr[i + 1].storage;
                arr[i + 1].storage = arr[i].storage;
                arr[i].storage = temp4;
                int temp5;
                temp5 = arr[i + 1].numberofphone;
                arr[i + 1].numberofphone = arr[i].numberofphone;
                arr[i].numberofphone = temp5;
                temp5 = arr[i + 1].numberofsold;
                arr[i + 1].numberofsold = arr[i].numberofsold;
                arr[i].numberofsold = temp5;
                float temp6;
                temp6 = arr[i + 1].price;
                arr[i + 1].price = arr[i].price;
                arr[i].price = temp6;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << "name: " << arr[i].name << endl;
        cout << "compony: " << arr[i].compony << endl;
        cout << "os: ";
        printios(arr[i].os);
        cout << endl;
        cout << "Ram: " << arr[i].Ram << endl;
        cout << "storage: " << arr[i].storage << endl;
        cout << "price: " << arr[i].price << endl;
        cout << "color: ";
        printcolor(arr[i].color);
        cout << endl;
        cout << "number of phone: " << arr[i].numberofphone << endl;
        cout << "number of sold: " << arr[i].numberofsold << endl
             << endl;
    }
}

void search(string name, string company, info *phone, int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if (phone[i].name == name && phone[i].compony == company)
        {
            cout << "name: " << phone[i].name << endl;
            cout << "compony: " << phone[i].compony << endl;
            cout << "os: ";
            printios(phone[i].os);
            cout << endl;
            cout << "Ram: " << phone[i].Ram << endl;
            cout << "storage: " << phone[i].storage << endl;
            cout << "price: " << phone[i].price << endl;
            cout << "color: ";
            printcolor(phone[i].color);
            cout << endl;
            cout << "number of phone: " << phone[i].numberofphone << endl;
            cout << "number of sold: " << phone[i].numberofsold << endl
                 << endl;
            result++;
        }
    }
    if (result == 0)
    {
        cout << " -1 " << endl;
    }
}

void sell_a_phone(string name, string company, info *&phone, int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if (phone[i].name == name && phone[i].compony == company)
        {
            phone[i].numberofphone--;
            phone[i].numberofsold++;
            result++;
        }
    }
    if (result == 0)
    {
        cout << "the phone not found" << endl;
    }
}

void print_phone(info *phone, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "name: " << phone[i].name << endl;
        cout << "compony: " << phone[i].compony << endl;
        cout << "os: ";
        printios(phone[i].os);
        cout << endl;
        cout << "Ram: " << phone[i].Ram << endl;
        cout << "storage: " << phone[i].storage << endl;
        cout << "price: " << phone[i].price << endl;
        cout << "color: ";
        printcolor(phone[i].color);
        cout << endl;
        cout << "number of phone: " << phone[i].numberofphone << endl;
        cout << "number of sold: " << phone[i].numberofsold << endl
             << endl;
    }
}

void printios(Os ios)
{
    if (ios == 0)
    {
        cout << "ios";
    }
    else if (ios == 1)
    {
        cout << "android";
    }
    else if (ios == 2)
    {
        cout << "windows";
    }
    else if (ios == 3)
    {
        cout << "phone";
    }
}

void printcolor(Color color)
{
    if (color == 0)
    {
        cout << "black";
    }
    else if (color == 1)
    {
        cout << "white";
    }
    else if (color == 2)
    {
        cout << "blue";
    }
    else if (color == 3)
    {
        cout << "red";
    }
    else if (color == 4)
    {
        cout << "silver";
    }
    else if (color == 5)
    {
        cout << "gold";
    }
}

void change_mobile_info(string name, string company, info *&phone, int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if (phone[i].name == name && phone[i].compony == company)
        {
            result++;
            int cnt;
            do
            {
                cout << "what do you want to change?\n1. os\n2. Ram\n3. Storage\n4. Price\n5. Color\n6. numer of phone\n7. number of sold\n0. exit\n";
                cin >> cnt;
                if (cnt == 1)
                {
                    string temp0;
                    do
                    {
                        cout << "enter Os of phone: ";
                        cin >> temp0;
                        if (temp0 == "ios")
                        {
                            phone[i].os = Os::ios;
                        }
                        else if (temp0 == "android")
                        {
                            phone[i].os = Os::android;
                        }
                        else if (temp0 == "windows")
                        {
                            phone[i].os = Os::windows;
                        }
                        else if (temp0 == "phone")
                        {
                            phone[i].os = Os::phone;
                        }
                        else
                        {
                            cout << "the Os of phone is not corroct please try again\n";
                        }
                    } while (temp0 != "ios" && temp0 != "android" && temp0 != "windows" && temp0 != "phone");
                }
                else if (cnt == 2)
                {
                    int temp1;
                    do
                    {
                        cout << "enter Ram of phone: ";
                        cin >> temp1;
                        if (temp1 == 2)
                        {
                            phone[i].Ram = Ram::twoGB;
                        }
                        else if (temp1 == 4)
                        {
                            phone[i].Ram = Ram::fourGB;
                        }
                        else if (temp1 == 6)
                        {
                            phone[i].Ram = Ram::sixGB;
                        }
                        else if (temp1 == 8)
                        {
                            phone[i].Ram = Ram::eightGB;
                        }
                        else if (temp1 == 12)
                        {
                            phone[i].Ram = Ram::twelveGB;
                        }
                        else if (temp1 == 16)
                        {
                            phone[i].Ram = Ram::sixteenGB;
                        }
                        else if (temp1 == 32)
                        {
                            phone[i].Ram = Ram::thirtytwogb;
                        }
                        else if (temp1 == 64)
                        {
                            phone[i].Ram = Ram::sixtyfourgb;
                        }
                        else
                        {
                            cout << "the amunt of Ram is not corroct please try again\n";
                        }
                    } while (temp1 != 2 && temp1 != 4 && temp1 != 6 && temp1 != 8 && temp1 != 12 && temp1 != 16 && temp1 != 32 && temp1 != 64);
                }
                else if (cnt == 3)
                {
                    int temp2;
                    do
                    {
                        cout << "enter Storage of phone: ";
                        cin >> temp2;
                        if (temp2 == 16)
                        {
                            phone[i].storage = Storage::sixtyGB;
                        }
                        else if (temp2 == 32)
                        {
                            phone[i].storage = Storage::thirtytwoGB;
                        }
                        else if (temp2 == 64)
                        {
                            phone[i].storage = Storage::sixtyfourGB;
                        }
                        else if (temp2 == 128)
                        {
                            phone[i].storage = Storage::onehundredtwentyeightGB;
                        }
                        else if (temp2 == 256)
                        {
                            phone[i].storage = Storage::twohundredfiftysixGB;
                        }
                        else if (temp2 == 512)
                        {
                            phone[i].storage = Storage::fivehundredtwelveGB;
                        }
                        else if (temp2 == 1)
                        {
                            phone[i].storage = Storage::oneT;
                        }
                        else if (temp2 == 2)
                        {
                            phone[i].storage = Storage::twoT;
                        }
                        else
                        {
                            cout << "the amunt of Storage is not corroct please try again\n";
                        }
                    } while (temp2 != 16 && temp2 != 32 && temp2 != 64 && temp2 != 128 && temp2 != 256 && temp2 != 512 && temp2 != 1 && temp2 != 2);
                }
                else if (cnt == 4)
                {
                    int tempprice;
                    cin >> tempprice;
                    phone[i].price = tempprice;
                }
                else if (cnt == 5)
                {
                    string temp3;
                    do
                    {
                        cin >> temp3;
                        if (temp3 == "black")
                        {
                            phone[i].color = Color::black;
                        }
                        else if (temp3 == "white")
                        {
                            phone[i].color = Color::white;
                        }
                        else if (temp3 == "gold")
                        {
                            phone[i].color = Color::gold;
                        }
                        else if (temp3 == "blue")
                        {
                            phone[i].color = Color::blue;
                        }
                        else if (temp3 == "red")
                        {
                            phone[i].color = Color::red;
                        }
                        else if (temp3 == "silver")
                        {
                            phone[i].color = Color::silver;
                        }
                        else
                        {
                            cout << "the Color of phone is not corroct please try again\n";
                        }
                    } while (temp3 != "black" && temp3 != "white" && temp3 != "gold" && temp3 != "blue" && temp3 != "red" && temp3 != "silver");
                }
                else if (cnt == 6)
                {
                    int tempphone;
                    cin >> tempphone;
                    phone[i].numberofphone = tempphone;
                }
                else if (cnt == 7)
                {
                    int tempsold;
                    cin >> tempsold;
                    phone[i].numberofsold = tempsold;
                }
            } while (cnt != 0);
        }
    }
    if (result == 0)
    {
        cout << "the phone is not found" << endl;
    }
}
