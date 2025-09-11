#include <iostream>
#include <vector>
using namespace std;

bool canWaterAllPlants(const vector<int>& W, int K, int R) {
    int jets_used = 1;
    int current_sum = 0;
    for(int water : W) {
        if(water > R) return false; // can't water this plant at all
        if(current_sum + water > R) {
            jets_used++;
            current_sum = 0;
        }
        current_sum += water;
    }
    return jets_used <= K;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> W(N);
    for(int i = 0; i < N; i++) cin >> W[i];
    int R;
    cin >> R;
    cout << (canWaterAllPlants(W, K, R) ? "YES" : "NO") << endl;
    return 0;
}
