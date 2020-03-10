#pragma once
#include <cstdint>
#include <map>
#include <vector>

namespace math
{
	/**
	*	����ʽ����
	*/
	struct PolynomialTerm
	{
	public:
		PolynomialTerm();
		PolynomialTerm(float coefficient, const std::map<int, float>& exponentials);
		PolynomialTerm(const PolynomialTerm& term);
		~PolynomialTerm();
	public:
		PolynomialTerm operator+(const PolynomialTerm& value);
		PolynomialTerm operator-(const PolynomialTerm& value);
		PolynomialTerm operator*(const PolynomialTerm& value);

		bool operator==(const PolynomialTerm& value);
		bool operator!=(const PolynomialTerm& value);
	public:
		/**
		*	�Ƿ�����ͬԪ
		*/
		bool hasSameExponentials(const PolynomialTerm& value);
		/**
		*	�Ƿ�Ϊ��
		*/
		bool isNull() const;
	public:
		/**
		*	���
		*/
		int getID() const;
		/**
		*	���ϵ��
		*/
		float getCoefficient() const;
		/**
		*	���ϵ��
		*/
		void setCoefficient(float value);
		/**
		*	���Ԫ
		*/
		const std::map<int, float>& getExponentials() const;
		/**
		*	���Ԫ
		*/
		void setExponentials(const std::map<int, float>& value);
	protected:
		/**
		*	�������id
		*/
		int generateID();
	protected:
		/**
		*	���
		*/
		int _id = 0;
		/**
		*	���ϵ��
		*/
		float _coefficient = 0;
		/**
		*	���Ԫ
		*/
		std::map<int, float> _mapExponentials;
	};

	// ����ʽ
	class Polynomial
	{
	public:
		Polynomial();
		Polynomial(const std::vector<PolynomialTerm>& mapTerm);
		Polynomial(const Polynomial& value);
		virtual ~Polynomial();
	public:
		/**
		*	�������ϵ��
		*/
		void setCoefficientOfTerm(int id, float coefficient);
		/**
		*	��ȡ���ϵ��
		*/
		float getCoefficientOfTerm(int id);
		/**
		*	��ȡ��
		*/
		PolynomialTerm getTerm(int id);
		/**
		*	�����
		*/
		int addTerm(const PolynomialTerm& term);
		/**
		*	�Ƴ���
		*/
		void removeTerm(int id);
		/**
		*	�Ƿ�����
		*/
		bool hasTerm(int id);
		/**
		*	����������
		*/
		void setTerms(const std::map<int, PolynomialTerm>& mapTerm);
		/**
		*	��ȡ������
		*/
		const std::map<int, PolynomialTerm>& getTerms() const;
	public:
		/**
		*	���
		*/
		Polynomial operator+(const Polynomial& value);
		/**
		*	���
		*/
		Polynomial operator-(const Polynomial& value);
		/**
		*	���
		*/
		Polynomial operator*(const Polynomial& value);
	protected:
		/**
		*	����ʽ����
		*/
		std::map<int, PolynomialTerm> _mapTerm;
	};
}