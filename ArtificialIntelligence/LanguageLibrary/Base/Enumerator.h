#pragma once

namespace ll
{
	// 单词词性
	enum WordNominal
	{
		// 名称 n.
		EWN_NOUNS = 1 << 0,
		// 代（名）词 pron.
		EWN_PRONOUN = 1 << 1,
		// 数词 num.
		EWN_NUMERAL = 1 << 2,
		// 动词 v.
		EWN_VERB = 1 << 3,
		// 形容词 adj. a.
		EWN_ADJECTIVE = 1 << 4,
		// 副词 adv.
		EWN_ADVERB = 1 << 5,
		// 冠词 art.
		EWN_ARTICLE = 1 << 6,
		// 介（系）词 prep.
		EWN_PREPOSITION = 1 << 7,
		// 连（接）词 conj.
		EWN_CONJUNCITION = 1 << 8,
		// (感)叹词 interj. int.
		EWN_INTERJECTION = 1 << 9,
	};

	// 名词分类
	enum NounClass1
	{
		// 专有名词
		ENC_PROPER_NOUN,
		// 普通名词
		ENC_COMMON_NOUN,
	};

	// 名词分类
	enum NounClass2
	{
		// 可数名词
		ENC_COUNTABLE_NOUN,
		// 不可数名词
		ENC_UNCOUNTABLE_NOUN,
	};

	// 代词分类
	enum PronounClass
	{
		// 人称代词
		EPC_PERSONAL_PRONOUN,
		// 物主代词
		EPC_POSSESSIVE_PRONOUN,
		// 指示代词
		EPC_DEMONSTRATIVE_PRONOUN,
		// 反身代词
		EPC_REFLEXIVE_PRONOUN,
		// 相互代词
		EPC_RECIPROCAL_PRONOUN,
		// 疑问代词
		EPC_INTERROGATIVE_PRONOUN,
		// 关系代词
		EPC_RELATIVE_PRONOUN,
		// 连接代词
		EPC_CONJUNCTIVE_PRONOUN,
		// 不定代词
		EPC_INDEFINITE_PRONOUN,
	};

	// 数词分类
	enum NumberClass
	{
		// 基数词
		ENC_CARDINAL_NUMBER,
		// 序数词
		ENC_ORIDNAL_NUMBER,
	};

	// 动词分类
	enum VerbClass
	{
		// 实义动词
		EVC_REAL_VERBS,
		// 及物动词
		EVC_TRANSITIVE_VERBS,
		// 不及物动词
		EVC_INTRANSITIVE_VERBS,
		// 系动词
		EVC_LINKING_VERBS,
		// 助动词
		EVC_AUXILIARY_VERBS,
		// 情态动词
		EVC_MODAL_VERBS,
	};

	// 句子成分
	enum SentenceComposition
	{
		// 主语
		ESC_SUBJECT = 1 << 0,
		// 谓语
		ESC_PREDICATE = 1 << 1,
		// 宾语
		ESC_OBJECT = 1 << 2,
		// 定语
		ESC_ATTRIBUTIVE = 1 << 3,
		// 状语
		ESC_ADVERBIAL = 1 << 4,
		// 补语
		ESC_COMPLEMENT = 1 << 5,
		// 表语
		ESC_PREDICATIVE = 1 << 6,
	};
}