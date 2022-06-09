class Solution {
public:
    int largestInteger(int num) {
         string s=to_string(num);
        priority_queue<char> p1,p2;
       
        for(int i=0;i<s.length();i++)
        {
            if((s[i]-'0')%2==0)
            {
                
                p1.push(s[i]);
            }
            else
            {
                p2.push(s[i]);
            }
        }
        for(int i=0;i<s.length();i++)
        {
           if((s[i]-'0')%2==0)
            {
                s[i]=p1.top();
               p1.pop();
            }
            else
            {
                s[i]=p2.top();
                p2.pop();
            } 
        }
        return(stoi(s));
    }
};