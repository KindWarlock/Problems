#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LEN = 100;

bool readLine(ifstream& in, char* line){
    line[0] = 0;
    in.getline(line, MAX_LEN, '\n');
    if (in.fail())
    {
        if (line[0] > 0)
            cout << "The string is too long" << endl;
        return false;
    }
    return true;
}

int countChars(ifstream& in){
    char line[MAX_LEN + 1];
    int max = 0;
    while (readLine(in, line)){
        if (strlen(line) > max)
            max = strlen(line);
    }
    return max;
}

void centerLine(char* line, const int full_len)
{
    int lineLength = strlen(line);
    int shift = (full_len - lineLength)/2;
    for (int i = lineLength; i >= 0; i--)
        line[i + shift] = line[i];
    for (int i = 0; i < shift; i++)
        line[i] = ' ';
}

int main()
{
    ifstream in("poem.txt");
    if (!in.is_open()){       
        cout << "No such file!";
        return 0;
    }
    ofstream out("out.txt");
    if (!out.is_open())
    {
        cout << "Unable to create an output file out.txt" << endl;
        return -2;
    } 
    char line[MAX_LEN + 1];
    int max = countChars(in);
    in.clear();
    in.seekg(0);
    while (readLine(in, line))
    {
        centerLine(line, max);
        out << line << endl;
    }
    in.close();
    out.close();
    return 0;
}
