#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <random>
#include <string>

using namespace std;
namespace fs = std::experimental::filesystem;

int main(){
    string folder = "generated_tests";
    if(!fs::exists(folder)){
        fs::create_directory(folder);
    }
    
    int num_tests = 5;
    int length = 100000; // Adjust the length if needed
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 2); // indices for three characters
    const char chars[3] = {'<', '>', '?'};
    
    for (int i = 1; i <= num_tests; i++){
        string test;
        test.resize(length);
        for (int j = 0; j < length; j++){
            test[j] = chars[dis(gen)];
        }
        
        string filename = folder + "/testcase" + to_string(i) + ".txt";
        ofstream out(filename);
        if (!out){
            cerr << "Error creating file " << filename << endl;
            continue;
        }
        out << test;
        out.close();
        cout << "Generated " << filename << " with length " << length << "\n";
    }
    
    return 0;
}
