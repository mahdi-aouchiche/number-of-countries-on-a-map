#include "number_of_countries.cpp"

int main() {

    // 11 countries
    vector<vector<int>> map1 = { 
        { 5, 4, 4 },
        { 4, 3, 4 },
        { 3, 2, 4 },
        { 2, 2, 2 },
        { 3, 3, 4 },
        { 1, 4, 4 },
        { 4, 1, 1 }
    };
    
    // 4 countries
    vector<vector<int>> map2 = { 
        { 1, 2},
        { 2, 2},
        { 3, 1},
        { 3, 3}
    };
    
    // 14 countries
    vector<vector<int>> map3 = { 
        { 5, 4, 4 ,5},
        { 4, 3, 4 ,5},
        { 3, 2, 4 ,4},
        { 2, 2, 2 ,1},
        { 3, 3, 4 ,2},
        { 1, 4, 4 ,1},
        { 4, 1, 1 ,1}
    };

    vector<vector<vector<int>>> vec = {map1, map2, map3};
    vector<int> solutions = {11, 4, 14};
    int passed = 0;
    int result = 0;
    
    for ( int i = 0; i < vec.size(); i++) {
        result = num_of_countries(vec[i]);
        passed += assert( i+1, result , solutions[i]);
    }
    cout << "TESTS PASSED: " << passed << "/" << vec.size() << endl;

    return 0;
}