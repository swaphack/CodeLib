#include "IFSystem.h"

alg::IFSystem::IFSystem()
{
}

const std::string& alg::IFSystem::getOrigin() const
{
    return _origin;
}

void alg::IFSystem::setOrigin(const std::string& origin)
{
    _origin = origin;
}

void alg::IFSystem::addWord(const std::string& word)
{
    _words.push_back(word);
}

void alg::IFSystem::removeWord(const std::string& word)
{
    auto it = std::find(_words.begin(), _words.end(), word);
    if (it != _words.end()) _words.erase(it);
}

void alg::IFSystem::setGenerateSymbol(const std::string& symbol)
{
    _generateSymbol = symbol;
}

const std::string& alg::IFSystem::getGenerateSymbol()
{
    return _generateSymbol;
}

void alg::IFSystem::setWordHandle(const WordHandle& handle)
{
    _wordHandle = handle;
}

const alg::IFSystem::WordHandle& alg::IFSystem::getWordHandle() const
{
    return _wordHandle;
}

void alg::IFSystem::addRule(float probability, const std::string& content)
{
    if (content.empty() || _generateSymbol.empty())
    {
        return;
    }
    sys::String text = content;
    std::vector<std::string> ruleAry;
    text.split(_generateSymbol, ruleAry);
    if (ruleAry.size() != 2)
    {
        return;
    }
    std::string key = ruleAry[0];
    std::string value = ruleAry[1];

    RuleInfo ruleInfo;
    ruleInfo.Probability = probability;
    ruleInfo.Content = content;
    ruleInfo.Key = key;
    ruleInfo.Value = value;

    _rules[key].push_back(ruleInfo);
}

std::string alg::IFSystem::getRandomRule(const std::string& key)
{
    if (_rules.size() == 0)
    {
        return "";
    }

    std::vector<RuleInfo> values;
    auto it = _rules.find(key);
    if (it == _rules.end())
    {
        return "";
    }

    float totalProbability = 0;
    // 获取全部概率
    for (auto item : values)
    {
        if (item.Content.empty())
            continue;
        totalProbability += item.Probability;
    }

    float value = sys::Random::getNumber(0.0f, totalProbability);

    float temp = 0;
    for (auto item : values)
    {
        // 闭区间
        if (value >= temp && value < temp + item.Probability)
        {
            return item.Value;
        }
        temp += item.Probability;
    }

    return "";
}

std::string alg::IFSystem::createText(int count)
{
    if (_origin.empty()
        || _rules.size() == 0
        || _generateSymbol.empty()
        || _words.size() == 0)
    {
        return "";
    }
    // 按照key长度分组
    std::map<int, std::vector<std::string>> keys;
    for (auto item : _rules)
    {
        if (!item.first.empty())
        {
            int len = item.first.size();
            keys[len].push_back(item.first);
        }
    }

    std::string text = _origin;
    for (int i = 0; i < count; i++)
    {
        text = createRoundText(text, keys);
    }

    return text;
}

std::string alg::IFSystem::createRoundText(const std::string& text, const std::map<int, std::vector<std::string>>& keys)
{
    if (text.empty() || keys.size() == 0)
    {
        return "";
    }
    sys::String roundText = text;
    int cursor = 0;
    do
    {
        bool bFind = false;
        for (auto item : keys)
        {
            if (cursor + item.first > roundText.getSize())
            {// 长度超过
                continue;
            }
            std::string subText = roundText.subString(cursor, item.first).getString();
            auto it = std::find(item.second.begin(), item.second.end(), subText);
            if (it != item.second.end())
            {// 包含关键字
             // 获取随机生成规则
                std::string ruleValue = getRandomRule(subText);
                if (!ruleValue.empty())
                {
                    roundText = roundText.remove(cursor, item.first);
                    roundText = roundText.insert(cursor, ruleValue);
                    cursor += ruleValue.size();
                    bFind = true;
                    break;
                }
            }
        }
        if (!bFind)
        {
            cursor++;
        }

    } while (cursor < roundText.getSize());

    return roundText.getString();
}

void alg::IFSystem::parseText(const std::string& text)
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
    for (auto item : _words)
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
        for (auto item : keys)
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
