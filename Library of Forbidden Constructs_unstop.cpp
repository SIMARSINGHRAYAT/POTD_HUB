/*In the Library of Forbidden Constructs, there are N magical scrolls. Some scrolls contain knowledge so dangerous that they can only be read after reading one or more prerequisite scrolls.

Each scroll has zero or more dependencies. A scroll cannot be read unless all of its prerequisites have already been read.

Your task is to determine whether it is possible to read all the scrolls without violating any prerequisite conditions. If possible, print one valid reading order that satisfies all dependencies. If it is impossible (due to cyclic dependencies), print "IMPOSSIBLE".

Among all possible reading orders, you must output the lexicographically smallest valid order. This means scrolls with smaller IDs should appear earlier where possible.

Input Format
The first line contains two integers N and M — the number of scrolls and the number of dependency rules.

The next M lines each contain two integers A and B denoting that scroll A must be read before scroll B.

Output Format
If a valid reading order exists, print N space-separated integers representing the lexicographically smallest order of reading the scrolls.

If no valid order exists due to a cycle, print a single line: IMPOSSIBLE

Constraints
1 ≤ N ≤ 10^5

0 ≤ M ≤ 2 × 10^5

1 ≤ A, B ≤ N

Sample Testcase 0
Testcase Input
4 4
1 2
2 3
3 4
4 2
Testcase Output
IMPOSSIBLE
Explanation
Scroll 2 depends on 1, scroll 3 on 2, scroll 4 on 3, and scroll 2 again on 4, forming a cycle.
 Hence, no valid reading order exists.

 Sample Testcase 1
 Testcase Input
 6 6
 1 3
 2 3
 3 4
 4 5
 4 6
 2 5
 Testcase Output
 1 2 3 4 5 6
 Explanation
 Scroll 3 depends on both 1 and 2, so it must appear after them.
  Scroll 4 depends on 3, so it must come later.
   Scrolls 5 and 6 depend on 4 and 2, respectively.
    The lexicographically smallest valid order satisfying all constraints is:
     1 → 2 → 3 → 4 → 5 → 6 */




/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> find_reading_order(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1, 0);

            // Build graph
                for (auto [u, v] : edges) {
                        adj[u].push_back(v);
                                indegree[v]++;
                                    }

                                        // Min-heap for lex smallest order
                                            priority_queue<int, vector<int>, greater<int>> pq;
                                                for (int i = 1; i <= n; ++i) {
                                                        if (indegree[i] == 0) pq.push(i);
                                                            }

                                                                vector<int> result;
                                                                    while (!pq.empty()) {
                                                                            int u = pq.top(); pq.pop();
                                                                                    result.push_back(u);
                                                                                            for (int v : adj[u]) {
                                                                                                        if (--indegree[v] == 0) pq.push(v);
                                                                                                                }
                                                                                                                    }

                                                                                                                        if ((int)result.size() != n) return {}; // Cycle detected
                                                                                                                            return result;
                                                                                                                            }

                                                                                                                            int main() {
                                                                                                                                int n, m;
                                                                                                                                    cin >> n >> m;
                                                                                                                                        vector<pair<int, int>> edges(m);
                                                                                                                                            for (int i = 0; i < m; ++i) {
                                                                                                                                                    cin >> edges[i].first >> edges[i].second;
                                                                                                                                                        }

                                                                                                                                                            vector<int> order = find_reading_order(n, edges);
                                                                                                                                                                if (order.empty()) {
                                                                                                                                                                        cout << "IMPOSSIBLE\n";
                                                                                                                                                                            } else {
                                                                                                                                                                                    for (int x : order) cout << x << " ";
                                                                                                                                                                                            cout << "\n";
                                                                                                                                                                                                }
                                                                                                                                                                                                    return 0;
                                                                                                                                                                                                    } */
                                                                                                           





#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> find_reading_order(int n, const std::vector<std::pair<int, int>>& edges) {
    std::vector<std::vector<int>> adj(n + 1);
        std::vector<int> indegree(n + 1, 0);

            // Build the graph
                for (size_t i = 0; i < edges.size(); ++i) {
                        int u = edges[i].first;
                                int v = edges[i].second;
                                        adj[u].push_back(v);
                                                indegree[v]++;
                                                    }

                                                        // Min-heap to ensure lexicographically smallest order
                                                            std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
                                                                for (int i = 1; i <= n; ++i) {
                                                                        if (indegree[i] == 0) {
                                                                                    pq.push(i);
                                                                                            }
                                                                                                }

                                                                                                    std::vector<int> result;
                                                                                                        while (!pq.empty()) {
                                                                                                                int u = pq.top();
                                                                                                                        pq.pop();
                                                                                                                                result.push_back(u);
                                                                                                                                        for (size_t i = 0; i < adj[u].size(); ++i) {
                                                                                                                                                    int v = adj[u][i];
                                                                                                                                                                indegree[v]--;
                                                                                                                                                                            if (indegree[v] == 0) {
                                                                                                                                                                                            pq.push(v);
                                                                                                                                                                                                        }
                                                                                                                                                                                                                }
                                                                                                                                                                                                                    }

                                                                                                                                                                                                                        if ((int)result.size() != n) {
                                                                                                                                                                                                                                return std::vector<int>(); // Cycle detected
                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                        return result;
                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                        int main() {
                                                                                                                                                                                                                                            int n, m;
                                                                                                                                                                                                                                                std::cin >> n >> m;
                                                                                                                                                                                                                                                    std::vector<std::pair<int, int>> edges(m);
                                                                                                                                                                                                                                                        for (int i = 0; i < m; ++i) {
                                                                                                                                                                                                                                                                std::cin >> edges[i].first >> edges[i].second;
                                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                                        std::vector<int> result = find_reading_order(n, edges);
                                                                                                                                                                                                                                                                            if (result.empty()) {
                                                                                                                                                                                                                                                                                    std::cout << "IMPOSSIBLE\n";
                                                                                                                                                                                                                                                                                        } else {
                                                                                                                                                                                                                                                                                                for (size_t i = 0; i < result.size(); ++i) {
                                                                                                                                                                                                                                                                                                            std::cout << result[i] << " ";
                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                            std::cout << "\n";
                                                                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                                                                    return 0;
                                                                                                                                                                                                                                                                                                                                    }
