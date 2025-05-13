#include "../header/number_of_countries.hpp"
#include <queue>


int num_of_countries(vector<vector<int>>& map) {
    int count = 0;
    int rows = map.size();
    int cols = map[0].size();

    // Create a matrix to keep track of visited elements of the map
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Direction vectors (current(i,j), north(i-1,j), south(i+1,j), west(i,j-1), east(i,j+1))
    vector<int> row_direction = {-1, 0, 1, 0};  // North, West, South, East
    vector<int> col_direction = {0, -1, 0, 1};  // North, West, South, East

    // Go through each element of the map and check if it is visited
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {

            if(!visited[i][j]) {
                count++;
                visited[i][j] = true;

                // Perform BFS to find all elements that are in the same country
                queue<pair<int, int>> q;
                q.push({i,j});

                // Check surrounding elements if they are the same country
                while(!q.empty()) {

                    /*  int x = q.front().first;
                        int y = q.front().second;
                        
                        OR                   
                        
                        auto [x,y] = q.front();
                        
                        OR
                        
                        pair<int,int> p = q.front();
                        int x = p.first;
                        int y = p.second; 
                    */
                    auto [x,y] = q.front();
                    q.pop();
                    
                    for(int k = 0; k < row_direction.size(); k++) {
                        int x_new = x + row_direction[k];
                        int y_new = y + col_direction[k];

                        // Check if element is not visited and in the same country
                        if((x_new >= 0) && (x_new < rows) && (y_new >= 0) && (y_new < cols) 
                           && (!visited[x_new][y_new]) && (map[x][y] == map[x_new][y_new])) 
                        {
                            visited[x_new][y_new] = true;
                            q.push({x_new,y_new});    
                        }
                    }
                }
            }
        }
    }

    return count;
}


int assert(int test_number, int result, int expected) {
    if (result == expected) {
        cout << "Test " << test_number << ": passed! Expected: " << expected << ", got: " << result << endl;
        return 1;
    } else {
        cout << "Test " << test_number << ": failed! Expected: " << expected << ", but got: " << result << endl;
        return 0;
    }
}