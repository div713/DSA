#include <iostream>
#include <stack>
using namespace std;

//prefix to infix expression

int main(){
    string exp = "*+ab-cd";

    stack<string> st;

    for(int i= exp.length()-1; i>=0; i--){
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();

            string ans = "(" + a + string(1,exp[i]) + b + ")";

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