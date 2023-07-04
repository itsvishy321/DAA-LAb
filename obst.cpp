#include<bits/stdc++.h>
using namespace std;

// Function to find the optimal cost of OBST
float findOBST(const vector<float>& keys, const vector<float>& probabilities)
{
    int n = keys.size();

    // Create a 2D table to store the costs
    vector<vector<float>> cost(n, vector<float>(n, 0.0));

    // Initialize the diagonal values with probabilities
    for (int i = 0; i < n; i++)
        cost[i][i] = probabilities[i];

    // Fill the table in bottom-up manner
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Try making each key in the range 'i' to 'j' as root
            for (int k = i; k <= j; k++) {
                float currentCost = ((k > i) ? cost[i][k - 1] : 0.0)
                    + ((k < j) ? cost[k + 1][j] : 0.0);
                if (currentCost < cost[i][j])
                    cost[i][j] = currentCost;
            }

            // Add the probabilities of keys in the range 'i' to 'j'
            for (int k = i; k <= j; k++)
                cost[i][j] += probabilities[k];
        }
    }

    // Return the optimal cost
    return cost[0][n - 1];
}

int main()
{
    vector<float> keys = { 10.0, 12.0, 20.0 };
    vector<float> probabilities = { 0.34, 0.08, 0.50 };

    float optimalCost = findOBST(keys, probabilities);

    cout << endl<<"The optimal cost of the optimal binary search tree is: " << optimalCost << endl;

    return 0;
