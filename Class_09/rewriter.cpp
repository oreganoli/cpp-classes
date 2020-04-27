#include <exception>
#include <fstream>
#include <iostream>
using namespace std;

enum class Gender
{
    Male,
    Female
};

void read_from_line(string &line, string &name, string &surname, Gender &gender,
                    int &age, double &salary)
{
    int prev_space = line.find(' ');
    int last_space;
    if (prev_space == -1)
    {
        throw runtime_error("Could not find a given name in the input string.");
    }
    name = line.substr(0, prev_space);
    last_space = line.find(' ', prev_space + 1);
    if (last_space == -1)
    {
        throw runtime_error("Could not find a surname in the input string.");
    }
    surname = line.substr(prev_space + 1, last_space - (prev_space + 1));
    prev_space = last_space;
    last_space = line.find(' ', prev_space + 1);
    if (last_space == -1)
    {
        throw runtime_error("Could not find a gender in the input string.");
    }
    string input = line.substr(prev_space + 1, last_space - (prev_space + 1));
    if (input == "M" || input == "m")
    {
        gender = Gender::Male;
    }
    else if (input == "K" || input == "k" || input == "F" || input == "f")
    {
        gender = Gender::Female;
    }
    else
    {
        throw runtime_error("Could not parse the gender given.");
    }
    prev_space = last_space;
    last_space = line.find(' ', prev_space + 1);
    if (last_space == -1)
    {
        throw runtime_error("Could not find an age in the input string.");
    }
    input = line.substr(prev_space + 1, last_space - (prev_space + 1));
    age = stoi(input);
    last_space = line.find(' ', prev_space + 1);
    if (last_space == -1)
    {
        throw runtime_error("Could not find a salary in the input string.");
    }
    salary = stod(line.substr(last_space + 1));
}

double rewrite(char *in_filename, int age_cutoff) {
    auto input_stream = ifstream(in_filename);
    string m_filename = "m";
    m_filename.append(in_filename);
    string f_filename = "f";
    f_filename.append(in_filename);
    auto men_stream = ofstream(m_filename);
    auto women_stream = ofstream(f_filename);
    ofstream *curr_stream;

    double men = 0;
    double sum_male_age = 0;
    
    string current_line;

    string name;
    string surname;
    Gender gender;
    int age;
    double salary;

    while (getline(input_stream, current_line))
    {
        read_from_line(current_line, name, surname, gender, age, salary);
        if (gender == Gender::Male) {
            curr_stream = &men_stream;
            men++;
            sum_male_age += age;
            salary *= (1 + ((double)age / 100));
        } else {
            curr_stream = &women_stream;
            if (age <= age_cutoff) {
                salary *= 0.97;
            } else {
                salary *= 1.05;
            }
        }
        *curr_stream << name << " " << surname << " " << age << " " << salary << endl;
    }
    input_stream.close();
    men_stream.close();
    women_stream.close();
    return sum_male_age / men;
}

int main()
{
    double avg = rewrite("rw_input.txt", 30);
    cout << "The mean age of all men in the input file is " << avg << endl;
}
