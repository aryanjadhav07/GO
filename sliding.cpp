#include<bits/stdc++.h>

using namespace std;

void goBack(int totalframes, int windowsize){

    cout << "Go back n protocol simulation" << endl;
    int base = 0;
    while(base < totalframes ){

    cout << "Window : ";
    for(int i = base ; i < min(base + windowsize, totalframes); i++){
        cout << "[Frame " << i << "]";
    }

    cout << endl;

    int lost;
    cout << "Enter the lost frame or -1 to acknowledge all frames : ";
    cin >> lost;

    if(lost == -1){
        cout << "All frames acknowledged . " << endl;
        base += windowsize;
    }
    else{
        cout << "Frame " << lost << " is lost . Resending from frame  " << lost << endl;
        base = lost;
    }

    }

}


    void selective(int totalframes, int windowsize){
        cout << "Selective repeate protocol. " << endl;
        int base = 0;
        vector<bool> acked(totalframes, false);
        
        while(base < totalframes){
        cout << "window: ";
        for(int i = base; i < min(base + windowsize, totalframes); i++){
            cout << "[Frame " << i << (acked[i] ? "*" : "") << "]";
        }

        cout << endl;

        int lostframes;

        cout << "Enter the lost frame or -1 to acknowledge all frames : ";
        cin >> lostframes;

        if(lostframes == -1){
            for(int i = base ; i < min(base + windowsize, totalframes); i++){
                acked[i] = true;
            }
            while(base < totalframes && acked[base]){
                base++;
            }

            cout << "All frames are acknowledged. " << endl;
        }
        else if(lostframes >= base && lostframes < (base + windowsize)){
            cout << "Frame " << lostframes << " is lost. Sending only frame " << lostframes << endl;
            acked[lostframes] = false;

            for(int i = base; i < min(base + windowsize, totalframes); i++){
                if(i != lostframes){
                    acked[i] = true;
                }
            }
            while(base < totalframes && acked[base]){
                base++;
            }
        }
        else{
            cout << "Invalid frame selection." << endl;
        }




        }

    }

int main(){
    
    goBack(10, 3);
    selective(10,3);


    return 0;
}