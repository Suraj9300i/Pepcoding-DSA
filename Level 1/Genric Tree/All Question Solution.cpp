#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define ll long long
#define mod 1000000007
#define debug(x) cerr<<#x<<" :- ";_print(x);cerr<<endl;
#define debugArray(x,y) cerr<<#x<<" :- ";_print(x,y);cerr<<endl;
using namespace std;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<vector<ll>> vvi;
void fastIO(){
	#ifndef ONLINE_JUDGE 
	freopen("Error.txt","w",stderr);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
}
template<class T> void _print(T x){cerr<<x<<endl;}
template<class T> void _print(vector<T> v){cerr<<"[ ";for(T ele:v) cerr<<ele<<" "; cerr<<"]\n";}
template<class T> void _print(T arr[],int n){cerr<<"[ ";for(int i=0;i<n;i++) cerr<<arr[i]<<" "; cerr<<"]\n";}

// *************************Jay Shree Ram**************************//

class Node{
public:
	int data;
	vector<Node*> children;
	Node(){
		data = 0;
		children = {};
	}
	Node(int val){
		data = val;
		children = {};
	}
};

Node* construct(){
	int rd,n,val;
	cin>>n>>rd;
	Node* root = new Node();
	root->data = rd;
	stack<Node*> st;
	st.push(root);
	for(int i=1;i<n;i++){
		cin>>val;
		if(val==-1) st.pop();
		else{
			Node* nn = new Node();
			nn->data = val;
			st.top()->children.push_back(nn);
			st.push(nn);
		}
	}
	return root;
}

void display(Node* root){
	cout<<root->data<<" -> ";
	for(Node* ch:root->children){
		cout<<ch->data<<", ";
	}
	cout<<"."<<endl;
	for(Node* ch:root->children){
		display(ch);
	}
}

int size(Node* node){
	int c = 0;
	for(Node* ch:node->children){
		c += size(ch);
	}
	return c+1;
}

int maxx(Node* node){
	int mx = INT_MIN;
	for(Node* ch:node->children){
		int cmx = maxx(ch);
		mx = max(mx,cmx);
	}
	return max(mx,node->data);
}

int height(Node* node){
	int mx = -1;
	for(Node* ch:node->children){
		int cht = height(ch);
		mx = max(mx,cht);
	}
	return mx+1;
}

void traversals(Node* node){
	cout<<"Node Pre "<<node->data<<"\n";
	for(Node* ch:node->children){
		cout<<"Edge Pre "<<node->data<<"--"<<ch->data<<"\n";
		traversals(ch);
		cout<<"Edge Post "<<node->data<<"--"<<ch->data<<"\n";
	}
	cout<<"Node Post "<<node->data<<"\n";
}

void levelOrder(Node* node){
	queue<Node*> qu;
	qu.push(node);
	while(!qu.empty()){
		Node* temp = qu.front();
		qu.pop();
		cout<<temp->data<<" ";
		for(Node* child:temp->children){
			qu.push(child);
		}
	}
	cout<<".\n";
}

void levelOrderLinewise(Node* node){
	/*******Method 1************/
	// queue<Node*> par;
	// queue<Node*> chq;
	// par.push(node);
	// while(!par.empty()){
	// 	Node* temp = par.front();
	// 	par.pop();
	// 	cout<<temp->data<<" ";
	// 	for(Node* child:temp->children){
	// 		chq.push(child);
	// 	}
	// 	if(par.empty()){
	// 		cout<<endl;
	// 		swap(par,chq);
	// 	}
	// }

	/*******Method 2************/
	// queue<Node*> qu;
	// qu.push(node);
	// Node* flag = new Node(-1);
	// qu.push(flag);
	// while(!qu.empty()){
	// 	Node* temp = qu.front();
	// 	qu.pop();
	// 	if(temp->data==-1){
	// 		if(qu.empty()){
	// 			break;
	// 		}
	// 		cout<<endl;
	// 		qu.push(flag);
	// 		continue;
	// 	}
	// 	cout<<temp->data<<" ";
	// 	for(Node* child:temp->children){
	// 		qu.push(child);
	// 	}
	// }

	/*******Method 3************/
	queue<Node*> qu;
	qu.push(node);
	int c = qu.size();
	while(!qu.empty()){
		for(int i=0;i<c;i++){
			Node* temp = qu.front();
			qu.pop();
			cout<<temp->data<<" ";
			for(Node* child:temp->children){
				qu.push(child);
			}
		}
		cout<<endl;
		c = qu.size();
	}
}

void levelOrderLinewiseZZ(Node* node){
	stack<Node*> pst;
	stack<Node*> cst;
	pst.push(node);
	int level = 0;
	while(!pst.empty()){
		Node* cur = pst.top();
		pst.pop();
		cout<<cur->data<<" ";
		if(level%2==0){
			for(int i=0;i<cur->children.size();i++){
				cst.push(cur->children[i]);
			}
		}
		else{
			for(int i=cur->children.size();i>0;i--){
				cst.push(cur->children[i-1]);
			}
		}
		if(pst.empty()){
			cout<<endl;
			level++;
			swap(pst,cst);
		}
	}
}

void mirror(Node* node){
	if(node==NULL)
		return;
	for(Node* child:node->children){
		mirror(child);
	}
	reverse(node->children.begin(), node->children.end());
}

