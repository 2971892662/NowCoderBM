//BM65 最长公共子序列（二）
#include <string>
#include <vector>
#include<iostream>
using namespace std;

struct pos {
    int i;
    int j;
    int len;
    pos() :i(-1), j(-1), len(0) {};
};

string LCS65(string s1, string s2) {
    int lcs = 0;
    pos lcs_pos;
    if (s1.length() == 0 || s2.length() == 0) {
        return "-1";
    }
    vector<vector<pos>> m_pos = vector<vector<pos>>(s1.length(), vector<pos>(s2.length()));
    for (int i = s1.length() - 1; i >= 0; i--) {
        for (int j = s2.length() - 1; j >= 0; j--) {
            if (j == s2.length() - 1 || i == s1.length() - 1) {
                if (s1[i] == s2[j]) {
                    m_pos[i][j].i = i;
                    m_pos[i][j].j = j;
                    m_pos[i][j].len = 1;
                }
                else {
                    /*
                    int main() {
                        string s1 = "EKhHnp06qE75TmA7036PyZdlzad49gGNsEAe0830ozh5zKD1w3ngrA7VA0OvK15v12WzqDERP375C3NJKP934O8Ix0NF412B6Kk2hbALBzYFq66r0BuSPt1KD816nwOWB0M1dK2Cg1s9O6IfQTS0bT852U78SSjk4astw2KKvudmsavy2699Ut1DN3bp0cbJuB131j6W8L7NTf8NnfznSWtF7g3UDB9O68UXU730f02WLnPGCcHOn0SRnnuXrQ862Z77Jo24H3WAmEZG5BbKztIec1OFr7kXS54k1HBN5Mqx5f6SzL6Po3LDXmIlb613ZBozxg5c9Uc3Bnssp17E1ch2ZS5LGn4TYf2CN88J2GC43k12hV4zeg23S4D3LNM31R6R3JuoMDBwHc349pzjmb7nCxWysf9csh4vC30k5185H023UI6E2Eiwys8bhb97CoDv16X40iNgb89O0c2C4y0Ew0FoHSFyePi34s2ik9H5KFgD7aCbar29j2bNxGo7ym1xO5VQouJAhmAZhBVHF6QPspcvn90zH8B2928Lae8a6JD28z38Z56Urr1MB8753xi5NfdGqA5CekTU0MStGmDBOzTE0GAfc3ygNLLTe0rwQ2WN4rX62YiwOBkX3OUJt8IR2Z7xv6u3g0E3498072lOGX6nm6zQJsV38HN4IFL9ekbWdMEr904wkK4mbEjz0ff3NB7G1x4Q42o9X2Vj5kDuSFl7HOT8CyMzw18kVoiDj3ri0EB2zl585M93rdOlcXL1acrR4m1VmRNRkj6YOsxa7g841UG77T5e2N61iZ1375A9BMKj5Li15rNKR33dXU6dNASuEBTgL4IR347M6kK40L6ui7uLW64qIUpPZvy5s3LP9827FWJEH98aB68rhp8xqUhJ6VPv4HJudP1l5wwL7g2B2o9s9P377Ed4c24e5HmDs5RU8YbB9uCGHC5da081o4C26FhJR8NSe0tIKoHPgbq31zNEmDo1nF3l1O4aSy0LF9dfthJFy0nWzyMdCy6du3bRNF8z93MKF1bJbehe16cqHXqFJI54aE3K9h8pooBgSqG4U9FH2eZT3IB21RJH24e9lrGpE8l22WOB3WmMj806890C45Few54gN5F1jBO2Ge5KqSopHaqK2FkvVStbeFkz4p143709gLtwIiww9E2Eg9VPty7Jx7ej7nmW5rfpnfwXWiD6zNg9z7J2ybs96l23868bytw8cA0H2kAA1QOidYvrA255bAZt0x5GTIrOP5I0ynCRsT54MYiDgFkJX7I7X9F2K3n369GOl8Ih3w7vwpq4f214e2l0745K9ighL6Pz7PNCO8oP5YNQ3oHXK7HV82bUSPk19kwu8xRRp8mNBAeo2W7yMe64UQD6W95fFo1NS2Q49e958w493WVL3O2t98Au6P3z3Bifb2bmQL1GXcL9VT1X3EgnmvnN03yqGVt278KLL5rJv05U7GUFOi957m8UFn5156Bg9ZcC9OM4Y2jdI1590XO9SrOF222gG13fP9WCNZ47298lZKA5h4sA20pyDqao3PP5YCCcIfTvsYy2ZR5w93s4Y8j0as32gy0ItXOzpqyp7hzik9P958hh8rEULpx1q63bo51Y3s8jLpCusP7O34REDjmixA2s2i4wbcVVshrvio1E4dJB77r2X6J3j8oW6LfmDuDpy3xy5wnJzAwjS5T78";
                        string s2 = "kQlReRfFX";
                        LCS65(s1, s2);
                    }
                    对于i,j为最后一个的情况，需要特殊讨论，不能直接简单的赋值
                    如aXa和X，i=0,j=0时，后面是存在X匹配的
                    */
                    if (j == s2.length() - 1 && i == s1.length() - 1) {
                        m_pos[i][j].i = -1;
                        m_pos[i][j].j = -1;
                        m_pos[i][j].len = 0;
                    }
                    else if (i == s1.length() - 1) {
                        m_pos[i][j].i = m_pos[i][j + 1].i;
                        m_pos[i][j].j = m_pos[i][j + 1].j;
                        m_pos[i][j].len = m_pos[i][j + 1].len;
                    }
                    else if (j == s2.length() - 1) {
                        m_pos[i][j].i = m_pos[i + 1][j].i;
                        m_pos[i][j].j = m_pos[i + 1][j].j;
                        m_pos[i][j].len = m_pos[i + 1][j].len;
                    }
                }
            }
            else {
                if (s1[i] == s2[j]) {
                    m_pos[i][j].i = i;
                    m_pos[i][j].j = j;
                    m_pos[i][j].len = m_pos[i + 1][j + 1].len + 1;
                }
                else {
                    if (m_pos[i + 1][j].len > m_pos[i][j + 1].len) {
                        m_pos[i][j].i = m_pos[i + 1][j].i;
                        m_pos[i][j].j = m_pos[i + 1][j].j;
                        m_pos[i][j].len = m_pos[i + 1][j].len; //易错点
                    }
                    else {
                        m_pos[i][j].i = m_pos[i][j + 1].i;
                        m_pos[i][j].j = m_pos[i][j + 1].j;
                        m_pos[i][j].len = m_pos[i][j + 1].len;
                    }

                }
            }
            if (m_pos[i][j].len > lcs) {
                lcs = m_pos[i][j].len;
                lcs_pos.i = i;
                lcs_pos.j = j;
                cout << s1[i] << "-s1[i]:" << i << ",s2[j]:" << j << ",length=" << m_pos[i][j].len << endl;
            }
        }
    }
    if (lcs == 0) {
        return "-1";
    }
    string result = "";
    int temp_i = 0;
    int temp_j = 0;
    while (lcs > 1) {
        result.insert(result.end(), s1[lcs_pos.i]);
        lcs--;
        temp_i = lcs_pos.i;
        temp_j = lcs_pos.j;
        lcs_pos.i = m_pos[temp_i + 1][temp_j + 1].i;
        lcs_pos.j = m_pos[temp_i + 1][temp_j + 1].j;
    }
    result.insert(result.end(), s1[lcs_pos.i]);
    return result;
}
