#include <bits/stdc++.h>
using namespace std;

struct Place {
    string name;
    int cost;
    int value;
};

int main() {
    int budget;
    cin >> budget;

    vector<Place> places = {
        {"Goa", 5000, 10},
        {"Manali", 3000, 7},
        {"Jaipur", 2000, 5},
        {"Kerala", 4000, 8}
    };

    // Sort by value/cost ratio
    sort(places.begin(), places.end(), [](Place a, Place b) {
        return (double)a.value/a.cost > (double)b.value/b.cost;
    });

    double totalValue = 0;

    for (auto &p : places) {
        if (budget >= p.cost) {
            budget -= p.cost;
            totalValue += p.value;
            cout << p.name << " FULL\n";
        } else {
            double fraction = (double)budget / p.cost;
            totalValue += p.value * fraction;
            cout << p.name << " " << fraction << "\n";
            break;
        }
    }

    cout << "TOTAL " << totalValue << endl;

    return 0;
}
