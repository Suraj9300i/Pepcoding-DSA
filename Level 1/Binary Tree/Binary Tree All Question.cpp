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
typedef vector<bool> vb;
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

void preorder(Node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int SSize(Node* node){
	if(node==NULL) return 0;
	int ls = SSize(node->left);
	int rs = SSize(node->right);
	return (ls+rs+1);
}

int Sum(Node* node){
	if(node==NULL) return 0;
	int ls = Sum(node->left);
	int rs = Sum(node->right);
	return (ls+rs+node->data);
}

int Max(Node* node){
	if(node==NULL) return INT_MIN;
	int lm = Max(node->left);
	int rm = Max(node->right);
	return max({lm,rm,node->data});
}

int Height(Node* node) {
	if(node==NULL) return -1;
	int lh = Height(node->left);
	int rh = Height(node->right);
	return 1+max(lh,rh);
}

void levelOrder(Node* node){
	queue<Node*> mqu,cqu;
	mqu.push(node);
	while(!mqu.empty()){
		Node* cur = mqu.front();
		mqu.pop();
		cout<<cur->data<<" ";
		if(cur->left!=NULL) cqu.push(cur->left);
		if(cur->right!=NULL) cqu.push(cur->right);
		if(mqu.empty()){
			swap(mqu,cqu);
			cout<<endl;
		}
	}
}

void iterativePrePostInTraversal(Node* node){
	vi pre,post,in;
	stack<pair<Node*,int>> st;
	st.push({node,1});
	while(!st.empty()){
		Node* cur = st.top().ff;
		int state = st.top().ss;
		if(state==1){
			pre.push_back(cur->data);
			st.top().ss++;
			if(cur->left!=NULL) st.push({cur->left,1});
		}
		else if(state==2){
			in.push_back(cur->data);
			st.top().ss++;
			if(cur->right!=NULL) st.push({cur->right,1});
		}
		else{
			post.push_back(cur->data);
			st.pop();
		}
	}
	for(int ele:pre) cout<<ele<<" ";
	cout<<endl;
	for(int ele:in) cout<<ele<<" ";
	cout<<endl;
	for(int ele:post) cout<<ele<<" ";
	cout<<endl;
}

vi nodeToRootPath(Node* root,int data){
	if(root==NULL) return {};
	if(root->data==data) return {data};
	vi lp = nodeToRootPath(root->left,data);
	vi rp = nodeToRootPath(root->right,data);
	vi v;
	for(int ele:lp) v.push_back(ele);
	for(int ele:rp) v.push_back(ele);
	if(v.size()>0) v.push_back(root->data);
	return v;
}

void printKLevelsDown(Node* node, int k){
	// Using Level Order Traversal

	// queue<Node*> mqu,cqu;
	// mqu.push(node);
	// while(!mqu.empty()){
	// 	Node* cur = mqu.front();
	// 	mqu.pop();
	// 	if(cur->left!=NULL) cqu.push(cur->left);
	// 	if(cur->right!=NULL) cqu.push(cur->right);
	// 	if(mqu.empty()){
	// 		swap(mqu,cqu);
	// 		k--;
	// 	}
	// 	if(k==0){
	// 		while(!mqu.empty()){
	// 			cout<<mqu.front()->data<<endl;
	// 			mqu.pop();
	// 		}
	// 		break;
	// 	}
	// }

	// Using DFS
	if(node==NULL) return;
	if(k==0) cout<<node->data<<"\n";
	printKLevelsDown(node->left,k-1);
	printKLevelsDown(node->right,k-1);
}

vector<Node*> nodeToRootPathNode(Node* root,int data){
	if(root==NULL) return {};
	if(root->data==data) return {root};
	vector<Node*> lp = nodeToRootPathNode(root->left,data);
	vector<Node*> rp = nodeToRootPathNode(root->right,data);
	vector<Node*> tp;
	for(Node* ele:lp) tp.push_back(ele);
	for(Node* ele:rp) tp.push_back(ele);
	if(tp.size()>0) tp.push_back(root);
	return tp;
}

void printKLevelsDownNode(Node* root,int k,Node* strict){
	if(root==NULL) return;
	if(k==0){
		cout<<root->data<<endl;
		return;
	}
	if(root->left!=strict) 
		printKLevelsDownNode(root->left,k-1,strict);
	if(root->right!=strict) 
		printKLevelsDownNode(root->right,k-1,strict);
}

void printKNodesFar(Node* node, int data, int k){
	vector<Node*> paths = nodeToRootPathNode(node,data);
	Node* prev = NULL;
	for(int i=0;i<paths.size();i++){
		if(k-i<0) break;
		printKLevelsDownNode(paths[i],k-i,prev);
		prev = paths[i];
	}
}

void pathToLeafFromRoot(Node* root, string path, int sum, int lo, int hi){
	if(root==NULL || sum>hi) return;
	if(root->left==NULL && root->right==NULL){
		sum += root->data;
		if(sum>=lo && sum<=hi){
			cout<<path<<root->data<<endl;
		}
		return;
	}
	path += to_string(root->data);
	path += " ";
	sum += root->data;
	pathToLeafFromRoot(root->left,path,sum,lo,hi);
	pathToLeafFromRoot(root->right,path,sum,lo,hi);
}

void printSingleChildNodes(Node* node, Node* parent){
	if(node==NULL) return;
	int c = 0;
	if(node->left!=NULL) c+=1;
	if(node->right!=NULL) c+=1;
	if(c==1){
		if(node->left!=NULL) cout<<node->left->data<<endl;
		if(node->right!=NULL) cout<<node->right->data<<endl;
	}
	printSingleChildNodes(node->left,node);
	printSingleChildNodes(node->right,node);

}

void removeLeaves1(Node* node,Node* parent,bool isLeft){
	if(node==NULL) return;
	if(node->left==NULL && node->right==NULL){
		if(isLeft) parent->left = NULL;
		else parent->right = NULL;
		return;
	}
	removeLeaves1(node->left,node,true);
	removeLeaves1(node->right,node,false);
}

Node* removeLeaves2(Node* node){
	if(node==NULL) return NULL;
	if(node->left==NULL && node->right==NULL) return NULL;
	Node* ln = removeLeaves2(node->left);
	Node* rn = removeLeaves2(node->right);
	node->left = ln;
	node->right = rn;
	return node;
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

void createLeftCloneTree1(Node* node){
	if(node==NULL) return;
	Node* olt = node->left;
	Node* nn = new Node(node->data);
	nn->left = olt;
	node->left = nn;
	createLeftCloneTree1(olt);
	createLeftCloneTree1(node->right);
}

Node* createLeftCloneTree2(Node* node){
	if(node==NULL){
		return NULL;
	}
	Node* oln = createLeftCloneTree2(node->left);
	Node* orn = createLeftCloneTree2(node->right);
	Node* nn = new Node(node->data);
	nn->left = oln;
	node->left = nn;
	node->right = orn;
	return node;
}

void transBackFromLeftClonedTree1(Node* node){
	if(node==NULL) return;
	if(node->left==NULL) return;
	node->left = node->left->left;
	transBackFromLeftClonedTree1(node->left);
	transBackFromLeftClonedTree1(node->right);
}

Node* transBackFromLeftClonedTree2(Node* node){
	if(node==NULL || node->left==NULL) return NULL;
	node->left = node->left->left;
	Node* ln = transBackFromLeftClonedTree2(node->left);
	Node* rn = transBackFromLeftClonedTree2(node->right);
	node->left = ln;
	node->right = rn;
	return node;
}

int totaltilt = 0;
int tilt(Node* node){
	if(node==NULL) return 0;
	int ls = tilt(node->left);
	int rs = tilt(node->right);
	totaltilt += abs(ls-rs);
	return (ls+rs+node->data);
}

int mx_diameter = 0;
int diameter(Node* node){
	if(node==NULL) return -1;
	int lh = diameter(node->left);
	int rh = diameter(node->right);
	mx_diameter = max(mx_diameter,(lh+rh+2));
	return max(lh,rh)+1;
}

bool isBalanced = true;
int isBalancedTree(Node* root){
	if(root==NULL) return -1;
	int lh = isBalancedTree(root->left);
	int rh = isBalancedTree(root->right);
	if(!isBalanced or lh==-2 or rh==-2) return -2;
	if(abs(lh-rh)>1){
		isBalanced = false;
		return -2;
	}
	return (1+max(lh,rh));
}

bool bst = true;
pair<int,int> isBSTHelper(Node* root){
	if(root==NULL || !bst){
		return {INT_MAX,INT_MIN};
	}
	pair<int,int> left = isBSTHelper(root->left);
	pair<int,int> right = isBSTHelper(root->right);
	if(root->data<=left.ss || root->data>right.ff){
		bst = false;
		return {INT_MAX,INT_MIN};
	}
	pair<int,int> cur;
	cur.ff = min({left.ff,right.ff,root->data});
	cur.ss = max({left.ss,right.ss,root->data});
	return cur;
}

bool isBST(Node* root){
	bst = true;
	isBSTHelper(root);
	return bst;
}

class helper{
public:
	int mn;
	int mx;
	int size;
	bool isBst;
	helper(){
		mn = INT_MAX;
		mx = INT_MIN;
		size = 0;
		isBst = true;
	}
};

Node* lbstNode;
int lbstNodesize;
helper* largestBSTHelper(Node* root){
	if(root==NULL)
		return new helper();
	if(root->left==NULL && root->right==NULL){
		helper* nh = new helper();
		nh->mn = root->data;
		nh->mx = root->data;
		nh->size = 1;
		nh->isBst = true;
		return nh;
	}
	helper* lt = largestBSTHelper(root->left);
	helper* rt = largestBSTHelper(root->right);
	helper* nh = new helper();
	nh->mn = min({root->data,lt->mn,rt->mn});
	nh->mx = max({root->data,lt->mx,rt->mx});
	nh->size = lt->size+rt->size+1;
	nh->isBst = false;
	if(lt->isBst && rt->isBst && root->data>lt->mx && root->data<=rt->mn){
		nh->isBst = true;
		if(nh->size>lbstNodesize){
			lbstNode = root;
			lbstNodesize = nh->size;
		}
	}
	// cout<<"Data: "<<root->data<<"\n";
	// cout<<"Max: "<<nh->mx<<"\n";
	// cout<<"Min: "<<nh->mn<<"\n";
	// cout<<"Size: "<<nh->size<<"\n";
	// cout<<"BST: "<<nh->isBst<<"\n";
	// cout<<"----------------------\n";
	return nh;
}

void largestBST(Node* root){
	lbstNode = NULL;
	lbstNodesize = 0;
	largestBSTHelper(root);
	cout<<lbstNode->data<<"@"<<lbstNodesize;
}

void solve(){
	Node* root = construct();
	largestBST(root);

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