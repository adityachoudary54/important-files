#include<iostream>
#include<queue>
#include<complex>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d):data(d),left(NULL),right(NULL){}//if any data member is const then using this list is compulsory
};

node* takeInput()
{
    int data;
    cin>>data;
    node *n=NULL;
    if(data!=-1)
    {
        n=new node(data);
        n->left=takeInput();
        n->right=takeInput();
    }
    return n;
}

void printtree(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" = ";
    if(root->left)
    {
        cout<<root->left->data<<",";
    }
    if(root->right)
    {
        cout<<root->right->data;
    }
    cout<<endl;
    printtree(root->left);
    printtree(root->right);
}
void preorder(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
node* takeinputlevel()
{
    node* root;
    int data;
    queue<node*> q;
    cout<<"Enter root data:";
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty())
    {
        node* f=q.front();
        q.pop();
        int d1,d2;
        cout<<"Enter children of "<<f->data<<" - ";
        cin>>d1>>d2;
        if(d1!=-1)
        {
            f->left=new node(d1);
            q.push(f->left);
        }
        if(d2!=-1)
        {
            f->right=new node(d2);
            q.push(f->right);
        }
    }
    return root;
}
void printlevel(node* root)
{
    queue<node*> q;
    cout<<root->data<<" ";
    q.push(root);
    while(!q.empty())
    {
        node* f=q.front();
        q.pop();
        if(f->left!=NULL)
        {
            cout<<f->left->data<<" ";
            q.push(f->left);
        }
        if(f->right!=NULL)
        {
            cout<<f->right->data<<" ";
            q.push(f->right);
        }
    }
}

void printpatternlevel(node* root)
{
    queue<node*> q;
   // cout<<root->data;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* f=q.front();
        q.pop();
        if(f==NULL)
        {
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
            continue;
        }
        cout<<f->data<<" ";
        if(f->left!=NULL)
        {
            //cout<<f->left->data<<" ";
            q.push(f->left);
        }
        if(f->right!=NULL)
        {
            //cout<<f->right->data<<" ";
            q.push(f->right);
        }
    }
}
istream& operator>>(istream& is,node* &r)
{
    r=takeinputlevel();
    return is;
}
ostream& operator<<(ostream& os,node* &r)
{
    printpatternlevel(r);
    return os;
}
int cnt_nodes(node* root)
{
    if(root==NULL)
        return 0;
    return cnt_nodes(root->left)+cnt_nodes(root->right)+1;
}
int height_tree(node* root)
{
    if(root==NULL)
        return 0;
    /*if(height_tree(root->left)>height_tree(root->right))
        return height_tree(root->left)+1;
    else if(height_tree(root->left)<height_tree(root->right))
        return height_tree(root->right)+1;
    else if(height_tree(root->left)==height_tree(root->right)&&height_tree(root->right)>0)
        return height_tree(root->right)+1;
    else
        return 1;*/
    return 1+max(height_tree(root->left),height_tree(root->right));
}
int sum_prblm(node* root)//address not updating only data is updating
{
    if(root==NULL)
        return 0;
    int temp,sum;
    temp=root->data;
    sum=sum_prblm(root->left)+sum_prblm(root->right);
    if(sum==0)
        return temp;
    root->data=sum;
    return sum+temp;
}

int diameter(node* root)
{
    if(root==NULL)
        return 0;
    //int op1=0;
   // cout<<"hello";
    int a=height_tree(root->left);
    int b=height_tree(root->right);
    int op1=a+b;
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));
}
class Pair
{
public:
    int height;
    int diameter;
};

Pair fastdiameter(node* root)
{
    Pair p;
    if(root==NULL)
    {
        p.height=0;
        p.diameter=0;
        return p;
    }
    Pair left=fastdiameter(root->left);
    Pair right=fastdiameter(root->right);
    int op1=left.height+right.height;
    int op2=left.diameter;
    int op3=right.diameter;
    //cout<<op1<<" "<<op2<<" "<<op3<<endl;
    p.diameter=max(op1,max(op2,op3));
    p.height=1+max(left.height,right.height);
    return p;
}
pair<int,int> amazingsum(node* root)
{
    if(root==NULL)
    {
        return make_pair(0,0);
    }
    pair<int,int> left=amazingsum(root->left);
    pair<int,int> right=amazingsum(root->right);
    int inc=root->data+left.second+right.second;
    int exc=max(left.first,left.second)+max(right.first,right.second);
    return make_pair(inc,exc);
}
node* mirror(node* root)
{
    if(root==NULL)
        return root;
    node* temp;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirror(root->left);
    mirror(root->right);
}

