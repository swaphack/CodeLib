#pragma once

namespace tribe
{
	// ����֧��
	class Finace
	{
	public:
		Finace();
		virtual ~Finace();
	public:
		// ��������
		void add(float money);
		// ��ȡ���
		inline float getMoney() const { return _money; }
		// �������
		inline void setMoney(float val) { _money = val; }
	protected:
	private:
		// ���
		float _money;
	};
}