class Solution {
public:
    void func(string &result, string symbol, int i){
        while(i > 0){
            result += symbol;
            i--;
        }
    }

    string intToRoman(int num) {
        vector<int> val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> symb = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string result = "";
        for(int i=0; i<13; i++){
            if(num == 0) break;

            int times = num / val[i];

            func(result, symb[i], times);

            num = num - times * val[i];
        }
        
        return result;
    }
};