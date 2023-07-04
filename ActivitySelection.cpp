#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Function to compare activities based on their finish time
bool compareActivities(const Activity& a1, const Activity& a2) {
    return (a1.finish < a2.finish);
}

// Function to perform activity selection
void selectActivities(const std::vector<Activity>& activities) {
    // Sort activities based on finish time
    std::vector<Activity> sortedActivities = activities;
    std::sort(sortedActivities.begin(), sortedActivities.end(), compareActivities);
    
    // The first activity is always selected
    std::cout << endl << "Selected activities: ";
    std::cout << "(" << sortedActivities[0].start << ", " << sortedActivities[0].finish << ") ";
    
    // Select the remaining activities
    int lastSelected = 0;
    for (int i = 1; i < sortedActivities.size(); i++) {
        if (sortedActivities[i].start >= sortedActivities[lastSelected].finish) {
            std::cout << "(" << sortedActivities[i].start << ", " << sortedActivities[i].finish << ") ";
            lastSelected = i;
        }
    }
    std::cout << std::endl;
}

int main() {
    // Create a vector of activities
    std::vector<Activity> activities = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };

    // Perform activity selection
    selectActivities(activities);

    return 0;
}
