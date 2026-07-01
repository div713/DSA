#include <iostream>
#include <stack>
using namespace std;

//infix to prefix;

int main(){
    string exp = "((a+b)*(c-d))";

    stack<string> st;

    for(int i=0; i<exp.length(); i++){
        if(exp[i] == ')'){
            string a = st.top();
            st.pop();
            string op = st.top();
            st.pop();
            string b = st.top();
            st.pop();

            st.pop();

            string newexp = b+a+op;

            st.push(newexp);
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