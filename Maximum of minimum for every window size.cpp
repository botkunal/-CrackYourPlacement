class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int> left(n), right(n), result(n + 1, 0);

    // Initialize stacks to find previous and next smaller elements
    stack<int> s;

    // Fill the left array (Previous Smaller Element)
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear the stack to use it for right array
    while (!s.empty()) {
        s.pop();
    }

    // Fill the right array (Next Smaller Element)
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Compute the maximum of minimums for each window size
    for (int i = 0; i < n; ++i) {
        int length = right[i] - left[i] - 1;  // Window size where arr[i] is the minimum
        result[length] = max(result[length], arr[i]);
    }

    // Fill the result array for all window sizes
    for (int i = n - 1; i >= 1; --i) {
        result[i] = max(result[i], result[i + 1]);
    }

    // The result array for window sizes 1 to n
    vector<int> answer(result.begin() + 1, result.end());
    return answer;
    }
};
