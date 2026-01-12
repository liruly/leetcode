// data_structures

// Step1
#include <stack>
#include <iostream>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
                continue;
            } else if ((c == ')' || c == '}' || c == ']') && !st.empty()) {
                const char top = st.top();
                if ((top == '(' && c == ')') || (top == '{' && c == '}') || (top == '[' && c == ']')) {
                    st.pop();
                    continue;
                }
            }
            return false;
        }
        return st.empty();
    }
};

// Step2
#include <stack>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;

        std::unordered_map<char, char> match = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        for (char c : s) {
            if (match.count(c)) {
                st.push(c);
            } else if (!st.empty() && match[st.top()] == c ) {
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty();
    }
};
