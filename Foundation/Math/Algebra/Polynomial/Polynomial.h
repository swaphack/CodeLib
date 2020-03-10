#pragma once
#include <cstdint>
#include <map>
#include <vector>

namespace math
{
	/**
	*	多项式的项
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
		*	是否有相同元
		*/
		bool hasSameExponentials(const PolynomialTerm& value);
		/**
		*	是否为空
		*/
		bool isNull() const;
	public:
		/**
		*	编号
		*/
		int getID() const;
		/**
		*	项的系数
		*/
		float getCoefficient() const;
		/**
		*	项的系数
		*/
		void setCoefficient(float value);
		/**
		*	项的元
		*/
		const std::map<int, float>& getExponentials() const;
		/**
		*	项的元
		*/
		void setExponentials(const std::map<int, float>& value);
	protected:
		/**
		*	生成项的id
		*/
		int generateID();
	protected:
		/**
		*	编号
		*/
		int _id = 0;
		/**
		*	项的系数
		*/
		float _coefficient = 0;
		/**
		*	项的元
		*/
		std::map<int, float> _mapExponentials;
	};

	// 多项式
	class Polynomial
	{
	public:
		Polynomial();
		Polynomial(const std::vector<PolynomialTerm>& mapTerm);
		Polynomial(const Polynomial& value);
		virtual ~Polynomial();
	public:
		/**
		*	设置项的系数
		*/
		void setCoefficientOfTerm(int id, float coefficient);
		/**
		*	获取项的系数
		*/
		float getCoefficientOfTerm(int id);
		/**
		*	获取项
		*/
		PolynomialTerm getTerm(int id);
		/**
		*	添加项
		*/
		int addTerm(const PolynomialTerm& term);
		/**
		*	移除项
		*/
		void removeTerm(int id);
		/**
		*	是否有项
		*/
		bool hasTerm(int id);
		/**
		*	设置所有项
		*/
		void setTerms(const std::map<int, PolynomialTerm>& mapTerm);
		/**
		*	获取所有项
		*/
		const std::map<int, PolynomialTerm>& getTerms() const;
	public:
		/**
		*	相加
		*/
		Polynomial operator+(const Polynomial& value);
		/**
		*	相减
		*/
		Polynomial operator-(const Polynomial& value);
		/**
		*	相乘
		*/
		Polynomial operator*(const Polynomial& value);
	protected:
		/**
		*	多项式的项
		*/
		std::map<int, PolynomialTerm> _mapTerm;
	};
}