void removeLeaves(Node* node){
	int n = node->children.size();
	for(int i=n-1;i>=0;i--){
		if(node->children[i]->children.size()==0){
			node->children.erase(node->children.begin()+i);
		}
	}
	for(Node* child:node->children){
		removeLeaves(child);
	}
}

Node* getTail(Node* node){
	if(node->children.size()==0)
		return node;
	return getTail(node->children[0]);
}

void linearize(Node* node){
	for(Node* child:node->children){
		linearize(child);
	}
	int n = node->children.size();
	if(n>1){
		Node* lc = node->children[n-1];
		for(int i=n-2;i>=0;i--){
			Node* tail = getTail(node->children[i]);
			tail->children.push_back(lc);
			lc = node->children[i];
			node->children.erase(node->children.begin()+i+1);
		}
	}
}

bool find(Node* node,int data){
	if(node->data==data)
		return true;
	for(Node* child:node->children){
		if(find(child,data))
			return true;
	}
	return false;
}

vector<int> nodeToRootPath(Node* node, int data){
	if(node->data == data)
		return {data};
	vector<int> ans;
	for(Node* child:node->children){
		vector<int> ca = nodeToRootPath(child,data);
		if(ca.size()>0){
			ans = ca;
			break;
		}
	}
	if(ans.size()>0){
		ans.push_back(node->data);
	}
	return ans;
}

int lca(Node* node, int d1, int d2){
	vector<int> p1 = nodeToRootPath(node,d1);
	vector<int> p2 = nodeToRootPath(node,d2);
	int n = p1.size();
	int m = p2.size();
	int i=0,j=0;
	if(n>m) i=n-m;
	else j = m-n;
	while(p1[i]!=p2[j]){
		i++,j++;
	}
	return p1[i];
}
int distanceBetweenNodes(Node* node, int d1, int d2){
	vector<int> p1 = nodeToRootPath(node,d1);
	vector<int> p2 = nodeToRootPath(node,d2);
	int i=p1.size(),j=p2.size();
	while(p1[i-1]==p2[j-1]){
		i--,j--;
	}
	return (i+j);
}

bool areSimilar(Node* n1, Node* n2){
	if(n1->children.size()!=n2->children.size())
		return false;
	int n = n1->children.size();
	for(int i=0;i<n;i++){
		if(!areSimilar(n1->children[i],n2->children[i]))
			return false;
	}
	return true;
}

bool areMirror(Node* n1, Node* n2){
	if(n1->children.size()!=n2->children.size())
		return false;
	int n = n1->children.size();
	for(int i=0;i<n;i++){
		if(!areMirror(n1->children[i],n2->children[n-i-1]))
			return false;
	}
	return true;
}

bool IsSymmetric(Node* node){
	return areMirror(node,node);
}

Node* predecessor = NULL;
Node* successor = NULL;
int pst = 0;
void predecessorAndSuccessor(Node* node, int data) {
	if(pst==0){
		if(node->data==data) pst=1;
		else predecessor = node;
	}
	else if(pst==1){
		successor = node;
		pst=2;
	}
	for(Node* child:node->children){
		predecessorAndSuccessor(child,data);
	}
}

int ceilx = INT_MAX;
int floorx = INT_MIN;
void ceilAndFloor(Node* node, int data) {
	if(node->data>data){
		ceilx = min(ceilx,node->data);
	}
	if(node->data<data){
		floorx = max(floorx,node->data);
	}
	for(Node* child:node->children){
		ceilAndFloor(child,data);
	}
}

int maxSum = INT_MIN;
Node* maxSumNode = NULL;
int maxSubtreeSum(Node* node){
	int sum = node->data;
	for(Node* child:node->children){
		sum += maxSubtreeSum(child);
	}

	if(sum>maxSum){
		maxSum = sum;
		maxSumNode = node;
	}

	return sum;
}

int kthLargest(Node* node, int k){
	int ans = INT_MAX;
	for(int i=0;i<k;i++){
		ceilAndFloor(node,ans);
		ans = floorx;
		floorx = INT_MIN;
	}
	return ans;
}

int dia = 0;
int diameterHelper(Node* root){
	int fht = -1;
	int sht = -1;
	for(Node* child:root->children){
		int cht = diameterHelper(child);
		if(cht>fht){
			sht = fht;
			fht = cht;
		}
		else if(cht>sht){
			sht = cht;
		}
	}

	int cur_dia = fht+sht+2;
	if(cur_dia>dia){
		dia = cur_dia;
	}

	return fht+1;
}

int diameter(Node* root){
	dia = 0;
	diameterHelper(root);
	return dia;
}
void IterativePreandPostOrder(Node* root){
	vi preorder,postorder;
	stack<pair<Node*,int>> st;
	st.push({root,0});
	while(!st.empty()){
		Node* node = st.top().ff;
		int cs = st.top().ss;
		int ts = node->children.size();
		st.pop();
		if(ts==0){
			preorder.push_back(node->data);
			postorder.push_back(node->data);
		}
		else if(cs<ts){
			if(cs==0) preorder.push_back(node->data);
			st.push({node,cs+1});
			st.push({node->children[cs],0});
		}
		else{
			postorder.push_back(node->data);
		}	
	}
	for(int ele:preorder) cout<<ele<<" ";
	cout<<endl;
	for(int ele:postorder) cout<<ele<<" ";
	cout<<endl;
}

int main(){
	fastIO();
	
	Node* root = construct();
	IterativePreandPostOrder(root);

return 0;
}