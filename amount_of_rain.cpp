#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<vector<float>> Lst(3000,vector<float>(12,-1));

void ReadData(){
    short int year, sumYear=0;
    ifstream readFile("data.txt");
    if (!readFile.is_open()) return;
    readFile>>sumYear;
    for(int i = 0; i < sumYear; i++){
        readFile>>year;
        for(int m = 0; m < 12; m++){
            readFile>>Lst[year][m];
        }
    }
    readFile.close();
}

void WriteData(){
    short int sumYear=0;
    vector<short int> lstYear(3000);
    ofstream writeFile("data.txt");
    for(int y = 0; y < 3000; y++){
        for(int m = 0; m < 12; m++){
            if(Lst[y][m] != -1){
                lstYear[sumYear]=y;
                sumYear++;
                break;
            }
        }
    }
    writeFile<<sumYear<<endl;
    for(int i = 0; i < sumYear; i++){
        writeFile<<lstYear[i]<<" ";
        for(int m = 0; m < 12; m++){
            writeFile<<Lst[lstYear[i]][m]<<" ";
        }
        writeFile<<endl;
    }
    writeFile.close();
}

void InputData(){
    system("cls");
    cout<<"Nhap du lieu luong mua cho thang trong nam.\n";
    short int year, month;
    string slt;
    cout<<"Nhap vao nam: ";cin>>year;
    while(year < 0 or year >= 3000){
        system("cls");
        cout<<"Nhap du lieu luong mua cho thang trong nam.\n";
        cout<<"Nam khong hop le. Vui long nhap lai!"<<endl;
        cout<<"Nhap vao nam: ";cin>>year;
    }
    cout<<"Nhap vao thang: ";cin>>month;
    while(month < 1 or month > 12){
        system("cls");
        cout<<"Nhap du lieu luong mua cho thang trong nam.\n";
        cout<<"Nhap vao nam: "<<year<<endl;
        cout<<"Thang khong hop le. Vui long nhap lai!"<<endl;
        cout<<"Nhap vao thang: ";cin>>month;
    }
    if(Lst[year][month-1] != -1){
        cout<<"Luong mua thang "<<month<<" la: "<<Lst[year][month-1]<<". Ban muon update khong?\n";
        cout<<"(co-c hoac khong-k): ";cin>>slt;
        if(slt == "k") return;
    }
    cout<<"Nhap vao luong mua: ";cin>>Lst[year][month-1];
}

void OutputData(){
    system("cls");
    cout<<"-----Thong ke luong mua-----"<<endl;
    short int year, sumRain = 0, count = 0;
    string str = "Danh sach cac thang chua co du lieu: ";
    cout<<"Nhap vao nam: ";cin>>year;
    while(year < 0 or year >= 3000){
        system("cls");
        cout<<"-----Thong ke luong mua-----"<<endl;
        cout<<"Nam khong hop le. Vui long nhap lai!"<<endl;
        cout<<"Nhap vao nam: ";cin>>year;
    }
    for(int m = 0; m < 12; m++){
        if(Lst[year][m] != -1){
            count++;
            sumRain+= Lst[year][m];
        }else str+= to_string(m+1) + " "; 
    }
    if(count != 0){
        cout<<"Tong luong mua: "<<sumRain<<endl;
        cout<<"Trung binh luong mua: "<<sumRain/count<<endl;
        if(count < 12) cout<<str<<endl;
    }else cout<<"Nam "<<year<<" chua co du lieu ve luong mua."<<endl;
}

int main(){
    short int select;
    ReadData();
    while (true){
        system("cls");
        cout<<"-----Chuong trinh quan ly luong mua-----"<<endl;
        cout<<"1. Nhap du lieu."<<endl;
        cout<<"2. Thong ke."<<endl;
        cout<<"3. Thoat."<<endl;
        cout<<"Nhap lua chon: ";cin>>select;
        if(select == 1){
            InputData();
        }
        else if(select == 2){
            int slt;
            do{
                OutputData();
                cout<<"Tiep tuc thong ke nam khac chon 1 hoac 0 de thoat: ";cin>>slt;
            }while(slt);
        }
        else if(select == 3){
            system("cls");
            cout<<"Cam on da su dung chuong trinh."<<endl;
            break;
        }else;
    }
    WriteData();
    return 0;
}