bool height_balanced(node* root)
{
    if(root==NULL)
        return true;
    int x=height_balanced(root->left);
    int y=height_balanced(root->right);
    int l=height_tree(root->left);
    int r=height_tree(root->right);
    return (abs(l-r)==0||abs(l-r)==1)&&x&&y;
}

pair<int,bool> impheight_balanced(node* root)
{
    if(root==NULL)
        return make_pair(0,true);
    pair<int,bool> left=impheight_balanced(root->left);
    pair<int,bool> right=impheight_balanced(root->right);
    return make_pair(1+max(left.first,right.first),(abs(left.first-right.first)==0||abs(left.first-right.first)==1)&&left.second&&right.second);
}

bool ifbst(node* root ,int min_v=INT_MIN,int max_v=INT_MAX)
{
    if(root==NULL)
        return true;
    bool l,r;
    l=ifbst(root->left,min_v,root->data);
    r=ifbst(root->right,root->data,max_v);
    return (root->data>=min_v&&root->data<=max_v)&&l&&r;
}
bool treeident(node* root1,node* root2)
{
    if(root1==NULL||root2==NULL)
        return root1==root2;
    bool l,r;
    //cout<<"hello";
    l=treeident(root1->left,root2->left);
    r=treeident(root1->right,root2->right);
    return (root1->data==root2->data)&&l&&r;
}
node* create_bt(int *in,int *pre,int s,int e)
{
    static int i = e;
    node *root = new node(pre[i]);
    if(s<=e)
    {
        int index=-1;
        for(int j=s;s<=e;j++){
            if(in[j]==pre[i]){
                index = j;
                break;
            }
        }
        i--;//denotes the root on which we are working.
        root->right = create_bt(in,pre,index+1,e);
        root->left = create_bt(in,pre,s,index-1);
        return root;
    }
    return NULL;
}
int main()
{
    node* head;
    int cho;
    head=NULL;
    int prorder[]={4,5,2,6,7,3,1};
    int inrder[]={4,2,5,1,6,3,7};
    int n=sizeof(prorder)/sizeof(int);
    cout<<"Enter the operation that u want to perform->"<<endl;
    cout<<"1. Take input using preorder traversal"<<endl;
    cout<<"2. Print the tree displaying parents with children"<<endl;
    cout<<"3. Print the tree using preorder traversal"<<endl;
    cout<<"4. Print the tree using inorder traversal"<<endl;
    cout<<"5. Print the tree using postorder traversal"<<endl;
    cout<<"6. Take input using level order traversal"<<endl;
    cout<<"7. Print using level order traversal"<<endl;
    cout<<"8. Print the tree using level order traversal in a pattern"<<endl;
    cout<<"9. Count nodes of the tree created"<<endl;
    cout<<"10. Display height of the tree"<<endl;
    cout<<"11. Display diameter of the tree"<<endl;
    cout<<"12. Display diameter of the tree using efficient algorithm"<<endl;
    cout<<"13. Convert tree to its mirror image"<<endl;
    cout<<"14. Check whether tree is balanced or not"<<endl;
    cout<<"15. Check whether the given tree is binary search tree or not"<<endl;
    cout<<"16. Sum problem"<<endl;
    cout<<"17. Create bt"<<endl;
    cout<<"18. exit()"<<endl;
    do
    {
        cin>>cho;
        switch(cho)
        {
        case 1:
            head=takeInput();
            break;
        case 2:printtree(head);
            cout<<endl;
            break;
        case 3:preorder(head);
        cout<<endl;
            break;
        case 4:inorder(head);
        cout<<endl;
            break;
        case 5:postorder(head);
        cout<<endl;
            break;
        case 6:head=takeinputlevel();
            break;
        case 7:printlevel(head);
        cout<<endl;
            break;
        case 8:printpatternlevel(head);
        cout<<endl;
            break;
        case 9:cout<<"No. of nodes in the tree are:"<<cnt_nodes(head)<<endl;
            break;
        case 10:cout<<"The height of given tree is:"<<height_tree(head)<<endl;
            break;
        case 11:cout<<"The diameter of given tree is:"<<diameter(head)<<endl;
            break;
        case 12:cout<<"The diameter of given tree using efficient algorithm is:"<<fastdiameter(head).diameter<<endl;
            break;
        case 13:mirror(head);
            break;
        case 14:if(impheight_balanced(head).first)
                    cout<<"Tree is balanced"<<endl;
                else
                    cout<<"Tree isn't balanced"<<endl;
            break;
        case 15:if(ifbst(head))
                    cout<<"Tree is bst"<<endl;
                else
                    cout<<"Tree isn't bst"<<endl;
            break;
        case 16:sum_prblm(head);
            break;
        case 17://cout<<n;
                head=create_bt(inrder,prorder,0,n-1);
                break;
        default:cho=18;
            break;
        }
    }while(cho!=18);
    return 0;
}
