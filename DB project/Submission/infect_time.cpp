#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
//Even though I tried really hard, but still cannot read this csv, I don't know what happened, hoping for partial credits
using namespace std;

const float INVALID_FLOAT = 1E5;

struct Audience {
    string id;
    string name;
    float exposure = 0;
    float remain_exposure = 0;
    bool infected = false;
    bool has_audience = false;
};

vector<string> read_csv_line(std::istream& istream) {
    vector<string> result;
    string line;
    std::getline(istream, line);

    std::stringstream line_stream(line);
    string cell;

    while (std::getline(line_stream, cell, ',')) {
        result.push_back(cell);
    }
    if (!line_stream && cell.empty()) {
        // if there was a trailing comma then add an empty element
        result.emplace_back("");
    }
    return result;
}

void write_csv(std::ostream& os, const vector<Audience>& audiences) {
    for (const auto& a : audiences) {
        os << a.name << ',' << a.id << ',' << a.exposure << '\n';
    }
}

bool audience_cmp(const Audience& a, const Audience& b) {
    return a.exposure > b.exposure;
}

using Mat = vector<vector<Audience>>;

int main() {
    int aud_size = 64;
    std::ifstream ifile("audiences_info.csv");
    read_csv_line(ifile); // skip header
    vector<vector<Audience>> empty_mat(aud_size, vector<Audience>(aud_size));
    //Three dimensions, each one is an auditorium, and there are 6 in total
    vector<Mat> auditoriums(6, empty_mat);
    vector<int> n_audiences(6, 0);
    vector<int> n_infected(6, 0);
    vector<vector<std::pair<int, int>>> starting_points(6);

    /// read csv
    while (!ifile.eof()) {
        // name,id,row_Number,seat_Number,auditorium_Number,score,test_result
        auto tokens = read_csv_line(ifile);
        if (tokens.size() <= 1)
            break;
        char* tmp;
        string name = tokens[0];
        string id = tokens[1];
        int row = (int)std::strtol(tokens[2].c_str(), &tmp, 10) - 1;
        int col = (int)std::strtol(tokens[3].c_str(), &tmp, 10) - 1;
        int aud = (int)std::strtol(tokens[4].c_str(), &tmp, 10) - 1;
        float score = std::strtof(tokens[5].c_str(), &tmp);
        bool test = tokens[6] == "True";

        if (test) {
            n_infected[aud] += 1;
            starting_points[aud].push_back({ row, col });
        }

        auditoriums[aud][row][col].name = name;
        auditoriums[aud][row][col].id = id;
        auditoriums[aud][row][col].has_audience = true;
        auditoriums[aud][row][col].infected = test;
        auditoriums[aud][row][col].remain_exposure = score * 0.06f;
        n_audiences[aud] += 1;
    }

    vector<Audience> alert;
    