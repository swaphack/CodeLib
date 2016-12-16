#pragma once

namespace ll
{
	// ���ʴ���
	enum WordNominal
	{
		// ���� n.
		EWN_NOUNS = 1 << 0,
		// ���������� pron.
		EWN_PRONOUN = 1 << 1,
		// ���� num.
		EWN_NUMERAL = 1 << 2,
		// ���� v.
		EWN_VERB = 1 << 3,
		// ���ݴ� adj. a.
		EWN_ADJECTIVE = 1 << 4,
		// ���� adv.
		EWN_ADVERB = 1 << 5,
		// �ڴ� art.
		EWN_ARTICLE = 1 << 6,
		// �飨ϵ���� prep.
		EWN_PREPOSITION = 1 << 7,
		// �����ӣ��� conj.
		EWN_CONJUNCITION = 1 << 8,
		// (��)̾�� interj. int.
		EWN_INTERJECTION = 1 << 9,
	};

	// ���ʷ���
	enum NounClass1
	{
		// ר������
		ENC_PROPER_NOUN,
		// ��ͨ����
		ENC_COMMON_NOUN,
	};

	// ���ʷ���
	enum NounClass2
	{
		// ��������
		ENC_COUNTABLE_NOUN,
		// ����������
		ENC_UNCOUNTABLE_NOUN,
	};

	// ���ʷ���
	enum PronounClass
	{
		// �˳ƴ���
		EPC_PERSONAL_PRONOUN,
		// ��������
		EPC_POSSESSIVE_PRONOUN,
		// ָʾ����
		EPC_DEMONSTRATIVE_PRONOUN,
		// �������
		EPC_REFLEXIVE_PRONOUN,
		// �໥����
		EPC_RECIPROCAL_PRONOUN,
		// ���ʴ���
		EPC_INTERROGATIVE_PRONOUN,
		// ��ϵ����
		EPC_RELATIVE_PRONOUN,
		// ���Ӵ���
		EPC_CONJUNCTIVE_PRONOUN,
		// ��������
		EPC_INDEFINITE_PRONOUN,
	};

	// ���ʷ���
	enum NumberClass
	{
		// ������
		ENC_CARDINAL_NUMBER,
		// ������
		ENC_ORIDNAL_NUMBER,
	};

	// ���ʷ���
	enum VerbClass
	{
		// ʵ�嶯��
		EVC_REAL_VERBS,
		// ���ﶯ��
		EVC_TRANSITIVE_VERBS,
		// �����ﶯ��
		EVC_INTRANSITIVE_VERBS,
		// ϵ����
		EVC_LINKING_VERBS,
		// ������
		EVC_AUXILIARY_VERBS,
		// ��̬����
		EVC_MODAL_VERBS,
	};

	// ���ӳɷ�
	enum SentenceComposition
	{
		// ����
		ESC_SUBJECT = 1 << 0,
		// ν��
		ESC_PREDICATE = 1 << 1,
		// ����
		ESC_OBJECT = 1 << 2,
		// ����
		ESC_ATTRIBUTIVE = 1 << 3,
		// ״��
		ESC_ADVERBIAL = 1 << 4,
		// ����
		ESC_COMPLEMENT = 1 << 5,
		// ����
		ESC_PREDICATIVE = 1 << 6,
	};
}