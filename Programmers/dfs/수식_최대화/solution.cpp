#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

deque<string> splitted_expression;
long long max_answer = 0;

void dfs(int depth, vector<string> &operations, int before, vector<string> used_op) {
    if(used_op.size() == operations.size()) {
        deque<string> calculate_ex = splitted_expression;
        deque<string> next_calculate;
        
        // 우선순위 높은 operation 부터 계산
        for(int i = 0; i < used_op.size(); i++) {
            while(!calculate_ex.empty()) {
                string first_operand = calculate_ex.front();
                calculate_ex.pop_front();
                
                // 마지막 숫자 처리
                if(calculate_ex.empty()) {
                    next_calculate.push_back(first_operand);
                    break;
                }
                
                string operation = calculate_ex.front();
                calculate_ex.pop_front();

                // 이번 단계에서 계산해야하는 operation인 경우
                if(operation == used_op[i]) {
                    string second_operand = calculate_ex.front();
                    calculate_ex.pop_front();
                    
                    long long first = stoll(first_operand);
                    long long second = stoll(second_operand);
                    
                    // 결과는 다음 operation의 first_operand로 사용되므로 
                    if(operation == "+") {
                        calculate_ex.push_front(to_string(first + second));
                    } else if(operation == "-") {
                        calculate_ex.push_front(to_string(first - second));
                    } else if(operation == "*") {
                        calculate_ex.push_front(to_string(first * second));
                    }
                    
                } else {
                    next_calculate.push_back(first_operand);
                    next_calculate.push_back(operation);
                }
            }
            
            calculate_ex = next_calculate;
            next_calculate.clear();
        }
        
        long long answer = stoll(calculate_ex.front());
        
        if(answer < 0) {
            answer *= -1;
        }
        
        if(answer > max_answer) {
            max_answer = answer;
        }
        
        return;
    }
    
    for(int i = 0; i < operations.size(); i++) {
        if(find(used_op.begin(), used_op.end(), operations[i]) == used_op.end()) {
            vector<string> before_op = used_op;
            used_op.push_back(operations[i]);
            dfs(depth + 1, operations, i, used_op);
            used_op = before_op;
        }
        
    }
}


long long solution(string expression) {
    long long answer = 0;
    
    set<string> operations;
    
    // 하나의 string으로 들어오는 expression parsing
    string tmp = "";
    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            if(tmp.length() > 0) {
                splitted_expression.push_back(tmp);
                tmp = "";
            }
            
            tmp += expression[i];
            splitted_expression.push_back(tmp);
            operations.insert(tmp);
            tmp = "";
        } else {
            tmp += expression[i];
        }
    }
    
    splitted_expression.push_back(tmp);
        
    vector<string> operations_list;
    for(auto o: operations) {
        operations_list.push_back(o);
    }
    
    // 모든 우선 순위에 대한 값을 계산
    vector<string> used_op;
    
    dfs(0, operations_list, -1, used_op);
    
    answer = max_answer;
    
    return answer;
}