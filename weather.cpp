#include <iostream>
#include <fstream>
#include <tuple>
#include <string>

using namespace std;

const int WINTER_CODE = 1,
          SUMMER_CODE = 3;

tuple <int, int> FindPos(string line, int column) {
    int cnt = 0,
        pos_start = 0,
        str_length;
    while (cnt < column - 1) {
        pos_start = line.find(' ', pos_start) + 1;
        cnt++;
    }
    str_length = line.find(' ', pos_start) + 1 - pos_start;
    return { pos_start,  str_length };
}

int GetTemperature(string line) {
    auto [ tmp_start, tmp_length ] = FindPos(line, 8);
    string tmp_str = line.substr(tmp_start, tmp_length);
    return stoi(tmp_str);
}

tuple<char, int> GetSeasonAndYear(string line) {
    auto [ year_start, year_length ] = FindPos(line, 2);
    auto [ month_start, month_length ] = FindPos(line, 3);
    int year = stoi(line.substr(year_start, year_length)),
        month = stoi(line.substr(month_start, month_length));
    int season;
    switch (month) {
    case 1:
    case 2:
    case 12:
        season = WINTER_CODE;
        break;
    case 6:
    case 7:
    case 8:
        season = SUMMER_CODE;
        break;
    default:
        season = -1;
    }
    return { season, year };
}

int main()
{
    string file_name;
    cout << "Enter weather file name: ";
    cin >> file_name;
    ifstream input_file;
    input_file.open(file_name + '\0');
    while (!input_file) {
        cout << "No such file!\n";
        cout << "Enter weather file name: ";
        cin >> file_name;
        input_file.open(file_name + '\0');
    }

    string line;
    int tmp_year = 0, tmp_win = 0, tmp_sum = 0,
        cnt_year = 0, cnt_win = 0, cnt_sum = 0;
    int prev_year = 0;
    while (getline(input_file, line)) {
        int tmp = GetTemperature(line);
        if (tmp == 9999) {
            continue;
        }
        auto [season, year] = GetSeasonAndYear(line);
        if (!prev_year)
            prev_year = year;
        if (year != prev_year) {
            if (cnt_year)
                cout << prev_year << ": " << (double)tmp_year / cnt_year << endl;
            if (cnt_win)
                cout << "    winter: " << (double)tmp_win / cnt_win << endl;
            if (cnt_sum)
                cout << "    summer: " << (double)tmp_sum / cnt_sum << endl;
            tmp_year = 0;
            tmp_win = 0;
            tmp_sum = 0;
            cnt_year = 0; 
            cnt_win = 0; 
            cnt_sum = 0;
            prev_year = year;
        }
        tmp_year += tmp;
        cnt_year++;
        if (season == 1) {
            tmp_win += tmp;
            cnt_win++;
        }
        else if (season == 3) {
            tmp_sum += tmp;
            cnt_sum++;
        }
    }
    input_file.close();
    return 0;
}