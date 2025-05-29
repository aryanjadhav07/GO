#include<bits/stdc++.h>

using namespace std;

int main(){
    string str;
    char cls;
    int lastdigit;

    cout << "Enter the IP address : ";
    getline(cin, str);
    vector<string> temp;
    string current;

    for(char ch : str){
        if(ch == '.'){
            if(!current.empty()){
                temp.push_back(current);
                current.clear();
            }
        }
        else{
            current += ch;
        }
    }

    if(!current.empty()){
        temp.push_back(current);
    }

    if(temp.size() != 4){
        cout << "Invalid IP address ." << endl;
        return 0;
    }

    for(int i = 0; i < temp.size(); i++){
        if(stoi(temp[i]) >= 0 && stoi(temp[i]) <= 255 ){
            string tm = temp[i];
            if(tm.length() > 1 && tm[0] == '0'){
                cout << "Invalid IP address." << endl;
                return 0;
            }
        }
        else{
            cout << "Invalid IP address." << endl;
            return 0;
        }
    }

    int foctet = stoi(temp[0]);

    if(foctet >= 0 && foctet <= 127){
        cls = 'A';
    }
    else if(foctet >= 128 && foctet <= 191){
        cls = 'B';
    }
    else if(foctet >= 192 && foctet <= 223){
        cls = 'C';
    }
    else if(foctet >= 224 && foctet <= 239){
        cls = 'D';
    }
    else if(foctet >= 240 && foctet <= 250){
        cls = 'E';
    }


    cout << "Enter the CIDR : ";
    int cidr;
    cin >> cidr;

    int acidr = 8, bcidr = 16, ccidr = 24;
    int bbit, rbit;

    if(cls == 'A'){
        bbit = cidr - acidr;
        rbit = 8 - bbit;
    }
    else if(cls == 'B'){
        bbit = cidr - bcidr;
        rbit = 8 - bbit;
    }
    else if(cls == 'C'){
        bbit = cidr - ccidr;
        rbit = 8 - bbit;
    }
    else{
        cout << "CIDR calculation is not applicable for the class : " << cls << endl;
        return 0;
    }

    int networks = pow(2, bbit);
    int ips = pow(2, rbit);
    int host = pow(2, rbit) - 2;

    cout << "Class : " << cls << endl;

    if(cls == 'A'){
        cout << "Default Subnet mask : 255.0.0.0" << endl;
    }
    else if(cls == 'B'){
        cout << "Default Subnet mask : 255.255.0.0" << endl;
    }
    else if(cls == 'C'){
        cout << "Default Subnet mask : 255.255.255.0" << endl;
    }
    else {
        cout << "Default Subnet mask : Not applicable for the class : " << cls << endl;
    }

    cout << "Networks : " << networks << endl;
    cout << "IP Addresses : " << ips << endl;
    cout << "Hosts : " << host << endl;

    int cidrld = 0;
    for(int i = 7 ; i >= 8 - bbit; i--){
        cidrld += pow(2, i);
    }

    if(cls == 'A'){
        cout << "Subnet mask : 255." << cidrld << ".0.0 " << endl;
    }
    else if(cls == 'B'){
        cout << "Subnet mask : 255.255." << cidrld << ".0" << endl;
    }
    else if(cls == 'C'){
        cout << "Subnet mask : 255.255.255." << cidrld << endl;
    }
    else {       
        cout << "Subnet mask : not applicable for this class : " << cls << endl;
        return 0;
    }


    int lastOctet = stoi(temp[3]);
    int firstIp = lastOctet & cidrld;
    int lastIp = lastOctet | (255-cidrld);

    cout << "First IP Address : " << temp[0] << "." << temp[1] <<"." << temp[2] << "." << firstIp + 1 << endl;
    cout << "Last IP Address : " << temp[0] << "." << temp[1] <<"." << temp[2] << "." << lastIp - 1 << endl;
    
    return 0;
}