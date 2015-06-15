#include "helper.h"

int MaxSubArray(vector<int> arr){
	vector<int> f(arr.size()+1, 0);
	f[0] = 0;
	int global = INT_MIN;
	for(int i = 0; i < arr.size(); i++){
		if(f[i] < 0)
			f[i+1] = arr[i];
		else
			f[i+1] = f[i]+arr[i];
		global = max(global, f[i+1]);
	}
	return global;
}


vector<int> MaxSubArray2(vector<int> arr){
	vector<int> f(arr.size()+1, 0);
	f[0] = 0;
	int index = -1;
	int global = INT_MIN;
	for(int i = 0; i < arr.size(); i++){
		if(f[i] < 0)
			f[i+1] = arr[i];
		else
			f[i+1] = f[i]+arr[i];
		if(f[i+1] > global){
			global = f[i+1];
			index = i+1;
		}
	}

	int j = index;
	vector<int> ret;
	while(j >= 0){
		if(f[j] < 0)
			break;
		ret.push_back(arr[j-1]);
		cout<<arr[j-1]<<endl;
		j--;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	vector<int> arr = {1, -2, 3, 10, -4, 7, 2, -5};
	auto ret = MaxSubArray(arr);
	cout<<ret<<endl;
	auto ret_arr = MaxSubArray2(arr);
	PrintVector(ret_arr);
	return 0;
}