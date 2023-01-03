#include <bits/stdc++.h>
using namespace std;

long long twoPower(int n){
	long long ans = 1;
	for(int i=0; i<n; i++){
		ans = ans * 2;
	}
	return ans;
}

int hosts(vector<int> nid){
	vector<int> a(4);
	int count = 0;
	for(int i=0; i<4; i++){
		int ct=0;
		int n = nid[i];
		while(n!=0){
			if(n&1 == 1){
				count++;
				ct++;
			}
			n = n>>1;
		}
		a[i] = ct;
	}
	// cout<<count<<endl;
	int c = 0;

	for(int i=0; i<4; i++){
		int x = a[i];	
		if(8-x != 0){
			c+=x;
		}
	}
	cout<<"The number of subnets are: ";
	cout<<a[2]+a[3]<<" ," ;
	cout<<twoPower(a[2]+a[3])<<endl;
	return (count);
}

int main(){

	vector<int> ip(4);
	vector<int> mask(4);

	cout<<"Enter ip address:";
	for(int i=0; i<4; i++){
		cin>>ip[i];
	}

	cout<<"Enter mask:";
	for(int i=0; i<4; i++){
		cin>>mask[i];
	}

	vector<int> nid(4);

	for(int i=0; i<4; i++){
		nid[i] = ip[i] & mask[i];
	}

	cout<<"The network id is: ";
	for(int i=0; i<4; i++){
		cout<<nid[i]<<" ";
	}
	cout<<endl;

	int n = hosts(mask);
	n = 32 - n;
	cout<<"Number of hosts are: "<<twoPower(n) - 2<<endl;
}
