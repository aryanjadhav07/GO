#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string str;
    char clss;
    int lastdigit;

    cout << "Enter the IP Address: ";
    getline(cin, str);
    vector<string> temp;
    string current;

    // Splitting the IP string by '.'
    for (char ch : str) {
        if (ch == '.') {
            if (!current.empty()) {
                temp.push_back(current);
                current.clear();
            }
        } else {
            current += ch;
        }
    }

    if (!current.empty()) {
        temp.push_back(current);
    }

    // IP Address validation
    if (temp.size() != 4) {
        cout << "Invalid IP Address" << endl;
        return 0;
    }

    for (int i = 0; i < temp.size(); i++) {
        if (stoi(temp[i]) >= 0 && stoi(temp[i]) <= 255) {
            string tm = temp[i];
            if (tm.length() > 1 && tm[0] == '0') {
                cout << "Invalid IP Address" << endl;
                return 0;
            }
        } else {
            cout << "Invalid IP Address" << endl;
            return 0;
        }
    }

    // Determine IP class
    int fOctet = stoi(temp[0]);

    if (fOctet >= 1 && fOctet <= 127) {
        clss = 'A';
    } else if (fOctet >= 128 && fOctet <= 191) {
        clss = 'B';
    } else if (fOctet >= 192 && fOctet <= 223) {
        clss = 'C';
    } else if (fOctet >= 224 && fOctet <= 239) {
        clss = 'D';
    } else {
        clss = 'E';
    }


    cout << "Enter the CIDR value: ";
    int cidr;
    cin >> cidr;

    int acidr = 8, bcidr = 16, ccidr = 24;
    int bbit = 0, rbit = 0;

    // CIDR calculation based on class 
    if (clss == 'A') {
        bbit = cidr - acidr;
        rbit = 8 - bbit;
    } else if (clss == 'B') {
        bbit = cidr - bcidr;
        rbit = 8 - bbit;
    } else if (clss == 'C') {
        bbit = cidr - ccidr;
        rbit = 8 - bbit;
    } else {
        cout << "CIDR calculation not applicable for Class " << clss << endl;
        return 0;
    }

    int networks = pow(2, bbit);
    int ips = pow(2, rbit);
    int hosts = ips - 2;

    cout << "Class: " << clss << endl;
    
    if (clss == 'A') {
        cout << "Default Subnet mask : 255.0.0.0" << endl;
    } else if (clss == 'B') {
        cout << "Default Subnet mask : 255.255.0.0" << endl;
    } else if (clss == 'C') {
        cout << "Default Subnet mask : 255.255.255.0" << endl;
    } else {
        cout << "Default Subnet mask : Not applicable for Class " << clss << endl;
    }

    cout << "Number of Networks: " << networks << endl;
    cout << "Number of IP Addresses: " << ips << endl;
    cout << "Number of Host Addresses: " << hosts << endl;
    

    // Subnet mask last octet calculation
    int cidrld = 0;
    for (int i = 7; i >= 8 - bbit; i--) {
        cidrld += pow(2, i);
    }

    if (clss == 'A') {
        cout << "Subnet mask : 255." << cidrld << ".0.0" << endl;
    } else if (clss == 'B') {
        cout << "Subnet mask : 255.255." << cidrld << ".0" << endl;
    } else if (clss == 'C') {
        cout << "Subnet mask : 255.255.255." << cidrld << endl;
    } else {
        cout << "Subnet mask : Not applicable for Class " << clss << endl;
    }

    // First and Last IP
    int lastOctet = stoi(temp[3]);

    int firstIP = cidrld & lastOctet;
    int inverseMask = 255 - cidrld;
    int lastIP = lastOctet | inverseMask;

    cout << "First IP Address: " << temp[0] << "." << temp[1] << "." << temp[2] << "." << firstIP << endl;
    cout << "Last IP Address: " << temp[0] << "." << temp[1] << "." << temp[2] << "." << lastIP << endl;

    return 0;
}
