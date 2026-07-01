#include <iostream>
#include <stack>
using namespace std;

//postfix to infix expression

int main(){
    string exp = "ab+cd-*";

    stack<string> st;

    for(int i=0; i<exp.length(); i++){
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();

            string ans = "(" + b + string(1,exp[i]) + a + ")";

            st.push(ans);
        }
        else{
            st.push(string(1,exp[i]));
        }
    }

    string ans = st.top();
    st.pop();

    cout<<ans<<endl;
    return 0;
}