// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
      int a, b;
      while ((a = rand7()) == 7) ;
      while ((b = rand7()) > 5) ;
      return (a % 2) * 5 + b;
    }
};
