#pragma once

namespace business
{
	class Relation;

	// ��ϵ����
	class RelationFactory
	{
	public:
		RelationFactory();
		~RelationFactory();
	public:
		template<typename T, enum C,
			typename = std::enable_if<std::is_base_of<Relation, T>::value, T>::type>
		T* make();
	protected:
	private:
	};
}