/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */
struct myFile
{
    char *str;
    size_t point;
    size_t length;
};

class Reader4 {
    myFile myfile;        
public:
    Reader4(const string str)
    {
        myfile.str = (char *)malloc(sizeof(char) * (str.length() + 1));
        memset(myfile.str, 0, sizeof(char) *(str.length() + 1));
        strcpy(myfile.str, str.c_str());
        myfile.point = 0;
        myfile.length = str.length() + 1;
    }

    int read4(char *buf4)
    {
        int n = 0;
        if(myfile.point + 3 < myfile.length-1)
        {
            while(n < 4)
            {
                buf4[n++] = myfile.str[myfile.point++];
            }
        }
        else if(myfile.point == myfile.length-1) return 0;
        else
        {
            while(myfile.point < myfile.length-1)
            {
                buf4[n++] = myfile.str[myfile.point++];
            }
        }
        return n;
    }

    ~Reader4(){
        myfile.point = 0;
        myfile.length = 0;
        if(myfile.str)
        {
            free(myfile.str);
        }   
    }
};
class Solution : public Reader4{
    char *cache = new char[4];
    int c_idx = 0, c_size = 0;
public:
    Solution(const string str) : Reader4(str){}
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ans = 0;
        while(ans < n)
        {
            while(c_idx < c_size && ans < n)
            {
                buf[ans++] = cache[c_idx++];
            }
            if(ans < n)
            {
                c_size = read4(cache);
                c_idx = 0;
                if(c_size == 0) break;
            }
            
        }   
        return ans;
        
    }
    ~Solution(){
        c_idx = 0, c_size = 0;
        if(cache)
        {
            delete[] cache;
        }
    } 
    
};


int main(int argc, char *argv[])
{
    const string str = "abclkjlij";
    Solution solution = Solution(str);
    char *buf = new char[4];
    int n = 15;

    int result = solution.read(buf, n);
    cout << "\"" << str.substr(0, result) << "\"" << endl;

    return 0;
}