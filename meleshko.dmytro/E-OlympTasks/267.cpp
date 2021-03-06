#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<double> sum_of_2(vector<double>& num1, vector<double>& num2){
    if(num1.size()<num2.size())
        num1.swap(num2);

    vector<double> sum_num;
    int fwd = 0, temp_val;
    for(unsigned it=0; it<num2.size(); it++){
        temp_val=num1[num1.size()-1-it]+num2[num2.size()-1-it]+fwd;
        sum_num.insert(sum_num.begin(), temp_val%10);
        fwd=temp_val/10;
    }

    if(num1.size()==num2.size() && fwd!=0){
         while(fwd!=0){
            sum_num.insert(sum_num.begin(), fwd%10);
            fwd=fwd/10;
        }
    }
    if(num1.size()>num2.size()){
        unsigned it=num2.size();
        while(it<num1.size()){
        temp_val=num1[num1.size()-1-it]+fwd;
        sum_num.insert(sum_num.begin(), temp_val%10);
        fwd=temp_val/10;
        it++;
        }
         while(fwd!=0){
            sum_num.insert(sum_num.begin(), fwd%10);
            fwd=fwd/10;
        }
    }
    return sum_num;
}

vector<double> res_of_2(vector<double>& num1, vector<double>& num2){
    double flag=1;
    if(num1.size()<num2.size()){
        num1.swap(num2);
        flag=-1;
    }
    vector<double> res_num;
    unsigned it;

    int s=0;
    if(num1.size()==num2.size()){
        while(num1[s]==num2[s]){
            s++;
            if(num1[s]<num2[s]){
                num1.swap(num2);
                flag=-1;
            }
        }
        if(num1==num2)
            flag=1;
    }

    for(it=0; it<num2.size(); it++){
        if(num1[num1.size()-it-1]>=num2[num2.size()-it-1]){
        res_num.insert(res_num.begin(), num1[num1.size()-it-1]-num2[num2.size()-it-1]);
        }
        else{
            res_num.insert(res_num.begin(), 10+num1[num1.size()-it-1]-num2[num2.size()-it-1]);
            num1[num1.size()-it-2]--;
        }
    }
        for(unsigned i=it; i<num1.size(); i++){
            if(num1[num1.size()-i-1]>=0)
                res_num.insert(res_num.begin(), num1[num1.size()-i-1]);
            else{
                res_num.insert(res_num.begin(), 10+num1[num1.size()-i-1]);
                 num1[num1.size()-i-2]--;
            }
     }

     while(res_num[0]==0 && res_num.size()>1)
        res_num.erase(res_num.begin());

    res_num[0]*=flag;
    return res_num;
}

vector<double> prod_of_2(vector<double>& num1, vector<double>& num2){
    if(num1.size()<num2.size())
        num1.swap(num2);

    vector<double> prod_num;
    int fwd = 0, temp_val;http://cpp.sh/#
    vector<double> temp;
    for(unsigned i=0; i<num2.size(); i++){
        for(unsigned j=0; j<num1.size(); j++){
            temp_val=num1[num1.size()-1-j]*num2[num2.size()-1-i]+fwd;
            temp.insert(temp.begin(), temp_val%10);
            fwd=temp_val/10;
        }
        while(fwd!=0){
            temp.insert(temp.begin(), fwd%10);
            fwd=fwd/10;
        }
        unsigned s = 0;
        while(s<i){
            temp.push_back(0);
            s++;
        }
        prod_num=sum_of_2(temp, prod_num);
        temp.clear();
    }

    return prod_num;
}

int main()
{
    /*
    string str;
    int N;
    vector<vector<double>> result;
    cin >> N;
    for(int it=0; it<N; it++){
        cin >> str;
        int i=0,m;
        vector<double> A,B,temp;
        while(str[i]!='+' && str[i]!='-'){
            A.push_back(str[i]-'0');
            i++;
        }
        m=i;
        i++;
        // cout << m << "\n";
        while(i<str.length()){
            B.push_back(str[i]-'0');
            i++;
        }
        if(str[m]=='+')
            result.push_back(sum_of_2(A, B));
        if(str[m]=='-')
            result.push_back(res_of_2(A, B));
    }

    for(int it=0; it<N; it++){
        for(unsigned i=0; i<result[it].size(); i++)
            cout << result[it][i];
        cout << "\n";
    }
    */



    string str1, str2;
    vector<double> num1, num2, sum, prod, res;
    //cout << "Enter number 1: ";
    cin >> str1;
    //cout << "Enter number 2: ";
    cin >> str2;


    for(unsigned i = 0; i < str1.length(); i++)
        num1.push_back(str1[i]-'0');
    for(unsigned i = 0; i < str2.length(); i++)
        num2.push_back(str2[i]-'0');

    sum = sum_of_2(num1, num2);
    // prod = prod_of_2(num1, num2);
    res = res_of_2(num1, num2);

    // cout << "\n=RESULTS=\nSum: ";
    // for(unsigned it=0; it<sum.size(); it++)
    //     cout << sum[it];
    // cout << "\nProd: ";
    // for(unsigned it=0; it<prod.size(); it++)
    //     cout << prod[it];
    // cout << "\nRes: ";
    for(unsigned it=0; it<res.size(); it++)
        cout << res[it];
    // cout << "\n";


    return 0;
}
