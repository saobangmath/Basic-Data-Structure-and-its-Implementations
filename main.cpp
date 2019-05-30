#include <iostream>
using namespace std;
struct Interval{
    int open ,close;
};
struct ITNode{
    Interval *i;
    int max; // store the maximum value of the subtree
    ITNode *left, *right;
};

ITNode* newNode(Interval i){
    ITNode *temp = new ITNode();
    temp->i = new Interval(i);
    temp->left=temp->right = NULL;
    temp->max = i.close;
    return temp;
};

//insert  function to insert new Interval in the IT Tree
ITNode *insert(ITNode *root, Interval i){
    if (root == NULL){
        return newNode(i);
    }
    else{
        int open = root->i->open;
        if (open > i.open){
            root->left = insert(root->left,i);
        }
        else{
            root->right = insert(root->right,i);
        }
        if (root->max < i.close){
            root->max = i.close;
        }
        return root;
    }
}
bool doOverLap(Interval i1, Interval i2){
    if (i1.open <= i2.close && i2.open <=i1.close){
        return true;
    }return false;
}
Interval *overlapSearch(ITNode *root, Interval i){
    if (root == NULL){
        return NULL;
    }
    else{
        if (doOverLap(*(root->i),i)){
            return root->i;
        }
        else{
            if (root->left != NULL && root->left->max >=i.open){
                return overlapSearch(root->left, i);
            }
            else{
                return overlapSearch(root->right,i);
            }
        }
    }
}
int main()
{
    Interval ints[] = {{15, 20}, {10, 30}, {17, 19},
        {5, 20}, {12, 15}, {30, 40}
    };
    int n = sizeof(ints)/sizeof(ints[0]);
    ITNode *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, ints[i]);
    Interval x = {6, 7};

    cout << "\nSearching for interval [" << x.open << "," << x.close << "]";
    Interval *res = overlapSearch(root, x);
    if (res == NULL)
        cout << "\nNo Overlapping Interval";
    else
        cout << "\nOverlaps with [" << res->open << ", " << res->close << "]";
    return 0;
}
