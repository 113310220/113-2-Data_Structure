#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Product {
private:
    string name;
    int expiry;
    int popularity;

public:
    Product(string n, int e, int p) {
        name = n;
        expiry = e;
        popularity = p;
    }

    string getName() const { return name; }
    int getExpiry() const { return expiry; }
    int getPopularity() const { return popularity; }

    static bool compare(const Product& a, const Product& b) {
        if (a.getExpiry() != b.getExpiry())
            return a.getExpiry() < b.getExpiry();  // 有效期限短的優先
        return a.getPopularity() > b.getPopularity();  // 熱銷程度高的優先
    }
};

void processFile(const string& inputFileName) {
    ifstream inFile(inputFileName.c_str());

    if (!inFile) {
        cerr << "無法開啟輸入檔案: " << inputFileName << endl;
        return;
    }

    int N;
    inFile >> N;
    inFile.ignore(); // 忽略換行

    vector<Product> products;

    for (int i = 0; i < N; ++i) {
        string line;
        getline(inFile, line);
        istringstream iss(line);

        string word, name = "";
        int expiry = 0, popularity = 0;

        while (iss >> word) {
            if (isdigit(word[0])) {
                expiry = stoi(word);
                break;
            }
            if (!name.empty()) name += " ";
            name += word;
        }

        iss >> popularity;
        products.push_back(Product(name, expiry, popularity));
    }

    sort(products.begin(), products.end(), Product::compare);


    cout << "商品順序:\n";
    for (size_t i = 0; i < products.size(); ++i) {
        cout << products[i].getName() << "\n";
    }


    inFile.close();
}

int main() {
    processFile("input3.txt");
    return 0;
}
