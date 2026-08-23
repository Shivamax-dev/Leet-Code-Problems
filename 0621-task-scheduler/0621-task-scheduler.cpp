class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        unordered_map<char, int> freq;
        unordered_map<char, int> free; // Har task kab free/ready hoga uska time

        for (int i = 0; i < m; i++) {
            freq[tasks[i]]++;
            free[tasks[i]] = 1; // Shuru me saare tasks time = 1 pe ready hain
        }

        // Max-heap: highest frequency task ko pehle process karenge
        // Pair me {frequency, character}
        priority_queue<pair<int, char>> pq;
        for (auto& item : freq) {
            pq.push({item.second, item.first});
        }

        int seat = 1; // Current CPU cycle / time

        while (!pq.empty()) {
            vector<pair<int, char>> pulled;
            bool executed = false;
            int next_available_time = INT_MAX;

            while (!pq.empty()) {
                pair<int, char> p = pq.top();
                pq.pop();

                int fr = p.first;
                char child = p.second;

                // Check karo kya ye task current time (seat) pe run ho sakta hai
                if (free[child] <= seat) {
                    free[child] = seat + n + 1; // Task run ho gaya, naya cooldown set karo
                    if (fr > 1) {
                        pq.push({fr - 1, child});
                    }
                    executed = true;
                    break;
                } else {
                    // Task cooldown me hai
                    next_available_time = min(next_available_time, free[child]);
                    pulled.push_back(p);
                }
            }

            // Pulled tasks ko wapas heap me daalo
            for (int i = 0; i < pulled.size(); i++) {
                pq.push(pulled[i]);
            }

            if (executed) {
                seat++; // Task execute hua toh time 1 step aage badhao
            } else if (!pq.empty()) {
                seat = next_available_time; // Koi bhi task ready nahi tha, seedha next cooldown tak jump karo
            }
        }

        return seat - 1; // Total time cycles spent
    }
};