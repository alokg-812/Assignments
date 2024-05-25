#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

class D_Array {
private:
    vector<int> array;
    int resize_factor;

public:
    D_Array(int resize_factor = 2) : resize_factor(resize_factor) {}

    void insert(int index, int element) {
        if (index < 0 || index > array.size()) {
            throw out_of_range("Index out of bound");
        }
        array.insert(array.begin() + index, element);
    }

    void delete_at_index(int index) {
        if (index < 0 || index >= array.size()) {
            throw out_of_range("Index out of bound");
        }
        array.erase(array.begin() + index);
    }

    int get_size() {
        return array.size();
    }

    bool is_empty() {
        return array.empty();
    }

    void rotate(int k) {
        if (array.size() == 0 || k == 0) {
            return;
        }
        k = k % array.size();
        std::rotate(array.rbegin(), array.rbegin() + k, array.rend());
    }

    void reverse() {
        std::reverse(array.begin(), array.end());
    }

    void append(int ele) {
        array.push_back(ele);
    }

    void prepend(int ele) {
        array.insert(array.begin(), ele);
    }

    void merge(D_Array& other_array) {
        array.insert(array.end(), other_array.array.begin(), other_array.array.end());
    }

    void interleave(D_Array& other_array) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < array.size() || j < other_array.array.size()) {
            if (i < array.size()) {
                res.push_back(array[i]);
                ++i;
            }
            if (j < other_array.array.size()) {
                res.push_back(other_array.array[j]);
                ++j;
            }
        }
        array = res;
    }

    int find_middle() {
        if (array.size() == 0) {
            return -1;
        }
        return array[array.size() / 2];
    }

    int index_of(int ele) {
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] == ele) {
                return i;
            }
        }
        return -1;
    }

    D_Array split(int index) {
        if (index < 0 || index > array.size()) {
            throw out_of_range("Index out of bound");
        }
        D_Array new_array(resize_factor);
        new_array.array = vector<int>(array.begin() + index, array.end());
        array.erase(array.begin() + index, array.end());
        return new_array;
    }

    void resize(int new_resize_factor) {
        resize_factor = new_resize_factor;
    }

    void __resize_up() {
        int new_capacity = int(array.size() * resize_factor);
        array.reserve(new_capacity);
    }

    void __resize_down() {
        int new_capacity = max(1, int(array.size() / resize_factor));
        array.resize(new_capacity);
    }

    void print_array() {
        for (int ele : array) {
            cout << ele << " ";
        }
        cout << endl;
    }
};

int main() {
    D_Array arr;
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.prepend(0);
    arr.insert(2, 5);
    cout << "Array after insertions: ";
    arr.print_array();

    arr.rotate(2);
    cout << "Array after rotation: ";
    arr.print_array();

    arr.reverse();
    cout << "Array after reversal: ";
    arr.print_array();

    D_Array other_arr;
    other_arr.append(6);
    other_arr.append(7);

    arr.merge(other_arr);
    cout << "Array after merging: ";
    arr.print_array();

    arr.interleave(other_arr);
    cout << "Array after interleaving: ";
    arr.print_array();

    cout << "Middle element: " << arr.find_middle() << endl;
    cout << "Index of 5: " << arr.index_of(5) << endl;

    D_Array new_arr = arr.split(3);
    cout << "Original array after split: ";
    arr.print_array();
    cout << "New array after split: ";
    new_arr.print_array();

    return 0;
}
