#include<iostream>
#include<string>
#include<limits>
#include<vector>
using namespace std;
struct item{
  int id;
  string name;
  int price;
  struct item* next;
  item(){
    vector<pair<string,int>>mp(11);
    mp[1]=make_pair("RTX 3080",47000);
    mp[2]=make_pair("RTX 2080ti",9800);
    mp[3]=make_pair("MX 240",42030);
    mp[4]=make_pair("RTX 2080 SUPER",23400);
    mp[5]=make_pair("RX 5600 XT",14000);
    mp[6]=make_pair("GTX 1650",12400);
    mp[7]=make_pair("GTX 1500",11000);
    mp[8]=make_pair("GTX 1500ti",16000);
    mp[9]=make_pair("RADEON RX 570",24000);
    mp[10]=make_pair("RADEON RX 580",22200);
    cout<<"choose from the menu"<<endl;
    cout<<"id of product-> name of product-> price of product"<<endl;
    for(int h=1;h<11;h++){
      cout<<h<<" "<<mp[h].first<<" "<<mp[h].second<<endl;;
    }
    sb:
    cout<<"ENTER THE PRODUCT ID TO ADD TO CART"<<endl;
    cin>>id;
    while(cin.fail()){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout<<"invalid input for item id enter again..."<<endl;
      cin>>id;
    }
    if(id<11&&id>=0){
      name=mp[id].first;
      price=mp[id].second;
    }
    else{
      cout<<"no product with this id is avaliable right now..try again"<<endl;
      goto sb;
    }
  }
  void dis(){
    cout<<"   "<<id<<"     "<<name<<"       "<<price<<endl;
  }
};
struct item* del(struct item* h,int k){
  struct item* l=h,*r=h;
  bool f=true;
  if(h->id==k){
    l=h->next;
    delete(h);
    cout<<"item deleted successfully.."<<endl;
    return l;
  }
  while(h!=nullptr){
    if(h->id==k){
      l->next=h->next;
      delete(h);
      f=false;
      cout<<"item deleted successfully.."<<endl;
      break;
    }
    l=h;
    h=h->next;
  }
  if(f){
    cout<<"no such item exists in the cart"<<endl;
  }
  return r;
}
class user{
  string name;
  string password;
public:
  user(){
    name="no_name";
    password="-1";
  }
  void newuser(){
    cout<<"enter the user name"<<endl;
    cin>>name;
    cout<<"enter the password"<<endl;
    cin>>password;
  }
};
class transaction{
  struct item* h;
  int grand_total;
public:
  transaction(){
  int m;
  grand_total=0;
  h=nullptr;
  do{
    cout<<"current items in cart: -"<<endl;
    this->display();
    cout<<"enter: "<<endl;
    cout<<"1 to add new item"<<endl;
    cout<<"2 to delete an item"<<endl;
    cin>>m;
      if(m==1){
      struct item* new_item=new item();
      new_item->next=h;
      h=new_item;
      cout<<"item added to the cart"<<endl;
    }
      else if(m==2){
      if(h!=nullptr){
        cout<<"enter the item id to delete"<<endl;
        int k;
        cin>>k;
        h=del(h,k);
      }
      else{
        cout<<"the list is empty!"<<endl;
      }
    }
    else
    cout<<"invalid input"<<endl;
    cout<<"press 0 to check out and any other number to continue"<<endl;
    cin>>m;
    if(m==0){
        cout<<"proceeding to payment......."<<endl;
        this->pay();
    }
    else
    system("cls");
  }while(m!=0);
}
void display(){
  if(h==nullptr){
    cout<<"_none_"<<endl;
    return;
  }
  struct item* temp=h;
  cout<<"   "<<"id"<<"     "<<"name"<<"       "<<"price"<<endl;
  while(temp!=nullptr){
    temp->dis();
     temp=temp->next;
  }
}
void pay(){
  struct item* temp=h;
  while(temp!=nullptr){
    grand_total+=temp->price;
     temp=temp->next;
  }
  cout<<"the grand total of all item is :- "<<grand_total<<endl;
  cout<<"total due after taxes: "<<float(grand_total)*18/100+grand_total<<endl;
}
};
int main(){
  transaction* t1=new transaction();
  return 0;
}

