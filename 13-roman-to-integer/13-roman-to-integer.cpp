class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int no = 0;
        int i=0;
        while(i<n) {
            switch(s[i]) {
                case 'I' :  no += 1;
                            if(i+1<n) {
                                if(s[i+1]=='V') {
                                    no += 3;
                                    i++;
                                }
                                else if(s[i+1]=='X') {
                                    no += 8;
                                    i++;
                                }
                            }
                        break;
                case 'V' : no += 5;
                        break;
                case 'X' :  no += 10;
                            if(i+1<n) {
                                if(s[i+1]=='L') {
                                    no += 30;
                                    i++;
                                }
                                else if(s[i+1]=='C') {
                                    no += 80;
                                    i++;
                                }
                            }
                        break;
                case 'L' :  no += 50;                            
                        break;
                case 'C' :  no += 100;
                            if(i+1<n) {
                                if(s[i+1]=='D') {
                                    no += 300;
                                    i++;
                                }
                                else if(s[i+1]=='M') {
                                    no += 800;
                                    i++;
                                }
                            }                            
                        break;
                case 'D' :  no += 500;
                        break;
                case 'M' :  no += 1000;
                        break;
            }
            i++;
        }
        return no;
    }
};