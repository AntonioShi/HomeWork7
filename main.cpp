/*
 * 利用队列，编写实现二叉树的层序遍历的代码 */
//  其中二叉树的构建代码如下:
#include <iostream>
#include <string>
using namespace std;

//二叉树节点类
class node {

    public:
        node(char c):data(c){
            leftchild=NULL ;
            rightchild=NULL ;
        }
        char data;
        node * leftchild ;
        node * rightchild ;
};

//构造二叉树，返回指向根节点的指针
node * create_bt(string str) {

    if (str.length()==0) return NULL;

    else {
        node *p=new node(str[0]);
        if(str.length()==1) return p;
        int pair=0,i=0;

        for(;i<str.length();i++) {
        if (str[i]=='(') pair++;
        if (str[i]==')') pair--;
        if ((str[i]==',')&&(pair==1)) break;
    }
    if(1<=i-2) {
        string leftstr=str.substr(2,i-2);
        p->leftchild=create_bt(leftstr);
    }
    if(1<=str.length()-2-i) {
        string rightstr=str.substr(i+1,str.length()-2-i);
        p->rightchild=create_bt(rightstr);
    }

    return p;
    }

}

//撤销二叉树
void destroy(node * root) {

    if (root==NULL) return;
    destroy(root->leftchild);
    destroy(root->rightchild);

    delete root;
}

//凹入法输出二叉树
void print(node * root, int t) {

    if (root==NULL) return ;
    print(root->rightchild,t+1) ;
    for(int i=0;i<t;i++) cout<<'\t';
    cout<<root->data<<endl;
    print(root->leftchild,t+1);//
}

int main() {

    string str="A(B(D,E(G,)),C(,F))" ;//构造二叉树的广义表字符串，格式为 “根节点（左子树，右子树）“
    node *p=create_bt(str) ;//p为指向构建的二叉树的根节点的指针
    print(p,0) ;
    destroy(p) ;

    return 0 ;
}
