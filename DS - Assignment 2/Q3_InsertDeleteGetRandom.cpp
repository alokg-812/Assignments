// https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/1342588352/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> valToIndex;

public:
    RandomizedSet() {
        srand(time(nullptr)); // Initialize random seed
    }

    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end()) {
            return false; // Element already exists
        }
        nums.push_back(val);
        valToIndex[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end()) {
            return false; // Element does not exist
        }
        int lastElement = nums.back();
        int idx = valToIndex[val];
        nums[idx] = lastElement;
        valToIndex[lastElement] = idx;
        nums.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

int main() {
    RandomizedSet* randomizedSet = new RandomizedSet();

    cout << (randomizedSet->insert(1) ? "Inserted 1" : "Failed to insert 1") << endl; // Inserts 1, returns true
    cout << (randomizedSet->remove(2) ? "Removed 2" : "Failed to remove 2") << endl; // Returns false, 2 does not exist in the set
    cout << (randomizedSet->insert(2) ? "Inserted 2" : "Failed to insert 2") << endl; // Inserts 2, returns true
    cout << "Random element: " << randomizedSet->getRandom() << endl; // Returns either 1 or 2 randomly
    cout << (randomizedSet->remove(1) ? "Removed 1" : "Failed to remove 1") << endl; // Removes 1, returns true
    cout << (randomizedSet->insert(2) ? "Inserted 2" : "Failed to insert 2") << endl; // 2 was already in the set, returns false
    cout << "Random element: " << randomizedSet->getRandom() << endl; // Returns 2

    delete randomizedSet;
    return 0;
}
