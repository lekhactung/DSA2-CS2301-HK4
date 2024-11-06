#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int findMax(int a[],int n){
    int max = a[0];
    for(int i=0;i<n;i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    return max;
}

void countingSortAsc(int a[],int b[],int n,int k,int &kt){
    int c[k+1] = {0};
    for(int i=0;i<n;i++){
        c[a[i]]++;
    }
    kt = 0;
    for(int i =0;i<=k;i++){
        while(c[i] > 0 ){
            b[kt++] = i;
            c[i]--;
        }
    }
}

void countingSortDesc(int a[],int b[],int n,int k,int &kt){
    int c[k+1] = {0};
    for(int i=0;i<n;i++){
        c[a[i]]++;
    }
    kt = 0;
    for(int i=k;i>=0;i--){
        while(c[i] > 0){
            b[kt++] = i;
            c[i]--;
        }
    }
}

void output(int a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}
int main(){
    int b[MAX];
    int a[15] = {7,5,1,1,4,2,1,5,0,8,3,5,1,3,7};
    int n = sizeof(a)/sizeof(a[0]);
    int k = findMax(a,n);
    int kt;
    countingSortDesc(a,b,n,k,kt);
    output(b,n);
    return 1;
}