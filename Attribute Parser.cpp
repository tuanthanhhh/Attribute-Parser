 #include "Attribute Parser.h"

extern vector<string> lines;
extern string outLine;
extern vector<string> outLines;
extern map<string, string> m;
extern int q;
extern vector<string> quer;


void readFile(string a)
{
    vector<string> linesOfTag;
    vector<string> linesOfQ;
    string line;
    ifstream infile;
    infile.open(a, ios::in);
    while (getline(infile, line))
    {
        lines.push_back(line);
    }
    infile.close();
}

void writeFile(string a)
{
    int dem = 0;
    ofstream outfile;
    outfile.open(a, ios::out);
    while (!outfile.is_open())
    {
        cout << "Error";
    }
    for (int i = 0; i < q; i++)
    {
        if (m.find(quer[i]) == m.end())
        {
            cout << "Not Found!\n";
            outLine = "Not Found!";
            outLines.push_back(outLine);
            dem++;
        }
        else
        {
            cout << m[quer[i]] << endl;
            outLine = m[quer[i]];
            outLines.push_back(outLine);
            dem++;
        }
    }

    for (int i = 0; i < dem; i++)
    {
        outfile << outLines[i] << endl;
    }

    outfile.close();
}