#include <iostream>
#include <stack>

const char* TERMS[] = {"()", "{}", "[]"};


bool match(char open_term, char close_term) {
    for (int i = 0; i < 3; ++i) {
        if (TERMS[i][0] == open_term) {
            return TERMS[i][1] == close_term;
        }
    }
    return false;
}

bool is_open_term(char open_term) {
    for (int i = 0; i < 3; ++i) {
        if (TERMS[i][0] == open_term) {
            return true;
        }
    }
    return false;
}

bool is_balanced(char* expression) {
    std::stack<char> st;
    for (int i = 0; i < strlen(expression); ++i) {
        char c = expression[i];
        if (is_open_term(c)) {
            st.push(c);
        }
        else {
            if (st.empty()) return false;
            char t = st.top(); st.pop();
            if (!match(t, c)) {
                return false;
            }
        }
    }
    return st.empty();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please pass string to program" << std::endl;
        exit(-1);
    }
    if (is_balanced(argv[1])) {
        std::cout << "Balanced" << std::endl;
    }
    else {
        std::cout << "Not balanced" << std::endl;
    }
    return 0;
}
