#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file("cnt.txt", ios::trunc);
    int *codeteam;
    string *teamname;
    string *cityname;
    string *couchname;
    string *playersname;
    string **players;
    int *pointteam;
    codeteam = new int[1];
    teamname = new string[1];
    cityname = new string[1];
    couchname = new string[1];
    playersname = new string[1];
    players = new string *[1];
    pointteam = new int[1];
    int size;
    string select;
    int x = 0;
    do
    {
        cout << "waht do you want?\nadd team = a\nedit = b\ndelete = c\nprint = f";
        cin >> select;
        if (select == "a")
        {
            codeteam = new int[x + 1];
            teamname = new string[x + 1];
            cityname = new string[x + 1];
            couchname = new string[x + 1];
            playersname = new string[x + 1];
            pointteam = new int[x + 1];
            cout << "enter codeteam:";
            cin >> codeteam[x];
            cout << "enter teamname:";
            cin >> teamname[x];
            cout << "enter cityname:";
            cin >> cityname[x];
            cout << "enter couchname:";
            cin >> couchname[x];
            cout << "enter number of players:";
            cin >> size;
            players[x] = new string[size];
            for (int i = 0; i < size; i++)
            {
                cout << "enter players" << i + 1 << ':';
                cin >> players[x][i];
            }
            cout << "enter pointteam:";
            cin >> pointteam[x];
            ofstream file("cnt.txt", ios::app);
            file << codeteam[x] << ' ' << teamname[x] << ' ' << cityname[x] << ' ' << couchname[x] << ' ';
            for (int j = 0; j < size; j++)
            {
                file << players[x][j] << ' ';
            }
            file << pointteam[x] << '\n';
            x++;
        }
        if (select == "b")
        {
            int searchname;
            int y = 0;
            int *select;
            cin >> searchname;
            for (int i = 0; i < x; i++)
            {
                if (codeteam[i] == searchname)
                {
                    y++;
                    select = new int[y];
                    select[y] = i;
                }
            }
            if (y == 1)
            {
                char cnt;
                int change;
                string change1;
                do
                {
                    cout << "what do you want to recreate?\nteam code = A\nname team = B\nname city = C\ncouch name = D\npleyers name = E\npoint team = F";
                    cin >> cnt;
                    if (cnt == 'A' || cnt == 'a')
                    {
                        cin >> change;
                        codeteam[select[y]] = change;
                    }
                    if (cnt == 'B' || cnt == 'b')
                    {
                        cin >> change1;
                        teamname[select[y]] = change1;
                    }
                    if (cnt == 'C' || cnt == 'c')
                    {
                        cin >> change1;
                        cityname[select[y]] = change1;
                    }
                    if (cnt == 'D' || cnt == 'd')
                    {
                        cin >> change1;
                        couchname[select[y]] = change1;
                    }
                    if (cnt == 'E' || cnt == 'e')
                    {
                        cin >> change1;
                        players[select[y]][0] = change1;
                    }
                    if (cnt == 'F' || cnt == 'f')
                    {
                        cin >> change;
                        pointteam[select[y]] = change;
                    }
                    cout << "Do you want to recreate anymore?(y/n)";
                    cin >> cnt;
                } while (cnt == 'Y' || cnt == 'y');
                ofstream file("cnt.txt", ios::trunc);
                for (int i = 0; i < x; i++)
                {
                    file << codeteam[i] << ' ' << teamname[i] << ' ' << cityname[i] << ' ' << couchname[i] << ' ';
                    for (int j = 0; j < size; j++)
                    {
                        file << players[i][j] << ' ';
                    }
                    file << pointteam[i] << '\n';
                }
            }
            else if (y > 1)
            {
                for (int i = 0; i < x; i++)
                {
                    cout << "etelaat" << select[i];
                }
                int temp;
                char cnt;
                int change;
                string change1;
                cin >> temp;
                do
                {
                    cout << "what do you want to recreate?\nteam code = A\nname team = B\nname city = C\ncouch name = D\npleyers name = E\npoint team = F";
                    cin >> cnt;
                    if (cnt == 'A' || cnt == 'a')
                    {
                        cin >> change;
                        codeteam[temp] = change;
                    }
                    if (cnt == 'B' || cnt == 'b')
                    {
                        cin >> change1;
                        teamname[temp] = change1;
                    }
                    if (cnt == 'C' || cnt == 'c')
                    {
                        cin >> change1;
                        cityname[temp] = change1;
                    }
                    if (cnt == 'D' || cnt == 'd')
                    {
                        cin >> change1;
                        couchname[temp] = change1;
                    }
                    if (cnt == 'E' || cnt == 'e')
                    {
                        cin >> change1;
                        players[temp][0] = change1;
                    }
                    if (cnt == 'F' || cnt == 'f')
                    {
                        cin >> change;
                        pointteam[temp] = change;
                    }
                    cout << "Do you want to recreate anymore?(y/n)";
                    cin >> cnt;
                } while (cnt == 'Y' || cnt == 'y');
            }
            else
            {
                cout << "not found";
            }
        }
        if (select == "c")
        {
            int searchcode;
            int x;
            cin >> searchcode;
            for (int i = 0; i < size; i++)
            {
                if (codeteam[i] == searchcode)
                {
                    x = i;
                }
            }
            for (int i = x; i < x; i++)
            {
                int temp = codeteam[i];
                codeteam[i] = codeteam[i + 1];
                codeteam[i + 1] = temp;
            }
            int *arr1;
            arr1 = new int[x - 1];
            for (int i = 0; i < x - 1; i++)
            {
                arr1[i] = codeteam[i];
            }
            for (int i = 0; i < x - 1; i++)
            {
                codeteam[i] = arr1[i];
            }
            for (int i = x; i < x; i++)
            {
                string temp = teamname[i];
                teamname[i] = teamname[i + 1];
                teamname[i + 1] = temp;
            }
            string *arr2;
            arr2 = new string[x - 1];
            for (int i = 0; i < x - 1; i++)
            {
                arr2[i] = teamname[i];
            }
            for (int i = 0; i < x - 1; i++)
            {
                teamname[i] = arr2[i];
            }
            for (int i = x; i < x; i++)
            {
                string temp = cityname[i];
                cityname[i] = cityname[i + 1];
                cityname[i + 1] = temp;
            }
            string *arr3;
            arr3 = new string[x - 1];
            for (int i = 0; i < x - 1; i++)
            {
                arr3[i] = cityname[i];
            }
            for (int i = 0; i < x - 1; i++)
            {
                cityname[i] = arr3[i];
            }
            for (int i = x; i < x; i++)
            {
                string temp = couchname[i];
                couchname[i] = couchname[i + 1];
                couchname[i + 1] = temp;
            }
            string *arr4;
            arr4 = new string[x - 1];
            for (int i = 0; i < x - 1; i++)
            {
                arr4[i] = couchname[i];
            }
            for (int i = 0; i < x - 1; i++)
            {
                couchname[i] = arr4[i];
            }
            // for (int i = x; i < x; i++)
            // {
            //     int temp = codeteam[i];
            //     codeteam[i] = codeteam[i + 1];
            //     codeteam[i + 1] = temp;
            // }
            // int *arr1;
            // arr1 = new int[x - 1];
            // for (int i = 0; i < x - 1; i++)
            // {
            //     arr1[i] = codeteam[i];
            // }
            // for (int i = 0; i < x - 1; i++)
            // {
            //     codeteam[i] = arr1[i];
            // }
            for (int i = x; i < x; i++)
            {
                int temp = pointteam[i];
                pointteam[i] = pointteam[i + 1];
                pointteam[i + 1] = temp;
            }
            int *arr6;
            arr6 = new int[x - 1];
            for (int i = 0; i < x - 1; i++)
            {
                arr6[i] = pointteam[i];
            }
            for (int i = 0; i < x - 1; i++)
            {
                pointteam[i] = arr6[i];
            }
        }

    } while (select != "exit");

    delete[] codeteam;
    delete[] teamname;
    delete[] cityname;
    delete[] couchname;
    delete[] playersname;
    delete[] * players;
    delete[] pointteam;
    system("pause");
    return 0;
}
