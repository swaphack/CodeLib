#pragma once

namespace tribe
{
	// 收入支出
	class Finace
	{
	public:
		Finace();
		virtual ~Finace();
	public:
		// 增加收入
		void add(float money);
		// 获取余款
		inline float getMoney() const { return _money; }
		// 设置余款
		inline void setMoney(float val) { _money = val; }
	protected:
	private:
		// 余款
		float _money;
	};
}