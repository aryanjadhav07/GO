#include <iostream>
#include <unordered_map>
using namespace std;

void display(unordered_map<string, int> &fruits){
    for(auto pair : fruits){
        cout << pair.first << " : " << pair.second << endl;
    }
}
int main() {

unordered_map<string, int> fruits;

fruits["apple"] = 10;
fruits["banana"] = 15;
fruits["orange"] = 20;

display(fruits);

if(fruits.find("banana") != fruits.end()){
    cout << "banana is present in the map with value : " << fruits["banana"] << endl;
}
else{
    cout << "banana is not present in the map" << endl;
}

cout << endl;

fruits.erase("apple");
cout << "Size of the map after erasing apple : " << fruits.size() << endl;

cout << "After erasing apple: " << endl;
for (auto pair : fruits){
    cout << pair.first << " : " << pair.second << endl;
}

    return 0;
}