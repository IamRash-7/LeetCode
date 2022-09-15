class Solution {
public:
  int myAtoi(string s) {
      
    const int len = s.size();

    if(len == 0){
        return 0;
    }

    int index = 0;

    // skipping white spaces
    while(index < len && s[index] == ' '){
        ++index;
    }

    // to handle sign cases
    bool isNegative = false;

    if(index < len)
    {
        if(s[index] == '-')
        {
            isNegative = true;
            ++index;
        } 
        else if (s[index] == '+')
        {
          ++index;
      }

    }

    int result = 0;

    // converting digit(in character form) to integer form
    // iterate until non-digit character is not found or we can say iterate till found character is a digit
    while(index < len && isDigit(s[index])){
      int digit = s[index] - '0';

      // to avoid integer overflow
      if(result > (INT_MAX / 10) || (result == (INT_MAX / 10) && digit > INT_MAX % 10))
      {
          return isNegative ? INT_MIN : INT_MAX;
      }

      result = (result * 10) + digit;
      ++index;
    }
      
    return isNegative ? -result : result;
  }
    
  bool isDigit(char ch){
    return ch >= '0' && ch <= '9';
  }
};