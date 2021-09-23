#pragma once

#include <string>
#include <functional>
#include <map>
#include <vector>
#include "system.h"
namespace alg
{
    /**
    *   函数迭代系统
    */
    class IFSystem
    {
    public:
        /**
        *   字符事件
        */
        typedef std::function<void(const std::string& text)> WordHandle;

        struct RuleInfo
        {
        public:
            // 概率
            float Probability = 1;
            // 关键字
            std::string Key;
            // 值
            std::string Value;
            // 内容
            std::string Content;
        };
    public:
        IFSystem();

    public:
        /**
        *   初始状态
        */
        const std::string& getOrigin() const;
        /**
        *   设置初始状态
        */
        void setOrigin(const std::string& origin);
        /**
        *   添加字母
        */
        void addWord(const std::string& word);
        /**
        *   移除字母
        */
        void removeWord(const std::string& word);
        /**
        *   产生符号
        */
        void setGenerateSymbol(const std::string& symbol);
        /**
        *   产生符号
        */
        const std::string& getGenerateSymbol();
        /**
        *   字母处理
        */
        void setWordHandle(const WordHandle& handle);
        /**
        *   字母处理
        */
        const WordHandle& getWordHandle() const;
    public:
        /**
        *   添加规则
        */
        void addRule(float probability, const std::string& content);
        /**
        *   选择一条规则
        */
        std::string getRandomRule(const std::string& key);

        /**
        *   创建文本
        */
        std::string createText(int count);

        /**
        *   生成一回合的文本
        */
        std::string createRoundText(const std::string& text, const std::map<int, std::vector<std::string>>& keys);

        /**
        *   解析文本
        */
        void parseText(const std::string& text);
    private:
        /**
        *   初始状态
        */
        std::string _origin;
        /**
        *   字母
        */
        std::vector<std::string> _words;
        /**
        *   生成规则
        */
        std::map<std::string, std::vector<RuleInfo>> _rules;
        /**
        *   产生符号
        */
        std::string _generateSymbol;
        /**
        *   字母处理
        */
        WordHandle _wordHandle;
    };
}