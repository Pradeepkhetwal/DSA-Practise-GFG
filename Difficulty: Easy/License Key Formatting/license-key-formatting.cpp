//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution
{
   public:
   void StringReversal(string &ans){
       	stack<char> st;
    	
    	for(int i = 0 ;i<ans.length();i++){
    	    st.push(ans[i]);
    	}
    	ans  ="";
    	while(!st.empty()){
    	   ans += st.top();
    	   st.pop();
    	}
   }
    string ReFormatString(string S, int K){
    	
    	//step 1 . Removing the dashes from the string .
    	
    	string ans = "";
    	for(int i = 0  ; i<S.length();i++){
    	    if(S[i]!='-'){
    	        ans += S[i];
    	    }
    	}
    	
    	
    	//step 2. string Reversal.
    StringReversal(ans);
    	
    	
    	//step 3 = converting to uppercase.
    	for(int i =0 ; i<ans.length();i++){
    	    ans[i] = toupper(ans[i]);
    	}
    	
    	//step 4-:Now using the value of K to divide the string into groups.
    	
    	int count =0 ;
    	string res = "";
    	for(int i =0 ; i<ans.length();i++){
    	    count++;
    	   res += ans[i];
    	   if(count == K && i+1 < ans.length()){
    	       res += '-';
    	       count = 0;
    	   }
    	}
    	
    	//step 5-:Reversing again
    	StringReversal(res);
    	return res;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string S;
	    cin>>S;
	    int K;
	    cin >> K;
	    Solution ob;  
	    string ans=ob.ReFormatString(S, K);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends