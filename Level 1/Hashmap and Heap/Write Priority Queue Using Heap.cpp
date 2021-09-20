#include<iostream>
#include<vector>

using namespace std;

class PriorityQueue {
    vector<int> data;
public:
    PriorityQueue() {}
    
    void add(int val) {
    	data.push_back(val);
    	int ci = data.size()-1;
    	while(ci>0){
    		int pi = (ci-1)/2;
    		if(data[pi]>data[ci]){
    			swap(data[pi],data[ci]);
    			ci = pi;
    		}
    		else break;
    	}
    }	

    int removee() {
    	if(data.size()<=0){
    		cout<<"Underflow"<<endl;
    		return -1;
    	}
    	int x = data[0];
    	swap(data[0],data[data.size()-1]);
    	data.pop_back();
    	int pi = 0;
    	while(pi<data.size()){
    		int lci = pi*2+1;
    		int rci = pi*2+2;
    		int mn = pi;
    		if(lci<data.size() && data[lci]<data[mn]) mn = lci;
    		if(rci<data.size() && data[rci]<data[mn]) mn = rci;
    		if(mn==pi) break;
    		swap(data[mn],data[pi]);
    		if(mn==lci) pi = lci;
    		else pi = rci;
    	}
    	return x;
    }

    int peek() {
    	if(data.size()<=0){
    		cout<<"Underflow"<<endl;
    		return -1;
    	}
    	return data[0];
    }

    int sizee() {
    	return data.size();
    }
};

int main(){
	string str;
	int n;
	PriorityQueue pq;
	while(true){
		cin>>str;
		if(str=="quit") break;
		else if(str=="add"){
			cin>>n;
			pq.add(n);
		}
		else if(str=="remove"){
		    int ans = pq.removee();
			if(ans!=-1) cout<<(ans)<<endl;
		}
		else if(str=="peek"){
		    int ans = pq.peek();
			if(ans!=-1) cout<<(ans)<<endl;
		}
		else if(str=="size"){
			cout<<(pq.sizee())<<endl;
		}
	}

	return 0;
}