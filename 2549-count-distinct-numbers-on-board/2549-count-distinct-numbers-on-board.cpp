class Solution {
public:
    int distinctIntegers(int n) {if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }
        return n-1;
    }
};