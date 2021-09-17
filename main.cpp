#include <iostream>
#include <memory>
#include <vector>
#include <conio.h>

using namespace std;

class Test {

private:

    int data;

public:

    Test()
        : data{0} {

        cout << "\tTest Constructor (" << data << ")" << endl;

    }

    Test(int data)
        : data{data} {

        cout << "\tTest Constructor (" << data << ")" << endl;

    }

    int getData() const {

        return data;

    }

    ~Test() {

        cout << "Test Destructor (" << data << ")" << endl;

    }

};

// Function prototypes
auto make();
void fill(vector<shared_ptr<Test>> &vec , int num);
void display(const vector<shared_ptr<Test>> &vec);

auto make(){

    return make_unique<vector<shared_ptr<Test>>>();

}

void fill(vector<shared_ptr<Test>> &vec , int num){

    int temp;
    for (int i = 1; i <= num; ++i) {

        cout << "Enter data point [" << i << "]:";
        cin >> temp;
//        shared_ptr<Test> ptr = make_shared<Test>(temp);
//        vec.push_back(ptr);
        vec.push_back(make_shared<Test>(temp));

    }

}

void display(const vector<shared_ptr<Test>> &vec){

    cout << "\nDisplay vector" << endl;
    cout << "================" << endl;
    for (const auto &ptr : vec) {

        cout << ptr->getData() << endl;

    }
    cout << "================" << endl;

}

int main() {

    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    cout << "How many?";
    int num;
    cin >> num;
    fill(*vec_ptr , num);
    display(*vec_ptr);

    getch();
    return 0;
}
