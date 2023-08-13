#include "Attribute Parser.h"

vector<string> lines;
string outLine;
vector<string> outLines;

vector<string> hrml;
vector<string> quer;
int n, q;
map<string, string> m;

int main()
{
    string h;


    cout << "========================================================================\n" << endl;
    cout << "                          ATRRIBUTE PARSER\n" << endl;
    cout << "========================================================================\n" << endl;
    cout << "\n" << endl;

    while (true)
    {
        cout << "Enter the path to the input file:   " << endl;
        getline(cin, h);
        if (filesystem::exists(h))
        {
            cout << "Valid Path" << endl;
            cout << "\n";
            break;
        }
        else
        {
            cout << "Invalid Path. Again" << endl;
        }
    }


    cout << "========================================================================\n" << endl;
    cout << "Complete read file: \n" << endl;

    readFile(h);
    n = lines[0][0] - 48;
    q = lines[0][2] - 48;

    for (int i = 1; i <= n; i++)
    {
        hrml.push_back(lines[i]);
        cout << lines[i] << endl;
    }
    for (int i = n + 1; i <= n + q; i++)
    {
        quer.push_back(lines[i]);
        cout << lines[i] << endl;
    }
    string temp;

    vector<string> tag;

    for (int i = 0; i < n; i++)
    {
        temp = hrml[i];
        temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '>'), temp.end());
        if (temp.substr(0, 2) == "</")
        {
            tag.pop_back();
        }
        else
        {
            stringstream ss;
            ss.str("");
            ss << temp;
            string t1, p1, v1;
            char ch;
            ss >> ch >> t1 >> p1 >> ch >> v1;
            string temp1 = "";
            if (tag.size() > 0)
            {
                temp1 = *tag.rbegin();
                temp1 = temp1 + "." + t1;
            }
            else
                temp1 = t1;
            tag.push_back(temp1);
            m[*tag.rbegin() + "~" + p1] = v1;
            while (ss)
            {
                ss >> p1 >> ch >> v1;
                m[*tag.rbegin() + "~" + p1] = v1;
            }
        }
    }
    cout << "========================================================================\n" << endl;

    while (true)
    {
        cout << "Enter the path to the output  file:   " << endl;
        getline(cin, h);
        if (filesystem::exists(h))
        {
            cout << "Valid Path" << endl;
            cout << "\n";
            break;
        }
        else
        {
            cout << "Invalid Path. Again" << endl;
        }
    }
    cout << "========================================================================\n" << endl;
    cout << "\nComplite write to file:\n";
    writeFile(h);
    getchar();
    return 0;
}