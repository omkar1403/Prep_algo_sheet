


  int nextGreaterElement(int n) {
      auto digits = to_string(n);
    next_permutation(begin(digits), end(digits));//here we have used next permutation inbuilt function
    auto res = stoll(digits);
    return (res > INT_MAX || res <= n) ? -1 : res;
      
    }