#pragma once

#include <string>
#include <functional>
#include <map>
#include <vector>
#include "system.h"

namespace alg
{
    /**
    *   L 系统
    */
    class LSystem
    {
    public:
        /**
        *   字符事件
        */
        typedef std::function<void(const std::string& text)> WordHandle;
    public:
        LSystem()
        {
        }
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
        *   创建文本
        */
        std::string createText(int count)
        {
            if (_origin.empty()
                || _rule.empty()
                || _generateSymbol.empty()
                || _words.size() == 0)
            {
                return "";
            }

            sys::String rule = _rule;
            std::vector<std::string> ruleAry;
            rule.split(_generateSymbol, ruleAry);

            if (ruleAry.size() != 2)
            {
                return "";
            }

            std::string a = ruleAry[0];
            std::string b = ruleAry[1];

            sys::String text = _origin;
            for (int i = 0; i < count; i++)
            {
                text = text.replace(a, b);
            }

            return text.getString();
        }

        /**
        *   解析文本
        */
        void parseText(const std::string& text)
        {
            if (text.empty())
            {
                return;
            }
            if (_words.size() == 0)
            {
                return;
            }
            std::map<int, std::vector<std::string>> keys;
            for(auto item : _words)
            {
                if (!item.empty())
                {
                    keys[item.size()].push_back(item);
                }
            }

            sys::String content = text;
            int cursor = 0;
            do
            {
                bool bFind = false;
                for(auto item : keys)
                {
                    if (cursor + item.first > content.getSize())
                    {
                        continue;
                    }
                    std::string value = content.subString(cursor, item.first).getString();
                    auto it = std::find(item.second.begin(), item.second.end(), value);
                    if (it != item.second.end())
                    {
                        if (_wordHandle != nullptr)
                        {
                            _wordHandle(value);
                        }
                        cursor += item.first;
                        bFind = true;
                        break;
                    }
                }

                if (!bFind)
                {
                    break;
                }

            } while (cursor < content.getSize());
        }
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
        std::string _rule;
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