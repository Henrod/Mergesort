#ifndef MERGESORTVECTOR_HPP
#define MERGESORTVECTOR_HPP

#include <vector>

class MsVector {
	public:
		MsVector(int size);
		MsVector(const std::vector<int>& vec);
		virtual ~MsVector();
		void sort();
		void print() const;
	private:
		void sort(std::vector<int>& vec, std::vector<int>& aux, int lo, int hi);
		void merge(std::vector<int>& vec, std::vector<int>& aux, int lo, int mid, int hi);
		std::vector<int>* mVec;
};

#endif //MERGESORTVECTOR_HPP
