#include "PCFG.h"
#include <chrono>
#include <fstream>
#include "md5.h"
#include <iomanip>
#include <vector>
using namespace std;
using namespace chrono;

// 编译指令如下：
// g++ correctness.cpp train.cpp guessing.cpp md5.cpp -o main
// g++ main.cpp train.cpp guessing.cpp md5.cpp -o main


// 通过这个函数，你可以验证你实现的SIMD哈希函数的正确性
int main()
{
    // 创建测试字符串向量
    vector<string> test_inputs;
    string test_str = "bvaisdbjasdfnavkjnakdjfejsdkafkasdfnavkjnakdasdkafkajfejfanjsdnfkajdfkajdfjkwanfdjaknsvjkanbjbjadfajwefajksdfakdnsvjadfasjdvabvaisdbjfanjsdnfkajdfkajdfjkwanfdjaknsvjkanbjbjadfajwefajksdfakdnsvjadfasjdvabvaisdbjasdkafkasdfnavkjnakdjfejfanjsdnfkajdfkajdfjkwanfdjaknsvjkanbjbjadfajwefajksdfakdnsvjadfasjdvabvaisdbjasdkafkasdfnavkjnakdjfejfanjsdnfkajdfkajdfjkwanfdjaknsvjkanbjbjadfajwefajksdfakdnsvjadfasjdva";
    
    // 填充4个相同的测试字符串
    for(int i = 0; i < 4; i++) {
        test_inputs.push_back(test_str);
    }

    // 创建状态数组
    bit32 states[4][4];
    
    // 调用SIMD版本的MD5哈希函数
    MD5Hash_SIMD(test_inputs, states);
    cout<<"________---------------------------------________"<<endl;

    // 输出第一个结果（因为4个输入相同，所以结果也应该相同）
    for(int i = 0; i < 4; i++){
    for (int i1 = 0; i1 < 4; i1 += 1)
    {
        cout << std::setw(8) << std::setfill('0') << hex << states[i][i1];
    } 
    
    cout << endl;
    }
    cout<<"Sgl"<<endl;
    // 为了验证正确性，我们也用原始MD5函数计算一次
    bit32 state[4];
    MD5Hash(test_str, state);
    for (int i1 = 0; i1 < 4; i1 += 1)
    {
        cout << std::setw(8) << std::setfill('0') << hex << state[i1];
    }
    cout << endl;
        cout<<"________---------------------------------________"<<endl;

}