#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

struct Student {
    int roll;
    int dept;
    int loyalty;
};

// Function to calculate maximum number of disjoint "Integrity Chains"
int calculateIntegrityChains(std::vector<Student>& students, int N, int D) {
    // Sort students by loyalty (then department, then roll)
    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        if (a.loyalty != b.loyalty) return a.loyalty < b.loyalty;
        if (a.dept != b.dept) return a.dept < b.dept;
        return a.roll < b.roll;
    });

    std::vector<bool> used(N, false);
    int chains = 0;

    for (int i = 0; i < N; i++) {
        // Start only from a CS student that is unused
        if (!used[i] && students[i].dept == 1) {
            std::set<int> deps;
            deps.insert(students[i].dept);
            used[i] = true;
            int lastLoyalty = students[i].loyalty;

            // Extend the chain
            for (int j = i + 1; j < N; j++) {
                if (!used[j] && students[j].loyalty > lastLoyalty && deps.find(students[j].dept) == deps.end()) {
                    deps.insert(students[j].dept);
                    used[j] = true;
                    lastLoyalty = students[j].loyalty;
                }
            }

            // Chain must have at least 2 members to count
            if (deps.size() >= 2) {
                chains++;
            }
        }
    }
    return chains;
}

int main() {
    int N, D;
    std::cin >> N >> D;

    std::vector<Student> students(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> students[i].roll >> students[i].dept >> students[i].loyalty;
    }

    int result = calculateIntegrityChains(students, N, D);
    std::cout << result << std::endl;

    return 0;
}
