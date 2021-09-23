#pragma once

#include <string>
#include <functional>
#include <map>
#include <vector>
#include "system.h"
namespace alg
{
    /**
    *   ��������ϵͳ
    */
    class IFSystem
    {
    public:
        /**
        *   �ַ��¼�
        */
        typedef std::function<void(const std::string& text)> WordHandle;

        struct RuleInfo
        {
        public:
            // ����
            float Probability = 1;
            // �ؼ���
            std::string Key;
            // ֵ
            std::string Value;
            // ����
            std::string Content;
        };
    public:
        IFSystem();

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
        *   ��ӹ���
        */
        void addRule(float probability, const std::string& content);
        /**
        *   ѡ��һ������
        */
        std::string getRandomRule(const std::string& key);

        /**
        *   �����ı�
        */
        std::string createText(int count);

        /**
        *   ����һ�غϵ��ı�
        */
        std::string createRoundText(const std::string& text, const std::map<int, std::vector<std::string>>& keys);

        /**
        *   �����ı�
        */
        void parseText(const std::string& text);
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
        std::map<std::string, std::vector<RuleInfo>> _rules;
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