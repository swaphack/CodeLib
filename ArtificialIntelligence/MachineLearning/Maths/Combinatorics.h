#include <cstdint>
namespace maths
{
	// 组合
	class Combinatorics
	{
	public:
		/**
		 * 从容器中选出目标中的不同分组数目
		 *	@param nPickNum 目标数
		 *	@param nTotalMum 总数
		 */
		static uint64_t pick(uint64_t nPickNum, uint64_t nTotalNum);
	protected:
	private:
	};
}