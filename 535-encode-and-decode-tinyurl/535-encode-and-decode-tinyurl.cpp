class Solution {
public:
    string my_url;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        my_url = longUrl;
        return "";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return my_url;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));