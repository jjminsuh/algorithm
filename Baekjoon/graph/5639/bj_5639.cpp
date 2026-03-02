#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

struct node {
    int key;
    int left = -1;
    int right = -1;
};

vector<int> left_first;
map<int, node> tree;

// node의 left, right child를 저장
void build_tree(int start, int end) {
    int parent = left_first[start];
    int left_child = -1;
    int right_child = -1;
    int i = start + 1;

    for(i = start + 1; i <= end; i++) {
        if(left_first[i] > parent) {
            break;
        }
    }

    // 오른쪽 tree가 존재하는 경우만 right child 설정
    if(i <= end) {
        right_child = left_first[i];
    }

    // 왼쪽 tree가 존재하는 경우만 left child 설정
    if (i > start + 1) {
        left_child = left_first[start + 1];
    }

    node new_node;
    new_node.key = parent;
    new_node.left = left_child;
    new_node.right = right_child;

    tree.insert(make_pair(parent, new_node));

    if (i != start + 1) {
        build_tree(start + 1, i - 1);
    }

    if(i <= end) {
        build_tree(i, end);
    }
    
    return;
}

int main() {

    int input;
    
    while(cin >> input) {
        left_first.push_back(input);
    }

    int root = left_first[0];

    build_tree(0, left_first.size() - 1);

    stack<int> to_visit;
    stack<int> answer;

    to_visit.push(root);

    // dfs로 순회
    while(!to_visit.empty()) {
        int top = to_visit.top();
        to_visit.pop();
        answer.push(top);

        if (tree[top].left != -1) {
            to_visit.push(tree[top].left);
        }

        if(tree[top].right != -1) {
            to_visit.push(tree[top].right);
        }
    }

    while(!answer.empty()) {
        cout << answer.top() << "\n";

        answer.pop();
    }


    return 0;
}