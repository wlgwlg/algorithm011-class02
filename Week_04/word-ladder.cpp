// 题目描述
// 127. 单词接龙
// 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord  到 endWord 的最短转换序列的长度。转换需遵循如下规则：
// 		每次转换只能改变一个字母。
// 		转换过程中的中间单词必须是字典中的单词。
// 说明:
// 如果不存在这样的转换序列，返回 0。
// 所有单词具有相同的长度。
// 所有单词只由小写字母组成。
// 字典中不存在重复的单词。
// 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int iWordLength = beginWord.length();
        int iTarget = -1;
        map<int, vector<int>> mapWord;
        wordList.push_back(beginWord);
        map<int, int> mapLevel;
        // 建图
        for (int i = 0; i < wordList.size(); ++i)
        {
            mapLevel[i] = 0;
            if (strcmp(wordList[i].c_str(), endWord.c_str()) == 0) iTarget = i;
            for (int j =0; j < wordList.size(); ++j)
            {
                if (i == j) continue;
                bool bHaveFind = false;
                for (int k = 0; k < iWordLength; ++k)
                {
                    if (wordList[i][k] == wordList[j][k]) continue;
                    if (bHaveFind)
                    {
                        bHaveFind = false;
                        break;
                    }
                    bHaveFind = true;
                }
                if (bHaveFind) mapWord[i].push_back(j);
            }
        }
        if (iTarget < 0) return 0;
        // BFS
        mapLevel[wordList.size() - 1] = 1;
        queue<int> q;
        q.push(wordList.size() - 1);
        while (!q.empty())
        {
            int iCur = q.front();
            q.pop();
            auto itr = mapWord.find(iCur);
            if (itr != mapWord.end())
            {
                for (int i = 0; i < itr->second.size(); ++i)
                {
                    int iCurChild = itr->second[i];
                    if (iCurChild == iTarget) return mapLevel[iCur] + 1;
                    if (mapLevel[iCurChild] != 0) continue;
                    mapLevel[iCurChild] = mapLevel[iCur] + 1;
                    q.push(iCurChild);
                }
            }
        }
        return 0;
    }
};

// 先根据单词关系构建关系图，再执行广度优先遍历，性能较低（时间复杂度O(k*n^2)），未优化