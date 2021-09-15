#include<bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define mod 1000000007
#define debug(x) cerr<<#x<<" :- ";_print(x);cerr<<endl;
#define debugArray(x,y) cerr<<#x<<" :- ";_print(x,y);cerr<<endl;
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
void fastIO(){
	#ifndef ONLINE_JUDGE 
	freopen("Error.txt","w",stderr);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
}
template<class T> void _print(T x){cerr<<x;}
template<class T> void _print(vector<T> v){cerr<<"[ ";for(T ele:v) cerr<<ele<<" "; cerr<<"]\n";}
template<class T> void _print(T arr[],int n){cerr<<"[ ";for(int i=0;i<n;i++) cerr<<arr[i]<<" "; cerr<<"]\n";}

/***************************Jay Shree Ram****************************/

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(){}
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};


Node* construct(){
	int n;
	cin>>n;
	string arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	Node* root = new Node(stoi(arr[0]));
	stack<pair<Node*,int>> st;
	st.push({root,1});
	for(int i=1;i<n;i++){
		Node* cur = st.top().ff;
		int state = st.top().ss;
		if(arr[i]=="n"){
			st.top().ss++;
			if(st.top().ss>2){
				st.pop();
			}
		}
		else if(state==1){
			Node* nn = new Node(stoi(arr[i]));
			cur->left = nn;
			st.top().ss++;
			st.push({nn,1});
		}
		else{
			Node* nn = new Node(stoi(arr[i]));
			cur->right = nn;
			st.pop();
			st.push({nn,1});
		}
	}
	return root;
}

void display(Node* root){
	if(root==NULL) return;
	if(root->left == NULL) cout<<".";
	else cout<<root->left->data;
	cout<<" <- "<<root->data<<" -> ";
	if(root->right == NULL) cout<<".";
	else cout<<root->right->data;
	cout<<endl;
	display(root->left);
	display(root->right);
}

int size(Node* node) {
	if(node==NULL) 
		return 0;
	return (size(node->left)+size(node->right)+1);
}

int sum(Node* node) {
	if(node==NULL) 
		return 0;
	return (sum(node->left)+sum(node->right)+node->data);
}

int Max(Node* node) {
	if(node->right==NULL)
		return node->data;
	return Max(node->right);
}

int Min(Node* node) {
	if(node->left==NULL)
		return node->data;
	return Min(node->left);
}

bool find(Node* node, int data){
	if(node->data==data)
		return true;
	bool found = false;
	if(data<node->data && node->left!=NULL)
		found = find(node->left,data);
	else if(data>=node->data && node->right!=NULL)
		found = find(node->right,data);
	return found;
}  

Node* add(Node* node, int data){
	if(node==NULL)
		return new Node(data);
	if(node->data==data)
		return node;
	Node* lt;
	Node* rt;
	if(data<node->data){
		lt = add(node->left,data);
		rt = node->right;
	}
	else{
		lt = node->left;
		rt = add(node->right,data);
	}
	node->left = lt;
	node->right = rt;
	return node;
}

Node* remove(Node* node, int data){
	if(node==NULL)
		return NULL;
	if(data==node->data){
		if(node->left==NULL && node->right==NULL){
			return NULL;
		}
		else if(node->left==NULL){
			node->right;
		}
		else if(node->right==NULL){
			return node->left;
		}
		else{
			int mx = Max(node->left);
			node->data = mx;
			remove(node->left,mx);
		}
	}
	else if(data<node->data){
		node->left = remove(node->left,data);
	}
	else{
		node->right = remove(node->right,data);
	}
	return node;
}

int sm = 0;
void rwsol(Node* node){
	if(node==NULL)
		return;
	rwsol(node->right);
	int temp = node->data;
	node->data = sm;
	sm += temp;
	rwsol(node->left);
}

int lca(Node* node, int d1, int d2){
	if(d1<node->data && d2<node->data)
		return lca(node->left,d1,d2);
	else if(d1>node->data && d2>node->data)
		return lca(node->right,d1,d2);
	else
		return node->data;
}

void pir(Node* node, int d1, int d2){
	if(node==NULL)
		return;
	if(node->data>=d1 && node->data<=d2){
		pir(node->left,d1,d2);
		cout<<node->data<<endl;
		pir(node->right,d1,d2);
	}
	else if(node->data>d2)
		pir(node->left,d1,d2);
	else if(node->data<d1)
		pir(node->right,d1,d2);
}

bool remFind(Node* root,Node* flag,int data){
    if(root==NULL) return false;
	if(root!=flag && root->data==data)
		return true;
	if(data<root->data && remFind(root->left,flag,data))
		return true;
	else if(data>=root->data && remFind(root->right,flag,data))
		return true;
	return false;
}

void targetSum(Node* root,Node* node,int tar){
	if(node==NULL) return;
	targetSum(root,node->left,tar);
	int rem = tar-node->data;
	if(rem>node->data){
		if(remFind(root,node,rem)){
			cout<<node->data<<" "<<rem<<endl;
		}
	}
	targetSum(root,node->right,tar);
	
	// Method 2
	// we can put all data in vector in inorder traversal, then
	// we can easily find all pair by 2 pointer approach
}

void solve(){
	Node* root = construct();
	int d1;
	cin>>d1;
	targetSum(root,root,d1);
}

int main(){
	fastIO();
	int t = 1;
	// cin>>t;
	for(int i=1;i<=t;i++){
		solve();
	}

return 0;
}