#include<iostream>
#include<string>
#include<windows.h>
#include<conio.h>
using namespace std;
struct emp{
string name,id,address;
int contact,salary;
};
emp e[100];
int total=0;
void empData(){
int choice;
cout<<"How many Employees you want to enter?"<<endl;
cin>>choice;
for(int i=total;i<total+choice;i++){
    cout<<"Enter data "<<i+1<<endl;
    cout<<"EMPLOYEE NAME:"<<endl;
    cin>>e[i].name;
    cout<<"ID :"<<endl;
    cin>>e[i].id;
    cout<<"EMPLOYEE ADDRESS :"<<endl;
    cin>>e[i].address;
    cout<<"EMPLOYEE CONTACT INFO :"<<endl;
    cin>>e[i].contact;
    cout<<"SALARY IS :"<<endl;
    cin>>e[i].salary;
}
total=total+choice;
}
void show(){
if(total !=0){
    for(int i=0; i<total;i++){
        cout<<"DATA OF EMPLOYEE :"<<i+1<<endl;
        cout<<"Employee Name :"<<e[i].name<<endl;
        cout<<"ID :"<<e[i].id<<endl;
        cout<<"Address is :"<<e[i].address<<endl;
          cout<<"Contact Info is :"<<e[i].contact<<endl;
        cout<<"Salary is :"<<e[i].salary<<endl;
      
    }

}  
else{
    cout<<"RECORD IS EMPTY"<<endl;
}
}
void search(){
if(total !=0){
    string id;
cout<<"Enter ID of search :"<<endl;
cin>>id;
bool found=false;
for(int i=0;i<total ;i++){
if(id==e[i].id){
     cout<<"DATA OF EMPLOYEE :"<<i+1<<endl;
        cout<<"Employee Name :"<<e[i].name<<endl;
        cout<<"ID :"<<e[i].id<<endl;
        cout<<"Address is :"<<e[i].address<<endl;
          cout<<"Contact Info is :"<<e[i].contact<<endl;
        cout<<"Salary is :"<<e[i].salary<<endl;
        found=true;
        break;
}
if(!found){
    cout<<"no record such found !!!!!:"<<endl;
}
}
}
else{
    cout<<"RECORD IS EMPTY"<<endl;
}
}
void update(){
if(total !=0){
    string id;
    bool found=false;
cout<<"Enter ID to update :"<<endl;
cin>>id;
for(int i=0;i<total ;i++){
if(id==e[i].id){
    found=true;
    cout<<"Previous Data"<<endl;
     cout<<"DATA OF EMPLOYEE :"<<i+1<<endl;
        cout<<"Employee Name :"<<e[i].name<<endl;
        cout<<"ID :"<<e[i].id<<endl;
        cout<<"Address is :"<<e[i].address<<endl;
        cout<<"Contact Info is :"<<e[i].contact<<endl;
        cout<<"Salary is :"<<e[i].salary<<endl;
        
        cout<<"\nEnter new Data"<<endl;

    cout<<"EMPLOYEE NAME:"<<endl;
    cin>>e[i].name;
    cout<<"ID :"<<endl;
    cin>>e[i].id;
    cout<<"EMPLOYEE ADDRESS :"<<endl;
    cin>>e[i].address;
    cout<<"EMPLOYEE CONTACT INFO :"<<endl;
    cin>>e[i].contact;
    cout<<"SALARY IS :"<<endl;
    cin>>e[i].salary;

        break;
}
if(!found){
    cout<<"no record such found !!!!!:"<<endl;
}
}
} else{
 cout<<"YOUR RECORD IS EMPTY"<<endl;
}
}
void deleteData(){
if(total !=0){
    char user;
cout<<"PRESS 1 TO DELETE FULL RECORD"<<endl;
cout<<"PRESS 2 TO DELETE SPECIFIC "<<endl;
user=getch();
if(user=='1'){
    total=0;
    cout<<"ALL DELETED...."<<endl;
}else if(user=='2') {
 string id;
cout<<"Enter ID to delete :"<<endl;
cin>>id;
for(int i=0;i<total;i++){
    if(id==e[i].id){
        for(int j=i;j<total;j++){

      
        e[j].name=e[j+1].name;
         e[j].id=e[j+1].id;
          e[j].address=e[j+1].address;
           e[j].contact=e[j+1].contact;
            e[j].salary=e[j+1].salary;
            total--;
            cout<<"DELETED"<<endl;
            break;
        }
if(i==total-1){
    cout<<"no record ....."<<endl;
}
    }
}
}


}else{
    cout<<"NOT FOUND..."<<endl;
}


}


int main (){
cout<<"\n\n\t\t  EMPLOYEE MANAGEMENT SYSTEM"<<endl;
cout<<"\n\n\t\t SIGN UP...."<<endl;
string userName;
string password;
string user1;
string pass1;
cout<<"\n\t\t ENTER USERNAME..: ";
cin>>userName;
cout<<"\n\t\t ENTER PASSWORD..: ";
cin>>password;
cout<<"\n\t\t ID IS CREATING PLEASE WAIT";
for(int i=0 ;i<4;i++){
    cout<<".";
    Sleep(1000);
}
cout<<"\n\t\t ID CREATED SUCCESSFULLY"<<endl;
system("CLS");
start:
system("CLS");
cout<<"\n\n\t\t  EMPLOYEE MANAGEMENT SYSTEM"<<endl;
cout<<"\n\n\t\t LOGIN "<<endl;
cout<<"USERNAME : ";
cin>>user1;
cout<<"PASSWORD : ";
cin>>pass1;
if(user1==userName && pass1==password){
system("CLS");
char user;
while(1){
    cout<<"\n\nPRESS 1 TO ENTER DATA.."<<endl;
    cout<<"PRESS 2 TO SHOW DATA.."<<endl;
    cout<<"PRESS 3 TO SEARCH DATA.."<<endl;
    cout<<"PRESS 4 TO UPDATE DATA.."<<endl;
    cout<<"PRESS 5 TO DELETE DATA.."<<endl;
    cout<<"PRESS 6 TO LOGOUT ..."<<endl;
    cout<<"PRESS 7 TO EXIT."<<endl;
    user=getch();
    system("CLS");
    switch(user){
        case '1':
        empData();
        break;
        case '2':
        show();
        break;
        case '3':
        search();
        break;
        case '4':
        update();
        break;
        case '5':
        deleteData();
        break;
        case '6':
        goto start;
        break;
        case '7':
    exit(0);
        default:
        cout<<"\aINVALID INPUT"<<endl;
    }
}
} else if(user1 !=userName){
    cout<<"INCORECT USERNAME"<<endl;
    Sleep(3000);
    goto start;
} else if(pass1 !=password){
    cout<<"INCORECT PASSWORD"<<endl;
    Sleep(3000);
    goto start;
}
    return 0;
}