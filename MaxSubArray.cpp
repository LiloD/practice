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

int main(){
	vector<int> arr = {1, -2, 3, 10, -4, 7, 2, -5};
	auto ret = MaxSubArray(arr);
	cout<<ret<<endl;
	return 0;
}