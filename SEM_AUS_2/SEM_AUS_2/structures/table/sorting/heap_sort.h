#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"

namespace structures
{

	/// <summary> Triedenie Heap sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class HeapSort : public Sort<K, T>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Heap sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
	};

	template<typename K, typename T>
	inline void HeapSort<K, T>::sort(UnsortedSequenceTable<K, T>& table)
	{
		bool change = false;

		for (int i = 1; i < table.size() - 1; i++)
		{
			int actual = i;
			do
			{
				int father = (actual - 1) / 2;
				if ((actual > 0) && (table.getItemAtIndex(actual).getKey() > table.getItemAtIndex(father).getKey()))
				{
					table.swap(actual, father);
					actual = father;
					change = true;
				}
			} while (change);
		}

		for (int i = table.size() - 1; i > 1; i--)
		{
			table.swap(0, i);
			int actual = 0;

			do
			{
				change = false;
				int left = actual * 2 + 1;
				int right = actual * 2 + 2;
				int max = 0;

				if ((left < i) && (right < i))
				{
					max = table.getItemAtIndex(left).getKey() > table.getItemAtIndex(right).getKey() ? left : right;
				}
				else
				{
					max = left < i ? left : right;
				}

				if ((max < i) && (table.getItemAtIndex(max).getKey()))
				{
					table.swap(max, actual);
					actual = max;
					change = true;
				}

			} while (change);
		}


	}

}