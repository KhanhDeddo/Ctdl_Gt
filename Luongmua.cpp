#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;
void NhapDuLieu(vector<vector<float>>& Lst);
void ThongKe(const vector<vector<float>>& Lst);
void checkInput(short int &nam, short int &thang, vector<vector<float>>& Lst);
void LuuDuLieuVaoFile(const vector<vector<float>>& Lst);
 
int main() {
    vector<vector<float>> Lst(3000, vector<float>(12, -1));
    short int select;
    while(true){
        system("clear");
        cout<<"------Menu lua chon------"<<endl;
        cout<<"1. Nhap du lieu."<<endl;
        cout<<"2. Thong ke."<<endl;
        cout<<"3. Thoat."<<endl;
        cout<<"Nhap lua chon: ";cin>>select;
        if(select==1) NhapDuLieu(Lst);
        else if(select==2)ThongKe(Lst);
        else if(select==3){
            system("clear");
            LuuDuLieuVaoFile(Lst);
            cout << "---Cam on da dung chuong trinh.---" << endl;
            break;
        } else{}
    }
    return 0;
}
 
void NhapDuLieu(vector<vector<float>>& Lst){
    short int select=1;
    short int nam, thang;
    float luongMua;
    checkInput(nam,thang,Lst);
    while(select!=0){
        cout<< "Nhap vao luong mua: ";cin>>luongMua;
        Lst[nam][thang-1] = luongMua;
        cout<<"Nhap 1 de nhap thang tiep hoac 0 de ve man hinh chinh: ";cin>>select;
        if(select==0 or thang==12) break;
        system("clear");
        thang++;
        cout<< "---Nhap du lieu---"<< endl;
        cout<<"Nam: "<<nam<<endl;
        cout<<"Thang: "<<thang<<endl;
    }
}
 
void ThongKe(const vector<vector<float>>& Lst) {
    short int select=1;
    while(select!=0){
        short int nam,count=0;
        float sum=0;
        system("clear");
        cout<<"Nhap vao nam: ";cin>>nam;
        for(short int thang=0; thang<12; thang++){
            if(Lst[nam][thang]!=-1){
                sum+=Lst[nam][thang];
                count+=1;
            }
            else{break;}
        }
        if(count==0) cout<<"Nam "<<nam<<" chua co du lieu."<<endl;
        else{
            system("clear");
            cout <<"---Thong Ke---" << endl;
            cout<<"Tong luong mua nam "<<nam<<": "<<sum<<endl;
            cout<<"Trung binh luong mua cac thang: "<<sum/count<<endl;
            cout<<"Du lieu da duoc cap nhat den het thang "<<count<<"."<<"\n\n";
        }
        cout<<"Nhan 1 de tiep tuc hoac 0 de qua lai man hinh chinh. ";cin>>select;
        if(select==0) break;
    }
}
void checkInput(short int &nam, short int &thang, vector<vector<float>>& Lst){
    system("clear");
    while(true){
        cout<< "---Nhap du lieu---"<< endl;
        cout<< "Nhap vao nam: ";cin>>nam;
        if(nam<0 or nam>3000){
            system("clear");
            cout<<"Nam "<<nam<<" khong hop le, yeu cau nhap lai."<<endl;
        }
        else{
            while(true){
                cout<< "Nhap vao thang: ";cin>>thang;
                if(thang<1 or thang>12){
                    system("clear");
                    cout<<"Thang "<<thang<<" khong hop le, yeu cau nhap lai."<<endl;
                    cout<<"Nam: "<<nam<<endl;
                }
                else if(thang>1 && Lst[nam][thang-2]==-1){
                    system("clear");
                    cout<<"Thang truoc chua co du lieu vui long nhap truoc."<<endl;
                    cout<<"Nam: "<<nam<<endl;
                }
                else{break;}
            }
            if(Lst[nam][thang-1]!=-1){
                char slt;
                cout<<"Luong mua thang "<<thang<<" la: "<<Lst[nam][thang-1]<<endl;
                cout<<"nhan y de cap nhat hoac n de quay lai: ";cin>>slt;
                if(slt=='y') break;
                else{system("clear");}
            }
            else{break;}
        }
    }
}
 
void LuuDuLieuVaoFile(const vector<vector<float>>& Lst) {
    ofstream outFile("data.txt"); 
    if (outFile.is_open()) { 
        for (int i = 0; i < 3000; ++i) {
            if(Lst[i][0]!=-1){
                    outFile <<i<<"\n"; 
            }
            for (int j = 0; j < 12; ++j) {
                if(Lst[i][j]!=-1){
                    outFile <<j+1<<"-"<<Lst[i][j] <<" "; 
                }
            }
            outFile << endl;
        }
        outFile.close(); 
    } else {
        cout << "Khong mo duoc file!" << endl;
    }
}
 
