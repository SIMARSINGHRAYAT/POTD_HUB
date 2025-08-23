
#include <bits/stdc++.h>

using namespace std;


 

int main(){

string str;

cin>>str;

int dots{};

vector <int> vec={};


 

for (int i{};i<str.length();i++){

int k;

k=str[i];


 

if (k==46){

dots+=1;


 

int vec_size=vec.size();

if (vec_size==0){

cout<<"NO";

return 0;

}

int actual_number={};

int tens=1;


 

for (int p{vec_size-1};p>=0;p--){

actual_number+=vec[p]*tens;

tens*=10;

}

vec.clear();

if (actual_number>255||actual_number<0){

cout<<"NO";

return 0;

}

}

else{

int number=(k-48);

vec.push_back(number);

}

}

int vec_size=vec.size();

int actual_number={};

int tens=1;


 

for (int p{vec_size-1};p>=0;p--){

actual_number+=vec[p]*tens;

tens*=10;

}

vec.clear();

if (actual_number>255||actual_number<0){

cout<<"NO";

return 0;

}

if (dots!=3)

cout<<"NO";

else

cout<<"YES";

}
