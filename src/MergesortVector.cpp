#include <vector>
#include <random>
#include <iostream>
#include "MergesortVector.hpp"

int generateRandom() {
	int min = 0, max = 1000;
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

	return uni(rng);
}

MsVector::MsVector(int size) {
	mVec = new std::vector<int>();

	for (int i = 0; i < size; ++i)
		mVec->push_back(generateRandom());
}

MsVector::MsVector(const std::vector<int>& vec) {
	mVec = new std::vector<int>(vec);
}

MsVector::~MsVector() {
	delete mVec;
}

void MsVector::sort() {
	std::vector<int> aux = std::vector<int>(mVec->size());

	sort(*mVec, aux, 0, mVec->size() - 1);
}

void MsVector::print() const {
	/*for (std::vector<int>::const_iterator itr = mVec->cbegin(); itr != mVec->cend(); ++itr)
		std::cout << *itr << " ";*/

	/*for (auto itr = mVec->cbegin(); itr != mVec->cend(); ++itr)
		std::cout << *itr << " ";*/

	for (const auto& x : *mVec)
		std::cout << x << " ";
	std::cout << std::endl << std::endl;
}

void MsVector::sort(std::vector<int>& vec, std::vector<int>& aux, int lo, int hi) {
	if (lo >= hi) return;

	int mid = (lo + hi) / 2;

	sort(vec, aux, lo, mid);
	sort(vec, aux, mid + 1, hi);
	merge(vec, aux, lo, mid, hi);
}

void MsVector::merge(std::vector<int>& vec, std::vector<int>& aux, int lo, int mid, int hi) {
	int i = lo,
			j = mid + 1,
			k = lo;

	while (k <= hi) {
		if 			(i > mid) 				aux[k++] = vec[j++];
		else if (j > hi)	 				aux[k++] = vec[i++];
		else if (vec[i] < vec[j])	aux[k++] = vec[i++];
		else 											aux[k++] = vec[j++];
	}

	for (k = lo; k <= hi; ++k) vec[k] = aux[k];
}
