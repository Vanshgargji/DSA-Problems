class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;

        for(int i=0; i<26; i++){
            int flag = 0;
            
            for(int j=0; j<word.size(); j++){
                if(word[j] == 'a'+ i){
                    flag++; 
                    break;
                }
            }

            for(int k=0; k<word.size(); k++){
                if(word[k] == 'A'+ i){
                    flag++; 
                    break;
                } 
            }

            if(flag == 2) count++;
        }
        return count;
    }
};