#pragma once

#include <string>
#include <functional>
#include <map>
#include <vector>
#include "system.h"

namespace alg
{
    /**
    *   L ϵͳ
    */
    class LSystem
    {
    public:
        /**
        *   �ַ��¼�
        */
        typedef std::function<void(const std::string& text)> WordHandle;
    public:
        LSystem()
        {
        }
    public:
        /**
        *   ��ʼ״̬
        */
        const std::string& getOrigin() const;
        /**
        *   ���ó�ʼ״̬
        */
        void setOrigin(const std::string& origin);
        /**
        *   �����ĸ
        */
        void addWord(const std::string& word);
        /**
        *   �Ƴ���ĸ
        */
        void removeWord(const std::string& word);
        /**
        *   ��������
        */
        void setGenerateSymbol(const std::string& symbol);
        /**
        *   ��������
        */
        const std::string& getGenerateSymbol();
        /**
        *   ��ĸ����
        */
        void setWordHandle(const WordHandle& handle);
        /**
        *   ��ĸ����
        */
        const WordHandle& getWordHandle() const;

    public:
        /**
        *   �����ı�
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
        *   �����ı�
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
        *   ��ʼ״̬
        */
        std::string _origin;
        /**
        *   ��ĸ
        */
        std::vector<std::string> _words;
        /**
        *   ���ɹ���
        */
        std::string _rule;
        /**
        *   ��������
        */
        std::string _generateSymbol;
        /**
        *   ��ĸ����
        */
        WordHandle _wordHandle;
    };
}